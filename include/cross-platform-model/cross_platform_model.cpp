//
//  cross_platform_model.m
//  cross-platform-model
//
//  Created by Mark Schisler on 3/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdexcept>
#include <boost/shared_ptr.hpp>
#include <sqlite3pp/sqlite3pp.h>
#include "cross_platform_model.h"

Person::Person(identifier_t identifier) : id_(identifier) {
    database_t db = db_acquire();
    sqlite3pp::query q(*db, "SELECT fname, lname FROM Person WHERE rowid = ?");
    q.bind(1, identifier);
    for (sqlite3pp::query::iterator i = q.begin(), end(q.end()); i != end; ++i) {
        char const* fname = NULL, *lname = NULL;
        boost::tie(fname, lname) = i->get_columns<char const*, char const*>(0,1);
        fname_ = string_t(fname);
        lname_ = string_t(lname);
        return;
    }
    throw std::exception();
}

void Person::persistToDisk() {
    database_t db = db_acquire();
    if ( id_ == 0 ) {
        sqlite3pp::command cmd(*db, "INSERT INTO Person(id,fname,lname) VALUES(NULL,?,?)");
        cmd.bind(1, fname_.getAsCString());
        cmd.bind(2, lname_.getAsCString());
        cmd.execute();
        id_ = db->last_insert_rowid();
    } else {
        sqlite3pp::command cmd(*db, "UPDATE Person SET fname=?, lname=? WHERE id=?");
        cmd.bind(1, fname_.getAsCString());
        cmd.bind(2, lname_.getAsCString());
        cmd.bind(3, id_);
        cmd.execute();
    }
}

Person::container_t getAllPersons() {
    Person::container_t persons;
    
    database_t db = db_acquire();
    sqlite3pp::query q(*db, "SELECT id, fname, lname FROM Person");
    for (sqlite3pp::query::iterator i = q.begin(), end(q.end()); i != end; ++i) {
        Person::identifier_t identifier = 0;
        char const* fname = NULL, *lname = NULL;
        boost::tie(identifier, fname, lname) = i->get_columns<int, char const*, char const*>(0,1,2);
        persons.push_back(Person(identifier, Person::string_t(fname), Person::string_t(lname)));
    }
    
    return persons;
}

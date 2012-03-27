#ifndef __CrossPlatformModel_H__
#define __CrossPlatformModel_H__

//
//  cross_platform_model.h
//  cross-platform-model
//
//  Created by Mark Schisler on 3/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <list>
#include <corefoundationcpp/corefoundationcpp.h>
#include <sqlite3pp/sqlite3pp.h>
#include "cross_platform_database.h"

extern database_t db_acquire();

class Person {
public:    
    typedef CoreFoundationCpp::String string_t;
    typedef std::list<Person>         container_t;
    typedef int                       identifier_t;
    
    friend Person::container_t getAllPersons();
    
    Person(identifier_t identifier);
    Person(string_t fname, string_t lname) : fname_(fname), lname_(lname), id_(0) {}
    virtual ~Person() {}
    
    identifier_t getID()const { return id_; }
    
    void setFirstName(string_t s) { fname_ = s; }
    void setLastName(string_t s) { lname_ = s; } 
    
    string_t getFirstName()const { return fname_; }
    string_t getLastName()const { return lname_; }
    
    void persistToDisk();
    
private:
    Person(identifier_t identifier, string_t fname, string_t lname) : id_(identifier), fname_(fname), lname_(lname) {}
    
    identifier_t id_;
    string_t fname_;
    string_t lname_;
};

Person::container_t getAllPersons();

#endif // __CrossPlatformModel_H__


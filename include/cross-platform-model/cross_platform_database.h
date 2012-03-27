//
//  cross_platform_database.h
//  cross-platform-model
//
//  Created by Mark Schisler on 3/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef cross_platform_model_database_h_
#define cross_platform_model_database_h_

#include <boost/shared_ptr.hpp>
#include <sqlite3pp/sqlite3pp.h>

typedef boost::shared_ptr<sqlite3pp::database> database_t;

#endif

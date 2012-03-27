//
//  cross_platform_model_tests.m
//  cross-platform-model-tests
//
//  Created by Mark Schisler on 3/20/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "cross_platform_model_tests.h"
#include "cross_platform_model.h"
#include "cross_platform_database_acquire.h"

using namespace CoreFoundationCpp;

@implementation cross_platform_model_tests

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
}

- (void)tearDown
{
    // Tear-down code here.
    
    [super tearDown];
}

- (void)testQueryPersonsModel
{
    STAssertTrue(getAllPersons().size() > 0,@"");
}

- (void)testInsertIntoPersonModelAndUpdate
{    
    String rotten("Rotten");
    Person p(String("Johnny"), String("Depp"));
    p.persistToDisk();
    
    p.setLastName(rotten);
    p.persistToDisk();
    
    Person::identifier_t identifier = p.getID();
    Person q(identifier);
    
    STAssertTrue(q.getID() == p.getID(), @"");
    STAssertTrue(p.getLastName() == rotten, @"");
    STAssertTrue(q.getLastName() == rotten, @"");
}

@end

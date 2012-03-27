//
//  corefoundationcppTests.m
//  corefoundationcppTests
//
//  Created by Mark Schisler on 3/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "corefoundationcppTests.h"
#include "corefoundationcpp.h"

@implementation corefoundationcppTests

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

- (void)testCreateReferenceCountedStringFromNTS {
    CoreFoundationCpp::String helloWorld("Hello World!");
    NSString* helloWorldNString = @"Hello World!"; 
    STAssertTrue([helloWorldNString isEqual:(NSString*)helloWorld.getAsCFStringRef()],@"");
}

- (void)testCreateNTSFromReferenceCountedString {
    CoreFoundationCpp::String helloWorld("Hello World!");
    const char* c = helloWorld.getAsCString();
    STAssertTrue(!strcmp(c,"Hello World!"),@"");
}

@end

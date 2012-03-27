//
//  ReferenceCountedString.cpp
//  corefoundationcpp
//
//  Created by Mark Schisler on 3/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <CoreFoundation/CoreFoundation.h>
#include "ReferenceCountedString.h"

namespace CoreFoundationCpp {
    
    ReferenceCountedString::ReferenceCountedString() {
        string_ = CFStringCreateMutable(kCFAllocatorDefault, 0);
    }
    
    ReferenceCountedString::ReferenceCountedString(const char* nts) {
        string_ = CFStringCreateMutable(kCFAllocatorDefault, 0);
        append(nts);
    }
    
    ReferenceCountedString::ReferenceCountedString(CFStringRef str)  {
        string_ = CFStringCreateMutable(kCFAllocatorDefault, 0);
        append(str);
    }
    
    ReferenceCountedString::ReferenceCountedString(const ReferenceCountedString& lhs) {
        CFRetain(lhs.string_);
        string_ = lhs.string_;
    }
    
    ReferenceCountedString::~ReferenceCountedString() {
        CFRelease(string_);
    }
    
    ReferenceCountedString& ReferenceCountedString::operator=(const ReferenceCountedString& rhs) {
        if ( this != &rhs ) {
            CFRelease(string_);
            CFRetain(rhs.string_);
            string_ = rhs.string_;
        }
        return *this;
    }
    
    bool ReferenceCountedString::operator==(const ReferenceCountedString& rhs)const{
        return CFEqual(string_, rhs.string_);
    }
    
    const char* ReferenceCountedString::getAsCString()const {
        buffer_ = boost::shared_array<char>(new char[getLength()+1]);
        if (!CFStringGetCString(string_, buffer_.get(), getLength()+1, kCFStringEncodingMacRoman))
            return NULL;
        return buffer_.get();
    } 
    
    void ReferenceCountedString::append(const char* nts) {
        CFStringAppendCString(string_, nts, kCFStringEncodingMacRoman);
    }
    
    void ReferenceCountedString::append(CFStringRef str) {
        CFStringAppend(string_, str);
    }
}


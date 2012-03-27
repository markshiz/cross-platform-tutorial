//
//  ReferenceCountedString.h
//  corefoundationcpp
//
//  Created by Mark Schisler on 3/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef corefoundationcpp_ReferenceCountedString_h
#define corefoundationcpp_ReferenceCountedString_h

#include <boost/shared_array.hpp>
#include <CoreFoundation/CoreFoundation.h>

namespace CoreFoundationCpp {

class ReferenceCountedString {
public:
    typedef size_t length_t;
    
    ReferenceCountedString();
    explicit ReferenceCountedString(const char* nts);
    explicit ReferenceCountedString(CFStringRef str);
    ReferenceCountedString(const ReferenceCountedString& lhs);
    virtual ~ReferenceCountedString();
    
    void append(const char* nts);
    void append(CFStringRef str);
    
    CFStringRef getAsCFStringRef()const { return string_; }
    const char* getAsCString()const;
    
    length_t    getLength()const { return CFStringGetLength(string_); }
    
    ReferenceCountedString& operator=(const ReferenceCountedString& rhs);
    bool operator==(const ReferenceCountedString& rhs)const;
    
private:
    CFMutableStringRef string_;
    mutable boost::shared_array<char> buffer_;
};

} // namespace 

#endif

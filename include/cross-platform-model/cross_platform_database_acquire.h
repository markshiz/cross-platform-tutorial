
#ifndef cross_platform_model_database_acquire_h_
#define cross_platform_model_database_acquire_h_

#include "cross_platform_database.h"

#ifdef __ANDROID__ 
 #include <android/log.h>
 #define kDefaultAndroidPath "/data/data/com.mobconverge.CrossPlatformTutorial/db.sqlite"
#endif 

database_t db_acquire() { 
    
  /* A bug in OCUnit causes the bundle to not be set correctly when running unit tests */
  #ifdef _UNITTEST
    CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFSTR("com.mobconverge.cross-platform-model-tests"));
  #else
    CFBundleRef bundle = CFBundleGetMainBundle();
  #endif
    
  if ( bundle ) {
    CFURLRef url = CFBundleCopyBundleURL(bundle);
    if ( url ) {
      CFStringRef path = CFURLCopyFileSystemPath(url, kCFURLPOSIXPathStyle);
      if ( path ) {
        CoreFoundationCpp::String fs_path(path);
        fs_path.append("/db.sqlite");
        return database_t(new sqlite3pp::database(fs_path.getAsCString()));
      }
    }
  }
    
  #ifdef __ANDROID__ 
    __android_log_print(ANDROID_LOG_VERBOSE, "cross-platform-tutorial", "Opening file at: %s", kDefaultAndroidPath);
    return database_t(new sqlite3pp::database(kDefaultAndroidPath));
  #endif 
  
  return database_t();
    
} 

#endif 
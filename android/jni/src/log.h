#ifndef __CROSS_PLATFORM_TUTORIAL_LOGGING_H__
#define __CROSS_PLATFORM_TUTORIAL_LOGGING_H__

#include <android/log.h> 

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, "cross-platform-tutorial", __VA_ARGS__) 

#endif // __CROSS_PLATFORM_TUTORIAL_LOGGING_H_

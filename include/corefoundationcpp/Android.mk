LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := ReferenceCountedString.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../

LOCAL_EXPORT_CPPFLAGS := -I$(LOCAL_PATH)/../

LOCAL_STATIC_LIBRARIES += corefoundationlite

LOCAL_MODULE := corefoundationcpp

include $(BUILD_STATIC_LIBRARY)

$(call import-module,corefoundationlite)

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../

LOCAL_EXPORT_CPPFLAGS := -I$(LOCAL_PATH)

LOCAL_SRC_FILES := sqlite3pp.cpp sqlite3ppext.cpp

LOCAL_STATIC_LIBRARIES += sqlite

LOCAL_MODULE := sqlite3pp

include $(BUILD_STATIC_LIBRARY)

$(call import-module,sqlite)

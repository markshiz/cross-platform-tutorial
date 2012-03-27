LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_EXPORT_CPPFLAGS := -I$(LOCAL_PATH)

LOCAL_SRC_FILES := sqlite3.c shell.c

LOCAL_MODULE := sqlite

include $(BUILD_STATIC_LIBRARY)


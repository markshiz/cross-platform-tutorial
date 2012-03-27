LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := cross_platform_model.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH) $(LOCAL_PATH)/../

LOCAL_EXPORT_CPPFLAGS := -I$(LOCAL_PATH)

LOCAL_STATIC_LIBRARIES += corefoundationlite corefoundationcpp sqlite3pp

LOCAL_MODULE := cross-platform-model

include $(BUILD_STATIC_LIBRARY)

$(call import-module,corefoundationlite)
$(call import-module,corefoundationcpp)
$(call import-module,sqlite3pp)

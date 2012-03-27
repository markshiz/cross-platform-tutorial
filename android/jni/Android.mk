
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := src/com_mobconverge_CrossPlatformTutorial_model_CrossPlatformTutorialModel.cpp \
	src/com_mobconverge_CrossPlatformTutorial_model_CrossPlatformTutorialModel_Person.cpp

LOCAL_STATIC_LIBRARIES += cross-platform-model

LOCAL_MODULE    := cross-platform-tutorial-model

LOCAL_CFLAGS := -D__ANDROID__=1

LOCAL_LDLIBS := -ldl -llog -lstdc++

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cross-platform-model)

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_LDLIBS    := -lm -llog


LOCAL_MODULE := JniLib
LOCAL_SRC_FILES =: JniLib.c
include $(BUILD_SHARED_LIBRARY)
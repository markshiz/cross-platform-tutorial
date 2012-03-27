#!/bin/sh -x
CURRENT=`pwd`
export NDK_MODULE_PATH=$CURRENT/../include
cd jni/
ndk-build clean

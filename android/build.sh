#!/bin/sh -x
CURRENT=`pwd`
export NDK_MODULE_PATH=$CURRENT/../include
cd jni/
ndk-build DEBUG=1 V=1

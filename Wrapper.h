#pragma once
#include <jni.h>
#include <Windows.h>
#include <stdint.h>
#include <cstring>
#include <iostream>
#using <mscorlib.dll>
using namespace System;
using namespace System::Text;
using namespace System::IO;

ref class Aix
{
public:
	static jbyteArray toJByteArray(JNIEnv * pEnv, array<byte>^ arr);
	static jstring tojString(JNIEnv * pEnv, array<byte>^ arr);
	static const char* toConstChar(JNIEnv* pEnv, jstring str);
};
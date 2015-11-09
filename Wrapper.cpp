#include "Wrapper.h"

jbyteArray Aix::toJByteArray(JNIEnv * pEnv, array<byte>^ arr)
{
	jbyteArray jab = pEnv->NewByteArray(arr->Length);
	pin_ptr<unsigned char> pUnmanagedArr = &arr[0];
	pEnv->SetByteArrayRegion(jab, 0, arr->Length , (jbyte*)pUnmanagedArr);
	return jab;
}
jstring Aix::tojString(JNIEnv * pEnv, array<byte>^ arr)
{
	pin_ptr<Byte> pinnedBytes = &arr[0];
	jstring s = pEnv->NewStringUTF(reinterpret_cast<char*>(pinnedBytes));
	return s;
}

const char* Aix::toConstChar(JNIEnv* pEnv, jstring jStr)
{
	const char* nativeString = pEnv->GetStringUTFChars(jStr, JNI_FALSE);
	pEnv->ReleaseStringUTFChars(jStr, nativeString);
	return nativeString;
}
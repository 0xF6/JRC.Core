

#pragma once 		// Исключает дубликаты файла (импортировать единожды)
#include <jni.h>	
#include <Windows.h>
#include <stdint.h>
#include <cstring>
#include <iostream>

#using <mscorlib.dll> // импортим управляемую билиотеку CLR (ядро .NET Framework)

#ifdef x64
#using <RC.Core.netmodule> // импортим библиотеку скомпилированного кода (Без dll header)
#else
#using <RC.Core.x86.netmodule>
#endif

// используем пространства имён из NET Framework
using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace Rc;
using namespace Rc::Framework;
using namespace Rc::Core;
using namespace Rc::Framework::Yaml::Serialization;
//- 

// Выравнивание памяти по 1 биту
#pragma pack(push, 1)
ref struct OrchNode
{
public:
	// Manage Type String
	// wchar_t* 
	String^ CommentNode;
	String^ KeyNode;
	String^ ValueNode;
};
// Отключение выравнивания
#pragma pack(pop)

// Объявляем класс c параметрами ссылочности (save point) (Orch^ name)
ref class Orch
{
public:
	String^ path;
	FileStream^ stream; // 
	bool inited; 
	bool isStarted;
	Dictionary<String^, OrchNode^> base;
	List<int>^ errorCode;
	List<int>^ allErrorCode;

	void Open(String^ pathToFile);
	void Create(String^ pathToFile);

	String^ get(String^ key, String^ def);
	void set(String^ key, String^ val);
	void add(String^ key, String^ val);
	void addErrorCode(int errorCode);
	void clearErrorCode();

	void Parse(String^ allText);

	static Orch^ instance;
};


array<byte>^ _compile_arrayinfo();

#ifndef _Included_ru_whisper_ntVM
#define _Included_ru_whisper_ntVM
#ifdef __cplusplus
extern "C" 
{
#endif
	/*
	* Domain:    RC
	* Class:     RFramework
	* Method:    getAssemblyInfo
	* Signature: ()[B
	*/
	_declspec(dllexport) jbyteArray __stdcall Java_RC_RFramework_getAssemblyInfo(JNIEnv* pEnv, jobject pThis);


	/*
	* Domain:    RC.Framework.Configuration
	* Class:     Orch
	* Method:    init
	* Signature: ()V
	*/
	_declspec(dllexport) void __stdcall Java_RC_Framework_Configuration_Orch_init(JNIEnv* pEnv, jclass pClazz);

	/*
	* Domain:    RC.Framework.Configuration
	* Class:     Orch
	* Method:    open
	* Signature: (Ljava/lang/String;)V
	*/
	_declspec(dllexport) void __stdcall Java_RC_Framework_Configuration_Orch_open(JNIEnv* pEnv, jclass pClazz, jclass jStr);

	/*
	* Domain:    RC.Framework.Configuration
	* Class:     Orch
	* Method:    create
	* Signature: (Ljava/lang/String;)V
	*/
	_declspec(dllexport) void __stdcall Java_RC_Framework_Configuration_Orch_create(JNIEnv* pEnv, jclass pClazz, jstring jStr);

   /*
	* Domain:    RC.Framework.Configuration
	* Class:     Orch
	* Method:    getString
	* Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
	*/
	_declspec(dllexport) jstring __stdcall Java_RC_Framework_Configuration_Orch_getString(JNIEnv* pEnv, jclass pClazz, jstring jStr, jstring jStrDef);

	/*
	 * Domain:    RC.Framework.Configuration
	 * Class:     Orch
	 * Method:    setString
	 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
	 */
	_declspec(dllexport) void __stdcall Java_RC_Framework_Configuration_Orch_setString(JNIEnv* pEnv, jclass pClazz, jstring jStr, jstring val);

	/*
	* Domain:    RC.Framework.Configuration
	* Class:     Orch
	* Method:    setString
	* Signature: (Ljava/lang/String;Ljava/lang/String;)V
	*/
	_declspec(dllexport) void __stdcall Java_RC_Framework_Configuration_Orch_addString(JNIEnv* pEnv, jclass pClazz, jstring jStr, jstring val);


	/*
	* Domain:    RC.Framework.Configuration
	* Class:     Orch
	* Method:    getErrorCode
	* Signature: (I)I
	*/
	_declspec(dllexport) jint __stdcall Java_RC_Framework_Configuration_Orch_getErrorCode(JNIEnv* pEnv, jclass pClazz, jint index);

	/*
	* Domain:    RC.Framework.Configuration
	* Class:     Orch
	* Method:    getErrorCodeLenght
	* Signature: ()I
	*/
	_declspec(dllexport) jint __stdcall Java_RC_Framework_Configuration_Orch_getErrorCodeLenght(JNIEnv* pEnv, jclass pClazz);

	/*
	* Domain:    RC.Framework.Configuration
	* Class:     Orch
	* Method:    isNotNull
	* Signature: ()b
	*/
	_declspec(dllexport) jboolean __stdcall  Java_RC_Framework_Configuration_Orch_isNotNull(JNIEnv * pEnv, jclass pClazz);
#ifdef __cplusplus
}
#endif
#endif

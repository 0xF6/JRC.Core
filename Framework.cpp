#include "Framework.h"
#include "Wrapper.h"
//! ERROR CODE INDEX
// 12 - aleready exist
void Orch::Open(String ^ pathToFile)
{
	if (File::Exists(pathToFile))
	{
		this->stream = File::Open(pathToFile, FileMode::Open, FileAccess::ReadWrite);
	}
	else
	{
		this->addErrorCode(0xB);
	}
}

void Orch::Create(String ^ pathToFile)
{
}

void Orch::Parse(String ^ allText)
{
}

String ^ Orch::get(String ^ key, String ^ def)
{
}

void Orch::set(String ^ key, String ^ val)
{
}

void Orch::add(String ^ key, String ^ val)
{
}

void Orch::addErrorCode(int errorCode)
{
	if (this->errorCode == nullptr)
		this->errorCode = gcnew List<int>();
	this->errorCode->Add(errorCode);
}

void Orch::clearErrorCode()
{
	if (this->errorCode != nullptr)
	{
		this->allErrorCode->AddRange(this->errorCode->ToArray());
		this->errorCode->Clear();
	}
}



_declspec(dllexport) jbyteArray __stdcall Java_RC_RFramework_getAssemblyInfo(JNIEnv * pEnv, jobject pThis)
{
	RCAssemblyInfo^ inf = Rc::Framework::Framework::GetInfoFramework();
	Rc::Framework::Net::IArchByteBoxWriter^ writer = Rc::Framework::Net::ArchByteBox::InvokeWriter();
	writer->wInt(inf->ver->Major);
	writer->wInt(inf->ver->Minor);
	writer->wInt(inf->ver->Build);
	writer->wInt(inf->ver->Revision);
	writer->wInt((int)inf->ProcArch);
	return Aix::toJByteArray(pEnv, writer->GetAll());
}

_declspec(dllexport) void __stdcall  Java_RC_Framework_Configuration_Orch_init(JNIEnv* pEnv, jclass pClazz)
{
	if (Orch::instance == nullptr)
	{
		Orch::instance					= gcnew Orch();
		Orch::instance->allErrorCode	= gcnew List<int>();
		Orch::instance->errorCode		= gcnew List<int>();
		Orch::instance->inited			= true;
	}
	else
	{
		Orch::instance->addErrorCode(0xC);
	}
}

_declspec(dllexport) void __stdcall  Java_RC_Framework_Configuration_Orch_open(JNIEnv * pEnv, jclass pClazz, jstring jStr)
{
	if (Orch::instance != nullptr)
	{
		const char* ch = Aix::toConstChar(pEnv, jStr);
		Orch::instance->Open(gcnew String(ch));
	}
}

_declspec(dllexport) void __stdcall  Java_RC_Framework_Configuration_Orch_create(JNIEnv * pEnv, jclass pClazz, jstring jStr)
{
	if (Orch::instance != nullptr)
	{
		const char* ch = Aix::toConstChar(pEnv, jStr);
		Orch::instance->Create(gcnew String(ch));
	}
}

_declspec(dllexport) jstring __stdcall  Java_RC_Framework_Configuration_Orch_getString(JNIEnv * pEnv, jclass pClazz, jstring jStr, jstring jStrDef)
{
	if (Orch::instance != nullptr)
	{
		const char* ch = Aix::toConstChar(pEnv, jStr);
		const char* chDef = Aix::toConstChar(pEnv, jStrDef);
		Orch::instance->get(gcnew String(ch), gcnew String(chDef));
	}
}

_declspec(dllexport) void __stdcall  Java_RC_Framework_Configuration_Orch_setString(JNIEnv * pEnv, jclass pClazz, jstring jStr, jstring val)
{
	if (Orch::instance != nullptr)
	{
		const char* ch = Aix::toConstChar(pEnv, jStr);
		const char* chval = Aix::toConstChar(pEnv, val);
		Orch::instance->set(gcnew String(ch), gcnew String(chval));
	}
}

_declspec(dllexport) void __stdcall Java_RC_Framework_Configuration_Orch_addString(JNIEnv* pEnv, jclass pClazz, jstring jStr, jstring val)
{
	if (Orch::instance != nullptr)
	{
		const char* ch = Aix::toConstChar(pEnv, jStr);
		const char* chval = Aix::toConstChar(pEnv, val);
		Orch::instance->add(gcnew String(ch), gcnew String(chval));
	}
}

_declspec(dllexport) jint __stdcall  Java_RC_Framework_Configuration_Orch_getErrorCode(JNIEnv * pEnv, jclass pClazz, jint index)
{
	if (Orch::instance != nullptr && Orch::instance->errorCode != nullptr)
	{
		return Orch::instance->errorCode[(int)index];
	}
}

_declspec(dllexport) jboolean __stdcall  Java_RC_Framework_Configuration_Orch_isNotNull(JNIEnv * pEnv, jclass pClazz)
{
	return Orch::instance != nullptr;
}

_declspec(dllexport) jint __stdcall Java_RC_Framework_Configuration_Orch_getErrorCodeLenght(JNIEnv * pEnv, jclass pClazz)
{
	if (Orch::instance != nullptr && Orch::instance->errorCode != nullptr)
	{
		return Orch::instance->errorCode->Count;
	}
}
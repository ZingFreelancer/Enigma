#pragma once
namespace Utility_Private
{
	using namespace std;
	using namespace System;
	using namespace System::Runtime::InteropServices;


	static void ToSTDString(System::String ^ s, std::string & os)
	{
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
}

namespace Utility
{
#include <string>
	static std::string StringToString(System::String ^ s)
	{
		std::string re;
		Utility_Private::ToSTDString(s, re);
		return re;
	}
}
#pragma once
//	Frank(5.2) i/e -> Core.h
#ifdef XJ_PLATFORM_WINDOWS
	#ifdef XJ_BUILD_DLL
		#define XJ_API __declspec(dllexport)
	#else
		#define XJ_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif



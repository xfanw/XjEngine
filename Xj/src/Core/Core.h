#pragma once

#ifdef XJ_PLATFORM_WINDOWS
	#ifdef XJ_BUILD_DLL
		#define XJ_API __declspec(dllexport)
	#else
		#define XJ_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif


#define BIT(x) (1 << x)
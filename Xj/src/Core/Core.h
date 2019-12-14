#pragma once
#include <intrin.h>
#ifdef XJ_PLATFORM_WINDOWS
	#ifdef XJ_BUILD_DLL
		#define XJ_API __declspec(dllexport)
	#else
		#define XJ_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif

#ifdef XJ_ENABLE_ASSERTS
#define XJ_ASSERT(x, ...){\
	if (!(x)) {\
		XJ_ERROR("Assertion failed: {0}", __VA_ARGS__);\
		__debugbreak();\
	}\
}
#define XJ_CORE_ASSERT(x, ...){\
	if (!(x)) {\
		XJ_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__);\
		__debugbreak();\
	}\
}
#else
	#define XJ_ASSERT(x, ...)
	#define XJ_CORE_ASSERT(x, ...)
#endif

#define XJ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#define BIT(x) (1 << x)
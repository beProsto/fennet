#pragma once

// On windows, if compiling to a DLL, we need spec declarations for shared libraries:
#if defined _WIN32 && !defined LIB_BUILD_STATIC
	#ifdef LIB_BUILD_SHARED
		// When building the DLL, we specify we want the classes and functions treated as export
		#define LIB_API __declspec(dllexport)
	#else
		// When building the executables, we specify we want everything treated as import
		#define LIB_API __declspec(dllimport)
	#endif
#else
	// On other systems we can leave it empty
	#define LIB_API 
#endif

#define NAH 0
#define YUP 1

int LIB_API doesItLookLikeImBoring();
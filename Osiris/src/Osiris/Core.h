#pragma once

#ifdef OSIRIS_PLATFORM_WINDOWS
	#ifdef OSIRIS_BUILD_DLL 
		#define OSIRIS_API __declspec(dllexport)
	#else
		#define OSIRIS_API __declspec(dllimport)
	#endif
#else
	#error Osiris only support Windows!
#endif
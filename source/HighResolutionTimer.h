#pragma once

#ifndef _HIGHRESOLUTIONTIMER_H_
#define _HIGHRESOLUTIONTIMER_H_
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#ifdef __cplusplus
extern "C"
{
#endif
	inline ULONGLONG GetCycleCount();
	LONGLONG GetFrequency(DWORD sleepTime);
#ifdef __cplusplus
}
#endif
#endif
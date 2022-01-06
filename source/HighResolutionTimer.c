#include "HighResolutionTimer.h"

#if _WIN64
inline ULONGLONG GetCycleCount();
#elif _WIN32
inline ULONGLONG GetCycleCount()
{
	__asm
	{
		_emit 0x0F;
		_emit 0x31;
	}
}
#endif 


LONGLONG GetFrequency(DWORD sleepTime)
{
    SetProcessAffinityMask(GetCurrentProcess(), 0x0);
    SetThreadAffinityMask(GetCurrentThread(), 1);
    SetPriorityClass(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
    LARGE_INTEGER fq, st, ed;
    QueryPerformanceFrequency(&fq);
    QueryPerformanceCounter(&st);
    LONGLONG begin = GetCycleCount();
    Sleep(sleepTime);
    QueryPerformanceCounter(&ed);
    LONGLONG end = GetCycleCount();
    return (end - begin) * fq.QuadPart / (ed.QuadPart - st.QuadPart);
}

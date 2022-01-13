#include "HighResolutionTimer.h"

#if _WIN64
inline ULONGLONG  GetCycleCount();
#elif _WIN32
inline ULONGLONG  GetCycleCount()
{
    __asm
    {
        _emit 0x0F;
        _emit 0x01;
        _emit 0xF9;
    }
}
#endif 


LONGLONG GetFrequency(DWORD sleepTime)
{
    double clockfreq;
    SetThreadAffinityMask(GetCurrentThread(), 0x01);
    LARGE_INTEGER fq, st, ed;
    QueryPerformanceFrequency(&fq);
    clockfreq = fq.QuadPart / 1000000;
    QueryPerformanceCounter(&st);
    LONGLONG begin = GetCycleCount();
    Sleep(sleepTime);
    QueryPerformanceCounter(&ed);   
    LONGLONG end = GetCycleCount();
    return (end - begin) * fq.QuadPart / (ed.QuadPart - st.QuadPart);
}

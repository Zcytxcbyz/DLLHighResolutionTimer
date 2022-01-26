#include "HighResolutionTimer.h"
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "ntdll.lib")
#include <MMSystem.h>

#if _WIN64
inline ULONGLONG  GetCycleCount();
#elif _WIN32
inline ULONGLONG  GetCycleCount()
{
    __asm
    {
        _emit 0x31;
        _emit 0x0F;
    }
}
#endif

//void PASCAL OneMilliSecondProc(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2)
//{
//}

LONGLONG GetFrequency(DWORD sleepTime)
{
    SetThreadAffinityMask(GetCurrentThread(), 0x01);
    LARGE_INTEGER fq, st, ed;
    QueryPerformanceFrequency(&fq);
    QueryPerformanceCounter(&st);
    LONGLONG begin = GetCycleCount();
    //timeSetEvent(1000, 0, (LPTIMECALLBACK)OneMilliSecondProc, (DWORD)(0), TIME_PERIODIC);
    timeBeginPeriod(begin);
    Sleep(sleepTime);
    QueryPerformanceCounter(&ed);   
    LONGLONG end = GetCycleCount();
    timeEndPeriod(end);
    return (end - begin) * fq.QuadPart / (ed.QuadPart - st.QuadPart);
}

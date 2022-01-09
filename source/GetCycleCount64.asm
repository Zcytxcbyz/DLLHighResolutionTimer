.code
  GetCycleCount proc
    cpuid
    rdtsc
    cpuid
    ret
  GetCycleCount endp
end

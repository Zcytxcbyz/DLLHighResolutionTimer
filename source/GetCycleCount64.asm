.code
  GetCycleCount proc
    cpuid
    rdtsc
    ret
  GetCycleCount endp
end

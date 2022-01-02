.code
  GetCycleCount proc 
    push rdx
	rdtsc
	shl rdx, 32
	or  rax, rdx
	pop rdx
	ret
  GetCycleCount endp
end

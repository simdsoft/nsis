#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#if defined(_MSC_VER) && _MSC_VER+0 >= 1400
#if defined(_MSC_FULL_VER) && _MSC_FULL_VER+0 >= 140050727
#include <intrin.h>
#else
EXTERN_C void __stosb(BYTE*,BYTE,size_t);
#endif
#pragma intrinsic(__stosb)
#define CRTINTRINSIC_memset(p,c,s) __stosb((BYTE*)(p),(BYTE)(c),(s))
#endif

#if defined(__cplusplus)
extern "C"
#endif
	void* __cdecl memset(void *p, int c, size_t z)
{
#ifdef CRTINTRINSIC_memset
  CRTINTRINSIC_memset(p, c, z);
#else
  BYTE *pb = reinterpret_cast<BYTE*>(p);
  for(size_t i=0; i<z; ++i, ++pb)
    (*pb) = c;
#endif
  return p;
}
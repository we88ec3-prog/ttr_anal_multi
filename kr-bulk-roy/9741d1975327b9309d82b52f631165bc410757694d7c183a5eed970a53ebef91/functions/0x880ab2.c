
/* Library Function - Single Match
    void __cdecl _Atexit(void (__cdecl*)(void))
   
   Library: Visual Studio 2010 Release */

void __cdecl _Atexit(_func_void *param_1)

{
  PVOID pvVar1;
  
  if (DAT_00d611a8 == 0) {
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  DAT_00d611a8 = DAT_00d611a8 + -1;
  pvVar1 = EncodePointer(param_1);
  *(PVOID *)(DAT_00d611a8 * 4 + 0xf8c99c) = pvVar1;
  return;
}


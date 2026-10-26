
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 2010 Release */

int __cdecl __setargv(void)

{
  uint _Size;
  void *pvVar1;
  int iVar2;
  uint local_10;
  uint local_c;
  char *local_8;
  
  if (DAT_00fe83d0 == 0) {
    ___initmbctable();
  }
  DAT_00f8d844 = 0;
  GetModuleFileNameA((HMODULE)0x0,&DAT_00f8d740,0x104);
  _DAT_00f8cafc = &DAT_00f8d740;
  if ((DAT_00fe73a4 == (char *)0x0) || (local_8 = DAT_00fe73a4, *DAT_00fe73a4 == '\0')) {
    local_8 = &DAT_00f8d740;
  }
  parse_cmdline(0,0,&local_c);
  if ((local_c < 0x3fffffff) && (local_10 != 0xffffffff)) {
    iVar2 = local_c * 4;
    _Size = iVar2 + local_10;
    if ((local_10 <= _Size) && (pvVar1 = __malloc_crt(_Size), pvVar1 != (void *)0x0)) {
      parse_cmdline(pvVar1,(void *)(iVar2 + (int)pvVar1),&local_c);
      _DAT_00f8cae0 = local_c - 1;
      _DAT_00f8cae4 = pvVar1;
      return 0;
    }
  }
  return -1;
}


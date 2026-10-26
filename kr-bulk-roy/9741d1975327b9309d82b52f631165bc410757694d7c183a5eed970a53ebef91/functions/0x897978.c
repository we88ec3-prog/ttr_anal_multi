
/* Library Function - Single Match
    __vsnwprintf_l
   
   Library: Visual Studio 2010 Release */

int __cdecl
__vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,wchar_t *_Format,_locale_t _Locale,va_list _ArgList
              )

{
  int *piVar1;
  int iVar2;
  char **ppcVar3;
  FILE local_24;
  
  local_24._ptr = (char *)0x0;
  ppcVar3 = (char **)&local_24._cnt;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppcVar3 = (char *)0x0;
    ppcVar3 = ppcVar3 + 1;
  }
  if (_Format == (wchar_t *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    iVar2 = -1;
  }
  else if ((_MaxCount == 0) || (_DstBuf != (wchar_t *)0x0)) {
    local_24._flag = 0x42;
    local_24._base = (char *)_DstBuf;
    local_24._ptr = (char *)_DstBuf;
    if (_MaxCount < 0x40000000) {
      local_24._cnt = _MaxCount * 2;
    }
    else {
      local_24._cnt = 0x7fffffff;
    }
    iVar2 = FUN_008a3d54(&local_24,_Format,_Locale,_ArgList);
    if (_DstBuf != (wchar_t *)0x0) {
      local_24._cnt = local_24._cnt + -1;
      if (local_24._cnt < 0) {
        __flsbuf(0,&local_24);
      }
      else {
        *local_24._ptr = 0;
        local_24._ptr = (char *)((int)local_24._ptr + 1);
      }
      local_24._cnt = local_24._cnt + -1;
      if (local_24._cnt < 0) {
        __flsbuf(0,&local_24);
      }
      else {
        *local_24._ptr = 0;
      }
    }
  }
  else {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    iVar2 = -1;
  }
  return iVar2;
}


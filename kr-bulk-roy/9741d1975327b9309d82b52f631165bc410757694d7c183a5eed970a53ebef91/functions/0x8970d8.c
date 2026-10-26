
/* Library Function - Single Match
    __wcsicmp
   
   Library: Visual Studio 2010 Release */

int __cdecl __wcsicmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  
  if (DAT_00f8cb10 == 0) {
    if ((_Str1 == (wchar_t *)0x0) || (_Str2 == (wchar_t *)0x0)) {
      piVar1 = __errno();
      *piVar1 = 0x16;
      FUN_00893343();
      iVar2 = 0x7fffffff;
    }
    else {
      iVar2 = (int)_Str1 - (int)_Str2;
      do {
        uVar4 = *(ushort *)(iVar2 + (int)_Str2);
        if ((0x40 < uVar4) && (uVar4 < 0x5b)) {
          uVar4 = uVar4 + 0x20;
        }
        uVar3 = (uint)(ushort)*_Str2;
        if ((0x40 < uVar3) && (uVar3 < 0x5b)) {
          uVar3 = uVar3 + 0x20 & 0xffff;
        }
        _Str2 = _Str2 + 1;
      } while ((uVar4 != 0) && (uVar4 == (ushort)uVar3));
      iVar2 = uVar4 - uVar3;
    }
  }
  else {
    iVar2 = __wcsicmp_l(_Str1,_Str2,(_locale_t)0x0);
  }
  return iVar2;
}


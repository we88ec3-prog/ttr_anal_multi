
undefined4 FUN_007d32d0(uint *param_1,char *param_2)

{
  char *_Str2;
  int iVar1;
  int unaff_ESI;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(unaff_ESI + 0x68) - *(int *)(unaff_ESI + 100) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(*(int *)(unaff_ESI + 100) + uVar2 * 4) + 4);
      _Str2 = (char *)(iVar1 + 8);
      if (0xf < *(uint *)(iVar1 + 0x1c)) {
        _Str2 = *(char **)_Str2;
      }
      iVar1 = __stricmp(param_2,_Str2);
      if (iVar1 == 0) {
        *param_1 = uVar2;
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_ESI + 0x68) - *(int *)(unaff_ESI + 100) >> 2));
  }
  *param_1 = 0xffff;
  return 0;
}


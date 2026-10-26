
uint FUN_0073bac0(wchar_t *param_1)

{
  wchar_t *_Str1;
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_EDI;
  
  uVar3 = 0;
  uVar4 = *(int *)(unaff_EDI + 0x1c) - *(int *)(unaff_EDI + 0x18) >> 2;
  if (uVar4 != 0) {
    do {
      puVar1 = (uint *)FUN_005719b0();
      if ((((*puVar1 < uVar4) &&
           (_Str1 = *(wchar_t **)(*(int *)(unaff_EDI + 0x18) + *puVar1 * 4), _Str1 != (wchar_t *)0x0
           )) && (*(int *)(_Str1 + 0x22) == *(int *)(param_1 + 0x22))) &&
         (((*(int *)(_Str1 + 0x20) == *(int *)(param_1 + 0x20) &&
           (*(int *)(_Str1 + 0x24) == *(int *)(param_1 + 0x24))) &&
          (*(int *)(_Str1 + 0x26) == *(int *)(param_1 + 0x26))))) {
        iVar2 = __wcsicmp(_Str1,param_1);
        if (iVar2 == 0) {
          return uVar3;
        }
      }
      uVar3 = uVar3 + 1;
      uVar4 = *(int *)(unaff_EDI + 0x1c) - *(int *)(unaff_EDI + 0x18) >> 2;
    } while (uVar3 < uVar4);
  }
  return 0xffffffff;
}


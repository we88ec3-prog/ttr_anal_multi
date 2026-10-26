
void FUN_007d4030(int param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  char *_Str1;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x7c) - *(int *)(param_1 + 0x78) >> 3 != 0) {
    do {
      iVar3 = *(int *)(param_1 + 0x78);
      iVar2 = *(int *)(iVar3 + 4 + uVar4 * 8);
      piVar1 = (int *)(iVar3 + uVar4 * 8);
      _Str1 = (char *)(iVar2 + 8);
      if (0xf < *(uint *)(iVar2 + 0x1c)) {
        _Str1 = *(char **)_Str1;
      }
      iVar3 = __stricmp(_Str1,param_2);
      if (iVar3 == 0) {
        *piVar1 = *piVar1 + 1;
        return;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(*(int *)(param_1 + 0x7c) - *(int *)(param_1 + 0x78) >> 3));
  }
  iVar3 = FUN_007c6700(*(undefined4 *)(param_1 + 0x10),param_2);
  if (iVar3 != 0) {
    FUN_007d4560();
  }
  return;
}


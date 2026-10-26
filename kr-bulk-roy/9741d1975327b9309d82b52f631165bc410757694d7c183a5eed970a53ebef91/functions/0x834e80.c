
undefined4 FUN_00834e80(int param_1,int param_2)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  FUN_00834f20(&param_1);
  if (in_ECX == *(int *)(in_EAX + 4)) {
    return 0;
  }
  iVar3 = (param_2 + 1) * 0x10;
  piVar4 = (int *)(iVar3 + in_ECX);
  iVar1 = *(int *)(iVar3 + 4 + in_ECX) - *piVar4;
  iVar3 = iVar1 >> 0x1f;
  iVar1 = iVar1 / 0xc + iVar3;
  uVar2 = 0;
  if (iVar1 != iVar3) {
    param_1 = 0;
    if (iVar1 == iVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid vector<T> subscript");
    }
    do {
      FUN_0052ef90();
      param_1 = param_1 + 0xc;
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)((piVar4[1] - *piVar4) / 0xc));
  }
  return 1;
}


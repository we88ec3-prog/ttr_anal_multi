
undefined4 FUN_00836680(uint param_1,int param_2,int *param_3)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  int in_ECX;
  
  FUN_00835c70(&param_1);
  if (in_ECX == *(int *)(in_EAX + 4)) {
    return 0;
  }
  FUN_00519680(&param_2);
  iVar1 = param_1;
  if (param_1 == *(int *)(in_ECX + 0x14)) {
    return 0;
  }
  uVar2 = (*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24)) / 0xc;
  param_1 = 0;
  if (uVar2 != 0) {
    param_2 = 0;
    do {
      if (uVar2 <= param_1) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      FUN_0052ef90();
      param_2 = param_2 + 0xc;
      uVar2 = (*(int *)(iVar1 + 0x28) - *(int *)(iVar1 + 0x24)) / 0xc;
      param_1 = param_1 + 1;
    } while (param_1 < uVar2);
  }
  *param_3 = *param_3 + *(int *)(iVar1 + 0x10);
  param_3[1] = param_3[1] + *(int *)(iVar1 + 0x14);
  param_3[2] = param_3[2] + *(int *)(iVar1 + 0x18);
  param_3[3] = param_3[3] + *(int *)(iVar1 + 0x1c);
  param_3[4] = param_3[4] + *(int *)(iVar1 + 0x20);
  return 1;
}



void FUN_007a71b0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int extraout_EDX;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0xf4) = param_1;
  *(undefined4 *)(in_ECX + 0xfc) = 1;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x44) = param_1;
    *(undefined4 *)(iVar1 + 0x48) = param_1;
    *(undefined4 *)(iVar1 + 0x4c) = param_1;
    FUN_0077ef50(param_1,param_1,param_1);
    in_ECX = extraout_EDX;
  }
  iVar1 = *(int *)(in_ECX + 0x104);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = param_1;
    *(undefined4 *)(iVar1 + 0x70) = 1;
    return;
  }
  return;
}


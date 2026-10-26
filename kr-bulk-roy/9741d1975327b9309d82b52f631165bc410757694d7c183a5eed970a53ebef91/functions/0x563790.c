
void FUN_00563790(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  
  FUN_0082ef00(&param_1);
  if ((in_ECX != *(int *)(in_ECX + 0x1c)) && (iVar1 = *(int *)(in_ECX + 0x10), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + 0x414) = param_3;
    *(undefined4 *)(iVar1 + 0x410) = param_3;
    *(undefined4 *)(iVar1 + 0x40c) = param_2;
  }
  return;
}


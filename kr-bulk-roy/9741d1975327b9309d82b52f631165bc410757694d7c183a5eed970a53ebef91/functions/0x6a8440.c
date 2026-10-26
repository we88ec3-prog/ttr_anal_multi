
void FUN_006a8440(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
      FUN_006a84a0();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
      iVar1 = FUN_00671e60();
      *(undefined4 *)(iVar1 + 4) = 0;
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  return;
}



void FUN_006bf2a0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x34] + 0x20))) {
    iVar1 = FUN_00404ba0();
    if (*(int *)(iVar1 + 0x5f4c) == 1) {
      FUN_0049b230();
      FUN_006bfae0();
      FUN_004054c0();
      FUN_0058b510();
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    FUN_00414680();
    FUN_004a38d0();
  }
  return;
}


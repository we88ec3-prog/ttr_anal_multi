
void FUN_006654c0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x42] + 0x20)) {
      iVar1 = FUN_00404ba0();
      if (*(int *)(iVar1 + 0x5f4c) == 0) {
        FUN_00414680();
        FUN_004a43f0(in_ECX[0x44]);
        (**(code **)(*in_ECX + 0x90))(0);
        return;
      }
      FUN_00414680();
      FUN_004a43b0(in_ECX[0x44]);
      (**(code **)(*in_ECX + 0x90))(0);
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x43] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  return;
}


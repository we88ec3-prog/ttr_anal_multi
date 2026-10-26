
void FUN_00680a30(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(in_ECX[0x48] + 0x20)) {
      FUN_00680d00();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x43] + 0x20)) {
      FUN_00681840();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x44] + 0x20)) {
      FUN_00681840();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x45] + 0x20)) {
      FUN_00681840();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x41] + 0x20)) {
      FUN_00681540();
    }
  }
  else {
    if (iVar1 == 0xf43a9) {
      FUN_00414680();
      FUN_004a3cd0(in_ECX[0x3e],in_ECX[0x3f],in_ECX[0x40] + 1);
      return;
    }
    if (iVar1 == 0xf43aa) {
      FUN_00681540();
      (**(code **)(*in_ECX + 0x16c))(1);
      return;
    }
  }
  return;
}


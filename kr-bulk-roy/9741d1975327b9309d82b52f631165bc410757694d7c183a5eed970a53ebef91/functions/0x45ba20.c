
void FUN_0045ba20(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x40] + 0x20)) {
      FUN_0045b410(in_ECX);
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
      FUN_0045c240();
    }
  }
  else {
    if (iVar1 == 0xf43a9) {
      FUN_0045c280(in_ECX);
      return;
    }
    if (iVar1 == 0xf43aa) {
      (**(code **)(*in_ECX + 0x16c))(1);
      return;
    }
  }
  return;
}


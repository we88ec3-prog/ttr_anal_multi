
void FUN_005965d0(int param_1)

{
  int iVar1;
  undefined4 in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xf434e) {
    FUN_006bd720();
  }
  else {
    if (iVar1 == 0xf4350) {
      FUN_00597110(in_ECX);
      return;
    }
    if (iVar1 == 0xf4355) {
      FUN_00597250(in_ECX);
      return;
    }
  }
  return;
}


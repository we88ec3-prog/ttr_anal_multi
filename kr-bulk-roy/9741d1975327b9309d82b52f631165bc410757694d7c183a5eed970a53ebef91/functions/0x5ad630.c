
void FUN_005ad630(int param_1)

{
  int iVar1;
  undefined4 in_ECX;
  
  FUN_0059bd80(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf4406) {
    FUN_005ac6e0(in_ECX);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xf4363) {
    FUN_005ad4c0();
  }
  else {
    if (iVar1 == 0xf43a1) {
      FUN_005ad120();
      return;
    }
    if (iVar1 == 0xf4427) {
      FUN_0045eb40();
      return;
    }
  }
  return;
}


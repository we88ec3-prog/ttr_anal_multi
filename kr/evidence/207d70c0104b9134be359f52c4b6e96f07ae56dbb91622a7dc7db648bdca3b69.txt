
void FUN_005a44e0(int param_1)

{
  int iVar1;
  undefined4 in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0xf42a3) {
    FUN_00597a30();
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xf425f) {
    FUN_00642e60(0,0,1);
  }
  else {
    if (iVar1 == 0xf4260) {
      FUN_005a3f90(in_ECX);
      return;
    }
    if (iVar1 == 0xf42b1) {
      FUN_005a58c0();
      return;
    }
  }
  return;
}


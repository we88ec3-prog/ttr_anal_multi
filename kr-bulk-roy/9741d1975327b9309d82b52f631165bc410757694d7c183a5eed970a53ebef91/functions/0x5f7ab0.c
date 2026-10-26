
void FUN_005f7ab0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_005f53c0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf43a3) {
    if (*(int *)(param_1 + 0x14) == 0x6a7) {
      FUN_005f7a60();
      return;
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0x76c) {
    if ((*(int *)(*(int *)(in_ECX + 0xf8) + 0xcc) == 0) ||
       (*(int *)(*(int *)(in_ECX + 0xf8) + 0xd8) == 0)) {
      iVar1 = -1;
    }
    else {
      iVar1 = FUN_005f55a0();
    }
    iVar2 = FUN_00404ba0();
    *(int *)(*(int *)(iVar2 + 0x6920) + 0x50bc) = iVar1 + 1;
  }
  return;
}


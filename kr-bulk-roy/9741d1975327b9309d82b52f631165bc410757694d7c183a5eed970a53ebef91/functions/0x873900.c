
undefined4 FUN_00873900(undefined4 param_1)

{
  int iVar1;
  int in_EDX;
  bool bVar2;
  
  if (*(int *)(in_EDX + 0x38) == 0) {
    return 0;
  }
  bVar2 = *(int *)(in_EDX + 0x2c) != 0;
  iVar1 = *(int *)(*(int *)(in_EDX + 0x38) + 4);
  if ((iVar1 != 2) && (iVar1 != 4)) {
    FUN_007919a0(param_1,bVar2);
    return 1;
  }
  FUN_007921c0(param_1,bVar2);
  return 1;
}


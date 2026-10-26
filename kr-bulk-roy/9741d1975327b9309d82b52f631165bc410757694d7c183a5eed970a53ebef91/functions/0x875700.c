
undefined4 FUN_00875700(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) == 0) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0x38) + 4);
  if (iVar1 == 2) {
    FUN_00791d70(param_1);
    return 1;
  }
  if (iVar1 == 4) {
    FUN_00791b90();
    return 1;
  }
  FUN_00791870(param_1);
  return 1;
}


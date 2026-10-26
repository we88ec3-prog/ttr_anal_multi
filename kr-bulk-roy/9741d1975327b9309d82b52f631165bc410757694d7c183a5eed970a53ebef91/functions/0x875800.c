
undefined4 FUN_00875800(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) == 0) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0x40) + 4);
  if (iVar1 == 2) {
    FUN_00791e20(param_1);
    return 1;
  }
  if (iVar1 == 4) {
    FUN_00791a80();
    return 1;
  }
  FUN_00791730(param_1);
  return 1;
}


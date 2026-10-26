
undefined4 FUN_008e1ec0(void)

{
  int iVar1;
  int in_EDX;
  
  iVar1 = *(int *)(in_EDX + 0x188);
  if (iVar1 == in_EDX + 8) {
    FUN_008e0760();
    return 0;
  }
  if (*(int *)(iVar1 + -4) != 2) {
    FUN_008e0760();
    return 0;
  }
  *(undefined4 **)(in_EDX + 0x188) = (undefined4 *)(iVar1 + -8);
  return *(undefined4 *)(iVar1 + -8);
}


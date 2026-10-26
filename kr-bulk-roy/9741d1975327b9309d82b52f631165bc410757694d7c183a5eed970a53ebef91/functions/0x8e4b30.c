
undefined4 FUN_008e4b30(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int in_ECX;
  char local_5;
  
  FUN_008e29a0();
  if (*(int *)(in_ECX + 4) == 0) {
    local_5 = *(char *)(in_ECX + 0x8d);
    *(undefined1 *)(in_ECX + 0xc0) = 0;
    FUN_008e0e20();
    FUN_008e39d0();
    iVar1 = *(int *)(in_ECX + 4);
    while (iVar1 == 0) {
      if ((local_5 == '\0') || (-1 < *(int *)(in_ECX + 0x74))) {
        FUN_008e0e40();
        break;
      }
      *(undefined1 *)(in_ECX + 0xc0) = 1;
      local_5 = '\0';
      FUN_008e0e20();
      FUN_008e39d0();
      iVar1 = *(int *)(in_ECX + 4);
    }
  }
  *param_2 = 0;
  FUN_008e0760();
  return *(undefined4 *)(in_ECX + 4);
}


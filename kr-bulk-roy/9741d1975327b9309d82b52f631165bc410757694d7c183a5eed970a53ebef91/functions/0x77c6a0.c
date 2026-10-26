
undefined4 FUN_0077c6a0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00776540(param_1);
  if (cVar1 != '\0') {
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x40));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x38));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x3c));
    FUN_007648e0(*(undefined4 *)(in_ECX + 0x44));
    return 1;
  }
  return 0;
}


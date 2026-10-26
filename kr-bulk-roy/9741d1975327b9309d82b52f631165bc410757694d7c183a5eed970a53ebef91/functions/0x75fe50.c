
undefined4 FUN_0075fe50(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00749460(param_1);
  if (cVar1 != '\0') {
    FUN_007448d0();
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xd4));
    FUN_00776b00(*(undefined4 *)(in_ECX + 200));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xcc));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xd0));
    return 1;
  }
  return 0;
}


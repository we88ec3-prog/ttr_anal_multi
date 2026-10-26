
undefined4 FUN_007543c0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00749460(param_1);
  if (cVar1 != '\0') {
    FUN_007448d0();
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xc4));
    FUN_00755dc0(param_1);
    FUN_00755dc0(param_1);
    return 1;
  }
  return 0;
}


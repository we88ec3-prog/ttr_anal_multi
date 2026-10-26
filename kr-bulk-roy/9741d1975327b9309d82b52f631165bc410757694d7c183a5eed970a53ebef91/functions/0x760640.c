
undefined4 FUN_00760640(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_007543c0(param_1);
  if (cVar1 != '\0') {
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xd4));
    return 1;
  }
  return 0;
}



undefined4 FUN_0074d0f0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00756740(param_1);
  if (cVar1 != '\0') {
    FUN_00756110(*(undefined1 *)(in_ECX + 0xf0));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xf4));
    return 1;
  }
  return 0;
}



undefined4 FUN_0076f550(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00756740(param_1);
  if (cVar1 != '\0') {
    FUN_00756110(*(undefined1 *)(in_ECX + 0xf4));
    FUN_00756110(*(undefined1 *)(in_ECX + 0xf5));
    FUN_00756110(*(undefined1 *)(in_ECX + 0xf6));
    return 1;
  }
  return 0;
}


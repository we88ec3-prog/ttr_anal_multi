
undefined4 FUN_0075ea90(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00749460(param_1);
  if (cVar1 != '\0') {
    FUN_007448d0();
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xbc));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xc0));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xc4));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xbc));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xd0));
    FUN_00756110(*(undefined1 *)(in_ECX + 0xd4));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xd8));
    return 1;
  }
  return 0;
}


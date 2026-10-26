
undefined4 FUN_00756740(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  cVar1 = FUN_00749460(param_1);
  if (cVar1 != '\0') {
    uVar2 = FUN_00764bb0();
    FUN_00764810(uVar2);
    FUN_0072e0d0();
    FUN_00755dc0(param_1);
    FUN_00756110(*(undefined1 *)(in_ECX + 0xe8));
    return 1;
  }
  return 0;
}


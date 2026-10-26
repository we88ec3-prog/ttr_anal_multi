
undefined4 FUN_007566e0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00748c40(param_1);
  if (cVar1 != '\0') {
    FUN_0075a620(in_ECX + 0x84);
    FUN_00755d10(param_1);
    FUN_00756010(in_ECX + 0xe8);
    return 1;
  }
  return 0;
}



undefined4 FUN_00645df0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_007566e0(param_1);
  if (cVar1 != '\0') {
    FUN_00756010(in_ECX + 0xf0);
    FUN_00429860(in_ECX + 0xf4);
    return 1;
  }
  return 0;
}


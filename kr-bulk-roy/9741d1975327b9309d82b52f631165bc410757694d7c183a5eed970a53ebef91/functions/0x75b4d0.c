
undefined4 FUN_0075b4d0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_007543c0(param_1);
  if (cVar1 != '\0') {
    FUN_00776320(param_1);
    FUN_007649b0(*(undefined4 *)(in_ECX + 0xfc));
    FUN_007649b0(*(undefined4 *)(in_ECX + 0xcc));
    FUN_007649b0(*(undefined4 *)(in_ECX + 200));
    return 1;
  }
  return 0;
}



undefined4 FUN_0075bea0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  float10 extraout_ST0;
  
  cVar1 = FUN_00754350(param_1);
  if (cVar1 != '\0') {
    FUN_00756010(in_ECX + 0xd4);
    FUN_00764f00(*(undefined4 *)(in_ECX + 0xd0));
    *(float *)(in_ECX + 0xd0) = (float)extraout_ST0;
    return 1;
  }
  return 0;
}


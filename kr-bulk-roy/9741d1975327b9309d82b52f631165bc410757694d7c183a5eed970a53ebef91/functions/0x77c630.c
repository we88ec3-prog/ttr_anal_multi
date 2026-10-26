
undefined4 FUN_0077c630(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  float10 extraout_ST0;
  
  cVar1 = FUN_00776440(param_1);
  if (cVar1 != '\0') {
    FUN_00429860(in_ECX + 0x40);
    FUN_00429860(in_ECX + 0x38);
    FUN_00429860(in_ECX + 0x3c);
    FUN_00764f00(0);
    *(float *)(in_ECX + 0x44) = (float)extraout_ST0;
    return 1;
  }
  return 0;
}


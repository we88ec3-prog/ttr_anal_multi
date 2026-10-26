
undefined4 FUN_0073aac0(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  piVar1 = in_ECX + 0x11;
  *piVar1 = *piVar1 + -1;
  uVar2 = in_ECX[0x11];
  if (*piVar1 == 0) {
    (**(code **)*in_ECX)(1);
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 FUN_0048a690(int param_1,undefined4 param_2)

{
  char cVar1;
  uint in_EAX;
  undefined4 *in_ECX;
  
  if (in_EAX < 0x110) {
    if (in_EAX == 0x10f) {
      cVar1 = FUN_006f21e0(param_1,param_2,*in_ECX);
      if (cVar1 != '\0') {
        *(undefined4 *)(param_1 + 0x98) = 1;
        return 0;
      }
    }
    else {
      if (in_EAX == 0x51) {
        FUN_006f2170(param_2);
        return 1;
      }
      if (in_EAX == 0x10d) {
        return 0;
      }
      if ((in_EAX == 0x10e) && (cVar1 = FUN_006f23c0(), cVar1 != '\0')) {
        *(undefined4 *)(param_1 + 0x98) = 1;
        return 0;
      }
    }
  }
  else if (in_EAX == 0x281) {
    *in_ECX = 0;
  }
  else if ((in_EAX == 0x282) && (cVar1 = FUN_006f23f0(param_1,param_2), cVar1 != '\0')) {
    *(undefined4 *)(param_1 + 0x98) = 1;
    return 0;
  }
  return 1;
}


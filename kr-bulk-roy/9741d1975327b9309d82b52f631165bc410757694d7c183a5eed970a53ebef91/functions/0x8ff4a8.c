
uint FUN_008ff4a8(int param_1,uint param_2)

{
  uint in_EAX;
  uint uVar1;
  bool in_ZF;
  unkbyte10 in_ST0;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
      uVar1 = FUN_00900ccc();
      goto LAB_008ff541;
    }
    param_2 = 0;
    if ((in_EAX & 0x80000000) == 0) goto LAB_008ff4d5;
  }
  else {
    if ((((param_2 & 0x7ff00000) == 0) && ((param_2 & 0xfffff) == 0)) && (param_1 == 0)) {
      uVar1 = 2;
      goto LAB_008ff541;
    }
    if ((param_2 & 0x80000000) == 0) {
      log2(in_ST0);
LAB_008ff4d5:
      if (DAT_00f8cb74 != 0) {
        return param_2;
      }
      uVar1 = __math_exit();
      return uVar1;
    }
  }
  uVar1 = 1;
LAB_008ff541:
  if (DAT_00f8cb74 != 0) {
    return uVar1;
  }
  uVar1 = __startOneArgErrorHandling();
  return uVar1;
}


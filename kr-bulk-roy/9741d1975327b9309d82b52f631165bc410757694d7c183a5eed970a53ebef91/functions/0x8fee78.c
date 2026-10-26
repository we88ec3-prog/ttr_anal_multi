
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_008fee78(int param_1,uint param_2)

{
  uint in_EAX;
  bool in_ZF;
  short in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (fVar1 = _DAT_00c577f0, param_1 != 0)) {
      fVar1 = (float10)FUN_00900ccc();
    }
LAB_008fef07:
    if (DAT_00f8cb74 == 0) {
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      in_EAX = FUN_00900cb5();
      in_ST0 = extraout_ST0;
    }
    if (in_EAX < 0x3ff00000) {
      fVar1 = (float10)fpatan(in_ST0,SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)));
    }
    else {
      fVar1 = _DAT_00c577f0;
      if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_008fef07;
      fVar1 = _DAT_00c577fa;
      if ((param_2 & 0x80000000) != 0) {
        fVar1 = -_DAT_00c577fa;
      }
    }
    if (DAT_00f8cb74 == 0) {
      fVar1 = (float10)__math_exit();
      return fVar1;
    }
  }
  return fVar1;
}


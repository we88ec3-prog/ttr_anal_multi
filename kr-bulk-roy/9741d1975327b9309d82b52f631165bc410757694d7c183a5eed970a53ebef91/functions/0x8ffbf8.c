
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_008ffbf8(int param_1)

{
  uint in_EAX;
  bool in_ZF;
  unkbyte10 in_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
      fVar1 = (float10)FUN_00900ccc();
      if (DAT_00f8cb74 != 0) {
        return fVar1;
      }
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
    fVar1 = _DAT_00c577fa;
    if ((in_EAX & 0x80000000) != 0) {
      fVar1 = -_DAT_00c577fa;
    }
  }
  else {
    fVar1 = (float10)fpatan(in_ST0,(float10)1);
  }
  if (DAT_00f8cb74 != 0) {
                    /* WARNING: Read-only address (ram,0x00c577fa) is written */
    return fVar1;
  }
  fVar1 = (float10)__math_exit();
  return fVar1;
}


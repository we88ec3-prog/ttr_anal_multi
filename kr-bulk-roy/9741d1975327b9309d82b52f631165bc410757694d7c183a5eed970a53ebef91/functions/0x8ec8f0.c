
int FUN_008ec8f0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 < 0) {
    iVar1 = -0x20 - (param_3 - param_2 & 0xffffffc0U);
    if (0 < iVar1) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = (param_3 + param_2 & 0xffffffc0U) + 0x20;
    if ((param_2 != 0) && (iVar1 < 0)) {
      return 0;
    }
  }
  return iVar1;
}


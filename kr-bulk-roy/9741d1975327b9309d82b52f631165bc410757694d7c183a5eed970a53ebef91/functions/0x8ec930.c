
uint FUN_008ec930(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 < 0) {
    uVar1 = -(param_3 - param_2 & 0xffffffc0U);
    if ((int)uVar1 < 1) {
      return uVar1;
    }
  }
  else if ((param_2 != 0) && (0 < param_3 + param_2)) {
    return param_3 + param_2 & 0xffffffc0;
  }
  return 0;
}


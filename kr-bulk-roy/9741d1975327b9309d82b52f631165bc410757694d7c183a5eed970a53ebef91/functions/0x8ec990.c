
uint FUN_008ec990(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 < 0) {
    uVar1 = -((param_3 - param_2) + 0x10U & 0xffffffe0);
    if ((int)uVar1 < 1) {
      return uVar1;
    }
  }
  else {
    uVar1 = param_2 + 0x10 + param_3;
    if ((param_2 != 0) && (0 < (int)uVar1)) {
      return uVar1 & 0xffffffe0;
    }
  }
  return 0;
}


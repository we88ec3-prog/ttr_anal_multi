
uint FUN_008b7f40(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
  uVar2 = (param_2 ^ (int)param_2 >> 0x1f) - ((int)param_2 >> 0x1f);
  if (uVar2 == 0) {
    uVar2 = 0x7fffffff;
  }
  else if (iVar1 >> 0x10 == 0) {
    uVar2 = (uint)(((int)uVar2 >> 1) + iVar1 * 0x10000) / uVar2;
  }
  else {
    FUN_008b7da0();
    uVar2 = FUN_008b7d60();
  }
  if ((int)(param_1 ^ param_2) < 0) {
    uVar2 = -uVar2;
  }
  return uVar2;
}



int FUN_008b7cb0(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0xffff < param_1) {
    param_1 = param_1 >> 0x10;
    iVar1 = 0x10;
  }
  if (0xff < param_1) {
    param_1 = param_1 >> 8;
    iVar1 = iVar1 + 8;
  }
  if (0xf < param_1) {
    param_1 = param_1 >> 4;
    iVar1 = iVar1 + 4;
  }
  if (3 < param_1) {
    param_1 = param_1 >> 2;
    iVar1 = iVar1 + 2;
  }
  if (1 < param_1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


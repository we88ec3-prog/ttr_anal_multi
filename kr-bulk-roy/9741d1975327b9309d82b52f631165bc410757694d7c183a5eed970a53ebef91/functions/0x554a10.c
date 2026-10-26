
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00554a10(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ff45;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (0xf < DAT_00fc196c) {
    FUN_0089120c(DAT_00fc1958,uVar1);
  }
  DAT_00fc196c = 0xf;
  _DAT_00fc1968 = 0;
  DAT_00fc1958 = DAT_00fc1958 & 0xffffff00;
  if (0xf < DAT_00fc1950) {
    FUN_0089120c(DAT_00fc193c,uVar1);
  }
  DAT_00fc1950 = 0xf;
  _DAT_00fc194c = 0;
  DAT_00fc193c = DAT_00fc193c & 0xffffff00;
  if (0xf < DAT_00fc1934) {
    FUN_0089120c(DAT_00fc1920,uVar1);
  }
  DAT_00fc1934 = 0xf;
  _DAT_00fc1930 = 0;
  DAT_00fc1920 = DAT_00fc1920 & 0xffffff00;
  if (DAT_00fc1910 != 0) {
    FUN_0049bf30();
    FUN_0089120c(DAT_00fc1910);
  }
  DAT_00fc1910 = 0;
  DAT_00fc1914 = 0;
  _DAT_00fc1918 = 0;
  local_8 = 0;
  FUN_00555c60(*DAT_00fc1904,DAT_00fc1904);
  FUN_0089120c(DAT_00fc1904);
  ExceptionList = local_10;
  return;
}


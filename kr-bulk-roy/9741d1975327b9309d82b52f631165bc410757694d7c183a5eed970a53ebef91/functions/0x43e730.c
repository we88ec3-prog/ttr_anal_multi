
void FUN_0043e730(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917b5a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0043f580(DAT_00fd9290[1]);
  DAT_00fd9290[1] = DAT_00fd9290;
  *DAT_00fd9290 = DAT_00fd9290;
  DAT_00fd9290[2] = DAT_00fd9290;
  DAT_00fd9294 = 0;
  local_8 = 1;
  FUN_0043f660(*DAT_00fd9290,DAT_00fd9290);
  FUN_0089120c(DAT_00fd9290,uVar1);
  ExceptionList = local_10;
  return;
}



void FUN_0059ded0(int param_1)

{
  uint uVar1;
  byte bVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e31c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  bVar2 = DAT_00fb9341 == '\0';
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb9343 < bVar2) {
    bVar2 = DAT_00fb9343;
  }
  DAT_00fb9341 = bVar2;
  if (bVar2 < DAT_00fb9342) {
    DAT_00fb9341 = DAT_00fb9342;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x198) + 0x28) >> 8 & 1) != 0) {
    FUN_006221d0();
    FUN_00622950();
    FUN_00624da0();
  }
  ExceptionList = local_10;
  return;
}


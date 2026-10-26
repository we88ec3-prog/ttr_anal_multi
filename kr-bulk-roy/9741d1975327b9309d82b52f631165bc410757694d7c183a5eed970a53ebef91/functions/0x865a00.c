
void FUN_00865a00(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00917fd1;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = GSArchive::vftable;
  local_8 = 2;
  FUN_00865c10(uVar1);
  if (param_1[0x10] != 0) {
    FUN_00440a80();
    FUN_0089120c(param_1[0x10]);
  }
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  local_8 = local_8 & 0xffffff00;
  if (param_1[0xc] != 0) {
    FUN_00842540(param_1[0xc],param_1[0xd],param_1);
    FUN_0089120c(param_1[0xc]);
  }
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  if (0xf < (uint)param_1[6]) {
    FUN_0089120c(param_1[1]);
  }
  param_1[6] = 0xf;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  ExceptionList = local_10;
  return;
}


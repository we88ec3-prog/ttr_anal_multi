
/* WARNING: Removing unreachable block (ram,0x006b8a54) */

void FUN_006b8970(void)

{
  undefined4 uVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093579e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_c = 1;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c._0_1_ = 2;
    local_c._1_3_ = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  if (*(int *)(DAT_00fab130 + 0x5ef8) == 0) {
    uVar1 = 0x16;
  }
  else {
    uVar1 = 0x21;
  }
  FUN_004095e0(uVar1);
  FUN_004095e0(0x1a);
  FUN_004095e0(0x3b);
  FUN_004095e0(0x3c);
  FUN_004095e0(0x3d);
  FUN_004095e0(0x3e);
  ExceptionList = local_14;
  return;
}


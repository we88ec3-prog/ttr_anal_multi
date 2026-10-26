
/* WARNING: Removing unreachable block (ram,0x005ac4df) */

void FUN_005ac3e0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009439ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00598890(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_005ac920();
  FUN_005a9f40(in_ECX + 0x21c);
  FUN_005aca00();
  FUN_005a9f40(in_ECX + 0x220);
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x21c) + 0xd0))();
  (**(code **)(**(int **)(in_ECX + 0x1dc) + 0xd4))();
  FUN_005a55e0(1);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8._0_1_ = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_0058e1c0(*(undefined4 *)(in_ECX + 0x21c));
  ExceptionList = local_10;
  return;
}



/* WARNING: Removing unreachable block (ram,0x005ad02f) */

void FUN_005acea0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009439ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005ac3e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_00437170();
  FUN_005a9f40(in_ECX + 0x224);
  FUN_00437090();
  FUN_005a9f40(in_ECX + 0x228);
  FUN_005adc60();
  FUN_005a9f40(in_ECX + 0x22c);
  FUN_005add40();
  FUN_005a9f40(in_ECX + 0x234);
  FUN_005ade30();
  FUN_005a9f40(in_ECX + 0x238);
  FUN_005adf10();
  FUN_005a9f40(in_ECX + 0x23c);
  FUN_005adff0();
  FUN_005a9f40(in_ECX + 0x240);
  FUN_005ae0d0();
  FUN_005a9f40(in_ECX + 0x248);
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x224) + 0xd0))();
  (**(code **)(**(int **)(in_ECX + 0x228) + 0xd0))();
  (**(code **)(**(int **)(in_ECX + 0x22c) + 0xd0))();
  FUN_00596d70(in_ECX,*(undefined4 *)(in_ECX + 0x23c),0,0,0,0,0);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8._0_1_ = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_0058e1c0(*(undefined4 *)(in_ECX + 0x224));
  ExceptionList = local_10;
  return;
}


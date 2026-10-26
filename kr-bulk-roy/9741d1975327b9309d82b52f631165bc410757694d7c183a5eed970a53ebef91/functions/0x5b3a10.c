
/* WARNING: Removing unreachable block (ram,0x005b3be5) */

void FUN_005b3a10(void)

{
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094943c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_005c29b0(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  FUN_00423850();
  FUN_005a9f40(in_ECX + 0x2fc);
  FUN_005b1f50();
  FUN_005a9f40(in_ECX + 0x304);
  FUN_005b4830();
  FUN_005a9f40(in_ECX + 0x308);
  FUN_005b0c10();
  FUN_005a9f40(in_ECX + 0x300);
  FUN_005af640();
  FUN_005a9f40(in_ECX + 0x30c);
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x2fc) + 0xd0))();
  (**(code **)(**(int **)(in_ECX + 0x308) + 0xd0))();
  (**(code **)(**(int **)(in_ECX + 0x30c) + 0xd0))();
  (**(code **)(**(int **)(in_ECX + 0x2f8) + 0xd4))();
  FUN_00596d70(in_ECX,*(undefined4 *)(in_ECX + 0x304),1,1,1,0,0);
  FUN_00596d70(in_ECX,*(undefined4 *)(in_ECX + 0x2e4),1,1,1,0,0);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*(undefined4 *)(in_ECX + 0x2fc));
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 3;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*(undefined4 *)(in_ECX + 0x30c));
  ExceptionList = local_14;
  return;
}


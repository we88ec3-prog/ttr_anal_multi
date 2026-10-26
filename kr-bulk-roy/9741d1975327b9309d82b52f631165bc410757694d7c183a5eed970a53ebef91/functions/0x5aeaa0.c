
/* WARNING: Removing unreachable block (ram,0x005aebc4) */

void FUN_005aeaa0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094748e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005ac3e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_005af3a0();
  FUN_005a9f40((undefined4 *)(in_ECX + 0x234));
  FUN_005af480();
  FUN_005a9f40(in_ECX + 0x238);
  FUN_005af560();
  FUN_005a9f40(in_ECX + 0x23c);
  puVar1 = (undefined4 *)(in_ECX + 0x224);
  FUN_005af640();
  FUN_005a9f40(puVar1);
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x234) + 0xd0))();
  FUN_006b0c40();
  (**(code **)(*(int *)*puVar1 + 0xd0))();
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8._0_1_ = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_0058e1c0(*puVar1);
  ExceptionList = local_10;
  return;
}


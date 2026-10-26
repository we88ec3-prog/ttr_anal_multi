
/* WARNING: Removing unreachable block (ram,0x005b00a8) */

void FUN_005affe0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009473fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005ac3e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_005b0300();
  FUN_005a9f40((undefined4 *)(in_ECX + 0x228));
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x228) + 0xd0))();
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8._0_1_ = 2;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_0058ac30(0xf43fd,6,0);
  ExceptionList = local_10;
  return;
}


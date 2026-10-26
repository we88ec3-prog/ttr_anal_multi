
/* WARNING: Removing unreachable block (ram,0x00427ead) */

void FUN_00427de0(void)

{
  uint uVar1;
  int in_ECX;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e6ce;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x46);
  FUN_004095e0(0x47);
  FUN_004095e0(0x48);
  local_14 = CONCAT31(local_14._1_3_,(char)(*(uint *)(*(int *)(in_ECX + 0x110) + 0x28) >> 9)) &
             0xffffff01;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8._0_1_ = 2;
    FUN_0058d410(uVar1);
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_0058ea80(L"MoveLock",local_14);
  ExceptionList = local_10;
  return;
}



/* WARNING: Removing unreachable block (ram,0x00427dc3) */

void FUN_00427cb0(void)

{
  int *in_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e6ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_00428d70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0x49);
  FUN_00428e50();
  FUN_005a9f40(in_ECX + 0x4a);
  FUN_00428f30();
  FUN_005a9f40(in_ECX + 0x4b);
  FUN_0040b670(in_ECX);
  local_14 = CONCAT31(local_14._1_3_,1);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8._0_1_ = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_0058eb30(L"MoveLock",&local_14);
  (**(code **)(*(int *)in_ECX[0x44] + 0xa0))(local_14);
  (**(code **)(*in_ECX + 0x16c))((char)local_14 == '\0');
  ExceptionList = local_10;
  return;
}


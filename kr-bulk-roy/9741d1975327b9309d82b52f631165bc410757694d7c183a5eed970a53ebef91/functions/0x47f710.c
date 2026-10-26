
void FUN_0047f710(int param_1)

{
  int iVar1;
  char **local_3c [5];
  uint local_28;
  undefined2 local_20;
  char local_1e [10];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920098;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)(param_1 + 0xf8);
  local_20 = 0xbb;
  if (*(char *)(iVar1 + 0x141) != '\0') {
    FUN_006edb10();
  }
  FUN_004026e0(iVar1 + 0x108,0,0xffffffff);
  FUN_0047f6b0();
  local_8 = 0;
  if (local_28 < 0x10) {
    local_3c[0] = (char **)local_3c;
  }
  _strcpy_s(local_1e,9,(char *)local_3c[0]);
  (**(code **)(*DAT_00fba854 + 0x10))();
  if (0xf < local_28) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


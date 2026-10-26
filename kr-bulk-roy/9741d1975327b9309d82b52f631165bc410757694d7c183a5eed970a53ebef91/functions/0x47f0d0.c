
void FUN_0047f0d0(int param_1)

{
  int iVar1;
  char **local_38 [5];
  uint local_24;
  undefined2 local_1c;
  char local_1a [6];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e548;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)(param_1 + 0xfc);
  local_1c = 0xba;
  if (*(char *)(iVar1 + 0x141) != '\0') {
    FUN_006edb10();
  }
  FUN_004026e0(iVar1 + 0x108,0,0xffffffff);
  FUN_0047f6b0();
  local_8 = 0;
  if (local_24 < 0x10) {
    local_38[0] = (char **)local_38;
  }
  _strcpy_s(local_1a,5,(char *)local_38[0]);
  (**(code **)(*DAT_00fba854 + 0x10))();
  if (0xf < local_24) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


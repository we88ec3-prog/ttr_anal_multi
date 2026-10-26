
void FUN_00659520(void)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  uint local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00920d5a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_50 = CONCAT31(local_50._1_3_,(char)(*(uint *)(*(int *)(in_ECX + 0x110) + 0x28) >> 9)) &
             0xffffff01;
  uVar2 = uVar1;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(uVar1);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0058ea80(L"MoveLock",local_50);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 1;
    FUN_0058d410(uVar2);
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0040ef80();
  local_8 = 2;
  FUN_0058ec10(&DAT_00faaf80,L"ResizedHeight");
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 3;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0040ef80();
  local_8 = 4;
  FUN_0058ec10(&DAT_00faaf80,L"ResizedWidth");
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


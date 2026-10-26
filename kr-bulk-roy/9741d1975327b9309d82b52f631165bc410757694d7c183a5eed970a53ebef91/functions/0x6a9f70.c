
void FUN_006a9f70(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b76e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)(*(int *)(param_1 + 0xf4) + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  }
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    local_8 = 0xffffffff;
  }
  FUN_004ecb20(&DAT_00fbad18);
  ExceptionList = local_10;
  return;
}


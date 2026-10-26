
void FUN_00622950(void)

{
  code *pcVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ab2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00624260(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x120) + 0xa0);
  if (DAT_00fb9335 != '\0') {
    (*pcVar1)(1);
    ExceptionList = local_10;
    return;
  }
  (*pcVar1)(0);
  ExceptionList = local_10;
  return;
}


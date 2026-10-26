
void FUN_004c8ed0(undefined4 param_1)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009305de;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x3d8) = param_1;
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 0;
    FUN_0049d6a0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcce20);
    *(undefined4 *)(in_ECX + 0x3e4) = *(undefined4 *)(in_ECX + 0x3d8);
  }
  else {
    *(undefined4 *)(in_ECX + 0x3e4) = *(undefined4 *)(in_ECX + 0x3d8);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


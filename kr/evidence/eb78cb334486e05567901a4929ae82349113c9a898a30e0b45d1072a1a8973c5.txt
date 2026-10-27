
/* WARNING: Removing unreachable block (ram,0x0053dac6) */

void FUN_0053da80(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009249de;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  if (*(int *)(param_1 + 0x20) != *(int *)(param_1 + 0x24)) {
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x20);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_0058aad0(0xf426f);
  ExceptionList = local_10;
  return;
}


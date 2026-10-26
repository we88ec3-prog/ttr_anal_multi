
void FUN_00624150(int param_1)

{
  int in_EDX;
  byte bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ab2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_EDX + 8) == *(int *)(*(int *)(param_1 + 0x120) + 0x20)) {
    bVar1 = (byte)(*(uint *)(*(int *)(param_1 + 0x120) + 0x28) >> 9) & 1;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fb9335 = bVar1;
    if (DAT_00fb9337 < bVar1) {
      DAT_00fb9335 = DAT_00fb9337;
    }
    if (DAT_00fb9335 < DAT_00fb9336) {
      DAT_00fb9335 = DAT_00fb9336;
    }
  }
  ExceptionList = local_10;
  return;
}


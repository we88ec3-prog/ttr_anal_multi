
void FUN_007cd580(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0091892e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fe1e1c & 1) == 0) {
    DAT_00fe1e1c = DAT_00fe1e1c | 1;
    local_c = 0;
    FUN_007c30c0(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit(FUN_00bcf1b0);
  }
  local_c = 0xffffffff;
  iVar1 = FUN_007c2c60();
  *(int *)(in_ECX + 0x20) = iVar1;
  if (iVar1 != 0) {
    FUN_007cdab0(in_ECX);
    *(undefined4 *)(in_ECX + 0x60) = 1;
    local_20 = 0;
    local_1c = 0;
    FUN_007c5f40(*(undefined4 *)(in_ECX + 0x20),&local_20);
    uVar2 = local_1c - local_20 >> 0x1f;
    *(float *)(in_ECX + 0x34) = (float)(int)((local_1c - local_20 ^ uVar2) - uVar2);
    FUN_00780150(*(int *)(in_ECX + 0x20),*(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x30));
  }
  ExceptionList = local_14;
  return;
}


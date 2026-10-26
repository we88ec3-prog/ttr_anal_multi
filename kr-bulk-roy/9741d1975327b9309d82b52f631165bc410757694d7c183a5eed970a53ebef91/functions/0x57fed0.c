
void FUN_0057fed0(void)

{
  undefined4 uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091afde;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1e1c & 1) == 0) {
    DAT_00fe1e1c = DAT_00fe1e1c | 1;
    local_8 = 0;
    FUN_007c30c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcf1b0);
  }
  local_8 = 0xffffffff;
  uVar1 = FUN_007c2b60(0x11);
  *(undefined4 *)(in_ECX + 4) = uVar1;
  FUN_007cd580();
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x68) = 1;
  FUN_007b7d40(*(undefined4 *)(*(int *)(in_ECX + 0x2c) + 4));
  *(int *)(*(int *)(in_ECX + 0x2c) + 4) = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  *(int *)(*(int *)(in_ECX + 0x2c) + 8) = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  ExceptionList = local_10;
  return;
}


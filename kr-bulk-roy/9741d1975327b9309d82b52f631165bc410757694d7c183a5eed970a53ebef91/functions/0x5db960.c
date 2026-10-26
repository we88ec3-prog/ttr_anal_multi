
void FUN_005db960(int param_1)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00946cfe;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_005d6fb0(param_1);
  if (*(int *)(param_1 + 0x10) == 0x7c) {
    iVar2 = *(int *)(in_ECX + 0x20) + 1;
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_8 = 0;
      FUN_004fdac0(uVar1);
      _atexit(FUN_00bce150);
      local_8 = 0xffffffff;
    }
    if (((iVar2 / 7 + (iVar2 >> 0x1f) == iVar2 >> 0x1f) && (iVar2 * 0x40 != -0xfc7b70)) &&
       ((&DAT_00fc7b88)[iVar2 * 0x10] != 0)) {
      FUN_00604a90(*(undefined4 *)(in_ECX + 0x2a8));
    }
  }
  ExceptionList = local_10;
  return;
}


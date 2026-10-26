
void FUN_005db8b0(char param_1)

{
  int in_ECX;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00946cfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == '\0') {
    iVar1 = *(int *)(in_ECX + 0x20) + 1;
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_8 = 0;
      FUN_004fdac0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit(FUN_00bce150);
    }
    local_8 = 0xffffffff;
    if (((iVar1 / 7 + (iVar1 >> 0x1f) == iVar1 >> 0x1f) && (iVar1 * 0x40 != -0xfc7b70)) &&
       ((&DAT_00fc7b88)[iVar1 * 0x10] != 0)) {
      FUN_00604a90(*(undefined4 *)(in_ECX + 0x2a8));
    }
  }
  ExceptionList = local_10;
  return;
}


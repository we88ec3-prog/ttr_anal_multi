
undefined4 FUN_007dd100(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091882e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)(in_ECX + 0x5c);
  *piVar1 = *piVar1 + -1;
  uVar3 = *(undefined4 *)(in_ECX + 0x5c);
  if (*piVar1 == 0) {
    FUN_007dd1f0(uVar2);
    uVar4 = 0;
    uVar2 = DAT_00fe1770 & 1;
    *(undefined4 *)(in_ECX + 0x44) = 0;
    if (uVar2 == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_8 = 0;
      FUN_007b7da0();
      _atexit((_func_4879 *)&LAB_00bce790);
      local_8 = 0xffffffff;
    }
    uVar2 = *(int *)(in_ECX + 0x50) - *(int *)(in_ECX + 0x4c) >> 2;
    if (uVar2 != 0) {
      do {
        FUN_007dc510();
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
    uVar3 = *(undefined4 *)(in_ECX + 0x5c);
  }
  ExceptionList = local_10;
  return uVar3;
}


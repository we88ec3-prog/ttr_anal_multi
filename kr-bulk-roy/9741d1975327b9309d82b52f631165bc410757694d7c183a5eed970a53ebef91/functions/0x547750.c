
/* WARNING: Removing unreachable block (ram,0x005477a7) */
/* WARNING: Removing unreachable block (ram,0x005477bb) */

void FUN_00547750(void)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090837e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 1;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  if (*(int *)(in_ECX + 0x30) != *(int *)(in_ECX + 0x34)) {
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x30);
  }
  if ((DAT_00fb7a20 & 1) == 0) {
    DAT_00fb7a20 = DAT_00fb7a20 | 1;
    local_8 = 0;
    FUN_00548da0(uVar1);
    _atexit(FUN_00bcd370);
  }
  DAT_00fb7ad0 = 0;
  DAT_00fb7ae0 = 0;
  DAT_00fb7af0 = 0;
  ExceptionList = local_10;
  return;
}


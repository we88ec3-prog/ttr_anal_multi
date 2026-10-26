
void FUN_0054e080(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ed96;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x40) != 0) {
    iVar3 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 2;
    if ((iVar3 == 0) ||
       (*(int *)(in_ECX + 0x44) <= *(int *)(*(int *)(*(int *)(in_ECX + 8) + -4 + iVar3 * 4) + 0x24))
       ) {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 0;
        FUN_00798de0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
      iVar3 = DAT_00fb76e8;
      uVar1 = DAT_00fb79e8 & 1;
      *(undefined4 *)(DAT_00fb76e8 + 0xc) = *(undefined4 *)(in_ECX + 0x18);
      *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(in_ECX + 0x1c);
      *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(in_ECX + 0x20);
      *(undefined4 *)(iVar3 + 0xcc) = 0;
      if (uVar1 == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 1;
        FUN_00798de0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
      iVar3 = DAT_00fb76e8;
      uVar1 = DAT_00fb79e8 & 1;
      *(undefined4 *)(DAT_00fb76e8 + 0x18) = *(undefined4 *)(in_ECX + 0x24);
      *(undefined4 *)(iVar3 + 0xcc) = 0;
      if (uVar1 == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 2;
        FUN_00798de0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
      iVar3 = DAT_00fb76e8;
      uVar1 = DAT_00fb79e8 & 1;
      *(undefined4 *)(DAT_00fb76e8 + 0x20) = *(undefined4 *)(in_ECX + 0x28);
      *(undefined4 *)(iVar3 + 0xcc) = 0;
      if (uVar1 == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 3;
        FUN_00798de0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
      iVar3 = DAT_00fb76e8;
      uVar1 = DAT_00fb79e8 & 1;
      *(undefined4 *)(DAT_00fb76e8 + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
      *(undefined4 *)(iVar3 + 0xcc) = 0;
      if (uVar1 == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 4;
        FUN_00798de0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
      iVar3 = DAT_00fb76e8;
      *(undefined4 *)(DAT_00fb76e8 + 0x24) = *(undefined4 *)(in_ECX + 0x30);
      *(undefined4 *)(iVar3 + 0xcc) = 0;
    }
  }
  ExceptionList = local_10;
  return;
}


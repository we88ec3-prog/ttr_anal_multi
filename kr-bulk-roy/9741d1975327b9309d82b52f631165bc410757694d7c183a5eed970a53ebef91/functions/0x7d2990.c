
void FUN_007d2990(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091888e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00523e40(in_ECX + 0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fe1bc0 & 1) == 0) {
    DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
    local_8 = 0;
    FUN_007bef00();
    _atexit((_func_4879 *)&LAB_00bcec50);
    local_8 = 0xffffffff;
  }
  local_1c = *(undefined4 *)(in_ECX + 8);
  local_18 = *(undefined4 *)(in_ECX + 0xc);
  FUN_004dd400(&DAT_00fe1b60,&local_14,&local_1c);
  if ((local_14 != DAT_00fe1b64) && (iVar1 = *(int *)(local_14 + 0x18), iVar1 != 0)) {
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + -1;
    uVar2 = 0;
    if (*(int *)(iVar1 + 0x2c) - *(int *)(iVar1 + 0x28) >> 2 != 0) {
      do {
        (**(code **)(**(int **)(*(int *)(iVar1 + 0x28) + uVar2 * 4) + 8))();
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)(*(int *)(iVar1 + 0x2c) - *(int *)(iVar1 + 0x28) >> 2));
    }
  }
  ExceptionList = local_10;
  return;
}


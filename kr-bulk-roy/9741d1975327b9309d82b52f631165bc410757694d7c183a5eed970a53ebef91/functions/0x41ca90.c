
void FUN_0041ca90(void)

{
  int iVar1;
  int in_ECX;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00927cfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  if (DAT_00fb7284 - DAT_00fb7280 >> 2 != 0) {
    do {
      iVar1 = local_14 * 4;
      FUN_0046b6f0(*(undefined4 *)(*(int *)(iVar1 + DAT_00fb7280) + 4));
      if (*(char *)(*(int *)(iVar1 + DAT_00fb7280) + 8) == '\0') {
        (**(code **)(**(int **)(iVar1 + *(int *)(in_ECX + 0xe0)) + 0x94))(0);
      }
      local_14 = local_14 + 1;
    } while (local_14 < (uint)(DAT_00fb7284 - DAT_00fb7280 >> 2));
  }
  FUN_006b57d0();
  FUN_0041c2b0();
  ExceptionList = local_10;
  return;
}


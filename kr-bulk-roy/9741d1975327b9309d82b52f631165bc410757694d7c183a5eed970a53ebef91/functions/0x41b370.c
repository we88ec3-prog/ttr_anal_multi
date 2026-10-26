
void FUN_0041b370(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093449e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0();
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(param_1 + 0xf4);
  if (*(int *)(iVar1 + 0x210) != *(int *)(iVar1 + 0x214)) {
    uVar2 = FUN_00692570();
    FUN_006925b0();
    *(undefined4 *)(iVar1 + 0x214) = uVar2;
  }
  uVar3 = 0;
  if (DAT_00fb7294 - DAT_00fb7290 >> 2 != 0) {
    do {
      FUN_004a78b0(*(undefined4 *)(DAT_00fb7290 + uVar3 * 4));
      FUN_00691240();
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(DAT_00fb7294 - DAT_00fb7290 >> 2));
  }
  FUN_00691440();
  ExceptionList = local_10;
  return;
}


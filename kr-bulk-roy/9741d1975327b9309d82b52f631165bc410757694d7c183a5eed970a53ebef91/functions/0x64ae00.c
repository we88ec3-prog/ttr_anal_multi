
void FUN_0064ae00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int local_28;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00933216;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0();
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_8 = 0xffffffff;
  FUN_004462a0();
  local_8 = 1;
  iVar1 = *(int *)(param_1 + 0x110);
  if (*(int *)(iVar1 + 0x210) != *(int *)(iVar1 + 0x214)) {
    uVar2 = FUN_00692570();
    FUN_006925b0();
    *(undefined4 *)(iVar1 + 0x214) = uVar2;
  }
  uVar3 = local_24 - local_28 >> 2;
  uVar4 = 0;
  if (uVar3 != 0) {
    do {
      FUN_004a78b0(*(undefined4 *)(local_28 + uVar4 * 4));
      FUN_00691240();
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  FUN_00691440();
  if (local_28 != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}


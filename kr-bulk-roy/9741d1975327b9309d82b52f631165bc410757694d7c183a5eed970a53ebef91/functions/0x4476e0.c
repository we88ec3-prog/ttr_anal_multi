
void FUN_004476e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00945266;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb93cc & 1) == 0) {
    DAT_00fb93cc = DAT_00fb93cc | 1;
    local_c = 0;
    FUN_00445460();
    _atexit((_func_4879 *)&LAB_00bcd620);
  }
  local_c = 0xffffffff;
  FUN_004462a0();
  local_c = 1;
  iVar1 = *(int *)(param_1 + 0x118);
  if (*(int *)(iVar1 + 0x220) != *(int *)(iVar1 + 0x224)) {
    uVar2 = FUN_00692570();
    FUN_006925b0();
    *(undefined4 *)(iVar1 + 0x224) = uVar2;
  }
  uVar4 = local_24 - local_28 >> 2;
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      FUN_004453e0(*(undefined4 *)(local_28 + uVar3 * 4));
      FUN_00691340();
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  FUN_006915e0();
  if (local_28 != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_14;
  return;
}



void FUN_006823c0(undefined4 param_1,int param_2)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  int iVar7;
  int local_28;
  int local_24;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093cae8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = *(int *)(param_2 + 0x14);
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_28 = iVar1;
  FUN_008438c0(&local_28);
  if (local_24 == DAT_00f8d91c) {
    local_28 = 0;
  }
  else {
    local_28 = *(int *)(local_24 + 0x10);
  }
  if (*(int *)(*(int *)(local_28 + 0x54) + 0xc) < 2) {
    FUN_00682640(iVar1,1);
    ExceptionList = local_14;
    return;
  }
  local_1c[0] = 0;
  if ((DAT_00fe1da0 & 1) == 0) {
    DAT_00fe1da0 = DAT_00fe1da0 | 1;
    local_c = 1;
    FUN_00830870();
    _atexit(FUN_00bcee30);
    local_c = 0xffffffff;
  }
  local_24 = iVar1;
  FUN_0082ef00(&local_24);
  if (local_20 == DAT_00fe1da8) {
    bVar6 = 0;
  }
  else {
    bVar6 = **(byte **)(local_20 + 0x10);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  cVar2 = FUN_004d9d20(DAT_00f94308,0xc);
  if ((cVar2 != '\0') && (bVar6 != 0)) {
    bVar6 = bVar6 + 1;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 3;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar7 = DAT_00f94314;
  local_1c[0] = iVar1;
  FUN_0082ef00(local_1c);
  if (local_20 == *(int *)(iVar7 + 4)) {
    bVar3 = 0;
  }
  else {
    bVar3 = *(byte *)(*(int *)(local_20 + 0x10) + 4);
  }
  if (bVar6 == 0) {
    iVar7 = *(int *)(*(int *)(local_28 + 0x54) + 0xc);
  }
  else {
    iVar7 = (uint)bVar6 - (uint)bVar3;
  }
  puVar4 = (undefined4 *)FUN_00891268(8);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[1] = iVar1;
    *puVar4 = FUI::QUANTITYDATA_BUYITEM::vftable;
  }
  puVar5 = (undefined4 *)FUN_00891268(0x2c);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_004072a0();
    ExceptionList = local_14;
    return;
  }
  puVar5[1] = 0xffffffff;
  puVar5[2] = 0xffffffff;
  puVar5[6] = 1;
  puVar5[7] = 1;
  puVar5[8] = iVar7;
  puVar5[3] = 0;
  puVar5[4] = 0xf4310;
  *puVar5 = FoxUI::FXUIEventI4P2::vftable;
  puVar5[5] = 0xf43a4;
  puVar5[9] = puVar4;
  puVar5[10] = param_1;
  FUN_004072a0();
  ExceptionList = local_14;
  return;
}


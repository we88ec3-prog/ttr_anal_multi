
void FUN_00667200(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  short *psVar6;
  short *psVar7;
  undefined2 auStack_5c [8];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 *puStack_40;
  undefined2 local_22;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933174;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = *(undefined4 **)(param_1 + 0x114);
  if (puVar2[0x19] == 0) {
    if (*(char *)(param_1 + 0x130) != '\0') {
      puStack_40 = (undefined4 *)param_1;
      uStack_44 = 0x6673c1;
      FUN_00668520();
    }
    ExceptionList = local_10;
    return;
  }
  uVar3 = *puVar2;
  uVar4 = puVar2[1];
  FUN_004adcd0();
  local_22 = 0x94;
  local_20 = uVar3;
  local_1c = uVar4;
  if (DAT_00fba798 == 0) {
    puStack_40 = (undefined4 *)&local_22;
    uStack_44 = 0;
    uStack_48 = 0x667272;
    (**(code **)(*DAT_00fba854 + 0x10))();
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    puStack_40 = (undefined4 *)0x667294;
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puStack_40 = (undefined4 *)0x6672a9;
  puStack_40 = (undefined4 *)FUN_00891268();
  if (puStack_40 == (undefined4 *)0x0) {
    puStack_40 = (undefined4 *)0x0;
  }
  else {
    *puStack_40 = FoxUI::FXUIEvent::vftable;
    puStack_40[1] = 0xffffffff;
    puStack_40[2] = 0xffffffff;
    puStack_40[3] = 0;
    puStack_40[4] = 0xf4319;
  }
  local_18 = (undefined1 *)auStack_5c;
  uStack_48 = 7;
  uStack_4c = 0;
  auStack_5c[0] = 0;
  FUN_00402160();
  local_8 = 1;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_005740f0();
  if (local_14 == DAT_00fe5b10) {
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  psVar7 = (short *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  psVar6 = psVar7;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(199);
  ExceptionList = local_10;
  return;
}


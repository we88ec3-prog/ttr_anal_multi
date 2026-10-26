
void FUN_005ac6e0(void)

{
  short sVar1;
  code *pcVar2;
  undefined4 *puVar3;
  short *psVar4;
  short *psVar5;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009336b4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar3 = (undefined4 *)FUN_00891268();
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = FoxUI::FXUIEvent::vftable;
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4321;
  }
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
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar5 = (short *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    psVar5 = *(short **)psVar5;
  }
  psVar4 = psVar5;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(200);
  ExceptionList = local_10;
  return;
}


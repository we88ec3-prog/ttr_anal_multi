
void FUN_005620b0(void)

{
  short sVar1;
  code *pcVar2;
  undefined4 *puVar3;
  short *psVar4;
  short *psVar5;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ec52;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  DAT_00fb8830 = DAT_00fb8830 | 2;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
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
    puVar3[4] = 0xf4322;
  }
  FUN_00402160();
  local_8 = 2;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,2);
  }
  FUN_005740f0();
  if (local_18 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar5 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
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


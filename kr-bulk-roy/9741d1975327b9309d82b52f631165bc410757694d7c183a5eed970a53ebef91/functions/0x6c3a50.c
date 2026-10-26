
void FUN_006c3a50(void)

{
  short sVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 *puVar4;
  short *psVar5;
  int in_ECX;
  short *psVar6;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00933054;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar4 = (undefined4 *)FUN_00891268();
  if (puVar4 != (undefined4 *)0x0) {
    uVar2 = *(undefined4 *)(in_ECX + 0xb4);
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf43fb;
    *puVar4 = FoxUI::FXUIEventI1::vftable;
    puVar4[5] = uVar2;
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
  if (local_18 == DAT_00fe5b10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  psVar6 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar6 = *(short **)psVar6;
  }
  psVar5 = psVar6;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xcf);
  ExceptionList = local_10;
  return;
}


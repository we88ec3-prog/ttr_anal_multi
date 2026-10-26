
void FUN_00604e20(undefined4 param_1,int param_2)

{
  short sVar1;
  code *pcVar2;
  char cVar3;
  short *psVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 in_ECX;
  int in_EDX;
  short *psVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00946cd4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  cVar3 = FUN_00605060();
  if (cVar3 != '\0') {
    iVar5 = FUN_00404ba0();
    if (((in_EDX == 1) && (*(int *)(iVar5 + 0x6920) != -0x16f8)) &&
       (iVar5 = FUN_00508da0(), iVar5 != 0)) {
      if (1 < *(int *)(iVar5 + 8)) {
        puVar6 = (undefined4 *)FUN_00891268();
        if (puVar6 != (undefined4 *)0x0) {
          puVar6[1] = 1;
          *puVar6 = FUI::QUANTITYDATA_ITEMTRADE::vftable;
          puVar6[2] = in_ECX;
          puVar6[3] = param_2;
        }
        iVar5 = FUN_00891268();
        if (iVar5 == 0) {
          FUN_004072a0();
          ExceptionList = local_10;
          return;
        }
        FUN_00753eb0();
        FUN_004072a0();
        ExceptionList = local_10;
        return;
      }
      FUN_00604ba0();
    }
    ExceptionList = local_10;
    return;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
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
  if (param_2 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar7 = (short *)(param_2 + 0x10);
  if (7 < *(uint *)(param_2 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  psVar4 = psVar7;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar4 - (int)(psVar7 + 1) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  return;
}


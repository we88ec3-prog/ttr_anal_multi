
void FUN_0069d480(void)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  short *psVar4;
  undefined4 uVar5;
  int unaff_EDI;
  undefined1 auStack_7c [4];
  undefined4 uStack_78;
  int iStack_74;
  uint local_70;
  int local_60;
  uint local_5c;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c744;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff80);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (*(int *)(unaff_EDI + 0x110) != DAT_00f94244) {
    *(int *)(unaff_EDI + 0x110) = DAT_00f94244;
    psVar3 = (short *)FUN_00412df0();
    local_c = 1;
    if (7 < *(uint *)(psVar3 + 10)) {
      psVar3 = *(short **)psVar3;
    }
    local_70 = local_70 & 0xffff0000;
    local_5c = 7;
    local_60 = 0;
    psVar4 = psVar3;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
    local_c._0_1_ = 3;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    local_40 = 7;
    local_44 = 0;
    local_54 = local_54 & 0xffff0000;
    if (local_60 == 0) {
      FUN_00402160(&DAT_00bf9280,1);
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 4;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 3;
    }
    uStack_78 = 0x1a;
    FUN_005740f0(&uStack_78);
    if (iStack_74 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar5 = FUN_004ed610();
    local_c._0_1_ = 5;
    FUN_00757800(uVar5);
    local_c = CONCAT31(local_c._1_3_,3);
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    (**(code **)(**(int **)(unaff_EDI + 0x10c) + 200))();
    if (7 < local_5c) {
      FUN_0089120c(local_70);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
}


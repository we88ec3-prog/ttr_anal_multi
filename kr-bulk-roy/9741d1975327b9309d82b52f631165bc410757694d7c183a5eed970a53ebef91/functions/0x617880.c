
undefined4 FUN_00617880(int param_1)

{
  short sVar1;
  code *pcVar2;
  undefined4 uVar3;
  short *psVar4;
  short *psVar5;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e0c0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (DAT_00f9392c != 4) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    if (DAT_00f9392c != 2) {
      ExceptionList = local_14;
      return 0;
    }
  }
  if (param_1 != 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 2;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    FUN_00402160();
    local_c = 3;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 4;
      local_c._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,3);
    }
    FUN_005740f0();
    if (local_20 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    psVar5 = (short *)(local_20 + 0x10);
    if (7 < *(uint *)(local_20 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
  }
  ExceptionList = local_14;
  return 1;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004f2260(void)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  undefined4 uVar4;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092f7c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0xffffffff;
  FUN_004f6a30();
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8 = 2;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8 = 0xffffffff;
  }
  FUN_005740f0();
  if (local_18 != DAT_00fe5b10) {
    psVar3 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar3 = *(short **)psVar3;
    }
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_8 = 3;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 4;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,3);
    }
    FUN_005740f0();
    if (DAT_00fe5b10 != 0x197) {
      FUN_004ed610();
      local_8 = 0xffffffff;
      FUN_0058b270(0xca);
      FUN_004f2c40();
      ExceptionList = local_10;
      return 0;
    }
    pcVar2 = (code *)swi(3);
    uVar4 = (*pcVar2)();
    return uVar4;
  }
  pcVar2 = (code *)swi(3);
  uVar4 = (*pcVar2)();
  return uVar4;
}



undefined4 FUN_004e88a0(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  short *psVar6;
  int in_ECX;
  short *psVar7;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009301b0;
  local_10 = ExceptionList;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
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
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    psVar7 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    psVar6 = psVar7;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
    FUN_004ec690();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 3;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0();
  }
  else {
    if (cVar1 == '\x01') {
      ExceptionList = &local_10;
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 4;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      FUN_00402160();
      local_8 = 5;
      iVar5 = FUN_005854b0();
      FUN_005740f0();
      if (in_ECX == *(int *)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        uVar4 = (*pcVar3)();
        return uVar4;
      }
      psVar7 = (short *)(in_ECX + 0x10);
      if (7 < *(uint *)(in_ECX + 0x24)) {
        psVar7 = *(short **)psVar7;
      }
      psVar6 = psVar7;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
    }
    else {
      if (cVar1 != '\x02') {
        return 0;
      }
      ExceptionList = &local_10;
      FUN_004054c0();
      FUN_00402250();
      local_8 = 6;
      FUN_005854b0();
      uVar4 = FUN_00585330();
      FUN_00402250(uVar4);
    }
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
  ExceptionList = local_10;
  return 0;
}


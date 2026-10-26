
undefined4 FUN_004fe6c0(int param_1)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  undefined4 uVar5;
  short *psVar6;
  int in_ECX;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f75e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 2) == '\0') {
    FUN_004ff080();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar5 = (*pcVar2)();
      return uVar5;
    }
    psVar4 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
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
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar5 = (*pcVar2)();
      return uVar5;
    }
    psVar4 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    psVar6 = psVar4;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 4;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '\x01') {
      FUN_006edb60();
      ExceptionList = local_10;
      return 0x80004005;
    }
    uVar3 = DAT_00faadd4 & 1;
    *(undefined4 *)(in_ECX + 0x5eac) = 4;
    *(undefined4 *)(in_ECX + 0x6240) = 0;
    if (uVar3 == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
  }
  FUN_0058aad0();
  ExceptionList = local_10;
  return 0;
}


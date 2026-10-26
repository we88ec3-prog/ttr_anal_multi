
/* WARNING: Removing unreachable block (ram,0x004b4659) */

void FUN_004b45b0(int param_1)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  short *psVar5;
  short *psVar6;
  int local_38;
  int local_34;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00930bd2;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 2) == '\0') {
    FUN_0040b310();
    local_8 = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    piVar4 = (int *)FUN_0080ab00();
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))();
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 2;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
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
    local_38 = 0xb6;
    FUN_005740f0();
    if (local_34 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar6 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
  if (*(char *)(param_1 + 2) == '\x12') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_00402160();
    local_8 = 6;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 7;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,6);
    }
    FUN_005740f0();
    if (local_38 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar6 = (short *)(local_38 + 0x10);
    if (7 < *(uint *)(local_38 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
  if (*(char *)(param_1 + 2) == '\x05') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 8;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_00402160();
    local_8 = 9;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 10;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,9);
    }
    FUN_005740f0();
    if (local_38 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar6 = (short *)(local_38 + 0x10);
    if (7 < *(uint *)(local_38 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}


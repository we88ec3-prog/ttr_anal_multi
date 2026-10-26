
/* WARNING: Removing unreachable block (ram,0x004b4a7a) */

void FUN_004b49d0(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  uint uVar4;
  int *piVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  short *psVar9;
  int local_38;
  int local_34;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00930b28;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
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
    piVar5 = (int *)FUN_0080ab00();
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x14))();
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
    FUN_005740f0();
    if (local_34 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar9 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar9 = *(short **)psVar9;
    }
    psVar6 = psVar9;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar9,(int)psVar6 - (int)(psVar9 + 1) >> 1);
  }
  else if (cVar1 == '\x12') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    local_8 = 6;
    iVar7 = FUN_005854b0();
    FUN_005740f0();
    if (local_38 == *(int *)(iVar7 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar9 = (short *)(local_38 + 0x10);
    if (7 < *(uint *)(local_38 + 0x24)) {
      psVar9 = *(short **)psVar9;
    }
    psVar6 = psVar9;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar9,(int)psVar6 - (int)(psVar9 + 1) >> 1);
  }
  else {
    if (cVar1 != '\x05') goto LAB_004b4ca0;
    FUN_004054c0();
    FUN_00402250();
    local_8 = 7;
    FUN_005854b0();
    uVar8 = FUN_00585330();
    FUN_00402250(uVar8);
  }
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
LAB_004b4ca0:
  ExceptionList = local_10;
  __security_check_cookie(uVar4 ^ (uint)&stack0xfffffffc);
  return;
}


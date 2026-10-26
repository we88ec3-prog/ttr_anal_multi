
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00442fa0(int param_1,int *param_2)

{
  short sVar1;
  code *pcVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  int local_44;
  int local_40;
  int local_30;
  int local_2c;
  int local_20;
  char local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00945434;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_00442470();
  piVar3 = (int *)(param_1 + 0x10c);
  iVar5 = 0;
  do {
    if ((((*param_2 != iVar5) && (-1 < piVar3[-1])) && (-1 < *piVar3)) && (piVar3[3] != local_20))
    goto LAB_004431c6;
    iVar5 = iVar5 + 1;
    piVar3 = piVar3 + 8;
  } while (iVar5 < 2);
  if ((local_30 < 0) || (local_2c < 0)) {
LAB_004431c6:
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 1;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    FUN_005740f0();
    if (local_44 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    psVar6 = (short *)(local_44 + 0x10);
    if (7 < *(uint *)(local_44 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_c = 2;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 3;
      local_c._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,2);
    }
    FUN_005740f0();
    if (local_44 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    psVar6 = (short *)(local_44 + 0x10);
    psVar7 = psVar6;
    if (7 < *(uint *)(local_44 + 0x24)) {
      psVar6 = *(short **)psVar6;
      psVar7 = psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
  }
  else {
    if (local_1c == '\0') {
      ExceptionList = local_14;
      return CONCAT31((int3)((uint)piVar3 >> 8),1);
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 4;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 5;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    FUN_005740f0();
    if (local_40 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    psVar6 = (short *)(local_40 + 0x10);
    if (7 < *(uint *)(local_40 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_c = 6;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 7;
      local_c._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,6);
    }
    FUN_005740f0();
    if (DAT_00fe5b10 == 0x196) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    psVar6 = (short *)&DAT_000001a6;
    psVar7 = (short *)&DAT_000001a6;
    if (7 < _DAT_000001ba) {
      psVar6 = _DAT_000001a6;
      psVar7 = _DAT_000001a6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
  }
  FUN_00402160(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
  local_c = 0xffffffff;
  uVar4 = FUN_0058b270(0xca);
  ExceptionList = local_14;
  return uVar4 & 0xffffff00;
}


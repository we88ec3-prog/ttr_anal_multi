
void FUN_005035d0(int param_1)

{
  short sVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  int iVar7;
  undefined2 *puVar8;
  int *local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00943ff1;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(local_14);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  piVar3 = (int *)FUN_00891268(0x18);
  local_54 = (int *)0x0;
  if (piVar3 != (int *)0x0) {
    iVar7 = *(int *)(param_1 + 2);
    piVar3[3] = 0;
    piVar3[1] = -1;
    piVar3[2] = -1;
    piVar3[4] = 0xf4280;
    *piVar3 = (int)FoxUI::FXUIEventI1::vftable;
    piVar3[5] = iVar7;
    local_54 = piVar3;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  FUN_00804260(&local_54);
  if (*(int *)(param_1 + 2) == 0) {
    puVar8 = (undefined2 *)(local_50 + 0x5ed0);
    iVar7 = 0x14;
    do {
      FUN_0040f060();
      FUN_0053dc90(*puVar8);
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar7 = FUN_0040f060();
    FUN_00500240(local_50,*(undefined4 *)(iVar7 + 0x8c));
    local_54 = (int *)FUN_00891268(0xc4);
    local_8 = 2;
    if (local_54 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005016f0(&DAT_00bed1fc,4);
    }
    if ((DAT_00fb7354 & 1) == 0) {
      DAT_00fb7354 = DAT_00fb7354 | 1;
      local_8 = 3;
      FUN_005533d0();
      _atexit((_func_4879 *)&LAB_00bcd100);
    }
    local_8 = 0xffffffff;
    (**(code **)(*piVar3 + 4))();
    (**(code **)(*piVar3 + 0x20))(DAT_00fb73ac,DAT_00fb73b0);
    piVar3[0x10] = 0;
    local_54 = piVar3;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00fb7378,uVar4);
    DAT_00fb7398 = DAT_00fb7398 + 1;
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8 = 4;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
      local_8 = 0xffffffff;
    }
    local_54 = (int *)0x15;
    FUN_005740f0(&local_54);
    if (local_50 == DAT_00fe5aec) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)FUN_0040aff0();
    local_8 = 5;
    if (7 < *(uint *)(psVar5 + 10)) {
      psVar5 = *(short **)psVar5;
    }
    local_30 = (uint)local_30._2_2_ << 0x10;
    local_1c = 7;
    local_20 = 0;
    psVar6 = psVar5;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 7;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004d6b30(&local_30);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



void FUN_005027d0(int param_1)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  short *psVar7;
  short *psVar8;
  int in_ECX;
  int *piVar9;
  int iVar10;
  int iVar11;
  int local_74;
  int local_70;
  int *local_6c;
  undefined4 local_68;
  uint local_54;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094014b;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar11 = *(int *)(in_ECX + 0x5eac);
  iVar10 = (int)*(short *)(param_1 + 2);
  local_74 = iVar10;
  local_14 = uVar3;
  FUN_00503d20(&local_74);
  piVar5 = local_6c;
  if ((local_6c != *(int **)(iVar11 + 4)) && (piVar9 = (int *)0x0, local_6c != (int *)0xfffffff0)) {
    if (local_6c[0x15] == 2) {
      iVar11 = local_6c[0x16];
      FUN_00422f40(iVar10,iVar11,uVar3);
      FUN_00561760(iVar10,iVar11);
    }
    else if (local_6c[0x15] == 3) {
      FUN_004054c0();
      puVar4 = (undefined4 *)FUN_00891268(0x18);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_0058aa50(0);
      }
      else {
        iVar11 = piVar5[0x14];
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf4306;
        *puVar4 = FoxUI::FXUIEventI1::vftable;
        puVar4[5] = iVar11;
        FUN_0058aa50(puVar4);
      }
      goto LAB_00502b20;
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30 = local_30 & 0xffffff00;
    FUN_0040b310("QUEST_READY");
    local_8 = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    piVar5 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x14))();
    }
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30 = local_30 & 0xffffff00;
    piVar5 = (int *)FUN_00891268(0xc4);
    local_8 = 2;
    if (piVar5 != (int *)0x0) {
      piVar9 = local_6c + 0x17;
      if (7 < (uint)local_6c[0x1c]) {
        piVar9 = (int *)*piVar9;
      }
      local_6c = piVar5;
      piVar9 = (int *)FUN_005016f0(piVar9,2);
      piVar5 = local_6c;
    }
    local_6c = piVar5;
    if ((DAT_00fb7354 & 1) == 0) {
      DAT_00fb7354 = DAT_00fb7354 | 1;
      local_8 = 3;
      FUN_005533d0();
      _atexit((_func_4879 *)&LAB_00bcd100);
    }
    local_8 = 0xffffffff;
    (**(code **)(*piVar9 + 4))();
    (**(code **)(*piVar9 + 0x20))(DAT_00fb73ac,DAT_00fb73b0);
    piVar9[0x10] = 0;
    local_70 = DAT_00fb7398;
    local_6c = piVar9;
    uVar6 = FUN_0057ef20();
    FUN_0082f200(&DAT_00fb7378,uVar6);
    DAT_00fb7398 = DAT_00fb7398 + 1;
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8 = 4;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
      local_8 = 0xffffffff;
    }
    local_6c = (int *)0x13;
    FUN_005740f0(&local_6c);
    if (local_74 == DAT_00fe5aec) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar7 = (short *)FUN_004ed610();
    local_8 = 5;
    if (7 < *(uint *)(psVar7 + 10)) {
      psVar7 = *(short **)psVar7;
    }
    local_4c = (uint)local_4c._2_2_ << 0x10;
    local_38 = 7;
    local_3c = 0;
    psVar8 = psVar7;
    do {
      sVar1 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 7;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004d6b30(&local_4c);
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c = local_4c & 0xffff0000;
    if (7 < local_54) {
      FUN_0089120c(local_68);
    }
  }
LAB_00502b20:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


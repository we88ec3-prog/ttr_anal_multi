
void FUN_005fcc60(int param_1)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  short *psVar7;
  int in_ECX;
  int in_EDX;
  short *psVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auStack_cc [4];
  short *local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  uint local_94;
  undefined1 auStack_8c [56];
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093eb59;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_cc;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff28;
  ExceptionList = &local_14;
  local_c0 = param_1;
  *(undefined2 *)(in_ECX + 0x144) = 0;
  local_b4 = in_ECX;
  FUN_00402160(&DAT_00bed1fc,0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if ((in_EDX != 1) || (iVar4 = DAT_00f94300 + 0x16f8, iVar4 == 0)) goto LAB_005fd053;
  if (99 < local_c0 - 1U) {
    FUN_006edb60(&DAT_00c0ddc0);
    goto LAB_005fd053;
  }
  iVar1 = local_c0 * 0x20 + iVar4;
  local_bc = iVar1;
  if (((*(int *)(local_c0 * 0x20 + 0xc + iVar4) == 0) || (*(int *)(iVar1 + 8) == 0)) || (iVar1 == 0)
     ) goto LAB_005fd053;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_c = 0xffffffff;
  }
  local_c8 = *(short **)(iVar1 + 0xc);
  FUN_008438c0(&local_c8);
  if (local_c4 == DAT_00f8d91c) {
    local_c8 = (short *)0x0;
  }
  else {
    local_c8 = *(short **)(local_c4 + 0x10);
  }
  local_b0 = *(undefined4 *)(iVar1 + 0x10);
  local_ac = *(undefined4 *)(iVar1 + 0x14);
  iVar4 = FUN_00409560();
  FUN_004dd400(iVar4,&local_c4,&local_b0);
  psVar7 = local_c8;
  if ((local_c4 == *(int *)(iVar4 + 4)) || (iVar4 = *(int *)(local_c4 + 0x18), iVar4 == 0)) {
LAB_005fcf28:
    psVar8 = local_c8;
    if (7 < *(uint *)(local_c8 + 10)) {
      psVar8 = *(short **)local_c8;
    }
    psVar6 = psVar8;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
  }
  else {
    *(bool *)(in_ECX + 0x145) = 0 < *(int *)(iVar4 + 0x30);
    *(bool *)(in_ECX + 0x144) = *(int *)(iVar4 + 0x48) - *(int *)(iVar4 + 0x44) >> 3 != 0;
    if (*(int *)(iVar4 + 0x30) == 0) goto LAB_005fcf28;
    if (7 < *(uint *)(local_c8 + 10)) {
      psVar7 = *(short **)local_c8;
    }
    uVar9 = 0x18;
    FUN_00585620(0x18,psVar7);
    FUN_00585330(uVar9);
    uVar9 = FUN_00483f00();
    local_c = 2;
    FUN_00402800(uVar9);
    local_c = 0xffffffff;
    psVar7 = local_c8;
    if (7 < local_94) {
      FUN_0089120c(local_a8);
      psVar7 = local_c8;
    }
  }
  iVar4 = *(int *)(psVar7 + 0x2a);
  if ((iVar4 == 0) || ((*(int *)(iVar4 + 8) != 6 && (*(int *)(iVar4 + 8) != 0x2d)))) {
    if (*(int *)(iVar4 + 8) == 0x15) {
      for (piVar5 = *(int **)(iVar4 + 0x148); piVar5 != *(int **)(iVar4 + 0x14c);
          piVar5 = piVar5 + 1) {
        if (*(short *)(*piVar5 + 8) == 0xc) goto LAB_005fcf5d;
      }
    }
    iVar4 = FUN_00891268(0x1c);
    if (iVar4 == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = FUN_00753e00(0xf4398,local_c0);
    }
    psVar7 = local_c8;
    if (7 < *(uint *)(local_c8 + 10)) {
      psVar7 = *(short **)local_c8;
    }
    uVar10 = 0xe9;
    FUN_005854b0(0xe9,psVar7);
    FUN_00585330(uVar10);
    uVar10 = FUN_00483f00();
    local_c = 3;
    FUN_007574a0(uVar10);
    uVar10 = 0x196;
    local_c._0_1_ = 4;
    FUN_005854b0(0x196);
    uVar10 = FUN_00585330(uVar10);
    uVar10 = FUN_007572f0(uVar10);
    local_c._0_1_ = 5;
    FUN_00407330(0xcf,auStack_8c,uVar10,uVar9,local_b4);
    local_c._0_1_ = 4;
    FUN_00757640(auStack_54);
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_00757640(auStack_8c);
    FUN_004fa440();
  }
  else {
LAB_005fcf5d:
    uVar9 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar9 = FUN_00585330(uVar9);
    uVar10 = 0xed;
    FUN_005854b0(0xed,uVar9);
    uVar9 = FUN_00585330(uVar10);
    FUN_00404b10(0xca,uVar9);
  }
LAB_005fd053:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_cc);
  return;
}


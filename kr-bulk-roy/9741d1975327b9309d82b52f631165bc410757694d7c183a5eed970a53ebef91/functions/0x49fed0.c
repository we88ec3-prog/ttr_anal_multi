
void FUN_0049fed0(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  undefined4 uVar8;
  int in_ECX;
  byte *pbVar9;
  int iVar10;
  bool bVar11;
  int local_148;
  int local_144;
  int local_140;
  byte local_13c;
  undefined2 local_13b;
  int local_138;
  uint local_134 [4];
  undefined4 local_124;
  uint local_120;
  undefined1 local_118 [256];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927959;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar6 = (int *)(param_1 + 0xc);
  local_144 = param_1;
  iVar10 = *piVar6;
  local_148 = in_ECX;
  if (iVar10 != 0) {
    if (*(int *)(iVar10 + 8) != 0) {
      (**(code **)(**(int **)(iVar10 + 8) + 0x24))(local_18);
    }
    *(undefined4 *)(*piVar6 + 0xc) = 1;
    *piVar6 = 0;
  }
  local_138 = 0;
  iVar10 = 0x20;
  do {
    if (iVar10 < 0) {
      if (local_138 == 0) goto LAB_004a0128;
      break;
    }
    FUN_004a0930("Sound/Scenario/%02d/Locale",iVar10);
    local_140 = 0;
    iVar5 = FUN_00714550(local_118);
    if ((iVar5 == 0) ||
       (piVar6 = (int *)FUN_00714770(local_118,&DAT_00bed1e0), piVar6 == (int *)0x0)) {
LAB_004a0014:
      local_138 = FUN_0049fd10("Scenario/%02d/V%05d.ogg",iVar10,local_148);
    }
    else {
      iVar5 = (**(code **)(*piVar6 + 0x2c))();
      if (iVar5 == 2) {
        local_13b = 0;
        local_13c = 0;
        (**(code **)(*piVar6 + 0x10))(&local_13c,2,1);
        pbVar9 = &DAT_00c0612c;
        pbVar7 = &local_13c;
        do {
          bVar1 = *pbVar7;
          bVar11 = bVar1 < *pbVar9;
          if (bVar1 != *pbVar9) {
LAB_0049fff0:
            iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            goto LAB_0049fff5;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar7[1];
          bVar11 = bVar1 < pbVar9[1];
          if (bVar1 != pbVar9[1]) goto LAB_0049fff0;
          pbVar7 = pbVar7 + 2;
          pbVar9 = pbVar9 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_0049fff5:
        if (iVar5 == 0) {
          local_140 = 1;
        }
      }
      (**(code **)(*piVar6 + 4))();
      if (local_140 == 0) goto LAB_004a0014;
    }
    iVar10 = iVar10 + -1;
  } while (local_138 == 0);
  local_120 = 0xf;
  local_124 = 0;
  local_134[0] = local_134[0] & 0xffffff00;
  FUN_0040b310("Voice");
  local_8 = 0;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_148 = FUN_0080c1c0(local_134);
  if ((local_148 == DAT_00fab054) || (cVar4 = FUN_005436a0(), cVar4 != '\0')) {
    local_140 = DAT_00fab054;
    piVar6 = &local_140;
  }
  else {
    piVar6 = &local_148;
  }
  uVar8 = DAT_00fab04c;
  if (*piVar6 != DAT_00fab054) {
    uVar8 = *(undefined4 *)(*piVar6 + 0x28);
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(local_138 + 8) = uVar8;
  if (0xf < local_120) {
    FUN_0089120c(local_134[0]);
  }
LAB_004a0128:
  puVar2 = *(undefined4 **)(local_144 + 0x20);
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    if (*(int *)(puVar3[2] + 8) != 0) {
      (**(code **)(**(int **)(puVar3[2] + 8) + 0x24))();
    }
  }
  FUN_0049fe30(local_144 + 0xc);
  *(undefined4 *)(local_144 + 0x38) = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


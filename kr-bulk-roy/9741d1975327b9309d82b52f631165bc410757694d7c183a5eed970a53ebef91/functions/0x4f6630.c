
void FUN_004f6630(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined **local_e4 [19];
  uint local_98;
  undefined4 local_88;
  uint local_84;
  byte local_6c [4];
  uint local_68;
  undefined4 local_58;
  uint local_54;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924653;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  FUN_0072ee30(local_e4);
  local_8 = 0;
  cVar2 = FUN_0072f110(0);
  if (cVar2 != '\0') {
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffffff00;
    FUN_00402a70(&DAT_00bf2375,0);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0072e2e0("DAMAGESOUNDS");
    piVar5 = (int *)FUN_0072e2e0("BaseFolder");
    if ((piVar5 != (int *)0x0) && (iVar6 = (**(code **)(*piVar5 + 0x14))(), iVar6 != 0)) {
      iVar6 = FUN_007300a0(&DAT_00c0d5f0);
      if (iVar6 == 0) {
        pcVar10 = (char *)0x0;
      }
      else {
        pcVar10 = (char *)(iVar6 + 0x30);
        if (0xf < *(uint *)(iVar6 + 0x44)) {
          pcVar10 = *(char **)pcVar10;
        }
      }
      pcVar7 = pcVar10;
      do {
        cVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      FUN_00402a70(pcVar10,(int)pcVar7 - (int)(pcVar10 + 1));
    }
    FUN_0072e2e0("DAMAGESOUNDS");
    for (piVar5 = (int *)FUN_0072e2e0("DSOUND"); piVar5 != (int *)0x0; piVar5 = (int *)piVar5[0x10])
    {
      bVar3 = 0;
      iVar6 = (**(code **)(*piVar5 + 0x14))();
      if (iVar6 != 0) {
        iVar6 = FUN_007300a0("ATTACK");
        if (iVar6 == 0) {
LAB_004f6794:
          cVar2 = '\0';
        }
        else {
          puVar8 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_004f6794;
          cVar2 = FUN_008917b4(puVar8);
        }
        iVar6 = FUN_007300a0("DEFENSE");
        if (iVar6 != 0) {
          puVar8 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 != (undefined4 *)0x0) {
            bVar3 = FUN_008917b4(puVar8);
          }
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        FUN_00403040(local_4c,0,0xffffffff);
        local_8._0_1_ = 2;
        iVar6 = FUN_007300a0(&DAT_00c0561c);
        if (iVar6 == 0) {
          pcVar10 = (char *)0x0;
        }
        else {
          pcVar10 = (char *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            pcVar10 = *(char **)pcVar10;
          }
        }
        pcVar7 = pcVar10;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        FUN_00401fc0(pcVar10,(int)pcVar7 - (int)(pcVar10 + 1));
        local_6c[0] = cVar2 << 3 | bVar3 & 7;
        local_54 = 0xf;
        local_58 = 0;
        local_68 = local_68 & 0xffffff00;
        FUN_00403040(local_30,0,0xffffffff);
        local_8 = CONCAT31(local_8._1_3_,3);
        uVar9 = FUN_004f9a60(local_6c);
        FUN_004f90b0(&DAT_00fb7510,uVar9);
        if (0xf < local_54) {
          FUN_0089120c(local_68);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        local_54 = 0xf;
        local_58 = 0;
        local_68 = local_68 & 0xffffff00;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
      }
    }
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffffff00;
  }
  local_8 = 0xffffffff;
  local_e4[0] = TiXmlDocument::vftable;
  if (0xf < local_84) {
    FUN_0089120c(local_98,uVar4);
  }
  local_84 = 0xf;
  local_88 = 0;
  local_98 = local_98 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


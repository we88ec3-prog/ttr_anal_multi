
void FUN_00528d00(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 local_154;
  uint local_140;
  uint local_12c;
  uint local_124;
  uint local_110;
  uint local_104;
  uint local_f0;
  undefined **local_e8 [17];
  char local_a4;
  uint local_9c;
  undefined4 local_8c;
  uint local_88;
  undefined1 local_70;
  undefined1 local_6f;
  uint local_6c;
  undefined4 local_5c;
  uint local_58;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923899;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_e8);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_a4 == '\0') && (iVar3 = FUN_0072e2e0("PHASEEXPLAIN"), iVar3 != 0)) {
    iVar3 = FUN_0072e360(uVar2);
    while (iVar3 != 0) {
      iVar3 = FUN_007300a0(&DAT_00bfb82c);
      if (iVar3 == 0) {
LAB_00528e57:
        local_154 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00528e57;
        local_154 = FUN_008917b4(puVar4);
      }
      iVar3 = FUN_0072e360();
      while (iVar3 != 0) {
        local_58 = 7;
        local_3c = 7;
        local_5c = 0;
        local_6c = local_6c & 0xffff0000;
        local_40 = 0;
        local_50 = local_50 & 0xffff0000;
        local_8._1_3_ = (undefined3)(local_8 >> 8);
        local_8 = CONCAT31(local_8._1_3_,1);
        local_70 = local_154;
        for (iVar7 = *(int *)(iVar3 + 0x94); iVar7 != iVar3 + 0x44; iVar7 = *(int *)(iVar7 + 0x50))
        {
          pcVar9 = (char *)(iVar7 + 0x14);
          if (0xf < *(uint *)(iVar7 + 0x28)) {
            pcVar9 = *(char **)pcVar9;
          }
          iVar5 = __stricmp(pcVar9,"ID");
          if (iVar5 == 0) {
            if (iVar7 != 0) {
              puVar4 = (undefined4 *)(iVar7 + 0x30);
              if (0xf < *(uint *)(iVar7 + 0x44)) {
                puVar4 = (undefined4 *)*puVar4;
              }
              if (puVar4 != (undefined4 *)0x0) {
                local_6f = FUN_008917b4(puVar4);
                goto LAB_00528efa;
              }
            }
            break;
          }
        }
        local_6f = 0;
LAB_00528efa:
        local_20 = 0xf;
        local_24 = 0;
        local_34[0] = local_34[0] & 0xffffff00;
        FUN_00402a70(&DAT_00c0ce30,4);
        local_8._0_1_ = 2;
        uVar6 = FUN_0072ecf0(&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00440130(uVar6);
        if (0xf < local_f0) {
          FUN_0089120c(local_104);
        }
        local_8._0_1_ = 1;
        local_f0 = 0xf;
        local_104 = local_104 & 0xffffff00;
        if (0xf < local_20) {
          FUN_0089120c(local_34[0]);
        }
        if ((*(int **)(iVar3 + 0x18) != (int *)0x0) &&
           (iVar7 = (**(code **)(**(int **)(iVar3 + 0x18) + 0x30))(), iVar7 != 0)) {
          puVar4 = (undefined4 *)(iVar7 + 0x20);
          if (0xf < *(uint *)(iVar7 + 0x34)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            if ((*(int **)(iVar3 + 0x18) == (int *)0x0) ||
               (iVar3 = (**(code **)(**(int **)(iVar3 + 0x18) + 0x30))(), iVar3 == 0)) {
              pcVar9 = (char *)0x0;
            }
            else {
              pcVar9 = (char *)(iVar3 + 0x20);
              if (0xf < *(uint *)(iVar3 + 0x34)) {
                pcVar9 = *(char **)pcVar9;
              }
            }
            local_20 = 0xf;
            local_24 = 0;
            local_34[0] = local_34[0] & 0xffffff00;
            pcVar8 = pcVar9;
            do {
              cVar1 = *pcVar8;
              pcVar8 = pcVar8 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
            local_8._0_1_ = 4;
            FUN_00440130(local_34);
            local_8._0_1_ = 1;
            if (0xf < local_20) {
              FUN_0089120c(local_34[0]);
            }
          }
        }
        uVar6 = FUN_00529870(&local_70);
        local_8 = CONCAT31(local_8._1_3_,5);
        uVar6 = FUN_00529ac0(uVar6);
        FUN_005298a0(param_1,uVar6);
        if (7 < local_110) {
          FUN_0089120c(local_124);
        }
        local_110 = 7;
        local_124 = local_124 & 0xffff0000;
        if (7 < local_12c) {
          FUN_0089120c(local_140);
        }
        local_8 = local_8 & 0xffffff00;
        local_12c = 7;
        local_140 = local_140 & 0xffff0000;
        if (7 < local_3c) {
          FUN_0089120c(local_50);
        }
        local_3c = 7;
        local_40 = 0;
        local_50 = local_50 & 0xffff0000;
        if (7 < local_58) {
          FUN_0089120c(local_6c);
        }
        local_6c = local_6c & 0xffff0000;
        local_58 = 7;
        local_5c = 0;
        iVar3 = FUN_0072e3c0();
      }
      iVar3 = FUN_0072e3c0();
    }
    local_8 = 0xffffffff;
    local_e8[0] = TiXmlDocument::vftable;
    if (0xf < local_88) {
      FUN_0089120c(local_9c);
    }
    local_88 = 0xf;
    local_8c = 0;
    local_9c = local_9c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_e8[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_88) {
      local_8 = 0xffffffff;
      local_e8[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_9c);
    }
    local_88 = 0xf;
    local_8c = 0;
    local_9c = local_9c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


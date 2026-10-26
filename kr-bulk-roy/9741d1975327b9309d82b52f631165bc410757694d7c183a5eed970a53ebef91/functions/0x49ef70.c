
void FUN_0049ef70(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  undefined4 *puVar9;
  int iStack_134;
  int iStack_130;
  uint uStack_12c;
  undefined4 uStack_11c;
  uint uStack_118;
  uint uStack_110;
  undefined4 uStack_100;
  uint uStack_fc;
  uint uStack_f4;
  undefined4 uStack_e4;
  uint uStack_e0;
  uint uStack_d8;
  undefined4 uStack_c8;
  uint uStack_c4;
  undefined4 uStack_bc;
  uint uStack_b8;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined4 uStack_9c;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009251d8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_134;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffec0;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if ((((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("FaceMessage"), iVar3 != 0)) &&
      (piVar4 = (int *)FUN_0072e360(uVar2), piVar4 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*piVar4 + 0x14))(), iVar3 != 0)) {
    iVar5 = (**(code **)(*piVar4 + 0x14))();
    iVar3 = iVar5;
    while (iStack_134 = iVar3, iVar5 != 0) {
      uStack_c4 = 7;
      uStack_c8 = 0;
      uStack_d8 = uStack_d8 & 0xffff0000;
      uStack_a4 = 7;
      uStack_a8 = 0;
      uStack_b8 = uStack_b8 & 0xffff0000;
      local_c._1_3_ = (undefined3)((uint)local_c >> 8);
      local_c._0_1_ = 1;
      uStack_118 = 0xf;
      uStack_11c = 0;
      uStack_12c = uStack_12c & 0xffffff00;
      FUN_00402a70("chatKey",7);
      local_c._0_1_ = 2;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_c._0_1_ = 3;
      uVar6 = FUN_004028b0(uVar6);
      local_c = CONCAT31(local_c._1_3_,4);
      FUN_00402800(uVar6);
      if (7 < uStack_fc) {
        FUN_0089120c(uStack_110);
      }
      uStack_fc = 7;
      uStack_100 = 0;
      uStack_110 = uStack_110 & 0xffff0000;
      if (0xf < uStack_e0) {
        FUN_0089120c(uStack_f4);
      }
      local_c = CONCAT31(local_c._1_3_,1);
      uStack_e0 = 0xf;
      uStack_e4 = 0;
      uStack_f4 = uStack_f4 & 0xffffff00;
      if (0xf < uStack_118) {
        FUN_0089120c(uStack_12c);
      }
      iVar5 = *(int *)(iVar3 + 0x94);
      iStack_130 = iVar3 + 0x44;
      if (iVar5 != iStack_130) {
        do {
          pcVar7 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar7 = *(char **)pcVar7;
          }
          iVar3 = __stricmp(pcVar7,"faceIdx");
          if (iVar3 == 0) {
            if (iVar5 != 0) {
              puVar9 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar9 = (undefined4 *)*puVar9;
              }
              if (puVar9 != (undefined4 *)0x0) {
                uStack_bc = FUN_008917b4(puVar9);
                goto LAB_0049f19c;
              }
            }
            break;
          }
          iVar5 = *(int *)(iVar5 + 0x50);
        } while (iVar5 != iStack_130);
      }
      uStack_bc = 0;
LAB_0049f19c:
      uStack_118 = 0xf;
      uStack_11c = 0;
      uStack_12c = uStack_12c & 0xffffff00;
      FUN_00402a70("systemMsg",9);
      local_c._0_1_ = 5;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_c._0_1_ = 6;
      uVar6 = FUN_004028b0(uVar6);
      local_c = CONCAT31(local_c._1_3_,7);
      FUN_00402800(uVar6);
      if (7 < uStack_e0) {
        FUN_0089120c(uStack_f4);
      }
      uStack_e0 = 7;
      uStack_e4 = 0;
      uStack_f4 = uStack_f4 & 0xffff0000;
      if (0xf < uStack_fc) {
        FUN_0089120c(uStack_110);
      }
      local_c = CONCAT31(local_c._1_3_,1);
      uStack_fc = 0xf;
      uStack_100 = 0;
      uStack_110 = uStack_110 & 0xffffff00;
      if (0xf < uStack_118) {
        FUN_0089120c(uStack_12c);
      }
      iVar5 = iStack_130;
      uStack_118 = 0xf;
      iVar3 = *(int *)(iStack_130 + 0x50);
      uStack_11c = 0;
      uStack_12c = uStack_12c & 0xffffff00;
      for (; iVar3 != iVar5; iVar3 = *(int *)(iVar3 + 0x50)) {
        pcVar7 = (char *)(iVar3 + 0x14);
        if (0xf < *(uint *)(iVar3 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar8 = __stricmp(pcVar7,"chat_id");
        if (iVar8 == 0) {
          if (iVar3 != 0) {
            puVar9 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar9 = (undefined4 *)*puVar9;
            }
            if (puVar9 != (undefined4 *)0x0) {
              uStack_9c = FUN_008917b4(puVar9);
              goto LAB_0049f2ba;
            }
          }
          break;
        }
      }
      uStack_9c = 0;
LAB_0049f2ba:
      FUN_0049f4d0();
      iVar5 = FUN_0072e3c0();
      iStack_134 = iVar5;
      if (7 < uStack_a4) {
        FUN_0089120c(uStack_b8);
      }
      uStack_a4 = 7;
      uStack_a8 = 0;
      uStack_b8 = uStack_b8 & 0xffff0000;
      if (7 < uStack_c4) {
        FUN_0089120c(uStack_d8);
      }
      uStack_c4 = 7;
      uStack_c8 = 0;
      uStack_d8 = uStack_d8 & 0xffff0000;
      iVar3 = iStack_134;
    }
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_134);
  return;
}


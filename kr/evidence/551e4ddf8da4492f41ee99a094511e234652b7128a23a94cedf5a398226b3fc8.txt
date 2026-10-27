
void FUN_00531d00(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *******pppppppuVar6;
  int local_1e4;
  int iStack_1e0;
  int iStack_1dc;
  int local_1d8;
  int *piStack_1d4;
  int iStack_1d0;
  int iStack_1c8;
  int iStack_1c4;
  undefined4 uStack_1c0;
  undefined4 ******appppppuStack_1b4 [4];
  undefined4 uStack_1a4;
  uint uStack_1a0;
  uint local_198;
  undefined4 local_188;
  uint local_184;
  uint uStack_17c;
  undefined4 uStack_16c;
  uint uStack_168;
  uint local_160;
  undefined4 local_150;
  uint local_14c;
  uint local_144;
  undefined4 local_134;
  uint local_130;
  undefined **local_128 [17];
  char local_e4;
  uint local_dc;
  undefined4 local_cc;
  uint local_c8;
  int iStack_b0;
  undefined1 auStack_ac [68];
  undefined1 auStack_68 [76];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00923515;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_1e4;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffe10;
  ExceptionList = &local_14;
  FUN_0072ed80(local_128);
  local_c = 0;
  FUN_0072f110(0);
  if (local_e4 == '\0') {
    local_1d8 = FUN_0072e2e0(&DAT_00c0f150);
    if (local_1d8 == 0) {
      FUN_006edb60(&DAT_00c0f158);
      iVar2 = local_1e4;
    }
    else {
      iVar2 = FUN_0072e2e0("ToolTip");
      if (iVar2 != 0) {
        local_1e4 = FUN_0072e360(uVar1);
        while (local_1e4 != 0) {
          local_130 = 0xf;
          local_134 = 0;
          local_144 = local_144 & 0xffffff00;
          local_c._1_3_ = (uint3)(local_c >> 8);
          local_c._0_1_ = 1;
          local_14c = 0xf;
          local_150 = 0;
          local_160 = local_160 & 0xffffff00;
          FUN_00402a70(&DAT_00c0d5f0,4);
          local_c._0_1_ = 2;
          uVar3 = FUN_0072ecf0(&DAT_00bf2375);
          local_c = CONCAT31(local_c._1_3_,3);
          FUN_00402bb0(uVar3);
          if (0xf < local_184) {
            FUN_0089120c(local_198);
          }
          local_c = CONCAT31(local_c._1_3_,1);
          local_184 = 0xf;
          local_188 = 0;
          local_198 = local_198 & 0xffffff00;
          if (0xf < local_14c) {
            FUN_0089120c(local_160);
          }
          iVar2 = FUN_007300a0("LOADTYPE");
          if (iVar2 == 0) {
LAB_00531ef8:
            iStack_1d0 = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_00531ef8;
            iStack_1d0 = FUN_008917b4(puVar4);
          }
          iStack_1d0 = iStack_1d0 + -1;
          piStack_1d4 = (int *)(&DAT_00fe1e48 + iStack_1d0 * 0x10);
          FUN_00532670();
          iVar2 = FUN_007300a0("HELPTYPE");
          if (iVar2 == 0) {
LAB_00531f42:
            iStack_1dc = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_00531f42;
            iStack_1dc = FUN_008917b4(puVar4);
          }
          iStack_1dc = iStack_1dc + -1;
          iVar2 = FUN_007300a0("HELPID");
          if (iVar2 == 0) {
LAB_00531f77:
            iStack_1e0 = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_00531f77;
            iStack_1e0 = FUN_008917b4(puVar4);
          }
          if ((-1 < iStack_1dc) && (iStack_1e0 != 0)) {
            local_14c = 7;
            local_150 = 0;
            local_160 = local_160 & 0xffff0000;
            local_c._0_1_ = 4;
            local_184 = 0xf;
            local_188 = 0;
            local_198 = local_198 & 0xffffff00;
            FUN_00402a70(&DAT_00c0ce30,4);
            local_c._0_1_ = 5;
            uVar3 = FUN_0072ecf0(&DAT_00bf2375);
            local_c = CONCAT31(local_c._1_3_,6);
            FUN_00440130(uVar3);
            if (0xf < uStack_168) {
              FUN_0089120c(uStack_17c);
            }
            uStack_168 = 0xf;
            uStack_16c = 0;
            uStack_17c = uStack_17c & 0xffffff00;
            if (0xf < local_184) {
              FUN_0089120c(local_198);
            }
            uStack_1a0 = 7;
            uStack_1a4 = 0;
            appppppuStack_1b4[0] = (undefined4 ******)((uint)appppppuStack_1b4[0] & 0xffff0000);
            local_c._0_1_ = 7;
            local_184 = 0xf;
            local_188 = 0;
            local_198 = local_198 & 0xffffff00;
            FUN_00402a70(&DAT_00c0d5f0,4);
            local_c._0_1_ = 8;
            uVar3 = FUN_0072ecf0(&DAT_00bf2375);
            local_c = CONCAT31(local_c._1_3_,9);
            FUN_00440130(uVar3);
            if (0xf < uStack_168) {
              FUN_0089120c(uStack_17c);
            }
            local_c._0_1_ = 7;
            uStack_168 = 0xf;
            uStack_16c = 0;
            uStack_17c = uStack_17c & 0xffffff00;
            if (0xf < local_184) {
              FUN_0089120c(local_198);
            }
            pppppppuVar6 = (undefined4 *******)appppppuStack_1b4[0];
            if (uStack_1a0 < 8) {
              pppppppuVar6 = appppppuStack_1b4;
            }
            FUN_00531a80(auStack_68,pppppppuVar6,0,(piStack_1d4[1] - *piStack_1d4) / 0x1c + -1,
                         iStack_1d0);
            local_c._0_1_ = 10;
            iStack_b0 = iStack_1e0;
            FUN_005330c0(auStack_ac);
            iVar2 = iStack_1dc * 0x10;
            local_c = CONCAT31(local_c._1_3_,0xb);
            uVar3 = FUN_00532ff0(&iStack_b0);
            FUN_00532d70(&DAT_00fe1ea8 + iVar2,uVar3);
            FUN_005325d0();
            FUN_005325d0();
            if (7 < uStack_1a0) {
              FUN_0089120c(appppppuStack_1b4[0]);
            }
            uStack_1a0 = 7;
            uStack_1a4 = 0;
            appppppuStack_1b4[0] = (undefined4 ******)((uint)appppppuStack_1b4[0] & 0xffff0000);
            if (7 < local_14c) {
              FUN_0089120c(local_160);
            }
          }
          local_c = local_c & 0xffffff00;
          if (0xf < local_130) {
            FUN_0089120c(local_144);
          }
          local_1e4 = FUN_0072e3c0();
        }
      }
      iVar5 = FUN_0072e2e0("TutoQuest");
      iVar2 = local_1e4;
      if (iVar5 != 0) {
        local_1e4 = FUN_0072e360();
        while (iVar2 = 0, local_1e4 != 0) {
          iVar2 = FUN_007300a0(&DAT_00c0f1b0);
          if (iVar2 == 0) {
LAB_005322a3:
            iStack_1dc = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_005322a3;
            iStack_1dc = FUN_008917b4(puVar4);
          }
          iVar2 = FUN_007300a0(&DAT_00c0f1b4);
          if (iVar2 == 0) {
LAB_005322d1:
            uVar3 = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_005322d1;
            uVar3 = FUN_008917b4(puVar4);
          }
          iVar2 = FUN_007300a0("TUTOID");
          if (iVar2 == 0) {
LAB_005322ff:
            iStack_1e0 = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_005322ff;
            iStack_1e0 = FUN_008917b4(puVar4);
          }
          iStack_1c8 = iStack_1e0;
          iStack_1c4 = iStack_1dc;
          uStack_1c0 = uVar3;
          uVar3 = FUN_00821c50();
          FUN_00517bf0(&DAT_00fe1e98,uVar3);
          iVar2 = FUN_007300a0("HELPTYPE");
          if (iVar2 == 0) {
LAB_0053235f:
            iVar2 = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_0053235f;
            iVar2 = FUN_008917b4(puVar4);
          }
          local_1d8 = iVar2 + -1;
          iVar5 = FUN_007300a0("HELPID");
          if (iVar5 == 0) {
LAB_00532399:
            iVar5 = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_00532399;
            iVar5 = FUN_008917b4(puVar4);
          }
          if ((-1 < iVar2 + -1) && (iVar5 != 0)) {
            uStack_1a0 = 7;
            uStack_1a4 = 0;
            appppppuStack_1b4[0] = (undefined4 ******)((uint)appppppuStack_1b4[0] & 0xffff0000);
            local_c._0_1_ = 0xc;
            local_130 = 0xf;
            local_134 = 0;
            local_144 = local_144 & 0xffffff00;
            FUN_00402a70(&DAT_00c0ce30,4);
            local_c._0_1_ = 0xd;
            uVar3 = FUN_0072ecf0(&DAT_00bf2375);
            local_c = CONCAT31(local_c._1_3_,0xe);
            FUN_00440130(uVar3);
            if (0xf < uStack_168) {
              FUN_0089120c(uStack_17c);
            }
            local_c._0_1_ = 0xc;
            uStack_168 = 0xf;
            uStack_16c = 0;
            uStack_17c = uStack_17c & 0xffffff00;
            if (0xf < local_130) {
              FUN_0089120c(local_144);
            }
            FUN_00531a80(auStack_68,&DAT_00bed1fc,1,iStack_1e0,0);
            local_c._0_1_ = 0xf;
            iStack_b0 = iVar5;
            FUN_005330c0(auStack_ac);
            iVar2 = local_1d8 * 0x10;
            local_c._0_1_ = 0x10;
            uVar3 = FUN_00532ff0(&iStack_b0);
            FUN_00532d70(&DAT_00fe1ea8 + iVar2,uVar3);
            FUN_005325d0();
            FUN_005325d0();
            local_c = (uint)local_c._1_3_ << 8;
            if (7 < uStack_1a0) {
              FUN_0089120c(appppppuStack_1b4[0]);
            }
            uStack_1a0 = 7;
            uStack_1a4 = 0;
            appppppuStack_1b4[0] = (undefined4 ******)((uint)appppppuStack_1b4[0] & 0xffff0000);
          }
          local_1e4 = FUN_0072e3c0();
        }
      }
    }
  }
  else {
    FUN_006edb60(&DAT_00c0f134);
    iVar2 = local_1e4;
  }
  local_1e4 = iVar2;
  local_128[0] = TiXmlDocument::vftable;
  local_c = 0xffffffff;
  if (0xf < local_c8) {
    local_c = 0xffffffff;
    local_128[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_dc);
  }
  local_c8 = 0xf;
  local_cc = 0;
  local_dc = local_dc & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_1e4);
  return;
}


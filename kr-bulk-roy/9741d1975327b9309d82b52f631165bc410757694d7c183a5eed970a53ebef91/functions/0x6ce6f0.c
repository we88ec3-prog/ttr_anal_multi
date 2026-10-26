
/* WARNING: Removing unreachable block (ram,0x006ce857) */

void FUN_006ce6f0(int param_1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  char *pcVar8;
  char ****ppppcVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  uint uVar12;
  char ****ppppcVar13;
  bool bVar14;
  undefined **local_e8 [19];
  uint local_9c;
  undefined4 local_8c;
  uint local_88;
  uint local_6c;
  undefined4 local_5c;
  uint local_58;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  char ***local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922961;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar2 = false;
  bVar1 = false;
  local_18 = uVar4;
  FUN_0072ee30(local_e8);
  local_8 = 0;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    local_8 = 0xffffffff;
    local_e8[0] = TiXmlDocument::vftable;
    if (0xf < local_88) {
      FUN_0089120c(local_9c);
    }
    local_88 = 0xf;
    local_8c = 0;
    local_9c = local_9c & 0xffffff00;
    FUN_0072e040();
    goto LAB_006cee76;
  }
  iVar5 = FUN_0072e2e0("JoypadMapping");
  if ((((iVar5 == 0) || (piVar6 = (int *)FUN_0072e2e0("DeviceType"), piVar6 == (int *)0x0)) ||
      (iVar5 = (**(code **)(*piVar6 + 0x14))(uVar4), iVar5 == 0)) ||
     (iVar5 = (**(code **)(*piVar6 + 0x14))(), iVar5 == 0)) {
LAB_006ce8a9:
    bVar14 = false;
  }
  else {
    local_3c = 0xf;
    local_40 = 0;
    local_50 = local_50 & 0xffffff00;
    FUN_00402a70(&DAT_00bed1d4,4);
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar5 = FUN_0072ecf0(&DAT_00bf2375);
    uVar4 = *(uint *)(iVar5 + 0x10);
    bVar2 = true;
    bVar1 = true;
    uVar12 = uVar4;
    if (5 < uVar4) {
      uVar12 = 6;
    }
    iVar5 = FUN_00407e70(uVar12);
    bVar14 = false;
    if (iVar5 == 0) {
      if (uVar4 < 6) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar4 != 6);
      }
      bVar14 = uVar4 == 0;
    }
    if (!bVar14) goto LAB_006ce8a9;
    bVar14 = true;
  }
  if (bVar1) {
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
  }
  local_8 = 0;
  if ((bVar2) && (0xf < local_3c)) {
    FUN_0089120c(local_50);
  }
  if (bVar14) {
    local_3c = 0xf;
    local_40 = 0;
    local_50 = local_50 & 0xffffff00;
    FUN_00402a70(&DAT_00bed1d4,4);
    local_8._0_1_ = 3;
    pcVar7 = (char *)FUN_0072ecf0(&DAT_00bf2375);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (0xf < *(uint *)(pcVar7 + 0x14)) {
      pcVar7 = *(char **)pcVar7;
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
    pcVar8 = pcVar7;
    do {
      cVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
    FUN_0040b310(pcVar7);
    if (0xf < local_58) {
      FUN_0089120c(local_6c);
    }
    local_58 = 0xf;
    local_5c = 0;
    local_6c = local_6c & 0xffffff00;
    local_8 = CONCAT31(local_8._1_3_,7);
    if (0xf < local_3c) {
      FUN_0089120c(local_50);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50 = local_50 & 0xffffff00;
    ppppcVar13 = (char ****)local_34[0];
    if (local_20 < 0x10) {
      ppppcVar13 = local_34;
    }
    ppppcVar9 = ppppcVar13;
    do {
      cVar3 = *(char *)ppppcVar9;
      ppppcVar9 = (char ****)((int)ppppcVar9 + 1);
    } while (cVar3 != '\0');
    FUN_00402a70(ppppcVar13,(int)ppppcVar9 - (int)((int)ppppcVar13 + 1));
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      iVar5 = FUN_007300a0("value");
      if (iVar5 == 0) {
LAB_006cea4c:
        uVar11 = 0;
      }
      else {
        puVar10 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar10 = (undefined4 *)*puVar10;
        }
        if (puVar10 == (undefined4 *)0x0) goto LAB_006cea4c;
        uVar11 = FUN_008917b4(puVar10);
      }
      *(undefined4 *)(param_1 + 0xcc) = uVar11;
    }
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      iVar5 = FUN_007300a0("value");
      if (iVar5 == 0) {
LAB_006cea8c:
        uVar11 = 0;
      }
      else {
        puVar10 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar10 = (undefined4 *)*puVar10;
        }
        if (puVar10 == (undefined4 *)0x0) goto LAB_006cea8c;
        uVar11 = FUN_008917b4(puVar10);
      }
      *(undefined4 *)(param_1 + 0xd0) = uVar11;
    }
    iVar5 = FUN_0072e360();
    if ((iVar5 != 0) && (iVar5 = FUN_0072e360(), iVar5 != 0)) {
      do {
        iVar5 = FUN_007300a0(&DAT_00bed1d0);
        if (iVar5 != 0) {
          puVar10 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar10 = (undefined4 *)*puVar10;
          }
          if (puVar10 != (undefined4 *)0x0) {
            FUN_008917b4(puVar10);
          }
        }
        iVar5 = FUN_007300a0("mapping");
        if (iVar5 != 0) {
          puVar10 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar10 = (undefined4 *)*puVar10;
          }
          if (puVar10 != (undefined4 *)0x0) {
            FUN_008917b4(puVar10);
          }
        }
        uVar11 = FUN_00821c50();
        FUN_00517bf0(param_1 + 0xd4,uVar11);
        iVar5 = FUN_0072e3c0();
      } while (iVar5 != 0);
    }
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      iVar5 = FUN_0072e360();
      if (iVar5 != 0) {
        do {
          iVar5 = FUN_007300a0(&DAT_00bed1d0);
          if (iVar5 != 0) {
            puVar10 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            if (puVar10 != (undefined4 *)0x0) {
              FUN_008917b4(puVar10);
            }
          }
          iVar5 = FUN_007300a0("forwarding");
          if (iVar5 != 0) {
            puVar10 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            if (puVar10 != (undefined4 *)0x0) {
              FUN_008917b4(puVar10);
            }
          }
          uVar11 = FUN_00821c50();
          FUN_00517bf0(param_1 + 0xe4,uVar11);
          iVar5 = FUN_0072e3c0();
        } while (iVar5 != 0);
      }
      iVar5 = FUN_0072e360();
      if (iVar5 != 0) {
        do {
          iVar5 = FUN_007300a0(&DAT_00bed1d0);
          if (iVar5 != 0) {
            puVar10 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            if (puVar10 != (undefined4 *)0x0) {
              FUN_008917b4(puVar10);
            }
          }
          iVar5 = FUN_007300a0("button");
          if (iVar5 != 0) {
            puVar10 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            if (puVar10 != (undefined4 *)0x0) {
              FUN_008917b4(puVar10);
            }
          }
          uVar11 = FUN_00821c50();
          FUN_00517bf0(param_1 + 0xf4,uVar11);
          iVar5 = FUN_0072e3c0();
        } while (iVar5 != 0);
      }
      iVar5 = FUN_0072e360();
      if (iVar5 != 0) {
        do {
          iVar5 = FUN_007300a0(&DAT_00bed1d0);
          if (iVar5 != 0) {
            puVar10 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            if (puVar10 != (undefined4 *)0x0) {
              FUN_008917b4(puVar10);
            }
          }
          iVar5 = FUN_007300a0("mapping");
          if (iVar5 != 0) {
            puVar10 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            if (puVar10 != (undefined4 *)0x0) {
              FUN_008917b4(puVar10);
            }
          }
          uVar11 = FUN_00821c50();
          FUN_00517bf0(param_1 + 0x104,uVar11);
          iVar5 = FUN_0072e3c0();
        } while (iVar5 != 0);
      }
    }
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
  }
  FUN_006edd00("Loaded custom Joypad mapping.");
  local_8 = 0xffffffff;
  local_e8[0] = TiXmlDocument::vftable;
  if (0xf < local_88) {
    FUN_0089120c(local_9c);
  }
  local_88 = 0xf;
  local_8c = 0;
  local_9c = local_9c & 0xffffff00;
  FUN_0072e040();
LAB_006cee76:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


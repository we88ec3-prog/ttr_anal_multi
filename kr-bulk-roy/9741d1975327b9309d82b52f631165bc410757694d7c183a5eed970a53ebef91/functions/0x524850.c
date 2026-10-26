
void FUN_00524850(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  undefined4 local_e0;
  undefined4 local_dc;
  int local_d8;
  int local_d4;
  undefined **local_d0 [17];
  char local_8c;
  uint local_84;
  undefined4 local_74;
  uint local_70;
  uint local_58;
  undefined4 local_48;
  uint local_44;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  int *local_28;
  int *local_24;
  int *local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923963;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_d0);
  local_8 = 0;
  FUN_0072f110(0);
  if (local_8c == '\0') {
    iVar3 = FUN_0072e2e0("NPCTABLE");
    if (iVar3 != 0) {
      iVar3 = FUN_0072e360(uVar2);
      while (iVar3 != 0) {
        iVar3 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar3 == 0) {
LAB_00524991:
          uVar5 = 0;
        }
        else {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 == (undefined4 *)0x0) goto LAB_00524991;
          uVar5 = FUN_008917b4(puVar4);
        }
        iVar3 = FUN_00526f60(param_1,uVar5);
        iVar6 = FUN_007300a0(&DAT_00bfb800);
        if (iVar6 == 0) {
LAB_005249d0:
          uVar5 = 0;
        }
        else {
          puVar4 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 == (undefined4 *)0x0) goto LAB_005249d0;
          uVar5 = FUN_008917b4(puVar4);
        }
        *(undefined4 *)(iVar3 + 0x20) = uVar5;
        local_44 = 0xf;
        local_48 = 0;
        local_58 = local_58 & 0xffffff00;
        FUN_00402a70(&DAT_00c0ce30,4);
        local_8._0_1_ = 1;
        uVar5 = FUN_0072ecf0(&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_00440130(uVar5);
        if ((int *)0xf < local_20) {
          FUN_0089120c(local_34);
        }
        local_8 = local_8 & 0xffffff00;
        local_20 = (int *)0xf;
        local_24 = (int *)0x0;
        local_34 = (undefined4 *)((uint)local_34 & 0xffffff00);
        if (0xf < local_44) {
          FUN_0089120c(local_58);
        }
        local_44 = 0xf;
        local_48 = 0;
        local_58 = local_58 & 0xffffff00;
        FUN_00402a70("GUILD",5);
        local_8._0_1_ = 3;
        uVar5 = FUN_0072ecf0(&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,4);
        FUN_00440130(uVar5);
        if (0xf < local_20) {
          FUN_0089120c(local_34);
        }
        local_8 = local_8 & 0xffffff00;
        local_20 = (int *)0xf;
        local_24 = (int *)0x0;
        local_34 = (undefined4 *)((uint)local_34 & 0xffffff00);
        if (0xf < local_44) {
          FUN_0089120c(local_58);
        }
        iVar3 = FUN_0072e2e0("TALKLIST");
        if ((iVar3 != 0) && (local_d8 = FUN_0072e360(), local_d8 != 0)) {
LAB_00524b10:
          piVar12 = (int *)0x0;
          local_38 = (undefined4 *)0x0;
          local_34 = (undefined4 *)0x0;
          local_30 = (undefined4 *)0x0;
          local_28 = (int *)0x0;
          local_24 = (int *)0x0;
          local_20 = (int *)0x0;
          iVar6 = local_d8 + 0x44;
          local_8 = CONCAT31(local_8._1_3_,5);
          for (iVar3 = *(int *)(local_d8 + 0x94); iVar3 != iVar6; iVar3 = *(int *)(iVar3 + 0x50)) {
            pcVar9 = (char *)(iVar3 + 0x14);
            if (0xf < *(uint *)(iVar3 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar7 = __stricmp(pcVar9,"ORDER");
            if (iVar7 == 0) {
              if (iVar3 != 0) {
                puVar4 = (undefined4 *)(iVar3 + 0x30);
                if (0xf < *(uint *)(iVar3 + 0x44)) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                if (puVar4 != (undefined4 *)0x0) {
                  local_3c = FUN_008917b4(puVar4);
                  goto LAB_00524b66;
                }
              }
              break;
            }
          }
          local_3c = 0;
LAB_00524b66:
          for (iVar3 = *(int *)(local_d8 + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
            pcVar9 = (char *)(iVar3 + 0x20);
            if (0xf < *(uint *)(iVar3 + 0x34)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar6 = __stricmp(pcVar9,"DEMANDLIST");
            if (iVar6 == 0) {
              if ((iVar3 != 0) && (local_d4 = FUN_0072e360(), puVar4 = local_34, local_d4 != 0))
              goto LAB_00524beb;
              break;
            }
          }
          goto LAB_00524e7f;
        }
LAB_0052507e:
        iVar3 = FUN_0072e3c0();
      }
      local_8 = 0xffffffff;
      local_d0[0] = TiXmlDocument::vftable;
      if (0xf < local_70) {
        FUN_0089120c(local_84);
      }
      local_70 = 0xf;
      local_74 = 0;
      local_84 = local_84 & 0xffffff00;
      FUN_0072e040();
      goto LAB_005250df;
    }
    FUN_006edb60("Not NPCTABLE File");
  }
  local_d0[0] = TiXmlDocument::vftable;
  local_8 = 0xffffffff;
  if (0xf < local_70) {
    local_8 = 0xffffffff;
    local_d0[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_84);
  }
  local_70 = 0xf;
  local_74 = 0;
  local_84 = local_84 & 0xffffff00;
  FUN_0072e040();
LAB_005250df:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
LAB_00524beb:
  do {
    iVar6 = local_d4;
    iVar7 = local_d4 + 0x44;
    for (iVar3 = *(int *)(local_d4 + 0x94); iVar3 != iVar7; iVar3 = *(int *)(iVar3 + 0x50)) {
      pcVar9 = (char *)(iVar3 + 0x14);
      if (0xf < *(uint *)(iVar3 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar8 = __stricmp(pcVar9,"TYPE");
      if (iVar8 == 0) {
        if (iVar3 != 0) {
          puVar10 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar10 = (undefined4 *)*puVar10;
          }
          if (puVar10 != (undefined4 *)0x0) {
            local_e0 = FUN_008917b4(puVar10);
            goto LAB_00524c2a;
          }
        }
        break;
      }
    }
    local_e0 = 0;
LAB_00524c2a:
    for (iVar3 = *(int *)(iVar6 + 0x94); iVar3 != iVar7; iVar3 = *(int *)(iVar3 + 0x50)) {
      pcVar9 = (char *)(iVar3 + 0x14);
      if (0xf < *(uint *)(iVar3 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar8 = __stricmp(pcVar9,"MIN");
      if (iVar8 == 0) {
        if (iVar3 != 0) {
          puVar10 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar10 = (undefined4 *)*puVar10;
          }
          if (puVar10 != (undefined4 *)0x0) {
            uVar1 = FUN_008917b4(puVar10);
            goto LAB_00524c61;
          }
        }
        break;
      }
    }
    uVar1 = 0;
LAB_00524c61:
    iVar3 = *(int *)(iVar6 + 0x94);
    local_dc = CONCAT22(local_dc._2_2_,uVar1);
    for (; iVar3 != iVar7; iVar3 = *(int *)(iVar3 + 0x50)) {
      pcVar9 = (char *)(iVar3 + 0x14);
      if (0xf < *(uint *)(iVar3 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar8 = __stricmp(pcVar9,"MAX");
      if (iVar8 == 0) {
        if (iVar3 != 0) {
          puVar10 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar10 = (undefined4 *)*puVar10;
          }
          if (puVar10 != (undefined4 *)0x0) {
            uVar1 = FUN_008917b4(puVar10);
            goto LAB_00524c9a;
          }
        }
        break;
      }
    }
    uVar1 = 0;
LAB_00524c9a:
    iVar3 = *(int *)(iVar6 + 0x94);
    local_dc = CONCAT22(uVar1,(undefined2)local_dc);
    for (; iVar3 != iVar7; iVar3 = *(int *)(iVar3 + 0x50)) {
      pcVar9 = (char *)(iVar3 + 0x14);
      if (0xf < *(uint *)(iVar3 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar6 = __stricmp(pcVar9,"VALUE");
      if (iVar6 == 0) {
        if (iVar3 != 0) {
          puVar10 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar10 = (undefined4 *)*puVar10;
          }
          if (puVar10 != (undefined4 *)0x0) {
            uVar1 = FUN_008917b4(puVar10);
            local_dc = CONCAT22(uVar1,uVar1);
          }
        }
        break;
      }
    }
    if ((&local_e0 < puVar4) && (local_38 <= &local_e0)) {
      iVar3 = (int)&local_e0 - (int)local_38 >> 3;
      if (puVar4 == local_30) {
        uVar2 = (int)puVar4 - (int)local_38 >> 3;
        if (0x1ffffffe < uVar2) goto LAB_005250fd;
        uVar2 = uVar2 + 1;
        uVar11 = (int)local_30 - (int)local_38 >> 3;
        if (uVar11 < uVar2) {
          if (0x1fffffff - (uVar11 >> 1) < uVar11) {
            uVar11 = 0;
          }
          else {
            uVar11 = uVar11 + (uVar11 >> 1);
          }
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
          FUN_004e7330(uVar11);
          puVar4 = local_34;
        }
      }
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = local_38[iVar3 * 2];
        puVar4[1] = local_38[iVar3 * 2 + 1];
      }
    }
    else {
      if (puVar4 == local_30) {
        uVar2 = (int)puVar4 - (int)local_38 >> 3;
        if (0x1ffffffe < uVar2) goto LAB_005250fd;
        uVar2 = uVar2 + 1;
        uVar11 = (int)local_30 - (int)local_38 >> 3;
        if (uVar11 < uVar2) {
          if (0x1fffffff - (uVar11 >> 1) < uVar11) {
            uVar11 = 0;
          }
          else {
            uVar11 = uVar11 + (uVar11 >> 1);
          }
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
          FUN_004e7330(uVar11);
          puVar4 = local_34;
        }
      }
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = local_e0;
        puVar4[1] = local_dc;
      }
    }
    local_34 = puVar4 + 2;
    local_d4 = FUN_0072e3c0();
    puVar4 = puVar4 + 2;
  } while (local_d4 != 0);
  local_d4 = 0;
  piVar12 = local_24;
LAB_00524e7f:
  for (iVar3 = *(int *)(local_d8 + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
    pcVar9 = (char *)(iVar3 + 0x20);
    if (0xf < *(uint *)(iVar3 + 0x34)) {
      pcVar9 = *(char **)pcVar9;
    }
    iVar6 = __stricmp(pcVar9,"TALKSTEP");
    if (iVar6 == 0) {
      if (iVar3 != 0) {
        iVar3 = FUN_0072e360();
        goto joined_r0x00524ed9;
      }
      break;
    }
  }
LAB_0052502b:
  FUN_005273c0();
  local_8 = local_8 & 0xffffff00;
  if (local_28 != (int *)0x0) {
    FUN_0089120c(local_28);
  }
  if (local_38 != (undefined4 *)0x0) {
    FUN_0089120c(local_38);
  }
  local_d8 = FUN_0072e3c0();
  if (local_d8 == 0) goto LAB_0052507e;
  goto LAB_00524b10;
joined_r0x00524ed9:
  if (iVar3 == 0) goto LAB_0052502b;
  for (iVar6 = *(int *)(iVar3 + 0x94); iVar6 != iVar3 + 0x44; iVar6 = *(int *)(iVar6 + 0x50)) {
    pcVar9 = (char *)(iVar6 + 0x14);
    if (0xf < *(uint *)(iVar6 + 0x28)) {
      pcVar9 = *(char **)pcVar9;
    }
    iVar7 = __stricmp(pcVar9,"VALUE");
    if (iVar7 == 0) {
      if (iVar6 != 0) {
        puVar4 = (undefined4 *)(iVar6 + 0x30);
        if (0xf < *(uint *)(iVar6 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 != (undefined4 *)0x0) {
          iVar3 = FUN_008917b4(puVar4);
          goto LAB_00524f19;
        }
      }
      break;
    }
  }
  iVar3 = 0;
LAB_00524f19:
  local_d4 = iVar3;
  if ((&local_d4 < piVar12) && (local_28 <= &local_d4)) {
    iVar3 = (int)&local_d4 - (int)local_28;
    if (piVar12 == local_20) {
      uVar2 = (int)piVar12 - (int)local_28 >> 2;
      if (0x3ffffffe < uVar2) goto LAB_005250fd;
      uVar2 = uVar2 + 1;
      uVar11 = (int)local_20 - (int)local_28 >> 2;
      if (uVar11 < uVar2) {
        if (0x3fffffff - (uVar11 >> 1) < uVar11) {
          uVar11 = 0;
        }
        else {
          uVar11 = uVar11 + (uVar11 >> 1);
        }
        if (uVar11 < uVar2) {
          uVar11 = uVar2;
        }
        FUN_00797980(uVar11);
        piVar12 = local_24;
      }
    }
    if (piVar12 != (int *)0x0) {
      *piVar12 = local_28[iVar3 >> 2];
    }
  }
  else {
    if (piVar12 == local_20) {
      uVar2 = (int)piVar12 - (int)local_28 >> 2;
      if (0x3ffffffe < uVar2) {
LAB_005250fd:
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long");
      }
      uVar2 = uVar2 + 1;
      uVar11 = (int)local_20 - (int)local_28 >> 2;
      if (uVar11 < uVar2) {
        if (0x3fffffff - (uVar11 >> 1) < uVar11) {
          uVar11 = 0;
        }
        else {
          uVar11 = uVar11 + (uVar11 >> 1);
        }
        if (uVar11 < uVar2) {
          uVar11 = uVar2;
        }
        FUN_00797980(uVar11);
        piVar12 = local_24;
      }
    }
    if (piVar12 != (int *)0x0) {
      *piVar12 = iVar3;
    }
  }
  piVar12 = piVar12 + 1;
  local_24 = piVar12;
  iVar3 = FUN_0072e3c0();
  goto joined_r0x00524ed9;
}


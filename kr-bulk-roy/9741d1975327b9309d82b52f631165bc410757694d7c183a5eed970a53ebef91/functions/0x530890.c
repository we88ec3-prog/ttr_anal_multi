
void FUN_00530890(int param_1)

{
  char cVar1;
  uint **ppuVar2;
  uint **ppuVar3;
  uint *puVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  undefined4 *******pppppppuVar13;
  int iVar14;
  char *pcVar15;
  uint uVar16;
  int *piVar17;
  undefined4 *puVar18;
  undefined4 **ppuVar19;
  uint uVar20;
  uint *puVar21;
  int *piVar22;
  undefined4 *puVar23;
  undefined4 *local_148;
  int local_144;
  undefined4 local_140;
  undefined4 local_13c;
  int local_138;
  int *local_134;
  int *local_130;
  undefined4 *local_12c;
  undefined4 *local_128;
  int *local_124;
  uint *local_120;
  uint local_11c;
  undefined4 local_10c;
  uint local_108;
  undefined **local_100 [17];
  char local_bc;
  uint local_b4;
  undefined4 local_a4;
  uint local_a0;
  uint local_88;
  undefined4 local_78;
  uint local_74;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 ******local_60 [4];
  undefined4 local_50;
  uint local_4c;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009235fd;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_144 = param_1;
  local_18 = uVar6;
  FUN_0072ee30(local_100);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_bc == '\0') && (iVar7 = FUN_0072e2e0("SKILLACTIVETABLE"), iVar7 != 0)) {
    local_30 = 7;
    local_34 = 0;
    local_44 = local_44 & 0xffff0000;
    local_4c = 7;
    local_50 = 0;
    local_60[0] = (undefined4 ******)((uint)local_60[0] & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_134 = *(int **)(iVar7 + 0x18);
    local_20 = 0;
    local_1c = 0;
    if (local_134 != (int *)0x0) {
      do {
        local_12c = (undefined4 *)(**(code **)(*local_134 + 0x14))(uVar6);
        iVar7 = FUN_007300a0(&DAT_00bfaf5c);
        if (iVar7 == 0) {
LAB_00530a18:
          local_138 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00530a18;
          local_138 = FUN_008917b4(puVar8);
        }
        iVar7 = FUN_007300a0(&DAT_00c0f030);
        if (iVar7 == 0) {
LAB_00530a4b:
          local_124 = (int *)0x0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00530a4b;
          local_124 = (int *)FUN_008917b4(puVar8);
        }
        iVar7 = FUN_007300a0(&DAT_00c0f038);
        if (iVar7 == 0) {
LAB_00530a7e:
          local_130 = (int *)0x0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00530a7e;
          local_130 = (int *)FUN_008917b4(puVar8);
        }
        iVar7 = FUN_007300a0("group");
        if (iVar7 != 0) {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 != (undefined4 *)0x0) {
            FUN_008917b4(puVar8);
          }
        }
        iVar7 = FUN_007300a0(&DAT_00bfb808);
        if (iVar7 == 0) {
LAB_00530ad6:
          local_128 = (undefined4 *)0x0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00530ad6;
          local_128 = (undefined4 *)FUN_008917b4(puVar8);
        }
        iVar7 = FUN_007300a0(&DAT_00c0f03c);
        if (iVar7 == 0) {
LAB_00530b09:
          local_140 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00530b09;
          local_140 = FUN_008917b4(puVar8);
        }
        iVar7 = FUN_007300a0("attribute");
        if (iVar7 == 0) {
LAB_00530b3c:
          local_13c = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00530b3c;
          local_13c = FUN_008917b4(puVar8);
        }
        iVar7 = FUN_007300a0("AtkLevel");
        if (iVar7 == 0) {
LAB_00530b6f:
          local_120 = (uint *)0x0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00530b6f;
          local_120 = (uint *)FUN_008917b4(puVar8);
        }
        iVar7 = FUN_007300a0("DefLevel");
        if (iVar7 == 0) {
LAB_00530b9e:
          uVar9 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00530b9e;
          uVar9 = FUN_008917b4(puVar8);
        }
        local_74 = 0xf;
        local_78 = 0;
        local_88 = local_88 & 0xffffff00;
        FUN_00402a70(&DAT_00bed1d4,4);
        local_8._0_1_ = 3;
        uVar10 = FUN_0072ecf0(&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,4);
        FUN_00440130(uVar10);
        if (0xf < local_108) {
          FUN_0089120c(local_11c);
        }
        local_8._0_1_ = 2;
        local_108 = 0xf;
        local_10c = 0;
        local_11c = local_11c & 0xffffff00;
        if (0xf < local_74) {
          FUN_0089120c(local_88);
        }
        switch(local_128) {
        case (undefined4 *)0x1:
        case (undefined4 *)0x2:
        case (undefined4 *)0x3:
        case (undefined4 *)0x4:
        case (undefined4 *)0x8:
        case (undefined4 *)0x9:
        case (undefined4 *)0xa:
          puVar8 = (undefined4 *)FUN_00891268(0x8c);
          local_8._0_1_ = 5;
          local_12c = puVar8;
          if (puVar8 == (undefined4 *)0x0) {
            local_128 = (undefined4 *)0x0;
          }
          else {
            FUN_0052f6b0(local_128,local_120,uVar9,local_130,local_124);
            *puVar8 = SkillTable::CSkillAttack::vftable;
            puVar8[0x13] = SkillTable::CSkillAttack::vftable;
            *(undefined2 *)(puVar8 + 0x22) = (undefined2)local_140;
            *(undefined2 *)((int)puVar8 + 0x8a) = (undefined2)local_13c;
            local_128 = puVar8;
          }
          break;
        default:
          local_12c = (undefined4 *)FUN_00891268(0x88);
          local_8._0_1_ = 6;
          if (local_12c == (undefined4 *)0x0) {
            local_128 = (undefined4 *)0x0;
          }
          else {
            local_128 = (undefined4 *)FUN_0052f6b0(local_128,local_120,uVar9,local_130,local_124);
          }
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        iVar7 = FUN_0072e2e0("DEMAND");
        puVar8 = local_128;
        if (iVar7 != 0) {
          local_130 = *(int **)(iVar7 + 0x18);
          while (local_130 != (int *)0x0) {
            iVar11 = (**(code **)(*local_130 + 0x14))();
            for (iVar7 = *(int *)(iVar11 + 0x94); iVar7 != iVar11 + 0x44;
                iVar7 = *(int *)(iVar7 + 0x50)) {
              pcVar15 = (char *)(iVar7 + 0x14);
              if (0xf < *(uint *)(iVar7 + 0x28)) {
                pcVar15 = *(char **)pcVar15;
              }
              iVar12 = __stricmp(pcVar15,"no");
              if (iVar12 == 0) {
                if (iVar7 != 0) {
                  puVar23 = (undefined4 *)(iVar7 + 0x30);
                  if (0xf < *(uint *)(iVar7 + 0x44)) {
                    puVar23 = (undefined4 *)*puVar23;
                  }
                  if (puVar23 != (undefined4 *)0x0) {
                    puVar21 = (uint *)FUN_008917b4(puVar23);
                    goto LAB_00530dc6;
                  }
                }
                break;
              }
            }
            puVar21 = (uint *)0x0;
LAB_00530dc6:
            ppuVar2 = (uint **)puVar8[0x1f];
            local_120 = puVar21;
            if (&local_120 < ppuVar2) {
              ppuVar3 = (uint **)puVar8[0x1e];
              if (&local_120 < ppuVar3) goto LAB_00530e35;
              if (ppuVar2 == (uint **)puVar8[0x20]) {
                FUN_006d6240();
              }
              if ((undefined4 *)puVar8[0x1f] != (undefined4 *)0x0) {
                *(undefined4 *)puVar8[0x1f] =
                     *(undefined4 *)(puVar8[0x1e] + ((int)&local_120 - (int)ppuVar3 >> 2) * 4);
              }
            }
            else {
LAB_00530e35:
              if (ppuVar2 == (uint **)puVar8[0x20]) {
                FUN_006d6240();
              }
              if ((undefined4 *)puVar8[0x1f] != (undefined4 *)0x0) {
                *(undefined4 *)puVar8[0x1f] = puVar21;
              }
            }
            puVar8[0x1f] = puVar8[0x1f] + 4;
            local_130 = (int *)local_130[0x10];
          }
        }
        for (piVar22 = (int *)local_134[6]; piVar22 != (int *)0x0; piVar22 = (int *)piVar22[0x10]) {
          piVar17 = piVar22 + 8;
          if (0xf < (uint)piVar22[0xd]) {
            piVar17 = (int *)*piVar17;
          }
          iVar7 = __stricmp((char *)piVar17,"LEVEL");
          if (iVar7 == 0) goto LAB_00530ea5;
        }
        piVar22 = (int *)0x0;
LAB_00530ea5:
        local_124 = piVar22;
        if (piVar22 != (int *)0x0) {
          local_12c = local_128 + 0x14;
          local_120 = local_128 + 0x18;
LAB_00530ed0:
          piVar22 = local_124;
          (**(code **)(*local_124 + 0x14))();
          local_24 = 0;
          local_28 = 0;
          local_20 = 0;
          local_1c = 0;
          local_6c = 0;
          local_68 = 0;
          local_64 = 0;
          local_50 = 0;
          pppppppuVar13 = (undefined4 *******)local_60[0];
          if (local_4c < 8) {
            pppppppuVar13 = local_60;
          }
          *(undefined2 *)pppppppuVar13 = 0;
          for (piVar22 = (int *)piVar22[6]; piVar22 != (int *)0x0; piVar22 = (int *)piVar22[0x10]) {
            piVar17 = piVar22 + 8;
            if (0xf < (uint)piVar22[0xd]) {
              piVar17 = (int *)*piVar17;
            }
            iVar7 = __stricmp((char *)piVar17,"REQUIREDINFO");
            if (iVar7 == 0) {
              if (piVar22 != (int *)0x0) {
                iVar12 = (**(code **)(*piVar22 + 0x14))();
                iVar11 = *(int *)(iVar12 + 0x94);
                iVar7 = iVar12 + 0x44;
                goto joined_r0x00530f64;
              }
              break;
            }
          }
          goto LAB_00531003;
        }
LAB_00531566:
        iVar7 = local_144;
        puVar8 = *(undefined4 **)(local_144 + 4);
        cVar1 = *(char *)((int)puVar8[1] + 0x15);
        local_12c = puVar8;
        puVar23 = (undefined4 *)puVar8[1];
        while (cVar1 == '\0') {
          if ((int)puVar23[3] < local_138) {
            puVar18 = (undefined4 *)puVar23[2];
            puVar23 = local_12c;
          }
          else {
            puVar18 = (undefined4 *)*puVar23;
          }
          local_12c = puVar23;
          puVar23 = puVar18;
          cVar1 = *(char *)((int)puVar18 + 0x15);
        }
        if ((local_12c == puVar8) || (local_138 < (int)local_12c[3])) {
          local_148 = puVar8;
          ppuVar19 = &local_148;
        }
        else {
          ppuVar19 = &local_12c;
        }
        if (*ppuVar19 == puVar8) {
          uVar9 = FUN_0057ef20();
          FUN_0057e850(iVar7,uVar9);
        }
        else if (local_128 != (undefined4 *)0x0) {
          (**(code **)*local_128)(1);
        }
        local_134 = (int *)local_134[0x10];
      } while (local_134 != (int *)0x0);
      if (7 < local_4c) {
        FUN_0089120c(local_60[0]);
      }
      if (7 < local_30) {
        FUN_0089120c(local_44);
      }
    }
    local_8 = 0xffffffff;
    local_30 = 7;
    local_34 = 0;
    local_44 = local_44 & 0xffff0000;
    local_100[0] = TiXmlDocument::vftable;
    if (0xf < local_a0) {
      FUN_0089120c(local_b4);
    }
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = local_b4 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_100[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_a0) {
      local_8 = 0xffffffff;
      local_100[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_b4);
    }
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = local_b4 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
joined_r0x00530f64:
  if (iVar11 == iVar7) goto LAB_00530f8d;
  pcVar15 = (char *)(iVar11 + 0x14);
  if (0xf < *(uint *)(iVar11 + 0x28)) {
    pcVar15 = *(char **)pcVar15;
  }
  iVar14 = __stricmp(pcVar15,"charlevel");
  if (iVar14 == 0) {
    if (iVar11 != 0) {
      puVar8 = (undefined4 *)(iVar11 + 0x30);
      if (0xf < *(uint *)(iVar11 + 0x44)) {
        puVar8 = (undefined4 *)*puVar8;
      }
      if (puVar8 != (undefined4 *)0x0) {
        local_6c = FUN_008917b4(puVar8);
        goto LAB_00530f94;
      }
    }
    goto LAB_00530f8d;
  }
  iVar11 = *(int *)(iVar11 + 0x50);
  goto joined_r0x00530f64;
LAB_00530f8d:
  local_6c = 0;
LAB_00530f94:
  for (iVar11 = *(int *)(iVar12 + 0x94); iVar11 != iVar7; iVar11 = *(int *)(iVar11 + 0x50)) {
    pcVar15 = (char *)(iVar11 + 0x14);
    if (0xf < *(uint *)(iVar11 + 0x28)) {
      pcVar15 = *(char **)pcVar15;
    }
    iVar14 = __stricmp(pcVar15,"skillexp");
    if (iVar14 == 0) {
      if (iVar11 != 0) {
        puVar8 = (undefined4 *)(iVar11 + 0x30);
        if (0xf < *(uint *)(iVar11 + 0x44)) {
          puVar8 = (undefined4 *)*puVar8;
        }
        if (puVar8 != (undefined4 *)0x0) {
          local_68 = FUN_008917b4(puVar8);
          goto LAB_00530fce;
        }
      }
      break;
    }
  }
  local_68 = 0;
LAB_00530fce:
  for (iVar11 = *(int *)(iVar12 + 0x94); iVar11 != iVar7; iVar11 = *(int *)(iVar11 + 0x50)) {
    pcVar15 = (char *)(iVar11 + 0x14);
    if (0xf < *(uint *)(iVar11 + 0x28)) {
      pcVar15 = *(char **)pcVar15;
    }
    iVar12 = __stricmp(pcVar15,"skillpoint");
    if (iVar12 == 0) {
      if (iVar11 != 0) {
        puVar8 = (undefined4 *)(iVar11 + 0x30);
        if (0xf < *(uint *)(iVar11 + 0x44)) {
          puVar8 = (undefined4 *)*puVar8;
        }
        if (puVar8 != (undefined4 *)0x0) {
          local_64 = FUN_008917b4(puVar8);
          goto LAB_00531003;
        }
      }
      break;
    }
  }
  local_64 = 0;
LAB_00531003:
  for (piVar22 = (int *)local_124[6]; piVar22 != (int *)0x0; piVar22 = (int *)piVar22[0x10]) {
    piVar17 = piVar22 + 8;
    if (0xf < (uint)piVar22[0xd]) {
      piVar17 = (int *)*piVar17;
    }
    iVar7 = __stricmp((char *)piVar17,"ACTIVEINFO");
    if (iVar7 == 0) {
      if (piVar22 != (int *)0x0) {
        iVar12 = (**(code **)(*piVar22 + 0x14))();
        iVar11 = *(int *)(iVar12 + 0x94);
        iVar7 = iVar12 + 0x44;
        goto joined_r0x005310dd;
      }
      break;
    }
  }
LAB_005311ad:
  iVar7 = FUN_0072e360();
  if (iVar7 != 0) {
    for (iVar11 = *(int *)(iVar7 + 0x94); iVar11 != iVar7 + 0x44; iVar11 = *(int *)(iVar11 + 0x50))
    {
      pcVar15 = (char *)(iVar11 + 0x14);
      if (0xf < *(uint *)(iVar11 + 0x28)) {
        pcVar15 = *(char **)pcVar15;
      }
      iVar12 = __stricmp(pcVar15,"ratio");
      if (iVar12 == 0) {
        if (iVar11 != 0) {
          puVar8 = (undefined4 *)(iVar11 + 0x30);
          if (0xf < *(uint *)(iVar11 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 != (undefined4 *)0x0) {
            uVar5 = FUN_008917b4(puVar8);
            local_20 = CONCAT22(local_20._2_2_,uVar5);
            goto LAB_005311fd;
          }
        }
        break;
      }
    }
    local_20 = local_20 & 0xffff0000;
LAB_005311fd:
    for (iVar11 = *(int *)(iVar7 + 0x94); iVar11 != iVar7 + 0x44; iVar11 = *(int *)(iVar11 + 0x50))
    {
      pcVar15 = (char *)(iVar11 + 0x14);
      if (0xf < *(uint *)(iVar11 + 0x28)) {
        pcVar15 = *(char **)pcVar15;
      }
      iVar12 = __stricmp(pcVar15,"rev");
      if (iVar12 == 0) {
        if (iVar11 != 0) {
          puVar8 = (undefined4 *)(iVar11 + 0x30);
          if (0xf < *(uint *)(iVar11 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 != (undefined4 *)0x0) {
            uVar5 = FUN_008917b4(puVar8);
            goto LAB_0053122d;
          }
        }
        break;
      }
    }
    uVar5 = 0;
LAB_0053122d:
    local_20 = CONCAT22(uVar5,(undefined2)local_20);
  }
  iVar7 = FUN_0072e360();
  if (iVar7 != 0) {
    for (iVar11 = *(int *)(iVar7 + 0x94); iVar11 != iVar7 + 0x44; iVar11 = *(int *)(iVar11 + 0x50))
    {
      pcVar15 = (char *)(iVar11 + 0x14);
      if (0xf < *(uint *)(iVar11 + 0x28)) {
        pcVar15 = *(char **)pcVar15;
      }
      iVar12 = __stricmp(pcVar15,"ratio");
      if (iVar12 == 0) {
        if (iVar11 != 0) {
          puVar8 = (undefined4 *)(iVar11 + 0x30);
          if (0xf < *(uint *)(iVar11 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 != (undefined4 *)0x0) {
            uVar5 = FUN_008917b4(puVar8);
            local_1c = CONCAT22(local_1c._2_2_,uVar5);
            goto LAB_0053127f;
          }
        }
        break;
      }
    }
    local_1c = local_1c & 0xffff0000;
LAB_0053127f:
    for (iVar11 = *(int *)(iVar7 + 0x94); iVar11 != iVar7 + 0x44; iVar11 = *(int *)(iVar11 + 0x50))
    {
      pcVar15 = (char *)(iVar11 + 0x14);
      if (0xf < *(uint *)(iVar11 + 0x28)) {
        pcVar15 = *(char **)pcVar15;
      }
      iVar12 = __stricmp(pcVar15,"rev");
      if (iVar12 == 0) {
        if (iVar11 != 0) {
          puVar8 = (undefined4 *)(iVar11 + 0x30);
          if (0xf < *(uint *)(iVar11 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 != (undefined4 *)0x0) {
            uVar5 = FUN_008917b4(puVar8);
            local_1c = CONCAT22(uVar5,(undefined2)local_1c);
            goto LAB_005312b3;
          }
        }
        break;
      }
    }
    local_1c = local_1c & 0xffff;
  }
LAB_005312b3:
  FUN_00508a20();
  puVar21 = local_120;
  puVar8 = (undefined4 *)local_120[1];
  if ((&local_28 < puVar8) && (puVar23 = (undefined4 *)*local_120, puVar23 <= &local_28)) {
    if (puVar8 == (undefined4 *)local_120[2]) {
      uVar16 = (int)puVar8 - (int)puVar23 >> 4;
      if (0xffffffe < uVar16) {
LAB_005316b9:
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long");
      }
      uVar16 = uVar16 + 1;
      uVar20 = (int)local_120[2] - (int)puVar23 >> 4;
      if (uVar20 < uVar16) {
        if (0xfffffff - (uVar20 >> 1) < uVar20) {
          uVar20 = 0;
        }
        else {
          uVar20 = uVar20 + (uVar20 >> 1);
        }
        if (uVar20 < uVar16) {
          uVar20 = uVar16;
        }
        FUN_00531860(uVar20);
      }
    }
    puVar8 = (undefined4 *)puVar21[1];
    puVar23 = (undefined4 *)(((int)&local_28 - (int)puVar23 & 0xfffffff0U) + *puVar21);
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = *puVar23;
      puVar8[1] = puVar23[1];
      puVar8[2] = puVar23[2];
      puVar8[3] = puVar23[3];
    }
    puVar21[1] = puVar21[1] + 0x10;
  }
  else {
    if (puVar8 == (undefined4 *)local_120[2]) {
      uVar16 = (int)((int)puVar8 - *local_120) >> 4;
      if (0xffffffe < uVar16) goto LAB_005316b9;
      uVar16 = uVar16 + 1;
      uVar20 = (int)((int)local_120[2] - *local_120) >> 4;
      if (uVar20 < uVar16) {
        if (0xfffffff - (uVar20 >> 1) < uVar20) {
          uVar20 = 0;
        }
        else {
          uVar20 = uVar20 + (uVar20 >> 1);
        }
        if (uVar20 < uVar16) {
          uVar20 = uVar16;
        }
        FUN_00531860(uVar20);
      }
    }
    puVar4 = (uint *)puVar21[1];
    if (puVar4 != (uint *)0x0) {
      *puVar4 = local_28;
      puVar4[1] = local_24;
      puVar4[2] = local_20;
      puVar4[3] = local_1c;
    }
    puVar21[1] = puVar21[1] + 0x10;
  }
  for (piVar22 = (int *)local_124[0x10]; piVar22 != (int *)0x0; piVar22 = (int *)piVar22[0x10]) {
    piVar17 = piVar22 + 8;
    if (0xf < (uint)piVar22[0xd]) {
      piVar17 = (int *)*piVar17;
    }
    iVar7 = __stricmp((char *)piVar17,"LEVEL");
    if (iVar7 == 0) goto LAB_00531558;
  }
  piVar22 = (int *)0x0;
LAB_00531558:
  local_124 = piVar22;
  if (piVar22 == (int *)0x0) goto LAB_00531566;
  goto LAB_00530ed0;
joined_r0x005310dd:
  if (iVar11 == iVar7) goto LAB_00531107;
  pcVar15 = (char *)(iVar11 + 0x14);
  if (0xf < *(uint *)(iVar11 + 0x28)) {
    pcVar15 = *(char **)pcVar15;
  }
  iVar14 = __stricmp(pcVar15,"hp");
  if (iVar14 == 0) {
    if (iVar11 != 0) {
      puVar8 = (undefined4 *)(iVar11 + 0x30);
      if (0xf < *(uint *)(iVar11 + 0x44)) {
        puVar8 = (undefined4 *)*puVar8;
      }
      if (puVar8 != (undefined4 *)0x0) {
        uVar5 = FUN_008917b4(puVar8);
        local_28 = CONCAT22(local_28._2_2_,uVar5);
        goto LAB_0053110d;
      }
    }
    goto LAB_00531107;
  }
  iVar11 = *(int *)(iVar11 + 0x50);
  goto joined_r0x005310dd;
LAB_00531107:
  local_28 = local_28 & 0xffff0000;
LAB_0053110d:
  for (iVar11 = *(int *)(iVar12 + 0x94); iVar11 != iVar7; iVar11 = *(int *)(iVar11 + 0x50)) {
    pcVar15 = (char *)(iVar11 + 0x14);
    if (0xf < *(uint *)(iVar11 + 0x28)) {
      pcVar15 = *(char **)pcVar15;
    }
    iVar14 = __stricmp(pcVar15,"sp");
    if (iVar14 == 0) {
      if (iVar11 != 0) {
        puVar8 = (undefined4 *)(iVar11 + 0x30);
        if (0xf < *(uint *)(iVar11 + 0x44)) {
          puVar8 = (undefined4 *)*puVar8;
        }
        if (puVar8 != (undefined4 *)0x0) {
          uVar5 = FUN_008917b4(puVar8);
          local_28 = CONCAT22(uVar5,(undefined2)local_28);
          goto LAB_00531141;
        }
      }
      break;
    }
  }
  local_28 = local_28 & 0xffff;
LAB_00531141:
  for (iVar11 = *(int *)(iVar12 + 0x94); iVar11 != iVar7; iVar11 = *(int *)(iVar11 + 0x50)) {
    pcVar15 = (char *)(iVar11 + 0x14);
    if (0xf < *(uint *)(iVar11 + 0x28)) {
      pcVar15 = *(char **)pcVar15;
    }
    iVar14 = __stricmp(pcVar15,"mp");
    if (iVar14 == 0) {
      if (iVar11 != 0) {
        puVar8 = (undefined4 *)(iVar11 + 0x30);
        if (0xf < *(uint *)(iVar11 + 0x44)) {
          puVar8 = (undefined4 *)*puVar8;
        }
        if (puVar8 != (undefined4 *)0x0) {
          uVar5 = FUN_008917b4(puVar8);
          goto LAB_00531171;
        }
      }
      break;
    }
  }
  uVar5 = 0;
LAB_00531171:
  iVar11 = *(int *)(iVar12 + 0x94);
  local_24 = CONCAT22(local_24._2_2_,uVar5);
  for (; iVar11 != iVar7; iVar11 = *(int *)(iVar11 + 0x50)) {
    pcVar15 = (char *)(iVar11 + 0x14);
    if (0xf < *(uint *)(iVar11 + 0x28)) {
      pcVar15 = *(char **)pcVar15;
    }
    iVar12 = __stricmp(pcVar15,"cooltime");
    if (iVar12 == 0) {
      if (iVar11 != 0) {
        puVar8 = (undefined4 *)(iVar11 + 0x30);
        if (0xf < *(uint *)(iVar11 + 0x44)) {
          puVar8 = (undefined4 *)*puVar8;
        }
        if (puVar8 != (undefined4 *)0x0) {
          uVar5 = FUN_008917b4(puVar8);
          local_24 = CONCAT22(uVar5,(undefined2)local_24);
          goto LAB_005311ad;
        }
      }
      break;
    }
  }
  local_24 = local_24 & 0xffff;
  goto LAB_005311ad;
}


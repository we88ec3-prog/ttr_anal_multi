
void FUN_0047de40(void)

{
  int *piVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  undefined4 *puVar13;
  uint *puVar14;
  int iVar15;
  int local_104;
  uint local_100;
  undefined4 *local_fc;
  uint uStack_f8;
  int iStack_f4;
  int aiStack_f0 [3];
  undefined4 *puStack_e4;
  undefined1 auStack_e0 [16];
  uint local_d0;
  int *piStack_cc;
  int *piStack_c8;
  int *piStack_c4;
  undefined4 local_c0;
  uint local_bc;
  uint local_b4;
  uint uStack_b0;
  int aiStack_ac [2];
  undefined4 local_a4;
  uint local_a0;
  undefined **local_98 [17];
  char local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00925475;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_104;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffef0;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar5 = FUN_0072e2e0("CHAPTERTABLE");
    if (iVar5 == 0) {
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
    else {
      local_104 = FUN_0072e360(uVar4);
      if (local_104 != 0) {
        do {
          local_100 = FUN_00891268(0x44);
          local_c._0_1_ = 1;
          if (local_100 == 0) {
            local_fc = (undefined4 *)0x0;
          }
          else {
            local_fc = (undefined4 *)FUN_0047e580(local_100);
          }
          puVar13 = local_fc;
          local_c = (uint)local_c._1_3_ << 8;
          iVar5 = FUN_007300a0("chapterIdx");
          if (iVar5 == 0) {
LAB_0047e005:
            uVar7 = 0;
          }
          else {
            puVar6 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 == (undefined4 *)0x0) goto LAB_0047e005;
            uVar7 = FUN_008917b4(puVar6);
          }
          *puVar13 = uVar7;
          iVar5 = FUN_007300a0("townId");
          if (iVar5 == 0) {
LAB_0047e031:
            uVar7 = 0;
          }
          else {
            puVar6 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 == (undefined4 *)0x0) goto LAB_0047e031;
            uVar7 = FUN_008917b4(puVar6);
          }
          puVar13[1] = uVar7;
          local_a0 = 0xf;
          local_a4 = 0;
          local_b4 = local_b4 & 0xffffff00;
          FUN_00402a70("chapterName",0xb);
          local_c._0_1_ = 2;
          uVar7 = FUN_0072ecf0(&DAT_00bf2375);
          local_c = CONCAT31(local_c._1_3_,3);
          FUN_00440130(uVar7);
          if (0xf < local_bc) {
            FUN_0089120c(local_d0);
          }
          local_c = local_c & 0xffffff00;
          local_bc = 0xf;
          local_c0 = 0;
          local_d0 = local_d0 & 0xffffff00;
          if (0xf < local_a0) {
            FUN_0089120c(local_b4);
          }
          iStack_f4 = FUN_0072e360();
          if (iStack_f4 != 0) {
            do {
              piVar12 = (int *)0x0;
              piStack_cc = (int *)0x0;
              piStack_c8 = (int *)0x0;
              piStack_c4 = (int *)0x0;
              iVar15 = iStack_f4 + 0x44;
              local_c = CONCAT31(local_c._1_3_,4);
              for (iVar5 = *(int *)(iStack_f4 + 0x94); iVar5 != iVar15;
                  iVar5 = *(int *)(iVar5 + 0x50)) {
                pcVar9 = (char *)(iVar5 + 0x14);
                if (0xf < *(uint *)(iVar5 + 0x28)) {
                  pcVar9 = *(char **)pcVar9;
                }
                iVar8 = __stricmp(pcVar9,"questId");
                if (iVar8 == 0) {
                  if (iVar5 != 0) {
                    puVar13 = (undefined4 *)(iVar5 + 0x30);
                    if (0xf < *(uint *)(iVar5 + 0x44)) {
                      puVar13 = (undefined4 *)*puVar13;
                    }
                    if (puVar13 != (undefined4 *)0x0) {
                      uStack_f8 = FUN_008917b4(puVar13);
                      goto LAB_0047e144;
                    }
                  }
                  break;
                }
              }
              uStack_f8 = 0;
LAB_0047e144:
              local_100 = uStack_f8;
              aiStack_f0[1] = FUN_0072e360();
              puVar13 = local_fc;
              uVar4 = uStack_f8;
joined_r0x0047e160:
              local_fc = puVar13;
              uStack_f8 = uVar4;
              if (aiStack_f0[1] != 0) {
                iVar15 = aiStack_f0[1] + 0x44;
                for (iVar5 = *(int *)(aiStack_f0[1] + 0x94); iVar5 != iVar15;
                    iVar5 = *(int *)(iVar5 + 0x50)) {
                  pcVar9 = (char *)(iVar5 + 0x14);
                  if (0xf < *(uint *)(iVar5 + 0x28)) {
                    pcVar9 = *(char **)pcVar9;
                  }
                  iVar8 = __stricmp(pcVar9,"sceneIdx");
                  if (iVar8 == 0) {
                    if (iVar5 != 0) {
                      puVar13 = (undefined4 *)(iVar5 + 0x30);
                      if (0xf < *(uint *)(iVar5 + 0x44)) {
                        puVar13 = (undefined4 *)*puVar13;
                      }
                      if (puVar13 != (undefined4 *)0x0) {
                        iVar5 = FUN_008917b4(puVar13);
                        goto LAB_0047e1ab;
                      }
                    }
                    break;
                  }
                }
                iVar5 = 0;
LAB_0047e1ab:
                aiStack_f0[0] = iVar5;
                if ((aiStack_f0 < piVar12) && (piStack_cc <= aiStack_f0)) {
                  iVar5 = (int)aiStack_f0 - (int)piStack_cc;
                  if (piVar12 == piStack_c4) {
                    uVar4 = (int)piVar12 - (int)piStack_cc >> 2;
                    if (0x3ffffffe < uVar4) goto LAB_0047e575;
                    uVar4 = uVar4 + 1;
                    uVar10 = (int)piStack_c4 - (int)piStack_cc >> 2;
                    if (uVar10 < uVar4) {
                      if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                        uVar10 = 0;
                      }
                      else {
                        uVar10 = uVar10 + (uVar10 >> 1);
                      }
                      if (uVar10 < uVar4) {
                        uVar10 = uVar4;
                      }
                      FUN_00797980(uVar10);
                      piVar12 = piStack_c8;
                    }
                  }
                  if (piVar12 != (int *)0x0) {
                    *piVar12 = piStack_cc[iVar5 >> 2];
                  }
                }
                else {
                  if (piVar12 == piStack_c4) {
                    uVar4 = (int)piVar12 - (int)piStack_cc >> 2;
                    if (0x3ffffffe < uVar4) goto LAB_0047e575;
                    uVar4 = uVar4 + 1;
                    uVar10 = (int)piStack_c4 - (int)piStack_cc >> 2;
                    if (uVar10 < uVar4) {
                      if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                        uVar10 = 0;
                      }
                      else {
                        uVar10 = uVar10 + (uVar10 >> 1);
                      }
                      if (uVar10 < uVar4) {
                        uVar10 = uVar4;
                      }
                      FUN_00797980(uVar10);
                      piVar12 = piStack_c8;
                    }
                  }
                  if (piVar12 != (int *)0x0) {
                    *piVar12 = iVar5;
                  }
                }
                piVar12 = piVar12 + 1;
                piStack_c8 = piVar12;
                for (piVar1 = *(int **)(aiStack_f0[1] + 0x40); piVar1 != (int *)0x0;
                    piVar1 = (int *)piVar1[0x10]) {
                  iVar5 = (**(code **)(*piVar1 + 0x18))();
                  if (iVar5 != 0) {
                    aiStack_f0[1] = (**(code **)(*piVar1 + 0x18))();
                    puVar13 = local_fc;
                    uVar4 = uStack_f8;
                    goto joined_r0x0047e160;
                  }
                }
                aiStack_f0[1] = 0;
                puVar13 = local_fc;
                uVar4 = uStack_f8;
                goto joined_r0x0047e160;
              }
              puVar2 = (uint *)puVar13[10];
              puVar14 = puVar13 + 9;
              local_d0 = uVar4;
              if ((&local_100 < puVar2) && (puVar3 = (uint *)*puVar14, puVar3 <= &local_100)) {
                if (puVar2 == (uint *)puVar13[0xb]) {
                  uVar4 = (int)puVar2 - (int)puVar3 >> 2;
                  if (0x3ffffffe < uVar4) {
LAB_0047e575:
                    /* WARNING: Subroutine does not return */
                    FUN_0087db30("vector<T> too long");
                  }
                  uVar4 = uVar4 + 1;
                  uVar10 = (int)puVar13[0xb] - (int)puVar3 >> 2;
                  if (uVar10 < uVar4) {
                    if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                      uVar10 = 0;
                    }
                    else {
                      uVar10 = uVar10 + (uVar10 >> 1);
                    }
                    if (uVar10 < uVar4) {
                      uVar10 = uVar4;
                    }
                    FUN_00797980(uVar10);
                  }
                }
                if ((undefined4 *)puVar13[10] != (undefined4 *)0x0) {
                  *(undefined4 *)puVar13[10] =
                       *(undefined4 *)(*puVar14 + ((int)&local_100 - (int)puVar3 >> 2) * 4);
                }
              }
              else {
                if (puVar2 == (uint *)puVar13[0xb]) {
                  uVar10 = (int)((int)puVar2 - *puVar14) >> 2;
                  if (0x3ffffffe < uVar10) goto LAB_0047e575;
                  uVar10 = uVar10 + 1;
                  uVar11 = (int)((int)puVar13[0xb] - *puVar14) >> 2;
                  if (uVar11 < uVar10) {
                    if (0x3fffffff - (uVar11 >> 1) < uVar11) {
                      uVar11 = 0;
                    }
                    else {
                      uVar11 = uVar11 + (uVar11 >> 1);
                    }
                    if (uVar11 < uVar10) {
                      uVar11 = uVar10;
                    }
                    FUN_00797980(uVar11);
                  }
                }
                if ((uint *)puVar13[10] != (uint *)0x0) {
                  *(uint *)puVar13[10] = uVar4;
                }
              }
              puVar13[10] = puVar13[10] + 4;
              local_b4 = uStack_f8;
              uStack_b0 = uStack_f8;
              FUN_007e8a90(aiStack_ac,&piStack_cc);
              puVar13 = local_fc + 0xd;
              local_c = CONCAT31(local_c._1_3_,5);
              FUN_0047ed90(&local_b4);
              FUN_0047eb20(puVar13,auStack_e0);
              if (aiStack_ac[0] != 0) {
                FUN_0089120c(aiStack_ac[0]);
              }
              local_c = local_c & 0xffffff00;
              if (piStack_cc != (int *)0x0) {
                FUN_0089120c(piStack_cc);
              }
              for (piVar12 = *(int **)(iStack_f4 + 0x40); piVar12 != (int *)0x0;
                  piVar12 = (int *)piVar12[0x10]) {
                iVar5 = (**(code **)(*piVar12 + 0x18))();
                if (iVar5 != 0) {
                  iStack_f4 = (**(code **)(*piVar12 + 0x18))();
                  goto LAB_0047e47a;
                }
              }
              iStack_f4 = 0;
LAB_0047e47a:
            } while (iStack_f4 != 0);
            iStack_f4 = 0;
            puVar13 = local_fc;
          }
          aiStack_f0[2] = *puVar13;
          puStack_e4 = puVar13;
          uVar7 = FUN_0057ef20();
          FUN_0057e850(&DAT_00fc0f68,uVar7);
          for (piVar12 = *(int **)(local_104 + 0x40); piVar12 != (int *)0x0;
              piVar12 = (int *)piVar12[0x10]) {
            iVar5 = (**(code **)(*piVar12 + 0x18))();
            if (iVar5 != 0) {
              local_104 = (**(code **)(*piVar12 + 0x18))();
              goto LAB_0047e4d2;
            }
          }
          local_104 = 0;
LAB_0047e4d2:
        } while (local_104 != 0);
        local_104 = 0;
      }
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
  }
  else {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_104);
  return;
}


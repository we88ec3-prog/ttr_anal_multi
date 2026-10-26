
void FUN_007d5060(uint *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  char *****pppppcVar11;
  char *pcVar12;
  undefined4 *****pppppuVar13;
  undefined4 *puVar14;
  char *in_ECX;
  char *in_EDX;
  uint *puVar15;
  long lVar16;
  float10 fVar17;
  undefined1 local_1b0 [4];
  undefined1 local_1ac [4];
  undefined1 local_1a8 [4];
  undefined1 local_1a4 [4];
  int local_1a0;
  int local_19c;
  int local_198;
  uint *local_194;
  char *local_190;
  uint *local_18c;
  uint *local_188;
  int local_184;
  char local_17d;
  int local_17c;
  int local_178 [6];
  uint local_160;
  int local_158;
  undefined4 local_154;
  undefined1 local_90;
  uint local_8c;
  undefined4 local_7c;
  uint local_78;
  char ****local_6c [5];
  uint local_58;
  undefined4 ****local_50 [4];
  undefined4 local_40;
  uint local_3c;
  undefined4 ****local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092854c;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_188 = param_1;
  local_3c = 0xf;
  local_40 = 0;
  local_50[0] = (undefined4 ****)((uint)local_50[0] & 0xffffff00);
  pcVar5 = in_ECX;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_190 = in_ECX;
  local_18 = uVar4;
  FUN_00402a70(in_ECX,(int)pcVar5 - (int)(in_ECX + 1));
  local_8 = 0;
  pcVar5 = in_EDX;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(in_EDX,(int)pcVar5 - (int)(in_EDX + 1));
  local_158 = 0;
  local_154 = 0;
  FUN_0071bc20(uVar4);
  local_90 = 0;
  local_78 = 0xf;
  local_7c = 0;
  local_8c = local_8c & 0xffffff00;
  local_8._0_1_ = 1;
  pppppuVar13 = (undefined4 *****)local_50[0];
  if (local_3c < 0x10) {
    pppppuVar13 = local_50;
  }
  piVar6 = (int *)FUN_00714770(pppppuVar13,&DAT_00bed1e0);
  if (piVar6 == (int *)0x0) {
LAB_007d5171:
    local_8 = (uint)local_8._1_3_ << 8;
    if (0xf < local_78) {
      FUN_0089120c(local_8c);
    }
  }
  else {
    (**(code **)(*piVar6 + 0x38))();
    uVar7 = (**(code **)(*piVar6 + 0x2c))();
    local_17d = FUN_00499340(uVar7);
    (**(code **)(*piVar6 + 4))();
    if (local_17d == '\0') goto LAB_007d5171;
    local_184 = local_158;
    FUN_00719da0(local_178);
    if (local_178[0] == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      if (0xf < local_78) {
        FUN_0089120c(local_8c);
      }
      local_78 = 0xf;
      local_7c = 0;
      local_8c = local_8c & 0xffffff00;
      FUN_0071bc90(&local_158);
      goto joined_r0x007d596e;
    }
    FUN_0071baa0("EquipIdentifier");
    if (local_184 != 0) {
      uVar4 = FUN_00719fa0(local_178,0);
      local_188[8] = uVar4;
    }
    fVar17 = (float10)FUN_00719fe0(local_178,0x3f800000);
    puVar15 = local_188;
    local_188[0xe] = (uint)(float)fVar17;
    FUN_00719da0(&local_17c);
    if (local_17c != 0) {
      local_194 = puVar15 + 10;
      do {
        FUN_00719f10(&local_17c,"Object");
        local_8._0_1_ = 2;
        pppppcVar11 = (char *****)local_6c[0];
        if (local_58 < 0x10) {
          pppppcVar11 = local_6c;
        }
        iVar8 = __stricmp((char *)pppppcVar11,"Object");
        if (iVar8 == 0) {
          local_178[0] = FUN_00891268(300);
          local_8._0_1_ = 3;
          if (local_178[0] == 0) {
            local_178[0] = 0;
          }
          else {
            local_178[0] = FUN_007eef50(local_178[0]);
          }
          local_8._0_1_ = 2;
          pcVar5 = local_190;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(local_190,(int)pcVar5 - (int)(local_190 + 1));
          FUN_0071baa0("Texture");
          if (local_198 == 0) {
            pcVar5 = (char *)0x0;
          }
          else {
            pcVar5 = *(char **)(local_198 + 8);
            if (pcVar5 == (char *)0x0) {
              pcVar5 = "";
            }
          }
          pcVar9 = pcVar5;
          do {
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar5,(int)pcVar9 - (int)(pcVar5 + 1));
          FUN_0071baa0(&DAT_00c4fa0c);
          iVar8 = local_178[0];
          if (local_19c == 0) {
            pcVar5 = (char *)0x0;
          }
          else {
            pcVar5 = *(char **)(local_19c + 8);
            if (pcVar5 == (char *)0x0) {
              pcVar5 = "";
            }
          }
          pcVar9 = pcVar5;
          do {
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar5,(int)pcVar9 - (int)(pcVar5 + 1));
          uVar7 = FUN_00719f10(&local_17c,&DAT_00bf2375);
          local_8._0_1_ = 4;
          FUN_00403040(uVar7,0,0xffffffff);
          local_8._0_1_ = 2;
          if (0xf < local_20) {
            FUN_0089120c(local_34[0]);
          }
          FUN_00719da0(&local_184);
          if (local_184 != 0) {
            FUN_00719f10(&local_184,&DAT_00bf2375);
            local_8._0_1_ = 5;
            pppppuVar13 = (undefined4 *****)local_34[0];
            if (local_20 < 0x10) {
              pppppuVar13 = local_34;
            }
            FUN_007d59a0(pppppuVar13,iVar8);
            local_8._0_1_ = 2;
            if (0xf < local_20) {
              FUN_0089120c(local_34[0]);
            }
          }
          FUN_00719da0(&local_18c);
          iVar8 = local_178[0];
          iVar10 = local_178[0];
          puVar15 = local_18c;
          if (local_18c != (uint *)0x0) {
LAB_007d54b0:
            FUN_00719f10(&local_18c,&DAT_00bf2375);
            local_8 = CONCAT31(local_8._1_3_,6);
            pppppuVar13 = (undefined4 *****)local_34[0];
            if (local_20 < 0x10) {
              pppppuVar13 = local_34;
            }
            FUN_007e9ef0(iVar8,pppppuVar13);
            if (puVar15 != (uint *)0x0) {
              for (puVar15 = (uint *)puVar15[6]; puVar15 != (uint *)0x0;
                  puVar15 = (uint *)puVar15[6]) {
                if (((char *)puVar15[2] != (char *)0x0) &&
                   (iVar10 = __stricmp("ReplaceObject",(char *)puVar15[2]), iVar10 == 0)) {
                  if (puVar15 == (uint *)0x0) goto LAB_007d5575;
                  goto LAB_007d5543;
                }
              }
            }
            goto LAB_007d5510;
          }
        }
        else {
          pppppcVar11 = (char *****)local_6c[0];
          if (local_58 < 0x10) {
            pppppcVar11 = local_6c;
          }
          iVar8 = __stricmp((char *)pppppcVar11,"Particle");
          iVar10 = 0;
          if (iVar8 == 0) {
            iVar8 = FUN_00891268(0x78);
            if (iVar8 == 0) {
              local_178[0] = 0;
            }
            else {
              local_178[0] = FUN_007f1050();
            }
            pcVar5 = (char *)FUN_00719f10(&local_17c,&DAT_00bf2375);
            local_8._0_1_ = 7;
            pcVar9 = (char *)FUN_00719f10(&local_17c,&DAT_00bf2375);
            local_8 = CONCAT31(local_8._1_3_,8);
            if (0xf < *(uint *)(pcVar5 + 0x14)) {
              pcVar5 = *(char **)pcVar5;
            }
            if (0xf < *(uint *)(pcVar9 + 0x14)) {
              pcVar9 = *(char **)pcVar9;
            }
            pcVar12 = pcVar9;
            do {
              cVar1 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(pcVar9,(int)pcVar12 - (int)(pcVar9 + 1));
            pcVar9 = pcVar5;
            do {
              cVar1 = *pcVar9;
              pcVar9 = pcVar9 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(pcVar5,(int)pcVar9 - (int)(pcVar5 + 1));
            if (0xf < local_20) {
              FUN_0089120c(local_34[0]);
            }
            local_8._0_1_ = 2;
            local_20 = 0xf;
            local_24 = 0;
            local_34[0] = (undefined4 ****)((uint)local_34[0] & 0xffffff00);
            if (0xf < local_160) {
              FUN_0089120c(local_178[1]);
            }
            FUN_00719da0(&local_188);
            puVar15 = local_188;
            iVar10 = local_178[0];
            if (local_188 != (uint *)0x0) {
LAB_007d56c0:
              FUN_00719f10(&local_188,&DAT_00bf2375);
              local_8 = CONCAT31(local_8._1_3_,9);
              pppppuVar13 = (undefined4 *****)local_34[0];
              if (local_20 < 0x10) {
                pppppuVar13 = local_34;
              }
              FUN_007e9ef0(local_178[0],pppppuVar13);
              if (puVar15 != (uint *)0x0) {
                for (puVar15 = (uint *)puVar15[6]; puVar15 != (uint *)0x0;
                    puVar15 = (uint *)puVar15[6]) {
                  if (((char *)puVar15[2] != (char *)0x0) &&
                     (iVar8 = __stricmp("ReplaceObject",(char *)puVar15[2]), iVar8 == 0)) {
                    if (puVar15 == (uint *)0x0) goto LAB_007d5870;
                    goto LAB_007d583e;
                  }
                }
              }
              goto LAB_007d5724;
            }
          }
        }
LAB_007d5752:
        puVar14 = (undefined4 *)FUN_00719da0(local_1a4);
        puVar14 = (undefined4 *)FUN_007d5db0(*puVar14);
        uVar7 = puVar14[1];
        uVar2 = puVar14[2];
        *(undefined4 *)(iVar10 + 4) = *puVar14;
        *(undefined4 *)(iVar10 + 8) = uVar7;
        *(undefined4 *)(iVar10 + 0xc) = uVar2;
        puVar14 = (undefined4 *)FUN_00719da0(local_1b0);
        puVar14 = (undefined4 *)FUN_007d5db0(*puVar14);
        uVar7 = puVar14[1];
        uVar2 = puVar14[2];
        *(undefined4 *)(iVar10 + 0x10) = *puVar14;
        *(undefined4 *)(iVar10 + 0x14) = uVar7;
        *(undefined4 *)(iVar10 + 0x18) = uVar2;
        puVar14 = (undefined4 *)FUN_00719da0(local_1a8);
        puVar14 = (undefined4 *)FUN_007d5db0(*puVar14);
        uVar7 = puVar14[1];
        uVar2 = puVar14[2];
        *(undefined4 *)(iVar10 + 0x1c) = *puVar14;
        *(undefined4 *)(iVar10 + 0x20) = uVar7;
        *(undefined4 *)(iVar10 + 0x24) = uVar2;
        lVar16 = 1;
        FUN_0071baa0("HierarchyTier");
        if (local_1a0 != 0) {
          if (*(char **)(local_1a0 + 8) == (char *)0x0) {
            lVar16 = 0;
          }
          else {
            lVar16 = _strtol(*(char **)(local_1a0 + 8),(char **)0x0,10);
          }
        }
        puVar15 = local_194;
        *(long *)(iVar10 + 0x3c) = lVar16;
        piVar6 = (int *)local_194[1];
        local_178[0] = iVar10;
        if (local_178 < piVar6) {
          piVar3 = (int *)*local_194;
          if (local_178 < piVar3) goto LAB_007d58d7;
          if (piVar6 == (int *)local_194[2]) {
            FUN_00797930();
          }
          if ((undefined4 *)puVar15[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar15[1] =
                 *(undefined4 *)(*puVar15 + ((int)local_178 - (int)piVar3 >> 2) * 4);
          }
        }
        else {
LAB_007d58d7:
          if (piVar6 == (int *)local_194[2]) {
            FUN_00797930();
          }
          if ((int *)puVar15[1] != (int *)0x0) {
            *(int *)puVar15[1] = iVar10;
          }
        }
        puVar15[1] = puVar15[1] + 4;
        piVar6 = (int *)FUN_00719e00(local_1ac);
        iVar8 = *piVar6;
        local_8._0_1_ = 1;
        local_17c = iVar8;
        if (0xf < local_58) {
          FUN_0089120c(local_6c[0]);
        }
      } while (iVar8 != 0);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (0xf < local_78) {
      FUN_0089120c(local_8c);
    }
  }
  local_7c = 0;
  local_78 = 0xf;
  local_8c = local_8c & 0xffffff00;
  FUN_0071bc90(&local_158);
joined_r0x007d596e:
  if (0xf < local_3c) {
    FUN_0089120c(local_50[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
LAB_007d5543:
  do {
    if ((*puVar15 & 7) == 1) goto LAB_007d5512;
    for (puVar15 = (uint *)puVar15[6]; puVar15 != (uint *)0x0; puVar15 = (uint *)puVar15[6]) {
      if (((char *)puVar15[2] != (char *)0x0) &&
         (iVar10 = __stricmp("ReplaceObject",(char *)puVar15[2]), iVar10 == 0)) goto LAB_007d5577;
    }
LAB_007d5575:
    puVar15 = (uint *)0x0;
LAB_007d5577:
  } while (puVar15 != (uint *)0x0);
LAB_007d5510:
  puVar15 = (uint *)0x0;
LAB_007d5512:
  local_8._0_1_ = 2;
  local_18c = puVar15;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  iVar10 = local_178[0];
  if (puVar15 == (uint *)0x0) goto LAB_007d5752;
  goto LAB_007d54b0;
LAB_007d583e:
  do {
    if ((*puVar15 & 7) == 1) goto LAB_007d5726;
    for (puVar15 = (uint *)puVar15[6]; puVar15 != (uint *)0x0; puVar15 = (uint *)puVar15[6]) {
      if (((char *)puVar15[2] != (char *)0x0) &&
         (iVar8 = __stricmp("ReplaceObject",(char *)puVar15[2]), iVar8 == 0)) goto LAB_007d5872;
    }
LAB_007d5870:
    puVar15 = (uint *)0x0;
LAB_007d5872:
  } while (puVar15 != (uint *)0x0);
LAB_007d5724:
  puVar15 = (uint *)0x0;
LAB_007d5726:
  local_8._0_1_ = 2;
  local_188 = puVar15;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  iVar10 = local_178[0];
  if (puVar15 == (uint *)0x0) goto LAB_007d5752;
  goto LAB_007d56c0;
}


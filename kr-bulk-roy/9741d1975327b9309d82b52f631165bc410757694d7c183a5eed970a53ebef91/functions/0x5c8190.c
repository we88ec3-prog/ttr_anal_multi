
void FUN_005c8190(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int *piVar11;
  char *in_ECX;
  int in_EDX;
  int *piVar12;
  undefined1 local_1f4 [16];
  undefined1 local_1e4 [8];
  undefined **local_1dc [3];
  undefined **local_1d0 [5];
  int local_1bc;
  char *local_1b8;
  char *local_1b4;
  int *local_1b0;
  int *local_1ac;
  uint *local_1a8;
  undefined **local_1a4 [19];
  uint local_158;
  undefined4 local_148;
  uint local_144;
  uint local_12c [4];
  int *local_11c;
  uint local_118;
  undefined2 local_110 [8];
  int *local_100;
  undefined4 local_fc;
  undefined2 local_f4;
  int *local_e4;
  undefined4 local_e0;
  undefined1 local_d8 [20];
  uint local_c4 [4];
  undefined4 local_b4;
  uint local_b0;
  uint local_a8 [4];
  undefined4 local_98;
  uint local_94;
  undefined2 local_8c [2];
  undefined4 *local_88;
  undefined4 local_84;
  uint local_7c [4];
  undefined4 local_6c;
  uint local_68;
  uint local_60 [4];
  undefined4 local_50;
  uint local_4c;
  undefined1 local_44 [4];
  undefined4 *local_40;
  undefined4 local_3c;
  undefined2 *local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922c5d;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_1bc = in_EDX;
  local_14 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  FUN_0072ef00(local_1a4,in_EDX + 4);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 != '\0') && (iVar4 = FUN_0072e2e0("FXUIXML"), iVar4 != 0)) {
    piVar5 = (int *)FUN_0072e2e0("FXUIIMAGESETGROUP");
    piVar11 = piVar5;
    while (local_1b0 = piVar11, piVar5 != (int *)0x0) {
      local_94 = 7;
      local_98 = 0;
      local_a8[0] = local_a8[0] & 0xffff0000;
      local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
      local_8._0_1_ = 1;
      local_84 = 0;
      puVar6 = (undefined4 *)FUN_00891268(0x74);
      if (puVar6 == (undefined4 *)0x0) {
        local_1b4 = (char *)0x0;
        std::exception::exception((exception *)local_1d0,&local_1b4);
        local_1d0[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_1d0,&DAT_00c857a8);
      }
      *puVar6 = puVar6;
      puVar6[1] = puVar6;
      puVar6[2] = puVar6;
      *(undefined1 *)(puVar6 + 0x1c) = 1;
      *(undefined1 *)((int)puVar6 + 0x71) = 1;
      local_8._0_1_ = 2;
      local_88 = puVar6;
      (**(code **)(*piVar11 + 0x14))();
      iVar4 = FUN_007300a0(&DAT_00bed1d4);
      if (iVar4 == 0) {
        pcVar3 = (char *)0x0;
      }
      else if (*(uint *)(iVar4 + 0x44) < 0x10) {
        pcVar3 = (char *)(iVar4 + 0x30);
      }
      else {
        pcVar3 = *(char **)(iVar4 + 0x30);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      pcVar7 = pcVar3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar3,(int)pcVar7 - (int)(pcVar3 + 1));
      local_8._0_1_ = 3;
      FUN_00440130(local_30);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      for (piVar5 = (int *)piVar11[6]; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[0x10]) {
        piVar12 = piVar5 + 8;
        if (0xf < (uint)piVar5[0xd]) {
          piVar12 = (int *)*piVar12;
        }
        iVar4 = __stricmp((char *)piVar12,"FXUIIMAGESET");
        if (iVar4 == 0) goto LAB_005c8375;
      }
      piVar5 = (int *)0x0;
LAB_005c8375:
      local_1ac = piVar5;
      if (piVar5 != (int *)0x0) {
        do {
          piVar5 = local_1ac;
          local_68 = 7;
          local_6c = 0;
          local_7c[0] = local_7c[0] & 0xffff0000;
          local_4c = 7;
          local_50 = 0;
          local_60[0] = local_60[0] & 0xffff0000;
          local_8._0_1_ = 5;
          local_3c = 0;
          puVar6 = (undefined4 *)FUN_00891268(0x30);
          if (puVar6 == (undefined4 *)0x0) {
            local_1b8 = (char *)0x0;
            std::exception::exception((exception *)local_1dc,&local_1b8);
            local_1dc[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_1dc,&DAT_00c857a8);
          }
          *puVar6 = puVar6;
          puVar6[1] = puVar6;
          puVar6[2] = puVar6;
          *(undefined1 *)(puVar6 + 0xb) = 1;
          *(undefined1 *)((int)puVar6 + 0x2d) = 1;
          local_8 = CONCAT31(local_8._1_3_,6);
          local_40 = puVar6;
          iVar8 = (**(code **)(*piVar5 + 0x14))();
          for (iVar4 = *(int *)(iVar8 + 0x94); iVar4 != iVar8 + 0x44; iVar4 = *(int *)(iVar4 + 0x50)
              ) {
            pcVar3 = (char *)(iVar4 + 0x14);
            if (0xf < *(uint *)(iVar4 + 0x28)) {
              pcVar3 = *(char **)pcVar3;
            }
            iVar9 = __stricmp(pcVar3,"code");
            if (iVar9 == 0) {
              if (iVar4 != 0) {
                pcVar3 = (char *)(iVar4 + 0x30);
                if (0xf < *(uint *)(iVar4 + 0x44)) {
                  pcVar3 = *(char **)pcVar3;
                }
                goto LAB_005c842a;
              }
              break;
            }
          }
          pcVar3 = (char *)0x0;
LAB_005c842a:
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = local_30[0] & 0xffffff00;
          pcVar7 = pcVar3;
          do {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar3,(int)pcVar7 - (int)(pcVar3 + 1));
          local_8._0_1_ = 7;
          FUN_00440130(local_30);
          local_8 = CONCAT31(local_8._1_3_,6);
          if (0xf < local_1c) {
            FUN_0089120c(local_30[0]);
          }
          iVar8 = (**(code **)(*piVar5 + 0x14))();
          for (iVar4 = *(int *)(iVar8 + 0x94); iVar4 != iVar8 + 0x44; iVar4 = *(int *)(iVar4 + 0x50)
              ) {
            pcVar3 = (char *)(iVar4 + 0x14);
            if (0xf < *(uint *)(iVar4 + 0x28)) {
              pcVar3 = *(char **)pcVar3;
            }
            iVar9 = __stricmp(pcVar3,"filename");
            if (iVar9 == 0) {
              if (iVar4 != 0) {
                pcVar3 = (char *)(iVar4 + 0x30);
                if (0xf < *(uint *)(iVar4 + 0x44)) {
                  pcVar3 = *(char **)pcVar3;
                }
                goto LAB_005c84c0;
              }
              break;
            }
          }
          pcVar3 = (char *)0x0;
LAB_005c84c0:
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = local_30[0] & 0xffffff00;
          pcVar7 = pcVar3;
          do {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar3,(int)pcVar7 - (int)(pcVar3 + 1));
          local_8._0_1_ = 8;
          FUN_00440130(local_30);
          local_8._0_1_ = 6;
          if (0xf < local_1c) {
            FUN_0089120c(local_30[0]);
          }
          for (piVar5 = (int *)piVar5[6]; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[0x10]) {
            piVar11 = piVar5 + 8;
            if (0xf < (uint)piVar5[0xd]) {
              piVar11 = (int *)*piVar11;
            }
            iVar4 = __stricmp((char *)piVar11,"RECT");
            if (iVar4 == 0) goto LAB_005c8545;
          }
          piVar5 = (int *)0x0;
LAB_005c8545:
          piVar12 = (int *)0x0;
          while (piVar5 != (int *)0x0) {
            local_b0 = 7;
            local_b4 = 0;
            local_c4[0] = local_c4[0] & 0xffff0000;
            local_8 = CONCAT31(local_8._1_3_,9);
            iVar8 = (**(code **)(*piVar5 + 0x14))();
            for (iVar4 = *(int *)(iVar8 + 0x94); iVar4 != iVar8 + 0x44;
                iVar4 = *(int *)(iVar4 + 0x50)) {
              pcVar3 = (char *)(iVar4 + 0x14);
              if (0xf < *(uint *)(iVar4 + 0x28)) {
                pcVar3 = *(char **)pcVar3;
              }
              iVar9 = __stricmp(pcVar3,"name");
              if (iVar9 == 0) {
                if (iVar4 != 0) {
                  puVar6 = (undefined4 *)(iVar4 + 0x30);
                  if (0xf < *(uint *)(iVar4 + 0x44)) {
                    puVar6 = (undefined4 *)*puVar6;
                  }
                  if (puVar6 != (undefined4 *)0x0) {
                    local_1a8 = (uint *)FUN_008917b4(puVar6);
                    goto LAB_005c85c2;
                  }
                }
                break;
              }
            }
            local_1a8 = (uint *)0x0;
LAB_005c85c2:
            iVar8 = (**(code **)(*piVar5 + 0x14))();
            for (iVar4 = *(int *)(iVar8 + 0x94); iVar4 != iVar8 + 0x44;
                iVar4 = *(int *)(iVar4 + 0x50)) {
              pcVar3 = (char *)(iVar4 + 0x14);
              if (0xf < *(uint *)(iVar4 + 0x28)) {
                pcVar3 = *(char **)pcVar3;
              }
              iVar9 = __stricmp(pcVar3,"code");
              if (iVar9 == 0) {
                if (iVar4 != 0) {
                  pcVar3 = (char *)(iVar4 + 0x30);
                  if (0xf < *(uint *)(iVar4 + 0x44)) {
                    pcVar3 = *(char **)pcVar3;
                  }
                  goto LAB_005c860d;
                }
                break;
              }
            }
            pcVar3 = (char *)0x0;
LAB_005c860d:
            local_1c = 0xf;
            local_20 = 0;
            local_30[0] = local_30[0] & 0xffffff00;
            pcVar7 = pcVar3;
            do {
              cVar1 = *pcVar7;
              pcVar7 = pcVar7 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(pcVar3,(int)pcVar7 - (int)(pcVar3 + 1));
            local_8._0_1_ = 10;
            FUN_00440130(local_30);
            local_8 = CONCAT31(local_8._1_3_,9);
            if (0xf < local_1c) {
              FUN_0089120c(local_30[0]);
            }
            for (piVar12 = (int *)piVar5[0x10]; piVar12 != (int *)0x0;
                piVar12 = (int *)piVar12[0x10]) {
              piVar5 = piVar12 + 8;
              if (0xf < (uint)piVar12[0xd]) {
                piVar5 = (int *)*piVar5;
              }
              iVar4 = __stricmp((char *)piVar5,"RECT");
              if (iVar4 == 0) goto LAB_005c8699;
            }
            piVar12 = (int *)0x0;
LAB_005c8699:
            local_34 = (undefined2 *)local_1a8;
            local_1c = 7;
            local_20 = 0;
            local_30[0] = local_30[0] & 0xffff0000;
            FUN_004026e0(local_c4,0,0xffffffff);
            local_8 = CONCAT31(local_8._1_3_,0xb);
            uVar10 = FUN_005063f0(&local_34);
            FUN_00480690(local_44,uVar10);
            if (7 < local_1c) {
              FUN_0089120c(local_30[0]);
            }
            local_8._0_1_ = 6;
            piVar5 = piVar12;
            if (7 < local_b0) {
              FUN_0089120c(local_c4[0]);
            }
          }
          for (piVar5 = (int *)local_1ac[0x10]; piVar5 != piVar12; piVar5 = (int *)piVar5[0x10]) {
            piVar11 = piVar5 + 8;
            if (0xf < (uint)piVar5[0xd]) {
              piVar11 = (int *)*piVar11;
            }
            iVar4 = __stricmp((char *)piVar11,"FXUIIMAGESET");
            if (iVar4 == 0) goto LAB_005c8757;
          }
          piVar5 = (int *)0x0;
LAB_005c8757:
          local_12c[0] = local_12c[0] & 0xffff0000;
          local_118 = 7;
          local_1ac = piVar5;
          local_11c = piVar12;
          FUN_004026e0(local_7c,piVar12,0xffffffff);
          local_8._0_1_ = 0xc;
          local_1a8 = (uint *)local_110;
          local_110[0] = 0;
          local_fc = 7;
          local_100 = piVar12;
          FUN_004026e0(local_7c,piVar12,0xffffffff);
          local_8._0_1_ = 0xd;
          local_e0 = 7;
          local_f4 = 0;
          local_e4 = piVar12;
          FUN_004026e0(local_60,piVar12,0xffffffff);
          local_8._0_1_ = 0xe;
          FUN_005ca290(local_d8,local_44);
          local_8._0_1_ = 0xf;
          uVar10 = FUN_005ca030(local_12c);
          FUN_005c9a50(local_8c,local_1e4,uVar10);
          local_8 = CONCAT31(local_8._1_3_,0x10);
          FUN_005c8c10(local_110);
          if (7 < local_118) {
            FUN_0089120c(local_12c[0]);
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_005c8c10(local_7c);
          piVar11 = local_1b0;
        } while (piVar5 != piVar12);
      }
      for (piVar5 = (int *)piVar11[0x10]; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[0x10]) {
        piVar11 = piVar5 + 8;
        if (0xf < (uint)piVar5[0xd]) {
          piVar11 = (int *)*piVar11;
        }
        iVar4 = __stricmp((char *)piVar11,"FXUIIMAGESETGROUP");
        if (iVar4 == 0) goto LAB_005c889d;
      }
      piVar5 = (int *)0x0;
LAB_005c889d:
      local_7c[0] = local_7c[0] & 0xffff0000;
      local_68 = 7;
      local_6c = 0;
      local_1b0 = piVar5;
      FUN_004026e0(local_a8,0,0xffffffff);
      local_8._0_1_ = 0x11;
      local_1a8 = local_60;
      local_60[0] = local_60[0] & 0xffff0000;
      local_4c = 7;
      local_50 = 0;
      FUN_004026e0(local_a8,0,0xffffffff);
      local_8._0_1_ = 0x12;
      FUN_005ca360(local_44,local_8c);
      iVar4 = local_1bc + 0x20;
      local_8._0_1_ = 0x13;
      uVar10 = FUN_005ca120(local_7c);
      FUN_005c9b70(iVar4,local_1f4,uVar10);
      local_1a8 = local_60;
      local_1ac = (int *)local_44;
      local_8 = CONCAT31(local_8._1_3_,0x16);
      FUN_005c8ed0(*local_40,local_40);
      FUN_0089120c(local_40);
      if (7 < local_4c) {
        FUN_0089120c(local_60[0]);
      }
      local_4c = 7;
      local_50 = 0;
      local_60[0] = local_60[0] & 0xffff0000;
      if (7 < local_68) {
        FUN_0089120c(local_7c[0]);
      }
      local_1a8 = (uint *)local_8c;
      local_8 = CONCAT31(local_8._1_3_,0x18);
      FUN_005c8ed0(*local_88,local_88);
      FUN_0089120c(local_88);
      if (7 < local_94) {
        FUN_0089120c(local_a8[0]);
      }
      local_94 = 7;
      local_98 = 0;
      local_a8[0] = local_a8[0] & 0xffff0000;
      piVar11 = local_1b0;
    }
  }
  local_8 = 0xffffffff;
  local_1a4[0] = TiXmlDocument::vftable;
  if (0xf < local_144) {
    FUN_0089120c(local_158,uVar2);
  }
  local_144 = 0xf;
  local_148 = 0;
  local_158 = local_158 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


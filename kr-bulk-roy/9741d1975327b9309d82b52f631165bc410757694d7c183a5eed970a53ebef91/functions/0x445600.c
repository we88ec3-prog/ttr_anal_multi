
void FUN_00445600(void)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  bool bVar12;
  int *piStack_114;
  undefined1 local_10d;
  int local_10c;
  int iStack_108;
  undefined4 uStack_104;
  int *piStack_100;
  undefined4 uStack_fc;
  undefined1 uStack_f8;
  int iStack_f0;
  uint local_e8 [4];
  undefined4 local_d8;
  uint local_d4;
  uint local_cc;
  undefined4 local_bc;
  uint local_b8;
  undefined **local_b0 [19];
  uint local_64;
  undefined4 local_54;
  uint local_50;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00925837;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&piStack_114;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffee0;
  ExceptionList = &local_14;
  FUN_0072ee30(local_b0);
  local_c = 0;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    local_c = 0xffffffff;
    local_b0[0] = TiXmlDocument::vftable;
    if (0xf < local_50) {
      FUN_0089120c(local_64);
    }
  }
  else {
    local_10c = FUN_0072e2e0("CHALLENGELISTTABLE");
    if (local_10c == 0) {
      local_c = 0xffffffff;
      local_b0[0] = TiXmlDocument::vftable;
      if (0xf < local_50) {
        FUN_0089120c(local_64);
      }
    }
    else {
      iVar6 = FUN_0072e2e0("CHALLENGE_TYPE_LIST");
      if (iVar6 != 0) {
        iVar6 = FUN_0072e360(uVar5);
        while (iVar6 != 0) {
          iVar6 = FUN_007300a0(&DAT_00bfb808);
          if (iVar6 == 0) {
LAB_0044575b:
            local_10d = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar6 + 0x30);
            if (0xf < *(uint *)(iVar6 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_0044575b;
            local_10d = FUN_008917b4(puVar7);
          }
          local_d4 = 7;
          local_d8 = 0;
          local_e8[0] = local_e8[0] & 0xffff0000;
          local_c._0_1_ = 1;
          local_b8 = 0xf;
          local_bc = 0;
          local_cc = local_cc & 0xffffff00;
          FUN_00402a70(&DAT_00bed1d4,4);
          local_c._0_1_ = 2;
          uVar8 = FUN_0072ecf0(&DAT_00bf2375);
          local_c = CONCAT31(local_c._1_3_,3);
          FUN_00440130(uVar8);
          if (0xf < local_24) {
            FUN_0089120c(local_38);
          }
          local_c._0_1_ = 1;
          local_24 = 0xf;
          local_28 = 0;
          local_38 = local_38 & 0xffffff00;
          if (0xf < local_b8) {
            FUN_0089120c(local_cc);
          }
          FUN_00445dc0();
          FUN_004026e0(local_e8,0,0xffffffff);
          local_c = (uint)local_c._1_3_ << 8;
          if (7 < local_d4) {
            FUN_0089120c(local_e8[0]);
          }
          iVar6 = FUN_0072e3c0();
        }
      }
      iVar6 = FUN_0072e2e0("CHALLENGE_LIST");
      if (iVar6 != 0) {
        iStack_108 = FUN_0072e360();
        while (iStack_108 != 0) {
          piStack_114 = (int *)FUN_00891268(0x1c);
          if (piStack_114 == (int *)0x0) {
            piStack_114 = (int *)0x0;
          }
          else {
            *piStack_114 = 0;
            piStack_114[1] = 0;
            *(undefined2 *)(piStack_114 + 2) = 0;
            piStack_114[3] = 0;
            piStack_114[4] = 0;
            piStack_114[5] = 0;
          }
          piVar9 = piStack_114;
          piStack_100 = piStack_114;
          iVar6 = FUN_007300a0(&DAT_00bfb82c);
          if (iVar6 == 0) {
LAB_00445905:
            iVar6 = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar6 + 0x30);
            if (0xf < *(uint *)(iVar6 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00445905;
            iVar6 = FUN_008917b4(puVar7);
          }
          *piVar9 = iVar6;
          iVar6 = FUN_0072e360();
          if (iVar6 != 0) {
            iVar6 = FUN_007300a0(&DAT_00bfb808);
            if (iVar6 == 0) {
LAB_0044594a:
              iVar6 = 0;
            }
            else {
              puVar7 = (undefined4 *)(iVar6 + 0x30);
              if (0xf < *(uint *)(iVar6 + 0x44)) {
                puVar7 = (undefined4 *)*puVar7;
              }
              if (puVar7 == (undefined4 *)0x0) goto LAB_0044594a;
              iVar6 = FUN_008917b4(puVar7);
            }
            uVar5 = DAT_00fb9390 & 1;
            piVar9[1] = iVar6;
            if (uVar5 == 0) {
              DAT_00fb9390 = DAT_00fb9390 | 1;
              local_c._0_1_ = 4;
              FUN_0044ad70();
              _atexit((_func_4879 *)&LAB_00bcd610);
              local_c = (uint)local_c._1_3_ << 8;
            }
            iVar6 = *piStack_114;
            FUN_0044af30();
            if ((iStack_f0 == DAT_00fb9398) ||
               (iVar1 = *(int *)(*(int *)(iStack_f0 + 0x10) + 8), local_10c = iVar6,
               piVar9 = (int *)FUN_0044b540(&local_10c), *piVar9 == iVar1)) {
              iVar6 = FUN_007300a0("visible");
              if (iVar6 == 0) {
LAB_00445a07:
                bVar12 = false;
              }
              else {
                pcVar10 = (char *)(iVar6 + 0x30);
                if (0xf < *(uint *)(iVar6 + 0x44)) {
                  pcVar10 = *(char **)pcVar10;
                }
                if (pcVar10 == (char *)0x0) goto LAB_00445a07;
                iVar6 = __stricmp(pcVar10,"true");
                bVar12 = iVar6 == 0;
              }
              *(bool *)(piStack_114 + 2) = bVar12;
            }
            else {
              *(undefined1 *)(piStack_114 + 2) = 0;
            }
            iVar6 = FUN_007300a0(&DAT_00bed1dc);
            if (iVar6 == 0) {
LAB_00445a44:
              bVar12 = false;
            }
            else {
              pcVar10 = (char *)(iVar6 + 0x30);
              if (0xf < *(uint *)(iVar6 + 0x44)) {
                pcVar10 = *(char **)pcVar10;
              }
              if (pcVar10 == (char *)0x0) goto LAB_00445a44;
              iVar6 = __stricmp(pcVar10,"true");
              bVar12 = iVar6 == 0;
            }
            *(bool *)((int)piStack_114 + 9) = bVar12;
          }
          iVar6 = FUN_0072e360();
          if (iVar6 != 0) {
            iVar6 = FUN_0072e360();
            while (local_10c = iVar6, iVar6 != 0) {
              for (iVar1 = *(int *)(iVar6 + 0x94); iVar1 != iVar6 + 0x44;
                  iVar1 = *(int *)(iVar1 + 0x50)) {
                pcVar10 = (char *)(iVar1 + 0x14);
                if (0xf < *(uint *)(iVar1 + 0x28)) {
                  pcVar10 = *(char **)pcVar10;
                }
                iVar11 = __stricmp(pcVar10,"product");
                if (iVar11 == 0) {
                  if (iVar1 != 0) {
                    puVar7 = (undefined4 *)(iVar1 + 0x30);
                    if (0xf < *(uint *)(iVar1 + 0x44)) {
                      puVar7 = (undefined4 *)*puVar7;
                    }
                    if (puVar7 != (undefined4 *)0x0) {
                      uStack_104 = FUN_008917b4(puVar7);
                      goto LAB_00445ac1;
                    }
                  }
                  break;
                }
              }
              uStack_104 = 0;
LAB_00445ac1:
              for (iVar1 = *(int *)(iVar6 + 0x94); iVar1 != iVar6 + 0x44;
                  iVar1 = *(int *)(iVar1 + 0x50)) {
                pcVar10 = (char *)(iVar1 + 0x14);
                if (0xf < *(uint *)(iVar1 + 0x28)) {
                  pcVar10 = *(char **)pcVar10;
                }
                iVar11 = __stricmp(pcVar10,"qty");
                if (iVar11 == 0) {
                  if (iVar1 != 0) {
                    puVar7 = (undefined4 *)(iVar1 + 0x30);
                    if (0xf < *(uint *)(iVar1 + 0x44)) {
                      puVar7 = (undefined4 *)*puVar7;
                    }
                    if (puVar7 != (undefined4 *)0x0) {
                      uVar4 = FUN_008917b4(puVar7);
                      goto LAB_00445af1;
                    }
                  }
                  break;
                }
              }
              uVar4 = 0;
LAB_00445af1:
              piVar9 = piStack_114;
              uStack_fc = uStack_104;
              puVar7 = (undefined4 *)piStack_114[4];
              uStack_f8 = uVar4;
              if (&uStack_fc < puVar7) {
                puVar2 = (undefined4 *)piStack_114[3];
                if (&uStack_fc < puVar2) goto LAB_00445ba2;
                if (puVar7 == (undefined4 *)piStack_114[5]) {
                  FUN_0051dff0();
                }
                puVar7 = (undefined4 *)(piVar9[3] + ((int)&uStack_fc - (int)puVar2 >> 3) * 8);
                puVar2 = (undefined4 *)piVar9[4];
                if (puVar2 != (undefined4 *)0x0) {
                  *puVar2 = *puVar7;
                  *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(puVar7 + 1);
                }
              }
              else {
LAB_00445ba2:
                if (puVar7 == (undefined4 *)piStack_114[5]) {
                  FUN_0051dff0();
                }
                puVar7 = (undefined4 *)piVar9[4];
                if (puVar7 != (undefined4 *)0x0) {
                  *puVar7 = uStack_104;
                  *(undefined1 *)(puVar7 + 1) = uVar4;
                }
              }
              piVar9[4] = piVar9[4] + 8;
              iVar6 = FUN_0072e3c0();
            }
          }
          if ((&piStack_100 < DAT_00fb93d4) && (DAT_00fb93d0 <= &piStack_100)) {
            iVar6 = (int)&piStack_100 - (int)DAT_00fb93d0;
            if (DAT_00fb93d4 == DAT_00fb93d8) {
              FUN_004deab0();
            }
            if (DAT_00fb93d4 != (int **)0x0) {
              *DAT_00fb93d4 = DAT_00fb93d0[iVar6 >> 2];
            }
          }
          else {
            if (DAT_00fb93d4 == DAT_00fb93d8) {
              FUN_004deab0();
            }
            if (DAT_00fb93d4 != (int **)0x0) {
              *DAT_00fb93d4 = piStack_114;
            }
          }
          DAT_00fb93d4 = DAT_00fb93d4 + 1;
          iStack_108 = FUN_0072e3c0();
        }
      }
      FUN_00445cf0();
      local_c = 0xffffffff;
      local_b0[0] = TiXmlDocument::vftable;
      if (0xf < local_50) {
        FUN_0089120c(local_64);
      }
    }
  }
  local_54 = 0;
  local_50 = 0xf;
  local_64 = local_64 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&piStack_114);
  return;
}


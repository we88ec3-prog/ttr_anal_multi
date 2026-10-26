
void FUN_006cd0e0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  char ****ppppcVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char ****ppppcVar13;
  int iStack_17c;
  int iStack_178;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined1 auStack_114 [8];
  char ***apppcStack_10c [4];
  undefined4 uStack_fc;
  uint uStack_f8;
  uint uStack_f0;
  undefined4 uStack_e0;
  uint uStack_dc;
  uint uStack_d4;
  undefined4 uStack_c4;
  uint uStack_c0;
  uint uStack_b8;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009229d5;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_17c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffe78;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 == '\0') {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  else {
    iVar3 = FUN_0072e2e0("JoypadMapping");
    if (((iVar3 != 0) && (piVar4 = (int *)FUN_0072e2e0("DeviceType"), piVar4 != (int *)0x0)) &&
       (iVar3 = (**(code **)(*piVar4 + 0x14))(uVar2), iVar3 != 0)) {
      iStack_174 = (**(code **)(*piVar4 + 0x14))();
      iVar3 = iStack_174;
      while (iVar3 != 0) {
        iStack_168 = FUN_00891268(0x80);
        local_c._0_1_ = 1;
        if (iStack_168 == 0) {
          iStack_178 = 0;
        }
        else {
          iStack_178 = FUN_006ccc00(iStack_168);
        }
        local_c._0_1_ = 0;
        iStack_168 = iStack_178;
        uStack_dc = 0xf;
        uStack_e0 = 0;
        uStack_f0 = uStack_f0 & 0xffffff00;
        FUN_00402a70(&DAT_00bed1d4,4);
        local_c._0_1_ = 2;
        pcVar5 = (char *)FUN_0072ecf0(&DAT_00bf2375);
        local_c = CONCAT31(local_c._1_3_,3);
        if (0xf < *(uint *)(pcVar5 + 0x14)) {
          pcVar5 = *(char **)pcVar5;
        }
        uStack_f8 = 0xf;
        uStack_fc = 0;
        apppcStack_10c[0] = (char ***)((uint)apppcStack_10c[0] & 0xffffff00);
        pcVar6 = pcVar5;
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        FUN_0040b310(pcVar5);
        if (0xf < uStack_c0) {
          FUN_0089120c(uStack_d4);
        }
        uStack_c0 = 0xf;
        uStack_c4 = 0;
        uStack_d4 = uStack_d4 & 0xffffff00;
        local_c = CONCAT31(local_c._1_3_,6);
        if (0xf < uStack_dc) {
          FUN_0089120c(uStack_f0);
        }
        uStack_dc = 0xf;
        uStack_e0 = 0;
        uStack_f0 = uStack_f0 & 0xffffff00;
        ppppcVar13 = (char ****)apppcStack_10c[0];
        if (uStack_f8 < 0x10) {
          ppppcVar13 = apppcStack_10c;
        }
        ppppcVar7 = ppppcVar13;
        do {
          cVar1 = *(char *)ppppcVar7;
          ppppcVar7 = (char ****)((int)ppppcVar7 + 1);
        } while (cVar1 != '\0');
        FUN_00402a70(ppppcVar13,(int)ppppcVar7 - (int)((int)ppppcVar13 + 1));
        iVar3 = FUN_0072e360();
        if (iVar3 != 0) {
          iVar3 = FUN_007300a0("value");
          if (iVar3 == 0) {
LAB_006cd3a3:
            uVar9 = 0;
          }
          else {
            puVar8 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar8 = (undefined4 *)*puVar8;
            }
            if (puVar8 == (undefined4 *)0x0) goto LAB_006cd3a3;
            uVar9 = FUN_008917b4(puVar8);
          }
          *(undefined4 *)(iStack_178 + 0x38) = uVar9;
        }
        iVar3 = FUN_0072e360();
        if (iVar3 != 0) {
          iVar3 = FUN_007300a0("value");
          if (iVar3 == 0) {
LAB_006cd3eb:
            uVar9 = 0;
          }
          else {
            puVar8 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar8 = (undefined4 *)*puVar8;
            }
            if (puVar8 == (undefined4 *)0x0) goto LAB_006cd3eb;
            uVar9 = FUN_008917b4(puVar8);
          }
          *(undefined4 *)(iStack_178 + 0x3c) = uVar9;
        }
        iVar3 = FUN_0072e360();
        if (iVar3 != 0) {
          iVar3 = FUN_0072e360();
          while (iStack_17c = iVar3, iVar3 != 0) {
            for (iVar12 = *(int *)(iVar3 + 0x94); iVar12 != iVar3 + 0x44;
                iVar12 = *(int *)(iVar12 + 0x50)) {
              pcVar5 = (char *)(iVar12 + 0x14);
              if (0xf < *(uint *)(iVar12 + 0x28)) {
                pcVar5 = *(char **)pcVar5;
              }
              iVar10 = __stricmp(pcVar5,"id");
              if (iVar10 == 0) {
                if (iVar12 != 0) {
                  puVar8 = (undefined4 *)(iVar12 + 0x30);
                  if (0xf < *(uint *)(iVar12 + 0x44)) {
                    puVar8 = (undefined4 *)*puVar8;
                  }
                  if (puVar8 != (undefined4 *)0x0) {
                    uVar9 = FUN_008917b4(puVar8);
                    goto LAB_006cd45f;
                  }
                }
                break;
              }
            }
            uVar9 = 0;
LAB_006cd45f:
            for (iVar12 = *(int *)(iVar3 + 0x94); iVar12 != iVar3 + 0x44;
                iVar12 = *(int *)(iVar12 + 0x50)) {
              pcVar5 = (char *)(iVar12 + 0x14);
              if (0xf < *(uint *)(iVar12 + 0x28)) {
                pcVar5 = *(char **)pcVar5;
              }
              iVar10 = __stricmp(pcVar5,"mapping");
              if (iVar10 == 0) {
                if (iVar12 != 0) {
                  puVar8 = (undefined4 *)(iVar12 + 0x30);
                  if (0xf < *(uint *)(iVar12 + 0x44)) {
                    puVar8 = (undefined4 *)*puVar8;
                  }
                  if (puVar8 != (undefined4 *)0x0) {
                    uStack_15c = FUN_008917b4(puVar8);
                    goto LAB_006cd490;
                  }
                }
                break;
              }
            }
            uStack_15c = 0;
LAB_006cd490:
            iVar3 = iStack_178 + 0x40;
            uStack_164 = uVar9;
            uStack_160 = uVar9;
            uVar9 = FUN_00821c50();
            FUN_00517bf0(iVar3,uVar9);
            iVar3 = FUN_0072e3c0();
          }
        }
        iStack_16c = FUN_0072e360();
        if (iStack_16c != 0) {
          iStack_17c = FUN_0072e360();
          if (iStack_17c != 0) {
            iStack_170 = iStack_178 + 0x50;
            do {
              iVar12 = iStack_17c;
              iVar10 = iStack_17c + 0x44;
              for (iVar3 = *(int *)(iStack_17c + 0x94); iVar3 != iVar10;
                  iVar3 = *(int *)(iVar3 + 0x50)) {
                pcVar5 = (char *)(iVar3 + 0x14);
                if (0xf < *(uint *)(iVar3 + 0x28)) {
                  pcVar5 = *(char **)pcVar5;
                }
                iVar11 = __stricmp(pcVar5,"id");
                if (iVar11 == 0) {
                  if (iVar3 != 0) {
                    puVar8 = (undefined4 *)(iVar3 + 0x30);
                    if (0xf < *(uint *)(iVar3 + 0x44)) {
                      puVar8 = (undefined4 *)*puVar8;
                    }
                    if (puVar8 != (undefined4 *)0x0) {
                      uVar9 = FUN_008917b4(puVar8);
                      goto LAB_006cd54f;
                    }
                  }
                  break;
                }
              }
              uVar9 = 0;
LAB_006cd54f:
              for (iVar3 = *(int *)(iVar12 + 0x94); iVar3 != iVar10; iVar3 = *(int *)(iVar3 + 0x50))
              {
                pcVar5 = (char *)(iVar3 + 0x14);
                if (0xf < *(uint *)(iVar3 + 0x28)) {
                  pcVar5 = *(char **)pcVar5;
                }
                iVar12 = __stricmp(pcVar5,"forwarding");
                if (iVar12 == 0) {
                  if (iVar3 != 0) {
                    puVar8 = (undefined4 *)(iVar3 + 0x30);
                    if (0xf < *(uint *)(iVar3 + 0x44)) {
                      puVar8 = (undefined4 *)*puVar8;
                    }
                    if (puVar8 != (undefined4 *)0x0) {
                      uStack_150 = FUN_008917b4(puVar8);
                      goto LAB_006cd580;
                    }
                  }
                  break;
                }
              }
              uStack_150 = 0;
LAB_006cd580:
              iVar3 = iStack_170;
              uStack_158 = uVar9;
              uStack_154 = uVar9;
              uVar9 = FUN_00821c50();
              FUN_00517bf0(iVar3,uVar9);
              iStack_17c = FUN_0072e3c0();
            } while (iStack_17c != 0);
            iStack_17c = 0;
          }
          iVar3 = FUN_0072e360();
          while (iStack_17c = iVar3, iVar3 != 0) {
            for (iVar12 = *(int *)(iVar3 + 0x94); iVar12 != iVar3 + 0x44;
                iVar12 = *(int *)(iVar12 + 0x50)) {
              pcVar5 = (char *)(iVar12 + 0x14);
              if (0xf < *(uint *)(iVar12 + 0x28)) {
                pcVar5 = *(char **)pcVar5;
              }
              iVar10 = __stricmp(pcVar5,"id");
              if (iVar10 == 0) {
                if (iVar12 != 0) {
                  puVar8 = (undefined4 *)(iVar12 + 0x30);
                  if (0xf < *(uint *)(iVar12 + 0x44)) {
                    puVar8 = (undefined4 *)*puVar8;
                  }
                  if (puVar8 != (undefined4 *)0x0) {
                    uVar9 = FUN_008917b4(puVar8);
                    goto LAB_006cd61f;
                  }
                }
                break;
              }
            }
            uVar9 = 0;
LAB_006cd61f:
            for (iVar12 = *(int *)(iVar3 + 0x94); iVar12 != iVar3 + 0x44;
                iVar12 = *(int *)(iVar12 + 0x50)) {
              pcVar5 = (char *)(iVar12 + 0x14);
              if (0xf < *(uint *)(iVar12 + 0x28)) {
                pcVar5 = *(char **)pcVar5;
              }
              iVar10 = __stricmp(pcVar5,"button");
              if (iVar10 == 0) {
                if (iVar12 != 0) {
                  puVar8 = (undefined4 *)(iVar12 + 0x30);
                  if (0xf < *(uint *)(iVar12 + 0x44)) {
                    puVar8 = (undefined4 *)*puVar8;
                  }
                  if (puVar8 != (undefined4 *)0x0) {
                    uStack_138 = FUN_008917b4(puVar8);
                    goto LAB_006cd650;
                  }
                }
                break;
              }
            }
            uStack_138 = 0;
LAB_006cd650:
            iVar3 = iStack_178 + 0x60;
            uStack_140 = uVar9;
            uStack_13c = uVar9;
            uVar9 = FUN_00821c50();
            FUN_00517bf0(iVar3,uVar9);
            iVar3 = FUN_0072e3c0();
          }
          iStack_17c = FUN_0072e360();
          if (iStack_17c != 0) {
            iStack_170 = iStack_178 + 0x70;
            do {
              iVar12 = iStack_17c;
              iVar10 = iStack_17c + 0x44;
              for (iVar3 = *(int *)(iStack_17c + 0x94); iVar3 != iVar10;
                  iVar3 = *(int *)(iVar3 + 0x50)) {
                pcVar5 = (char *)(iVar3 + 0x14);
                if (0xf < *(uint *)(iVar3 + 0x28)) {
                  pcVar5 = *(char **)pcVar5;
                }
                iVar11 = __stricmp(pcVar5,"id");
                if (iVar11 == 0) {
                  if (iVar3 != 0) {
                    puVar8 = (undefined4 *)(iVar3 + 0x30);
                    if (0xf < *(uint *)(iVar3 + 0x44)) {
                      puVar8 = (undefined4 *)*puVar8;
                    }
                    if (puVar8 != (undefined4 *)0x0) {
                      uVar9 = FUN_008917b4(puVar8);
                      goto LAB_006cd6ff;
                    }
                  }
                  break;
                }
              }
              uVar9 = 0;
LAB_006cd6ff:
              for (iVar3 = *(int *)(iVar12 + 0x94); iVar3 != iVar10; iVar3 = *(int *)(iVar3 + 0x50))
              {
                pcVar5 = (char *)(iVar3 + 0x14);
                if (0xf < *(uint *)(iVar3 + 0x28)) {
                  pcVar5 = *(char **)pcVar5;
                }
                iVar12 = __stricmp(pcVar5,"mapping");
                if (iVar12 == 0) {
                  if (iVar3 != 0) {
                    puVar8 = (undefined4 *)(iVar3 + 0x30);
                    if (0xf < *(uint *)(iVar3 + 0x44)) {
                      puVar8 = (undefined4 *)*puVar8;
                    }
                    if (puVar8 != (undefined4 *)0x0) {
                      uStack_144 = FUN_008917b4(puVar8);
                      goto LAB_006cd730;
                    }
                  }
                  break;
                }
              }
              uStack_144 = 0;
LAB_006cd730:
              iVar3 = iStack_170;
              uStack_14c = uVar9;
              uStack_148 = uVar9;
              uVar9 = FUN_00821c50();
              FUN_00517bf0(iVar3,uVar9);
              iStack_17c = FUN_0072e3c0();
            } while (iStack_17c != 0);
          }
        }
        uVar9 = FUN_006cf6b0(apppcStack_10c,&iStack_168);
        local_c._0_1_ = 7;
        uVar9 = FUN_006cfb60(uVar9);
        FUN_006cf820(auStack_114,uVar9);
        local_c._0_1_ = 6;
        if (0xf < uStack_a4) {
          FUN_0089120c(uStack_b8);
        }
        uStack_a4 = 0xf;
        uStack_a8 = 0;
        uStack_b8 = uStack_b8 & 0xffffff00;
        iVar3 = FUN_0072e3c0();
        local_c = (uint)local_c._1_3_ << 8;
        iStack_174 = iVar3;
        if (0xf < uStack_f8) {
          FUN_0089120c(apppcStack_10c[0]);
        }
        uStack_f8 = 0xf;
        uStack_fc = 0;
        apppcStack_10c[0] = (char ***)((uint)apppcStack_10c[0] & 0xffffff00);
      }
    }
    FUN_006edd00("Loaded default Joypad mapping.");
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  local_3c = 0;
  local_38 = 0xf;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_17c);
  return;
}



void FUN_00820540(int param_1)

{
  float *pfVar1;
  undefined4 *puVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  char *pcVar14;
  double dVar15;
  undefined1 local_f0 [4];
  undefined4 *local_ec;
  undefined **local_d8 [4];
  undefined4 local_c8;
  float local_c4;
  undefined4 local_c0;
  undefined1 *local_bc;
  char *local_b8;
  undefined1 local_b4;
  undefined1 local_b0 [4];
  undefined4 *local_ac;
  undefined4 local_a8;
  float local_a0;
  int local_9c;
  float local_98;
  undefined1 local_91;
  undefined **local_90 [6];
  undefined4 *local_78;
  undefined4 local_70;
  uint local_5c;
  char local_4c;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092604a;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_9c = param_1;
  local_18 = uVar4;
  FUN_0072ed80(local_90);
  local_8 = 0;
  FUN_0072f110(0);
  if (local_4c != '\0') {
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
    goto LAB_00820f37;
  }
  local_a0 = (float)FUN_0072e2e0("RAREAVATAR");
  if (local_a0 != 0.0) {
    iVar5 = FUN_0072e360(uVar4);
    if (iVar5 != 0) {
      iVar5 = FUN_0072e360(uVar4);
      while (iVar5 != 0) {
        iVar5 = FUN_007300a0("ProductNo");
        if (iVar5 == 0) {
LAB_0082064d:
          local_98 = 0.0;
        }
        else {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_0082064d;
          local_98 = (float)FUN_008917b4(puVar6);
        }
        FUN_006de9c0();
        iVar5 = FUN_0072e3c0();
      }
    }
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      iVar5 = FUN_0072e360();
      while (iVar5 != 0) {
        iVar5 = FUN_007300a0(&DAT_00c52850);
        if (iVar5 == 0) {
LAB_008206d2:
          local_98 = 0.0;
        }
        else {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_008206d2;
          local_98 = (float)FUN_008917b4(puVar6);
        }
        iVar5 = FUN_007300a0("Leeloo");
        if (iVar5 == 0) {
LAB_00820706:
          uVar7 = 0;
        }
        else {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_00820706;
          uVar7 = FUN_008917b4(puVar6);
        }
        iVar5 = FUN_007300a0("Category");
        if (iVar5 == 0) {
LAB_00820730:
          local_c8 = 0;
        }
        else {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_00820730;
          local_c8 = FUN_008917b4(puVar6);
        }
        iVar5 = local_9c;
        local_c4 = local_98;
        local_c0 = uVar7;
        uVar7 = FUN_00821c50();
        FUN_00517bf0(iVar5,uVar7);
        iVar5 = FUN_0072e3c0();
      }
    }
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      local_98 = (float)FUN_0072e360();
      while (local_98 != 0.0) {
        local_a8 = 0;
        puVar6 = (undefined4 *)FUN_00891268(0x18);
        fVar3 = local_98;
        if (puVar6 == (undefined4 *)0x0) {
          local_b8 = (char *)0x0;
          std::exception::exception((exception *)local_d8,&local_b8);
          local_d8[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_d8,&DAT_00c857a8);
        }
        *puVar6 = puVar6;
        puVar6[1] = puVar6;
        puVar6[2] = puVar6;
        *(undefined1 *)(puVar6 + 5) = 1;
        *(undefined1 *)((int)puVar6 + 0x15) = 1;
        local_8 = CONCAT31(local_8._1_3_,1);
        iVar13 = (int)local_98 + 0x44;
        local_ac = puVar6;
        for (iVar5 = *(int *)((int)local_98 + 0x94); iVar5 != iVar13; iVar5 = *(int *)(iVar5 + 0x50)
            ) {
          pcVar14 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar8 = __stricmp(pcVar14,"Char");
          if (iVar8 == 0) {
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                local_b4 = FUN_008917b4(puVar6);
                goto LAB_0082083d;
              }
            }
            break;
          }
        }
        local_b4 = 0;
LAB_0082083d:
        iVar5 = *(int *)((int)fVar3 + 0x94);
        local_91 = 0x11;
        for (; iVar5 != iVar13; iVar5 = *(int *)(iVar5 + 0x50)) {
          pcVar14 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar8 = __stricmp(pcVar14,"Head");
          if (iVar8 == 0) {
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                uVar7 = FUN_008917b4(puVar6);
                goto LAB_0082087a;
              }
            }
            break;
          }
        }
        uVar7 = 0;
LAB_0082087a:
        puVar6 = (undefined4 *)FUN_00820fd0();
        *puVar6 = uVar7;
        iVar5 = *(int *)((int)fVar3 + 0x94);
        local_91 = 0x12;
        for (; iVar5 != iVar13; iVar5 = *(int *)(iVar5 + 0x50)) {
          pcVar14 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar8 = __stricmp(pcVar14,"Back");
          if (iVar8 == 0) {
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                uVar7 = FUN_008917b4(puVar6);
                goto LAB_008208c9;
              }
            }
            break;
          }
        }
        uVar7 = 0;
LAB_008208c9:
        puVar6 = (undefined4 *)FUN_00820fd0();
        *puVar6 = uVar7;
        iVar5 = *(int *)((int)fVar3 + 0x94);
        local_91 = 0x13;
        for (; iVar5 != iVar13; iVar5 = *(int *)(iVar5 + 0x50)) {
          pcVar14 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar8 = __stricmp(pcVar14,"Waist");
          if (iVar8 == 0) {
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                uVar7 = FUN_008917b4(puVar6);
                goto LAB_00820919;
              }
            }
            break;
          }
        }
        uVar7 = 0;
LAB_00820919:
        puVar6 = (undefined4 *)FUN_00820fd0();
        *puVar6 = uVar7;
        iVar5 = *(int *)((int)fVar3 + 0x94);
        local_91 = 0x20;
        for (; iVar5 != iVar13; iVar5 = *(int *)(iVar5 + 0x50)) {
          pcVar14 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar8 = __stricmp(pcVar14,"FaceMask");
          if (iVar8 == 0) {
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                uVar7 = FUN_008917b4(puVar6);
                goto LAB_00820969;
              }
            }
            break;
          }
        }
        uVar7 = 0;
LAB_00820969:
        puVar6 = (undefined4 *)FUN_00820fd0();
        *puVar6 = uVar7;
        iVar5 = *(int *)((int)fVar3 + 0x94);
        local_91 = 0x24;
        for (; iVar5 != iVar13; iVar5 = *(int *)(iVar5 + 0x50)) {
          pcVar14 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar8 = __stricmp(pcVar14,"Weapon");
          if (iVar8 == 0) {
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                uVar7 = FUN_008917b4(puVar6);
                goto LAB_008209b9;
              }
            }
            break;
          }
        }
        uVar7 = 0;
LAB_008209b9:
        puVar6 = (undefined4 *)FUN_00820fd0();
        *puVar6 = uVar7;
        iVar5 = *(int *)((int)fVar3 + 0x94);
        local_91 = 0x25;
        for (; iVar5 != iVar13; iVar5 = *(int *)(iVar5 + 0x50)) {
          pcVar14 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar8 = __stricmp(pcVar14,"Armor");
          if (iVar8 == 0) {
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                uVar7 = FUN_008917b4(puVar6);
                goto LAB_00820a09;
              }
            }
            break;
          }
        }
        uVar7 = 0;
LAB_00820a09:
        puVar6 = (undefined4 *)FUN_00820fd0();
        *puVar6 = uVar7;
        uVar7 = FUN_00821810();
        iVar5 = local_9c + 0x10;
        local_8._0_1_ = 2;
        uVar7 = FUN_00821c90(uVar7);
        FUN_00821970(iVar5,uVar7);
        local_bc = local_f0;
        local_8._0_1_ = 3;
        FUN_005540c0(*local_ec,local_ec);
        FUN_0089120c(local_ec);
        local_bc = local_b0;
        local_8._0_1_ = 4;
        FUN_005540c0(*local_ac,local_ac);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0089120c(local_ac);
        local_98 = (float)FUN_0072e3c0();
      }
    }
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      for (iVar13 = *(int *)(iVar5 + 0x94); iVar13 != iVar5 + 0x44; iVar13 = *(int *)(iVar13 + 0x50)
          ) {
        pcVar14 = (char *)(iVar13 + 0x14);
        if (0xf < *(uint *)(iVar13 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar8 = __stricmp(pcVar14,"Main");
        if (iVar8 == 0) {
          if (iVar13 != 0) {
            pcVar14 = (char *)(iVar13 + 0x30);
            if (0xf < *(uint *)(iVar13 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar15 = _atof(pcVar14);
              local_98 = (float)dVar15;
              goto LAB_00820b40;
            }
          }
          break;
        }
      }
      local_98 = 0.0;
LAB_00820b40:
      iVar5 = local_9c;
      *(float *)(local_9c + 0x30) = local_98;
      pfVar10 = *(float **)(local_9c + 0x38);
      puVar12 = (uint *)(local_9c + 0x34);
      local_98 = 0.0;
      if (&local_98 < pfVar10) {
        pfVar1 = (float *)*puVar12;
        if (&local_98 < pfVar1) goto LAB_00820d30;
        if (pfVar10 == *(float **)(local_9c + 0x3c)) {
          FUN_0079bf10();
        }
        puVar6 = *(undefined4 **)(iVar5 + 0x38);
        if (puVar6 != (undefined4 *)0x0) {
          uVar7 = *(undefined4 *)(*puVar12 + ((int)&local_98 - (int)pfVar1 >> 2) * 4);
          goto LAB_00820d4a;
        }
      }
      else {
LAB_00820d30:
        if (pfVar10 == *(float **)(local_9c + 0x3c)) {
          FUN_0079bf10();
        }
        puVar6 = *(undefined4 **)(iVar5 + 0x38);
        if (puVar6 != (undefined4 *)0x0) {
          uVar7 = 0;
LAB_00820d4a:
          *puVar6 = uVar7;
        }
      }
      *(int *)(iVar5 + 0x38) = *(int *)(iVar5 + 0x38) + 4;
      local_9c = FUN_0072e360();
      while (local_9c != 0) {
        iVar8 = local_9c + 0x44;
        for (iVar13 = *(int *)(local_9c + 0x94); iVar13 != iVar8; iVar13 = *(int *)(iVar13 + 0x50))
        {
          pcVar14 = (char *)(iVar13 + 0x14);
          if (0xf < *(uint *)(iVar13 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar9 = __stricmp(pcVar14,"Ratio");
          if (iVar9 == 0) {
            if (iVar13 != 0) {
              pcVar14 = (char *)(iVar13 + 0x30);
              if (0xf < *(uint *)(iVar13 + 0x44)) {
                pcVar14 = *(char **)pcVar14;
              }
              if (pcVar14 != (char *)0x0) {
                dVar15 = _atof(pcVar14);
                local_a0 = (float)dVar15;
                goto LAB_00820daf;
              }
            }
            break;
          }
        }
        local_a0 = 0.0;
LAB_00820daf:
        pfVar10 = *(float **)(iVar5 + 0x38);
        local_98 = local_a0;
        if ((&local_98 < pfVar10) && (pfVar1 = (float *)*puVar12, pfVar1 <= &local_98)) {
          if (pfVar10 == *(float **)(iVar5 + 0x3c)) {
            uVar4 = (int)pfVar10 - (int)pfVar1 >> 2;
            if (0x3ffffffe < uVar4) {
LAB_00820f55:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar4 = uVar4 + 1;
            uVar11 = (int)*(float **)(iVar5 + 0x3c) - (int)pfVar1 >> 2;
            if (uVar11 < uVar4) {
              if (0x3fffffff - (uVar11 >> 1) < uVar11) {
                uVar11 = 0;
              }
              else {
                uVar11 = uVar11 + (uVar11 >> 1);
              }
              if (uVar11 < uVar4) {
                uVar11 = uVar4;
              }
              FUN_00797980(uVar11);
            }
          }
          pfVar10 = *(float **)(iVar5 + 0x38);
          if (pfVar10 != (float *)0x0) {
            fVar3 = *(float *)(*puVar12 + ((int)&local_98 - (int)pfVar1 >> 2) * 4);
LAB_00820ea7:
            *pfVar10 = fVar3;
          }
        }
        else {
          if (pfVar10 == *(float **)(iVar5 + 0x3c)) {
            uVar4 = (int)((int)pfVar10 - *puVar12) >> 2;
            if (0x3ffffffe < uVar4) goto LAB_00820f55;
            uVar4 = uVar4 + 1;
            uVar11 = (int)((int)*(float **)(iVar5 + 0x3c) - *puVar12) >> 2;
            if (uVar11 < uVar4) {
              if (0x3fffffff - (uVar11 >> 1) < uVar11) {
                uVar11 = 0;
              }
              else {
                uVar11 = uVar11 + (uVar11 >> 1);
              }
              if (uVar11 < uVar4) {
                uVar11 = uVar4;
              }
              FUN_00797980(uVar11);
            }
          }
          pfVar10 = *(float **)(iVar5 + 0x38);
          fVar3 = local_a0;
          if (pfVar10 != (float *)0x0) goto LAB_00820ea7;
        }
        *(int *)(iVar5 + 0x38) = *(int *)(iVar5 + 0x38) + 4;
        local_9c = FUN_0072e3c0();
      }
    }
  }
  local_90[0] = TiXmlDocument::vftable;
  if (0xf < local_30) {
    FUN_0089120c(local_44);
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = local_44 & 0xffffff00;
  local_90[0] = TiXmlNode::vftable;
  local_8 = 6;
  puVar6 = local_78;
  while (puVar6 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar6;
    puVar6 = (undefined4 *)puVar6[0x10];
    (*(code *)*puVar2)(1);
  }
  if (0xf < local_5c) {
    FUN_0089120c(local_70);
  }
LAB_00820f37:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


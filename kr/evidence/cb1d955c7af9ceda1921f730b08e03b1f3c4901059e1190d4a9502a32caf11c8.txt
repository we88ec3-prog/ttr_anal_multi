
void FUN_00504740(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 ***pppuVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 ***pppuVar10;
  uint uVar11;
  undefined4 ***pppuVar12;
  int *piVar13;
  undefined4 uVar14;
  char *pcVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined4 ****ppppuVar18;
  uint ****ppppuVar19;
  uint uVar20;
  undefined1 auStack_25c [4];
  undefined4 ***pppuStack_258;
  int *local_254;
  undefined4 ***pppuStack_250;
  int *piStack_24c;
  uint ***apppuStack_248 [4];
  undefined4 ***pppuStack_238;
  uint **ppuStack_234;
  undefined4 local_230;
  uint auStack_224 [4];
  undefined4 uStack_214;
  uint uStack_210;
  undefined4 local_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  uint ***pppuStack_1f8;
  uint ***pppuStack_1f4;
  uint ***pppuStack_1f0;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  int iStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 ***pppuStack_174;
  undefined4 ***pppuStack_170;
  undefined4 ***pppuStack_16c;
  uint auStack_15c [4];
  undefined4 uStack_14c;
  uint uStack_148;
  undefined **local_140 [17];
  char local_fc;
  uint local_f4;
  undefined4 local_e4;
  uint local_e0;
  undefined4 uStack_c8;
  undefined1 auStack_c4 [168];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092423d;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_25c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffd98;
  ExceptionList = &local_14;
  local_230 = param_1;
  FUN_0072ee30(local_140);
  local_c = 0;
  FUN_0072f110(0);
  if (local_fc != '\0') {
    local_c = 0xffffffff;
    local_140[0] = TiXmlDocument::vftable;
    if (0xf < local_e0) {
      FUN_0089120c(local_f4,uVar4);
    }
    local_e0 = 0xf;
    local_e4 = 0;
    local_f4 = local_f4 & 0xffffff00;
    FUN_0072e040();
    goto LAB_005054d8;
  }
  iVar5 = FUN_0072e2e0("QuestInfo");
  if (iVar5 == 0) {
    FUN_006edb60(&DAT_00c0db7c);
    local_c = 0xffffffff;
    local_140[0] = TiXmlDocument::vftable;
    if (0xf < local_e0) {
      FUN_0089120c(local_f4,uVar4);
    }
    local_e0 = 0xf;
    local_e4 = 0;
    local_f4 = local_f4 & 0xffffff00;
    FUN_0072e040();
    goto LAB_005054d8;
  }
  local_254 = *(int **)(iVar5 + 0x18);
  if (local_254 != (int *)0x0) {
LAB_005048c0:
    FUN_004ff920(&local_208);
    local_c = CONCAT31(local_c._1_3_,1);
    (**(code **)(*local_254 + 0x14))();
    iVar5 = FUN_007300a0(&DAT_00bed1d0);
    if (iVar5 == 0) {
LAB_0050490c:
      local_208 = 0;
    }
    else {
      puVar6 = (undefined4 *)(iVar5 + 0x30);
      if (0xf < *(uint *)(iVar5 + 0x44)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) goto LAB_0050490c;
      local_208 = FUN_008917b4(puVar6);
    }
    iVar5 = FUN_007300a0(&DAT_00bfb808);
    if (iVar5 == 0) {
LAB_00504939:
      uStack_204 = 0;
    }
    else {
      puVar6 = (undefined4 *)(iVar5 + 0x30);
      if (0xf < *(uint *)(iVar5 + 0x44)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) goto LAB_00504939;
      uStack_204 = FUN_008917b4(puVar6);
    }
    iVar5 = FUN_007300a0("subtype");
    if (iVar5 == 0) {
LAB_00504966:
      uStack_200 = 0;
    }
    else {
      puVar6 = (undefined4 *)(iVar5 + 0x30);
      if (0xf < *(uint *)(iVar5 + 0x44)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) goto LAB_00504966;
      uStack_200 = FUN_008917b4(puVar6);
    }
    iVar5 = FUN_007300a0("level");
    if (iVar5 == 0) {
LAB_00504993:
      uStack_1fc = 0;
    }
    else {
      puVar6 = (undefined4 *)(iVar5 + 0x30);
      if (0xf < *(uint *)(iVar5 + 0x44)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) goto LAB_00504993;
      uStack_1fc = FUN_008917b4(puVar6);
    }
    iVar5 = FUN_007300a0("giver");
    if (iVar5 == 0) {
LAB_005049c0:
      uStack_1e0 = 0;
    }
    else {
      puVar6 = (undefined4 *)(iVar5 + 0x30);
      if (0xf < *(uint *)(iVar5 + 0x44)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) goto LAB_005049c0;
      uStack_1e0 = FUN_008917b4(puVar6);
    }
    iVar5 = FUN_007300a0("finisher");
    if (iVar5 == 0) {
LAB_005049f0:
      uStack_1dc = 0;
    }
    else {
      puVar6 = (undefined4 *)(iVar5 + 0x30);
      if (0xf < *(uint *)(iVar5 + 0x44)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) goto LAB_005049f0;
      uStack_1dc = FUN_008917b4(puVar6);
    }
    iVar5 = FUN_007300a0(&DAT_00c0dbb8);
    if (iVar5 == 0) {
LAB_00504a20:
      uStack_1e8 = 0;
    }
    else {
      puVar6 = (undefined4 *)(iVar5 + 0x30);
      if (0xf < *(uint *)(iVar5 + 0x44)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) goto LAB_00504a20;
      uStack_1e8 = FUN_008917b4(puVar6);
    }
    iVar5 = FUN_007300a0("field");
    if (iVar5 == 0) {
LAB_00504a50:
      uStack_1e4 = 0;
    }
    else {
      puVar6 = (undefined4 *)(iVar5 + 0x30);
      if (0xf < *(uint *)(iVar5 + 0x44)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) goto LAB_00504a50;
      uStack_1e4 = FUN_008917b4(puVar6);
    }
    iVar5 = FUN_007300a0("subject");
    if (iVar5 == 0) {
      pcVar15 = (char *)0x0;
    }
    else {
      pcVar15 = (char *)(iVar5 + 0x30);
      if (0xf < *(uint *)(iVar5 + 0x44)) {
        pcVar15 = *(char **)pcVar15;
      }
    }
    uStack_210 = 0xf;
    uStack_214 = 0;
    auStack_224[0] = auStack_224[0] & 0xffffff00;
    pcVar7 = pcVar15;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar15,(int)pcVar7 - (int)(pcVar15 + 1));
    local_c._0_1_ = 2;
    FUN_00440130(auStack_224);
    local_c = CONCAT31(local_c._1_3_,1);
    if (0xf < uStack_210) {
      FUN_0089120c(auStack_224[0]);
    }
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      iVar5 = FUN_007300a0(&DAT_00bfb808);
      if (iVar5 == 0) {
LAB_00504b19:
        uStack_1cc = 0;
      }
      else {
        puVar6 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 == (undefined4 *)0x0) goto LAB_00504b19;
        uStack_1cc = FUN_008917b4(puVar6);
      }
      iVar5 = FUN_007300a0("param");
      if (iVar5 != 0) {
        puVar6 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 != (undefined4 *)0x0) {
          uStack_1c8 = FUN_008917b4(puVar6);
          goto LAB_00504b52;
        }
      }
      uStack_1c8 = 0;
    }
LAB_00504b52:
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      iVar5 = FUN_007300a0(&DAT_00bfb808);
      if (iVar5 == 0) {
LAB_00504b8c:
        uStack_1c4 = 0;
      }
      else {
        puVar6 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 == (undefined4 *)0x0) goto LAB_00504b8c;
        uStack_1c4 = FUN_008917b4(puVar6);
      }
      iVar5 = FUN_007300a0("param");
      if (iVar5 != 0) {
        puVar6 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 != (undefined4 *)0x0) {
          uStack_1c0 = FUN_008917b4(puVar6);
          goto LAB_00504bc5;
        }
      }
      uStack_1c0 = 0;
    }
LAB_00504bc5:
    iVar5 = FUN_0072e2e0("Demands");
    if (iVar5 != 0) {
      iVar5 = FUN_0072e360();
      while (iVar5 != 0) {
        for (iVar9 = *(int *)(iVar5 + 0x94); iVar9 != iVar5 + 0x44; iVar9 = *(int *)(iVar9 + 0x50))
        {
          pcVar15 = (char *)(iVar9 + 0x14);
          if (0xf < *(uint *)(iVar9 + 0x28)) {
            pcVar15 = *(char **)pcVar15;
          }
          iVar8 = __stricmp(pcVar15,"id");
          if (iVar8 == 0) {
            if (iVar9 != 0) {
              puVar6 = (undefined4 *)(iVar9 + 0x30);
              if (0xf < *(uint *)(iVar9 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                ppppuVar19 = (uint ****)FUN_008917b4(puVar6);
                goto LAB_00504c26;
              }
            }
            break;
          }
        }
        ppppuVar19 = (uint ****)0x0;
LAB_00504c26:
        pppuStack_258 = ppppuVar19;
        if ((&pppuStack_258 < pppuStack_1f4) && (pppuStack_1f8 <= &pppuStack_258)) {
          iVar5 = (int)&pppuStack_258 - (int)pppuStack_1f8;
          if (pppuStack_1f4 == pppuStack_1f0) {
            FUN_006d6240();
          }
          if ((undefined4 ****)pppuStack_1f4 != (undefined4 ****)0x0) {
            *pppuStack_1f4 = pppuStack_1f8[iVar5 >> 2];
          }
        }
        else {
          if (pppuStack_1f4 == pppuStack_1f0) {
            FUN_006d6240();
          }
          if ((undefined4 ****)pppuStack_1f4 != (undefined4 ****)0x0) {
            *pppuStack_1f4 = (uint **)ppppuVar19;
          }
        }
        pppuStack_1f4 = pppuStack_1f4 + 1;
        iVar5 = FUN_0072e3c0();
      }
    }
    for (iVar5 = local_254[6]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x40)) {
      pcVar15 = (char *)(iVar5 + 0x20);
      if (0xf < *(uint *)(iVar5 + 0x34)) {
        pcVar15 = *(char **)pcVar15;
      }
      iVar9 = __stricmp(pcVar15,"RewardsEtc");
      if (iVar9 == 0) {
        if (iVar5 != 0) {
          iVar5 = FUN_0072e360();
          while (piStack_24c = (int *)iVar5, iVar5 != 0) {
            for (iVar9 = *(int *)(iVar5 + 0x94); iVar9 != iVar5 + 0x44;
                iVar9 = *(int *)(iVar9 + 0x50)) {
              pcVar15 = (char *)(iVar9 + 0x14);
              if (0xf < *(uint *)(iVar9 + 0x28)) {
                pcVar15 = *(char **)pcVar15;
              }
              iVar8 = __stricmp(pcVar15,"type");
              if (iVar8 == 0) {
                if (iVar9 != 0) {
                  puVar6 = (undefined4 *)(iVar9 + 0x30);
                  if (0xf < *(uint *)(iVar9 + 0x44)) {
                    puVar6 = (undefined4 *)*puVar6;
                  }
                  if (puVar6 != (undefined4 *)0x0) {
                    uVar17 = FUN_008917b4(puVar6);
                    goto LAB_00504d67;
                  }
                }
                break;
              }
            }
            uVar17 = 0;
LAB_00504d67:
            for (iVar9 = *(int *)(iVar5 + 0x94); iVar9 != iVar5 + 0x44;
                iVar9 = *(int *)(iVar9 + 0x50)) {
              pcVar15 = (char *)(iVar9 + 0x14);
              if (0xf < *(uint *)(iVar9 + 0x28)) {
                pcVar15 = *(char **)pcVar15;
              }
              iVar8 = __stricmp(pcVar15,"value");
              if (iVar8 == 0) {
                if (iVar9 != 0) {
                  puVar6 = (undefined4 *)(iVar9 + 0x30);
                  if (0xf < *(uint *)(iVar9 + 0x44)) {
                    puVar6 = (undefined4 *)*puVar6;
                  }
                  if (puVar6 != (undefined4 *)0x0) {
                    uVar14 = FUN_008917b4(puVar6);
                    goto LAB_00504d96;
                  }
                }
                break;
              }
            }
            uVar14 = 0;
LAB_00504d96:
            switch(uVar17) {
            case 1:
              uStack_188 = uVar14;
              break;
            case 2:
              uStack_180 = uVar14;
              break;
            case 3:
              uStack_184 = uVar14;
              break;
            case 4:
              uStack_18c = uVar14;
              break;
            case 5:
              uStack_17c = uVar14;
              break;
            case 6:
              uStack_178 = uVar14;
            }
            iVar5 = FUN_0072e3c0();
          }
        }
        break;
      }
    }
    for (piVar2 = (int *)local_254[6]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x10]) {
      piVar13 = piVar2 + 8;
      if (0xf < (uint)piVar2[0xd]) {
        piVar13 = (int *)*piVar13;
      }
      iVar5 = __stricmp((char *)piVar13,"RewardsItem");
      if (iVar5 == 0) goto joined_r0x00504e6b;
    }
    piVar2 = (int *)0x0;
joined_r0x00504e6b:
    piStack_24c = piVar2;
    if (piStack_24c != (int *)0x0) {
      (**(code **)(*piStack_24c + 0x14))();
      iStack_190 = iStack_190 + 1;
      ppppuVar18 = (undefined4 ****)0x0;
      apppuStack_248[0] = (uint ***)0x0;
      apppuStack_248[1] = (uint ***)0x0;
      apppuStack_248[2] = (uint ***)0x0;
      local_c = CONCAT31(local_c._1_3_,3);
      pppuVar10 = (undefined4 ***)FUN_0072e360();
      while (pppuStack_258 = pppuVar10, pppuVar10 != (undefined4 ***)0x0) {
        for (pppuVar3 = (undefined4 ***)pppuVar10[0x25]; pppuVar3 != pppuVar10 + 0x11;
            pppuVar3 = (undefined4 ***)pppuVar3[0x14]) {
          pppuVar12 = pppuVar3 + 5;
          if ((undefined4 **)0xf < pppuVar3[10]) {
            pppuVar12 = (undefined4 ***)*pppuVar12;
          }
          iVar5 = __stricmp((char *)pppuVar12,"idx");
          if (iVar5 == 0) {
            if (pppuVar3 != (undefined4 ***)0x0) {
              pppuVar12 = pppuVar3 + 0xc;
              if ((undefined4 **)0xf < pppuVar3[0x11]) {
                pppuVar12 = (undefined4 ***)*pppuVar12;
              }
              if (pppuVar12 != (undefined4 ***)0x0) {
                pppuStack_250 = (undefined4 ***)FUN_008917b4(pppuVar12);
                goto LAB_00504ef4;
              }
            }
            break;
          }
        }
        pppuStack_250 = (uint ****)0x0;
LAB_00504ef4:
        for (pppuVar3 = (undefined4 ***)pppuVar10[0x25]; pppuVar3 != pppuVar10 + 0x11;
            pppuVar3 = (undefined4 ***)pppuVar3[0x14]) {
          pppuVar12 = pppuVar3 + 5;
          if ((undefined4 **)0xf < pppuVar3[10]) {
            pppuVar12 = (undefined4 ***)*pppuVar12;
          }
          iVar5 = __stricmp((char *)pppuVar12,"value");
          if (iVar5 == 0) {
            if (pppuVar3 != (undefined4 ***)0x0) {
              pppuVar10 = pppuVar3 + 0xc;
              if ((undefined4 **)0xf < pppuVar3[0x11]) {
                pppuVar10 = (undefined4 ***)*pppuVar10;
              }
              if (pppuVar10 != (undefined4 ***)0x0) {
                pppuVar10 = (undefined4 ***)FUN_008917b4(pppuVar10);
                goto LAB_00504f2a;
              }
            }
            break;
          }
        }
        pppuVar10 = (undefined4 ***)0x0;
LAB_00504f2a:
        pppuVar3 = pppuStack_250;
        pppuStack_238 = pppuStack_250;
        ppuStack_234 = (uint **)pppuVar10;
        if ((&pppuStack_238 < ppppuVar18) && (apppuStack_248[0] <= &pppuStack_238)) {
          iVar5 = (int)&pppuStack_238 - (int)apppuStack_248[0] >> 3;
          if (ppppuVar18 == (undefined4 ****)apppuStack_248[2]) {
            uVar11 = (int)ppppuVar18 - (int)apppuStack_248[0] >> 3;
            if (0x1ffffffe < uVar11) goto LAB_00505547;
            uVar11 = uVar11 + 1;
            uVar16 = (int)apppuStack_248[2] - (int)apppuStack_248[0] >> 3;
            if (uVar16 < uVar11) {
              if (0x1fffffff - (uVar16 >> 1) < uVar16) {
                uVar16 = 0;
              }
              else {
                uVar16 = uVar16 + (uVar16 >> 1);
              }
              if (uVar16 < uVar11) {
                uVar16 = uVar11;
              }
              FUN_004e7330(uVar16);
              ppppuVar18 = (undefined4 ****)apppuStack_248[1];
            }
          }
          if (ppppuVar18 != (undefined4 ****)0x0) {
            *ppppuVar18 = (undefined4 ***)apppuStack_248[0][iVar5 * 2];
            ppppuVar18[1] = (undefined4 ***)apppuStack_248[0][iVar5 * 2 + 1];
          }
        }
        else {
          if (ppppuVar18 == (undefined4 ****)apppuStack_248[2]) {
            uVar11 = (int)ppppuVar18 - (int)apppuStack_248[0] >> 3;
            if (0x1ffffffe < uVar11) goto LAB_00505547;
            uVar11 = uVar11 + 1;
            uVar16 = (int)apppuStack_248[2] - (int)apppuStack_248[0] >> 3;
            if (uVar16 < uVar11) {
              if (0x1fffffff - (uVar16 >> 1) < uVar16) {
                uVar16 = 0;
              }
              else {
                uVar16 = uVar16 + (uVar16 >> 1);
              }
              if (uVar16 < uVar11) {
                uVar16 = uVar11;
              }
              FUN_004e7330(uVar16);
              ppppuVar18 = (undefined4 ****)apppuStack_248[1];
            }
          }
          if (ppppuVar18 != (undefined4 ****)0x0) {
            *ppppuVar18 = pppuVar3;
            ppppuVar18[1] = pppuVar10;
          }
        }
        ppppuVar18 = ppppuVar18 + 2;
        apppuStack_248[1] = (uint ***)ppppuVar18;
        pppuVar10 = (undefined4 ***)FUN_0072e3c0();
      }
      if ((apppuStack_248 < pppuStack_170) && (pppuStack_174 <= apppuStack_248)) {
        uVar11 = (int)apppuStack_248 - (int)pppuStack_174;
        if (pppuStack_170 == pppuStack_16c) {
          uVar16 = (int)pppuStack_170 - (int)pppuStack_174 >> 4;
          if (0xffffffe < uVar16) {
LAB_00505547:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar16 = uVar16 + 1;
          uVar20 = (int)pppuStack_16c - (int)pppuStack_174 >> 4;
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
            FUN_00655e30(uVar20);
          }
        }
        ppppuVar19 = (uint ****)((uVar11 & 0xfffffff0) + (int)pppuStack_174);
        local_c._0_1_ = 4;
        pppuStack_258 = pppuStack_170;
        pppuStack_250 = pppuStack_170;
        if ((uint ****)pppuStack_170 != (uint ****)0x0) {
LAB_005051a5:
          pppuStack_258 = pppuStack_170;
          pppuStack_250 = pppuStack_170;
          FUN_004fcd00(pppuStack_170,ppppuVar19);
        }
      }
      else {
        if (pppuStack_170 == pppuStack_16c) {
          uVar11 = (int)pppuStack_170 - (int)pppuStack_174 >> 4;
          if (0xffffffe < uVar11) goto LAB_00505547;
          uVar11 = uVar11 + 1;
          uVar16 = (int)pppuStack_16c - (int)pppuStack_174 >> 4;
          if (uVar16 < uVar11) {
            if (0xfffffff - (uVar16 >> 1) < uVar16) {
              uVar16 = 0;
            }
            else {
              uVar16 = uVar16 + (uVar16 >> 1);
            }
            if (uVar16 < uVar11) {
              uVar16 = uVar11;
            }
            FUN_00655e30(uVar16);
          }
        }
        local_c._0_1_ = 5;
        pppuStack_258 = pppuStack_170;
        pppuStack_250 = pppuStack_170;
        if ((uint ****)pppuStack_170 != (uint ****)0x0) {
          ppppuVar19 = apppuStack_248;
          goto LAB_005051a5;
        }
      }
      pppuStack_170 = pppuStack_170 + 4;
      local_c = CONCAT31(local_c._1_3_,1);
      if ((undefined4 ****)apppuStack_248[0] != (undefined4 ****)0x0) {
        FUN_0089120c(apppuStack_248[0]);
      }
      piVar2 = (int *)piStack_24c[0x10];
      apppuStack_248[0] = (uint ***)0x0;
      apppuStack_248[1] = (uint ***)0x0;
      apppuStack_248[2] = (uint ***)0x0;
      for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x10]) {
        piVar13 = piVar2 + 8;
        if (0xf < (uint)piVar2[0xd]) {
          piVar13 = (int *)*piVar13;
        }
        iVar5 = __stricmp((char *)piVar13,"RewardsItem");
        if (iVar5 == 0) goto joined_r0x00504e6b;
      }
      piVar2 = (int *)0x0;
      goto joined_r0x00504e6b;
    }
    piStack_24c = (int *)0x0;
    for (iVar5 = local_254[6]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x40)) {
      pcVar15 = (char *)(iVar5 + 0x20);
      if (0xf < *(uint *)(iVar5 + 0x34)) {
        pcVar15 = *(char **)pcVar15;
      }
      iVar9 = __stricmp(pcVar15,"Contents");
      if (iVar9 == 0) {
        if (iVar5 != 0) {
          piVar2 = *(int **)(iVar5 + 0x18);
          goto joined_r0x0050526d;
        }
        break;
      }
    }
    goto LAB_005053fb;
  }
  goto LAB_0050547e;
joined_r0x0050526d:
  if (piVar2 == (int *)0x0) goto LAB_00505288;
  iVar5 = (**(code **)(*piVar2 + 0x18))();
  if (iVar5 != 0) {
    iVar5 = (**(code **)(*piVar2 + 0x18))();
    goto joined_r0x0050528e;
  }
  piVar2 = (int *)piVar2[0x10];
  goto joined_r0x0050526d;
LAB_00505288:
  iVar5 = 0;
joined_r0x0050528e:
  if (iVar5 != 0) {
    for (iVar9 = *(int *)(iVar5 + 0x94); iVar9 != iVar5 + 0x44; iVar9 = *(int *)(iVar9 + 0x50)) {
      pcVar15 = (char *)(iVar9 + 0x14);
      if (0xf < *(uint *)(iVar9 + 0x28)) {
        pcVar15 = *(char **)pcVar15;
      }
      iVar8 = __stricmp(pcVar15,"id");
      if (iVar8 == 0) {
        if (iVar9 != 0) {
          puVar6 = (undefined4 *)(iVar9 + 0x30);
          if (0xf < *(uint *)(iVar9 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 != (undefined4 *)0x0) {
            iVar9 = FUN_008917b4(puVar6);
            goto LAB_005052ce;
          }
        }
        break;
      }
    }
    iVar9 = 0;
LAB_005052ce:
    pppuStack_250 = (undefined4 ***)(iVar9 + 1000);
    if ((*(int **)(iVar5 + 0x18) != (int *)0x0) &&
       (iVar9 = (**(code **)(**(int **)(iVar5 + 0x18) + 0x30))(), iVar9 != 0)) {
      pcVar15 = (char *)(iVar9 + 0x20);
      if (0xf < *(uint *)(iVar9 + 0x34)) {
        pcVar15 = *(char **)pcVar15;
      }
      if (pcVar15 != (char *)0x0) {
        uStack_148 = 7;
        uStack_14c = 0;
        auStack_15c[0] = auStack_15c[0] & 0xffff0000;
        local_c._0_1_ = 6;
        uStack_214 = 0;
        uStack_210 = 0xf;
        auStack_224[0] = auStack_224[0] & 0xffffff00;
        pcVar7 = pcVar15;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar15,(int)pcVar7 - (int)(pcVar15 + 1));
        local_c._0_1_ = 7;
        FUN_00440130(auStack_224);
        local_c._0_1_ = 6;
        if (0xf < uStack_210) {
          FUN_0089120c(auStack_224[0]);
        }
        FUN_00505870();
        FUN_004026e0(auStack_15c,0,0xffffffff);
        local_c = CONCAT31(local_c._1_3_,1);
        if (7 < uStack_148) {
          FUN_0089120c(auStack_15c[0]);
        }
      }
    }
    for (piVar2 = *(int **)(iVar5 + 0x40); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x10]) {
      iVar5 = (**(code **)(*piVar2 + 0x18))();
      if (iVar5 != 0) {
        iVar5 = (**(code **)(*piVar2 + 0x18))();
        goto joined_r0x0050528e;
      }
    }
    iVar5 = 0;
    goto joined_r0x0050528e;
  }
LAB_005053fb:
  uStack_c8 = local_208;
  FUN_005064d0(auStack_c4);
  uVar17 = local_230;
  local_c._0_1_ = 8;
  uVar14 = FUN_00506310(&uStack_c8);
  FUN_00505f70(uVar17,uVar14);
  local_c._0_1_ = 1;
  FUN_005045c0(auStack_c4);
  local_c = (uint)local_c._1_3_ << 8;
  FUN_005045c0(&local_208);
  local_254 = (int *)local_254[0x10];
  if (local_254 == (int *)0x0) goto code_r0x00505477;
  goto LAB_005048c0;
code_r0x00505477:
  local_254 = (int *)0x0;
LAB_0050547e:
  local_c = 0xffffffff;
  local_140[0] = TiXmlDocument::vftable;
  if (0xf < local_e0) {
    FUN_0089120c(local_f4,uVar4);
  }
  local_e0 = 0xf;
  local_e4 = 0;
  local_f4 = local_f4 & 0xffffff00;
  FUN_0072e040();
LAB_005054d8:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_25c);
  return;
}


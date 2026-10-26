
void FUN_0060f120(int param_1)

{
  char cVar1;
  int *piVar2;
  int **ppiVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 **ppuVar10;
  int *piVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  undefined2 auStack_b0 [6];
  undefined4 uStack_a4;
  undefined4 *puStack_a0;
  undefined ***pppuStack_9c;
  undefined1 auStack_84 [3];
  byte local_81;
  undefined4 *puStack_80;
  int local_7c;
  undefined4 uStack_78;
  int *piStack_74;
  undefined4 *puStack_70;
  int *apiStack_6c [3];
  int iStack_60;
  int iStack_5c;
  undefined4 *puStack_58;
  ushort uStack_54;
  char *pcStack_50;
  undefined4 *puStack_4c;
  undefined4 *puStack_48;
  undefined **appuStack_44 [8];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e536;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  ExceptionList = &local_14;
  local_7c = param_1;
  local_81 = 0;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    pppuStack_9c = (undefined ***)0x60f195;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fba7a4 != (int *)0x0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      pppuStack_9c = (undefined ***)0x60f1ce;
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    iVar6 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar6 != 0) {
      FUN_0040f060();
      iVar6 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      local_81 = *(byte *)(iVar6 + 0x88);
    }
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    pppuStack_9c = (undefined ***)0x60f22e;
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (local_81 < 10) {
    iVar6 = (uint)local_81 * 0x210;
    apiStack_6c[0] = (int *)(iVar6 + DAT_00f94304);
    if ((*(int *)(iVar6 + 0x5c + DAT_00f94304) != 0) && (apiStack_6c[0] != (int *)0x0)) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 3;
        FUN_004e1590();
        pppuStack_9c = (undefined ***)0x60f2a0;
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      if ((*(int *)(iVar6 + 0x5c + DAT_00f94304) == 0) || (iVar6 + DAT_00f94304 == 0)) {
        iVar6 = 0;
      }
      else {
        iVar6 = iVar6 + DAT_00f94304 + 500;
      }
      if (*(short *)(param_1 + 0x162) < 0) {
        cVar5 = *(char *)((uint)(*(char *)(iVar6 + 2) != '\0') + iVar6);
      }
      else {
        cVar5 = (char)*(short *)(param_1 + 0x162);
      }
      piStack_74 = (int *)CONCAT31(piStack_74._1_3_,cVar5);
      if ((DAT_00fab278 & 1) == 0) {
        DAT_00fab278 = DAT_00fab278 | 1;
        local_c = 4;
        FUN_00817da0();
        pppuStack_9c = (undefined ***)0x60f311;
        _atexit((_func_4879 *)&LAB_00bcced0);
        local_c = 0xffffffff;
      }
      pppuStack_9c = (undefined ***)(uint)local_81;
      uStack_54 = (ushort)local_81;
      puStack_a0 = (undefined4 *)0x60f335;
      iStack_60 = FUN_00819220();
      iVar14 = *(int *)(iVar6 + 4);
      uVar7 = 0;
      local_81 = 0;
      if (*(int *)(iVar6 + 8) != iVar14) {
        do {
          if (*(char *)(iVar14 + uVar7) == cVar5) {
            local_81 = 1;
            break;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < (uint)(*(int *)(iVar6 + 8) - iVar14));
      }
      if ((DAT_00fc0dd8 & 1) == 0) {
        DAT_00fc0dd8 = DAT_00fc0dd8 | 1;
        local_c = 5;
        FUN_00484f20();
        pppuStack_9c = (undefined ***)0x60f38b;
        _atexit((_func_4879 *)&LAB_00bcd9f0);
        local_c = 0xffffffff;
      }
      iVar6 = local_7c;
      apiStack_6c[1] = *(int **)(local_7c + 0x15c);
      pppuStack_9c = (undefined ***)0x60f3b6;
      FUN_00835c70();
      if ((puStack_80 == DAT_00fc0de0) ||
         (apiStack_6c[1] = puStack_80 + 4, apiStack_6c[1] == (undefined4 *)0x0)) {
        pppuStack_9c = *(undefined ****)(*(int *)(iVar6 + 400) + 0xcc);
        if (pppuStack_9c != (undefined ***)0x0) {
          puStack_a0 = (undefined4 *)0x60f3e3;
          FUN_00408920();
        }
        pppuStack_9c = (undefined ***)0x60f3ef;
        FUN_00749920();
        piVar15 = *(int **)(iVar6 + 400);
      }
      else {
        if (*(int *)(*(int *)(iVar6 + 400) + 0xcc) != 0) {
          pppuStack_9c = (undefined ***)0x60f410;
          FUN_006438f0();
        }
        piVar15 = *(int **)apiStack_6c[1][1];
        piStack_74 = piVar15;
        if (piVar15 != (int *)apiStack_6c[1][1]) {
          puStack_48 = (undefined4 *)FUN_004d4210();
          do {
            iVar6 = iStack_60;
            puVar8 = (undefined4 *)*puStack_48;
            uVar7 = puStack_48[1] - (int)puVar8 >> 3;
            uVar13 = 0;
            puStack_70 = (undefined4 *)piVar15[3];
            puVar9 = puVar8;
            if (uVar7 != 0) {
              do {
                if ((undefined4 *)*puVar9 == (undefined4 *)piVar15[3]) {
                  cVar5 = (char)*(undefined2 *)(puVar8 + uVar13 * 2 + 1);
                  goto LAB_0060f45f;
                }
                uVar13 = uVar13 + 1;
                puVar9 = puVar9 + 2;
              } while (uVar13 < uVar7);
            }
            cVar5 = '\0';
LAB_0060f45f:
            uStack_78 = CONCAT31(uStack_78._1_3_,cVar5);
            if ((DAT_00fb11a8 & 1) == 0) {
              DAT_00fb11a8 = DAT_00fb11a8 | 1;
              local_c = 6;
              FUN_00813890();
              pppuStack_9c = (undefined ***)0x60f491;
              _atexit((_func_4879 *)&LAB_00bccec0);
              local_c = 0xffffffff;
            }
            cVar1 = *(char *)((int)DAT_00fb11b0[1] + 0x15);
            puVar8 = (undefined4 *)DAT_00fb11b0[1];
            puStack_80 = DAT_00fb11b0;
            while (puVar9 = puVar8, cVar1 == '\0') {
              if ((undefined4 *)puVar9[3] < puStack_70) {
                puVar8 = (undefined4 *)puVar9[2];
                puVar9 = puStack_80;
              }
              else {
                puVar8 = (undefined4 *)*puVar9;
              }
              cVar1 = *(char *)((int)puVar8 + 0x15);
              puStack_80 = puVar9;
            }
            if ((puStack_80 == DAT_00fb11b0) || (puStack_70 < (undefined4 *)puStack_80[3])) {
              puStack_58 = DAT_00fb11b0;
              ppuVar10 = &puStack_58;
            }
            else {
              ppuVar10 = &puStack_80;
            }
            if (*ppuVar10 == DAT_00fb11b0) {
              iVar14 = 0;
            }
            else {
              iVar14 = (*ppuVar10)[4];
            }
            if (*(ushort *)(iVar14 + 0x10) == uStack_54) {
              if ((((iVar6 != 0) && (cVar5 == '\0')) && (local_81 != 0)) &&
                 (iVar14 = *(int *)(iVar6 + 0x6c) - *(int *)(iVar6 + 0x68) >> 3, iVar14 != 0)) {
                puVar8 = *(undefined4 **)(iVar6 + 0x68);
                do {
                  if ((undefined4 *)*puVar8 == puStack_70) {
                    uStack_78 = CONCAT31(uStack_78._1_3_,*(undefined1 *)(puVar8 + 1));
                  }
                  puVar8 = puVar8 + 2;
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
              }
              if (*(char *)(local_7c + 0x1ed) == '\0') {
                if ((byte)uStack_78 != '\0') {
                  *(undefined1 *)(local_7c + 0x1ed) = 1;
                  goto LAB_0060f560;
                }
LAB_0060f730:
                if ((DAT_00fab100 & 1) == 0) {
                  DAT_00fab100 = DAT_00fab100 | 1;
                  local_c = 7;
                  FUN_0049d6a0();
                  pppuStack_9c = (undefined ***)0x60f75a;
                  _atexit((_func_4879 *)&LAB_00bcce20);
                  local_c = 0xffffffff;
                }
              }
              else {
LAB_0060f560:
                if (((byte)uStack_78 == '\0') || (*(char *)(local_7c + 0x1ec) == '\0'))
                goto LAB_0060f730;
                if ((DAT_00fc0dc4 & 1) == 0) {
                  DAT_00fc0dc4 = DAT_00fc0dc4 | 1;
                  local_c = 8;
                  DAT_00fc0dd0 = 0;
                  pppuStack_9c = (undefined ***)0x60f5a2;
                  iVar6 = FUN_00891268();
                  if (iVar6 == 0) {
                    pcStack_50 = (char *)0x0;
                    pppuStack_9c = (undefined ***)0x60f9ab;
                    std::exception::exception((exception *)appuStack_44,&pcStack_50);
                    pppuStack_9c = appuStack_44;
                    appuStack_44[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                    puStack_a0 = (undefined4 *)&UNK_0060f9c2;
                    __CxxThrowException_8();
                  }
                  DAT_00fc0dcc = iVar6;
                  *(int *)iVar6 = iVar6;
                  *(int *)(DAT_00fc0dcc + 4) = DAT_00fc0dcc;
                  *(int *)(DAT_00fc0dcc + 8) = DAT_00fc0dcc;
                  *(undefined1 *)(DAT_00fc0dcc + 0x5c) = 1;
                  *(undefined1 *)(DAT_00fc0dcc + 0x5d) = 1;
                  pppuStack_9c = (undefined ***)0x60f5e1;
                  _atexit(FUN_00bcd980);
                  local_c = 0xffffffff;
                }
                puStack_80 = puStack_70;
                pppuStack_9c = (undefined ***)0x60f60a;
                FUN_0052a340();
                iVar6 = iStack_5c;
                if ((iStack_5c != DAT_00fc0dcc) && (iStack_5c != -0x10)) {
                  apiStack_6c[2] = (int *)auStack_b0;
                  pppuStack_9c = (undefined ***)0x7;
                  puStack_a0 = (undefined4 *)0x0;
                  auStack_b0[0] = 0;
                  FUN_004026e0(iStack_5c + 0x14,0,0xffffffff);
                  bVar4 = (byte)uStack_78;
                  puStack_a0 = (undefined4 *)FUN_0043b280(L"<#FFC000>{0} Lv.{1}</#>");
                  pppuStack_9c = (undefined ***)0x0;
                  local_c = 9;
                  uStack_a4 = 0x60f683;
                  FUN_004041f0();
                  local_c = 0xffffffff;
                  if (7 < uStack_24) {
                    pppuStack_9c = (undefined ***)0x60f69f;
                    FUN_0089120c();
                  }
                  pppuStack_9c = (undefined ***)&DAT_00bfb894;
                  puStack_a0 = (undefined4 *)0x60f6ae;
                  FUN_00404300();
                  pppuStack_9c = (undefined ***)0x0;
                  puStack_a0 = (undefined4 *)(iVar6 + 0x30);
                  uStack_a4 = 0x60f6bd;
                  FUN_004041f0();
                  pppuStack_9c = (undefined ***)&DAT_00bfb894;
                  puStack_a0 = (undefined4 *)0x60f6c9;
                  FUN_00404300();
                  puVar8 = (undefined4 *)(*(undefined4 **)(iVar6 + 0x50))[1];
                  cVar5 = *(char *)((int)puVar8 + 0x31);
                  puStack_80 = *(undefined4 **)(iVar6 + 0x50);
                  while (cVar5 == '\0') {
                    if (*(byte *)(puVar8 + 3) < bVar4) {
                      puVar9 = (undefined4 *)puVar8[2];
                      puVar8 = puStack_80;
                    }
                    else {
                      puVar9 = (undefined4 *)*puVar8;
                    }
                    puStack_80 = puVar8;
                    puVar8 = puVar9;
                    cVar5 = *(char *)((int)puVar9 + 0x31);
                  }
                  if ((puStack_80 == *(undefined4 **)(iVar6 + 0x50)) ||
                     (bVar4 < *(byte *)(puStack_80 + 3))) {
                    puStack_4c = *(undefined4 **)(iVar6 + 0x50);
                    ppuVar10 = &puStack_4c;
                  }
                  else {
                    ppuVar10 = &puStack_80;
                  }
                  puVar8 = *ppuVar10;
                  if ((puVar8 != *(undefined4 **)(iVar6 + 0x50)) &&
                     (puVar8 != (undefined4 *)0xfffffff0)) {
                    pppuStack_9c = (undefined ***)0x0;
                    puStack_a0 = puVar8 + 5;
                    uStack_a4 = 0x60f722;
                    FUN_004041f0();
                    pppuStack_9c = (undefined ***)&DAT_00bfb894;
                    puStack_a0 = (undefined4 *)0x60f72e;
                    FUN_00404300();
                  }
                }
              }
              piVar15 = *(int **)(*(int *)(local_7c + 400) + 0xcc);
              if (piVar15 == (int *)0x0) {
                piVar11 = (int *)0x0;
              }
              else {
                piVar2 = (int *)piVar15[0x29];
                puStack_80 = (undefined4 *)piVar15[0x39];
                if (piVar2 == (int *)0x0) {
                  piVar11 = (int *)0x0;
                }
                else {
                  if (piVar15[0x2e] == piVar15[0x2f]) {
                    piVar11 = (int *)(**(code **)(*piVar2 + 0x28))();
                  }
                  else {
                    piVar11 = *(int **)(piVar15[0x2f] + -4);
                    pppuStack_9c = (undefined ***)0x60f7c2;
                    (**(code **)(*piVar2 + 0x2c))();
                    if (piVar15[0x2e] != piVar15[0x2f]) {
                      piVar15[0x2f] = piVar15[0x2f] + -4;
                    }
                  }
                  piVar11[8] = (int)puStack_80;
                  pppuStack_9c = (undefined ***)0x60f7ee;
                  apiStack_6c[0] = piVar11;
                  (**(code **)(*piVar15 + 0x70))();
                  ppiVar3 = (int **)piVar15[0x2b];
                  if (apiStack_6c < ppiVar3) {
                    if (apiStack_6c < (int **)piVar15[0x2a]) goto LAB_0060f841;
                    apiStack_6c[2] = (int *)((int)apiStack_6c - piVar15[0x2a] >> 2);
                    if (ppiVar3 == (int **)piVar15[0x2c]) {
                      FUN_004deab0();
                    }
                    if ((undefined4 *)piVar15[0x2b] != (undefined4 *)0x0) {
                      *(undefined4 *)piVar15[0x2b] =
                           *(undefined4 *)(piVar15[0x2a] + (int)apiStack_6c[2] * 4);
                    }
                  }
                  else {
LAB_0060f841:
                    if (ppiVar3 == (int **)piVar15[0x2c]) {
                      FUN_004deab0();
                    }
                    if ((undefined4 *)piVar15[0x2b] != (undefined4 *)0x0) {
                      *(undefined4 *)piVar15[0x2b] = piVar11;
                    }
                  }
                  piVar15[0x2b] = piVar15[0x2b] + 4;
                  puVar12 = (undefined *)((int)puStack_80 + 1);
                  if ((undefined *)((int)puStack_80 + 1) <= (undefined *)piVar15[0x39]) {
                    puVar12 = (undefined *)piVar15[0x39];
                  }
                  piVar15[0x39] = (int)puVar12;
                }
              }
              puVar8 = puStack_70;
              puStack_a0 = (undefined4 *)0x60f899;
              pppuStack_9c = (undefined ***)piVar11;
              FUN_0060d340();
              pppuStack_9c = (undefined ***)0x60f8ae;
              (**(code **)(*piVar11 + 0x90))();
              pppuStack_9c = (undefined ***)0x60f8ba;
              (**(code **)(*piVar11 + 200))();
              pppuStack_9c = (undefined ***)puVar8;
              puStack_a0 = (undefined4 *)local_7c;
              uStack_a4 = 0x60f8c8;
              FUN_0060fa30();
              piVar15 = piStack_74;
            }
            if (*(char *)((int)piVar15 + 0x11) == '\0') {
              piVar11 = (int *)piVar15[2];
              if (*(char *)((int)piVar11 + 0x11) == '\0') {
                cVar5 = *(char *)(*piVar11 + 0x11);
                piVar15 = piVar11;
                piVar11 = (int *)*piVar11;
                while (cVar5 == '\0') {
                  cVar5 = *(char *)(*piVar11 + 0x11);
                  piVar15 = piVar11;
                  piVar11 = (int *)*piVar11;
                }
              }
              else {
                cVar5 = *(char *)(piVar15[1] + 0x11);
                piVar2 = (int *)piVar15[1];
                piVar11 = piVar15;
                while ((piVar15 = piVar2, cVar5 == '\0' && (piVar11 == (int *)piVar15[2]))) {
                  cVar5 = *(char *)(piVar15[1] + 0x11);
                  piVar2 = (int *)piVar15[1];
                  piVar11 = piVar15;
                }
              }
              piStack_74 = piVar15;
            }
          } while (piVar15 != (int *)apiStack_6c[1][1]);
        }
        piVar15 = *(int **)(local_7c + 400);
        puVar8 = (undefined4 *)piVar15[0x19];
        for (puVar9 = (undefined4 *)*puVar8; puVar9 != puVar8; puVar9 = (undefined4 *)*puVar9) {
          if ((*(int *)(puVar9[2] + 0x60) != 0) &&
             (piVar11 = *(int **)(puVar9[2] + 0x1c), piVar11[2] != 6)) {
            pppuStack_9c = (undefined ***)0x60f950;
            (**(code **)(*piVar11 + 0x30))();
          }
        }
        (**(code **)(*piVar15 + 0x128))();
        piVar15 = *(int **)(local_7c + 400);
      }
      (**(code **)(*piVar15 + 200))();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}


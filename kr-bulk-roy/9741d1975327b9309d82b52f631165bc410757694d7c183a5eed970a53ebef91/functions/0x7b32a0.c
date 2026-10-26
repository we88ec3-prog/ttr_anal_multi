
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_007b32a0(int param_1)

{
  char cVar1;
  undefined4 **ppuVar2;
  undefined4 **ppuVar3;
  uint **ppuVar4;
  uint **ppuVar5;
  int iVar6;
  int *piVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 unaff_EBX;
  int *unaff_ESI;
  uint *puVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  int *piVar17;
  undefined4 *puStack_7c;
  uint *apuStack_78 [2];
  uint uStack_70;
  uint *local_6c;
  int iStack_68;
  int *piStack_64;
  undefined1 auStack_60 [4];
  int *local_5c;
  uint *local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined **ppuStack_40;
  undefined4 *puStack_3c;
  int *piStack_38;
  undefined1 auStack_34 [4];
  int iStack_30;
  void *pvStack_2c;
  undefined4 uStack_24;
  void *pvStack_20;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093249a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff78);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  puVar8 = DAT_00fb76a8;
  local_c = 0xffffffff;
  local_58 = DAT_00fb76a8;
  (**(code **)(*DAT_00fb76a8 + 0x7c))(&local_6c,"Material/Char_Skin.obj");
  iVar6 = (**(code **)(*puVar8 + 0x104))(apuStack_78 + 1);
  if (iVar6 == 0) {
    ExceptionList = pvStack_20;
    return 0;
  }
  piVar7 = *(int **)(param_1 + 0x10);
  local_6c = (uint *)(param_1 + 0xa8);
  local_5c = piVar7;
  FUN_00523e40(local_6c);
  pvStack_2c = (void *)0x0;
  iStack_30 = FUN_00891268(0x24);
  if (iStack_30 == 0) {
    local_58 = (uint *)0x0;
    std::exception::exception((exception *)&ppuStack_40,(char **)&local_58);
    ppuStack_40 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&ppuStack_40,&DAT_00c857a8);
  }
  *(int *)iStack_30 = iStack_30;
  *(int *)(iStack_30 + 4) = iStack_30;
  *(int *)(iStack_30 + 8) = iStack_30;
  *(undefined1 *)(iStack_30 + 0x20) = 1;
  *(undefined1 *)(iStack_30 + 0x21) = 1;
  uStack_18 = 2;
  FUN_007c7f90(piVar7,auStack_34);
  (**(code **)(*puVar8 + 0xa0))(auStack_60,"2s_alphatest");
  piVar13 = (int *)*piStack_38;
  if (piVar13 != piStack_38) {
    do {
      puVar8 = local_6c;
      iVar6 = piVar13[3];
      if (iStack_68 == *(int *)(iVar6 + 0x164)) {
        piVar7 = (int *)(**(code **)(*local_6c + 0xcc))(unaff_EBX);
        puVar8 = (uint *)(**(code **)(*puVar8 + 0xcc))(unaff_ESI);
        if (piVar7 != (int *)0x0) {
          piVar7[1] = piVar7[1] + 1;
        }
        if (puVar8 != (uint *)0x0) {
          puVar8[1] = puVar8[1] + 1;
        }
        pvStack_20 = (void *)CONCAT31(pvStack_20._1_3_,4);
        apuStack_78[0] = (uint *)0x1;
        local_5c = piVar7;
        local_58 = puVar8;
        FUN_00855a30(apuStack_78);
        apuStack_78[0] = (uint *)0x0;
        FUN_00855a30(apuStack_78);
        iVar14 = 0;
        if (0 < *(int *)(iVar6 + 0x178)) {
          do {
            piVar7 = (int *)FUN_00843ef0();
            (**(code **)(*piVar7 + 0xc))();
            FUN_00843fa0(unaff_ESI,2);
            FUN_00843fa0(puVar8,2);
            iVar14 = iVar14 + 1;
          } while (iVar14 < *(int *)(iVar6 + 0x178));
        }
        uStack_50 = *(undefined4 *)(iVar6 + 0x1b0);
        uStack_4c = *(undefined4 *)(iVar6 + 0x1b4);
        uStack_54 = *(undefined4 *)(iVar6 + 0x1ac);
        FUN_00855110();
        FUN_00855110();
        iVar6 = piVar13[4];
        uVar15 = 0;
        iVar14 = 0;
        apuStack_78[0] = (uint *)0x0;
        if (piVar13[5] - iVar6 >> 2 != 0) {
          do {
            piVar7 = *(int **)(iVar6 + uVar15 * 4);
            iVar6 = (**(code **)(*piVar7 + 4))();
            if (*(int *)(iVar6 + 4) == -0x5edc0000) {
              puVar9 = (undefined4 *)piVar7[0x1d];
              if (piVar7[0x1f] == piVar7[0x20]) {
                if (puVar9 != (undefined4 *)0x0) {
                  piVar17 = puVar9 + 1;
                  *piVar17 = *piVar17 + -1;
                  if (*piVar17 == 0) {
                    (**(code **)*puVar9)(1);
                  }
                }
                piVar7[0x1d] = (int)puVar8;
                if (puVar8 != (uint *)0x0) {
                  iVar6 = (**(code **)(*puVar8 + 8))();
                  if (iVar6 == 0) {
                    iVar6 = (**(code **)(*(int *)piVar7[0x1d] + 0xc))();
                    piVar7[0x1d] = iVar6;
                  }
                  *(int *)(piVar7[0x1d] + 4) = *(int *)(piVar7[0x1d] + 4) + 1;
                }
                apuStack_78[0] = (uint *)((int)apuStack_78[0] + 1);
              }
              else {
                if (puVar9 != (undefined4 *)0x0) {
                  piVar17 = puVar9 + 1;
                  *piVar17 = *piVar17 + -1;
                  if (*piVar17 == 0) {
                    (**(code **)*puVar9)(1);
                  }
                }
                piVar7[0x1d] = (int)unaff_ESI;
                if (unaff_ESI != (int *)0x0) {
                  iVar6 = (**(code **)(*unaff_ESI + 8))();
                  if (iVar6 == 0) {
                    iVar6 = (**(code **)(*(int *)piVar7[0x1d] + 0xc))();
                    piVar7[0x1d] = iVar6;
                  }
                  *(int *)(piVar7[0x1d] + 4) = *(int *)(piVar7[0x1d] + 4) + 1;
                }
                iVar14 = iVar14 + 1;
              }
            }
            iVar6 = piVar13[4];
            uVar15 = uVar15 + 1;
          } while (uVar15 < (uint)(piVar13[5] - iVar6 >> 2));
          puVar12 = apuStack_78[1];
          if (iVar14 != 0) {
            puVar9 = (undefined4 *)FUN_00891268(0x24);
            puVar12 = apuStack_78[1];
            if (puVar9 == (undefined4 *)0x0) {
              puVar9 = (undefined4 *)0x0;
            }
            else {
              *puVar9 = IS3D::CMaterial::vftable;
              puVar9[1] = uStack_70;
              puVar9[2] = unaff_ESI;
              if (unaff_ESI != (int *)0x0) {
                unaff_ESI[1] = unaff_ESI[1] + 1;
              }
              *puVar9 = IS3DIMP::CCellShaderMaterial::vftable;
              puVar9[6] = 0;
              puVar9[7] = 0;
              puVar9[8] = 0;
            }
            ppuVar2 = (undefined4 **)apuStack_78[1][1];
            puStack_7c = puVar9;
            if ((&puStack_7c < ppuVar2) &&
               (ppuVar3 = (undefined4 **)*apuStack_78[1], ppuVar3 <= &puStack_7c)) {
              if (ppuVar2 == (undefined4 **)apuStack_78[1][2]) {
                uVar15 = (int)ppuVar2 - (int)ppuVar3 >> 2;
                if (0x3ffffffe < uVar15) goto LAB_007b3995;
                uVar15 = uVar15 + 1;
                uVar11 = (int)apuStack_78[1][2] - (int)ppuVar3 >> 2;
                if (uVar11 < uVar15) {
                  if (0x3fffffff - (uVar11 >> 1) < uVar11) {
                    uVar11 = 0;
                  }
                  else {
                    uVar11 = uVar11 + (uVar11 >> 1);
                  }
                  if (uVar11 < uVar15) {
                    uVar11 = uVar15;
                  }
                  FUN_00797980(uVar11);
                }
              }
              if ((undefined4 *)puVar12[1] != (undefined4 *)0x0) {
                *(undefined4 *)puVar12[1] =
                     *(undefined4 *)(*puVar12 + ((int)&puStack_7c - (int)ppuVar3 >> 2) * 4);
              }
              puVar12[1] = puVar12[1] + 4;
            }
            else {
              if (ppuVar2 == (undefined4 **)apuStack_78[1][2]) {
                uVar15 = (int)((int)ppuVar2 - *apuStack_78[1]) >> 2;
                if (0x3ffffffe < uVar15) goto LAB_007b3995;
                uVar15 = uVar15 + 1;
                uVar11 = (int)((int)apuStack_78[1][2] - *apuStack_78[1]) >> 2;
                if (uVar11 < uVar15) {
                  if (0x3fffffff - (uVar11 >> 1) < uVar11) {
                    uVar11 = 0;
                  }
                  else {
                    uVar11 = uVar11 + (uVar11 >> 1);
                  }
                  if (uVar11 < uVar15) {
                    uVar11 = uVar15;
                  }
                  FUN_00797980(uVar11);
                }
              }
              if ((undefined4 *)puVar12[1] != (undefined4 *)0x0) {
                *(undefined4 *)puVar12[1] = puVar9;
              }
              puVar12[1] = puVar12[1] + 4;
            }
          }
          if (apuStack_78[0] != (uint *)0x0) {
            puVar10 = (uint *)FUN_00891268(0x24);
            if (puVar10 == (uint *)0x0) {
              puVar10 = (uint *)0x0;
            }
            else {
              *puVar10 = (uint)IS3D::CMaterial::vftable;
              puVar10[1] = uStack_70;
              puVar10[2] = (uint)puVar8;
              if (puVar8 != (uint *)0x0) {
                puVar8[1] = puVar8[1] + 1;
              }
              *puVar10 = (uint)IS3DIMP::CCellShaderMaterial::vftable;
              puVar10[6] = 0;
              puVar10[7] = 0;
              puVar10[8] = 0;
            }
            ppuVar4 = (uint **)puVar12[1];
            apuStack_78[0] = puVar10;
            if ((apuStack_78 < ppuVar4) && (ppuVar5 = (uint **)*puVar12, ppuVar5 <= apuStack_78)) {
              if (ppuVar4 == (uint **)puVar12[2]) {
                uVar15 = (int)ppuVar4 - (int)ppuVar5 >> 2;
                if (0x3ffffffe < uVar15) {
LAB_007b3995:
                    /* WARNING: Subroutine does not return */
                  FUN_0087db30("vector<T> too long");
                }
                uVar15 = uVar15 + 1;
                uVar11 = (int)puVar12[2] - (int)ppuVar5 >> 2;
                if (uVar11 < uVar15) {
                  if (0x3fffffff - (uVar11 >> 1) < uVar11) {
                    uVar11 = 0;
                  }
                  else {
                    uVar11 = uVar11 + (uVar11 >> 1);
                  }
                  if (uVar11 < uVar15) {
                    uVar11 = uVar15;
                  }
                  FUN_00797980(uVar11);
                }
              }
              if ((undefined4 *)puVar12[1] != (undefined4 *)0x0) {
                *(undefined4 *)puVar12[1] =
                     *(undefined4 *)(*puVar12 + ((int)apuStack_78 - (int)ppuVar5 >> 2) * 4);
              }
            }
            else {
              if (ppuVar4 == (uint **)puVar12[2]) {
                uVar15 = (int)((int)ppuVar4 - *puVar12) >> 2;
                if (0x3ffffffe < uVar15) goto LAB_007b3995;
                uVar15 = uVar15 + 1;
                uVar11 = (int)((int)puVar12[2] - *puVar12) >> 2;
                if (uVar11 < uVar15) {
                  if (0x3fffffff - (uVar11 >> 1) < uVar11) {
                    uVar11 = 0;
                  }
                  else {
                    uVar11 = uVar11 + (uVar11 >> 1);
                  }
                  if (uVar11 < uVar15) {
                    uVar11 = uVar15;
                  }
                  FUN_00797980(uVar11);
                }
              }
              if ((int *)puVar12[1] != (int *)0x0) {
                *(int *)puVar12[1] = (int)puVar10;
              }
            }
            puVar12[1] = puVar12[1] + 4;
          }
        }
        if (*(char *)((int)piVar13 + 0x21) == '\0') {
          piVar7 = (int *)piVar13[2];
          if (*(char *)((int)piVar7 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar7 + 0x21);
            piVar13 = piVar7;
            piVar7 = (int *)*piVar7;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar7 + 0x21);
              piVar13 = piVar7;
              piVar7 = (int *)*piVar7;
            }
          }
          else {
            cVar1 = *(char *)(piVar13[1] + 0x21);
            piVar17 = (int *)piVar13[1];
            piVar7 = piVar13;
            while ((piVar13 = piVar17, cVar1 == '\0' && (piVar7 == (int *)piVar13[2]))) {
              cVar1 = *(char *)(piVar13[1] + 0x21);
              piVar17 = (int *)piVar13[1];
              piVar7 = piVar13;
            }
          }
        }
        pvStack_20._0_1_ = 3;
        piVar17 = piVar13;
        if (puVar8 != (uint *)0x0) {
          puVar12 = puVar8 + 1;
          *puVar12 = *puVar12 - 1;
          if (*puVar12 == 0) {
            (**(code **)*puVar8)(1);
          }
        }
        pvStack_20 = (void *)CONCAT31(pvStack_20._1_3_,2);
        if (unaff_ESI != (int *)0x0) {
          piVar7 = unaff_ESI + 1;
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)*unaff_ESI)(1);
          }
        }
      }
      else {
        FUN_0085e240();
        piVar17 = piVar13;
      }
      bVar16 = piVar13 != piStack_38;
      piVar7 = piStack_64;
      puVar8 = local_6c;
      piVar13 = piVar17;
    } while (bVar16);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    pvStack_20._0_1_ = 5;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    pvStack_20 = (void *)CONCAT31(pvStack_20._1_3_,2);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
  (**(code **)(*piVar7 + 0x58))(puVar8);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    uStack_24 = CONCAT31(uStack_24._1_3_,6);
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
  uStack_24 = 7;
  FUN_0085e680(*puStack_3c,puStack_3c);
  FUN_0089120c(puStack_3c);
  ExceptionList = pvStack_2c;
  return 1;
}


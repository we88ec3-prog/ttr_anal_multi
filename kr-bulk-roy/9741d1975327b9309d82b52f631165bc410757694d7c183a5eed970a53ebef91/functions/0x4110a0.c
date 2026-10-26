
void FUN_004110a0(int param_1)

{
  undefined ***pppuVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 **ppuVar6;
  char cVar7;
  ushort uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 **ppuVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  byte bVar16;
  uint uVar17;
  int iVar18;
  uint *puVar19;
  undefined ***pppuVar20;
  undefined8 uVar21;
  undefined4 *local_a8;
  undefined4 *local_a4;
  uint local_a0;
  undefined4 *local_9c;
  undefined4 *local_98;
  char local_91;
  undefined1 local_90 [4];
  undefined4 *local_8c;
  undefined4 local_88;
  undefined4 *local_80;
  char *local_7c;
  char *local_78;
  undefined **local_74 [4];
  undefined4 *local_64;
  undefined4 *local_60;
  undefined4 *puStack_5c;
  undefined4 *local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 *puStack_44;
  undefined4 *local_40;
  undefined4 *puStack_3c;
  undefined4 *puStack_38;
  undefined4 *puStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00942018;
  local_14 = ExceptionList;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xffffff48;
  ExceptionList = &local_14;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_c = 0;
    FUN_00813890(uVar9);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_a0 = (DAT_00fb11dc + 5) / 5;
  do {
    local_74[0] = (undefined **)0x0;
    local_74[1] = (undefined **)0x0;
    local_74[2] = (undefined **)0x0;
    local_c = 1;
    pppuVar20 = *(undefined ****)(param_1 + 0x128);
    if ((local_74 < pppuVar20) &&
       (pppuVar1 = *(undefined ****)(param_1 + 0x124), pppuVar1 <= local_74)) {
      if (pppuVar20 == *(undefined ****)(param_1 + 300)) {
        FUN_004123e0();
      }
      local_7c = *(char **)(param_1 + 0x128);
      pppuVar20 = (undefined ***)
                  (((int)local_74 - (int)pppuVar1 & 0xfffffff0U) + *(int *)(param_1 + 0x124));
      local_c = CONCAT31(local_c._1_3_,2);
      local_78 = local_7c;
      if (local_7c != (char *)0x0) {
LAB_004111be:
        local_78 = local_7c;
        FUN_007e8a90(local_7c,pppuVar20);
      }
    }
    else {
      if (pppuVar20 == *(undefined ****)(param_1 + 300)) {
        FUN_004123e0();
      }
      local_7c = *(char **)(param_1 + 0x128);
      local_c = CONCAT31(local_c._1_3_,3);
      local_78 = local_7c;
      if (local_7c != (char *)0x0) {
        pppuVar20 = local_74;
        goto LAB_004111be;
      }
    }
    *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + 0x10;
    local_a0 = local_a0 - 1;
    local_74[0] = (undefined **)0x0;
    local_74[1] = (undefined **)0x0;
    local_74[2] = (undefined **)0x0;
  } while (local_a0 != 0);
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_c._1_3_ = 0;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_c._0_1_ = 5;
    local_c._1_3_ = 0;
    FUN_00813890(uVar9);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_c._0_1_ = 4;
  FUN_008176c0(*(undefined1 *)(param_1 + 0x144),&local_54);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 6;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c._0_1_ = 4;
  }
  if (*(byte *)(param_1 + 0x144) < 10) {
    uVar9 = DAT_00f94304 + (uint)*(byte *)(param_1 + 0x144) * 0x210;
    uVar9 = -(uint)(*(int *)(uVar9 + 0x5c) != 0) & uVar9;
  }
  else {
    uVar9 = 0;
  }
  if (*(byte *)(param_1 + 0x145) < 7) {
    local_60 = (undefined4 *)(uVar9 + 0x110 + (uint)*(byte *)(param_1 + 0x145) * 0x1c);
  }
  else {
    local_60 = (undefined4 *)0x0;
  }
  local_88 = 0;
  local_8c = (undefined4 *)FUN_00891268(0x10);
  if (local_8c == (undefined4 *)0x0) {
    local_7c = (char *)0x0;
    std::exception::exception((exception *)local_74,&local_7c);
    local_74[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_74,&DAT_00c857a8);
  }
  *local_8c = local_8c;
  local_8c[1] = local_8c;
  local_8c[2] = local_8c;
  *(undefined1 *)((int)local_8c + 0xe) = 1;
  *(undefined1 *)((int)local_8c + 0xf) = 1;
  if ((DAT_00fab278 & 1) == 0) {
    DAT_00fab278 = DAT_00fab278 | 1;
    local_c._0_1_ = 8;
    FUN_00817da0();
    _atexit((_func_4879 *)&LAB_00bcced0);
  }
  local_c = CONCAT31(local_c._1_3_,7);
  local_98 = (undefined4 *)(uint)*(byte *)(param_1 + 0x144);
  bVar16 = *(byte *)(param_1 + 0x145);
  FUN_008195e0(&local_98);
  puVar12 = local_9c;
  if (local_9c != DAT_00fab280) {
    puVar15 = (undefined4 *)((undefined4 *)local_9c[5])[1];
    cVar7 = *(char *)((int)puVar15 + 0x19);
    local_98 = (undefined4 *)local_9c[5];
    while (cVar7 == '\0') {
      if (*(byte *)(puVar15 + 3) < bVar16) {
        puVar11 = (undefined4 *)puVar15[2];
        puVar15 = local_98;
      }
      else {
        puVar11 = (undefined4 *)*puVar15;
      }
      local_98 = puVar15;
      puVar15 = puVar11;
      cVar7 = *(char *)((int)puVar11 + 0x19);
    }
    puVar15 = (undefined4 *)local_9c[5];
    if ((local_98 == puVar15) || (bVar16 < *(byte *)(local_98 + 3))) {
      local_9c = puVar15;
      ppuVar13 = &local_9c;
    }
    else {
      ppuVar13 = &local_98;
    }
    puVar11 = *ppuVar13;
    if (puVar15 == puVar11) {
      if ((bVar16 != 0) || (puVar12[6] == 0)) goto LAB_0041142f;
      puVar11 = (undefined4 *)*puVar15;
    }
    iVar2 = puVar11[4];
    if (iVar2 != 0) {
      local_a0 = 0;
      do {
        uVar17 = 0;
        uVar9 = local_a0;
        do {
          if (((byte)uVar9 < 4) && ((byte)uVar17 < 0xb)) {
            uVar8 = *(ushort *)(iVar2 + 4 + ((uVar9 & 0xff) * 0xb + (uVar17 & 0xff)) * 2);
          }
          else {
            uVar8 = 0;
          }
          local_98 = (undefined4 *)(uint)uVar8;
          if (uVar8 != 0) {
            uVar10 = FUN_0055e5b0(&local_98);
            FUN_00412b40(local_90,uVar10);
            uVar9 = local_a0;
          }
          uVar17 = uVar17 + 1;
        } while (uVar17 < 0xb);
        local_a0 = uVar9 + 1;
      } while (local_a0 < 4);
    }
  }
LAB_0041142f:
  local_78 = (char *)(local_50 - local_54 >> 2);
  local_a0 = 0;
  puVar12 = local_8c;
  if (local_78 != (char *)0x0) {
    do {
      puVar15 = *(undefined4 **)(local_54 + local_a0 * 4);
      puVar11 = (undefined4 *)*local_60;
      uVar9 = local_60[1] - (int)puVar11 >> 3;
      uVar17 = 0;
      local_98 = puVar15;
      puVar14 = puVar11;
      if (uVar9 != 0) {
        do {
          if ((undefined4 *)*puVar14 == puVar15) {
            cVar7 = (char)*(undefined2 *)(puVar11 + uVar17 * 2 + 1);
            goto LAB_0041148e;
          }
          uVar17 = uVar17 + 1;
          puVar14 = puVar14 + 2;
        } while (uVar17 < uVar9);
      }
      cVar7 = '\0';
LAB_0041148e:
      local_91 = cVar7 + '\x01';
      if ((DAT_00fb11a8 & 1) == 0) {
        DAT_00fb11a8 = DAT_00fb11a8 | 1;
        local_c._0_1_ = 9;
        FUN_00813890();
        _atexit((_func_4879 *)&LAB_00bccec0);
        local_c = CONCAT31(local_c._1_3_,7);
        puVar12 = local_8c;
      }
      cVar7 = *(char *)((int)DAT_00fb11b0[1] + 0x15);
      puVar11 = (undefined4 *)DAT_00fb11b0[1];
      local_9c = DAT_00fb11b0;
      while (puVar14 = puVar11, cVar7 == '\0') {
        if ((undefined4 *)puVar14[3] < puVar15) {
          puVar11 = (undefined4 *)puVar14[2];
          puVar14 = local_9c;
        }
        else {
          puVar11 = (undefined4 *)*puVar14;
        }
        cVar7 = *(char *)((int)puVar11 + 0x15);
        local_9c = puVar14;
      }
      if ((local_9c == DAT_00fb11b0) || (puVar15 < (undefined4 *)local_9c[3])) {
        local_58 = DAT_00fb11b0;
        ppuVar13 = &local_58;
      }
      else {
        ppuVar13 = &local_9c;
      }
      if ((*ppuVar13 != DAT_00fb11b0) && (iVar2 = (*ppuVar13)[4], iVar2 != 0)) {
        iVar18 = *(int *)(iVar2 + 0x14);
        iVar3 = *(int *)(iVar2 + 0x18);
        local_9c = (undefined4 *)0x0;
        local_a4 = (undefined4 *)0x0;
        if (iVar18 == iVar3) {
          bVar16 = 0;
        }
        else {
          bVar16 = (char)(iVar3 - iVar18 >> 2) - 1;
        }
        if ((uint)bVar16 < (uint)(iVar3 - iVar18 >> 2)) {
          iVar18 = *(int *)(iVar18 + (uint)bVar16 * 4);
          local_64 = (undefined4 *)(*(int *)(iVar18 + 0x18) - *(int *)(iVar18 + 0x14) >> 2);
        }
        else {
          local_64 = (undefined4 *)0x0;
        }
        local_80 = (undefined4 *)0x0;
        if (local_64 != (undefined4 *)0x0) {
          do {
            puVar15 = local_80;
            uVar21 = FUN_0081ae80();
            iVar18 = *(int *)(*(int *)((int)((ulonglong)uVar21 >> 0x20) + 0x14) +
                             ((uint)uVar21 & 0xff) * 4);
            if ((puVar15 < (undefined4 *)(*(int *)(iVar18 + 0x18) - *(int *)(iVar18 + 0x14) >> 2))
               && (piVar4 = *(int **)(*(int *)(iVar18 + 0x14) + (int)puVar15 * 4),
                  piVar4 != (int *)0x0)) {
              uVar9 = (**(code **)(*piVar4 + 4))();
              if ((uVar9 & 0x12100000) == 0x12100000) {
                uVar9 = (**(code **)(*piVar4 + 4))();
                uVar8 = *(ushort *)
                         ((~-(uint)((uVar9 & 0x12100000) != 0x12100000) & (uint)piVar4) + 4);
                cVar7 = *(char *)((int)local_8c[1] + 0xf);
                puVar12 = (undefined4 *)local_8c[1];
                local_a4 = local_8c;
                while (puVar11 = puVar12, cVar7 == '\0') {
                  if (*(ushort *)(puVar11 + 3) < uVar8) {
                    puVar12 = (undefined4 *)puVar11[2];
                    puVar11 = local_a4;
                  }
                  else {
                    puVar12 = (undefined4 *)*puVar11;
                  }
                  cVar7 = *(char *)((int)puVar12 + 0xf);
                  local_a4 = puVar11;
                }
                if ((local_a4 == local_8c) || (uVar8 < *(ushort *)(local_a4 + 3))) {
                  puStack_5c = local_8c;
                  ppuVar13 = &puStack_5c;
                }
                else {
                  ppuVar13 = &local_a4;
                }
                puVar12 = local_8c;
                if (*ppuVar13 != local_8c) goto LAB_00411808;
                local_a4 = (undefined4 *)0x1;
              }
              uVar9 = (**(code **)(*piVar4 + 4))();
              if ((uVar9 & 0x12200000) == 0x12200000) {
                uVar9 = (**(code **)(*piVar4 + 4))();
                uVar8 = *(ushort *)
                         ((~-(uint)((uVar9 & 0x12200000) != 0x12200000) & (uint)piVar4) + 4);
                cVar7 = *(char *)((int)local_8c[1] + 0xf);
                puVar12 = (undefined4 *)local_8c[1];
                local_80 = local_8c;
                while (puVar11 = puVar12, cVar7 == '\0') {
                  if (*(ushort *)(puVar11 + 3) < uVar8) {
                    puVar12 = (undefined4 *)puVar11[2];
                    puVar11 = local_80;
                  }
                  else {
                    puVar12 = (undefined4 *)*puVar11;
                  }
                  cVar7 = *(char *)((int)puVar12 + 0xf);
                  local_80 = puVar11;
                }
                if ((local_80 == local_8c) || (uVar8 < *(ushort *)(local_80 + 3))) {
                  puStack_34 = local_8c;
                  ppuVar13 = &puStack_34;
                }
                else {
                  ppuVar13 = &local_80;
                }
                puVar12 = local_8c;
                if (*ppuVar13 != local_8c) goto LAB_00411808;
                local_a4 = (undefined4 *)0x1;
              }
              else {
                uVar9 = (**(code **)(*piVar4 + 4))();
                puVar12 = local_8c;
                if ((uVar9 & 0x14100000) == 0x14100000) {
                  uVar9 = (**(code **)(*piVar4 + 4))();
                  FUN_007e8a90(&iStack_30,
                               (~-(uint)((uVar9 & 0x14100000) != 0x14100000) & (uint)piVar4) + 8);
                  local_c = CONCAT31(local_c._1_3_,10);
                  uVar9 = iStack_2c - iStack_30 >> 2;
                  uVar17 = 0;
                  if (uVar9 != 0) {
                    if (uVar9 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_0087db7d("invalid vector<T> subscript");
                    }
                    do {
                      iVar18 = *(int *)(iStack_30 + uVar17 * 4);
                      if (*(int *)(iVar18 + 4) == 5) {
                        uVar8 = *(ushort *)(iVar18 + 8);
                        cVar7 = *(char *)((int)local_8c[1] + 0xf);
                        puVar12 = (undefined4 *)local_8c[1];
                        puStack_44 = local_8c;
                        while (puVar15 = puVar12, cVar7 == '\0') {
                          if (*(ushort *)(puVar15 + 3) < uVar8) {
                            puVar12 = (undefined4 *)puVar15[2];
                            puVar15 = puStack_44;
                          }
                          else {
                            puVar12 = (undefined4 *)*puVar15;
                          }
                          cVar7 = *(char *)((int)puVar12 + 0xf);
                          puStack_44 = puVar15;
                        }
                        if ((puStack_44 == local_8c) || (uVar8 < *(ushort *)(puStack_44 + 3))) {
                          puStack_38 = local_8c;
                          ppuVar13 = &puStack_38;
                        }
                        else {
                          ppuVar13 = &puStack_44;
                        }
                        if (*ppuVar13 != local_8c) {
                          local_9c = (undefined4 *)0x1;
                          break;
                        }
                        local_a4 = (undefined4 *)0x1;
                      }
                      uVar17 = uVar17 + 1;
                    } while (uVar17 < uVar9);
                  }
                  local_c = CONCAT31(local_c._1_3_,7);
                  if (iStack_30 != 0) {
                    FUN_0089120c(iStack_30);
                  }
                  iStack_30 = 0;
                  iStack_2c = 0;
                  uStack_28 = 0;
                  puVar15 = local_80;
                  puVar12 = local_8c;
                }
              }
            }
            local_80 = (undefined4 *)((int)puVar15 + 1);
          } while ((undefined4 *)((int)puVar15 + 1) < local_64);
          if ((local_9c == (undefined4 *)0x0) && (local_a4 != (undefined4 *)0x0)) goto LAB_00411a02;
        }
LAB_00411808:
        iVar18 = *(int *)(iVar2 + 0x18);
        iVar3 = *(int *)(iVar2 + 0x14);
        uVar9 = 0;
        while( true ) {
          uVar17 = FUN_0081ae80();
          if (((uint)(iVar18 - iVar3 >> 2) <= (uVar17 & 0xff)) ||
             (iVar5 = *(int *)(*(int *)(iVar2 + 0x14) + (uVar17 & 0xff) * 4),
             (uint)(*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2) <= uVar9)) goto LAB_00411a02;
          uVar21 = FUN_0081ae80();
          iVar5 = *(int *)((int)((ulonglong)uVar21 >> 0x20) + ((uint)uVar21 & 0xff) * 4);
          if ((1 < (uint)(*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2)) &&
             ((iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4), iVar5 != 0 && (*(int *)(iVar5 + 4) == 4)))
             ) break;
          uVar9 = uVar9 + 1;
        }
        iVar18 = *(int *)(iVar5 + 8);
        if (0 < iVar18) {
          iVar18 = iVar18 / 5;
        }
        local_a8 = (undefined4 *)FUN_00891268(8);
        if (local_a8 == (undefined4 *)0x0) {
          local_a8 = (undefined4 *)0x0;
        }
        else {
          if (*(int *)(iVar2 + 0x14) == *(int *)(iVar2 + 0x18)) {
            cVar7 = '\0';
          }
          else {
            cVar7 = (char)(*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2) + -1;
          }
          *local_a8 = local_98;
          *(char *)((int)local_a8 + 5) = cVar7;
          *(char *)(local_a8 + 1) = local_91;
          *(undefined1 *)((int)local_a8 + 6) = 0;
          *(char *)((int)local_a8 + 7) = (char)iVar18 * '\x05';
        }
        puVar19 = (uint *)(iVar18 * 0x10 + *(int *)(param_1 + 0x124));
        ppuVar13 = (undefined4 **)puVar19[1];
        local_a4 = local_a8;
        if (&local_a4 < ppuVar13) {
          ppuVar6 = (undefined4 **)*puVar19;
          if (&local_a4 < ppuVar6) goto LAB_00411968;
          if (ppuVar13 == (undefined4 **)puVar19[2]) {
            uVar9 = (int)ppuVar13 - (int)ppuVar6 >> 2;
            if (0x3ffffffe < uVar9) goto LAB_00411a9b;
            uVar9 = uVar9 + 1;
            uVar17 = (int)puVar19[2] - (int)ppuVar6 >> 2;
            if (uVar17 < uVar9) {
              if (0x3fffffff - (uVar17 >> 1) < uVar17) {
                uVar17 = 0;
              }
              else {
                uVar17 = uVar17 + (uVar17 >> 1);
              }
              if (uVar17 < uVar9) {
                uVar17 = uVar9;
              }
              FUN_00797980(uVar17);
            }
          }
          if ((undefined4 *)puVar19[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar19[1] =
                 *(undefined4 *)(*puVar19 + ((int)&local_a4 - (int)ppuVar6 >> 2) * 4);
          }
        }
        else {
LAB_00411968:
          if (ppuVar13 == (undefined4 **)puVar19[2]) {
            uVar9 = (int)((int)ppuVar13 - *puVar19) >> 2;
            if (0x3ffffffe < uVar9) {
LAB_00411a9b:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar9 = uVar9 + 1;
            uVar17 = (int)((int)puVar19[2] - *puVar19) >> 2;
            if (uVar17 < uVar9) {
              if (0x3fffffff - (uVar17 >> 1) < uVar17) {
                uVar17 = 0;
              }
              else {
                uVar17 = uVar17 + (uVar17 >> 1);
              }
              if (uVar17 < uVar9) {
                uVar17 = uVar9;
              }
              FUN_00797980(uVar17);
            }
          }
          if ((undefined4 *)puVar19[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar19[1] = local_a8;
          }
        }
        puVar19[1] = puVar19[1] + 4;
        local_40 = local_98;
        puStack_3c = local_a8;
        uVar10 = FUN_0057ef20();
        FUN_0082f200(param_1 + 0x114,uVar10);
        puVar12 = local_8c;
        if (*(int *)(param_1 + 0x158) == 0) {
          *(undefined4 **)(param_1 + 0x158) = local_a8;
        }
      }
LAB_00411a02:
      local_a0 = local_a0 + 1;
    } while (local_a0 < local_78);
  }
  iVar18 = local_54;
  iVar2 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
  if (iVar2 != 0) {
    FUN_00408920(iVar2,*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 4);
    puVar12 = local_8c;
  }
  local_c = CONCAT31(local_c._1_3_,0xb);
  FUN_0081cd10(*puVar12,puVar12);
  FUN_0089120c(local_8c);
  if (iVar18 != 0) {
    FUN_0089120c(iVar18);
  }
  ExceptionList = local_14;
  return;
}


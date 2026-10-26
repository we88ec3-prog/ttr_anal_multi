
void FUN_0084e8f0(int param_1)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  int *piVar11;
  float *pfVar12;
  int iVar13;
  int **ppiVar14;
  int *piVar15;
  int *in_ECX;
  undefined4 *puVar16;
  int *piVar17;
  uint uVar18;
  undefined1 *puVar19;
  float *pfVar20;
  int iVar21;
  float **ppfVar22;
  bool bVar23;
  undefined ***pppuVar24;
  undefined **local_1a0 [3];
  undefined **local_194 [3];
  undefined **local_188 [3];
  undefined1 local_17c [20];
  undefined1 local_168 [8];
  undefined1 local_160 [8];
  undefined1 local_158 [12];
  undefined1 local_14c [12];
  undefined4 local_140;
  int local_13c;
  float *local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  int *local_124;
  float *local_120;
  float *local_11c;
  int local_118;
  undefined **local_114 [3];
  int *local_108;
  int *local_104;
  undefined1 local_100 [4];
  float *local_fc;
  undefined4 local_f8;
  undefined **local_f0 [3];
  undefined1 local_e4 [4];
  float *local_e0;
  undefined4 local_dc;
  undefined1 local_d4 [4];
  int *local_d0;
  float local_cc;
  int *local_c0;
  undefined4 local_bc;
  undefined1 local_b4 [4];
  float *local_b0;
  undefined4 local_ac;
  undefined1 local_a4 [4];
  float *local_a0;
  float local_9c;
  char *local_94;
  float *local_90;
  char *local_8c;
  float local_88;
  int local_84;
  int *local_80;
  undefined4 local_7c;
  float **local_74;
  float **local_70;
  float **local_6c;
  int *local_64;
  undefined4 local_60;
  float *local_5c;
  float local_58;
  undefined4 *local_54;
  float local_50;
  float *local_48;
  int *local_44;
  int *local_40;
  float *local_3c;
  float *local_38;
  int local_34;
  float *local_30;
  float *local_2c;
  float *local_28;
  int local_24 [5];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_0090e1e4;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_88 = *(float *)(param_1 + 0xbc);
  local_34 = param_1;
  local_44 = in_ECX;
  local_24[3] = uVar4;
  if (*(int *)(param_1 + 0xc0) != *(int *)(param_1 + 0xc4)) {
    uVar5 = FUN_008539a0();
    *(undefined4 *)(param_1 + 0xc4) = uVar5;
  }
  local_2c = (float *)((in_ECX[1] - *in_ECX) / 100);
  if (local_2c != (float *)0x0) {
    iVar6 = FUN_00857520(0);
    if (iVar6 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(iVar6 + 8);
    }
    if (*(int *)(param_1 + 0xc0) != *(int *)(param_1 + 0xc4)) {
      uVar7 = FUN_008539a0(local_94,uVar4);
      *(undefined4 *)(param_1 + 0xc4) = uVar7;
    }
    FUN_00850690(uVar5);
    local_38 = (float *)0x0;
    if (local_2c != (float *)0x0) {
      local_28 = (float *)0x0;
      do {
        iVar6 = *local_44;
        if ((float *)((local_44[1] - iVar6) / 100) <= local_38) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        local_64 = *(int **)(iVar6 + 0x58 + (int)local_28);
        for (local_40 = *(int **)(iVar6 + 0x54 + (int)local_28); local_40 != local_64;
            local_40 = local_40 + 2) {
          pfVar10 = (float *)local_40[1];
          iVar21 = *(int *)(local_34 + 0xc0);
          iVar6 = *local_40 * 0x24;
          iVar13 = *(int *)(iVar6 + 0x20 + iVar21);
          pfVar12 = (float *)(iVar6 + iVar21);
          iVar8 = 0;
          local_30 = pfVar10;
          if (0 < iVar13) {
            do {
              if ((float *)*pfVar12 == local_38) {
                iVar6 = iVar6 + iVar8 * 8;
                *(float *)(iVar6 + 4 + iVar21) = *(float *)(iVar6 + 4 + iVar21) + (float)pfVar10;
                goto LAB_0084ead3;
              }
              iVar8 = iVar8 + 1;
              pfVar12 = pfVar12 + 2;
            } while (iVar8 < iVar13);
          }
          if (0.01 < (float)pfVar10) {
            if (iVar13 < 4) {
              *(float **)(iVar6 + iVar13 * 8 + *(int *)(local_34 + 0xc0)) = local_38;
              *(float **)(iVar6 + iVar13 * 8 + 4 + *(int *)(local_34 + 0xc0)) = pfVar10;
              piVar11 = (int *)(iVar6 + 0x20 + *(int *)(local_34 + 0xc0));
              *piVar11 = *piVar11 + 1;
            }
            else {
              iVar8 = 0;
              pfVar12 = local_38;
              local_3c = pfVar10;
              if (0 < iVar13) {
                do {
                  pfVar20 = pfVar12;
                  pfVar9 = pfVar10;
                  if (*(float *)(iVar6 + iVar8 * 8 + 4 + iVar21) < (float)pfVar10) {
                    pfVar9 = (float *)(iVar6 + iVar8 * 8 + *(int *)(local_34 + 0xc0));
                    local_3c = (float *)pfVar9[1];
                    pfVar20 = (float *)*pfVar9;
                    *pfVar9 = (float)pfVar12;
                    *(float **)(iVar6 + iVar8 * 8 + 4 + *(int *)(local_34 + 0xc0)) = pfVar10;
                    pfVar9 = local_3c;
                    local_30 = pfVar10;
                  }
                  pfVar10 = pfVar9;
                  iVar21 = *(int *)(local_34 + 0xc0);
                  iVar8 = iVar8 + 1;
                  pfVar12 = pfVar20;
                } while (iVar8 < *(int *)(iVar6 + 0x20 + iVar21));
              }
            }
          }
LAB_0084ead3:
        }
        local_28 = local_28 + 0x19;
        local_38 = (float *)((int)local_38 + 1);
        param_1 = local_34;
      } while (local_38 < local_2c);
    }
    local_64 = (int *)FUN_00857b00(0,0);
    if ((-1 < (int)local_64) &&
       (pfVar12 = (float *)((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0xc),
       local_11c = pfVar12, pfVar12 != (float *)0x0)) {
      local_f8 = 0;
      pfVar10 = (float *)FUN_00891268(0x20);
      if (pfVar10 == (float *)0x0) {
        local_94 = (char *)0x0;
        std::exception::exception((exception *)local_194,&local_94);
        pppuVar24 = local_194;
        local_194[0] = std::bad_alloc::vftable;
      }
      else {
        *pfVar10 = (float)pfVar10;
        pfVar10[1] = (float)pfVar10;
        pfVar10[2] = (float)pfVar10;
        *(undefined1 *)(pfVar10 + 7) = 1;
        *(undefined1 *)((int)pfVar10 + 0x1d) = 1;
        local_8._0_1_ = 0;
        local_8._1_3_ = 0;
        local_30 = (float *)0x0;
        local_fc = pfVar10;
        if (pfVar12 != (float *)0x0) {
          local_64 = (int *)((int)local_64 * 0xc);
          do {
            piVar11 = (int *)(*(int *)(**(int **)(local_34 + 0x44) + (int)local_30 * 0x14) +
                             (int)local_64);
            local_24[0] = *piVar11;
            local_24[1] = piVar11[1];
            local_24[2] = piVar11[2];
            local_9c = 0.0;
            pfVar12 = (float *)FUN_00891268(0x14);
            if (pfVar12 == (float *)0x0) {
              local_48 = (float *)0x0;
              std::exception::exception((exception *)local_f0,(char **)&local_48);
              local_f0[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(local_f0,&DAT_00c857a8);
            }
            local_a0 = pfVar12;
            *pfVar12 = (float)pfVar12;
            pfVar12[1] = (float)pfVar12;
            pfVar12[2] = (float)pfVar12;
            *(undefined1 *)(pfVar12 + 4) = 1;
            *(undefined1 *)((int)pfVar12 + 0x11) = 1;
            local_8._0_1_ = 1;
            local_40 = (int *)0x0;
            do {
              pfVar12 = (float *)(*(int *)(local_34 + 0xc0) + local_24[(int)local_40] * 0x24);
              iVar6 = 0;
              pfVar10 = pfVar12;
              if (0 < (int)pfVar12[8]) {
                do {
                  local_28 = pfVar10;
                  uVar5 = FUN_006bde40(local_28);
                  FUN_00852b40(local_a4,uVar5);
                  local_28 = local_28 + 2;
                  iVar6 = iVar6 + 1;
                  pfVar10 = local_28;
                } while (iVar6 < (int)pfVar12[8]);
              }
              local_40 = (int *)((int)local_40 + 1);
            } while ((int)local_40 < 3);
            if ((uint)local_88 < (uint)local_9c) {
              local_cc = 0.0;
              piVar11 = (int *)FUN_00891268(0x14);
              if (piVar11 == (int *)0x0) {
                local_5c = (float *)0x0;
                ppfVar22 = &local_5c;
                goto LAB_0084f742;
              }
              *piVar11 = (int)piVar11;
              piVar11[1] = (int)piVar11;
              piVar11[2] = (int)piVar11;
              *(undefined1 *)(piVar11 + 4) = 1;
              *(undefined1 *)((int)piVar11 + 0x11) = 1;
              local_8._0_1_ = 2;
              local_bc = 0;
              local_d0 = piVar11;
              piVar11 = (int *)FUN_00891268(0x1c);
              if (piVar11 == (int *)0x0) {
                local_90 = (float *)0x0;
                std::exception::exception((exception *)local_1a0,(char **)&local_90);
                local_1a0[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(local_1a0,&DAT_00c857a8);
              }
              *piVar11 = (int)piVar11;
              piVar11[1] = (int)piVar11;
              piVar11[2] = (int)piVar11;
              *(undefined1 *)(piVar11 + 6) = 1;
              *(undefined1 *)((int)piVar11 + 0x19) = 1;
              local_8._0_1_ = 3;
              local_7c = 0;
              local_c0 = piVar11;
              piVar11 = (int *)FUN_00891268(0x18);
              if (piVar11 == (int *)0x0) {
                local_8c = (char *)0x0;
                std::exception::exception((exception *)local_188,&local_8c);
                local_188[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(local_188,&DAT_00c857a8);
              }
              local_80 = piVar11;
              *piVar11 = (int)piVar11;
              piVar11[1] = (int)piVar11;
              piVar11[2] = (int)piVar11;
              *(undefined1 *)(piVar11 + 5) = 1;
              *(undefined1 *)((int)piVar11 + 0x15) = 1;
              local_8 = CONCAT31(local_8._1_3_,4);
              local_3c = (float *)0x0;
              do {
                iVar13 = local_24[(int)local_3c];
                iVar21 = *(int *)(local_34 + 0xc0);
                local_28 = *(float **)(iVar21 + 4 + iVar13 * 0x24);
                local_40 = *(int **)(iVar21 + iVar13 * 0x24);
                iVar6 = iVar21 + iVar13 * 0x24;
                local_38 = (float *)0x0;
                if (0 < *(int *)(iVar21 + 0x20 + iVar13 * 0x24)) {
                  do {
                    local_134 = *(undefined4 *)(iVar6 + 4 + (int)local_38 * 8);
                    local_130 = *(undefined4 *)(iVar6 + (int)local_38 * 8);
                    FUN_00853c50();
                    FUN_00853ac0(&local_84);
                    local_140 = *(undefined4 *)(iVar6 + (int)local_38 * 8);
                    local_13c = (int)local_3c;
                    local_138 = local_38;
                    iVar13 = FUN_00821c50();
                    puVar16 = (undefined4 *)local_c0[1];
                    local_2c = (float *)CONCAT31(local_2c._1_3_,1);
                    if (*(char *)((int)puVar16 + 0x19) == '\0') {
                      do {
                        bVar23 = *(uint *)(iVar13 + 0xc) < (uint)puVar16[3];
                        local_2c = (float *)CONCAT31(local_2c._1_3_,bVar23);
                        if (bVar23) {
                          puVar16 = (undefined4 *)*puVar16;
                        }
                        else {
                          puVar16 = (undefined4 *)puVar16[2];
                        }
                      } while (*(char *)((int)puVar16 + 0x19) == '\0');
                    }
                    FUN_00518bc0(local_158,local_2c,iVar13);
                    fVar1 = *(float *)(iVar6 + 4 + (int)local_38 * 8);
                    if ((float)local_28 < fVar1 != ((float)local_28 == fVar1)) {
                      local_28 = *(float **)(iVar6 + 4 + (int)local_38 * 8);
                      local_40 = *(int **)(iVar6 + (int)local_38 * 8);
                    }
                    local_38 = (float *)((int)local_38 + 1);
                  } while ((int)local_38 < *(int *)(iVar6 + 0x20));
                }
                pfVar12 = local_3c;
                uVar5 = FUN_006bde40(&local_40);
                FUN_0044bbd0(local_d4,uVar5);
                fVar1 = local_88;
                local_3c = (float *)((int)pfVar12 + 1);
              } while ((int)local_3c < 3);
              piVar11 = (int *)*local_80;
              local_44 = local_80;
              if (piVar11 != local_80) {
                do {
                  uVar5 = FUN_006bde40(piVar11 + 4);
                  FUN_0044bbd0(local_d4,uVar5);
                  if ((uint)fVar1 <= (uint)local_cc) break;
                  if (*(char *)((int)piVar11 + 0x15) == '\0') {
                    piVar17 = (int *)piVar11[2];
                    if (*(char *)((int)piVar17 + 0x15) == '\0') {
                      cVar2 = *(char *)(*piVar17 + 0x15);
                      piVar11 = piVar17;
                      piVar17 = (int *)*piVar17;
                      while (cVar2 == '\0') {
                        cVar2 = *(char *)(*piVar17 + 0x15);
                        piVar11 = piVar17;
                        piVar17 = (int *)*piVar17;
                      }
                    }
                    else {
                      cVar2 = *(char *)(piVar11[1] + 0x15);
                      piVar15 = (int *)piVar11[1];
                      piVar17 = piVar11;
                      while ((piVar11 = piVar15, cVar2 == '\0' && (piVar17 == (int *)piVar11[2]))) {
                        cVar2 = *(char *)(piVar11[1] + 0x15);
                        piVar15 = (int *)piVar11[1];
                        piVar17 = piVar11;
                      }
                    }
                  }
                } while (piVar11 != local_44);
              }
              ppfVar22 = (float **)0x0;
              local_74 = (float **)0x0;
              local_70 = (float **)0x0;
              local_6c = (float **)0x0;
              local_8 = CONCAT31(local_8._1_3_,5);
              local_3c = (float *)*local_a0;
              local_120 = local_a0;
              if (local_3c != local_a0) {
                do {
                  local_38 = (float *)local_3c[3];
                  cVar2 = *(char *)(local_d0[1] + 0x11);
                  piVar11 = (int *)local_d0[1];
                  local_44 = local_d0;
                  while (piVar17 = piVar11, cVar2 == '\0') {
                    if ((float *)piVar17[3] < local_38) {
                      piVar11 = (int *)piVar17[2];
                      piVar17 = local_44;
                    }
                    else {
                      piVar11 = (int *)*piVar17;
                    }
                    cVar2 = *(char *)((int)piVar11 + 0x11);
                    local_44 = piVar17;
                  }
                  if ((local_44 == local_d0) || (local_38 < (float *)local_44[3])) {
                    local_108 = local_d0;
                    ppiVar14 = &local_108;
                  }
                  else {
                    ppiVar14 = &local_44;
                  }
                  if (*ppiVar14 == local_d0) {
                    cVar2 = *(char *)(local_c0[1] + 0x19);
                    piVar11 = (int *)local_c0[1];
                    local_44 = local_c0;
                    while (piVar17 = piVar11, cVar2 == '\0') {
                      if ((float *)piVar17[3] < local_38) {
                        piVar11 = (int *)piVar17[2];
                        piVar17 = local_44;
                      }
                      else {
                        piVar11 = (int *)*piVar17;
                      }
                      cVar2 = *(char *)((int)piVar11 + 0x19);
                      local_44 = piVar17;
                    }
                    if ((local_44 == local_c0) || (local_38 < (float *)local_44[3])) {
                      local_124 = local_c0;
                      ppiVar14 = &local_124;
                    }
                    else {
                      ppiVar14 = &local_44;
                    }
                    piVar11 = *ppiVar14;
                    piVar17 = piVar11;
                    while ((piVar11 != local_c0 && ((float *)piVar11[3] == local_38))) {
                      local_118 = piVar11[4];
                      local_40 = (int *)piVar11[5];
                      iVar13 = local_24[local_118] * 0x24;
                      iVar6 = *(int *)(*(int *)(local_34 + 0xc0) + 0x20 + iVar13);
                      if ((int)local_40 < iVar6) {
                        if (local_40 == (int *)(iVar6 + -1)) {
                          *(undefined4 *)(*(int *)(local_34 + 0xc0) + (int)local_40 * 8 + iVar13) =
                               0;
                          *(undefined4 *)
                           (*(int *)(local_34 + 0xc0) + (int)local_40 * 8 + 4 + iVar13) = 0;
                        }
                        else {
                          iVar8 = iVar6 * 8;
                          iVar21 = iVar8 + *(int *)(local_34 + 0xc0);
                          uVar5 = *(undefined4 *)(iVar21 + -4 + iVar13);
                          uVar4 = *(uint *)(iVar21 + -8 + iVar13);
                          *(uint *)(*(int *)(local_34 + 0xc0) + (int)local_40 * 8 + iVar13) = uVar4;
                          *(undefined4 *)
                           (*(int *)(local_34 + 0xc0) + (int)local_40 * 8 + 4 + iVar13) = uVar5;
                          *(undefined4 *)(*(int *)(local_34 + 0xc0) + iVar8 + -8 + iVar13) = 0;
                          *(undefined4 *)(*(int *)(local_34 + 0xc0) + iVar8 + -4 + iVar13) = 0;
                          piVar17[5] = iVar6 + -1;
                          cVar2 = *(char *)(local_c0[1] + 0x19);
                          piVar11 = (int *)local_c0[1];
                          local_44 = local_c0;
                          while (piVar15 = piVar11, cVar2 == '\0') {
                            if ((uint)piVar15[3] < uVar4) {
                              piVar11 = (int *)piVar15[2];
                              piVar15 = local_44;
                            }
                            else {
                              piVar11 = (int *)*piVar15;
                            }
                            cVar2 = *(char *)((int)piVar11 + 0x19);
                            local_44 = piVar15;
                          }
                          if ((local_44 == local_c0) || (uVar4 < (uint)local_44[3])) {
                            local_104 = local_c0;
                            ppiVar14 = &local_104;
                          }
                          else {
                            ppiVar14 = &local_44;
                          }
                          piVar15 = *ppiVar14;
                          while( true ) {
                            piVar11 = piVar17;
                            if ((piVar15 == local_c0) || (piVar15[3] != uVar4)) goto LAB_0084f19b;
                            if (piVar15[4] == local_118) break;
                            if (*(char *)((int)piVar15 + 0x19) == '\0') {
                              piVar11 = (int *)piVar15[2];
                              if (*(char *)((int)piVar11 + 0x19) == '\0') {
                                cVar2 = *(char *)(*piVar11 + 0x19);
                                piVar15 = piVar11;
                                piVar11 = (int *)*piVar11;
                                while (cVar2 == '\0') {
                                  cVar2 = *(char *)(*piVar11 + 0x19);
                                  piVar15 = piVar11;
                                  piVar11 = (int *)*piVar11;
                                }
                              }
                              else {
                                cVar2 = *(char *)(piVar15[1] + 0x19);
                                piVar3 = (int *)piVar15[1];
                                piVar11 = piVar15;
                                while ((piVar15 = piVar3, cVar2 == '\0' &&
                                       (piVar11 == (int *)piVar15[2]))) {
                                  cVar2 = *(char *)(piVar15[1] + 0x19);
                                  piVar3 = (int *)piVar15[1];
                                  piVar11 = piVar15;
                                }
                              }
                            }
                          }
                          piVar15[5] = (int)local_40;
                        }
LAB_0084f19b:
                        piVar15 = (int *)(*(int *)(local_34 + 0xc0) + 0x20 + iVar13);
                        *piVar15 = *piVar15 + -1;
                        ppfVar22 = local_70;
                      }
                      if (*(char *)((int)piVar11 + 0x19) == '\0') {
                        piVar17 = (int *)piVar11[2];
                        if (*(char *)((int)piVar17 + 0x19) == '\0') {
                          cVar2 = *(char *)(*piVar17 + 0x19);
                          piVar11 = piVar17;
                          piVar15 = (int *)*piVar17;
                          while (piVar17 = piVar11, cVar2 == '\0') {
                            cVar2 = *(char *)(*piVar15 + 0x19);
                            piVar11 = piVar15;
                            piVar15 = (int *)*piVar15;
                          }
                        }
                        else {
                          cVar2 = *(char *)(piVar11[1] + 0x19);
                          piVar17 = (int *)piVar11[1];
                          piVar15 = piVar11;
                          while ((piVar11 = piVar17, piVar17 = piVar11, cVar2 == '\0' &&
                                 (piVar15 == (int *)piVar11[2]))) {
                            cVar2 = *(char *)(piVar11[1] + 0x19);
                            piVar17 = (int *)piVar11[1];
                            piVar15 = piVar11;
                          }
                        }
                      }
                    }
                    local_28 = local_38;
                    if ((&local_28 < ppfVar22) && (local_74 <= &local_28)) {
                      iVar6 = (int)&local_28 - (int)local_74;
                      if (ppfVar22 == local_6c) {
                        uVar4 = (int)ppfVar22 - (int)local_74 >> 2;
                        if (0x3ffffffe < uVar4) {
LAB_0084f6ca:
                    /* WARNING: Subroutine does not return */
                          FUN_0087db30("vector<T> too long");
                        }
                        uVar4 = uVar4 + 1;
                        uVar18 = (int)local_6c - (int)local_74 >> 2;
                        if (uVar18 < uVar4) {
                          if (0x3fffffff - (uVar18 >> 1) < uVar18) {
                            uVar18 = 0;
                          }
                          else {
                            uVar18 = uVar18 + (uVar18 >> 1);
                          }
                          if (uVar18 < uVar4) {
                            uVar18 = uVar4;
                          }
                          FUN_00797980(uVar18);
                          ppfVar22 = local_70;
                        }
                      }
                      if (ppfVar22 != (float **)0x0) {
                        *ppfVar22 = local_74[iVar6 >> 2];
                      }
                    }
                    else {
                      if (ppfVar22 == local_6c) {
                        uVar4 = (int)ppfVar22 - (int)local_74 >> 2;
                        if (0x3ffffffe < uVar4) goto LAB_0084f6ca;
                        uVar4 = uVar4 + 1;
                        uVar18 = (int)local_6c - (int)local_74 >> 2;
                        if (uVar18 < uVar4) {
                          if (0x3fffffff - (uVar18 >> 1) < uVar18) {
                            uVar18 = 0;
                          }
                          else {
                            uVar18 = uVar18 + (uVar18 >> 1);
                          }
                          if (uVar18 < uVar4) {
                            uVar18 = uVar4;
                          }
                          FUN_00797980(uVar18);
                          ppfVar22 = local_70;
                        }
                      }
                      if (ppfVar22 != (float **)0x0) {
                        *ppfVar22 = local_38;
                      }
                    }
                    ppfVar22 = ppfVar22 + 1;
                    local_70 = ppfVar22;
                  }
                  if (*(char *)((int)local_3c + 0x11) == '\0') {
                    pfVar12 = (float *)local_3c[2];
                    if (*(char *)((int)pfVar12 + 0x11) == '\0') {
                      cVar2 = *(char *)((int)*pfVar12 + 0x11);
                      local_3c = pfVar12;
                      pfVar12 = (float *)*pfVar12;
                      while (cVar2 == '\0') {
                        cVar2 = *(char *)((int)*pfVar12 + 0x11);
                        local_3c = pfVar12;
                        pfVar12 = (float *)*pfVar12;
                      }
                    }
                    else {
                      cVar2 = *(char *)((int)local_3c[1] + 0x11);
                      pfVar10 = (float *)local_3c[1];
                      pfVar12 = local_3c;
                      while ((local_3c = pfVar10, cVar2 == '\0' && (pfVar12 == (float *)local_3c[2])
                             )) {
                        cVar2 = *(char *)((int)local_3c[1] + 0x11);
                        pfVar10 = (float *)local_3c[1];
                        pfVar12 = local_3c;
                      }
                    }
                  }
                } while (local_3c != local_120);
              }
              iVar6 = (int)ppfVar22 - (int)local_74 >> 2;
              ppfVar22 = local_74;
              for (; iVar6 != 0; iVar6 = iVar6 + -1) {
                FUN_00851470(&local_12c,ppfVar22);
                FUN_004ca160(local_12c,local_128);
                ppfVar22 = ppfVar22 + 1;
              }
              if (local_74 != (float **)0x0) {
                FUN_0089120c(local_74);
              }
              local_74 = (float **)0x0;
              local_70 = (float **)0x0;
              local_6c = (float **)0x0;
              local_8._0_1_ = 6;
              FUN_005540c0(*local_80,local_80);
              FUN_0089120c(local_80);
              local_8._0_1_ = 7;
              FUN_00535ac0(*local_c0,local_c0);
              FUN_0089120c(local_c0);
              local_8._0_1_ = 8;
              FUN_004ca160(*local_d0,local_d0);
              local_8._0_1_ = 1;
              FUN_0089120c(local_d0);
            }
            uVar5 = FUN_008533a0(local_a4);
            FUN_008529f0(local_100,local_160,uVar5);
            local_8._0_1_ = 9;
            FUN_004ca160(*local_a0,local_a0);
            local_8._0_1_ = 0;
            FUN_0089120c(local_a0);
            local_30 = (float *)((int)local_30 + 1);
            param_1 = local_34;
          } while (local_30 < local_11c);
        }
        pfVar12 = (float *)((*(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0)) / 0x24);
        if (pfVar12 != (float *)0x0) {
          iVar6 = *(int *)(param_1 + 0xc0);
          iVar13 = 0;
          local_2c = pfVar12;
          do {
            iVar21 = *(int *)(iVar13 + 0x20 + iVar6);
            local_30 = (float *)0x0;
            if (0 < iVar21) {
              pfVar12 = (float *)(iVar13 + 4 + iVar6);
              iVar8 = iVar21;
              do {
                iVar8 = iVar8 + -1;
                local_30 = (float *)((float)local_30 + *pfVar12);
                pfVar12 = pfVar12 + 2;
              } while (iVar8 != 0);
            }
            iVar8 = 0;
            if (0 < iVar21) {
              do {
                iVar21 = iVar13 + iVar8 * 8;
                iVar8 = iVar8 + 1;
                *(float *)(iVar21 + 4 + iVar6) = *(float *)(iVar21 + 4 + iVar6) / (float)local_30;
                iVar6 = *(int *)(param_1 + 0xc0);
              } while (iVar8 < *(int *)(iVar13 + 0x20 + iVar6));
            }
            iVar13 = iVar13 + 0x24;
            local_2c = (float *)((int)local_2c + -1);
          } while (local_2c != (float *)0x0);
        }
        local_dc = 0;
        pfVar12 = (float *)FUN_00891268(0x20);
        if (pfVar12 == (float *)0x0) {
          local_5c = (float *)0x0;
          std::exception::exception((exception *)local_f0,(char **)&local_5c);
          pppuVar24 = local_f0;
          local_f0[0] = std::bad_alloc::vftable;
        }
        else {
          *pfVar12 = (float)pfVar12;
          pfVar12[1] = (float)pfVar12;
          pfVar12[2] = (float)pfVar12;
          *(undefined1 *)(pfVar12 + 7) = 1;
          *(undefined1 *)((int)pfVar12 + 0x1d) = 1;
          local_8._0_1_ = 10;
          local_50 = 0.0;
          local_e0 = pfVar12;
          local_54 = (undefined4 *)FUN_00891268(0x14);
          if (local_54 != (undefined4 *)0x0) {
            *local_54 = local_54;
            local_54[1] = local_54;
            local_54[2] = local_54;
            *(undefined1 *)(local_54 + 4) = 1;
            *(undefined1 *)((int)local_54 + 0x11) = 1;
            local_8._0_1_ = 0xb;
            local_ac = 0;
            local_b0 = (float *)FUN_00891268(0x14);
            if (local_b0 == (float *)0x0) {
              local_8c = (char *)0x0;
              std::exception::exception((exception *)local_f0,&local_8c);
              local_f0[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(local_f0,&DAT_00c857a8);
            }
            *local_b0 = (float)local_b0;
            local_b0[1] = (float)local_b0;
            local_b0[2] = (float)local_b0;
            *(undefined1 *)(local_b0 + 4) = 1;
            *(undefined1 *)((int)local_b0 + 0x11) = 1;
            local_8 = CONCAT31(local_8._1_3_,0xc);
            local_90 = (float *)*local_fc;
            local_28 = local_fc;
            if (local_fc != local_90) {
              do {
                pfVar10 = local_28;
                FUN_00851420();
                local_2c = pfVar10;
                FUN_00852060();
                pfVar12 = (float *)local_2c[4];
                local_30 = pfVar12;
                local_2c = pfVar10;
                FUN_00852060();
                pfVar10 = *(float **)local_2c[4];
                local_2c = pfVar12;
                while (local_2c != pfVar10) {
                  FUN_007a3230();
                  FUN_008177b0(local_160,local_2c + 3);
                  FUN_007a3230();
                  local_2c = local_30;
                }
                local_2c = (float *)*local_e0;
                local_5c = local_e0;
                if (local_2c != local_e0) {
                  do {
                    pfVar12 = local_2c;
                    FUN_00851420();
                    FUN_00853470(*(undefined4 *)pfVar12[4],(undefined4 *)pfVar12[4],*local_b0,
                                 local_b0,&local_58,*local_54);
                    if (local_50 == 0.0) {
                      FUN_00851420();
                      uVar5 = *local_54;
                      puVar19 = local_14c;
                    }
                    else {
                      FUN_00851420();
                      uVar5 = *local_54;
                      puVar19 = local_17c;
                    }
                    local_48 = (float *)*local_b0;
                    FUN_00853550(puVar19,*(undefined4 *)pfVar12[4],(undefined4 *)pfVar12[4],local_48
                                 ,local_b0,&local_58,uVar5);
                    if ((local_50 != 0.0) && ((uint)local_50 <= (uint)local_88)) {
                      if (pfVar12 + 3 != &local_58) {
                        puVar16 = (undefined4 *)pfVar12[4];
                        pfVar12[4] = (float)local_54;
                        fVar1 = pfVar12[5];
                        pfVar12[5] = local_50;
                        local_54 = puVar16;
                        local_50 = fVar1;
                      }
                      goto LAB_0084f817;
                    }
                    FUN_00850c30();
                  } while (local_2c != local_5c);
                }
                uVar5 = FUN_008533a0(local_b4);
                FUN_008529f0(local_e4,local_168,uVar5);
LAB_0084f817:
                FUN_00852060();
              } while (local_28 != local_90);
            }
            iVar6 = local_34;
            local_30 = (float *)(local_34 + 0x6c);
            if (*(int *)(local_34 + 0x6c) != *(int *)(local_34 + 0x70)) {
              piVar15 = (int *)FUN_00858240(*(int *)(local_34 + 0x70),local_60);
              piVar11 = *(int **)(iVar6 + 0x70);
              for (piVar17 = piVar15; piVar17 != piVar11; piVar17 = piVar17 + 4) {
                if (*piVar17 != 0) {
                  FUN_0089120c(*piVar17);
                }
                *piVar17 = 0;
                piVar17[1] = 0;
                piVar17[2] = 0;
              }
              local_30[1] = (float)piVar15;
            }
            local_28 = (float *)*local_e0;
            local_48 = local_e0;
            if (local_28 != local_e0) {
              do {
                pfVar12 = local_28;
                local_84 = 0;
                local_80 = (int *)0x0;
                local_7c = 0;
                local_8 = CONCAT31(local_8._1_3_,0x11);
                fVar1 = local_28[5];
                FUN_005f7e40(fVar1);
                pfVar12 = (float *)pfVar12[4];
                local_2c = (float *)*pfVar12;
                if (local_2c != pfVar12) {
                  pfVar10 = (float *)(local_84 + -4 + (int)fVar1 * 4);
                  do {
                    *pfVar10 = local_2c[3];
                    pfVar10 = pfVar10 + -1;
                    FUN_0079c460();
                  } while (local_2c != pfVar12);
                }
                FUN_00850030();
                FUN_00850c30();
                if (local_84 != 0) {
                  FUN_0089120c(local_84);
                }
                local_84 = 0;
                local_80 = (int *)0x0;
                local_7c = 0;
              } while (local_28 != local_48);
            }
            local_8._0_1_ = 0x12;
            FUN_004ca160(*local_b0,local_b0);
            FUN_0089120c(local_b0);
            local_8._0_1_ = 0x13;
            FUN_004ca160(*local_54,local_54);
            FUN_0089120c(local_54);
            local_8 = CONCAT31(local_8._1_3_,0x14);
            FUN_00851360(*local_e0,local_e0);
            FUN_0089120c(local_e0);
            local_8._0_1_ = 0x15;
            local_8._1_3_ = 0;
            FUN_00851360(*local_fc,local_fc);
            FUN_0089120c(local_fc);
            goto LAB_0084fa95;
          }
          local_48 = (float *)0x0;
          ppfVar22 = &local_48;
LAB_0084f742:
          std::exception::exception((exception *)local_114,(char **)ppfVar22);
          pppuVar24 = local_114;
          local_114[0] = std::bad_alloc::vftable;
        }
      }
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(pppuVar24,&DAT_00c857a8);
    }
  }
LAB_0084fa95:
  ExceptionList = local_10;
  __security_check_cookie(local_24[3] ^ (uint)&stack0xfffffffc);
  return;
}


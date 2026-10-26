
/* WARNING: Type propagation algorithm not settling */

void FUN_00877c20(void *******param_1,int *param_2,void *******param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  void ******ppppppvVar4;
  void *******pppppppvVar5;
  undefined4 uVar6;
  void *******pppppppvVar7;
  uint uVar8;
  void ******ppppppvVar9;
  void *******pppppppvVar10;
  void ******ppppppvVar11;
  int iVar12;
  void *******pppppppvVar13;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  void ******local_b0;
  void ******local_ac;
  undefined4 local_a8;
  int *local_a4;
  void *****local_a0;
  void *******local_9c;
  void ******local_98;
  void ******local_94;
  undefined4 local_90;
  undefined4 local_8c;
  void *******local_88;
  void *******local_84;
  void ******local_80;
  void ******local_7c;
  void ******local_78;
  void *******local_70;
  void *******local_6c;
  void *******local_68;
  void *******local_60;
  void *******local_5c;
  void *******local_58;
  void *******local_54;
  void *******local_4c;
  void *******local_48;
  void *******local_44;
  void *******local_40;
  void *******local_38;
  void *******local_34 [2];
  void *******local_2c;
  void ******local_28;
  void *******local_24;
  void *******local_20;
  void *******local_1c [3];
  void ******local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0090ba18;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = local_1c + 3;
  iVar12 = *param_2;
  uVar3 = param_2[1] - iVar12 >> 2;
  if (1 < uVar3) {
    ppppppvVar11 = (void ******)0x0;
    ppppppvVar9 = (void ******)0x0;
    local_80 = (void ******)0x0;
    local_7c = (void ******)0x0;
    local_78 = (void ******)0x0;
    local_8 = 0;
    local_34[0] = (void *******)0x0;
    if (uVar3 != 0) {
      ppppppvVar11 = (void ******)0x0;
      do {
        local_1c[0] = (void *******)0x0;
        if (*(int *)(*(int *)(iVar12 + (int)local_34[0] * 4) + 8) != 0) {
          do {
            FUN_00843770(uVar2);
            for (ppppppvVar4 = ppppppvVar9; ppppppvVar4 != ppppppvVar11;
                ppppppvVar4 = ppppppvVar4 + 1) {
              if (*ppppppvVar4 == local_28) {
                if (ppppppvVar4 != ppppppvVar11) goto LAB_00877d89;
                break;
              }
            }
            if ((&local_28 < ppppppvVar11) && (ppppppvVar9 <= &local_28)) {
              local_24 = (void *******)((int)&local_28 - (int)ppppppvVar9 >> 2);
              if (ppppppvVar11 == local_78) {
                uVar3 = (int)ppppppvVar11 - (int)ppppppvVar9 >> 2;
                if (0x3ffffffe < uVar3) goto LAB_00877e01;
                uVar3 = uVar3 + 1;
                uVar8 = (int)local_78 - (int)ppppppvVar9 >> 2;
                if (uVar8 < uVar3) {
                  if (0x3fffffff - (uVar8 >> 1) < uVar8) {
                    uVar8 = 0;
                  }
                  else {
                    uVar8 = uVar8 + (uVar8 >> 1);
                  }
                  if (uVar8 < uVar3) {
                    uVar8 = uVar3;
                  }
                  FUN_00797980(uVar8);
                  ppppppvVar9 = local_80;
                  ppppppvVar11 = local_7c;
                }
              }
              if (ppppppvVar11 != (void ******)0x0) {
                *ppppppvVar11 = ppppppvVar9[(int)local_24];
              }
            }
            else {
              if (ppppppvVar11 == local_78) {
                uVar3 = (int)ppppppvVar11 - (int)ppppppvVar9 >> 2;
                if (0x3ffffffe < uVar3) goto LAB_00877e01;
                uVar3 = uVar3 + 1;
                uVar8 = (int)local_78 - (int)ppppppvVar9 >> 2;
                if (uVar8 < uVar3) {
                  if (0x3fffffff - (uVar8 >> 1) < uVar8) {
                    uVar8 = 0;
                  }
                  else {
                    uVar8 = uVar8 + (uVar8 >> 1);
                  }
                  if (uVar8 < uVar3) {
                    uVar8 = uVar3;
                  }
                  FUN_00797980(uVar8);
                  ppppppvVar9 = local_80;
                  ppppppvVar11 = local_7c;
                }
              }
              if (ppppppvVar11 != (void ******)0x0) {
                *ppppppvVar11 = local_28;
              }
            }
            ppppppvVar11 = ppppppvVar11 + 1;
            local_7c = ppppppvVar11;
LAB_00877d89:
            local_1c[0] = (void *******)((int)local_1c[0] + 1);
          } while (local_1c[0] < *(void ********)(*(int *)(*param_2 + (int)local_34[0] * 4) + 8));
        }
        iVar12 = *param_2;
        local_34[0] = (void *******)((int)local_34[0] + 1);
      } while (local_34[0] < (void *******)(param_2[1] - iVar12 >> 2));
    }
    local_4c = (void *******)((int)ppppppvVar11 - (int)ppppppvVar9 >> 2);
    local_1c[1] = (void *******)0x0;
    if (local_4c != (void *******)0x0) {
      do {
        local_24 = param_1;
        pppppppvVar10 = param_3[1];
        cVar1 = *(char *)((int)pppppppvVar10[1] + 0x15);
        local_2c = pppppppvVar10;
        pppppppvVar13 = pppppppvVar10[1];
        while (cVar1 == '\0') {
          if ((int)pppppppvVar13[3] < (int)local_80[(int)local_1c[1]]) {
            pppppppvVar5 = pppppppvVar13[2];
            pppppppvVar13 = local_2c;
          }
          else {
            pppppppvVar5 = *pppppppvVar13;
          }
          local_2c = pppppppvVar13;
          pppppppvVar13 = pppppppvVar5;
          cVar1 = *(char *)((int)pppppppvVar5 + 0x15);
        }
        if ((local_2c == pppppppvVar10) || ((int)local_80[(int)local_1c[1]] < (int)local_2c[3])) {
          local_34[0] = pppppppvVar10;
          pppppppvVar13 = local_34;
        }
        else {
          pppppppvVar13 = &local_2c;
        }
        if (*pppppppvVar13 != pppppppvVar10) {
          local_24 = param_3;
        }
        local_48 = (void *******)0x0;
        local_44 = (void *******)0x0;
        local_40 = (void *******)0x0;
        local_5c = (void *******)0x0;
        local_58 = (void *******)0x0;
        local_54 = (void *******)0x0;
        local_8 = CONCAT31(local_8._1_3_,2);
        iVar12 = *param_2;
        local_20 = (void *******)0x0;
        if (param_2[1] - iVar12 >> 2 != 0) {
          do {
            pppppppvVar13 = local_58;
            iVar12 = *(int *)(iVar12 + (int)local_20 * 4);
            local_2c = *(void ********)(iVar12 + 4);
            pppppppvVar10 = local_2c[1];
            cVar1 = *(char *)((int)pppppppvVar10 + 0x15);
            while (cVar1 == '\0') {
              if ((int)pppppppvVar10[3] < (int)local_80[(int)local_1c[1]]) {
                pppppppvVar5 = pppppppvVar10[2];
                pppppppvVar10 = local_2c;
              }
              else {
                pppppppvVar5 = *pppppppvVar10;
              }
              local_2c = pppppppvVar10;
              pppppppvVar10 = pppppppvVar5;
              cVar1 = *(char *)((int)pppppppvVar5 + 0x15);
            }
            pppppppvVar10 = *(void ********)(iVar12 + 4);
            if ((local_2c == pppppppvVar10) || ((int)local_80[(int)local_1c[1]] < (int)local_2c[3]))
            {
              local_60 = pppppppvVar10;
              pppppppvVar5 = &local_60;
            }
            else {
              pppppppvVar5 = &local_2c;
            }
            if (*pppppppvVar5 == pppppppvVar10) {
              pppppppvVar10 = local_24[1][1];
              cVar1 = *(char *)((int)pppppppvVar10 + 0x15);
              local_2c = local_24[1];
              while (cVar1 == '\0') {
                if ((int)pppppppvVar10[3] < (int)local_80[(int)local_1c[1]]) {
                  pppppppvVar5 = pppppppvVar10[2];
                  pppppppvVar10 = local_2c;
                }
                else {
                  pppppppvVar5 = *pppppppvVar10;
                }
                local_2c = pppppppvVar10;
                pppppppvVar10 = pppppppvVar5;
                cVar1 = *(char *)((int)pppppppvVar5 + 0x15);
              }
              pppppppvVar10 = local_24[1];
              if ((local_2c == pppppppvVar10) ||
                 ((int)local_80[(int)local_1c[1]] < (int)local_2c[3])) {
                local_38 = pppppppvVar10;
                pppppppvVar5 = &local_38;
              }
              else {
                pppppppvVar5 = &local_2c;
              }
              if (*pppppppvVar5 != pppppppvVar10) {
                local_28 = (*pppppppvVar5)[4];
              }
              local_1c[0] = local_20;
              if ((local_1c < local_44) && (local_48 <= local_1c)) {
                iVar12 = (int)local_1c - (int)local_48;
                if (local_44 == local_40) {
                  uVar2 = (int)local_44 - (int)local_48 >> 2;
                  if (0x3ffffffe < uVar2) goto LAB_00877e01;
                  uVar2 = uVar2 + 1;
                  uVar3 = (int)local_40 - (int)local_48 >> 2;
                  if (uVar3 < uVar2) {
                    if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                      uVar3 = 0;
                    }
                    else {
                      uVar3 = uVar3 + (uVar3 >> 1);
                    }
                    if (uVar3 < uVar2) {
                      uVar3 = uVar2;
                    }
                    FUN_00797980(uVar3);
                  }
                }
                if (local_44 != (void *******)0x0) {
                  *local_44 = local_48[iVar12 >> 2];
                }
                local_44 = local_44 + 1;
              }
              else {
                if (local_44 == local_40) {
                  uVar2 = (int)local_44 - (int)local_48 >> 2;
                  if (0x3ffffffe < uVar2) {
LAB_00877e01:
                    /* WARNING: Subroutine does not return */
                    FUN_0087db30("vector<T> too long");
                  }
                  uVar2 = uVar2 + 1;
                  uVar3 = (int)local_40 - (int)local_48 >> 2;
                  if (uVar3 < uVar2) {
                    if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                      uVar3 = 0;
                    }
                    else {
                      uVar3 = uVar3 + (uVar3 >> 1);
                    }
                    if (uVar3 < uVar2) {
                      uVar3 = uVar2;
                    }
                    FUN_00797980(uVar3);
                  }
                }
                if (local_44 != (void *******)0x0) {
                  *local_44 = local_20;
                }
                local_44 = local_44 + 1;
              }
            }
            else {
              local_28 = (*pppppppvVar5)[4];
            }
            if ((&local_28 < pppppppvVar13) && (local_5c <= &local_28)) {
              iVar12 = (int)&local_28 - (int)local_5c;
              if (pppppppvVar13 == local_54) {
                uVar2 = (int)pppppppvVar13 - (int)local_5c >> 2;
                if (0x3ffffffe < uVar2) goto LAB_00877e01;
                uVar2 = uVar2 + 1;
                uVar3 = (int)local_54 - (int)local_5c >> 2;
                if (uVar3 < uVar2) {
                  if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                    uVar3 = 0;
                  }
                  else {
                    uVar3 = uVar3 + (uVar3 >> 1);
                  }
                  if (uVar3 < uVar2) {
                    uVar3 = uVar2;
                  }
                  FUN_00797980(uVar3);
                  pppppppvVar13 = local_58;
                }
              }
              if (pppppppvVar13 != (void *******)0x0) {
                *pppppppvVar13 = local_5c[iVar12 >> 2];
              }
            }
            else {
              if (pppppppvVar13 == local_54) {
                uVar2 = (int)pppppppvVar13 - (int)local_5c >> 2;
                if (0x3ffffffe < uVar2) goto LAB_00877e01;
                uVar2 = uVar2 + 1;
                uVar3 = (int)local_54 - (int)local_5c >> 2;
                if (uVar3 < uVar2) {
                  if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                    uVar3 = 0;
                  }
                  else {
                    uVar3 = uVar3 + (uVar3 >> 1);
                  }
                  if (uVar3 < uVar2) {
                    uVar3 = uVar2;
                  }
                  FUN_00797980(uVar3);
                  pppppppvVar13 = local_58;
                }
              }
              if (pppppppvVar13 != (void *******)0x0) {
                *pppppppvVar13 = local_28;
              }
            }
            iVar12 = *param_2;
            local_20 = (void *******)((int)local_20 + 1);
            local_58 = pppppppvVar13 + 1;
          } while (local_20 < (void *******)(param_2[1] - iVar12 >> 2));
        }
        iVar12 = (int)local_58 - (int)local_5c >> 2;
        uVar2 = 0;
        if (iVar12 != 1) {
LAB_008780e2:
          if (local_5c[uVar2] == local_5c[uVar2 + 1]) goto code_r0x008780ef;
          local_1c[0] = (void *******)0x0;
          local_24 = (void *******)((int)local_44 - (int)local_48 >> 2);
          if (local_24 != (void *******)0x0) {
            do {
              local_a0 = local_80[(int)local_1c[1]];
              iVar12 = *(int *)((int)local_48[(int)local_1c[0]] * 4 + *param_2);
              local_9c = local_5c[(int)local_48[(int)local_1c[0]]];
              uVar6 = FUN_0057ef20();
              FUN_0057e850(iVar12,uVar6);
              local_1c[0] = (void *******)((int)local_1c[0] + 1);
              *(undefined4 *)(iVar12 + 0x114) = 1;
            } while (local_1c[0] < local_24);
          }
          local_24 = local_80[(int)local_1c[1]];
          FUN_005c2210(&local_a8,&local_24);
          FUN_005540c0(local_a8,local_a4);
          param_3[0x45] = (void ******)0x1;
          goto LAB_00878263;
        }
LAB_008780f4:
        iVar12 = *param_2;
        uVar2 = 0;
        if (param_2[1] - iVar12 >> 2 != 0) {
          do {
            iVar12 = *(int *)(iVar12 + uVar2 * 4);
            local_24 = local_80[(int)local_1c[1]];
            FUN_005c2210(&local_c0,&local_24);
            FUN_005540c0(local_c0,local_bc);
            *(undefined4 *)(iVar12 + 0x114) = 1;
            iVar12 = *param_2;
            uVar2 = uVar2 + 1;
          } while (uVar2 < (uint)(param_2[1] - iVar12 >> 2));
        }
        uVar6 = FUN_0057ef20();
        FUN_0057e850(param_3,uVar6);
        param_3[0x45] = (void ******)0x1;
LAB_00878263:
        if (local_5c != (void *******)0x0) {
          FUN_0089120c(local_5c);
        }
        local_5c = (void *******)0x0;
        local_58 = (void *******)0x0;
        local_54 = (void *******)0x0;
        if (local_48 != (void *******)0x0) {
          FUN_0089120c(local_48);
        }
        local_1c[1] = (void *******)((int)local_1c[1] + 1);
        local_48 = (void *******)0x0;
        local_44 = (void *******)0x0;
        local_40 = (void *******)0x0;
      } while (local_1c[1] < local_4c);
    }
    local_60 = (void *******)0x0;
    do {
      pppppppvVar10 = (void *******)0x0;
      pppppppvVar13 = (void *******)0x0;
      local_48 = (void *******)0x0;
      local_44 = (void *******)0x0;
      local_40 = (void *******)0x0;
      local_8 = CONCAT31(local_8._1_3_,3);
      iVar12 = *param_2;
      local_38 = (void *******)0x0;
      if (param_2[1] - iVar12 >> 2 != 0) {
        local_20 = (void *******)((int)local_60 << 4);
        do {
          iVar12 = *(int *)(iVar12 + (int)local_38 * 4);
          local_1c[0] = (void *******)0x0;
          if (0 < *(int *)(iVar12 + 0x18 + (int)local_20)) {
            do {
              FUN_008437e0(iVar12);
              pppppppvVar5 = local_34[0];
              for (; pppppppvVar10 != pppppppvVar13; pppppppvVar10 = pppppppvVar10 + 1) {
                if (*pppppppvVar10 == local_34[0]) {
                  if (pppppppvVar10 != pppppppvVar13) {
                    if ((local_34 < pppppppvVar13) && (local_48 <= local_34)) {
                      iVar12 = (int)local_34 - (int)local_48;
                      if (pppppppvVar13 == local_40) {
                        uVar2 = (int)pppppppvVar13 - (int)local_48 >> 2;
                        if (0x3ffffffe < uVar2) goto LAB_00877e01;
                        uVar2 = uVar2 + 1;
                        uVar3 = (int)local_40 - (int)local_48 >> 2;
                        if (uVar3 < uVar2) {
                          if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                            uVar3 = 0;
                          }
                          else {
                            uVar3 = uVar3 + (uVar3 >> 1);
                          }
                          if (uVar3 < uVar2) {
                            uVar3 = uVar2;
                          }
                          FUN_00797980(uVar3);
                          pppppppvVar13 = local_44;
                        }
                      }
                      if (pppppppvVar13 != (void *******)0x0) {
                        *pppppppvVar13 = local_48[iVar12 >> 2];
                      }
                    }
                    else {
                      if (pppppppvVar13 == local_40) {
                        uVar2 = (int)pppppppvVar13 - (int)local_48 >> 2;
                        if (0x3ffffffe < uVar2) goto LAB_00877e01;
                        uVar2 = uVar2 + 1;
                        uVar3 = (int)local_40 - (int)local_48 >> 2;
                        if (uVar3 < uVar2) {
                          if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                            uVar3 = 0;
                          }
                          else {
                            uVar3 = uVar3 + (uVar3 >> 1);
                          }
                          if (uVar3 < uVar2) {
                            uVar3 = uVar2;
                          }
                          FUN_00797980(uVar3);
                          pppppppvVar13 = local_44;
                        }
                      }
                      if (pppppppvVar13 != (void *******)0x0) {
                        *pppppppvVar13 = pppppppvVar5;
                      }
                    }
                    pppppppvVar13 = pppppppvVar13 + 1;
                    local_44 = pppppppvVar13;
                  }
                  break;
                }
              }
              iVar12 = *(int *)(*param_2 + (int)local_38 * 4);
              local_1c[0] = (void *******)((int)local_1c[0] + 1);
              pppppppvVar10 = local_48;
            } while ((int)local_1c[0] < *(int *)(iVar12 + 0x18 + (int)local_20));
          }
          iVar12 = *param_2;
          local_38 = (void *******)((int)local_38 + 1);
        } while (local_38 < (void *******)(param_2[1] - iVar12 >> 2));
      }
      local_34[1] = (void *******)((int)pppppppvVar13 - (int)pppppppvVar10 >> 2);
      local_1c[1] = (void *******)0x0;
      if (local_34[1] != (void *******)0x0) {
        local_20 = (void *******)((int)local_60 * 0x10);
        local_24 = (void *******)((int)(local_20 + 4) + (int)param_3);
        local_a4 = (int *)((int)(local_20 + 5) + (int)param_3);
        do {
          local_1c[0] = param_1;
          pppppppvVar10 = local_24[1][1];
          cVar1 = *(char *)((int)pppppppvVar10 + 0x15);
          local_4c = local_24[1];
          while (cVar1 == '\0') {
            if ((int)pppppppvVar10[3] < (int)local_48[(int)local_1c[1]]) {
              pppppppvVar13 = pppppppvVar10[2];
              pppppppvVar10 = local_4c;
            }
            else {
              pppppppvVar13 = *pppppppvVar10;
            }
            local_4c = pppppppvVar10;
            pppppppvVar10 = pppppppvVar13;
            cVar1 = *(char *)((int)pppppppvVar13 + 0x15);
          }
          if ((local_4c == local_24[1]) || ((int)local_48[(int)local_1c[1]] < (int)local_4c[3])) {
            local_88 = local_24[1];
            pppppppvVar10 = &local_88;
          }
          else {
            pppppppvVar10 = &local_4c;
          }
          if (*pppppppvVar10 != (void ******)*local_a4) {
            local_28 = (*pppppppvVar10)[4];
            local_1c[0] = param_3;
          }
          pppppppvVar10 = (void *******)0x0;
          local_5c = (void *******)0x0;
          local_58 = (void *******)0x0;
          local_54 = (void *******)0x0;
          local_70 = (void *******)0x0;
          local_6c = (void *******)0x0;
          local_68 = (void *******)0x0;
          local_8 = CONCAT31(local_8._1_3_,5);
          iVar12 = *param_2;
          local_38 = (void *******)0x0;
          if (param_2[1] - iVar12 >> 2 != 0) {
            do {
              pppppppvVar5 = local_6c;
              iVar12 = *(int *)(iVar12 + (int)local_38 * 4);
              local_4c = *(void ********)(iVar12 + 0x14 + (int)local_20);
              pppppppvVar13 = local_4c[1];
              cVar1 = *(char *)((int)pppppppvVar13 + 0x15);
              while (cVar1 == '\0') {
                if ((int)pppppppvVar13[3] < (int)local_48[(int)local_1c[1]]) {
                  pppppppvVar7 = pppppppvVar13[2];
                  pppppppvVar13 = local_4c;
                }
                else {
                  pppppppvVar7 = *pppppppvVar13;
                }
                local_4c = pppppppvVar13;
                pppppppvVar13 = pppppppvVar7;
                cVar1 = *(char *)((int)pppppppvVar7 + 0x15);
              }
              pppppppvVar13 = *(void ********)(iVar12 + 0x14 + (int)local_20);
              if ((local_4c == pppppppvVar13) ||
                 ((int)local_48[(int)local_1c[1]] < (int)local_4c[3])) {
                local_9c = pppppppvVar13;
                pppppppvVar13 = &local_9c;
              }
              else {
                pppppppvVar13 = &local_4c;
              }
              if (*pppppppvVar13 == *(void *******)(iVar12 + 0x14 + (int)local_20)) {
                pppppppvVar13 = (*(void ********)((int)(local_20 + 5) + (int)local_1c[0]))[1];
                cVar1 = *(char *)((int)pppppppvVar13 + 0x15);
                local_4c = *(void ********)((int)(local_20 + 5) + (int)local_1c[0]);
                while (cVar1 == '\0') {
                  if ((int)pppppppvVar13[3] < (int)local_48[(int)local_1c[1]]) {
                    pppppppvVar7 = pppppppvVar13[2];
                    pppppppvVar13 = local_4c;
                  }
                  else {
                    pppppppvVar7 = *pppppppvVar13;
                  }
                  local_4c = pppppppvVar13;
                  pppppppvVar13 = pppppppvVar7;
                  cVar1 = *(char *)((int)pppppppvVar7 + 0x15);
                }
                if ((local_4c == *(void ********)((int)(local_20 + 5) + (int)local_1c[0])) ||
                   ((int)local_48[(int)local_1c[1]] < (int)local_4c[3])) {
                  local_84 = *(void ********)((int)(local_20 + 5) + (int)local_1c[0]);
                  pppppppvVar13 = &local_84;
                }
                else {
                  pppppppvVar13 = &local_4c;
                }
                if (*pppppppvVar13 != *(void *******)((int)(local_20 + 5) + (int)local_1c[0])) {
                  local_28 = (*pppppppvVar13)[4];
                }
                local_2c = local_38;
                if ((&local_2c < pppppppvVar10) && (local_5c <= &local_2c)) {
                  iVar12 = (int)&local_2c - (int)local_5c;
                  if (local_58 == local_54) {
                    uVar2 = (int)local_58 - (int)local_5c >> 2;
                    if (0x3ffffffe < uVar2) goto LAB_00877e01;
                    uVar2 = uVar2 + 1;
                    uVar3 = (int)local_54 - (int)local_5c >> 2;
                    if (uVar3 < uVar2) {
                      if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                        uVar3 = 0;
                      }
                      else {
                        uVar3 = uVar3 + (uVar3 >> 1);
                      }
                      if (uVar3 < uVar2) {
                        uVar3 = uVar2;
                      }
                      FUN_00797980(uVar3);
                    }
                  }
                  if (local_58 != (void *******)0x0) {
                    *local_58 = local_5c[iVar12 >> 2];
                  }
                  pppppppvVar10 = local_58 + 1;
                  local_58 = pppppppvVar10;
                }
                else {
                  if (pppppppvVar10 == local_54) {
                    uVar2 = (int)pppppppvVar10 - (int)local_5c >> 2;
                    if (0x3ffffffe < uVar2) goto LAB_00877e01;
                    uVar2 = uVar2 + 1;
                    uVar3 = (int)local_54 - (int)local_5c >> 2;
                    if (uVar3 < uVar2) {
                      if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                        uVar3 = 0;
                      }
                      else {
                        uVar3 = uVar3 + (uVar3 >> 1);
                      }
                      if (uVar3 < uVar2) {
                        uVar3 = uVar2;
                      }
                      FUN_00797980(uVar3);
                      pppppppvVar10 = local_58;
                    }
                  }
                  if (pppppppvVar10 != (void *******)0x0) {
                    *pppppppvVar10 = local_38;
                  }
                  pppppppvVar10 = pppppppvVar10 + 1;
                  local_58 = pppppppvVar10;
                }
              }
              else {
                local_28 = (*pppppppvVar13)[4];
              }
              if ((&local_28 < pppppppvVar5) && (local_70 <= &local_28)) {
                iVar12 = (int)&local_28 - (int)local_70;
                if (pppppppvVar5 == local_68) {
                  uVar2 = (int)pppppppvVar5 - (int)local_70 >> 2;
                  if (0x3ffffffe < uVar2) goto LAB_00877e01;
                  uVar2 = uVar2 + 1;
                  uVar3 = (int)local_68 - (int)local_70 >> 2;
                  if (uVar3 < uVar2) {
                    if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                      uVar3 = 0;
                    }
                    else {
                      uVar3 = uVar3 + (uVar3 >> 1);
                    }
                    if (uVar3 < uVar2) {
                      uVar3 = uVar2;
                    }
                    FUN_00797980(uVar3);
                    pppppppvVar5 = local_6c;
                  }
                }
                pppppppvVar10 = local_58;
                if (pppppppvVar5 != (void *******)0x0) {
                  *pppppppvVar5 = local_70[iVar12 >> 2];
                }
              }
              else {
                if (pppppppvVar5 == local_68) {
                  uVar2 = (int)pppppppvVar5 - (int)local_70 >> 2;
                  if (0x3ffffffe < uVar2) goto LAB_00877e01;
                  uVar2 = uVar2 + 1;
                  uVar3 = (int)local_68 - (int)local_70 >> 2;
                  if (uVar3 < uVar2) {
                    if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                      uVar3 = 0;
                    }
                    else {
                      uVar3 = uVar3 + (uVar3 >> 1);
                    }
                    if (uVar3 < uVar2) {
                      uVar3 = uVar2;
                    }
                    FUN_00797980(uVar3);
                    pppppppvVar5 = local_6c;
                  }
                }
                if (pppppppvVar5 != (void *******)0x0) {
                  *pppppppvVar5 = local_28;
                }
              }
              iVar12 = *param_2;
              local_38 = (void *******)((int)local_38 + 1);
              local_6c = pppppppvVar5 + 1;
            } while (local_38 < (void *******)(param_2[1] - iVar12 >> 2));
          }
          iVar12 = (int)local_6c - (int)local_70 >> 2;
          uVar2 = 0;
          if (iVar12 != 1) {
LAB_008787b0:
            if (local_70[uVar2] == local_70[uVar2 + 1]) goto code_r0x008787bd;
            pppppppvVar13 = (void *******)0x0;
            local_2c = (void *******)((int)pppppppvVar10 - (int)local_5c >> 2);
            if (local_2c != (void *******)0x0) {
              do {
                local_94 = local_70[(int)local_5c[(int)pppppppvVar13]];
                local_98 = local_48[(int)local_1c[1]];
                local_4c = *(void ********)((int)local_5c[(int)pppppppvVar13] * 4 + *param_2);
                iVar12 = (int)(local_4c + 4) + (int)local_20;
                uVar6 = FUN_0057ef20();
                FUN_0057e850(iVar12,uVar6);
                pppppppvVar13 = (void *******)((int)pppppppvVar13 + 1);
                local_4c[0x45] = (void *****)0x1;
              } while (pppppppvVar13 < local_2c);
            }
            local_4c = local_48[(int)local_1c[1]];
            FUN_005c2210(&local_90,&local_4c);
            FUN_005540c0(local_90,local_8c);
            param_3[0x45] = (void ******)0x1;
            pppppppvVar10 = local_70;
            goto LAB_0087893e;
          }
LAB_008787c2:
          iVar12 = *param_2;
          uVar2 = 0;
          if (param_2[1] - iVar12 >> 2 != 0) {
            do {
              local_4c = local_48[(int)local_1c[1]];
              iVar12 = *(int *)(iVar12 + uVar2 * 4);
              FUN_005c2210(&local_b8,&local_4c);
              FUN_005540c0(local_b8,local_b4);
              *(undefined4 *)(iVar12 + 0x114) = 1;
              iVar12 = *param_2;
              uVar2 = uVar2 + 1;
            } while (uVar2 < (uint)(param_2[1] - iVar12 >> 2));
          }
          pppppppvVar13 = local_24;
          pppppppvVar10 = local_70;
          local_ac = *local_70;
          local_b0 = local_48[(int)local_1c[1]];
          uVar6 = FUN_0057ef20();
          FUN_0057e850(pppppppvVar13,uVar6);
          param_3[0x45] = (void ******)0x1;
LAB_0087893e:
          if (pppppppvVar10 != (void *******)0x0) {
            FUN_0089120c(pppppppvVar10);
          }
          local_70 = (void *******)0x0;
          local_6c = (void *******)0x0;
          local_68 = (void *******)0x0;
          if (local_5c != (void *******)0x0) {
            FUN_0089120c(local_5c);
          }
          local_1c[1] = (void *******)((int)local_1c[1] + 1);
          local_5c = (void *******)0x0;
          local_58 = (void *******)0x0;
          local_54 = (void *******)0x0;
        } while (local_1c[1] < local_34[1]);
      }
      if (local_48 != (void *******)0x0) {
        FUN_0089120c(local_48);
      }
      local_60 = (void *******)((int)local_60 + 1);
      local_48 = (void *******)0x0;
      local_44 = (void *******)0x0;
      local_40 = (void *******)0x0;
    } while (local_60 < (void *******)0x8);
    local_38 = (void *******)0x0;
    local_1c[1] = (void *******)0x90;
    do {
      pppppppvVar10 = (void *******)0x0;
      pppppppvVar13 = (void *******)0x0;
      local_70 = (void *******)0x0;
      local_6c = (void *******)0x0;
      local_68 = (void *******)0x0;
      local_8 = CONCAT31(local_8._1_3_,6);
      iVar12 = *param_2;
      local_2c = (void *******)0x0;
      if (param_2[1] - iVar12 >> 2 != 0) {
        do {
          iVar12 = *(int *)(iVar12 + (int)local_2c * 4);
          local_24 = (void *******)0x0;
          if (*(int *)((int)local_1c[1] + iVar12 + 8) != 0) {
            do {
              FUN_00843850(iVar12);
              pppppppvVar7 = local_1c[0];
              for (pppppppvVar5 = pppppppvVar10; pppppppvVar5 != pppppppvVar13;
                  pppppppvVar5 = pppppppvVar5 + 1) {
                if (*pppppppvVar5 == local_1c[0]) {
                  if (pppppppvVar5 != pppppppvVar13) {
                    if ((local_1c < pppppppvVar13) && (pppppppvVar10 <= local_1c)) {
                      local_34[1] = (void *******)((int)local_1c - (int)pppppppvVar10 >> 2);
                      if (pppppppvVar13 == local_68) {
                        uVar2 = (int)pppppppvVar13 - (int)pppppppvVar10 >> 2;
                        if (0x3ffffffe < uVar2) goto LAB_00877e01;
                        uVar2 = uVar2 + 1;
                        uVar3 = (int)local_68 - (int)pppppppvVar10 >> 2;
                        if (uVar3 < uVar2) {
                          if (0x3fffffff - (uVar3 >> 1) < uVar3) {
                            uVar3 = 0;
                          }
                          else {
                            uVar3 = uVar3 + (uVar3 >> 1);
                          }
                          if (uVar3 < uVar2) {
                            uVar3 = uVar2;
                          }
                          FUN_00797980(uVar3);
                          pppppppvVar10 = local_70;
                          pppppppvVar13 = local_6c;
                        }
                      }
                      if (pppppppvVar13 != (void *******)0x0) {
                        *pppppppvVar13 = pppppppvVar10[(int)local_34[1]];
                      }
                    }
                    else {
                      if (pppppppvVar13 == local_68) {
                        FUN_00797930();
                        pppppppvVar10 = local_70;
                        pppppppvVar13 = local_6c;
                      }
                      if (pppppppvVar13 != (void *******)0x0) {
                        *pppppppvVar13 = pppppppvVar7;
                      }
                    }
                    pppppppvVar13 = pppppppvVar13 + 1;
                    local_6c = pppppppvVar13;
                  }
                  break;
                }
              }
              iVar12 = *(int *)(*param_2 + (int)local_2c * 4);
              local_24 = (void *******)((int)local_24 + 1);
            } while (local_24 < *(void ********)((int)local_1c[1] + iVar12 + 8));
          }
          iVar12 = *param_2;
          local_2c = (void *******)((int)local_2c + 1);
        } while (local_2c < (void *******)(param_2[1] - iVar12 >> 2));
      }
      ppppppvVar9 = (void ******)((int)pppppppvVar13 - (int)pppppppvVar10 >> 2);
      if (ppppppvVar9 != (void ******)0x0) {
        local_24 = (void *******)((int)local_1c[1] + (int)param_3);
        local_20 = local_70;
        local_28 = ppppppvVar9;
        do {
          pppppppvVar10 = local_24;
          local_34[1] = *local_20;
          local_2c = param_1;
          FUN_008438c0(local_34 + 1);
          pppppppvVar13 = local_1c[1];
          if (local_84 != pppppppvVar10[1]) {
            local_60 = local_84[4];
            local_2c = param_3;
          }
          local_48 = (void *******)0x0;
          local_44 = (void *******)0x0;
          local_40 = (void *******)0x0;
          local_5c = (void *******)0x0;
          local_58 = (void *******)0x0;
          local_54 = (void *******)0x0;
          local_8 = CONCAT31(local_8._1_3_,8);
          iVar12 = *param_2;
          local_34[0] = (void *******)0x0;
          if (param_2[1] - iVar12 >> 2 != 0) {
            do {
              iVar12 = *(int *)(iVar12 + (int)local_34[0] * 4);
              pppppppvVar10 = *local_20;
              local_34[1] = pppppppvVar10;
              FUN_008438c0(local_34 + 1);
              pppppppvVar5 = local_2c;
              if (local_9c == *(void ********)((int)pppppppvVar13 + iVar12 + 4)) {
                local_34[1] = pppppppvVar10;
                FUN_008438c0(local_34 + 1);
                if (local_a4 != *(int **)((int)(pppppppvVar13 + 1) + (int)pppppppvVar5)) {
                  local_60 = (void *******)local_a4[4];
                }
                local_34[1] = local_34[0];
                FUN_004a8680();
              }
              else {
                local_60 = local_9c[4];
              }
              FUN_004a8680();
              iVar12 = *param_2;
              local_34[0] = (void *******)((int)local_34[0] + 1);
            } while (local_34[0] < (void *******)(param_2[1] - iVar12 >> 2));
          }
          iVar12 = (int)local_58 - (int)local_5c >> 2;
          uVar2 = 0;
          if (iVar12 != 1) {
LAB_00878c30:
            if (local_5c[uVar2] == local_5c[uVar2 + 1]) goto code_r0x00878c3d;
            pppppppvVar10 = (void *******)0x0;
            local_88 = (void *******)((int)local_44 - (int)local_48 >> 2);
            if (local_88 != (void *******)0x0) {
              do {
                iVar12 = *(int *)((int)local_48 + (int)pppppppvVar10 * 4);
                local_b0 = *local_20;
                local_ac = local_5c[iVar12];
                local_34[1] = *(void ********)(iVar12 * 4 + *param_2);
                iVar12 = (int)local_1c[1] + (int)local_34[1];
                uVar6 = FUN_0057ef20();
                FUN_0057e850(iVar12,uVar6);
                pppppppvVar10 = (void *******)((int)pppppppvVar10 + 1);
                *(undefined4 *)((int)local_34[1] + 0x114) = 1;
              } while (pppppppvVar10 < local_88);
            }
            local_34[1] = *local_20;
            FUN_005c2210(&local_b8,local_34 + 1);
            FUN_005540c0(local_b8,local_b4);
            param_3[0x45] = (void ******)0x1;
            pppppppvVar10 = local_5c;
            goto LAB_00878dbb;
          }
LAB_00878c42:
          iVar12 = *param_2;
          uVar2 = 0;
          if (param_2[1] - iVar12 >> 2 != 0) {
            do {
              local_34[1] = *local_20;
              iVar12 = *(int *)(iVar12 + uVar2 * 4);
              FUN_005c2210(&local_90,local_34 + 1);
              FUN_005540c0(local_90,local_8c);
              *(undefined4 *)(iVar12 + 0x114) = 1;
              iVar12 = *param_2;
              uVar2 = uVar2 + 1;
            } while (uVar2 < (uint)(param_2[1] - iVar12 >> 2));
          }
          pppppppvVar13 = local_24;
          pppppppvVar10 = local_5c;
          local_94 = *local_5c;
          local_98 = *local_20;
          uVar6 = FUN_0057ef20();
          FUN_0057e850(pppppppvVar13,uVar6);
          param_3[0x45] = (void ******)0x1;
LAB_00878dbb:
          if (pppppppvVar10 != (void *******)0x0) {
            FUN_0089120c(pppppppvVar10);
          }
          local_5c = (void *******)0x0;
          local_58 = (void *******)0x0;
          local_54 = (void *******)0x0;
          if (local_48 != (void *******)0x0) {
            FUN_0089120c(local_48);
          }
          local_20 = local_20 + 1;
          local_28 = (void ******)((int)local_28 + -1);
          local_48 = (void *******)0x0;
          local_44 = (void *******)0x0;
          local_40 = (void *******)0x0;
        } while (local_28 != (void ******)0x0);
      }
      local_8 = local_8 & 0xffffff00;
      if (local_70 != (void *******)0x0) {
        FUN_0089120c(local_70);
      }
      local_38 = (void *******)((int)local_38 + 1);
      local_1c[1] = local_1c[1] + 4;
      local_70 = (void *******)0x0;
      local_6c = (void *******)0x0;
      local_68 = (void *******)0x0;
    } while (local_1c[1] < (void *******)0x110);
    if (local_80 != (void ******)0x0) {
      FUN_0089120c(local_80);
    }
  }
  ExceptionList = local_10;
  return;
code_r0x008780ef:
  uVar2 = uVar2 + 1;
  if (iVar12 - 1U <= uVar2) goto LAB_008780f4;
  goto LAB_008780e2;
code_r0x008787bd:
  uVar2 = uVar2 + 1;
  if (iVar12 - 1U <= uVar2) goto LAB_008787c2;
  goto LAB_008787b0;
code_r0x00878c3d:
  uVar2 = uVar2 + 1;
  if (iVar12 - 1U <= uVar2) goto LAB_00878c42;
  goto LAB_00878c30;
}



void FUN_008266f0(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  char *pcVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined2 local_b4;
  undefined1 local_b0;
  undefined1 local_ac;
  int local_a4;
  undefined4 local_a0;
  undefined1 local_9c [4];
  undefined1 local_98 [4];
  undefined1 local_94 [4];
  undefined **local_90 [19];
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925dab;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar5;
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    iVar6 = FUN_0072e360(uVar5);
    if (iVar6 == 0) {
      local_8 = 0xffffffff;
      FUN_00407fb0();
    }
    else {
      iVar6 = FUN_0072e360(uVar5);
      if (iVar6 != 0) {
        iVar6 = FUN_0072e360(uVar5);
        while (iVar6 != 0) {
          iVar6 = FUN_007300a0("ClassID");
          if (iVar6 == 0) {
LAB_00826837:
            local_b0 = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar6 + 0x30);
            if (0xf < *(uint *)(iVar6 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00826837;
            local_b0 = FUN_008917b4(puVar7);
          }
          local_a4 = FUN_0072e360();
          if (local_a4 != 0) {
            local_9c[0] = local_b0;
            do {
              for (iVar6 = *(int *)(local_a4 + 0x94); iVar6 != local_a4 + 0x44;
                  iVar6 = *(int *)(iVar6 + 0x50)) {
                pcVar11 = (char *)(iVar6 + 0x14);
                if (0xf < *(uint *)(iVar6 + 0x28)) {
                  pcVar11 = *(char **)pcVar11;
                }
                iVar8 = __stricmp(pcVar11,"RankID");
                if (iVar8 == 0) {
                  if (iVar6 != 0) {
                    puVar7 = (undefined4 *)(iVar6 + 0x30);
                    if (0xf < *(uint *)(iVar6 + 0x44)) {
                      puVar7 = (undefined4 *)*puVar7;
                    }
                    if (puVar7 != (undefined4 *)0x0) {
                      uVar4 = FUN_008917b4(puVar7);
                      goto LAB_008268ae;
                    }
                  }
                  break;
                }
              }
              uVar4 = 0;
LAB_008268ae:
              for (iVar6 = *(int *)(local_a4 + 0x94); iVar6 != local_a4 + 0x44;
                  iVar6 = *(int *)(iVar6 + 0x50)) {
                pcVar11 = (char *)(iVar6 + 0x14);
                if (0xf < *(uint *)(iVar6 + 0x28)) {
                  pcVar11 = *(char **)pcVar11;
                }
                iVar8 = __stricmp(pcVar11,"Money");
                if (iVar8 == 0) {
                  if (iVar6 != 0) {
                    puVar7 = (undefined4 *)(iVar6 + 0x30);
                    if (0xf < *(uint *)(iVar6 + 0x44)) {
                      puVar7 = (undefined4 *)*puVar7;
                    }
                    if (puVar7 != (undefined4 *)0x0) {
                      uVar13 = FUN_008917b4(puVar7);
                      goto LAB_008268df;
                    }
                  }
                  break;
                }
              }
              uVar13 = 0;
LAB_008268df:
              local_94[0] = uVar4;
              FUN_00827050(param_1,local_9c);
              puVar7 = (undefined4 *)FUN_008271c0();
              *puVar7 = 1;
              puVar7[1] = uVar13;
              iVar6 = FUN_0072e360();
              if (iVar6 != 0) {
                local_94[0] = local_b0;
                local_98[0] = uVar4;
                do {
                  for (iVar8 = *(int *)(iVar6 + 0x94); iVar8 != iVar6 + 0x44;
                      iVar8 = *(int *)(iVar8 + 0x50)) {
                    pcVar11 = (char *)(iVar8 + 0x14);
                    if (0xf < *(uint *)(iVar8 + 0x28)) {
                      pcVar11 = *(char **)pcVar11;
                    }
                    iVar9 = __stricmp(pcVar11,"ItemID");
                    if (iVar9 == 0) {
                      if (iVar8 != 0) {
                        puVar7 = (undefined4 *)(iVar8 + 0x30);
                        if (0xf < *(uint *)(iVar8 + 0x44)) {
                          puVar7 = (undefined4 *)*puVar7;
                        }
                        if (puVar7 != (undefined4 *)0x0) {
                          local_b4 = FUN_008917b4(puVar7);
                          goto LAB_008269e9;
                        }
                      }
                      break;
                    }
                  }
                  local_b4 = 0;
LAB_008269e9:
                  for (iVar8 = *(int *)(iVar6 + 0x94); iVar8 != iVar6 + 0x44;
                      iVar8 = *(int *)(iVar8 + 0x50)) {
                    pcVar11 = (char *)(iVar8 + 0x14);
                    if (0xf < *(uint *)(iVar8 + 0x28)) {
                      pcVar11 = *(char **)pcVar11;
                    }
                    iVar9 = __stricmp(pcVar11,"Qty");
                    if (iVar9 == 0) {
                      if (iVar8 != 0) {
                        puVar7 = (undefined4 *)(iVar8 + 0x30);
                        if (0xf < *(uint *)(iVar8 + 0x44)) {
                          puVar7 = (undefined4 *)*puVar7;
                        }
                        if (puVar7 != (undefined4 *)0x0) {
                          uVar4 = FUN_008917b4(puVar7);
                          goto LAB_00826a19;
                        }
                      }
                      break;
                    }
                  }
                  uVar4 = 0;
LAB_00826a19:
                  FUN_00827050(param_1,local_94);
                  puVar10 = (undefined4 *)FUN_008271c0();
                  puVar1 = puVar10 + 2;
                  *puVar10 = 1;
                  puVar7 = (undefined4 *)puVar10[3];
                  local_a0._0_3_ = CONCAT12(uVar4,local_b4);
                  if (&local_a0 < puVar7) {
                    puVar2 = (undefined4 *)*puVar1;
                    if (&local_a0 < puVar2) goto LAB_00826b30;
                    if (puVar7 == (undefined4 *)puVar10[4]) {
                      uVar5 = (int)puVar7 - (int)puVar2 >> 2;
                      if (0x3ffffffe < uVar5) goto LAB_00826c57;
                      uVar5 = uVar5 + 1;
                      uVar12 = (int)puVar10[4] - (int)puVar2 >> 2;
                      if (uVar12 < uVar5) {
                        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                          uVar12 = 0;
                        }
                        else {
                          uVar12 = uVar12 + (uVar12 >> 1);
                        }
                        if (uVar12 < uVar5) {
                          uVar12 = uVar5;
                        }
                        FUN_0083f320(uVar12);
                      }
                    }
                    if ((undefined4 *)puVar10[3] != (undefined4 *)0x0) {
                      *(undefined4 *)puVar10[3] =
                           *(undefined4 *)(*puVar1 + ((int)&local_a0 - (int)puVar2 >> 2) * 4);
                    }
                  }
                  else {
LAB_00826b30:
                    if (puVar7 == (undefined4 *)puVar10[4]) {
                      uVar5 = (int)((int)puVar7 - *puVar1) >> 2;
                      if (0x3ffffffe < uVar5) goto LAB_00826c57;
                      uVar5 = uVar5 + 1;
                      uVar12 = (int)((int)puVar10[4] - *puVar1) >> 2;
                      if (uVar12 < uVar5) {
                        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                          uVar12 = 0;
                        }
                        else {
                          uVar12 = uVar12 + (uVar12 >> 1);
                        }
                        if (uVar12 < uVar5) {
                          uVar12 = uVar5;
                        }
                        FUN_0083f320(uVar12);
                      }
                    }
                    if ((undefined4 *)puVar10[3] != (undefined4 *)0x0) {
                      *(undefined4 *)puVar10[3] = local_a0;
                    }
                  }
                  puVar10[3] = puVar10[3] + 4;
                  iVar6 = FUN_0072e3c0();
                } while (iVar6 != 0);
              }
              local_a4 = FUN_0072e3c0();
            } while (local_a4 != 0);
          }
          iVar6 = FUN_0072e3c0();
        }
      }
      iVar6 = FUN_0072e360();
      if (iVar6 != 0) {
        iVar6 = FUN_0072e360();
        while (iVar6 != 0) {
          iVar6 = FUN_007300a0("ClassID");
          if (iVar6 == 0) {
LAB_00826c61:
            local_ac = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar6 + 0x30);
            if (0xf < *(uint *)(iVar6 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00826c61;
            local_ac = FUN_008917b4(puVar7);
          }
          local_a4 = FUN_0072e360();
          if (local_a4 != 0) {
            local_98[0] = local_ac;
            do {
              for (iVar6 = *(int *)(local_a4 + 0x94); iVar6 != local_a4 + 0x44;
                  iVar6 = *(int *)(iVar6 + 0x50)) {
                pcVar11 = (char *)(iVar6 + 0x14);
                if (0xf < *(uint *)(iVar6 + 0x28)) {
                  pcVar11 = *(char **)pcVar11;
                }
                iVar8 = __stricmp(pcVar11,"RankID");
                if (iVar8 == 0) {
                  if (iVar6 != 0) {
                    puVar7 = (undefined4 *)(iVar6 + 0x30);
                    if (0xf < *(uint *)(iVar6 + 0x44)) {
                      puVar7 = (undefined4 *)*puVar7;
                    }
                    if (puVar7 != (undefined4 *)0x0) {
                      uVar4 = FUN_008917b4(puVar7);
                      goto LAB_00826cd2;
                    }
                  }
                  break;
                }
              }
              uVar4 = 0;
LAB_00826cd2:
              for (iVar6 = *(int *)(local_a4 + 0x94); iVar6 != local_a4 + 0x44;
                  iVar6 = *(int *)(iVar6 + 0x50)) {
                pcVar11 = (char *)(iVar6 + 0x14);
                if (0xf < *(uint *)(iVar6 + 0x28)) {
                  pcVar11 = *(char **)pcVar11;
                }
                iVar8 = __stricmp(pcVar11,"Money");
                if (iVar8 == 0) {
                  if (iVar6 != 0) {
                    puVar7 = (undefined4 *)(iVar6 + 0x30);
                    if (0xf < *(uint *)(iVar6 + 0x44)) {
                      puVar7 = (undefined4 *)*puVar7;
                    }
                    if (puVar7 != (undefined4 *)0x0) {
                      uVar13 = FUN_008917b4(puVar7);
                      goto LAB_00826d0a;
                    }
                  }
                  break;
                }
              }
              uVar13 = 0;
LAB_00826d0a:
              local_94[0] = uVar4;
              FUN_00827050(param_1 + 0x10,local_98);
              puVar7 = (undefined4 *)FUN_008271c0();
              *puVar7 = 1;
              puVar7[1] = uVar13;
              iVar6 = FUN_0072e360();
              if (iVar6 != 0) {
                local_94[0] = local_ac;
                local_9c[0] = uVar4;
                do {
                  for (iVar8 = *(int *)(iVar6 + 0x94); iVar8 != iVar6 + 0x44;
                      iVar8 = *(int *)(iVar8 + 0x50)) {
                    pcVar11 = (char *)(iVar8 + 0x14);
                    if (0xf < *(uint *)(iVar8 + 0x28)) {
                      pcVar11 = *(char **)pcVar11;
                    }
                    iVar9 = __stricmp(pcVar11,"ItemID");
                    if (iVar9 == 0) {
                      if (iVar8 != 0) {
                        puVar7 = (undefined4 *)(iVar8 + 0x30);
                        if (0xf < *(uint *)(iVar8 + 0x44)) {
                          puVar7 = (undefined4 *)*puVar7;
                        }
                        if (puVar7 != (undefined4 *)0x0) {
                          local_b4 = FUN_008917b4(puVar7);
                          goto LAB_00826e19;
                        }
                      }
                      break;
                    }
                  }
                  local_b4 = 0;
LAB_00826e19:
                  for (iVar8 = *(int *)(iVar6 + 0x94); iVar8 != iVar6 + 0x44;
                      iVar8 = *(int *)(iVar8 + 0x50)) {
                    pcVar11 = (char *)(iVar8 + 0x14);
                    if (0xf < *(uint *)(iVar8 + 0x28)) {
                      pcVar11 = *(char **)pcVar11;
                    }
                    iVar9 = __stricmp(pcVar11,"Qty");
                    if (iVar9 == 0) {
                      if (iVar8 != 0) {
                        puVar7 = (undefined4 *)(iVar8 + 0x30);
                        if (0xf < *(uint *)(iVar8 + 0x44)) {
                          puVar7 = (undefined4 *)*puVar7;
                        }
                        if (puVar7 != (undefined4 *)0x0) {
                          uVar4 = FUN_008917b4(puVar7);
                          goto LAB_00826e49;
                        }
                      }
                      break;
                    }
                  }
                  uVar4 = 0;
LAB_00826e49:
                  FUN_00827050(param_1 + 0x10,local_94);
                  puVar10 = (undefined4 *)FUN_008271c0();
                  puVar1 = puVar10 + 2;
                  *puVar10 = 1;
                  puVar7 = (undefined4 *)puVar10[3];
                  local_a0._0_3_ = CONCAT12(uVar4,local_b4);
                  if (&local_a0 < puVar7) {
                    puVar2 = (undefined4 *)*puVar1;
                    if (&local_a0 < puVar2) goto LAB_00826f63;
                    if (puVar7 == (undefined4 *)puVar10[4]) {
                      uVar5 = (int)puVar7 - (int)puVar2 >> 2;
                      if (0x3ffffffe < uVar5) goto LAB_00826c57;
                      uVar5 = uVar5 + 1;
                      uVar12 = (int)puVar10[4] - (int)puVar2 >> 2;
                      if (uVar12 < uVar5) {
                        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                          uVar12 = 0;
                        }
                        else {
                          uVar12 = uVar12 + (uVar12 >> 1);
                        }
                        if (uVar12 < uVar5) {
                          uVar12 = uVar5;
                        }
                        FUN_0083f320(uVar12);
                      }
                    }
                    if ((undefined4 *)puVar10[3] != (undefined4 *)0x0) {
                      *(undefined4 *)puVar10[3] =
                           *(undefined4 *)(*puVar1 + ((int)&local_a0 - (int)puVar2 >> 2) * 4);
                    }
                  }
                  else {
LAB_00826f63:
                    if (puVar7 == (undefined4 *)puVar10[4]) {
                      uVar5 = (int)((int)puVar7 - *puVar1) >> 2;
                      if (0x3ffffffe < uVar5) {
LAB_00826c57:
                    /* WARNING: Subroutine does not return */
                        FUN_0087db30("vector<T> too long");
                      }
                      uVar5 = uVar5 + 1;
                      uVar12 = (int)((int)puVar10[4] - *puVar1) >> 2;
                      if (uVar12 < uVar5) {
                        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                          uVar12 = 0;
                        }
                        else {
                          uVar12 = uVar12 + (uVar12 >> 1);
                        }
                        if (uVar12 < uVar5) {
                          uVar12 = uVar5;
                        }
                        FUN_0083f320(uVar12);
                      }
                    }
                    if ((undefined4 *)puVar10[3] != (undefined4 *)0x0) {
                      *(undefined4 *)puVar10[3] = local_a0;
                    }
                  }
                  puVar10[3] = puVar10[3] + 4;
                  iVar6 = FUN_0072e3c0();
                } while (iVar6 != 0);
              }
              local_a4 = FUN_0072e3c0();
            } while (local_a4 != 0);
          }
          iVar6 = FUN_0072e3c0();
        }
      }
      local_8 = 0xffffffff;
      FUN_00407fb0();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


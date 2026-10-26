
void FUN_004d2ff0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined1 local_e8 [12];
  int local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_cc;
  undefined4 local_c8 [4];
  undefined4 local_b8;
  int *local_b4;
  undefined4 local_b0;
  int *local_ac;
  undefined4 *local_a8;
  undefined4 *local_a4;
  undefined4 *local_a0;
  int *local_98;
  int *local_94;
  undefined **local_90 [17];
  char local_4c;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924d21;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_cc = param_1;
  local_18 = uVar1;
  FUN_0072ee30(local_90);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_4c == '\0') && (iVar2 = FUN_0072e2e0("PRACTICELIST"), iVar2 != 0)) {
    piVar10 = *(int **)(iVar2 + 0x18);
    local_b4 = piVar10;
    if (piVar10 != (int *)0x0) {
      do {
        local_b4 = piVar10;
        (**(code **)(*piVar10 + 0x14))(uVar1);
        iVar2 = FUN_007300a0(&DAT_00bfb82c);
        puVar12 = (undefined4 *)0x0;
        if (iVar2 == 0) {
LAB_004d311e:
          local_b0 = 0;
        }
        else {
          puVar3 = (undefined4 *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            puVar3 = (undefined4 *)*puVar3;
          }
          if (puVar3 == (undefined4 *)0x0) goto LAB_004d311e;
          local_b0 = FUN_008917b4(puVar3);
        }
        local_a8 = (undefined4 *)0x0;
        local_a4 = (undefined4 *)0x0;
        local_a0 = (undefined4 *)0x0;
        local_8._0_1_ = 1;
        local_94 = (int *)piVar10[6];
        if (local_94 != (int *)0x0) {
          do {
            iVar4 = (**(code **)(*local_94 + 0x14))();
            for (iVar2 = *(int *)(iVar4 + 0x94); iVar2 != iVar4 + 0x44;
                iVar2 = *(int *)(iVar2 + 0x50)) {
              pcVar7 = (char *)(iVar2 + 0x14);
              if (0xf < *(uint *)(iVar2 + 0x28)) {
                pcVar7 = *(char **)pcVar7;
              }
              iVar5 = __stricmp(pcVar7,"ID");
              if (iVar5 == 0) {
                if (iVar2 != 0) {
                  puVar3 = (undefined4 *)(iVar2 + 0x30);
                  if (0xf < *(uint *)(iVar2 + 0x44)) {
                    puVar3 = (undefined4 *)*puVar3;
                  }
                  if (puVar3 != (undefined4 *)0x0) {
                    local_b8 = FUN_008917b4(puVar3);
                    goto LAB_004d31a2;
                  }
                }
                break;
              }
            }
            local_b8 = 0;
LAB_004d31a2:
            piVar10 = local_b4;
            for (local_98 = (int *)local_94[6]; local_b4 = piVar10, local_98 != (int *)0x0;
                local_98 = (int *)local_98[0x10]) {
              iVar4 = (**(code **)(*local_98 + 0x14))();
              for (iVar2 = *(int *)(iVar4 + 0x94); iVar2 != iVar4 + 0x44;
                  iVar2 = *(int *)(iVar2 + 0x50)) {
                pcVar7 = (char *)(iVar2 + 0x14);
                if (0xf < *(uint *)(iVar2 + 0x28)) {
                  pcVar7 = *(char **)pcVar7;
                }
                iVar5 = __stricmp(pcVar7,"ID");
                if (iVar5 == 0) {
                  if (iVar2 != 0) {
                    puVar3 = (undefined4 *)(iVar2 + 0x30);
                    if (0xf < *(uint *)(iVar2 + 0x44)) {
                      puVar3 = (undefined4 *)*puVar3;
                    }
                    if (puVar3 != (undefined4 *)0x0) {
                      uVar6 = FUN_008917b4(puVar3);
                      goto LAB_004d320a;
                    }
                  }
                  break;
                }
              }
              uVar6 = 0;
LAB_004d320a:
              local_ac = (int *)local_98[6];
              if (local_ac != (int *)0x0) {
                local_c8[0] = local_b0;
                local_c8[1] = local_b8;
                local_c8[2] = uVar6;
                do {
                  iVar4 = (**(code **)(*local_ac + 0x14))();
                  for (iVar2 = *(int *)(iVar4 + 0x94); iVar2 != iVar4 + 0x44;
                      iVar2 = *(int *)(iVar2 + 0x50)) {
                    pcVar7 = (char *)(iVar2 + 0x14);
                    if (0xf < *(uint *)(iVar2 + 0x28)) {
                      pcVar7 = *(char **)pcVar7;
                    }
                    iVar5 = __stricmp(pcVar7,"ID");
                    if (iVar5 == 0) {
                      if (iVar2 != 0) {
                        puVar3 = (undefined4 *)(iVar2 + 0x30);
                        if (0xf < *(uint *)(iVar2 + 0x44)) {
                          puVar3 = (undefined4 *)*puVar3;
                        }
                        if (puVar3 != (undefined4 *)0x0) {
                          uVar6 = FUN_008917b4(puVar3);
                          goto LAB_004d328a;
                        }
                      }
                      break;
                    }
                  }
                  uVar6 = 0;
LAB_004d328a:
                  local_c8[3] = uVar6;
                  if ((local_c8 < puVar12) && (local_a8 <= local_c8)) {
                    uVar11 = (int)local_c8 - (int)local_a8;
                    if (puVar12 == local_a0) {
                      uVar8 = (int)puVar12 - (int)local_a8 >> 4;
                      if (0xffffffe < uVar8) {
LAB_004d357e:
                    /* WARNING: Subroutine does not return */
                        FUN_0087db30("vector<T> too long");
                      }
                      uVar8 = uVar8 + 1;
                      uVar9 = (int)local_a0 - (int)local_a8 >> 4;
                      if (uVar9 < uVar8) {
                        if (0xfffffff - (uVar9 >> 1) < uVar9) {
                          uVar9 = 0;
                        }
                        else {
                          uVar9 = uVar9 + (uVar9 >> 1);
                        }
                        if (uVar9 < uVar8) {
                          uVar9 = uVar8;
                        }
                        FUN_004d3750(uVar9);
                        puVar12 = local_a4;
                      }
                    }
                    puVar3 = (undefined4 *)((uVar11 & 0xfffffff0) + (int)local_a8);
                    if (puVar12 != (undefined4 *)0x0) {
                      *puVar12 = *puVar3;
                      puVar12[1] = puVar3[1];
                      puVar12[2] = puVar3[2];
                      puVar12[3] = puVar3[3];
                    }
                  }
                  else {
                    if (puVar12 == local_a0) {
                      uVar11 = (int)puVar12 - (int)local_a8 >> 4;
                      if (0xffffffe < uVar11) goto LAB_004d357e;
                      uVar11 = uVar11 + 1;
                      uVar8 = (int)local_a0 - (int)local_a8 >> 4;
                      if (uVar8 < uVar11) {
                        if (0xfffffff - (uVar8 >> 1) < uVar8) {
                          uVar8 = 0;
                        }
                        else {
                          uVar8 = uVar8 + (uVar8 >> 1);
                        }
                        if (uVar8 < uVar11) {
                          uVar8 = uVar11;
                        }
                        FUN_004d3750(uVar8);
                        puVar12 = local_a4;
                      }
                    }
                    if (puVar12 != (undefined4 *)0x0) {
                      *puVar12 = local_c8[0];
                      puVar12[1] = local_c8[1];
                      puVar12[2] = local_c8[2];
                      puVar12[3] = uVar6;
                    }
                  }
                  local_ac = (int *)local_ac[0x10];
                  puVar12 = puVar12 + 4;
                  local_a4 = puVar12;
                } while (local_ac != (int *)0x0);
              }
              piVar10 = local_b4;
            }
            local_94 = (int *)local_94[0x10];
            local_98 = (int *)0x0;
          } while (local_94 != (int *)0x0);
          local_94 = (int *)0x0;
        }
        FUN_004d3ad0();
        uVar6 = local_cc;
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_004fcae0();
        FUN_004d3af0(uVar6,local_e8);
        if (local_dc != 0) {
          FUN_0089120c(local_dc);
        }
        local_8 = local_8 & 0xffffff00;
        local_dc = 0;
        local_d8 = 0;
        local_d4 = 0;
        if (local_a8 != (undefined4 *)0x0) {
          FUN_0089120c(local_a8);
        }
        piVar10 = (int *)piVar10[0x10];
        local_a8 = (undefined4 *)0x0;
        local_a4 = (undefined4 *)0x0;
        local_a0 = (undefined4 *)0x0;
      } while (piVar10 != (int *)0x0);
      local_b4 = (int *)0x0;
    }
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
    local_90[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_30) {
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


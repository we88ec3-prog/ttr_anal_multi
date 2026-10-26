
void FUN_00759ed0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  short sVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  int *piVar10;
  undefined4 *****pppppuVar11;
  short *psVar12;
  int iVar13;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int *local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int *local_b4;
  int local_b0;
  int local_a8;
  int *local_a4;
  int local_a0;
  undefined4 local_9c;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined **local_84 [3];
  undefined4 ****local_78 [4];
  int local_68;
  uint local_64;
  undefined4 local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_40;
  uint local_2c;
  undefined4 local_24;
  undefined2 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092a749;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_dc;
  ExceptionList = &local_14;
  local_78[0] = (undefined4 ****)((uint)local_78[0] & 0xffff0000);
  local_bc = param_1;
  local_64 = 7;
  local_68 = 0;
  FUN_004026e0(param_2,0,0xffffffff);
  local_c = 0;
  iVar7 = FUN_00466df0(local_78,&DAT_00c059b8,2);
  while (iVar7 != -1) {
    FUN_00402400(iVar7,2);
    iVar7 = FUN_00466df0(local_78,&DAT_00c059b8,2);
  }
  local_20 = 0;
  psVar8 = (short *)&local_24;
  local_24 = (char *)0xa000d;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  iVar9 = (int)psVar8 - ((int)&local_24 + 2) >> 1;
  iVar7 = FUN_00466df0(local_78,&local_24,iVar9);
  local_c0 = local_68;
  while (local_68 = local_c0, iVar7 != -1) {
    FUN_00402400(iVar7,2);
    iVar7 = FUN_00466df0(local_78,&local_24,iVar9);
    local_c0 = local_68;
  }
  local_a8 = *(int *)(param_1 + 0x10);
  puVar4 = (undefined4 *)**(undefined4 **)(local_bc + 0x1c);
  iVar7 = 0xffffff;
  local_c8 = 0;
  for (; (puVar4 != *(undefined4 **)(local_bc + 0x1c) && ((int)puVar4[2] <= local_a8));
      puVar4 = (undefined4 *)*puVar4) {
    iVar7 = puVar4[3];
  }
  local_48 = 7;
  local_4c = 0;
  local_5c = (short *)((uint)local_5c._2_2_ << 0x10);
  local_a4 = (int *)0x0;
  local_a0 = 0;
  local_9c = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_c._1_3_ = (undefined3)((uint)local_c >> 8);
  local_c._0_1_ = 3;
  local_b0 = 0;
  local_b8 = iVar7;
  piVar10 = (int *)FUN_00891268(0xc);
  local_c4 = piVar10;
  if (piVar10 == (int *)0x0) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_84,(char **)&local_24);
    local_84[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_84,&DAT_00c857a8);
  }
  *piVar10 = (int)piVar10;
  piVar10[1] = (int)piVar10;
  local_c._0_1_ = 4;
  local_dc = iVar7;
  local_b4 = piVar10;
  iVar7 = FUN_0074d700(piVar10,piVar10,&local_dc);
  piVar10[1] = iVar7;
  iVar9 = 0;
  local_b0 = 1;
  **(int **)(iVar7 + 4) = iVar7;
  iVar7 = 0;
  if (0 < local_c0) {
    local_cc = 3;
    local_d0 = 8;
    local_d8 = 5;
    local_d4 = 4;
    do {
      if (local_d8 < local_c0) {
        pppppuVar11 = (undefined4 *****)local_78[0];
        if (local_64 < 8) {
          pppppuVar11 = local_78;
        }
        if (*(short *)((int)pppppuVar11 + iVar9 * 2) != 0x3c) goto LAB_0075a1b9;
        pppppuVar11 = (undefined4 *****)local_78[0];
        if (local_64 < 8) {
          pppppuVar11 = local_78;
        }
        if (*(short *)((int)pppppuVar11 + iVar9 * 2 + 2) != 0x23) goto LAB_0075a1b9;
        pppppuVar11 = (undefined4 *****)local_78[0];
        if (local_64 < 8) {
          pppppuVar11 = local_78;
        }
        if (*(short *)((int)pppppuVar11 + iVar9 * 2 + 10) != 0x3e) goto LAB_0075a1b9;
        local_dc = 0xffffff;
        FUN_004a8680();
        FUN_004a8680();
        piVar10 = local_c4;
        iVar7 = FUN_0074d700(local_c4,local_c4[1],&local_dc);
        if (local_b0 == 0x3ffffffe) goto LAB_0075a4ca;
        local_b0 = local_b0 + 1;
        piVar10[1] = iVar7;
        **(int **)(iVar7 + 4) = iVar7;
        local_d8 = local_d8 + 5;
        local_d0 = local_d0 + 5;
        local_cc = local_cc + 5;
        iVar9 = iVar9 + 5;
        local_d4 = local_d4 + 10;
      }
      else {
LAB_0075a1b9:
        if (local_d0 < local_c0) {
          pppppuVar11 = (undefined4 *****)local_78[0];
          if (local_64 < 8) {
            pppppuVar11 = local_78;
          }
          if (*(short *)((int)pppppuVar11 + iVar9 * 2) == 0x3c) {
            pppppuVar11 = (undefined4 *****)local_78[0];
            if (local_64 < 8) {
              pppppuVar11 = local_78;
            }
            if (*(short *)((int)pppppuVar11 + iVar9 * 2 + 2) == 0x23) {
              pppppuVar11 = (undefined4 *****)local_78[0];
              if (local_64 < 8) {
                pppppuVar11 = local_78;
              }
              if (*(short *)((int)pppppuVar11 + iVar9 * 2 + 0x10) == 0x3e) {
                FUN_0043f3e0(local_78);
                local_c._0_1_ = 5;
                local_dc = FUN_00528730();
                FUN_004a8680();
                FUN_004a8680();
                iVar7 = FUN_0074d700(local_c4,local_c4[1],&local_dc);
                if (local_b0 == 0x3ffffffe) {
LAB_0075a4ca:
                    /* WARNING: Subroutine does not return */
                  FUN_0087db30("list<T> too long");
                }
                local_b0 = local_b0 + 1;
                local_d4 = local_d4 + 0x10;
                local_c4[1] = iVar7;
                **(int **)(iVar7 + 4) = iVar7;
                local_d8 = local_d8 + 8;
                local_d0 = local_d0 + 8;
                local_cc = local_cc + 8;
                iVar9 = iVar9 + 8;
                local_c._0_1_ = 4;
                if (7 < local_2c) {
                  FUN_0089120c(local_40);
                }
                goto LAB_0075a43c;
              }
            }
          }
        }
        if (local_cc < local_c0) {
          pppppuVar11 = (undefined4 *****)local_78[0];
          if (local_64 < 8) {
            pppppuVar11 = local_78;
          }
          if (*(short *)((int)pppppuVar11 + iVar9 * 2) != 0x3c) goto LAB_0075a41a;
          pppppuVar11 = (undefined4 *****)local_78[0];
          if (local_64 < 8) {
            pppppuVar11 = local_78;
          }
          if (*(short *)((int)pppppuVar11 + iVar9 * 2 + 6) != 0x3e) goto LAB_0075a41a;
          pppppuVar11 = (undefined4 *****)local_78[0];
          if (local_64 < 8) {
            pppppuVar11 = local_78;
          }
          sVar1 = *(short *)((int)pppppuVar11 + iVar9 * 2 + 2);
          pppppuVar11 = (undefined4 *****)local_78[0];
          if (local_64 < 8) {
            pppppuVar11 = local_78;
          }
          sVar2 = *(short *)(local_d4 + (int)pppppuVar11);
          if (((sVar1 == 0x62) || (sVar1 == 0x42)) && ((sVar2 == 0x72 || (sVar2 == 0x52)))) {
            FUN_00440010(1,10);
            local_c8 = local_c8 + 1;
            local_d8 = local_d8 + 3;
            local_d0 = local_d0 + 3;
            local_cc = local_cc + 3;
            iVar9 = iVar9 + 3;
            local_d4 = local_d4 + 6;
            goto LAB_0075a43c;
          }
          if ((sVar1 == 0x2f) && (sVar2 == 0x23)) {
            FUN_004a8680();
            iVar7 = local_b0;
            if (local_b0 == 0) {
LAB_0075a3ab:
              local_dc = local_b8;
            }
            else {
              piVar10 = (int *)local_c4[1];
              if (piVar10 != local_c4) {
                *(int *)piVar10[1] = *piVar10;
                *(int *)(*piVar10 + 4) = piVar10[1];
                FUN_0089120c(piVar10);
                local_b0 = iVar7 + -1;
              }
              if (local_b0 == 0) goto LAB_0075a3ab;
            }
            FUN_004a8680();
            local_d8 = local_d8 + 3;
            local_d0 = local_d0 + 3;
            local_cc = local_cc + 3;
            iVar9 = iVar9 + 3;
            local_d4 = local_d4 + 6;
            goto LAB_0075a43c;
          }
          pppppuVar11 = (undefined4 *****)local_78[0];
          if (local_64 < 8) {
            pppppuVar11 = local_78;
          }
          uVar3 = *(undefined2 *)((int)pppppuVar11 + iVar9 * 2);
        }
        else {
LAB_0075a41a:
          pppppuVar11 = (undefined4 *****)local_78[0];
          if (local_64 < 8) {
            pppppuVar11 = local_78;
          }
          uVar3 = *(undefined2 *)((int)pppppuVar11 + iVar9 * 2);
        }
        FUN_00440010(1,uVar3);
        local_c8 = local_c8 + 1;
      }
LAB_0075a43c:
      local_d4 = local_d4 + 2;
      local_d8 = local_d8 + 1;
      local_d0 = local_d0 + 1;
      local_cc = local_cc + 1;
      iVar9 = iVar9 + 1;
      iVar7 = local_a0;
    } while (iVar9 < local_c0);
  }
  iVar9 = local_bc;
  psVar8 = local_5c;
  if (local_48 < 8) {
    psVar8 = (short *)&local_5c;
  }
  psVar12 = psVar8;
  do {
    sVar1 = *psVar12;
    psVar12 = psVar12 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar8,(int)psVar12 - (int)(psVar8 + 1) >> 1);
  iVar7 = iVar7 - (int)local_a4 >> 2;
  if (0 < iVar7) {
    iVar13 = 0;
    if (0 < iVar7) {
      local_dc = *(int *)(iVar9 + 0x10) - local_a8;
      local_c0 = local_94 - (int)local_a4;
      piVar10 = local_a4;
      do {
        iVar13 = iVar13 + 1;
        iVar9 = local_dc;
        if (iVar13 < iVar7) {
          iVar9 = piVar10[1];
        }
        FUN_007591a0(*piVar10 + local_a8,iVar9 - *piVar10,*(undefined4 *)(local_c0 + (int)piVar10));
        piVar10 = piVar10 + 1;
      } while (iVar13 < iVar7);
    }
    FUN_007592c0(local_bc);
    iVar9 = local_bc;
  }
  FUN_00757940(iVar9,param_3,param_4);
  piVar6 = local_c4;
  piVar10 = (int *)*local_c4;
  *local_c4 = (int)local_c4;
  local_c4[1] = (int)local_c4;
  while (piVar10 != piVar6) {
    piVar5 = (int *)*piVar10;
    FUN_0089120c(piVar10);
    piVar10 = piVar5;
  }
  FUN_0089120c(piVar6);
  if (local_94 != 0) {
    FUN_0089120c(local_94);
  }
  if (local_a4 != (int *)0x0) {
    FUN_0089120c(local_a4);
  }
  if (7 < local_48) {
    FUN_0089120c(local_5c);
  }
  local_48 = 7;
  local_4c = 0;
  local_5c = (short *)((uint)local_5c & 0xffff0000);
  if (7 < local_64) {
    FUN_0089120c(local_78[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_dc);
  return;
}


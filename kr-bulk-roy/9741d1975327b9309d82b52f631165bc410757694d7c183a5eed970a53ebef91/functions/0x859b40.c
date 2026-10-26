
/* WARNING: Removing unreachable block (ram,0x00859e76) */
/* WARNING: Removing unreachable block (ram,0x0085a076) */

undefined4 * FUN_00859b40(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  char cVar2;
  int *piVar3;
  char **ppcVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  char **ppcVar10;
  int local_4c;
  char **local_38;
  char **local_34;
  undefined **local_2c;
  undefined1 local_28 [8];
  int *local_20;
  char *local_1c;
  char *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090bc33;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = gbDxEffect::vftable;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  local_8 = 1;
  uStack_7 = 0;
  param_1[0xe] = 0;
  iVar7 = FUN_00891268(0x48,uVar6);
  if (iVar7 == 0) {
    local_20 = (int *)0x0;
    std::exception::exception((exception *)&local_38,(char **)&local_20);
    local_38 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_38,&DAT_00c857a8);
  }
  param_1[0xd] = iVar7;
  *(int *)iVar7 = iVar7;
  *(undefined4 *)(param_1[0xd] + 4) = param_1[0xd];
  *(undefined4 *)(param_1[0xd] + 8) = param_1[0xd];
  *(undefined1 *)(param_1[0xd] + 0x44) = 1;
  *(undefined1 *)(param_1[0xd] + 0x45) = 1;
  local_8 = 2;
  param_1[0x12] = 0;
  uVar8 = FUN_00570a10();
  param_1[0x11] = uVar8;
  *(undefined4 *)uVar8 = uVar8;
  *(undefined4 *)(param_1[0x11] + 4) = param_1[0x11];
  *(undefined4 *)(param_1[0x11] + 8) = param_1[0x11];
  *(undefined1 *)(param_1[0x11] + 0x40) = 1;
  *(undefined1 *)(param_1[0x11] + 0x41) = 1;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  local_8 = 4;
  param_1[0x1a] = 0;
  iVar7 = FUN_00891268(0x24,uVar6);
  if (iVar7 == 0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)&local_38,&local_1c);
    local_38 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_38,&DAT_00c857a8);
  }
  param_1[0x19] = iVar7;
  *(int *)iVar7 = iVar7;
  *(undefined4 *)(param_1[0x19] + 4) = param_1[0x19];
  *(undefined4 *)(param_1[0x19] + 8) = param_1[0x19];
  *(undefined1 *)(param_1[0x19] + 0x20) = 1;
  *(undefined1 *)(param_1[0x19] + 0x21) = 1;
  local_8 = 5;
  param_1[0x1e] = 0;
  iVar7 = FUN_00891268(0x24,uVar6);
  if (iVar7 == 0) {
    local_20 = (int *)0x0;
    std::exception::exception((exception *)&local_2c,(char **)&local_20);
    local_2c = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_2c,&DAT_00c857a8);
  }
  param_1[0x1d] = iVar7;
  *(int *)iVar7 = iVar7;
  *(undefined4 *)(param_1[0x1d] + 4) = param_1[0x1d];
  *(undefined4 *)(param_1[0x1d] + 8) = param_1[0x1d];
  *(undefined1 *)(param_1[0x1d] + 0x20) = 1;
  *(undefined1 *)(param_1[0x1d] + 0x21) = 1;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  local_8 = 7;
  piVar3 = *(int **)(param_2 + 4);
  param_1[1] = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(piVar3);
  }
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[0x21] = *(undefined4 *)(param_2 + 0x84);
  local_20 = *(int **)(param_2 + 100);
  local_14 = (int *)*local_20;
  if (local_14 != local_20) {
    do {
      local_38 = (char **)0x0;
      local_34 = (char **)0x0;
      local_8 = 8;
      iVar7 = local_14[4];
      local_1c = (char *)0x0;
      if (local_14[5] - iVar7 >> 2 != 0) {
        do {
          ppcVar4 = local_34;
          ppcVar10 = local_38;
          local_18 = (char *)(**(code **)**(undefined4 **)(iVar7 + (int)local_1c * 4))();
          uVar6 = (int)ppcVar10 >> 2;
          if (&local_18 < ppcVar10) {
            if (ppcVar10 == local_34) {
              if (0x3ffffffe < uVar6) goto LAB_00859ede;
              uVar6 = uVar6 + 1;
              uVar9 = (int)local_34 >> 2;
              if (uVar9 < uVar6) {
                if (0x3fffffff - (uVar9 >> 1) < uVar9) {
                  uVar9 = 0;
                }
                else {
                  uVar9 = uVar9 + (uVar9 >> 1);
                }
                if (uVar9 < uVar6) {
                  uVar9 = uVar6;
                }
                FUN_00797980(uVar9);
                ppcVar10 = local_38;
              }
            }
            if (ppcVar10 != (char **)0x0) {
              *ppcVar10 = *(char **)(((int)&local_18 >> 2) * 4);
            }
          }
          else {
            if (ppcVar10 == ppcVar4) {
              if (0x3ffffffe < uVar6) goto LAB_00859ede;
              uVar6 = uVar6 + 1;
              uVar9 = (int)ppcVar4 >> 2;
              if (uVar9 < uVar6) {
                if (0x3fffffff - (uVar9 >> 1) < uVar9) {
                  uVar9 = 0;
                }
                else {
                  uVar9 = uVar9 + (uVar9 >> 1);
                }
                if (uVar9 < uVar6) {
                  uVar9 = uVar6;
                }
                FUN_00797980(uVar9);
                ppcVar10 = local_38;
              }
            }
            if (ppcVar10 != (char **)0x0) {
              *ppcVar10 = local_18;
            }
          }
          iVar7 = local_14[4];
          local_1c = local_1c + 1;
          local_38 = ppcVar10 + 1;
        } while (local_1c < (char *)(local_14[5] - iVar7 >> 2));
      }
      FUN_0085f5f0();
      _local_8 = CONCAT31(uStack_7,9);
      FUN_004fcae0();
      FUN_007cd000(param_1 + 0x18,local_28);
      if (local_4c != 0) {
        FUN_0089120c(local_4c);
      }
      if (*(char *)((int)local_14 + 0x21) == '\0') {
        piVar3 = (int *)local_14[2];
        if (*(char *)((int)piVar3 + 0x21) == '\0') {
          cVar2 = *(char *)(*piVar3 + 0x21);
          local_14 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar2 == '\0') {
            cVar2 = *(char *)(*piVar3 + 0x21);
            local_14 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar2 = *(char *)(local_14[1] + 0x21);
          piVar5 = (int *)local_14[1];
          piVar3 = local_14;
          while ((local_14 = piVar5, cVar2 == '\0' && (piVar3 == (int *)local_14[2]))) {
            cVar2 = *(char *)(local_14[1] + 0x21);
            piVar5 = (int *)local_14[1];
            piVar3 = local_14;
          }
        }
      }
      local_8 = 7;
      local_38 = (char **)0x0;
      local_34 = (char **)0x0;
    } while (local_14 != local_20);
  }
  local_20 = *(int **)(param_2 + 0x74);
  local_14 = (int *)*local_20;
  if (local_14 != local_20) {
    do {
      local_38 = (char **)0x0;
      local_34 = (char **)0x0;
      local_8 = 10;
      iVar7 = local_14[4];
      local_1c = (char *)0x0;
      if (local_14[5] - iVar7 >> 2 != 0) {
        do {
          ppcVar4 = local_34;
          ppcVar10 = local_38;
          local_18 = (char *)(**(code **)**(undefined4 **)(iVar7 + (int)local_1c * 4))();
          uVar6 = (int)ppcVar10 >> 2;
          if (&local_18 < ppcVar10) {
            if (ppcVar10 == local_34) {
              if (0x3ffffffe < uVar6) goto LAB_00859ede;
              uVar6 = uVar6 + 1;
              uVar9 = (int)local_34 >> 2;
              if (uVar9 < uVar6) {
                if (0x3fffffff - (uVar9 >> 1) < uVar9) {
                  uVar9 = 0;
                }
                else {
                  uVar9 = uVar9 + (uVar9 >> 1);
                }
                if (uVar9 < uVar6) {
                  uVar9 = uVar6;
                }
                FUN_00797980(uVar9);
                ppcVar10 = local_38;
              }
            }
            if (ppcVar10 != (char **)0x0) {
              *ppcVar10 = *(char **)(((int)&local_18 >> 2) * 4);
            }
          }
          else {
            if (ppcVar10 == ppcVar4) {
              if (0x3ffffffe < uVar6) goto LAB_00859ede;
              uVar6 = uVar6 + 1;
              uVar9 = (int)ppcVar4 >> 2;
              if (uVar9 < uVar6) {
                if (0x3fffffff - (uVar9 >> 1) < uVar9) {
                  uVar9 = 0;
                }
                else {
                  uVar9 = uVar9 + (uVar9 >> 1);
                }
                if (uVar9 < uVar6) {
                  uVar9 = uVar6;
                }
                FUN_00797980(uVar9);
                ppcVar10 = local_38;
              }
            }
            if (ppcVar10 != (char **)0x0) {
              *ppcVar10 = local_18;
            }
          }
          iVar7 = local_14[4];
          local_1c = local_1c + 1;
          local_38 = ppcVar10 + 1;
        } while (local_1c < (char *)(local_14[5] - iVar7 >> 2));
      }
      FUN_0085f5f0();
      _local_8 = CONCAT31(uStack_7,0xb);
      FUN_004fcae0();
      FUN_007cd000(param_1 + 0x1c,local_28);
      if (local_4c != 0) {
        FUN_0089120c(local_4c);
      }
      if (*(char *)((int)local_14 + 0x21) == '\0') {
        piVar3 = (int *)local_14[2];
        if (*(char *)((int)piVar3 + 0x21) == '\0') {
          cVar2 = *(char *)(*piVar3 + 0x21);
          local_14 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar2 == '\0') {
            cVar2 = *(char *)(*piVar3 + 0x21);
            local_14 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar2 = *(char *)(local_14[1] + 0x21);
          piVar5 = (int *)local_14[1];
          piVar3 = local_14;
          while ((local_14 = piVar5, cVar2 == '\0' && (piVar3 == (int *)local_14[2]))) {
            cVar2 = *(char *)(local_14[1] + 0x21);
            piVar5 = (int *)local_14[1];
            piVar3 = local_14;
          }
        }
      }
      local_8 = 7;
      local_38 = (char **)0x0;
      local_34 = (char **)0x0;
    } while (local_14 != local_20);
  }
  local_20 = (int *)(param_2 + 0x30);
  if (param_1 + 0xc != local_20) {
    FUN_0085e3e0(*(undefined4 *)param_1[0xd],(undefined4 *)param_1[0xd]);
    FUN_0085e4a0(local_20);
  }
  local_20 = (int *)(param_2 + 0x40);
  if (param_1 + 0x10 != local_20) {
    FUN_0085e530(*(undefined4 *)param_1[0x11],(undefined4 *)param_1[0x11]);
    FUN_0085e5f0(local_20);
  }
  FUN_0085dd70(param_2 + 0x20);
  FUN_004738a0(param_2 + 0x10);
  local_1c = (char *)param_1[0x14];
  puVar1 = param_1 + 0x14;
  if (local_1c != (char *)param_1[0x15]) {
    local_20 = (int *)0x0;
    FID_conflict__memcpy(local_1c,(char *)param_1[0x15],0);
    param_1[0x15] = (char *)((int)local_20 + (int)local_1c);
  }
  iVar7 = *(int *)(param_2 + 0x50);
  local_1c = (char *)0x0;
  if (*(int *)(param_2 + 0x54) - iVar7 >> 2 != 0) {
    do {
      local_18 = (char *)(**(code **)**(undefined4 **)(iVar7 + (int)local_1c * 4))();
      ppcVar10 = (char **)param_1[0x15];
      if ((&local_18 < ppcVar10) && (ppcVar4 = (char **)*puVar1, ppcVar4 <= &local_18)) {
        local_20 = (int *)((int)&local_18 - (int)ppcVar4 >> 2);
        if (ppcVar10 == (char **)param_1[0x16]) {
          uVar6 = (int)ppcVar10 - (int)ppcVar4 >> 2;
          if (0x3ffffffe < uVar6) goto LAB_00859ede;
          uVar6 = uVar6 + 1;
          uVar9 = (int)param_1[0x16] - (int)ppcVar4 >> 2;
          if (uVar9 < uVar6) {
            if (0x3fffffff - (uVar9 >> 1) < uVar9) {
              uVar9 = 0;
            }
            else {
              uVar9 = uVar9 + (uVar9 >> 1);
            }
            if (uVar9 < uVar6) {
              uVar9 = uVar6;
            }
            FUN_00797980(uVar9);
          }
        }
        if ((undefined4 *)param_1[0x15] != (undefined4 *)0x0) {
          *(undefined4 *)param_1[0x15] = *(undefined4 *)(*puVar1 + (int)local_20 * 4);
        }
      }
      else {
        if (ppcVar10 == (char **)param_1[0x16]) {
          uVar6 = (int)((int)ppcVar10 - *puVar1) >> 2;
          if (0x3ffffffe < uVar6) {
LAB_00859ede:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar6 = uVar6 + 1;
          uVar9 = (int)((int)param_1[0x16] - *puVar1) >> 2;
          if (uVar9 < uVar6) {
            if (0x3fffffff - (uVar9 >> 1) < uVar9) {
              uVar9 = 0;
            }
            else {
              uVar9 = uVar9 + (uVar9 >> 1);
            }
            if (uVar9 < uVar6) {
              uVar9 = uVar6;
            }
            FUN_00797980(uVar9);
          }
        }
        if ((undefined4 *)param_1[0x15] != (undefined4 *)0x0) {
          *(undefined4 *)param_1[0x15] = local_18;
        }
      }
      param_1[0x15] = param_1[0x15] + 4;
      iVar7 = *(int *)(param_2 + 0x50);
      local_1c = local_1c + 1;
    } while (local_1c < (char *)(*(int *)(param_2 + 0x54) - iVar7 >> 2));
  }
  param_1[0x22] = *(undefined4 *)(param_2 + 0x88);
  FUN_006dd790(param_2 + 0x8c);
  ExceptionList = local_10;
  return param_1;
}


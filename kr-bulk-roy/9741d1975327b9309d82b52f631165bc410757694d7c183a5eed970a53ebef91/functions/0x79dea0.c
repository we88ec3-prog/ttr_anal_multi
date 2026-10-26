
/* WARNING: Removing unreachable block (ram,0x0079e2a4) */
/* WARNING: Removing unreachable block (ram,0x0079e2b0) */
/* WARNING: Removing unreachable block (ram,0x0079e2c4) */
/* WARNING: Removing unreachable block (ram,0x0079e3b1) */
/* WARNING: Removing unreachable block (ram,0x0079e3bb) */
/* WARNING: Removing unreachable block (ram,0x0079e3c0) */
/* WARNING: Removing unreachable block (ram,0x0079e3c7) */
/* WARNING: Removing unreachable block (ram,0x0079e447) */
/* WARNING: Removing unreachable block (ram,0x0079e3cf) */
/* WARNING: Removing unreachable block (ram,0x0079e3d5) */
/* WARNING: Removing unreachable block (ram,0x0079e3d8) */
/* WARNING: Removing unreachable block (ram,0x0079e052) */
/* WARNING: Removing unreachable block (ram,0x0079e059) */
/* WARNING: Removing unreachable block (ram,0x0079e060) */
/* WARNING: Removing unreachable block (ram,0x0079e068) */
/* WARNING: Removing unreachable block (ram,0x0079e112) */
/* WARNING: Removing unreachable block (ram,0x0079e074) */
/* WARNING: Removing unreachable block (ram,0x0079e07b) */
/* WARNING: Removing unreachable block (ram,0x0079e07e) */
/* WARNING: Removing unreachable block (ram,0x0079e411) */
/* WARNING: Removing unreachable block (ram,0x0079e41d) */
/* WARNING: Removing unreachable block (ram,0x0079e431) */
/* WARNING: Removing unreachable block (ram,0x0079e0dc) */
/* WARNING: Removing unreachable block (ram,0x0079e0ec) */
/* WARNING: Removing unreachable block (ram,0x0079e104) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079dea0(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar1;
  undefined ***pppuVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  DWORD DVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined ***local_bc;
  DWORD local_a0;
  undefined ***local_94;
  int *local_90;
  undefined ****local_84;
  undefined ***local_80;
  int *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  int *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  char *local_4c;
  undefined **local_48 [3];
  undefined **local_3c [10];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00938e85;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_64 = (int *)0x0;
  local_bc = (undefined ***)0x79dedf;
  piVar4 = (int *)FUN_00891268();
  if (piVar4 == (int *)0x0) {
    local_84 = (undefined ****)0x0;
    local_bc = (undefined ***)0x79e518;
    std::exception::exception((exception *)local_3c,(char **)&local_84);
    local_bc = local_3c;
    local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8();
  }
  *piVar4 = 0;
  piVar4[1] = 0;
  *piVar4 = (int)&local_64;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_c = 0;
  local_7c = (int *)0x0;
  local_bc = (undefined ***)0x79df23;
  local_64 = piVar4;
  piVar4 = (int *)FUN_00891268();
  if (piVar4 == (int *)0x0) {
    local_4c = (char *)0x0;
    local_bc = (undefined ***)0x79e4ef;
    std::exception::exception((exception *)local_48,&local_4c);
    local_bc = local_48;
    local_48[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8();
  }
  piVar4[1] = 0;
  *piVar4 = 0;
  *piVar4 = (int)&local_7c;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_c._0_1_ = 1;
  cVar1 = *(char *)(param_1 + 0xc0);
  local_7c = piVar4;
  do {
    if (cVar1 != '\0') {
      local_bc = (undefined ***)0x79e47f;
      SetEvent(*(HANDLE *)(param_1 + 0xc4));
      __endthread();
      local_c = CONCAT31(local_c._1_3_,5);
      FUN_007a1320();
      local_bc = (undefined ***)0x79e49f;
      FUN_0089120c();
      local_7c = (int *)0x0;
      local_c = 6;
      FUN_007a1320();
      local_bc = (undefined ***)0x79e4c4;
      FUN_0089120c();
      ExceptionList = local_14;
      return;
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x70);
    local_bc = (undefined ***)0x79df7a;
    EnterCriticalSection(lpCriticalSection);
    if (((*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x2c)) &&
        (*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x3c))) && (*(int *)(param_1 + 0x68) == 0))
    {
      local_bc = (undefined ***)0x79df96;
      LeaveCriticalSection(lpCriticalSection);
      if (*(char *)(param_1 + 200) == '\0') {
        local_bc = (undefined ***)0x79e463;
        Sleep(0xf);
      }
      else {
        *(undefined1 *)(param_1 + 200) = 0;
        local_bc = (undefined ***)0x79dfb7;
        SetEvent(*(HANDLE *)(param_1 + 0xcc));
      }
    }
    else {
      local_bc = (undefined ***)0x79dfc3;
      LeaveCriticalSection(lpCriticalSection);
      local_bc = (undefined ***)0x79dfcf;
      FUN_0079e7c0();
      local_bc = (undefined ***)0x79dfd9;
      FUN_0079e8a0();
      if (*(int *)(param_1 + 0x68) == 0) {
        if (local_54 == 0) {
          if (local_6c != 0) {
            local_a0 = timeGetTime();
            while (local_6c != 0) {
              piVar4 = (int *)FUN_00542210();
              if ((int *)*piVar4 == (int *)0x0) {
                iVar10 = 0;
              }
              else {
                iVar10 = *(int *)*piVar4;
              }
              uVar5 = (uint)piVar4[2] >> 1;
              uVar9 = piVar4[2] & 1;
              if (*(uint *)(iVar10 + 8) <= uVar5) {
                uVar5 = uVar5 - *(uint *)(iVar10 + 8);
              }
              iVar10 = *(int *)(*(int *)(iVar10 + 4) + uVar5 * 4);
              iVar6 = *(int *)(iVar10 + 4 + uVar9 * 8);
              local_80 = *(undefined ****)(iVar10 + uVar9 * 8);
              if (iVar6 != 0) {
                iVar10 = *(int *)(iVar6 + 4);
                while (iVar10 != 0) {
                  LOCK();
                  iVar8 = *(int *)(iVar6 + 4);
                  if (iVar10 == iVar8) {
                    *(int *)(iVar6 + 4) = iVar10 + 1;
                    iVar8 = iVar10;
                  }
                  UNLOCK();
                  if (iVar8 == iVar10) {
                    local_bc = local_80;
                    FUN_007a31c0();
                    break;
                  }
                  iVar10 = *(int *)(iVar6 + 4);
                }
              }
              local_c = CONCAT31(local_c._1_3_,4);
              FUN_007a13e0();
              local_84 = &local_bc;
              local_bc = (undefined ***)0x0;
              FUN_0079ed00();
              DVar7 = timeGetTime();
              if (0xf < DVar7 - local_a0) {
                local_a0 = timeGetTime();
                local_bc = (undefined ***)0x79e405;
                Sleep(5);
              }
              local_c._0_1_ = 1;
            }
          }
        }
        else {
          local_a0 = timeGetTime();
          while (local_54 != 0) {
            piVar4 = (int *)FUN_00542210();
            if ((int *)*piVar4 == (int *)0x0) {
              iVar10 = 0;
            }
            else {
              iVar10 = *(int *)*piVar4;
            }
            uVar5 = (uint)piVar4[2] >> 1;
            uVar9 = piVar4[2] & 1;
            if (*(uint *)(iVar10 + 8) <= uVar5) {
              uVar5 = uVar5 - *(uint *)(iVar10 + 8);
            }
            iVar10 = *(int *)(*(int *)(iVar10 + 4) + uVar5 * 4);
            piVar4 = *(int **)(iVar10 + 4 + uVar9 * 8);
            local_80 = *(undefined ****)(iVar10 + uVar9 * 8);
            local_94 = (undefined ***)0x0;
            local_90 = (int *)0x0;
            pppuVar2 = local_94;
            piVar3 = local_90;
            if (piVar4 != (int *)0x0) {
              iVar10 = piVar4[1];
              while (pppuVar2 = local_94, piVar3 = local_90, iVar10 != 0) {
                LOCK();
                iVar6 = piVar4[1];
                if (iVar10 == iVar6) {
                  piVar4[1] = iVar10 + 1;
                  iVar6 = iVar10;
                }
                UNLOCK();
                pppuVar2 = local_80;
                piVar3 = piVar4;
                if (iVar6 == iVar10) break;
                iVar10 = piVar4[1];
              }
            }
            local_90 = piVar3;
            local_94 = pppuVar2;
            local_c = CONCAT31(local_c._1_3_,3);
            FUN_007a13e0();
            local_bc = (undefined ***)0x0;
            if (local_90 != (int *)0x0) {
              iVar10 = local_90[1];
              while (iVar10 != 0) {
                LOCK();
                iVar6 = local_90[1];
                if (iVar10 == iVar6) {
                  local_90[1] = iVar10 + 1;
                  iVar6 = iVar10;
                }
                UNLOCK();
                if (iVar6 == iVar10) {
                  local_bc = local_94;
                  break;
                }
                iVar10 = local_90[1];
              }
            }
            local_84 = &local_bc;
            FUN_0079e980(param_1);
            DVar7 = timeGetTime();
            if (0xf < DVar7 - local_a0) {
              local_a0 = timeGetTime();
              local_bc = (undefined ***)0x79e242;
              Sleep(5);
            }
            local_c._0_1_ = 1;
            if (local_90 != (int *)0x0) {
              LOCK();
              iVar10 = local_90[1] + -1;
              local_90[1] = iVar10;
              UNLOCK();
              if (iVar10 == 0) {
                (**(code **)*local_90)();
                LOCK();
                iVar10 = local_90[2] + -1;
                local_90[2] = iVar10;
                UNLOCK();
                if (iVar10 == 0) {
                  (**(code **)(*local_90 + 4))();
                }
              }
            }
          }
        }
      }
      else {
        iVar10 = *(int *)(param_1 + 0x6c);
        local_bc = *(undefined ****)(param_1 + 0x68);
        if (iVar10 != 0) {
          iVar6 = *(int *)(iVar10 + 4);
          while (iVar6 != 0) {
            LOCK();
            iVar8 = *(int *)(iVar10 + 4);
            if (iVar6 == iVar8) {
              *(int *)(iVar10 + 4) = iVar6 + 1;
              iVar8 = iVar6;
            }
            UNLOCK();
            if (iVar8 == iVar6) {
              FUN_007a31c0();
              break;
            }
            iVar6 = *(int *)(iVar10 + 4);
          }
        }
        local_84 = &local_bc;
        local_c = CONCAT31(local_c._1_3_,2);
        local_bc = (undefined ***)0x0;
        FUN_007a03b0(param_1);
        local_bc = (undefined ***)0x79e094;
        SetEvent((HANDLE)**(undefined4 **)(param_1 + 0x68));
        piVar4 = *(int **)(param_1 + 0x6c);
        *(undefined4 *)(param_1 + 0x6c) = 0;
        *(undefined4 *)(param_1 + 0x68) = 0;
        if (piVar4 != (int *)0x0) {
          LOCK();
          iVar10 = piVar4[1] + -1;
          piVar4[1] = iVar10;
          UNLOCK();
          if (iVar10 == 0) {
            (**(code **)*piVar4)();
            LOCK();
            iVar10 = piVar4[2] + -1;
            piVar4[2] = iVar10;
            UNLOCK();
            if (iVar10 == 0) {
              (**(code **)(*piVar4 + 4))();
            }
          }
        }
        local_c._0_1_ = 1;
      }
    }
    cVar1 = *(char *)(param_1 + 0xc0);
  } while( true );
}


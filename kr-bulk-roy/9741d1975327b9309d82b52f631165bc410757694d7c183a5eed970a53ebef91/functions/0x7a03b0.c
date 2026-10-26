
void FUN_007a03b0(int param_1,int param_2,int *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 **ppuVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  undefined4 *puVar15;
  undefined1 local_78 [4];
  int *local_74;
  undefined4 local_70;
  undefined **local_68 [7];
  int local_4c;
  int *local_48;
  char *local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  int local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938e1a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = (undefined4 *)(uint)(*(int *)(param_1 + 0x50) != 0);
  if (*(int *)(param_1 + 0x58) != 0) {
    local_1c = (undefined4 *)0x2;
  }
  if (*(int *)(param_1 + 0x60) != 0) {
    local_1c = (undefined4 *)0x3;
  }
  local_70 = 0;
  local_74 = (int *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (local_74 == (int *)0x0) {
    local_40 = (char *)0x0;
    std::exception::exception((exception *)local_68,&local_40);
    local_68[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_68,&DAT_00c857a8);
  }
  *local_74 = (int)local_74;
  local_74[1] = (int)local_74;
  local_74[2] = (int)local_74;
  *(undefined1 *)(local_74 + 4) = 1;
  *(undefined1 *)((int)local_74 + 0x11) = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  if (*(char *)(param_2 + 8) != '\0') {
    if (*(undefined4 **)(param_2 + 4) == (undefined4 *)0xff) {
      local_24 = local_1c;
    }
    else {
      local_24 = *(undefined4 **)(param_2 + 4);
    }
    local_18 = (int *)(param_1 + 0x48);
    local_20 = (undefined4 *)0x0;
    do {
      iVar5 = *local_18;
      if ((iVar5 != 0) && (local_24 <= local_20)) {
        uVar13 = 0;
        if (*(int *)(iVar5 + 0x10) - *(int *)(iVar5 + 0xc) >> 2 != 0) {
          do {
            puVar2 = *(undefined4 **)(param_1 + 4);
            uVar12 = *(uint *)(uVar13 * 4 + *(int *)(iVar5 + 0xc));
            cVar1 = *(char *)((int)puVar2[1] + 0x19);
            local_28 = puVar2;
            puVar15 = (undefined4 *)puVar2[1];
            while (cVar1 == '\0') {
              if ((uint)puVar15[3] < uVar12) {
                puVar11 = (undefined4 *)puVar15[2];
                puVar15 = local_28;
              }
              else {
                puVar11 = (undefined4 *)*puVar15;
              }
              local_28 = puVar15;
              puVar15 = puVar11;
              cVar1 = *(char *)((int)puVar11 + 0x19);
            }
            if ((local_28 == puVar2) || (uVar12 < (uint)local_28[3])) {
              local_2c = puVar2;
              ppuVar8 = &local_2c;
            }
            else {
              ppuVar8 = &local_28;
            }
            if ((*ppuVar8 != puVar2) && (iVar5 = *(int *)((*ppuVar8)[4] + 0x54), iVar5 != 0)) {
              piVar9 = (int *)(iVar5 + 0x3c);
              if (0xf < *(uint *)(iVar5 + 0x50)) {
                piVar9 = (int *)*piVar9;
              }
              FID_conflict__wprintf("(%s)DECREF: %d\n",piVar9,*(int *)(iVar5 + 0x5c) + -1);
              *(int *)(iVar5 + 0x5c) = *(int *)(iVar5 + 0x5c) + -1;
            }
            uVar6 = FUN_006bde40(*(int *)(*local_18 + 0xc) + uVar13 * 4);
            FUN_0044bbd0(local_78,uVar6);
            iVar5 = *local_18;
            uVar13 = uVar13 + 1;
          } while (uVar13 < (uint)(*(int *)(iVar5 + 0x10) - *(int *)(iVar5 + 0xc) >> 2));
        }
        FID_conflict__wprintf("PreloadStack %d Released\n",local_20);
        piVar9 = (int *)local_18[1];
        local_18[1] = 0;
        *local_18 = 0;
        if (piVar9 != (int *)0x0) {
          LOCK();
          iVar5 = piVar9[1] + -1;
          piVar9[1] = iVar5;
          UNLOCK();
          if (iVar5 == 0) {
            (**(code **)*piVar9)();
            LOCK();
            iVar5 = piVar9[2] + -1;
            piVar9[2] = iVar5;
            UNLOCK();
            if (iVar5 == 0) {
              (**(code **)(*piVar9 + 4))();
            }
          }
        }
      }
      local_18 = local_18 + 2;
      local_20 = (undefined4 *)((int)local_20 + 1);
    } while (local_20 < (undefined4 *)0x4);
  }
  local_18 = local_1c;
  if (*(int *)(param_1 + 0x48) != 0) {
    local_18 = (undefined4 *)0x0;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    local_18 = (undefined4 *)0x1;
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    local_18 = (undefined4 *)0x2;
  }
  if (*(int *)(param_1 + 0x60) != 0) {
    local_18 = (undefined4 *)0x3;
  }
  if (*(undefined4 **)(param_2 + 4) != (undefined4 *)0xff) {
    local_18 = *(undefined4 **)(param_2 + 4);
  }
  local_24 = (undefined4 *)0x0;
  if (*(int *)(param_2 + 0x10) - *(int *)(param_2 + 0xc) >> 2 != 0) {
    do {
      puVar15 = local_24;
      puVar14 = (uint *)(*(int *)(param_2 + 0xc) + (int)local_24 * 4);
      puVar2 = *(undefined4 **)(param_1 + 4);
      local_24 = puVar2;
      if (*(char *)((int)puVar2[1] + 0x19) == '\0') {
        puVar11 = (undefined4 *)puVar2[1];
        do {
          if ((uint)puVar11[3] < *puVar14) {
            puVar7 = (undefined4 *)puVar11[2];
          }
          else {
            puVar7 = (undefined4 *)*puVar11;
            local_24 = puVar11;
          }
          puVar11 = puVar7;
        } while (*(char *)((int)puVar7 + 0x19) == '\0');
      }
      if ((local_24 == puVar2) || (*puVar14 < (uint)local_24[3])) {
        local_20 = puVar2;
        ppuVar8 = &local_20;
      }
      else {
        ppuVar8 = &local_24;
      }
      if (*ppuVar8 != puVar2) {
        if (*(int *)((*ppuVar8)[4] + 0x54) == 0) {
          FUN_0079d570(*puVar14);
        }
        puVar2 = *(undefined4 **)(param_1 + 4);
        uVar13 = *(uint *)(*(int *)(param_2 + 0xc) + (int)puVar15 * 4);
        cVar1 = *(char *)((int)puVar2[1] + 0x19);
        local_1c = puVar2;
        puVar11 = (undefined4 *)puVar2[1];
        while (cVar1 == '\0') {
          if ((uint)puVar11[3] < uVar13) {
            puVar7 = (undefined4 *)puVar11[2];
            puVar11 = local_1c;
          }
          else {
            puVar7 = (undefined4 *)*puVar11;
          }
          local_1c = puVar11;
          puVar11 = puVar7;
          cVar1 = *(char *)((int)puVar7 + 0x19);
        }
        if ((local_1c == puVar2) || (uVar13 < (uint)local_1c[3])) {
          local_30 = puVar2;
          ppuVar8 = &local_30;
        }
        else {
          ppuVar8 = &local_1c;
        }
        if ((*ppuVar8 != puVar2) && (iVar5 = *(int *)((*ppuVar8)[4] + 0x54), iVar5 != 0)) {
          piVar9 = (int *)(iVar5 + 0x3c);
          if (0xf < *(uint *)(iVar5 + 0x50)) {
            piVar9 = (int *)*piVar9;
          }
          FID_conflict__wprintf("(%s)ADDREF: %d\n",piVar9,*(int *)(iVar5 + 0x5c) + 1);
          *(int *)(iVar5 + 0x5c) = *(int *)(iVar5 + 0x5c) + 1;
        }
        uVar6 = FUN_006bde40(*(int *)(param_2 + 0xc) + (int)puVar15 * 4);
        FUN_0044bbd0(local_78,uVar6);
      }
      local_24 = (undefined4 *)((int)puVar15 + 1);
    } while (local_24 < (undefined4 *)(*(int *)(param_2 + 0x10) - *(int *)(param_2 + 0xc) >> 2));
  }
  piVar9 = local_18;
  if (*(int *)(param_1 + 0x48 + (int)local_18 * 8) == 0) {
    FID_conflict__wprintf("PreloadStack %d Stacked\n",local_18);
    local_4c = 0;
    local_48 = (int *)0x0;
    local_34 = param_2;
    if (param_3 != (int *)0x0) {
      piVar3 = param_3 + 1;
      iVar5 = param_3[1];
      while (iVar5 != 0) {
        LOCK();
        iVar10 = *piVar3;
        if (iVar5 == iVar10) {
          *piVar3 = iVar5 + 1;
          iVar10 = iVar5;
        }
        UNLOCK();
        piVar9 = local_18;
        if (iVar10 == iVar5) {
          local_48 = param_3;
          local_4c = param_2;
          break;
        }
        iVar5 = *piVar3;
      }
    }
    piVar3 = *(int **)(param_1 + 0x4c + (int)piVar9 * 8);
    *(int **)(param_1 + 0x4c + (int)piVar9 * 8) = local_48;
    *(int *)(param_1 + 0x48 + (int)piVar9 * 8) = local_4c;
    if (piVar3 != (int *)0x0) {
      LOCK();
      iVar5 = piVar3[1] + -1;
      piVar3[1] = iVar5;
      UNLOCK();
      if (iVar5 == 0) {
        (**(code **)*piVar3)();
        LOCK();
        iVar5 = piVar3[2] + -1;
        piVar3[2] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)(*piVar3 + 4))();
        }
      }
    }
  }
  else {
    local_20 = (undefined4 *)0x0;
    if (*(int *)(param_2 + 0x10) - *(int *)(param_2 + 0xc) >> 2 != 0) {
      do {
        iVar5 = *(int *)(param_1 + 0x48 + (int)local_18 * 8);
        puVar2 = *(undefined4 **)(iVar5 + 0x10);
        puVar14 = (uint *)(iVar5 + 0xc);
        puVar15 = (undefined4 *)(*(int *)(param_2 + 0xc) + (int)local_20 * 4);
        if ((puVar15 < puVar2) && (puVar11 = (undefined4 *)*puVar14, puVar11 <= puVar15)) {
          if (puVar2 == *(undefined4 **)(iVar5 + 0x14)) {
            uVar13 = (int)puVar2 - (int)puVar11 >> 2;
            if (0x3ffffffe < uVar13) {
LAB_007a0890:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar13 = uVar13 + 1;
            uVar12 = (int)*(undefined4 **)(iVar5 + 0x14) - (int)puVar11 >> 2;
            if (uVar12 < uVar13) {
              if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                uVar12 = 0;
              }
              else {
                uVar12 = uVar12 + (uVar12 >> 1);
              }
              if (uVar12 < uVar13) {
                uVar12 = uVar13;
              }
              FUN_00797980(uVar12);
            }
          }
          if (*(undefined4 **)(iVar5 + 0x10) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar5 + 0x10) =
                 *(undefined4 *)(*puVar14 + ((int)puVar15 - (int)puVar11 >> 2) * 4);
          }
        }
        else {
          if (puVar2 == *(undefined4 **)(iVar5 + 0x14)) {
            uVar13 = (int)((int)puVar2 - *puVar14) >> 2;
            if (0x3ffffffe < uVar13) goto LAB_007a0890;
            uVar13 = uVar13 + 1;
            uVar12 = (int)((int)*(undefined4 **)(iVar5 + 0x14) - *puVar14) >> 2;
            if (uVar12 < uVar13) {
              if (0x3fffffff - (uVar12 >> 1) < uVar12) {
                uVar12 = 0;
              }
              else {
                uVar12 = uVar12 + (uVar12 >> 1);
              }
              if (uVar12 < uVar13) {
                uVar12 = uVar13;
              }
              FUN_00797980(uVar12);
            }
          }
          if (*(undefined4 **)(iVar5 + 0x10) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar5 + 0x10) = *puVar15;
          }
        }
        puVar2 = local_20;
        *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 4;
        FID_conflict__wprintf
                  ("PreloadStack %d Added %d\n",local_18,
                   *(undefined4 *)(*(int *)(param_2 + 0xc) + (int)local_20 * 4));
        local_20 = (undefined4 *)((int)puVar2 + 1);
      } while (local_20 < (undefined4 *)(*(int *)(param_2 + 0x10) - *(int *)(param_2 + 0xc) >> 2));
    }
    FID_conflict__wprintf("PreloadStack %d Merged\n",local_18);
  }
  piVar9 = (int *)*local_74;
  if (piVar9 != local_74) {
    do {
      puVar2 = *(undefined4 **)(param_1 + 4);
      cVar1 = *(char *)((int)puVar2[1] + 0x19);
      local_38 = puVar2;
      puVar15 = (undefined4 *)puVar2[1];
      while (cVar1 == '\0') {
        if ((uint)puVar15[3] < (uint)piVar9[3]) {
          puVar11 = (undefined4 *)puVar15[2];
          puVar15 = local_38;
        }
        else {
          puVar11 = (undefined4 *)*puVar15;
        }
        local_38 = puVar15;
        puVar15 = puVar11;
        cVar1 = *(char *)((int)puVar11 + 0x19);
      }
      if ((local_38 == puVar2) || ((uint)piVar9[3] < (uint)local_38[3])) {
        local_3c = puVar2;
        ppuVar8 = &local_3c;
      }
      else {
        ppuVar8 = &local_38;
      }
      if ((*ppuVar8 != puVar2) && (iVar5 = *(int *)((*ppuVar8)[4] + 0x54), iVar5 != 0)) {
        if (*(int *)(iVar5 + 0x5c) == 0) {
          if (*(char *)(iVar5 + 0x60) != '\0') {
            FUN_007c4ff0();
          }
        }
        else {
          FUN_007c5be0();
        }
      }
      if (*(char *)((int)piVar9 + 0x11) == '\0') {
        piVar3 = (int *)piVar9[2];
        if (*(char *)((int)piVar3 + 0x11) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x11);
          piVar9 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x11);
            piVar9 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x11);
          piVar4 = (int *)piVar9[1];
          piVar3 = piVar9;
          while ((piVar9 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar9[2]))) {
            cVar1 = *(char *)(piVar9[1] + 0x11);
            piVar4 = (int *)piVar9[1];
            piVar3 = piVar9;
          }
        }
      }
    } while (piVar9 != local_74);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004ca160(*local_74,local_74);
  FUN_0089120c(local_74);
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    LOCK();
    iVar5 = param_3[1] + -1;
    param_3[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*param_3)();
      LOCK();
      iVar5 = param_3[2] + -1;
      param_3[2] = iVar5;
      UNLOCK();
      if (iVar5 == 0) {
        (**(code **)(*param_3 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return;
}


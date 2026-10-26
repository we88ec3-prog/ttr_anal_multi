
/* WARNING: Removing unreachable block (ram,0x00655074) */
/* WARNING: Removing unreachable block (ram,0x0065503e) */
/* WARNING: Removing unreachable block (ram,0x00655040) */

void FUN_00654f90(int param_1)

{
  int *piVar1;
  float fVar2;
  float *pfVar3;
  int *piVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  float *pfVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  void *pvVar14;
  float fVar15;
  int iVar16;
  uint *puVar17;
  int iVar18;
  int *piVar19;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int *local_44;
  int local_3c;
  float local_38;
  void *local_34;
  float local_30 [2];
  int *local_28;
  int *local_24;
  undefined4 local_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00916276;
  local_14 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  iVar16 = *(int *)(param_1 + 0xd4);
  local_54 = 0x1c;
  if (iVar16 == 2) {
    local_54 = 0x29;
  }
  else if (iVar16 == 3) {
    local_54 = 0x21;
  }
  local_4c = (iVar16 * -0xb4 + 800) / 2 + 0x5b;
  local_3c = 0;
  if (0 < iVar16) {
    local_44 = (int *)(param_1 + 0xac);
    local_58 = 0;
    do {
      iVar16 = *(int *)(param_1 + 0xd8);
      if (*(int *)(iVar16 + local_58) != *(int *)(iVar16 + 4 + local_58)) {
        *(int *)(iVar16 + 4 + local_58) = *(int *)(iVar16 + local_58);
      }
      iVar16 = *(int *)(param_1 + 0xe8);
      if (*(int *)(iVar16 + local_58) != *(int *)(iVar16 + 4 + local_58)) {
        *(int *)(iVar16 + local_58 + 4) = *(int *)(iVar16 + local_58);
      }
      FUN_00654730(uVar6);
      fVar2 = *(float *)(*local_44 + 0xc);
      local_50 = 0;
      local_5c = 0;
      iVar16 = 0x4e;
      FUN_00654800();
      local_c = 0;
      piVar19 = local_28;
      iVar12 = local_4c;
      if (local_28 != local_24) {
        do {
          iVar7 = *piVar19;
          if (iVar7 == 0) {
            if ((fVar2 == 0.0) || (piVar19 != local_24 + -1)) {
              local_50 = local_50 + local_54;
            }
            else {
              iVar7 = FUN_008fed10();
              local_50 = local_50 + iVar7;
            }
          }
          else if (iVar7 == 1) {
            if ((fVar2 == 0.0) || (piVar19 != local_24 + -1)) {
              local_5c = local_5c + -0xb4;
            }
            else {
              iVar7 = FUN_008fed10();
              local_5c = local_5c - iVar7;
            }
          }
          else if (iVar7 == 2) {
            if ((fVar2 == 0.0) || (piVar19 != local_24 + -1)) {
              local_5c = local_5c + 0xb4;
            }
            else {
              iVar7 = FUN_008fed10();
              local_5c = local_5c + iVar7;
            }
          }
          puVar17 = (uint *)(*(int *)(param_1 + 0xd8) + local_58);
          pfVar9 = (float *)puVar17[1];
          local_38 = (float)iVar12;
          local_34 = (void *)(float)iVar16;
          if (&local_38 < pfVar9) {
            pfVar3 = (float *)*puVar17;
            if (&local_38 < pfVar3) goto LAB_00655246;
            if (pfVar9 == (float *)puVar17[2]) {
              uVar8 = (int)pfVar9 - (int)pfVar3 >> 3;
              if (0x1ffffffe < uVar8) goto LAB_006554ad;
              uVar8 = uVar8 + 1;
              uVar13 = (int)puVar17[2] - (int)pfVar3 >> 3;
              if (uVar13 < uVar8) {
                if (0x1fffffff - (uVar13 >> 1) < uVar13) {
                  uVar13 = 0;
                }
                else {
                  uVar13 = uVar13 + (uVar13 >> 1);
                }
                if (uVar13 < uVar8) {
                  uVar13 = uVar8;
                }
                FUN_004e7330(uVar13);
              }
            }
            pfVar9 = (float *)puVar17[1];
            pfVar3 = (float *)(*puVar17 + ((int)&local_38 - (int)pfVar3 >> 3) * 8);
            if (pfVar9 != (float *)0x0) {
              *pfVar9 = *pfVar3;
              pvVar14 = (void *)pfVar3[1];
              goto LAB_0065529c;
            }
          }
          else {
LAB_00655246:
            if (pfVar9 == (float *)puVar17[2]) {
              uVar8 = (int)((int)pfVar9 - *puVar17) >> 3;
              if (0x1ffffffe < uVar8) goto LAB_006554ad;
              uVar8 = uVar8 + 1;
              uVar13 = (int)((int)puVar17[2] - *puVar17) >> 3;
              if (uVar13 < uVar8) {
                if (0x1fffffff - (uVar13 >> 1) < uVar13) {
                  uVar13 = 0;
                }
                else {
                  uVar13 = uVar13 + (uVar13 >> 1);
                }
                if (uVar13 < uVar8) {
                  uVar13 = uVar8;
                }
                FUN_004e7330(uVar13);
              }
            }
            pfVar9 = (float *)puVar17[1];
            if (pfVar9 != (float *)0x0) {
              *pfVar9 = local_38;
              pvVar14 = local_34;
LAB_0065529c:
              pfVar9[1] = (float)pvVar14;
            }
          }
          puVar17[1] = puVar17[1] + 8;
          local_30[0] = (float)(local_4c + local_5c);
          local_30[1] = (float)(local_50 + 0x4e);
          puVar17 = (uint *)(*(int *)(param_1 + 0xe8) + local_58);
          pfVar9 = (float *)puVar17[1];
          if ((local_30 < pfVar9) && (pfVar3 = (float *)*puVar17, pfVar3 <= local_30)) {
            if (pfVar9 == (float *)puVar17[2]) {
              uVar8 = (int)pfVar9 - (int)pfVar3 >> 3;
              if (0x1ffffffe < uVar8) {
LAB_006554ad:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar8 = uVar8 + 1;
              uVar13 = (int)puVar17[2] - (int)pfVar3 >> 3;
              if (uVar13 < uVar8) {
                if (0x1fffffff - (uVar13 >> 1) < uVar13) {
                  uVar13 = 0;
                }
                else {
                  uVar13 = uVar13 + (uVar13 >> 1);
                }
                if (uVar13 < uVar8) {
                  uVar13 = uVar8;
                }
                FUN_004e7330(uVar13);
              }
            }
            pfVar9 = (float *)puVar17[1];
            pfVar3 = (float *)(*puVar17 + ((int)local_30 - (int)pfVar3 >> 3) * 8);
            if (pfVar9 != (float *)0x0) {
              *pfVar9 = *pfVar3;
              fVar15 = pfVar3[1];
LAB_00655399:
              pfVar9[1] = fVar15;
            }
          }
          else {
            if (pfVar9 == (float *)puVar17[2]) {
              uVar8 = (int)((int)pfVar9 - *puVar17) >> 3;
              if (0x1ffffffe < uVar8) goto LAB_006554ad;
              uVar8 = uVar8 + 1;
              uVar13 = (int)((int)puVar17[2] - *puVar17) >> 3;
              if (uVar13 < uVar8) {
                if (0x1fffffff - (uVar13 >> 1) < uVar13) {
                  uVar13 = 0;
                }
                else {
                  uVar13 = uVar13 + (uVar13 >> 1);
                }
                if (uVar13 < uVar8) {
                  uVar13 = uVar8;
                }
                FUN_004e7330(uVar13);
              }
            }
            pfVar9 = (float *)puVar17[1];
            if (pfVar9 != (float *)0x0) {
              *pfVar9 = local_30[0];
              fVar15 = local_30[1];
              goto LAB_00655399;
            }
          }
          puVar17[1] = puVar17[1] + 8;
          piVar19 = piVar19 + 1;
          iVar16 = local_50 + 0x4e;
          iVar12 = local_4c + local_5c;
        } while (piVar19 != local_24);
      }
      local_c = 0xffffffff;
      if (local_28 != (int *)0x0) {
        FUN_0089120c(local_28);
      }
      local_44 = local_44 + 1;
      local_4c = local_4c + 0xb4;
      local_58 = local_58 + 0x10;
      local_3c = local_3c + 1;
      local_28 = (int *)0x0;
      local_24 = (int *)0x0;
      local_20 = 0;
    } while (local_3c < *(int *)(param_1 + 0xd4));
  }
  bVar5 = true;
  local_4c = 0;
  if (0 < *(int *)(param_1 + 0xd4)) {
    local_44 = (int *)0x0;
    piVar19 = (int *)(param_1 + 0xf8);
    do {
      iVar16 = *(int *)(param_1 + 0xe8);
      if (*(int *)(iVar16 + (int)local_44) != *(int *)(iVar16 + 4 + (int)local_44)) {
        iVar16 = *(int *)(iVar16 + 4 + (int)local_44);
        local_30[0] = *(float *)(iVar16 + -8);
        local_30[1] = *(float *)(iVar16 + -4);
        uVar10 = FUN_008fed10();
        uVar11 = FUN_008fed10(uVar10);
        FUN_00749a00(uVar11,uVar10);
      }
      iVar16 = *piVar19;
      if ((uint)*(byte *)(piVar19[-0x13] + 0x31) == *(byte *)(piVar19[-0x13] + 2) - 1) {
        iVar12 = *(int *)(param_1 + 0x138 + piVar19[-0xf] * 4);
        if ((((*(char *)(iVar16 + 0xa4) != '\0') && (*(int *)(iVar16 + 0x94) != 0)) &&
            (iVar7 = (**(code **)(**(int **)(iVar16 + 0x94) + 4))(), iVar7 == 0xbf6b)) &&
           (iVar16 = *(int *)(iVar16 + 0x94), *(int *)(iVar16 + 0x10) != iVar12)) {
          if (((iVar12 != 0) && (piVar4 = *(int **)(iVar12 + 8), piVar4 != (int *)0x0)) &&
             (piVar4[0x27] = piVar4[0x27] + 1, piVar4[0x27] == 1)) {
            (**(code **)(*piVar4 + 0x24))();
          }
          if ((*(int *)(iVar16 + 0x10) != 0) &&
             (piVar4 = *(int **)(*(int *)(iVar16 + 0x10) + 8), piVar4 != (int *)0x0)) {
            piVar1 = piVar4 + 0x27;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (**(code **)(*piVar4 + 0x28))();
            }
          }
          *(int *)(iVar16 + 0x10) = iVar12;
        }
        if (local_4c == *(int *)(param_1 + 0xcc)) {
          (**(code **)(**(int **)(param_1 + 0x108) + 0xd4))();
          (**(code **)(**(int **)(param_1 + 0x10c) + 0xd0))();
        }
        (**(code **)(*(int *)*piVar19 + 200))();
      }
      else {
        iVar12 = *(int *)(param_1 + 0x110 + piVar19[-0xf] * 4);
        if ((((*(char *)(iVar16 + 0xa4) != '\0') && (*(int *)(iVar16 + 0x94) != 0)) &&
            (iVar7 = (**(code **)(**(int **)(iVar16 + 0x94) + 4))(), iVar7 == 0xbf6b)) &&
           (iVar16 = *(int *)(iVar16 + 0x94), *(int *)(iVar16 + 0x10) != iVar12)) {
          if (((iVar12 != 0) && (piVar4 = *(int **)(iVar12 + 8), piVar4 != (int *)0x0)) &&
             (piVar4[0x27] = piVar4[0x27] + 1, piVar4[0x27] == 1)) {
            (**(code **)(*piVar4 + 0x24))();
          }
          if ((*(int *)(iVar16 + 0x10) != 0) &&
             (piVar4 = *(int **)(*(int *)(iVar16 + 0x10) + 8), piVar4 != (int *)0x0)) {
            piVar1 = piVar4 + 0x27;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (**(code **)(*piVar4 + 0x28))();
            }
          }
          *(int *)(iVar16 + 0x10) = iVar12;
        }
        if (local_4c == *(int *)(param_1 + 0xcc)) {
          (**(code **)(**(int **)(param_1 + 0x108) + 0xd0))();
          (**(code **)(**(int **)(param_1 + 0x10c) + 0xd4))();
        }
        (**(code **)(*(int *)*piVar19 + 200))();
        bVar5 = false;
      }
      local_44 = (int *)((int)local_44 + 0x10);
      local_4c = local_4c + 1;
      piVar19 = piVar19 + 1;
    } while (local_4c < *(int *)(param_1 + 0xd4));
    if (!bVar5) goto LAB_00655722;
  }
  if (*(char *)(param_1 + 0xa8) == '\0') {
    piVar19 = (int *)FUN_00891268(0x18);
    if (piVar19 == (int *)0x0) {
      piVar19 = (int *)0x0;
    }
    else {
      iVar16 = *(int *)(param_1 + 0xd0);
      piVar19[1] = -1;
      piVar19[2] = -1;
      piVar19[3] = 0;
      piVar19[4] = 0xf43a0;
      *piVar19 = (int)FoxUI::FXUIEventI1::vftable;
      piVar19[5] = iVar16;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 1;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar19);
    }
    if (piVar19 != (int *)0x0) {
      (**(code **)(*piVar19 + 0x10))(1);
    }
    *(undefined1 *)(param_1 + 0xa8) = 1;
  }
LAB_00655722:
  iVar16 = *(int *)(param_1 + 0xf8 + *(int *)(param_1 + 0xcc) * 4);
  iVar12 = (*(int *)(iVar16 + 0x10) - *(int *)(iVar16 + 8)) / 2;
  iVar18 = *(int *)(iVar16 + 8) + iVar12;
  iVar12 = *(int *)(iVar16 + 0x10) + iVar12;
  iVar7 = -((*(int *)(iVar16 + 0x14) - *(int *)(iVar16 + 0xc)) / 2);
  iStack_1c = *(int *)(iVar16 + 0x14) + iVar7;
  iVar7 = *(int *)(iVar16 + 0xc) + iVar7;
  (**(code **)(**(int **)(param_1 + 0x108) + 0xbc))(iVar18,iVar7,iVar12,iStack_1c);
  (**(code **)(**(int **)(param_1 + 0x10c) + 0xbc))(iVar18,iVar7,iVar12,local_30[1]);
  ExceptionList = local_34;
  return;
}


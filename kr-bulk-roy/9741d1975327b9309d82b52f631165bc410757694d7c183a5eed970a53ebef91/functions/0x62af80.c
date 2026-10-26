
void FUN_0062af80(int *param_1)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  void **ppvVar9;
  int iVar10;
  int *piVar11;
  void **ppvVar12;
  void **ppvVar13;
  void **local_34;
  void **local_30;
  void **local_2c;
  int *local_24;
  int local_20;
  uint local_1c;
  void *local_18 [4];
  int local_8;
  
  local_18[3] = &LAB_00928ce6;
  local_18[2] = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = local_18 + 2;
  local_24 = *(int **)((int)param_1 + 0x104);
  piVar11 = (int *)*local_24;
  param_1 = piVar11;
  if (piVar11 != local_24) {
    do {
      local_20 = piVar11[3];
      ppvVar13 = (void **)0x0;
      ppvVar9 = (void **)0x0;
      local_34 = (void **)0x0;
      local_30 = (void **)0x0;
      local_2c = (void **)0x0;
      local_8 = 0;
      local_1c = 0;
      if (piVar11[0x11] - piVar11[0x10] >> 2 != 0) {
        do {
          ppvVar12 = local_30;
          iVar2 = piVar11[0x10];
          iVar10 = local_1c * 4;
          if ((DAT_00fdfb10 & 1) == 0) {
            DAT_00fdfb10 = DAT_00fdfb10 | 1;
            local_8._0_1_ = 1;
            FUN_00590760(uVar6);
            _atexit((_func_4879 *)&LAB_00bce760);
            local_8 = (uint)local_8._1_3_ << 8;
            ppvVar9 = local_2c;
          }
          pvVar3 = *(void **)(iVar2 + iVar10);
          local_18[0] = pvVar3;
          if ((local_18 < ppvVar12) && (ppvVar13 <= local_18)) {
            iVar10 = (int)local_18 - (int)ppvVar13;
            if (ppvVar12 == ppvVar9) {
              uVar7 = (int)ppvVar12 - (int)ppvVar13 >> 2;
              if (0x3ffffffe < uVar7) {
LAB_0062b1b9:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar7 = uVar7 + 1;
              uVar8 = (int)ppvVar9 - (int)ppvVar13 >> 2;
              if (uVar8 < uVar7) {
                if (0x3fffffff - (uVar8 >> 1) < uVar8) {
                  uVar8 = 0;
                }
                else {
                  uVar8 = uVar8 + (uVar8 >> 1);
                }
                if (uVar8 < uVar7) {
                  uVar8 = uVar7;
                }
                FUN_00797980(uVar8);
                ppvVar9 = local_2c;
                ppvVar12 = local_30;
                ppvVar13 = local_34;
              }
            }
            if (ppvVar12 != (void **)0x0) {
              *ppvVar12 = ppvVar13[iVar10 >> 2];
            }
          }
          else {
            if (ppvVar12 == ppvVar9) {
              uVar7 = (int)ppvVar12 - (int)ppvVar13 >> 2;
              if (0x3ffffffe < uVar7) goto LAB_0062b1b9;
              uVar7 = uVar7 + 1;
              uVar8 = (int)ppvVar9 - (int)ppvVar13 >> 2;
              if (uVar8 < uVar7) {
                if (0x3fffffff - (uVar8 >> 1) < uVar8) {
                  uVar8 = 0;
                }
                else {
                  uVar8 = uVar8 + (uVar8 >> 1);
                }
                if (uVar8 < uVar7) {
                  uVar8 = uVar7;
                }
                FUN_00797980(uVar8);
                ppvVar9 = local_2c;
                ppvVar12 = local_30;
                ppvVar13 = local_34;
              }
            }
            if (ppvVar12 != (void **)0x0) {
              *ppvVar12 = pvVar3;
            }
          }
          local_1c = local_1c + 1;
          local_30 = ppvVar12 + 1;
          piVar11 = param_1;
        } while (local_1c < (uint)(param_1[0x11] - param_1[0x10] >> 2));
      }
      FUN_006d5010(&local_34);
      if (*(char *)((int)piVar11 + 0x89) == '\0') {
        piVar4 = (int *)piVar11[2];
        if (*(char *)((int)piVar4 + 0x89) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x89);
          piVar11 = piVar4;
          piVar4 = (int *)*piVar4;
          while (param_1 = piVar11, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x89);
            piVar11 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar11[1] + 0x89);
          piVar5 = (int *)piVar11[1];
          piVar4 = piVar11;
          while ((piVar11 = piVar5, param_1 = piVar11, cVar1 == '\0' &&
                 (piVar4 == (int *)piVar11[2]))) {
            cVar1 = *(char *)(piVar11[1] + 0x89);
            piVar5 = (int *)piVar11[1];
            piVar4 = piVar11;
          }
        }
      }
      local_8 = 0xffffffff;
      if (ppvVar13 != (void **)0x0) {
        FUN_0089120c(ppvVar13);
      }
    } while (piVar11 != local_24);
  }
  ExceptionList = local_18[2];
  return;
}



void FUN_005572a0(int param_1)

{
  char cVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  float10 fVar10;
  float10 fVar11;
  
  piVar9 = (int *)**(int **)(param_1 + 4);
  if (piVar9 != *(int **)(param_1 + 4)) {
    do {
      if (DAT_00fba7cc == 0) {
        iVar8 = FUN_00891268(0x1380);
        if (iVar8 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          *(undefined8 *)(iVar8 + 0x1350) = 0;
          *(undefined8 *)(iVar8 + 0x1358) = 0;
          *(undefined4 *)(iVar8 + 0x1370) = 1;
          *(undefined4 *)(iVar8 + 0x1374) = 1;
          *(undefined8 *)(iVar8 + 0x1368) = 0x3fa1111111111111;
          *(undefined4 *)(iVar8 + 0x1378) = 0;
          *(undefined4 *)(iVar8 + 0x1360) = 0x1e;
          FUN_006df660();
          DAT_00fba7cc = iVar8;
        }
      }
      iVar8 = DAT_00fba7cc;
      if ((DAT_00d63d09 != '\0') &&
         (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      fVar3 = (float)*(int *)(iVar8 + 0x28);
      if (*(int *)(iVar8 + 0x28) < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      if (DAT_00fba7cc == 0) {
        iVar8 = FUN_00891268(0x1380);
        if (iVar8 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          *(undefined8 *)(iVar8 + 0x1350) = 0;
          *(undefined8 *)(iVar8 + 0x1358) = 0;
          *(undefined4 *)(iVar8 + 0x1370) = 1;
          *(undefined4 *)(iVar8 + 0x1374) = 1;
          *(undefined8 *)(iVar8 + 0x1368) = 0x3fa1111111111111;
          *(undefined4 *)(iVar8 + 0x1378) = 0;
          *(undefined4 *)(iVar8 + 0x1360) = 0x1e;
          FUN_006df660();
          DAT_00fba7cc = iVar8;
        }
      }
      iVar8 = DAT_00fba7cc;
      if ((DAT_00d63d09 != '\0') &&
         (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      fVar4 = (float)*(int *)(iVar8 + 0x2c);
      if (*(int *)(iVar8 + 0x2c) < 0) {
        fVar4 = fVar4 + 4.2949673e+09;
      }
      iVar8 = piVar9[4];
      fVar5 = *(float *)(iVar8 + 0x18) - *(float *)(iVar8 + 8);
      fVar6 = *(float *)(iVar8 + 0x1c) - *(float *)(iVar8 + 0xc);
      fVar10 = (float10)FUN_008fef70();
      *(float *)(piVar9[4] + 0x20) = (float)fVar10 + (float)fVar10;
      fVar10 = (float10)FUN_008ff0a0();
      fVar11 = (float10)FUN_008fef70();
      iVar8 = piVar9[4];
      *(float *)(iVar8 + 0x18) = (float)fVar10 * 200.0 + fVar3 * 0.5;
      *(float *)(iVar8 + 0x1c) = fVar4 * 0.5 + (float)fVar11 * 60.0;
      *(float *)(piVar9[4] + 0x20) =
           ((*(float *)(piVar9[4] + 0xc) - fVar4 * 0.5) + 60.0) / 120.0 + 0.5;
      if (fVar5 * fVar5 + fVar6 * fVar6 <= 2.829) {
        iVar8 = piVar9[4];
        fVar10 = (float10)FUN_008fedca();
        *(float *)(iVar8 + 0x24) = (float)fVar10 + 1.5707964;
      }
      if (*(char *)((int)piVar9 + 0x15) == '\0') {
        piVar2 = (int *)piVar9[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar9 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar9 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x15);
          piVar7 = (int *)piVar9[1];
          piVar2 = piVar9;
          while ((piVar9 = piVar7, cVar1 == '\0' && (piVar2 == (int *)piVar9[2]))) {
            cVar1 = *(char *)(piVar9[1] + 0x15);
            piVar7 = (int *)piVar9[1];
            piVar2 = piVar9;
          }
        }
      }
    } while (piVar9 != *(int **)(param_1 + 4));
  }
  piVar9 = (int *)**(int **)(param_1 + 4);
  if (piVar9 != *(int **)(param_1 + 4)) {
    do {
      FUN_00556a20();
      if (*(char *)((int)piVar9 + 0x15) == '\0') {
        piVar2 = (int *)piVar9[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar9 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar9 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x15);
          piVar7 = (int *)piVar9[1];
          piVar2 = piVar9;
          while ((piVar9 = piVar7, cVar1 == '\0' && (piVar2 == (int *)piVar9[2]))) {
            cVar1 = *(char *)(piVar9[1] + 0x15);
            piVar7 = (int *)piVar9[1];
            piVar2 = piVar9;
          }
        }
      }
    } while (piVar9 != *(int **)(param_1 + 4));
  }
  return;
}


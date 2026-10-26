
void FUN_0080b410(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *_Str2;
  uint uVar10;
  int *piVar11;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar12;
  char *_Str1;
  float10 fVar13;
  int local_2c;
  int local_28;
  float local_24;
  LPCRITICAL_SECTION local_20;
  float local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c270;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x23);
  local_20 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  local_18 = (int *)param_1[0x17];
  piVar12 = (int *)*local_18;
  if ((int *)*local_18 != local_18) {
    do {
      iVar9 = piVar12[2];
      if (((*(int *)(iVar9 + 0x24) < 1) &&
          (((*(int *)(iVar9 + 8) == 0 ||
            (iVar8 = (**(code **)(**(int **)(iVar9 + 8) + 0x10))(uVar7), iVar8 == 0)) &&
           (*(int *)(iVar9 + 0xc) != 0)))) && (*(int *)(iVar9 + 0x20) == 0)) {
        iVar9 = piVar12[2];
        if (iVar9 != 0) {
          FUN_0080cb90();
          FUN_0089120c(iVar9);
          piVar12[2] = 0;
        }
        piVar11 = (int *)*piVar12;
        if (piVar12 != (int *)param_1[0x17]) {
          *(int **)piVar12[1] = piVar11;
          *(int *)(*piVar12 + 4) = piVar12[1];
          FUN_0089120c(piVar12);
          param_1[0x18] = param_1[0x18] + -1;
        }
      }
      else {
        piVar11 = (int *)*piVar12;
      }
      lpCriticalSection = local_20;
      piVar12 = piVar11;
    } while (piVar11 != local_18);
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
  puVar2 = (undefined4 *)param_1[0x13];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    puVar3[10] = 0;
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar6 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  local_18 = (int *)param_1[0x17];
  piVar12 = (int *)*local_18;
  local_14 = piVar12;
  if (piVar12 != local_18) {
    do {
      iVar9 = piVar12[2];
      iVar8 = *(int *)(iVar9 + 4);
      _Str1 = (char *)(iVar8 + 0x18);
      local_14 = piVar12;
      if (*(int *)(iVar9 + 8) == 0) {
        fVar13 = (float10)0;
      }
      else {
        fVar13 = (float10)(**(code **)(**(int **)(iVar9 + 8) + 0x30))();
      }
      local_1c = (float)fVar13;
      fVar13 = (float10)(**(code **)(**(int **)(piVar12[2] + 4) + 0x20))();
      local_24 = (float)fVar13;
      iVar9 = piVar12[2];
      if (((0 < *(int *)(iVar9 + 0x24)) ||
          ((*(int *)(iVar9 + 8) != 0 &&
           (iVar9 = (**(code **)(**(int **)(iVar9 + 8) + 0x10))(), iVar9 != 0)))) &&
         ((local_1c < (float)param_1[0x16] * local_24 && (local_1c != 0.0)))) {
        local_28 = FUN_0080c1c0(_Str1);
        if (local_28 == param_1[0x13]) {
LAB_0080b63c:
          local_2c = param_1[0x13];
          piVar11 = &local_2c;
        }
        else {
          uVar7 = *(uint *)(local_28 + 0x1c);
          _Str2 = (char *)(local_28 + 0xc);
          if (0xf < *(uint *)(local_28 + 0x20)) {
            _Str2 = *(char **)_Str2;
          }
          uVar5 = *(uint *)(iVar8 + 0x28);
          uVar10 = uVar5;
          if (uVar7 <= uVar5) {
            uVar10 = uVar7;
          }
          if (0xf < *(uint *)(iVar8 + 0x2c)) {
            _Str1 = *(char **)_Str1;
          }
          uVar10 = __strnicmp(_Str1,_Str2,uVar10);
          if (uVar10 == 0) {
            if (uVar5 < uVar7) {
              uVar10 = 0xffffffff;
            }
            else {
              uVar10 = (uint)(uVar5 != uVar7);
            }
          }
          if ((int)uVar10 < 0) goto LAB_0080b63c;
          piVar11 = &local_28;
        }
        piVar12 = local_14;
        if (*piVar11 != param_1[0x13]) {
          piVar11 = (int *)(*piVar11 + 0x28);
          *piVar11 = *piVar11 + 1;
        }
      }
      piVar12 = (int *)*piVar12;
      local_14 = piVar12;
    } while (piVar12 != local_18);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1d));
  local_8 = 1;
  (**(code **)(*(int *)*param_1 + 0x14))();
  local_8 = 0xffffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1d));
  puVar2 = (undefined4 *)param_1[0xf];
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    piVar12 = (int *)puVar3[10];
    if (piVar12[0xd] != 0) {
      piVar12[0xd] = piVar12[0xd] + -1;
    }
    if (((piVar12[0xd] == 0) && (piVar12[0xe] == 0)) && (piVar12[3] != 0)) {
      (**(code **)(*piVar12 + 8))();
    }
    if (*(int *)(puVar3[10] + 0xc) != 0) {
      param_1[0x2a] = param_1[0x2a] + 1;
    }
    param_1[0x29] = param_1[0x29] + 1;
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar6 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}


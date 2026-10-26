
void FUN_007bbe10(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00935048;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00d63c68 = 0;
  SetEvent(*(HANDLE *)(param_1 + 100));
  WaitForSingleObject(DAT_00d63c6c,0xffffffff);
  CloseHandle(DAT_00d63c6c);
  DAT_00d63c6c = (HANDLE)0xffffffff;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  piVar4 = DAT_00fb76a8;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  FUN_007bd600(param_1 + 0x34);
  piVar8 = (int *)**(int **)(param_1 + 0x28);
  if (piVar8 != *(int **)(param_1 + 0x28)) {
    do {
      puVar2 = (undefined4 *)piVar8[10];
      if (puVar2[7] != 0) {
        if ((uint)piVar8[8] < 0x10) {
          piVar9 = piVar8 + 3;
        }
        else {
          piVar9 = (int *)piVar8[3];
        }
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8 = 2;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8 = 0xffffffff;
        }
        iVar3 = *piVar4;
        uVar7 = FUN_0079be00(piVar9);
        (**(code **)(iVar3 + 0x6c))(uVar7);
      }
      if (0xf < (uint)puVar2[5]) {
        FUN_0089120c(*puVar2);
      }
      puVar2[5] = 0xf;
      puVar2[4] = 0;
      *(undefined1 *)puVar2 = 0;
      FUN_0089120c(puVar2);
      if (*(char *)((int)piVar8 + 0x2d) == '\0') {
        piVar9 = (int *)piVar8[2];
        if (*(char *)((int)piVar9 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar9 + 0x2d);
          piVar8 = piVar9;
          piVar9 = (int *)*piVar9;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar9 + 0x2d);
            piVar8 = piVar9;
            piVar9 = (int *)*piVar9;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x2d);
          piVar5 = (int *)piVar8[1];
          piVar9 = piVar8;
          while ((piVar8 = piVar5, cVar1 == '\0' && (piVar9 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x2d);
            piVar5 = (int *)piVar8[1];
            piVar9 = piVar8;
          }
        }
      }
    } while (piVar8 != *(int **)(param_1 + 0x28));
  }
  FUN_007b7d40(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
  uVar6 = DAT_00fb79e8 & 1;
  *(int *)(*(int *)(param_1 + 0x28) + 4) = *(int *)(param_1 + 0x28);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(int *)(*(int *)(param_1 + 0x28) + 8) = *(int *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if (uVar6 == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 3;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  piVar4 = *(int **)(param_1 + 0x5c);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  ExceptionList = local_10;
  return;
}


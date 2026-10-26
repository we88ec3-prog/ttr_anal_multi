
void FUN_007e8420(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  undefined1 local_20 [4];
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937858;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = *(int **)(param_2 + 4);
  piVar9 = (int *)*local_1c;
  local_14 = piVar9;
  if (piVar9 != local_1c) {
    do {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 0;
        FUN_00798de0(uVar4);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      piVar6 = DAT_00fb76a8;
      local_18 = DAT_00fb76a8;
      if ((uint)piVar9[0x10] < 0x10) {
        piVar10 = piVar9 + 0xb;
      }
      else {
        piVar10 = (int *)piVar9[0xb];
      }
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 1;
        FUN_00798de0(uVar4);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 2;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      puVar5 = (uint *)(**(code **)(*DAT_00fb76a8 + 0x54))(local_20,piVar10);
      uVar11 = *puVar5;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
      if (uVar11 == 0) {
LAB_007e8576:
        puVar8 = (undefined4 *)0x0;
      }
      else {
        uVar7 = uVar11 & 0xffff;
        if (((uint)((local_18[0x41] - piVar6[0x40]) / 0x34) <= uVar7) ||
           (*(uint *)(local_18[0x44] + uVar7 * 4) != uVar11 >> 0x10)) goto LAB_007e8576;
        puVar8 = (undefined4 *)(uVar7 * 0x34 + piVar6[0x40]);
      }
      uVar2 = *puVar8;
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 3;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      piVar6 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
      (**(code **)(*piVar6 + 0x104))(piVar6,0,uVar2);
      uVar7 = piVar9[0x13] - piVar9[0x12] >> 2;
      FUN_007f3540();
      uVar11 = 0;
      if (uVar7 != 0) {
        do {
          iVar3 = *(int *)(piVar9[0x12] + uVar11 * 4);
          *(int *)(iVar3 + 0x3ecc) = *(int *)(iVar3 + 0x3ecc) + -1;
          FUN_007f3210(*(undefined4 *)(iVar3 + 0xa8),*(int *)(iVar3 + 0xac) * 3,iVar3 + 0x38b0,
                       iVar3 + 0xb0);
          uVar11 = uVar11 + 1;
          piVar9 = local_14;
        } while (uVar11 < uVar7);
      }
      iVar3 = *(int *)(param_1 + 0x24);
      if (((*(int *)(iVar3 + 4) != 0) && (*(int *)(iVar3 + 8) != 0)) &&
         ((FUN_007f33a0(), *(uint *)(iVar3 + 0x14) <= *(uint *)(iVar3 + 0x24) ||
          (*(uint *)(iVar3 + 0x1c) <= *(uint *)(iVar3 + 0x2c))))) {
        *(undefined4 *)(iVar3 + 0x2c) = 0;
        *(undefined4 *)(iVar3 + 0x24) = 0;
      }
      if (*(char *)((int)piVar9 + 0x59) == '\0') {
        piVar6 = (int *)piVar9[2];
        if (*(char *)((int)piVar6 + 0x59) == '\0') {
          cVar1 = *(char *)(*piVar6 + 0x59);
          piVar9 = piVar6;
          piVar6 = (int *)*piVar6;
          while (local_14 = piVar9, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar6 + 0x59);
            piVar9 = piVar6;
            piVar6 = (int *)*piVar6;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x59);
          piVar10 = (int *)piVar9[1];
          piVar6 = piVar9;
          while ((piVar9 = piVar10, local_14 = piVar9, cVar1 == '\0' && (piVar6 == (int *)piVar9[2])
                 )) {
            cVar1 = *(char *)(piVar9[1] + 0x59);
            piVar10 = (int *)piVar9[1];
            piVar6 = piVar9;
          }
        }
      }
    } while (piVar9 != local_1c);
  }
  FUN_007e88a0(*(undefined4 *)(*(int *)(param_2 + 4) + 4));
  *(int *)(*(int *)(param_2 + 4) + 4) = *(int *)(param_2 + 4);
  *(undefined4 *)*(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 4);
  *(int *)(*(int *)(param_2 + 4) + 8) = *(int *)(param_2 + 4);
  *(undefined4 *)(param_2 + 8) = 0;
  ExceptionList = local_10;
  return;
}



void FUN_007be770(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  undefined1 local_24 [4];
  float local_20;
  float local_1c;
  float local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00934f0e;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = (float)FUN_00891268(0xe8,uVar5);
  local_8 = 0;
  if (local_20 == 0.0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0077ebb0();
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(param_1 + 4) = uVar6;
  local_20 = (float)FUN_00891268(0xe8,uVar5);
  local_8 = 1;
  if (local_20 == 0.0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0077ebb0();
  }
  uVar5 = DAT_00fb79e8 & 1;
  *(undefined4 *)(param_1 + 8) = uVar6;
  if (uVar5 == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  local_14 = *(int *)(param_1 + 0x18);
  if (local_14 != *(int *)(param_1 + 0x14)) {
    do {
      iVar4 = *(int *)(local_14 + -4);
      piVar10 = *(int **)(iVar4 + 0x54);
      if ((*(int **)(iVar4 + 0x54) == (int *)0x0) &&
         (piVar10 = DAT_00fb76b4, (DAT_00fb79e8 & 1) == 0)) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 3;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
        piVar10 = DAT_00fb76b4;
      }
      iVar7 = (**(code **)(*piVar10 + 0xc))();
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 4;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 5;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      puVar8 = (undefined4 *)(**(code **)(*DAT_00fb76a8 + 0x54))(local_24,iVar4);
      local_18 = (float)*puVar8;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
      iVar9 = FUN_00843ef0();
      *(float *)(iVar9 + 0xb8) = local_18;
      fVar1 = *(float *)(iVar4 + 0x40) / 10.0;
      fVar2 = *(float *)(iVar4 + 0x44) / 10.0;
      if (((fVar1 != *(float *)(iVar7 + 0x84)) || (fVar2 != *(float *)(iVar7 + 0x88))) ||
         (*(float *)(iVar7 + 0x8c) != 1.0)) {
        *(undefined4 *)(iVar7 + 0xc0) = 0;
        *(float *)(iVar7 + 0x84) = fVar1;
        *(float *)(iVar7 + 0x88) = fVar2;
        *(undefined4 *)(iVar7 + 0x8c) = 0x3f800000;
      }
      local_1c = *(float *)(iVar4 + 0x48);
      local_20 = *(float *)(iVar4 + 0x4c);
      local_18 = *(float *)(iVar4 + 0x50);
      if (((local_1c != *(float *)(iVar7 + 0x68)) || (local_20 != *(float *)(iVar7 + 0x6c))) ||
         (local_18 != *(float *)(iVar7 + 0x70))) {
        *(undefined4 *)(iVar7 + 0xc0) = 0;
        *(float *)(iVar7 + 0x68) = local_1c;
        *(float *)(iVar7 + 0x6c) = local_20;
        *(float *)(iVar7 + 0x70) = local_18;
      }
      *(int *)(iVar4 + 0x58) = iVar7;
      (**(code **)(**(int **)(param_1 + 8) + 0x40))(iVar7);
      local_14 = local_14 + -4;
    } while (local_14 != *(int *)(param_1 + 0x14));
  }
  (**(code **)(**(int **)(param_1 + 4) + 0x40))(*(undefined4 *)(param_1 + 8));
  fVar1 = *(float *)(param_1 + 0x10);
  iVar4 = *(int *)(param_1 + 4);
  fVar2 = *(float *)(param_1 + 0x10);
  fVar3 = *(float *)(param_1 + 0x10);
  if (((fVar1 == *(float *)(iVar4 + 0x84)) && (fVar2 == *(float *)(iVar4 + 0x88))) &&
     (fVar3 == *(float *)(iVar4 + 0x8c))) {
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(iVar4 + 0xc0) = 0;
  *(float *)(iVar4 + 0x84) = fVar1;
  *(float *)(iVar4 + 0x88) = fVar2;
  *(float *)(iVar4 + 0x8c) = fVar3;
  ExceptionList = local_10;
  return;
}


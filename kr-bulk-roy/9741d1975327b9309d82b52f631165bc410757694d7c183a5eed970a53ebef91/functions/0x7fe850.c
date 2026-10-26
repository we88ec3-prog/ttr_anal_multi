
undefined4 FUN_007fe850(undefined4 param_1)

{
  float fVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  undefined1 local_5c [44];
  float local_30;
  float local_2c;
  float local_28;
  int local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00934588;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 4) != 0) {
    return 0;
  }
  if (((DAT_00fba850 == 0) && (**(int **)(in_ECX + 0x7c) == 0)) &&
     (*(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58) >> 2 == 0)) {
    return 0;
  }
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar6 = DAT_00fb76e8;
  local_24 = DAT_00fb76e8;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  pfVar3 = (float *)(**(code **)(**(int **)(iVar6 + 4) + 0x24))(local_5c);
  local_30 = *pfVar3;
  local_2c = pfVar3[1];
  local_28 = pfVar3[2];
  local_1c = local_30 - *(float *)(in_ECX + 0x34);
  fVar1 = local_2c - *(float *)(in_ECX + 0x38);
  local_18 = local_28 - *(float *)(in_ECX + 0x3c);
  local_20 = local_18 * local_18 + local_1c * local_1c + fVar1 * fVar1;
  fVar9 = (float10)FUN_004ad080(local_20);
  local_20 = (float)fVar9;
  local_1c = local_20 - *(float *)(in_ECX + 0x40);
  iVar4 = FUN_007cb600(param_1,*(undefined4 *)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x38),
                       *(undefined4 *)(in_ECX + 0x3c),*(undefined4 *)(in_ECX + 0x40));
  local_20 = *(float *)(iVar6 + 0x24);
  iVar7 = 0;
  if ((local_1c < local_20) || (DAT_00fba850 != 0)) {
    if (iVar4 != 0) {
      iVar7 = FUN_00798440(iVar6,*(undefined4 *)(in_ECX + 0x28));
    }
    if ((DAT_00fba850 != 0) || ((iVar7 != 0 && (**(int **)(in_ECX + 0x7c) != 0)))) {
      if (*(int *)(in_ECX + 0x30) != *(int *)(in_ECX + 0x28)) goto LAB_007fea1d;
      uVar5 = *(undefined4 *)(in_ECX + 0x2c);
      goto LAB_007fea13;
    }
    if (*(int *)(in_ECX + 0x30) != *(int *)(in_ECX + 0x2c)) goto LAB_007fea1d;
    *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 0x28);
  }
  else {
    if (*(int *)(in_ECX + 0x30) != *(int *)(in_ECX + 0x2c)) goto LAB_007fea1d;
    uVar5 = *(undefined4 *)(in_ECX + 0x28);
LAB_007fea13:
    *(undefined4 *)(in_ECX + 0x30) = uVar5;
  }
  *(undefined4 *)(in_ECX + 0x78) = 1;
LAB_007fea1d:
  if (iVar4 != 0) {
    local_18 = 0.0;
    local_14 = *(float *)(iVar6 + 0x24);
    uVar8 = *(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58) >> 2;
    uVar2 = 0;
    if (uVar8 != 0) {
      do {
        local_20 = 0.0;
        if (local_1c < local_14) {
          uVar5 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x30))
                            (*(undefined4 *)(*(int *)(in_ECX + 0x58) + uVar2 * 4),0,&local_20,
                             local_14);
          iVar6 = FUN_007c9470(param_1,uVar5);
          if ((iVar6 != 0) && (local_18 < local_20)) {
            local_18 = local_20;
          }
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar8);
    }
    local_20 = local_14 - local_18;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb771c);
    if ((local_20 < *(float *)(local_24 + 0xd4)) &&
       (!NAN(local_20) && 0.0 < local_20 != (local_20 == 0.0))) {
      *(float *)(local_24 + 0xd4) = local_20 - 3.0;
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 3;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb771c);
  }
  ExceptionList = local_10;
  return 0;
}


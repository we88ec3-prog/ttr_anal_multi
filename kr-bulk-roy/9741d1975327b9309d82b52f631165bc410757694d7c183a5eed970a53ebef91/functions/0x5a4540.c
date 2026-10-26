
void FUN_005a4540(void)

{
  float fVar1;
  uint uVar2;
  DWORD DVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  bool bVar7;
  undefined8 uVar8;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093ae9c;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  iVar4 = *(int *)(in_ECX + 0xb4);
  if ((((iVar4 != 0) && (*(char *)(iVar4 + 0xa8) == '\0')) && (*(int *)(iVar4 + 0x9c) != 0)) &&
     (DVar3 = timeGetTime(), 0x5dc < DVar3 - *(int *)(iVar4 + 0xa4))) {
    FUN_006bd400();
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x14c) + 0x28) >> 8 & 1) != 0) {
    iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0x14c) + 0xf4) + 0xc4);
    FUN_006477c0(uVar2);
    *(float *)(in_ECX + 0x160) = (float)iVar4 / 100.0;
  }
  if (*(char *)(in_ECX + 0x15c) == '\0') {
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_c = 0;
      FUN_00560170();
      _atexit((_func_4879 *)&LAB_00bcd110);
      local_c = 0xffffffff;
    }
    bVar7 = DAT_00fb73e8 != 0;
    if (*(char *)(in_ECX + 0x154) == '\0') {
      if (bVar7) {
        FUN_005a55e0(2);
        FUN_005a5760(in_ECX);
        FUN_005a57a0();
      }
    }
    else if (!bVar7) {
      FUN_005a55e0(1);
    }
    *(bool *)(in_ECX + 0x154) = bVar7;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if ((*(int *)(in_ECX + 0x140) == 0) ||
     ((*(uint *)(*(int *)(in_ECX + 0x140) + 0x28) >> 8 & 1) == 0)) goto LAB_005a488f;
  iVar4 = FUN_00404aa0();
  if (*(int *)(iVar4 + 0x13cc) == 0) {
LAB_005a46d9:
    piVar6 = *(int **)(in_ECX + 0x140);
    piVar5 = (int *)FUN_00443da0();
    if (((DAT_00f948b8 < *piVar5) || (piVar5[2] < DAT_00f948b8)) ||
       ((DAT_00f948bc < piVar5[1] || (piVar5[3] < DAT_00f948bc)))) goto LAB_005a4709;
LAB_005a4757:
    if (*(float *)(in_ECX + 0x138) < 1.0) {
      fVar1 = *(float *)(in_ECX + 0x138) + 0.06666667;
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
      *(float *)(in_ECX + 0x138) = fVar1;
      (**(code **)(*piVar6 + 0xd8))(fVar1);
      FUN_006453a0(*(undefined4 *)(in_ECX + 0x138));
      (**(code **)(**(int **)(in_ECX + 0x140) + 200))();
    }
  }
  else {
    piVar6 = *(int **)(in_ECX + 0x140);
    piVar5 = (int *)FUN_00745c20();
    if (piVar5 == piVar6) goto LAB_005a46d9;
LAB_005a4709:
    iVar4 = 0;
    piVar5 = piVar6 + 0x4f;
    do {
      if ((*(uint *)(*piVar5 + 0x28) >> 8 & 1) != 0) goto LAB_005a4757;
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < 5);
    if (*(float *)(in_ECX + 0x160) < *(float *)(in_ECX + 0x138)) {
      fVar1 = *(float *)(in_ECX + 0x138) - 0.06666667;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0;
      }
      *(float *)(in_ECX + 0x138) = fVar1;
      (**(code **)(*piVar6 + 0xd8))(fVar1);
      FUN_006453a0(*(undefined4 *)(in_ECX + 0x138));
      (**(code **)(**(int **)(in_ECX + 0x140) + 200))();
    }
  }
  if (*(float *)(in_ECX + 0x138) < *(float *)(in_ECX + 0x160)) {
    fVar1 = *(float *)(in_ECX + 0x138) + 0.06666667;
    if (1.0 <= fVar1) {
      fVar1 = 1.0;
    }
    *(float *)(in_ECX + 0x138) = fVar1;
    (**(code **)(**(int **)(in_ECX + 0x140) + 0xd8))(fVar1);
    FUN_006453a0(*(undefined4 *)(in_ECX + 0x138));
    (**(code **)(**(int **)(in_ECX + 0x140) + 200))();
  }
LAB_005a488f:
  if (*(char *)(in_ECX + 0x13c) == '\0') {
    if ((*(int *)(in_ECX + 0x144) != 0) &&
       ((*(uint *)(*(int *)(in_ECX + 0x144) + 0x28) >> 8 & 1) != 0)) {
      iVar4 = FUN_00404aa0();
      if (*(int *)(iVar4 + 0x13d0) == 0) {
        iVar4 = *(int *)(in_ECX + 0x144);
        if (*(char *)(iVar4 + 0x144) != '\0') {
          FUN_00641d90(iVar4);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        uVar8 = FUN_00745c20();
        iVar4 = (int)((ulonglong)uVar8 >> 0x20);
        if ((int)uVar8 == iVar4) {
          ExceptionList = local_14;
          return;
        }
      }
      FUN_00641d90(iVar4);
      (**(code **)(**(int **)(in_ECX + 0x144) + 0xd4))();
      ExceptionList = local_14;
      return;
    }
  }
  else {
    *(undefined1 *)(in_ECX + 0x13c) = 0;
  }
  ExceptionList = local_14;
  return;
}


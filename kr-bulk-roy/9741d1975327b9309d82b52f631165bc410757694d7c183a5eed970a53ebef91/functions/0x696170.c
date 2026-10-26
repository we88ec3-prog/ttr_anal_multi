
void FUN_00696170(void)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  int local_2c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00942aaa;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  if ((DAT_00fc7f1c & 1) == 0) {
    DAT_00fc7f1c = DAT_00fc7f1c | 1;
    local_c = 1;
    FUN_0053c300();
    _atexit(FUN_00bce1d0);
  }
  iVar4 = DAT_00fcdddc;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 2;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_c = 0xffffffff;
  if ((*(int *)(in_ECX + 0x94) == 0) || ((*(uint *)(*(int *)(in_ECX + 0x94) + 0x28) >> 8 & 1) == 0))
  goto LAB_0069634a;
  iVar2 = FUN_00404aa0();
  if ((*(int *)(iVar2 + 0x13cc) == 0) || (iVar2 = FUN_00745c20(), iVar2 == in_ECX)) {
    piVar5 = *(int **)(in_ECX + 0x94);
    piVar3 = (int *)FUN_00443da0();
    if ((((DAT_00f948b8 < *piVar3) || (piVar3[2] < DAT_00f948b8)) || (DAT_00f948bc < piVar3[1])) ||
       (piVar3[3] < DAT_00f948bc)) goto LAB_006962e9;
    if (1.0 <= *(float *)(in_ECX + 0x80)) goto LAB_0069634a;
    fVar1 = *(float *)(in_ECX + 0x80) + 0.06666667;
    if (1.0 <= fVar1) {
      fVar1 = 1.0;
    }
    *(float *)(in_ECX + 0x80) = fVar1;
    iVar2 = *piVar5;
  }
  else {
LAB_006962e9:
    if (*(float *)(in_ECX + 0x80) <= 0.0) goto LAB_0069634a;
    fVar1 = *(float *)(in_ECX + 0x80) - 0.06666667;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    *(float *)(in_ECX + 0x80) = fVar1;
    iVar2 = **(int **)(in_ECX + 0x94);
  }
  (**(code **)(iVar2 + 0xd8))(fVar1);
  (**(code **)(**(int **)(in_ECX + 0x94) + 200))();
LAB_0069634a:
  local_2c = -1;
  if (iVar4 == 0) {
    piVar5 = *(int **)(*(int *)(in_ECX + 0x94) + 0xd8);
    if (((uint)piVar5[10] >> 8 & 1) != 0) {
      (**(code **)(*piVar5 + 0x94))(0);
      local_2c = iVar4;
    }
  }
  else {
    piVar5 = *(int **)(*(int *)(in_ECX + 0x94) + 0xd8);
    if (((uint)piVar5[10] >> 8 & 1) == 0) {
      (**(code **)(*piVar5 + 0x94))(1);
      local_2c = 1;
    }
  }
  piVar5 = (int *)(in_ECX + 0x8c);
  iVar4 = 2;
  do {
    if (((uint)((int *)*piVar5)[10] >> 8 & 1) != 0) {
      (**(code **)(*(int *)*piVar5 + 0xd8))(0x3f800000);
      (**(code **)(*(int *)*piVar5 + 0x170))(*(undefined4 *)(in_ECX + 0x80));
      (**(code **)(*(int *)*piVar5 + 0x16c))();
    }
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = *(int *)(in_ECX + 0x94);
  if ((*(int *)(iVar4 + 0xcc) == 0) || (*(int *)(iVar4 + 0xd8) == 0)) {
    iVar2 = -1;
  }
  else {
    iVar2 = FUN_005f55a0();
  }
  iVar4 = *(int *)(iVar4 + 0xd8);
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c + iVar2 * 4) + 0x174))();
  if (iVar4 != 0) {
    iVar2 = iVar2 + (*(int *)(iVar4 + 0x14) - *(int *)(iVar4 + 0xc));
  }
  if (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc) != iVar2) {
    FUN_00749d00();
  }
  if (local_2c != -1) {
    FUN_0040b5b0(local_2c);
  }
  ExceptionList = local_14;
  return;
}


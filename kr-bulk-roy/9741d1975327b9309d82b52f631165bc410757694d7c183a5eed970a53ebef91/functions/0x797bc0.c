
void FUN_00797bc0(int *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  float10 fVar5;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092bde5;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  iVar3 = FUN_00891268(0x8c,uVar2);
  local_c = 0;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0077e550();
  }
  local_c = 0xffffffff;
  *param_1 = iVar3;
  param_1[0x33] = 0;
  if (iVar3 != 0) {
    *(float *)(iVar3 + 0x74) = (float)param_1[0x2f] * ((float)param_1[0xd] / 1.3333334);
  }
  *(int *)(*param_1 + 0x7c) = param_1[0xc];
  *(int *)(*param_1 + 0x78) = param_1[0xb];
  iVar3 = FUN_00891268(0xe8,uVar2);
  local_c = 1;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0077ebb0();
  }
  param_1[1] = iVar3;
  FUN_0077f030(0,0,param_1[9]);
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = puVar1[1] + 1;
  }
  local_c = 2;
  FUN_0077f8f0();
  local_c = 0xffffffff;
  if (puVar1 != (undefined4 *)0x0) {
    piVar4 = puVar1 + 1;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      (**(code **)*puVar1)(1);
    }
  }
  iVar3 = FUN_00891268(0xe8);
  local_c = 3;
  if (iVar3 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_0077ebb0();
  }
  local_c = 0xffffffff;
  param_1[2] = (int)piVar4;
  (**(code **)(*piVar4 + 0x40))(param_1[1]);
  iVar3 = param_1[2];
  fVar5 = (float10)FUN_008ff0a0();
  *(float *)(iVar3 + 0x74) = (float)fVar5;
  *(float *)(iVar3 + 0x78) = (float)(fVar5 * (float10)0.0);
  *(float *)(iVar3 + 0x7c) = (float)(fVar5 * (float10)0.0);
  fVar5 = (float10)FUN_008fef70();
  *(float *)(iVar3 + 0x80) = (float)fVar5;
  uVar2 = DAT_00fb79e8 & 1;
  *(undefined4 *)(iVar3 + 0xc0) = 0;
  param_1[0x33] = 0;
  if (uVar2 == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    puStack_10 = (undefined1 *)0x4;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  if (DAT_00fb76e8 == (int *)0x0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      puStack_10 = (undefined1 *)0x5;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    DAT_00fb76e8 = param_1;
  }
  ExceptionList = pvStack_18;
  return;
}


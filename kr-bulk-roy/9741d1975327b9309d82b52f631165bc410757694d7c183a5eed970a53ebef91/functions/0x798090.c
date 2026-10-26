
void FUN_00798090(void)

{
  float fVar1;
  uint uVar2;
  int unaff_ESI;
  float10 fVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b79e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(unaff_ESI + 0xb0) == 0) {
    FUN_00780150(*(int *)(unaff_ESI + 8),*(undefined4 *)(*(int *)(unaff_ESI + 8) + 0x30));
    *(undefined4 *)(unaff_ESI + 0xd4) = 0;
  }
  if (*(float *)(unaff_ESI + 0xd4) < *(float *)(unaff_ESI + 0xd0) ==
      (*(float *)(unaff_ESI + 0xd4) == *(float *)(unaff_ESI + 0xd0))) {
    fVar1 = (*(float *)(unaff_ESI + 0xd0) * 19.0 + *(float *)(unaff_ESI + 0xd4)) / 20.0;
    *(float *)(unaff_ESI + 0xd0) = fVar1;
    fVar3 = (float10)FUN_004ff540(fVar1 - *(float *)(unaff_ESI + 0xd4),uVar2);
    if ((float10)0.01 <= fVar3) goto LAB_0079813d;
  }
  *(undefined4 *)(unaff_ESI + 0xd0) = *(undefined4 *)(unaff_ESI + 0xd4);
LAB_0079813d:
  FUN_0077f030(0,0,*(undefined4 *)(unaff_ESI + 0xd0));
  FUN_00780150(*(int *)(unaff_ESI + 8),*(undefined4 *)(*(int *)(unaff_ESI + 8) + 0x30));
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  (**(code **)(**(int **)(unaff_ESI + 8) + 0x28))(DAT_00fb76a8);
  ExceptionList = local_10;
  return;
}


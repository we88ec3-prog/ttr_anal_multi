
void FUN_007a6830(float param_1)

{
  float fVar1;
  int iVar2;
  int unaff_ESI;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a155;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_008380b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_14 = param_1;
  local_8 = 0;
  fVar1 = 0.0;
  if ((0.0 <= param_1) && (fVar1 = local_14, *(float *)(unaff_ESI + 0xb8) < param_1)) {
    fVar1 = *(float *)(unaff_ESI + 0xb8);
  }
  local_14 = fVar1;
  *(float *)(unaff_ESI + 0xb4) = local_14;
  if (*(int *)(unaff_ESI + 0x1c) == 0) goto LAB_007a6942;
  if (*(int *)(unaff_ESI + 0xac) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0xac) + 0x20))
              (*(int *)(unaff_ESI + 0x1c),*(undefined4 *)(unaff_ESI + 0xb4));
  }
  if (*(int *)(unaff_ESI + 0x108) != 0) {
    if ((*(int *)(unaff_ESI + 0xac) != 0) &&
       (iVar2 = (**(code **)(**(int **)(unaff_ESI + 0xac) + 4))(), iVar2 == 1)) {
      *(undefined4 *)(*(int *)(unaff_ESI + 0x108) + 0x1c) = 0;
      FUN_007be5b0();
      FUN_007d3bd0(*(undefined4 *)(unaff_ESI + 0x1c));
      goto LAB_007a6942;
    }
    *(float *)(*(int *)(unaff_ESI + 0x108) + 0x1c) = param_1;
    if (param_1 == 0.0) {
      FUN_007be5b0();
      FUN_007d3bd0(*(undefined4 *)(unaff_ESI + 0x1c));
      goto LAB_007a6942;
    }
  }
  FUN_007d3bd0(*(undefined4 *)(unaff_ESI + 0x1c));
LAB_007a6942:
  FUN_00837fd0();
  PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
  ExceptionList = local_10;
  return;
}


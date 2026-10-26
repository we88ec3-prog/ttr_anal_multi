
void FUN_007fc530(float param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  param_1 = param_1 + *(float *)(in_ECX + 0x48);
  iVar1 = *(int *)(in_ECX + 0x40);
  *(float *)(in_ECX + 0x48) = param_1;
  if (iVar1 != 0) {
    FUN_005366c0(in_ECX + 0x3c);
    if (in_ECX != *(int *)(iVar1 + 4)) {
      if (*(int *)(in_ECX + 0x2c) == 0) {
        *(undefined4 *)(in_ECX + 0x4c) = 0;
      }
      else {
        if (*(float *)(*(int *)(in_ECX + 0x2c) + 4) < param_1) {
          *(undefined4 *)(in_ECX + 0x48) = 0;
        }
        if (*(int *)(in_ECX + 0x4c) == 0) {
          *(undefined4 *)(in_ECX + 0x4c) = 1;
          FUN_007dbb40(*(undefined4 *)(in_ECX + 0x38),0);
        }
        FUN_007dbb40(*(undefined4 *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x48));
      }
    }
    iVar1 = *(int *)(in_ECX + 0x34);
    if (*(int *)(iVar1 + 0x20) != 0) {
      if (*(float *)(iVar1 + 0x24) < *(float *)(in_ECX + 0x48)) {
        *(undefined4 *)(in_ECX + 0x48) = 0;
      }
      iVar1 = **(int **)(iVar1 + 0x10);
      uVar2 = FUN_008fed10();
      (**(code **)(iVar1 + 0x1c))(uVar2);
      FUN_007d3bd0(*(undefined4 *)(in_ECX + 0x34));
      return;
    }
    FUN_007d3bd0(*(undefined4 *)(in_ECX + 0x34));
  }
  return;
}


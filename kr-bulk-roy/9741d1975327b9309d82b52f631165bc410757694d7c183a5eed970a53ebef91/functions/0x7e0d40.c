
void FUN_007e0d40(float param_1)

{
  int *piVar1;
  float fVar2;
  int in_ECX;
  
  fVar2 = param_1;
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    *(float *)(in_ECX + 0x30) = *(float *)(in_ECX + 0x2c) * param_1 + *(float *)(in_ECX + 0x30);
    if (0.0 <= *(float *)(in_ECX + 0x30)) {
      if (*(float *)(in_ECX + 0x30) <= 1.0) {
        param_1 = *(float *)(in_ECX + 0x30);
      }
      else {
        param_1 = 1.0;
      }
    }
    else {
      param_1 = 0.0;
    }
    *(float *)(in_ECX + 0x30) = param_1;
    if (1.0 <= param_1) {
      *(undefined4 *)(in_ECX + 0x30) = 0;
      *(int *)(in_ECX + 4) = *(int *)(in_ECX + 8);
    }
  }
  piVar1 = *(int **)(*(int *)(in_ECX + 0xc + *(int *)(in_ECX + 4) * 4) + 0x10);
  if (piVar1 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar1 + 0x20))(fVar2);
  return;
}


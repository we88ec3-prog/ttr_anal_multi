
void FUN_006dd470(float param_1)

{
  float fVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x2c) != '\0') {
    param_1 = param_1 + *(float *)(in_ECX + 0x28);
    *(float *)(in_ECX + 0x28) = param_1;
    if (0.5 < param_1) {
      *(undefined4 *)(in_ECX + 0x28) = 0x3f000000;
      *(undefined1 *)(in_ECX + 0x2c) = 0;
    }
    fVar1 = *(float *)(in_ECX + 0x28);
    *(float *)(in_ECX + 0x1c) = fVar1 * *(float *)(in_ECX + 0x60) * 2.0 + *(float *)(in_ECX + 0x30);
    *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 100) * fVar1 * 2.0 + *(float *)(in_ECX + 0x34);
    *(float *)(in_ECX + 0x24) = fVar1 * *(float *)(in_ECX + 0x68) * 2.0 + *(float *)(in_ECX + 0x38);
    return;
  }
  *(undefined4 *)(in_ECX + 0x28) = 0;
  return;
}


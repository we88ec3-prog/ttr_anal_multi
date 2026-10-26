
void FUN_006dd6f0(void)

{
  float fVar1;
  int in_ECX;
  
  if (*(float *)(in_ECX + 0x24) <= 150.0 && *(float *)(in_ECX + 0x24) != 150.0) {
    *(undefined4 *)(in_ECX + 0x24) = 0x43160000;
  }
  if (400.0 < *(float *)(in_ECX + 0x24)) {
    *(undefined4 *)(in_ECX + 0x24) = 0x43c80000;
  }
  fVar1 = ((*(float *)(in_ECX + 0x24) - 150.0) / 250.0) * 15.0 + 40.0;
  *(float *)(in_ECX + 0x7c) = fVar1;
  if (fVar1 < *(float *)(in_ECX + 0x20)) {
    *(float *)(in_ECX + 0x20) = fVar1;
    return;
  }
  if (*(float *)(in_ECX + 0x20) < -fVar1) {
    *(float *)(in_ECX + 0x20) = -fVar1;
  }
  return;
}


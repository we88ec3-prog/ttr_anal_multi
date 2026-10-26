
void FUN_0080ebc0(float param_1)

{
  code *pcVar1;
  int *in_ECX;
  float fVar2;
  
  fVar2 = 1.0;
  if ((1.0 < param_1) || (fVar2 = 0.0, param_1 < 0.0)) {
    param_1 = fVar2;
  }
  fVar2 = (float)(((uint)(param_1 + 1.0) & 0x807fffff) + 0x3f800000);
  pcVar1 = *(code **)(*in_ECX + 0x48);
  in_ECX[9] = (int)((float)(int)(((int)(param_1 + 1.0) >> 0x17 & 0xffU) - 0x80) +
                   ((2.0 - fVar2 * 0.33333334) * fVar2 - 0.6666667));
  (*pcVar1)(in_ECX[8]);
  return;
}


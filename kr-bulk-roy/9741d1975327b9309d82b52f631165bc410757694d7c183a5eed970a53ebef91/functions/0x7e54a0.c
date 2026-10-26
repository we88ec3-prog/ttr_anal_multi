
void FUN_007e54a0(void)

{
  float fVar1;
  int in_ECX;
  float *pfVar2;
  uint uVar3;
  
  if (*(int *)(in_ECX + 0x174) != 0) {
    pfVar2 = *(float **)(in_ECX + 0x16c);
    *(float *)(in_ECX + 0x13c) = *pfVar2;
    *(float *)(in_ECX + 0x140) = pfVar2[1];
    *(float *)(in_ECX + 0x144) = pfVar2[2];
    *(float *)(in_ECX + 0x130) = *pfVar2;
    *(float *)(in_ECX + 0x134) = pfVar2[1];
    *(float *)(in_ECX + 0x138) = pfVar2[2];
    uVar3 = 0;
    if (*(int *)(in_ECX + 0x174) != 0) {
      do {
        if (*(float *)(in_ECX + 0x130) <= *pfVar2) {
          fVar1 = *(float *)(in_ECX + 0x130);
        }
        else {
          fVar1 = *pfVar2;
        }
        *(float *)(in_ECX + 0x130) = fVar1;
        if (*(float *)(in_ECX + 0x134) <= pfVar2[1]) {
          fVar1 = *(float *)(in_ECX + 0x134);
        }
        else {
          fVar1 = pfVar2[1];
        }
        *(float *)(in_ECX + 0x134) = fVar1;
        if (*(float *)(in_ECX + 0x138) <= pfVar2[2]) {
          fVar1 = *(float *)(in_ECX + 0x138);
        }
        else {
          fVar1 = pfVar2[2];
        }
        *(float *)(in_ECX + 0x138) = fVar1;
        if (*pfVar2 <= *(float *)(in_ECX + 0x13c)) {
          fVar1 = *(float *)(in_ECX + 0x13c);
        }
        else {
          fVar1 = *pfVar2;
        }
        *(float *)(in_ECX + 0x13c) = fVar1;
        if (pfVar2[1] <= *(float *)(in_ECX + 0x140)) {
          fVar1 = *(float *)(in_ECX + 0x140);
        }
        else {
          fVar1 = pfVar2[1];
        }
        *(float *)(in_ECX + 0x140) = fVar1;
        if (pfVar2[2] <= *(float *)(in_ECX + 0x144)) {
          fVar1 = *(float *)(in_ECX + 0x144);
        }
        else {
          fVar1 = pfVar2[2];
        }
        uVar3 = uVar3 + 1;
        pfVar2 = pfVar2 + 3;
        *(float *)(in_ECX + 0x144) = fVar1;
      } while (uVar3 < *(uint *)(in_ECX + 0x174));
    }
  }
  return;
}


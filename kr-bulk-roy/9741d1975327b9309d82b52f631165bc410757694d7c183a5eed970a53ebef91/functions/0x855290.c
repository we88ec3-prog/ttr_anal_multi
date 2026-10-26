
void FUN_00855290(void)

{
  float fVar1;
  undefined4 uVar2;
  float *in_ECX;
  int in_EDX;
  float *unaff_ESI;
  float *unaff_EDI;
  
  fVar1 = 0.0;
  if (0.0 < *in_ECX) {
    if (1.0 <= *in_ECX) {
      fVar1 = 1.0;
    }
    else if (0.0 < *in_ECX) {
      fVar1 = *in_ECX;
    }
  }
  *(float *)(in_EDX + 0x194) = fVar1;
  if (0.0 < *unaff_ESI) {
    if (1.0 <= *unaff_ESI) {
      fVar1 = 1.0;
      goto LAB_008552fc;
    }
    if (0.0 < *unaff_ESI) {
      fVar1 = *unaff_ESI;
      goto LAB_008552fc;
    }
  }
  fVar1 = 0.0;
LAB_008552fc:
  *(float *)(in_EDX + 0x198) = fVar1;
  if (*unaff_EDI <= 0.0) {
    *(undefined4 *)(in_EDX + 0x19c) = 0;
    return;
  }
  if (1.0 <= *unaff_EDI) {
    uVar2 = 0x3f800000;
  }
  else {
    uVar2 = 0;
    if (0.0 < *unaff_EDI) {
      *(float *)(in_EDX + 0x19c) = *unaff_EDI;
      return;
    }
  }
  *(undefined4 *)(in_EDX + 0x19c) = uVar2;
  return;
}


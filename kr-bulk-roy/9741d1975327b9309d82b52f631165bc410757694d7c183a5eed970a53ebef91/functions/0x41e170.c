
undefined4 FUN_0041e170(float param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int in_EDX;
  int iVar4;
  
  pfVar3 = (float *)(in_EDX + 0x38);
  iVar4 = 2;
  do {
    if (*(char *)(pfVar3 + -3) != '\0') {
      if (*pfVar3 - param_1 <= 0.0) {
        *pfVar3 = 0.0;
        *(undefined1 *)(pfVar3 + -3) = 0;
      }
      else {
        *pfVar3 = *pfVar3 - param_1;
      }
    }
    if (*(char *)(pfVar3 + 0xc) != '\0') {
      if (pfVar3[0xf] - param_1 <= 0.0) {
        pfVar3[0xf] = 0.0;
        *(undefined1 *)(pfVar3 + 0xc) = 0;
      }
      else {
        pfVar3[0xf] = pfVar3[0xf] - param_1;
      }
    }
    if (*(char *)(pfVar3 + 0x1b) != '\0') {
      if (pfVar3[0x1e] - param_1 <= 0.0) {
        pfVar3[0x1e] = 0.0;
        *(undefined1 *)(pfVar3 + 0x1b) = 0;
      }
      else {
        pfVar3[0x1e] = pfVar3[0x1e] - param_1;
      }
    }
    if (*(char *)(pfVar3 + 0x2a) != '\0') {
      if (pfVar3[0x2d] - param_1 <= 0.0) {
        pfVar3[0x2d] = 0.0;
        *(undefined1 *)(pfVar3 + 0x2a) = 0;
      }
      else {
        pfVar3[0x2d] = pfVar3[0x2d] - param_1;
      }
    }
    if (*(char *)(pfVar3 + 0x39) != '\0') {
      if (pfVar3[0x3c] - param_1 <= 0.0) {
        pfVar3[0x3c] = 0.0;
        *(undefined1 *)(pfVar3 + 0x39) = 0;
      }
      else {
        pfVar3[0x3c] = pfVar3[0x3c] - param_1;
      }
    }
    pfVar3 = pfVar3 + 0x4b;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (*(char *)(in_EDX + 0x2c) != '\0') {
    fVar1 = *(float *)(in_EDX + 0x38);
    fVar2 = 0.7 - fVar1;
    if (0.05 < fVar2) {
      fVar2 = 0.05;
    }
    *(float *)(in_EDX + 0x14) =
         (*(float *)(in_EDX + 0x24) - *(float *)(in_EDX + 0x1c)) * fVar2 * 20.0 +
         *(float *)(in_EDX + 0x1c);
    *(float *)(in_EDX + 0x18) =
         *(float *)(in_EDX + 0x20) +
         fVar2 * (*(float *)(in_EDX + 0x28) - *(float *)(in_EDX + 0x20)) * 20.0;
    if (fVar1 < 0.2) {
      *(float *)(in_EDX + 0x34) = (fVar1 / 0.2) * 255.0;
    }
  }
  pfVar3 = (float *)(in_EDX + 0x5c);
  iVar4 = 3;
  do {
    if (*(char *)(pfVar3 + 3) != '\0') {
      fVar1 = pfVar3[6];
      fVar2 = 0.7 - fVar1;
      if (0.05 < fVar2) {
        fVar2 = 0.05;
      }
      pfVar3[-3] = (pfVar3[1] - pfVar3[-1]) * fVar2 * 20.0 + pfVar3[-1];
      pfVar3[-2] = *pfVar3 + fVar2 * (pfVar3[2] - *pfVar3) * 20.0;
      if (fVar1 < 0.2) {
        pfVar3[5] = (fVar1 / 0.2) * 255.0;
      }
    }
    if (*(char *)(pfVar3 + 0x12) != '\0') {
      fVar1 = pfVar3[0x15];
      fVar2 = 0.7 - fVar1;
      if (0.05 < fVar2) {
        fVar2 = 0.05;
      }
      pfVar3[0xc] = (pfVar3[0x10] - pfVar3[0xe]) * fVar2 * 20.0 + pfVar3[0xe];
      pfVar3[0xd] = pfVar3[0xf] + fVar2 * (pfVar3[0x11] - pfVar3[0xf]) * 20.0;
      if (fVar1 < 0.2) {
        pfVar3[0x14] = (fVar1 / 0.2) * 255.0;
      }
    }
    if (*(char *)(pfVar3 + 0x21) != '\0') {
      fVar1 = pfVar3[0x24];
      fVar2 = 0.7 - fVar1;
      if (0.05 < fVar2) {
        fVar2 = 0.05;
      }
      pfVar3[0x1b] = (pfVar3[0x1f] - pfVar3[0x1d]) * fVar2 * 20.0 + pfVar3[0x1d];
      pfVar3[0x1c] = pfVar3[0x1e] + fVar2 * (pfVar3[0x20] - pfVar3[0x1e]) * 20.0;
      if (fVar1 < 0.2) {
        pfVar3[0x23] = (fVar1 / 0.2) * 255.0;
      }
    }
    pfVar3 = pfVar3 + 0x2d;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return 0;
}



undefined4 FUN_00559390(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  float10 fVar3;
  float fVar4;
  
  if (*(int *)(unaff_ESI + 0x2c) != 0) {
    *(int *)(unaff_ESI + 0x2c) = *(int *)(unaff_ESI + 0x2c) + -1;
  }
  if (*(int *)(unaff_ESI + 0x54) != 0) {
    *(int *)(unaff_ESI + 0x54) = *(int *)(unaff_ESI + 0x54) + -1;
  }
  if (*(int *)(unaff_ESI + 0x74) != 0) {
    *(int *)(unaff_ESI + 0x74) = *(int *)(unaff_ESI + 0x74) + -1;
  }
  if (*(int *)(unaff_ESI + 0x94) != 0) {
    *(int *)(unaff_ESI + 0x94) = *(int *)(unaff_ESI + 0x94) + -1;
  }
  if (*(int *)(unaff_ESI + 0xb8) != 0) {
    *(int *)(unaff_ESI + 0xb8) = *(int *)(unaff_ESI + 0xb8) + -1;
  }
  uVar2 = *(uint *)(unaff_ESI + 0x2c);
  if ((int)(0x3c - uVar2) < 6) {
    fVar4 = (float)(int)(0x3c - uVar2) / 6.0;
    *(float *)(unaff_ESI + 0x28) = fVar4 * 192.0 + 63.0;
    *(float *)(unaff_ESI + 0x24) = 2.0 - fVar4;
  }
  else if (uVar2 < 6) {
    fVar4 = (float)(int)uVar2;
    if ((int)uVar2 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    *(float *)(unaff_ESI + 0x28) = (fVar4 / 6.0) * 255.0;
    *(float *)(unaff_ESI + 0x24) = 1.2 - (fVar4 / 6.0) * 0.2;
  }
  else {
    *(undefined4 *)(unaff_ESI + 0x28) = 0x437f0000;
    *(undefined4 *)(unaff_ESI + 0x24) = 0x3f800000;
  }
  uVar2 = *(uint *)(unaff_ESI + 0x54);
  if ((int)(0x24 - uVar2) < 6) {
    fVar4 = (float)(int)(0x24 - uVar2) / 6.0;
    *(float *)(unaff_ESI + 0x50) = fVar4 * 192.0 + 63.0;
    *(float *)(unaff_ESI + 0x4c) = 2.0 - fVar4;
  }
  else if (uVar2 < 6) {
    fVar4 = (float)(int)uVar2;
    if ((int)uVar2 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    *(float *)(unaff_ESI + 0x50) = (fVar4 / 6.0) * 255.0;
    *(float *)(unaff_ESI + 0x4c) = 1.1 - (fVar4 / 6.0) * 0.1;
  }
  else {
    *(undefined4 *)(unaff_ESI + 0x50) = 0x437f0000;
    *(undefined4 *)(unaff_ESI + 0x4c) = 0x3f800000;
    iVar1 = FUN_0089289d();
    *(float *)(unaff_ESI + 0x3c) = ((float)(iVar1 % 6) + *(float *)(unaff_ESI + 0x44)) - 3.0;
    iVar1 = FUN_0089289d();
    *(float *)(unaff_ESI + 0x40) = ((float)(iVar1 % 6) + *(float *)(unaff_ESI + 0x48)) - 3.0;
  }
  uVar2 = *(uint *)(unaff_ESI + 0x74);
  fVar3 = (float10)FUN_008fef70();
  fVar4 = (float)fVar3;
  if (fVar4 <= 0.0) {
    fVar4 = 0.0;
  }
  *(float *)(unaff_ESI + 0x6c) = fVar4 + 1.0;
  if (uVar2 < 3) {
    fVar4 = (float)(int)uVar2;
    if ((int)uVar2 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    *(float *)(unaff_ESI + 0x70) = (fVar4 / 3.0) * 255.0;
  }
  else {
    *(undefined4 *)(unaff_ESI + 0x70) = 0x437f0000;
  }
  iVar1 = *(int *)(unaff_ESI + 0x94);
  *(int *)(unaff_ESI + 0x98) = 7 - iVar1;
  if (4 < 7 - iVar1) {
    fVar4 = (float)iVar1;
    if (iVar1 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    *(float *)(unaff_ESI + 0x90) = (fVar4 / 6.0) * 255.0;
  }
  uVar2 = *(uint *)(unaff_ESI + 0xb8);
  if (5 < uVar2) {
    iVar1 = FUN_0089289d();
    *(float *)(unaff_ESI + 0xa0) = (float)(iVar1 % ((int)uVar2 / 3)) + *(float *)(unaff_ESI + 0xa8);
    iVar1 = FUN_0089289d();
    *(float *)(unaff_ESI + 0xa4) = (float)(iVar1 % ((int)uVar2 / 3)) + *(float *)(unaff_ESI + 0xac);
    uVar2 = FUN_0089289d();
    uVar2 = uVar2 & 0x8000007f;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xffffff80) + 1;
    }
    *(float *)(unaff_ESI + 0xb4) = (float)(int)(0xff - uVar2);
    return 0;
  }
  fVar4 = (float)(int)uVar2;
  if ((int)uVar2 < 0) {
    fVar4 = fVar4 + 4.2949673e+09;
  }
  *(float *)(unaff_ESI + 0xb4) = (fVar4 / 6.0) * 255.0;
  return 0;
}


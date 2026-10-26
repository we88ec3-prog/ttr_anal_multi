
void FUN_0055a350(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int unaff_ESI;
  float10 fVar4;
  float local_20 [2];
  float local_18 [2];
  float local_10;
  float local_c;
  float local_8;
  
  FUN_00559e90(local_20,local_18);
  local_20[0] = (float)*(int *)(unaff_ESI + 0x38) + (float)((int)local_20[0] / 3);
  local_8 = (float)((int)local_18[0] * 0xf);
  *(float *)(unaff_ESI + 0xfc) = local_8;
  *(float *)(unaff_ESI + 0xf8) = local_20[0];
  local_c = *(float *)(unaff_ESI + 0xf0);
  if ((local_c == local_20[0]) && (*(float *)(unaff_ESI + 0xf4) == local_8)) {
    *(undefined4 *)(unaff_ESI + 0xe8) = 0;
    return;
  }
  *(undefined4 *)(unaff_ESI + 0xe8) = 1;
  fVar1 = (local_20[0] - local_c) * 0.5 + local_c;
  *(float *)(unaff_ESI + 0xf0) = fVar1;
  local_10 = *(float *)(unaff_ESI + 0xf4);
  local_18[0] = (local_8 - local_10) * 0.5 + local_10;
  *(float *)(unaff_ESI + 0xf4) = local_18[0];
  fVar4 = (float10)FUN_004ff540(local_20[0] - fVar1);
  if (fVar4 < (float10)1) {
    fVar4 = (float10)FUN_004ff540(local_8 - local_18[0]);
    if (fVar4 < (float10)1) {
      *(float *)(unaff_ESI + 0xf0) = local_20[0];
      *(float *)(unaff_ESI + 0xf4) = local_8;
      *(undefined4 *)(unaff_ESI + 0xe8) = 0;
    }
  }
  if ((DAT_00fe4b54 & 1) == 0) {
    DAT_00fe4b54 = DAT_00fe4b54 | 1;
    DAT_00fe4b4c = 0;
    DAT_00fe4b50 = 0;
  }
  if ((DAT_00fe4b54 & 2) == 0) {
    DAT_00fe4b54 = DAT_00fe4b54 | 2;
    DAT_00fe4b44 = 0x3f800000;
    DAT_00fe4b48 = 0x3f800000;
  }
  fVar1 = *(float *)(unaff_ESI + 0xf0);
  *(undefined4 *)(unaff_ESI + 0x58) = DAT_00fe4b4c;
  *(undefined4 *)(unaff_ESI + 0x5c) = DAT_00fe4b50;
  fVar2 = *(float *)(unaff_ESI + 0xf4);
  *(undefined4 *)(unaff_ESI + 0x60) = DAT_00fe4b4c;
  *(undefined4 *)(unaff_ESI + 100) = DAT_00fe4b50;
  *(float *)(unaff_ESI + 0x68) = fVar1;
  *(undefined4 *)(unaff_ESI + 0x6c) = 0;
  *(undefined4 *)(unaff_ESI + 0x70) = DAT_00fe4b4c;
  *(undefined4 *)(unaff_ESI + 0x74) = DAT_00fe4b50;
  *(undefined4 *)(unaff_ESI + 0x78) = DAT_00fe4b4c;
  *(undefined4 *)(unaff_ESI + 0x7c) = DAT_00fe4b50;
  *(float *)(unaff_ESI + 0x80) = fVar1;
  *(undefined4 *)(unaff_ESI + 0x84) = 0;
  *(undefined4 *)(unaff_ESI + 0x88) = 0;
  *(float *)(unaff_ESI + 0x8c) = fVar2;
  fVar3 = fVar1 / 20.0 + 0.1;
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  *(float *)(unaff_ESI + 0x94) = fVar2;
  *(float *)(unaff_ESI + 0x98) = fVar1;
  *(float *)(unaff_ESI + 0x9c) = fVar2;
  *(undefined4 *)(unaff_ESI + 0xa0) = DAT_00fe4b44;
  *(undefined4 *)(unaff_ESI + 0xa4) = DAT_00fe4b48;
  *(float *)(unaff_ESI + 0xa8) = fVar3;
  *(undefined4 *)(unaff_ESI + 0xac) = 0x3f800000;
  *(undefined4 *)(unaff_ESI + 0xb0) = DAT_00fe4b44;
  *(undefined4 *)(unaff_ESI + 0xb4) = DAT_00fe4b48;
  *(undefined4 *)(unaff_ESI + 0xb8) = 0x3f800000;
  fVar1 = fVar2 / 17.0 + 0.1;
  *(float *)(unaff_ESI + 0xc0) = fVar3;
  *(float *)(unaff_ESI + 0xbc) = fVar1;
  *(float *)(unaff_ESI + 0xc4) = fVar1;
  *(float *)(unaff_ESI + 0xcc) = fVar1;
  *(undefined4 *)(unaff_ESI + 200) = 0x3f800000;
  *(undefined4 *)(unaff_ESI + 0xd0) = DAT_00fe4b44;
  *(undefined4 *)(unaff_ESI + 0xd4) = DAT_00fe4b48;
  *(float *)(unaff_ESI + 0xd8) = fVar3;
  *(undefined4 *)(unaff_ESI + 0xdc) = 0x3f800000;
  *(undefined4 *)(unaff_ESI + 0xe0) = DAT_00fe4b44;
  *(undefined4 *)(unaff_ESI + 0xe4) = DAT_00fe4b48;
  return;
}


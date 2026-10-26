
void FUN_00559a50(void)

{
  float fVar1;
  float fVar2;
  float *unaff_ESI;
  undefined1 local_20 [12];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)local_20);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (DAT_00f9392c == 0x1a) {
    fVar1 = ((float)((int)unaff_ESI[2] / 2) - *unaff_ESI * 384.0) + 105.0;
  }
  else {
    fVar1 = (float)((int)unaff_ESI[2] / 2) - *unaff_ESI * 384.0;
  }
  unaff_ESI[0x23] = 2.0;
  unaff_ESI[0x21] = fVar1;
  fVar2 = (float)(int)unaff_ESI[3] - unaff_ESI[1] * 197.0;
  unaff_ESI[0x1f] = fVar1;
  unaff_ESI[0x25] = 9.80909e-45;
  unaff_ESI[0x24] = 255.0;
  unaff_ESI[0x22] = fVar2;
  unaff_ESI[0x20] = fVar2;
  unaff_ESI[0x2e] = 2.52234e-44;
  unaff_ESI[0x2c] = 1.0;
  unaff_ESI[0x2d] = 255.0;
  ExceptionList = local_14;
  return;
}


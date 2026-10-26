
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054cba0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a3cc;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0054ba30(0xf);
  iVar6 = (**(code **)(*DAT_00fba7a4 + 0x20))(uVar5);
  if (iVar6 == 0) {
    ExceptionList = local_10;
    return;
  }
  cVar4 = *(char *)(iVar6 + 0xb0);
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
  }
  fVar1 = (float)(&DAT_00fb7c20)[(byte)(cVar4 + 0x80)];
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  fVar2 = *(float *)(DAT_00fb76e8 + 0x20);
  fVar8 = (float10)FUN_007cd340(fVar1,fVar2);
  fVar3 = (float)fVar8;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  if (((DAT_00fb9135 == '\0') ||
      (fVar8 = (float10)FUN_004ff540(_DAT_00fbab0c - fVar1), (float10)0.005 <= fVar8)) ||
     ((*(ushort *)(iVar6 + 0xe2) & 0x8000) != 0)) {
    DAT_00fbab10 = 0;
    _DAT_00fbab0c = fVar1;
  }
  else {
    DAT_00fbab10 = DAT_00fbab10 + 1;
    _DAT_00fbab0c = fVar1;
    iVar7 = FUN_00444ad0();
    if (*(int *)(iVar7 + 0x13c) <= DAT_00fbab10) {
      local_14 = fVar3 * 0.033333 * _DAT_00fbab08;
      iVar6 = FUN_00444ad0();
      _DAT_00fbab08 = *(float *)(iVar6 + 0x16c) + _DAT_00fbab08;
      iVar6 = FUN_00444ad0();
      if (*(float *)(iVar6 + 0x154) < _DAT_00fbab08) {
        iVar6 = FUN_00444ad0();
        _DAT_00fbab08 = *(float *)(iVar6 + 0x154);
      }
      goto LAB_0054ce45;
    }
  }
  if ((((*(ushort *)(iVar6 + 0xe2) & 0x8000) == 0) ||
      (iVar6 = FUN_00444ad0(), *(char *)(iVar6 + 0xd9) == '\0')) ||
     ((ABS(fVar3) <= 0.2617994 || (2.8797932 <= ABS(fVar3))))) {
    _DAT_00fbab08 = 0.0;
    DAT_00fbab14 = 0;
    ExceptionList = local_10;
    return;
  }
  DAT_00fbab14 = DAT_00fbab14 + 1;
  iVar6 = FUN_00444ad0();
  if (DAT_00fbab14 < *(int *)(iVar6 + 0xf4)) {
    ExceptionList = local_10;
    return;
  }
  local_14 = fVar3 * 0.033333 * _DAT_00fbab08;
  iVar6 = FUN_00444ad0();
  _DAT_00fbab08 = *(float *)(iVar6 + 0x124) + _DAT_00fbab08;
  iVar6 = FUN_00444ad0();
  if (*(float *)(iVar6 + 0x10c) < _DAT_00fbab08) {
    iVar6 = FUN_00444ad0();
    _DAT_00fbab08 = *(float *)(iVar6 + 0x10c);
  }
LAB_0054ce45:
  if (_DAT_00fbab08 < 0.0) {
    ExceptionList = local_10;
    return;
  }
  iVar6 = FUN_00434740();
  iVar6 = *(int *)(iVar6 + 0x40);
  *(float *)(iVar6 + 0x20) = local_14 + fVar2;
  *(undefined4 *)(iVar6 + 0xcc) = 0;
  FUN_0054ba30(0x10);
  ExceptionList = local_10;
  return;
}


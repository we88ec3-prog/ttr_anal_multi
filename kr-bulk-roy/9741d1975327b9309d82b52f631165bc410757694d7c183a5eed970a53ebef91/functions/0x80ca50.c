
void FUN_0080ca50(float param_1,char param_2)

{
  float fVar1;
  int unaff_ESI;
  float10 fVar2;
  undefined1 auStack_20 [4];
  float local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009185be;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_2 != '\0') {
    if (param_1 <= 0.0) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = 1.0;
      if (param_1 < 1.0) {
        fVar1 = param_1;
      }
    }
    param_1 = fVar1;
    local_1c = 1.0 - param_1;
    fVar2 = (float10)FUN_008ff5a0(DAT_00d61f20 ^ (uint)auStack_20);
    local_1c = (float)fVar2;
    param_1 = 1.0 - local_1c;
    if (param_1 <= 0.0) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = 1.0;
      if (param_1 < 1.0) goto LAB_0080caf4;
    }
    param_1 = fVar1;
  }
LAB_0080caf4:
  *(uint *)(unaff_ESI + 0x20) = *(uint *)(unaff_ESI + 0x20) | 1;
  *(float *)(unaff_ESI + 0x24) = param_1;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c = 0;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_c = 0xffffffff;
  }
  FUN_0080c0a0();
  ExceptionList = local_14;
  return;
}


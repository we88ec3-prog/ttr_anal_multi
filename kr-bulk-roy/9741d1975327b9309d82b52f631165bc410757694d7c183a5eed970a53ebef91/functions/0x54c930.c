
void FUN_0054c930(float param_1)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00939ca8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar1 = DAT_00fb76e8;
  local_28 = 0.0;
  local_24 = 0.0;
  local_20 = 0.0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 2;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
  }
  local_1c = DAT_00fb90ac * 4.0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 3;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  uVar2 = DAT_00fbab40;
  local_8 = 0xffffffff;
  local_18 = DAT_00fb90ac * 0.25;
  local_14 = 0.0;
  if (((DAT_00fbab40 & 2) != 0) || ((DAT_00fbab40 & 0x20000) != 0)) {
    local_24 = 0.0 - local_1c * param_1;
  }
  if (((DAT_00fbab40 & 8) != 0) || ((DAT_00fbab40 & 0x80000) != 0)) {
    local_28 = 0.0 - local_1c * param_1;
  }
  if (((DAT_00fbab40 & 0x10) != 0) || ((DAT_00fbab40 & 0x100000) != 0)) {
    local_28 = local_1c * param_1 + local_28;
  }
  if (((DAT_00fbab40 & 4) != 0) || ((DAT_00fbab40 & 0x40000) != 0)) {
    local_24 = local_1c * param_1 + local_24;
  }
  if (((char)DAT_00fbab40 < '\0') || ((char)(DAT_00fbab40 >> 0x10) < '\0')) {
    local_20 = local_1c * param_1 + 0.0;
  }
  if (((DAT_00fbab40 & 0x100) != 0) || ((DAT_00fbab40._2_2_ & 0x100) == 0x100)) {
    local_20 = local_20 - param_1 * local_1c;
  }
  if (((DAT_00fbab40 & 0x20) != 0) || ((DAT_00fbab40 & 0x200000) != 0)) {
    local_14 = local_18 * param_1 + 0.0;
    fVar3 = (float10)FUN_004ff540(local_14);
    if ((float10)0.005 < fVar3) {
      DAT_00fbab10 = 0;
    }
  }
  if (((uVar2 & 0x40) != 0) || ((DAT_00fbab40._2_2_ & 0x40) != 0)) {
    local_14 = local_14 - local_18 * param_1;
    fVar3 = (float10)FUN_004ff540(local_14);
    if ((float10)0.005 < fVar3) {
      DAT_00fbab10 = 0;
    }
  }
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(float *)(iVar1 + 0x20) = *(float *)(iVar1 + 0x20) + local_14;
  FUN_0054d930(&local_28);
  DAT_00fbab40 = DAT_00fbab40 & 0xff;
  ExceptionList = local_10;
  return;
}


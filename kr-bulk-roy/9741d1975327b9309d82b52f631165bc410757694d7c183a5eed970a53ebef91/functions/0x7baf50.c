
void FUN_007baf50(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092bc58;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  uVar4 = 0;
  DAT_00fb7990 = 0;
  if (*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2 != 0) {
    while( true ) {
      if ((DAT_00fe32bc & 1) == 0) {
        DAT_00fe32bc = DAT_00fe32bc | 1;
        local_c = 1;
        FUN_007dda50();
        _atexit((_func_4879 *)&LAB_00bd0ac0);
        local_c = 0xffffffff;
      }
      iVar3 = FUN_007ddcf0();
      if (*(int *)(iVar3 + 8) != 0) break;
      uVar4 = uVar4 + 1;
      if ((uint)(*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2) <= uVar4) {
        ExceptionList = local_14;
        return;
      }
    }
    *(undefined4 *)(in_ECX + 0xd8) =
         *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x7c) + uVar4 * 4) + 0x30);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 2;
      FUN_00798de0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    DAT_00fb7990 = 1;
    fVar1 = *(float *)(*(int *)(*(int *)(in_ECX + 0x7c) + uVar4 * 4) + 0x30);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 3;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    DAT_00fb7994 = 0;
    DAT_00fb7998 = 0;
    DAT_00fb799c = 0x3f800000;
    DAT_00fb79a0 = -fVar1;
  }
  ExceptionList = local_14;
  return;
}


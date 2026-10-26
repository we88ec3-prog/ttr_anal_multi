
void FUN_004c8c40(float param_1)

{
  float fVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d8de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  fVar1 = DAT_00fb90bc;
  local_8 = 0xffffffff;
  *(float *)(in_ECX + 0xb4) = param_1;
  if ((*(int *)(in_ECX + 0x370) != 0) && (*(int *)(in_ECX + 0x15c) != 0)) {
    (**(code **)(*(int *)(*(int *)(in_ECX + 0x15c) + 4) + 0x14))(fVar1 * param_1);
  }
  ExceptionList = local_10;
  return;
}


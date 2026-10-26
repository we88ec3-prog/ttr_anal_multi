
void FUN_00564a60(void)

{
  int in_ECX;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ceee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_8 = 0;
    FUN_005533d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd100);
  }
  local_14 = *(undefined4 *)(in_ECX + 0x40);
  FUN_0082ef00(&local_14);
  if ((local_18 != DAT_00fb735c) && (*(int *)(local_18 + 0x10) != 0)) {
    *(undefined4 *)(*(int *)(local_18 + 0x10) + 0x14) = 0;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0xffffffff;
  ExceptionList = local_10;
  return;
}


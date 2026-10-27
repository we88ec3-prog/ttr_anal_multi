
undefined4 FUN_00434530(void)

{
  int iVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093abdc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    local_c = 0;
    FUN_0054e750(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bcd260);
  }
  local_c = 0xffffffff;
  if (DAT_00fb7620 != (int *)0x0) {
    (**(code **)(*DAT_00fb7620 + 0xc))();
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar1 = DAT_00fb76e8;
  *(undefined4 *)(DAT_00fb76e8 + 0x24) = *(undefined4 *)(in_ECX + 0x5eac);
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  ExceptionList = local_14;
  return 0;
}


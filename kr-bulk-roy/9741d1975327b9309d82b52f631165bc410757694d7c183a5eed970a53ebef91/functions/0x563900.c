
void FUN_00563900(void)

{
  undefined1 auStack_18 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093a9de;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    local_c = 0;
    FUN_0054e750(DAT_00d61f20 ^ (uint)auStack_18);
    _atexit((_func_4879 *)&LAB_00bcd260);
  }
  DAT_00fb7620 = 0;
  ExceptionList = local_14;
  return;
}


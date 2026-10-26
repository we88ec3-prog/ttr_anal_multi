
void FUN_00585390(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092717a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  local_8 = 0xffffffff;
  FUN_00584d40(&DAT_00d65c20,0x1e5);
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_8 = 1;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
    local_8 = 0xffffffff;
  }
  FUN_00584d40(&DAT_00d672f0,0x7a);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  FUN_00584d40(&DAT_00d678a8,0x359);
  DAT_00fba797 = 1;
  ExceptionList = local_10;
  return;
}


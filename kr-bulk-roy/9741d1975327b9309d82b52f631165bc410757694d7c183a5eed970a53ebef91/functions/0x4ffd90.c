
undefined * FUN_004ffd90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924353;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1db8 & 1) == 0) {
    DAT_00fe1db8 = DAT_00fe1db8 | 1;
    local_8 = 0;
    FUN_0056c130(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0056bf40();
    _atexit(FUN_00bceee0);
  }
  ExceptionList = local_10;
  return &DAT_00fe1dbc;
}


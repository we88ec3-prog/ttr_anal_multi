
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004a79a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009250d9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fb7260 = 0;
  DAT_00fb7264 = 0;
  _DAT_00fb7268 = 0;
  DAT_00fb7270 = 0;
  DAT_00fb7274 = 0;
  DAT_00fb7278 = 0;
  DAT_00fb7280 = 0;
  DAT_00fb7284 = 0;
  DAT_00fb7288 = 0;
  DAT_00fb7290 = 0;
  DAT_00fb7294 = 0;
  DAT_00fb7298 = 0;
  local_8 = 3;
  FUN_004a7ae0(DAT_00d61f20 ^ (uint)&stack0xfffffffc,&DAT_00fb7260);
  FUN_004a7f90();
  ExceptionList = local_10;
  return &DAT_00fb7260;
}


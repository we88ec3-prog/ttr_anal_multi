
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004fdac0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00940290;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  DAT_00fc1cc0 = CTradeMgr::vftable;
  _eh_vector_constructor_iterator_
            (&DAT_00fc7b70,0x40,7,(_func_void_void_ptr *)&LAB_004fda00,FUN_004fdc20);
  local_8 = CONCAT31(local_8._1_3_,1);
  _eh_vector_constructor_iterator_
            (&DAT_00fc7d30,0x40,7,(_func_void_void_ptr *)&LAB_004fda00,FUN_004fdc20);
  _DAT_00fc7b6c = 0;
  _memset(&DAT_00fc7b70,0,0x1c0);
  _memset(&DAT_00fc7d30,0,0x1c0);
  DAT_00fc7ef0 = 0;
  DAT_00fc7ef4 = 0;
  DAT_00fc7ef8 = 0;
  DAT_00fc7efc = 0;
  DAT_00fc7f00 = 0;
  FUN_004fe100(uVar1);
  ExceptionList = local_10;
  return &DAT_00fc1cc0;
}


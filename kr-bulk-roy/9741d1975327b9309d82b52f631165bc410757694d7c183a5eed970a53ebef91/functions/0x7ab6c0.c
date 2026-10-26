
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007ab6c0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0090563b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  if (DAT_00fd93e0 != 0) {
    FUN_0089120c(DAT_00fd93e0,uVar1);
  }
  DAT_00fd93e0 = 0;
  _DAT_00fd93e4 = 0;
  _DAT_00fd93e8 = 0;
  _eh_vector_destructor_iterator_(&DAT_00fd936c,0x1c,4,FUN_00402c50);
  local_8 = local_8 & 0xffffff00;
  _eh_vector_destructor_iterator_(&DAT_00fd92ac,0x1c,6,FUN_00402c50);
  FUN_007ac300();
  FUN_0089120c(DAT_00fd92a0,uVar1);
  ExceptionList = local_10;
  return;
}


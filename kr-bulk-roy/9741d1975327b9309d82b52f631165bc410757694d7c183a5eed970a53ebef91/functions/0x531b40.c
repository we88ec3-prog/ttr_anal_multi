
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00531b40(void)

{
  uint uVar1;
  undefined *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923586;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = &DAT_00fe1e48;
  _eh_vector_constructor_iterator_
            (&DAT_00fe1e48,0x10,5,(_func_void_void_ptr *)&LAB_00689330,FUN_00532630);
  local_8 = 0;
  _DAT_00fe1ea0 = 0;
  DAT_00fe1e9c = FUN_00820120(uVar1,puVar2);
  *(int *)DAT_00fe1e9c = DAT_00fe1e9c;
  *(int *)(DAT_00fe1e9c + 4) = DAT_00fe1e9c;
  *(int *)(DAT_00fe1e9c + 8) = DAT_00fe1e9c;
  *(undefined1 *)(DAT_00fe1e9c + 0x18) = 1;
  *(undefined1 *)(DAT_00fe1e9c + 0x19) = 1;
  local_8._0_1_ = 1;
  _eh_vector_constructor_iterator_(&DAT_00fe1ea8,0x10,4,FUN_00532740,FUN_00531c00);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00531d00();
  ExceptionList = local_10;
  return &DAT_00fe1e48;
}


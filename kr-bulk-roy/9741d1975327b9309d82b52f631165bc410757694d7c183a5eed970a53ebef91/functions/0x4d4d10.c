
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004d4d10(void)

{
  undefined4 *puVar1;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b138;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fb11e8;
  DAT_00fb11e8 = 0;
  DAT_00fb11ec = 0;
  DAT_00fb11f0 = 0;
  _DAT_00fb11f4 = 0;
  local_8 = 0;
  DAT_00fb11fc = (undefined4 *)0x0;
  puVar1 = (undefined4 *)FUN_00891268(8,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_00fb11fc = puVar1;
    *puVar1 = 0;
    puVar1[1] = 0;
    *DAT_00fb11fc = &DAT_00fb11fc;
    _DAT_00fb1200 = 0;
    _DAT_00fb1204 = 0;
    _DAT_00fb1208 = 0;
    _DAT_00fb120c = 0;
    local_8._0_1_ = 1;
    _eh_vector_constructor_iterator_(&DAT_00fb1214,0x18,8,FUN_004d7f50,FUN_004d7fc0);
    _DAT_00fb12d4 = 0;
    DAT_00fb12ec = 7;
    _DAT_00fb12e8 = 0;
    DAT_00fb12d8._0_2_ = 0;
    DAT_00fb12f4 = 0;
    _DAT_00fb12f8 = 0;
    _DAT_00fb12fc = 0;
    local_8 = CONCAT31(local_8._1_3_,4);
    _DAT_00fb1304 = 0;
    DAT_00fb1308 = 0;
    _DAT_00fb130c = 0;
    FUN_004d76c0();
    ExceptionList = local_10;
    return &DAT_00fb11e8;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


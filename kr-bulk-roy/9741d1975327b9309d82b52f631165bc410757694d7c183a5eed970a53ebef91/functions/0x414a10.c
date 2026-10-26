
undefined4 * FUN_00414a10(undefined4 *param_1)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009137db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007451f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x20] = 0;
  *param_1 = FUI::CCashShopSell::vftable;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  param_1[0x34] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_14);
    local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_20,&DAT_00c857a8);
  }
  param_1[0x33] = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1[0x33] + 4) = param_1[0x33];
  *(undefined4 *)(param_1[0x33] + 8) = param_1[0x33];
  *(undefined1 *)(param_1[0x33] + 0x14) = 1;
  *(undefined1 *)(param_1[0x33] + 0x15) = 1;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  local_8._0_1_ = 2;
  _eh_vector_constructor_iterator_
            (param_1 + 0x38,0x10,6,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
  local_8._0_1_ = 3;
  _eh_vector_constructor_iterator_
            (param_1 + 0x50,0x10,6,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
  param_1[0x68] = 0xffffffff;
  param_1[0x69] = 0xffffffff;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  local_8._0_1_ = 5;
  _eh_vector_constructor_iterator_
            (param_1 + 0x70,0x10,0xf,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
  local_8._0_1_ = 6;
  _eh_vector_constructor_iterator_
            (param_1 + 0xac,0x10,0xf,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
  local_8._0_1_ = 7;
  _eh_vector_constructor_iterator_
            (param_1 + 0xe8,0x10,0xf,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
  local_8 = CONCAT31(local_8._1_3_,8);
  param_1[0x124] = 0;
  param_1[0x125] = 0;
  param_1[0x12a] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    param_1[0x129] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x129] + 4) = param_1[0x129];
    *(undefined4 *)(param_1[0x129] + 8) = param_1[0x129];
    *(undefined1 *)(param_1[0x129] + 0x14) = 1;
    *(undefined1 *)(param_1[0x129] + 0x15) = 1;
    param_1[0x126] = 0;
    *(undefined2 *)(param_1 + 0x127) = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


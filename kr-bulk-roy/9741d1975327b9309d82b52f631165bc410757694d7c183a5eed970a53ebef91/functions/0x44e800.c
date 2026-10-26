
int FUN_0044e800(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009257d6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 != 0) {
    *(int *)(param_1 + 4) = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x2c) = 1;
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x2d) = 1;
    local_8 = 0;
    *(undefined4 *)(param_1 + 0x24) = 7;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined2 *)(param_1 + 0x10) = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    local_8._0_1_ = 1;
    *(undefined4 *)(param_1 + 0x40) = 7;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined2 *)(param_1 + 0x2c) = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    local_8._0_1_ = 2;
    *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
    _eh_vector_constructor_iterator_
              ((void *)(param_1 + 0x50),0x1c,6,(_func_void_void_ptr *)&LAB_00402140,FUN_004fa440);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00402160(L"normal",6);
    FUN_00402160(L"spring",6);
    FUN_00402160(L"summer",6);
    FUN_00402160(L"autumn",6);
    FUN_00402160(L"winter",6);
    FUN_0044e960(param_1);
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


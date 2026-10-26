
undefined4 * FUN_00843940(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090e331;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0077fd70(param_1);
  local_8 = 0;
  *param_1 = gbMaterial::vftable;
  param_1[0x17] = 0;
  uVar2 = FUN_00820120(uVar1);
  param_1[0x16] = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(undefined4 *)(param_1[0x16] + 4) = param_1[0x16];
  *(undefined4 *)(param_1[0x16] + 8) = param_1[0x16];
  *(undefined1 *)(param_1[0x16] + 0x18) = 1;
  *(undefined1 *)(param_1[0x16] + 0x19) = 1;
  local_8._0_1_ = 1;
  _eh_vector_constructor_iterator_(param_1 + 0x19,0x10,8,FUN_00844c20,FUN_00843ab0);
  local_8._0_1_ = 2;
  _eh_vector_constructor_iterator_(param_1 + 0x39,0x10,8,FUN_00844c20,FUN_00843ab0);
  local_8 = CONCAT31(local_8._1_3_,3);
  param_1[0x59] = 0;
  param_1[0x5b] = 0;
  param_1[0x5e] = 0;
  iVar3 = FUN_00891268(0x18);
  if (iVar3 != 0) {
    param_1[0x5d] = iVar3;
    *(int *)iVar3 = iVar3;
    *(undefined4 *)(param_1[0x5d] + 4) = param_1[0x5d];
    *(undefined4 *)(param_1[0x5d] + 8) = param_1[0x5d];
    *(undefined1 *)(param_1[0x5d] + 0x14) = 1;
    *(undefined1 *)(param_1[0x5d] + 0x15) = 1;
    param_1[0x5a] = 0;
    param_1[0x60] = 0xffffffff;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


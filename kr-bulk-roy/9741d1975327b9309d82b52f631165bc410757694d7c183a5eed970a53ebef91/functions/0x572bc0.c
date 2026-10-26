
undefined4 * FUN_00572bc0(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ceb6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  local_8 = 0;
  puVar3 = param_1 + 5;
  *puVar3 = 0;
  puVar2 = (undefined4 *)FUN_00891268(8,uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  *puVar3 = puVar2;
  puVar2[1] = 0;
  *puVar2 = 0;
  *(undefined4 **)*puVar3 = puVar3;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  puVar2 = param_1 + 0xb;
  *puVar2 = 0;
  puVar3 = (undefined4 *)FUN_00891268(8,uVar1);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar2 = puVar3;
    *puVar3 = 0;
    puVar3[1] = 0;
    *(undefined4 **)*puVar2 = puVar2;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    FUN_006df330();
    FUN_007b6d70();
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


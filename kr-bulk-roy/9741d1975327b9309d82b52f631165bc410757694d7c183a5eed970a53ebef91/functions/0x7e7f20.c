
undefined4 * FUN_007e7f20(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00934a8d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = IS3D::CDecalMgr::vftable;
  param_1[3] = 0;
  iVar2 = FUN_00891268(0x5c,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[2] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(param_1[2] + 4) = param_1[2];
  *(undefined4 *)(param_1[2] + 8) = param_1[2];
  *(undefined1 *)(param_1[2] + 0x58) = 1;
  *(undefined1 *)(param_1[2] + 0x59) = 1;
  local_8._0_1_ = 1;
  param_1[7] = 0;
  iVar2 = FUN_00891268(0x5c,uVar1);
  if (iVar2 != 0) {
    param_1[6] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[6] + 4) = param_1[6];
    *(undefined4 *)(param_1[6] + 8) = param_1[6];
    *(undefined1 *)(param_1[6] + 0x58) = 1;
    *(undefined1 *)(param_1[6] + 0x59) = 1;
    local_8._0_1_ = 2;
    local_18 = (char *)FUN_00891268(0x3c,uVar1);
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_18 == (char *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_007f3080(0xc00);
    }
    param_1[9] = uVar3;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


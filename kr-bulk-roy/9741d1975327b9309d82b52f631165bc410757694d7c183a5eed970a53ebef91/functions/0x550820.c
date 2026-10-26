
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00550820(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_3c [3];
  undefined **local_30 [3];
  undefined *local_24;
  undefined4 *local_20;
  char *local_1c;
  char *local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908323;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = &DAT_00fdf680;
  local_8 = 0;
  DAT_00fdf680 = CCustomEffectMgr::vftable;
  _DAT_00fdf688 = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 == 0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_3c,&local_1c);
    local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_3c,&DAT_00c857a8);
  }
  DAT_00fdf684 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fdf684 + 4) = DAT_00fdf684;
  local_8._0_1_ = 1;
  _DAT_00fdf698 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  DAT_00fdf694 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fdf694 + 4) = DAT_00fdf694;
  *(int *)(DAT_00fdf694 + 8) = DAT_00fdf694;
  *(undefined1 *)(DAT_00fdf694 + 0x14) = 1;
  *(undefined1 *)(DAT_00fdf694 + 0x15) = 1;
  local_8._0_1_ = 2;
  _DAT_00fdf6a8 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 == 0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_3c,&local_1c);
    local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_3c,&DAT_00c857a8);
  }
  DAT_00fdf6a4 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fdf6a4 + 4) = DAT_00fdf6a4;
  *(int *)(DAT_00fdf6a4 + 8) = DAT_00fdf6a4;
  *(undefined1 *)(DAT_00fdf6a4 + 0x2c) = 1;
  *(undefined1 *)(DAT_00fdf6a4 + 0x2d) = 1;
  local_8._0_1_ = 3;
  local_24 = &DAT_00fdf6b0;
  DAT_00fdf6b0 = local_11;
  _DAT_00fdf6b8 = 0;
  iVar2 = FUN_00891268(0x28,uVar1);
  if (iVar2 != 0) {
    DAT_00fdf6b4 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fdf6b4 + 4) = DAT_00fdf6b4;
    _DAT_00fdf6c0 = 0;
    _DAT_00fdf6c4 = 0;
    _DAT_00fdf6c8 = 0;
    local_8 = CONCAT31(local_8._1_3_,5);
    _DAT_00fdf6d8 = 0x3f800000;
    FUN_007dcc30(8);
    ExceptionList = local_10;
    return &DAT_00fdf680;
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_30,&local_18);
  local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_30,&DAT_00c857a8);
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0050caf0(void)

{
  int iVar1;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009240bc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = &DAT_00fe17c0;
  FUN_0050de90(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  _DAT_00fe17d8 = 0;
  iVar1 = FUN_00891268(0x6c);
  if (iVar1 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fe17d4 = iVar1;
  *(int *)iVar1 = iVar1;
  *(int *)(DAT_00fe17d4 + 4) = DAT_00fe17d4;
  *(int *)(DAT_00fe17d4 + 8) = DAT_00fe17d4;
  *(undefined1 *)(DAT_00fe17d4 + 0x68) = 1;
  *(undefined1 *)(DAT_00fe17d4 + 0x69) = 1;
  local_8._0_1_ = 1;
  _DAT_00fe17e8 = 0;
  iVar1 = FUN_00891268(0x34);
  if (iVar1 != 0) {
    DAT_00fe17e4 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe17e4 + 4) = DAT_00fe17e4;
    *(int *)(DAT_00fe17e4 + 8) = DAT_00fe17e4;
    *(undefined1 *)(DAT_00fe17e4 + 0x30) = 1;
    *(undefined1 *)(DAT_00fe17e4 + 0x31) = 1;
    local_8._0_1_ = 2;
    _DAT_00fe17f8 = 0;
    DAT_00fe17f4 = FUN_00820120();
    *(int *)DAT_00fe17f4 = DAT_00fe17f4;
    *(int *)(DAT_00fe17f4 + 4) = DAT_00fe17f4;
    *(int *)(DAT_00fe17f4 + 8) = DAT_00fe17f4;
    *(undefined1 *)(DAT_00fe17f4 + 0x18) = 1;
    *(undefined1 *)(DAT_00fe17f4 + 0x19) = 1;
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0050cee0();
    ExceptionList = local_10;
    return &DAT_00fe17c0;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}


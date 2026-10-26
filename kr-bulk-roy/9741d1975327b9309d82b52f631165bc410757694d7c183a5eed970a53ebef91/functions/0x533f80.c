
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00533f80(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009233c6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = &DAT_00fe1be0;
  DAT_00fe1be4 = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_24,&local_14);
    local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_24,&DAT_00c857a8);
  }
  DAT_00fe1be0 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fe1be0 + 4) = DAT_00fe1be0;
  local_8 = 0;
  FUN_00537140(&DAT_00fe1bec);
  local_8._0_1_ = 1;
  _DAT_00fe1c14 = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 != 0) {
    DAT_00fe1c10 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fe1c10 + 4) = DAT_00fe1c10;
    DAT_00fe1c2c = 0;
    DAT_00fe1c30 = 0;
    _DAT_00fe1c34 = 0;
    DAT_00fe1c3c = 0;
    DAT_00fe1c40 = 0;
    _DAT_00fe1c44 = 0;
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_00534290();
    FUN_00534480();
    _DAT_00fe1c0c = 500;
    DAT_00fe1c28 = 0;
    ExceptionList = local_10;
    return &DAT_00fe1be0;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


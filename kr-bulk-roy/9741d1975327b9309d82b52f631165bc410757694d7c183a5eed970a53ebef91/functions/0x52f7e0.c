
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0052f7e0(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_44 [3];
  undefined **local_38 [3];
  undefined **local_2c [3];
  undefined *local_20;
  char *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908517;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = &DAT_00fc1098;
  _DAT_00fc10a0 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_44,&local_1c);
    local_44[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_44,&DAT_00c857a8);
  }
  DAT_00fc109c = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fc109c + 4) = DAT_00fc109c;
  *(int *)(DAT_00fc109c + 8) = DAT_00fc109c;
  *(undefined1 *)(DAT_00fc109c + 0x14) = 1;
  *(undefined1 *)(DAT_00fc109c + 0x15) = 1;
  local_8 = 0;
  _DAT_00fc10b0 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    DAT_00fc10ac = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fc10ac + 4) = DAT_00fc10ac;
    *(int *)(DAT_00fc10ac + 8) = DAT_00fc10ac;
    *(undefined1 *)(DAT_00fc10ac + 0x14) = 1;
    *(undefined1 *)(DAT_00fc10ac + 0x15) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    _DAT_00fc10c0 = 0;
    iVar2 = FUN_00891268(0x18,uVar1);
    if (iVar2 != 0) {
      DAT_00fc10bc = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00fc10bc + 4) = DAT_00fc10bc;
      *(int *)(DAT_00fc10bc + 8) = DAT_00fc10bc;
      *(undefined1 *)(DAT_00fc10bc + 0x14) = 1;
      *(undefined1 *)(DAT_00fc10bc + 0x15) = 1;
      DAT_00fc10c8 = 0;
      ExceptionList = local_10;
      return &DAT_00fc1098;
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_2c,&local_14);
    local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_2c,&DAT_00c857a8);
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_38,&local_18);
  local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_38,&DAT_00c857a8);
}


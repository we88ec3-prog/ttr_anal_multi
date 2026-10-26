
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0058d410(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912ab3;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00faaf80;
  _DAT_00faaf80 = FUI::FXUIHistory::vftable;
  _DAT_00faaf84 = FUI::FXUIAttributeHistory::vftable;
  _DAT_00faaf90 = 0;
  iVar2 = FUN_00891268(0x48,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00faaf8c = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00faaf8c + 4) = DAT_00faaf8c;
  *(int *)(DAT_00faaf8c + 8) = DAT_00faaf8c;
  *(undefined1 *)(DAT_00faaf8c + 0x44) = 1;
  *(undefined1 *)(DAT_00faaf8c + 0x45) = 1;
  local_8 = 0;
  _DAT_00faafa0 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 != 0) {
    DAT_00faaf9c = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00faaf9c + 4) = DAT_00faaf9c;
    *(int *)(DAT_00faaf9c + 8) = DAT_00faaf9c;
    *(undefined1 *)(DAT_00faaf9c + 0x2c) = 1;
    *(undefined1 *)(DAT_00faaf9c + 0x2d) = 1;
    DAT_00faafbc = 7;
    _DAT_00faafb8 = 0;
    DAT_00faafa8._0_2_ = 0;
    local_8 = CONCAT31(local_8._1_3_,2);
    _DAT_00faafcc = 0;
    iVar2 = FUN_00891268(0x40,uVar1);
    if (iVar2 != 0) {
      DAT_00faafc8 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00faafc8 + 4) = DAT_00faafc8;
      *(int *)(DAT_00faafc8 + 8) = DAT_00faafc8;
      *(undefined1 *)(DAT_00faafc8 + 0x3c) = 1;
      *(undefined1 *)(DAT_00faafc8 + 0x3d) = 1;
      ExceptionList = local_10;
      return &DAT_00faaf80;
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00511ca0(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00923f28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fb1354;
  _DAT_00fb1354 = CCashShopTable::vftable;
  DAT_00fb1358 = 0;
  DAT_00fb135c = 0;
  DAT_00fb1360 = 0;
  local_8 = 0;
  _DAT_00fb1370 = 0;
  iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fb136c = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb136c + 4) = DAT_00fb136c;
    *(int *)(DAT_00fb136c + 8) = DAT_00fb136c;
    *(undefined1 *)(DAT_00fb136c + 0x14) = 1;
    *(undefined1 *)(DAT_00fb136c + 0x15) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00511e40();
    ExceptionList = local_10;
    return &DAT_00fb1354;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


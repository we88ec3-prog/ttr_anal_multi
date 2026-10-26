
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0075f1d0(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ed28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fb72fc;
  local_8 = 0;
  _DAT_00fb72fc = FoxUI::FXUIManagerContainer<unsigned_int,FoxUI::FXUICharSet>::vftable;
  _DAT_00fb7308 = 0;
  iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fb7304 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb7304 + 4) = DAT_00fb7304;
    *(int *)(DAT_00fb7304 + 8) = DAT_00fb7304;
    *(undefined1 *)(DAT_00fb7304 + 0x14) = 1;
    *(undefined1 *)(DAT_00fb7304 + 0x15) = 1;
    ExceptionList = local_10;
    return &DAT_00fb72fc;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00764640(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ed28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00faafd8;
  local_8 = 0;
  DAT_00faafd8 = FoxUI::FXUIManagerContainer<unsigned_int,FoxUI::FXUICmdTarget>::vftable;
  _DAT_00faafe4 = 0;
  iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00faafe0 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00faafe0 + 4) = DAT_00faafe0;
    *(int *)(DAT_00faafe0 + 8) = DAT_00faafe0;
    *(undefined1 *)(DAT_00faafe0 + 0x14) = 1;
    *(undefined1 *)(DAT_00faafe0 + 0x15) = 1;
    ExceptionList = local_10;
    return &DAT_00faafd8;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0053f970(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00923212;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fe18cc;
  DAT_00fe18cc = 0;
  DAT_00fe18d0 = 0;
  _DAT_00fe18d4 = 0;
  local_8 = 0;
  _DAT_00fe18e4 = 0;
  iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fe18e0 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe18e0 + 4) = DAT_00fe18e0;
    *(int *)(DAT_00fe18e0 + 8) = DAT_00fe18e0;
    *(undefined1 *)(DAT_00fe18e0 + 0x14) = 1;
    *(undefined1 *)(DAT_00fe18e0 + 0x15) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0053fbb0();
    ExceptionList = local_10;
    return &DAT_00fe18cc;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


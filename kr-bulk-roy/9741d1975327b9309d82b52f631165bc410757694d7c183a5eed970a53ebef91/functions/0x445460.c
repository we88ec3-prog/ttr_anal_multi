
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00445460(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00925890;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fb93d0;
  DAT_00fb93d0 = 0;
  DAT_00fb93d4 = 0;
  DAT_00fb93d8 = 0;
  DAT_00fb93e0 = 0;
  DAT_00fb93e4 = 0;
  DAT_00fb93e8 = 0;
  local_8 = 1;
  uStack_7 = 0;
  _DAT_00fb93f8 = 0;
  iVar1 = FUN_00891268(0x30,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fb93f4 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb93f4 + 4) = DAT_00fb93f4;
    *(int *)(DAT_00fb93f4 + 8) = DAT_00fb93f4;
    *(undefined1 *)(DAT_00fb93f4 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fb93f4 + 0x2d) = 1;
    _local_8 = CONCAT31(uStack_7,2);
    FUN_00445600();
    ExceptionList = local_10;
    return &DAT_00fb93d0;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0047faf0(void)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910c25;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0047ffb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  _DAT_00fe1b4c = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    DAT_00fe1b48 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe1b48 + 4) = DAT_00fe1b48;
    *(int *)(DAT_00fe1b48 + 8) = DAT_00fe1b48;
    *(undefined1 *)(DAT_00fe1b48 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe1b48 + 0x2d) = 1;
    ExceptionList = local_10;
    return &DAT_00fe1b34;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


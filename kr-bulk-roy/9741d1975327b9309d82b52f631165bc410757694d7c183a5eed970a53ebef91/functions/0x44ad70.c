
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0044ad70(void)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908b25;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0044b610(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  _DAT_00fb93ac = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    DAT_00fb93a8 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb93a8 + 4) = DAT_00fb93a8;
    *(int *)(DAT_00fb93a8 + 8) = DAT_00fb93a8;
    *(undefined1 *)(DAT_00fb93a8 + 0x14) = 1;
    *(undefined1 *)(DAT_00fb93a8 + 0x15) = 1;
    _DAT_00fb93b4 = 1;
    ExceptionList = local_10;
    return &DAT_00fb9394;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


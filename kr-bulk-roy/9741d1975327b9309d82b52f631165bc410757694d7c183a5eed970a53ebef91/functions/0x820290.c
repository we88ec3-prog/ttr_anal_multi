
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00820290(void)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c105;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fb7bd8 = 0;
  DAT_00fb7bd4 = FUN_00820120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(int *)DAT_00fb7bd4 = DAT_00fb7bd4;
  *(int *)(DAT_00fb7bd4 + 4) = DAT_00fb7bd4;
  *(int *)(DAT_00fb7bd4 + 8) = DAT_00fb7bd4;
  *(undefined1 *)(DAT_00fb7bd4 + 0x18) = 1;
  *(undefined1 *)(DAT_00fb7bd4 + 0x19) = 1;
  local_8 = 0;
  _DAT_00fb7be8 = 0;
  iVar1 = FUN_00891268(0x28);
  if (iVar1 != 0) {
    DAT_00fb7be4 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb7be4 + 4) = DAT_00fb7be4;
    *(int *)(DAT_00fb7be4 + 8) = DAT_00fb7be4;
    *(undefined1 *)(DAT_00fb7be4 + 0x24) = 1;
    *(undefined1 *)(DAT_00fb7be4 + 0x25) = 1;
    DAT_00fb7bf0 = 0;
    DAT_00fb7bf4 = 0;
    _DAT_00fb7bf8 = 0;
    DAT_00fb7c04 = 0;
    _DAT_00fb7c08 = 0;
    _DAT_00fb7c0c = 0;
    ExceptionList = local_10;
    return &DAT_00fb7bd0;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


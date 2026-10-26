
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0081b920(void)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911645;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fb7330 = 0;
  DAT_00fb732c = FUN_00570a10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(int *)DAT_00fb732c = DAT_00fb732c;
  *(int *)(DAT_00fb732c + 4) = DAT_00fb732c;
  *(int *)(DAT_00fb732c + 8) = DAT_00fb732c;
  *(undefined1 *)(DAT_00fb732c + 0x40) = 1;
  *(undefined1 *)(DAT_00fb732c + 0x41) = 1;
  local_8 = 0;
  _DAT_00fb7340 = 0;
  iVar1 = FUN_00891268(0x10);
  if (iVar1 != 0) {
    DAT_00fb733c = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb733c + 4) = DAT_00fb733c;
    *(int *)(DAT_00fb733c + 8) = DAT_00fb733c;
    *(undefined1 *)(DAT_00fb733c + 0xe) = 1;
    *(undefined1 *)(DAT_00fb733c + 0xf) = 1;
    ExceptionList = local_10;
    return &DAT_00fb7328;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


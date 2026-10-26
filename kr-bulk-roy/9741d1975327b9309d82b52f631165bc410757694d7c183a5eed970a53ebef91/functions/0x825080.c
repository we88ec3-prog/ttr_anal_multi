
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_00825080(void)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907215;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fbacf0 = 0;
  DAT_00fbacf4 = 0;
  _DAT_00fbacf8 = 0;
  local_8 = 0;
  _DAT_00fbad08 = 0;
  iVar1 = FUN_00891268(0x28,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fbad04 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fbad04 + 4) = DAT_00fbad04;
    *(int *)(DAT_00fbad04 + 8) = DAT_00fbad04;
    *(undefined1 *)(DAT_00fbad04 + 0x24) = 1;
    *(undefined1 *)(DAT_00fbad04 + 0x25) = 1;
    ExceptionList = local_10;
    return &DAT_00fbace8;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


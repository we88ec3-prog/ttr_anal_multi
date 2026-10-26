
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00832a70(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906f80;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fe3438;
  DAT_00fe3438 = 0;
  DAT_00fe343c = 0;
  _DAT_00fe3440 = 0;
  DAT_00fe3448 = 0;
  _DAT_00fe344c = 0;
  _DAT_00fe3450 = 0;
  local_8 = 1;
  _DAT_00fe3460 = 0;
  iVar1 = FUN_00891268(0x24,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fe345c = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe345c + 4) = DAT_00fe345c;
    *(int *)(DAT_00fe345c + 8) = DAT_00fe345c;
    *(undefined1 *)(DAT_00fe345c + 0x20) = 1;
    *(undefined1 *)(DAT_00fe345c + 0x21) = 1;
    DAT_00fe3468 = 0;
    _DAT_00fe346c = 0;
    _DAT_00fe3470 = 0;
    ExceptionList = local_10;
    return &DAT_00fe3438;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0053c300(void)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009366e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fc7f20;
  local_8 = 0;
  DAT_00fc7f20 = CUnionPartyMgr::vftable;
  _DAT_00fcddd4 = 0;
  iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fcddd0 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fcddd0 + 4) = DAT_00fcddd0;
    *(int *)(DAT_00fcddd0 + 8) = DAT_00fcddd0;
    *(undefined1 *)(DAT_00fcddd0 + 0x14) = 1;
    *(undefined1 *)(DAT_00fcddd0 + 0x15) = 1;
    DAT_00fcdddc = 0;
    FUN_0053c470();
    ExceptionList = local_10;
    return extraout_EDX;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


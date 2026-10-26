
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00539c20(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093ffe6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fb1380;
  DAT_00fb1380 = CPartyMgr::vftable;
  DAT_00fb722c = 0;
  DAT_00fb7230 = 0;
  _DAT_00fb7234 = 0;
  DAT_00fb7238 = 0;
  DAT_00fb723c = 0;
  _DAT_00fb7240 = 0;
  local_8 = 1;
  _DAT_00fb7250 = 0;
  iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fb724c = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb724c + 4) = DAT_00fb724c;
    *(int *)(DAT_00fb724c + 8) = DAT_00fb724c;
    *(undefined1 *)(DAT_00fb724c + 0x14) = 1;
    *(undefined1 *)(DAT_00fb724c + 0x15) = 1;
    DAT_00fb7258 = 0;
    FUN_00539df0();
    ExceptionList = local_10;
    return extraout_ECX;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


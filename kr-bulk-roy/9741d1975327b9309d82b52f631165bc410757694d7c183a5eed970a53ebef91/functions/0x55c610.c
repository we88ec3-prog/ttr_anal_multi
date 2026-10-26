
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0055c610(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009389a8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = &DAT_00fe1eec;
  _DAT_00fe1efc = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    DAT_00fe1ef8 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fe1ef8 + 4) = DAT_00fe1ef8;
    *(int *)(DAT_00fe1ef8 + 8) = DAT_00fe1ef8;
    *(undefined1 *)(DAT_00fe1ef8 + 0x14) = 1;
    *(undefined1 *)(DAT_00fe1ef8 + 0x15) = 1;
    DAT_00fe1f18 = 0xf;
    _DAT_00fe1f14 = 0;
    DAT_00fe1f04._0_1_ = 0;
    local_8 = 1;
    DAT_00fe1eec = FUN_006f74b0();
    if (DAT_00fe1eec != 0) {
      *(code **)(*(int *)(DAT_00fe1eec + 0x10) + 0x58) = FUN_006f71a0;
    }
    DAT_00fe1ef0 = (int *)FUN_00891268(0xc,uVar1);
    if (DAT_00fe1ef0 == (int *)0x0) {
      DAT_00fe1ef0 = (int *)0x0;
    }
    else {
      *DAT_00fe1ef0 = DAT_00fe1eec;
      DAT_00fe1ef0[1] = 0;
      DAT_00fe1ef0[2] = 0;
    }
    FUN_0055d7e0();
    ExceptionList = local_10;
    return &DAT_00fe1eec;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


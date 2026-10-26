
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0055ac10(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905d45;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_00fd8eb4 = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 != 0) {
    DAT_00fd8eb0 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fd8eb0 + 4) = DAT_00fd8eb0;
    local_8 = 0;
    DAT_00fd8ebc = (undefined4 *)FUN_00891268(0x28,uVar1);
    if (DAT_00fd8ebc == (undefined4 *)0x0) {
      DAT_00fd8ebc = (undefined4 *)0x0;
    }
    else {
      *(undefined1 *)(DAT_00fd8ebc + 1) = 0;
      DAT_00fd8ebc[3] = 0;
      DAT_00fd8ebc[4] = 0;
      DAT_00fd8ebc[5] = 0;
      DAT_00fd8ebc[6] = 0;
      *DAT_00fd8ebc = Graphics::CImageRHW::vftable;
    }
    _DAT_00fd8ec4 = 0xffffffff;
    _DAT_00fd8ec8 = 0xffffffff;
    _DAT_00fd8ecc = 0xffffffff;
    _DAT_00fd8ed0 = 0xffffffff;
    _DAT_00fd8ed4 = 0xffffffff;
    _DAT_00fd8ed8 = 0xffffffff;
    _DAT_00fd8eec = 0xffffffff;
    _DAT_00fd8ef0 = 0xffffffff;
    _DAT_00fd8ee4 = 0xff00ffff;
    _DAT_00fd8ee8 = 0xff00ffff;
    _DAT_00fd8ec0 = 1;
    _DAT_00fd8edc = 0xff00bbdd;
    _DAT_00fd8ee0 = 0xffff71f3;
    _DAT_00fd8ef4 = 0xff9eeeff;
    ExceptionList = local_10;
    return &DAT_00fd8eb0;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


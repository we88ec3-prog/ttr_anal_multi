
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007bb970(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093507d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fe1ac8;
  _DAT_00fe1ac8 = IS3D::CTextureMgr::vftable;
  _DAT_00fe1af4 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fe1af0 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fe1af0 + 4) = DAT_00fe1af0;
  *(int *)(DAT_00fe1af0 + 8) = DAT_00fe1af0;
  *(undefined1 *)(DAT_00fe1af0 + 0x2c) = 1;
  *(undefined1 *)(DAT_00fe1af0 + 0x2d) = 1;
  local_8 = 0;
  _DAT_00fe1b00 = 0;
  iVar2 = FUN_00891268(0x50,uVar1);
  if (iVar2 != 0) {
    DAT_00fe1afc = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fe1afc + 4) = DAT_00fe1afc;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
    DAT_00fe1b2c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    _DAT_00fe1ad8 = FUN_007bc6e0;
    DAT_00fe1ae8 = FUN_007bc6e0;
    _DAT_00fe1acc = FUN_007bc060;
    _DAT_00fe1ad0 = FUN_007bc2c0;
    _DAT_00fe1ad4 = FUN_007bc4d0;
    DAT_00fe1adc = FUN_007bc060;
    DAT_00fe1ae0 = FUN_007bc2c0;
    DAT_00fe1ae4 = FUN_007bc4d0;
    ExceptionList = local_10;
    return &DAT_00fe1ac8;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}


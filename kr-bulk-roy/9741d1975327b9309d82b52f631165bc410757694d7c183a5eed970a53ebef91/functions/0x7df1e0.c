
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_007df1e0(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009076b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fe3288;
  local_8 = 0;
  DAT_00fe3288 = IS3D::CStaticMeshMgr::vftable;
  DAT_00fe328c = 0;
  _DAT_00fe3298 = 0;
  iVar1 = FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fe3294 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3294 + 4) = DAT_00fe3294;
    *(int *)(DAT_00fe3294 + 8) = DAT_00fe3294;
    *(undefined1 *)(DAT_00fe3294 + 0x10) = 1;
    *(undefined1 *)(DAT_00fe3294 + 0x11) = 1;
    _DAT_00fe32a0 = 0;
    _DAT_00fe32a4 = 0;
    _DAT_00fe32a8 = 0;
    _DAT_00fe32b0 = 0;
    _DAT_00fe32b4 = 0x2000;
    _DAT_00fe32b8 = 0x4000;
    ExceptionList = local_10;
    return &DAT_00fe3288;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}


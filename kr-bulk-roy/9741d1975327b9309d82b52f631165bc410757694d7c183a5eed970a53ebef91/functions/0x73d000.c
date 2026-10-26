
undefined4 * FUN_0073d000(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  int *unaff_FS_OFFSET;
  undefined **local_20 [3];
  char *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f13a;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  *param_1 = 0;
  FUN_0073e090(param_1 + 1);
  local_8 = 0;
  param_1[0xd] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[0xc] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0xc] + 4) = param_1[0xc];
    *(undefined4 *)(param_1[0xc] + 8) = param_1[0xc];
    *(undefined1 *)(param_1[0xc] + 0x14) = 1;
    *(undefined1 *)(param_1[0xc] + 0x15) = 1;
    param_1[0xf] = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    _Dst = (void *)FUN_0087dc3d(0x600000);
    param_1[0x11] = _Dst;
    _memset(_Dst,0,0x600000);
    *unaff_FS_OFFSET = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


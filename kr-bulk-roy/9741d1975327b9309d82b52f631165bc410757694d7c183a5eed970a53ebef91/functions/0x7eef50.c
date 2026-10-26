
undefined4 * FUN_007eef50(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c621;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[10] = 0;
  param_1[2] = 0;
  param_1[0xb] = 0;
  param_1[3] = 0;
  param_1[0xc] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0x3f800000;
  param_1[8] = 0x3f800000;
  param_1[9] = 0x3f800000;
  param_1[0xe] = 0;
  param_1[0x10] = IS3D::AnimationLoadEventReciver::vftable;
  *param_1 = IS3D::CItemBaseNodeSimple::vftable;
  param_1[0x10] = IS3D::CItemBaseNodeSimple::vftable;
  param_1[0x16] = 0xf;
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  param_1[0x1d] = 0xf;
  param_1[0x1c] = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  param_1[0x24] = 0xf;
  param_1[0x23] = 0;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  param_1[0x2b] = 0xf;
  param_1[0x2a] = 0;
  *(undefined1 *)(param_1 + 0x26) = 0;
  param_1[0x32] = 0xf;
  param_1[0x31] = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  param_1[0x39] = 0xf;
  param_1[0x38] = 0;
  *(undefined1 *)(param_1 + 0x34) = 0;
  param_1[0x3b] = 0;
  param_1[0x41] = 0xf;
  param_1[0x40] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  local_8 = 7;
  param_1[0x45] = 0;
  iVar2 = FUN_00891268(0x34,uVar1);
  if (iVar2 != 0) {
    param_1[0x44] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x44] + 4) = param_1[0x44];
    *(undefined4 *)(param_1[0x44] + 8) = param_1[0x44];
    *(undefined1 *)(param_1[0x44] + 0x30) = 1;
    *(undefined1 *)(param_1[0x44] + 0x31) = 1;
    param_1[0x47] = 0;
    param_1[0x48] = 0;
    param_1[0x49] = 0;
    param_1[0x4a] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


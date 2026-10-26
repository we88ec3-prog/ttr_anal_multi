
undefined4 * FUN_007a4c50(undefined4 *param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  undefined **local_2c [3];
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00907963;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = IS3D::IObject::vftable;
  param_1[2] = IDXManagedObject::vftable;
  param_1[3] = IS3D::CShadowCaster::vftable;
  param_1[4] = 0;
  param_1[5] = 0;
  local_8 = 4;
  uStack_7 = 0;
  *param_1 = IS3D::CDoll::vftable;
  param_1[1] = IS3D::CDoll::vftable;
  param_1[2] = IS3D::CDoll::vftable;
  param_1[3] = IS3D::CDoll::vftable;
  param_1[6] = param_2;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 10) = 1;
  FUN_007a5020(param_1 + 0xb);
  local_8 = 5;
  param_1[0x15] = 0;
  iVar2 = FUN_00891268(0x14,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_2c,&local_14);
    local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_2c,&DAT_00c857a8);
  }
  param_1[0x14] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(param_1[0x14] + 4) = param_1[0x14];
  *(undefined4 *)(param_1[0x14] + 8) = param_1[0x14];
  *(undefined1 *)(param_1[0x14] + 0x10) = 1;
  *(undefined1 *)(param_1[0x14] + 0x11) = 1;
  local_8 = 6;
  param_1[0x19] = 0;
  iVar2 = FUN_00891268(0x28,uVar1);
  if (iVar2 != 0) {
    param_1[0x18] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x18] + 4) = param_1[0x18];
    *(undefined4 *)(param_1[0x18] + 8) = param_1[0x18];
    *(undefined1 *)(param_1[0x18] + 0x20) = 1;
    *(undefined1 *)(param_1[0x18] + 0x21) = 1;
    local_8 = 7;
    param_1[0x1d] = 0;
    iVar2 = FUN_00891268(0x28,uVar1);
    if (iVar2 == 0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_2c,&local_14);
      local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_2c,&DAT_00c857a8);
    }
    param_1[0x1c] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x1c] + 4) = param_1[0x1c];
    *(undefined4 *)(param_1[0x1c] + 8) = param_1[0x1c];
    *(undefined1 *)(param_1[0x1c] + 0x20) = 1;
    *(undefined1 *)(param_1[0x1c] + 0x21) = 1;
    local_8 = 8;
    param_1[0x21] = 0;
    iVar2 = FUN_00891268(0x18,uVar1);
    if (iVar2 == 0) {
      param_2 = (char *)0x0;
      std::exception::exception((exception *)local_20,&param_2);
      local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    param_1[0x20] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x20] + 4) = param_1[0x20];
    *(undefined4 *)(param_1[0x20] + 8) = param_1[0x20];
    *(undefined1 *)(param_1[0x20] + 0x14) = 1;
    *(undefined1 *)(param_1[0x20] + 0x15) = 1;
    param_1[0x23] = 1;
    param_1[0x24] = 0;
    param_1[0x25] = 0;
    param_1[0x26] = 0;
    local_8 = 10;
    param_1[0x28] = 0;
    param_1[0x29] = 0;
    param_1[0x2a] = 2;
    param_1[0x2b] = 0;
    param_1[0x2c] = 0;
    param_1[0x2d] = 0;
    param_1[0x31] = 0;
    param_1[0x2e] = 0x3f800000;
    param_1[0x32] = 0;
    param_1[0x30] = 0x3f800000;
    param_1[0x33] = 0;
    param_1[0x3a] = 1;
    param_1[0x2f] = 0;
    param_1[0x36] = 0;
    param_1[0x37] = 0;
    param_1[0x38] = 0;
    param_1[0x39] = 0x3f800000;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    param_1[0x3d] = 0;
    param_1[0x3f] = 0;
    param_1[0x40] = 0;
    param_1[0x42] = 0;
    param_1[0x3e] = 0x3f800000;
    param_1[0x41] = 0x3f800000;
    param_1[0x44] = 0;
    iVar2 = FUN_00891268(0x10);
    if (iVar2 != 0) {
      param_1[0x43] = iVar2;
      *(int *)iVar2 = iVar2;
      *(undefined4 *)(param_1[0x43] + 4) = param_1[0x43];
      param_1[0x46] = 0;
      param_1[0x47] = 0;
      param_1[0x48] = 0;
      param_1[0x49] = 0;
      param_1[0x4a] = 0;
      param_1[0x4b] = 0x3f48c8c9;
      param_1[0x4c] = 0x3f48c8c9;
      param_1[0x4d] = 0x3f48c8c9;
      param_1[0x4e] = 0x3f800000;
      param_1[0x4f] = 1;
      param_1[0x50] = 0;
      param_1[0x51] = 0;
      param_1[0x52] = 0;
      param_1[0x53] = 0;
      param_1[0x54] = 0;
      param_1[0x55] = 0;
      param_1[0x57] = 0;
      param_1[0x58] = 0;
      param_1[0x59] = 0;
      param_1[0x5a] = 0;
      ExceptionList = local_10;
      return param_1;
    }
  }
  param_2 = (char *)0x0;
  std::exception::exception((exception *)local_20,&param_2);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}


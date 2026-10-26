
undefined4 * FUN_007faf00(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909b68;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[10] = 0xf;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[0x10] = 0x41f00000;
  param_1[0xc] = 0;
  param_1[0xd] = 0x3c;
  param_1[0x12] = 0;
  param_1[0x13] = 0x3000;
  param_1[0x14] = 0;
  param_1[0x15] = 0x600;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  local_8 = 0;
  *param_1 = IS3D::CQuadPatchParticleBase::vftable;
  iVar2 = FUN_00891268(0x18c,uVar1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007fae60();
  }
  param_1[0x1a] = uVar3;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x20] = 0xbf000000;
  param_1[0x21] = 0x3f000000;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x22] = 0;
  param_1[0x26] = 0x3f000000;
  param_1[0x27] = 0x3f000000;
  param_1[0x2a] = 0x3f800000;
  param_1[0x28] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0xbf000000;
  param_1[0x2d] = 0xbf000000;
  param_1[0x30] = 0;
  param_1[0x2e] = 0;
  param_1[0x31] = 0x3f800000;
  param_1[0x32] = 0xbf000000;
  param_1[0x33] = 0xbf000000;
  param_1[0x34] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0x3f800000;
  param_1[0x38] = 0x3f000000;
  param_1[0x39] = 0x3f000000;
  param_1[0x3a] = 0;
  param_1[0x3d] = 0;
  param_1[0x3c] = 0x3f800000;
  param_1[0x3e] = 0x3f000000;
  param_1[0x3f] = 0xbf000000;
  param_1[0x40] = 0;
  param_1[0x23] = 0xffffffff;
  param_1[0x29] = 0xffffffff;
  param_1[0x2f] = 0xffffffff;
  param_1[0x35] = 0xffffffff;
  param_1[0x3b] = 0xffffffff;
  param_1[0x41] = 0xffffffff;
  param_1[0x45] = 1;
  param_1[0x48] = 1;
  param_1[0x49] = 1;
  param_1[0x4c] = 1;
  param_1[0x4d] = 1;
  param_1[0x4f] = 1;
  param_1[0x42] = 0x3f800000;
  param_1[0x43] = 0x3f800000;
  param_1[0x44] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4e] = 0;
  ExceptionList = local_10;
  return param_1;
}


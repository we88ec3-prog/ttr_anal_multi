
undefined4 * FUN_007fa190(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009075b8;
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
  *param_1 = IS3D::CPointSpriteParticleBase::vftable;
  puVar2 = (undefined4 *)FUN_00891268(0x158,uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_007f9fc0();
    *puVar2 = IS3D::PS_EmitterSet::vftable;
  }
  param_1[0x1a] = puVar2;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  ExceptionList = local_10;
  return param_1;
}


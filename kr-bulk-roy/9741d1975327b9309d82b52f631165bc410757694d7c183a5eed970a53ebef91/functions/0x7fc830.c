
undefined4 * FUN_007fc830(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907558;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[9] = 1;
  param_1[10] = 1;
  param_1[0xb] = 0;
  local_8 = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *param_1 = IS3D::CItemNodeParticle::vftable;
  param_1[0xc] = 0;
  param_1[0xf] = 1;
  puVar2 = (undefined4 *)FUN_00891268(0x2c,uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    param_1[0x10] = 0;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0x3f800000;
    puVar2[7] = 0x3f800000;
    puVar2[8] = 0x3f800000;
    puVar2[9] = 0x3f800000;
    puVar2[10] = 1;
    param_1[0x10] = puVar2;
  }
  ExceptionList = local_10;
  return param_1;
}


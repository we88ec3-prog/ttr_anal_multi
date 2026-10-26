
undefined4 * FUN_008016d0(undefined4 *param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00909b38;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007f2640(param_3,param_4);
  local_8 = 0;
  *param_1 = IS3D::CPointSpriteParticle::vftable;
  param_1[0x39] = *(undefined4 *)(param_2 + 0x68);
  iVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)param_3 * 0x84 >> 0x20) != 0) |
                       (uint)((ulonglong)param_3 * 0x84),uVar1);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar4 = param_3 - 1;
    if (-1 < iVar4) {
      puVar3 = (undefined4 *)(iVar2 + 0x30);
      do {
        puVar3[-0xc] = 0;
        puVar3[-0xb] = 0;
        puVar3[-10] = 0;
        iVar4 = iVar4 + -1;
        puVar3[-9] = 0;
        puVar3[-8] = 0;
        puVar3[-7] = 0;
        puVar3[-6] = 0x3f800000;
        puVar3[-5] = 0;
        puVar3[-4] = 0;
        puVar3[-3] = 0;
        puVar3[-2] = 0;
        puVar3[-1] = 0;
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar3[6] = 0;
        puVar3[7] = 0x3f800000;
        puVar3[9] = 0;
        puVar3[10] = 0x3f800000;
        puVar3[0xb] = 0x3f800000;
        puVar3[0xc] = 0;
        puVar3[0xd] = 0x3f800000;
        puVar3[0xe] = 0x3f800000;
        puVar3[0xf] = 0;
        puVar3[0x10] = 0x3f800000;
        puVar3[0x11] = 0x3f800000;
        puVar3[0x12] = 0;
        puVar3[0x13] = 0x3f800000;
        puVar3[0x14] = 0x3f800000;
        puVar3 = puVar3 + 0x21;
      } while (-1 < iVar4);
    }
  }
  param_1[0x3b] = 0x3f800000;
  param_1[0x3a] = iVar2;
  FUN_007f2800();
  ExceptionList = local_10;
  return param_1;
}



void FUN_00803560(undefined4 param_1,float *param_2,float *param_3)

{
  int iVar1;
  int in_ECX;
  float unaff_EBX;
  undefined1 *puStack_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_74;
  float local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  float local_60 [4];
  undefined1 local_50 [40];
  uint uStack_28;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_74;
  local_84 = 1.1774141e-38;
  local_74 = (float)FUN_0089289d();
  local_70 = (float)(int)local_74 * 0.00019165625;
  local_84 = 1.1774174e-38;
  local_74 = (float)FUN_0089289d();
  local_60[0] = (float)(int)local_74 * 0.00019165625;
  local_84 = 1.1774206e-38;
  iVar1 = FUN_0089289d();
  puStack_90 = local_50;
  local_84 = (float)iVar1 * 0.00019165625;
  local_88 = local_60[0];
  local_8c = local_70;
  local_74 = local_84;
  D3DXMatrixRotationYawPitchRoll();
  uStack_6c = 0;
  uStack_68 = 0x3f800000;
  uStack_64 = 0;
  D3DXVec3TransformCoord(&uStack_6c,&uStack_6c,local_60);
  *param_3 = unaff_EBX;
  param_3[1] = local_74;
  param_3[2] = local_70;
  local_8c = *(float *)(in_ECX + 4);
  local_88 = local_8c * unaff_EBX;
  *param_2 = local_88;
  local_84 = local_74 * local_8c;
  param_2[1] = local_84;
  param_2[2] = local_8c * local_70;
  __security_check_cookie(uStack_28 ^ (uint)&puStack_90);
  return;
}


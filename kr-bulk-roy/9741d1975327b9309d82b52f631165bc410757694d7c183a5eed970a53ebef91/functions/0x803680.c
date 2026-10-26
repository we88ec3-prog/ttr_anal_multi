
void FUN_00803680(float param_1,float *param_2)

{
  int in_ECX;
  undefined1 *puStack_84;
  undefined1 *puStack_80;
  float local_7c;
  float fStack_70;
  float local_6c;
  float fStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_58 [8];
  undefined1 local_50 [48];
  uint uStack_20;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&fStack_70;
  puStack_80 = local_50;
  local_7c = param_1 * 6.28 * *(float *)(in_ECX + 8);
  puStack_84 = (undefined1 *)0x8036c0;
  local_6c = local_7c;
  D3DXMatrixRotationZ();
  uStack_64 = 0;
  puStack_84 = auStack_58;
  uStack_60 = 0x3f800000;
  uStack_5c = 0;
  D3DXVec3TransformCoord(&uStack_64,&uStack_64);
  puStack_80 = *(undefined1 **)(in_ECX + 4);
  local_7c = (float)puStack_80 * fStack_70;
  *param_2 = local_7c;
  param_2[1] = (float)puStack_80 * local_6c;
  param_2[2] = (float)puStack_80 * fStack_68;
  __security_check_cookie(uStack_20 ^ (uint)&puStack_84);
  return;
}


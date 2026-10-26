
void FUN_00803410(undefined4 param_1,float *param_2)

{
  int iVar1;
  float fVar2;
  int in_ECX;
  float fVar3;
  float fVar4;
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
  local_7c = 1.1773665e-38;
  iVar1 = FUN_0089289d();
  puStack_80 = local_50;
  local_7c = ((float)iVar1 / 32767.0) * 6.28;
  puStack_84 = (undefined1 *)0x80345b;
  local_6c = local_7c;
  D3DXMatrixRotationZ();
  uStack_64 = 0;
  puStack_84 = auStack_58;
  uStack_60 = 0x3f800000;
  uStack_5c = 0;
  D3DXVec3TransformCoord(&uStack_64,&uStack_64);
  puStack_80 = *(undefined1 **)(in_ECX + 8);
  fVar3 = (float)puStack_80 * fStack_70;
  fVar4 = local_6c * (float)puStack_80;
  fVar2 = (float)puStack_80 * fStack_68;
  local_7c = fVar3;
  if (*(int *)(in_ECX + 4) != 0) {
    iVar1 = FUN_0089289d();
    puStack_80 = (undefined1 *)((float)iVar1 / 32767.0);
    fVar3 = (float)puStack_80 * local_7c;
    fVar4 = fVar4 * (float)puStack_80;
    fVar2 = (float)puStack_80 * fVar2;
    fStack_70 = fVar3;
    local_6c = fVar4;
    fStack_68 = fVar2;
  }
  *param_2 = fVar3;
  param_2[1] = fVar4;
  param_2[2] = fVar2;
  __security_check_cookie(uStack_20 ^ (uint)&puStack_84);
  return;
}


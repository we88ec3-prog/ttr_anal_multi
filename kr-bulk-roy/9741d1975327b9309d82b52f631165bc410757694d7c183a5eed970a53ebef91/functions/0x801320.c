
void FUN_00801320(void)

{
  uint *unaff_ESI;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (float)unaff_ESI[1];
  local_10 = (float)unaff_ESI[4];
  local_c = (float)unaff_ESI[7];
  local_20 = (float)unaff_ESI[2];
  local_1c = (float)unaff_ESI[5];
  local_18 = (float)unaff_ESI[8];
  D3DXVec3TransformCoord(&local_14,&local_14);
  D3DXVec3TransformCoord(&local_20,&local_20);
  unaff_ESI[1] = (uint)local_14;
  *unaff_ESI = (uint)((float)unaff_ESI[2] != local_14);
  unaff_ESI[4] = (uint)local_10;
  unaff_ESI[3] = (uint)((float)unaff_ESI[5] != local_10);
  unaff_ESI[7] = (uint)local_c;
  unaff_ESI[6] = (uint)((float)unaff_ESI[8] != local_c);
  unaff_ESI[2] = (uint)local_20;
  *unaff_ESI = (uint)((float)unaff_ESI[1] != local_20);
  unaff_ESI[5] = (uint)local_1c;
  unaff_ESI[3] = (uint)((float)unaff_ESI[4] != local_1c);
  unaff_ESI[8] = (uint)local_18;
  if ((float)unaff_ESI[7] != local_18) {
    unaff_ESI[6] = 1;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  unaff_ESI[6] = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


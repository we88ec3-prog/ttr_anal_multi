
void FUN_00775750(int param_1,int param_2,int param_3)

{
  float fVar1;
  int in_ECX;
  int iVar2;
  undefined4 unaff_ESI;
  float *pfVar3;
  int unaff_EDI;
  float10 fVar4;
  float local_84;
  float local_78;
  float local_74;
  float local_70;
  int local_6c;
  float local_68;
  float local_64;
  undefined4 local_60;
  float local_5c [3];
  undefined1 local_50 [56];
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_78;
  local_6c = in_ECX - param_1;
  local_68 = (float)local_6c;
  local_64 = (float)(param_3 - param_2);
  local_74 = local_68 * local_68 + local_64 * local_64 + 0.0;
  local_84 = 1.0959872e-38;
  fVar4 = (float10)FUN_008ff870();
  local_74 = (float)fVar4;
  local_68 = local_68 / local_74;
  local_64 = local_64 / local_74;
  local_78 = local_64 - local_68 * 0.0;
  local_70 = local_64 * 0.0 + local_68;
  if (1.0 <= local_70) {
    local_70 = 1.0;
  }
  else if (local_70 <= -1.0) {
    local_70 = -1.0;
  }
  if (0.0 <= local_78) {
    pfVar3 = local_5c;
    local_5c[0] = 0.0;
    local_5c[1] = 0.0;
    local_5c[2] = 1.0;
  }
  else {
    pfVar3 = &local_68;
    local_68 = 0.0;
    local_64 = 0.0;
    local_60 = 0xbf800000;
  }
  local_84 = 1.0960133e-38;
  fVar4 = (float10)FUN_008ff1d0();
  local_84 = (float)fVar4;
  local_78 = local_84;
  D3DXMatrixRotationAxis(local_50,pfVar3);
  fVar1 = *(float *)(unaff_EDI + 0x88) * 0.5;
  iVar2 = 4;
  *(float *)(unaff_EDI + 4) = 0.0;
  *(float *)(unaff_EDI + 8) = fVar1;
  *(undefined4 *)(unaff_EDI + 0xc) = 0;
  *(undefined4 *)(unaff_EDI + 0x20) = unaff_ESI;
  *(float *)(unaff_EDI + 0x24) = fVar1;
  *(undefined4 *)(unaff_EDI + 0x28) = 0;
  *(undefined4 *)(unaff_EDI + 0x3c) = 0;
  *(float *)(unaff_EDI + 0x40) = -fVar1;
  *(undefined4 *)(unaff_EDI + 0x44) = 0;
  *(undefined4 *)(unaff_EDI + 0x58) = unaff_ESI;
  *(float *)(unaff_EDI + 0x5c) = -fVar1;
  *(undefined4 *)(unaff_EDI + 0x60) = 0;
  local_84 = (float)param_1;
  pfVar3 = (float *)(unaff_EDI + 4);
  do {
    D3DXVec3TransformCoord(pfVar3,pfVar3,local_5c);
    iVar2 = iVar2 + -1;
    *pfVar3 = local_84 + *pfVar3;
    pfVar3[1] = (float)param_2 + pfVar3[1];
    pfVar3 = pfVar3 + 7;
  } while (iVar2 != 0);
  local_84 = (float)(int)(((uint)local_78 ^ (int)local_78 >> 0x1f) - ((int)local_78 >> 0x1f)) /
             *(float *)(unaff_EDI + 0x84);
  *(undefined4 *)(unaff_EDI + 0x18) = 0;
  *(undefined4 *)(unaff_EDI + 0x1c) = 0x3f800000;
  *(float *)(unaff_EDI + 0x34) = local_84;
  *(float *)(unaff_EDI + 0x6c) = local_84;
  *(undefined4 *)(unaff_EDI + 0x38) = 0x3f800000;
  *(undefined4 *)(unaff_EDI + 0x50) = 0;
  *(undefined4 *)(unaff_EDI + 0x54) = 0;
  *(undefined4 *)(unaff_EDI + 0x70) = 0;
  __security_check_cookie(uStack_18 ^ (uint)&local_84);
  return;
}


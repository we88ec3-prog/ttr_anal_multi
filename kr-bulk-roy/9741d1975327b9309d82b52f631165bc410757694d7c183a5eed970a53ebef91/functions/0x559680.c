
void FUN_00559680(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int *in_ECX;
  float fVar4;
  uint uVar5;
  int iVar6;
  float *unaff_ESI;
  float local_24;
  float local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_1c = in_ECX;
  if (unaff_ESI[0x2f] != 0.0) {
    if (((unaff_ESI[4] != 0.0) && (unaff_ESI[0xd] != 0.0)) && (unaff_ESI[0xb] != 0.0)) {
      (**(code **)(*(int *)unaff_ESI[4] + 0x28))
                (unaff_ESI + 5,0,0,0,0,(int)unaff_ESI[10] << 0x18 | 0xffffff);
    }
    if (((unaff_ESI[0xc] != 0.0) && (unaff_ESI[0xd] != 0.0)) && (unaff_ESI[0xb] != 0.0)) {
      iVar6 = (int)unaff_ESI[5];
      fVar1 = unaff_ESI[6];
      fVar4 = unaff_ESI[0xd];
      do {
        iVar6 = iVar6 + -0x4c;
        fVar2 = (float)((int)fVar4 / 10);
        local_24 = unaff_ESI[9];
        local_18 = (((int)fVar4 % 10) % 6) * 0x4c;
        local_14 = (((int)fVar4 % 10) / 6) * 0x48;
        local_c = local_14 + 0x48;
        local_10 = local_18 + 0x4c;
        local_20 = local_24;
        (**(code **)(*(int *)unaff_ESI[0xc] + 0x24))
                  (iVar6,(int)fVar1 + -6,&local_18,&local_24,0,0,
                   (int)unaff_ESI[10] << 0x18 | 0xffffff);
        fVar4 = fVar2;
        in_ECX = local_1c;
      } while (fVar2 != 0.0);
    }
    if ((unaff_ESI[0xe] != 0.0) && (unaff_ESI[0x15] != 0.0)) {
      local_24 = unaff_ESI[0x13];
      local_20 = local_24;
      (**(code **)(*(int *)unaff_ESI[0xe] + 0x28))
                (unaff_ESI + 0xf,0,&local_24,0,0,(int)unaff_ESI[0x14] << 0x18 | 0xffffff);
    }
    if ((unaff_ESI[0x1e] != 0.0) && (unaff_ESI[0x25] != 0.0)) {
      (**(code **)(*in_ECX + 0xe4))(in_ECX,0x13,2);
      (**(code **)(*in_ECX + 0xe4))(in_ECX,0x14,2);
      (**(code **)(*in_ECX + 0xe4))(in_ECX,0xab,1);
      if ((unaff_ESI[0x1e] != 0.0) && (unaff_ESI[0x25] != 0.0)) {
        uVar5 = (uint)unaff_ESI[0x26] & 0x80000001;
        if ((int)uVar5 < 0) {
          uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
        }
        local_1c = (int *)unaff_ESI[0x23];
        local_14 = ((int)unaff_ESI[0x26] / 2) * 0x80;
        local_24 = (float)local_1c * *unaff_ESI;
        local_c = local_14 + 0x80;
        local_20 = (float)local_1c * unaff_ESI[1];
        local_18 = uVar5 * 0x80;
        local_10 = local_18 + 0x80;
        (**(code **)(*(int *)unaff_ESI[0x1e] + 0x28))
                  (unaff_ESI + 0x1f,&local_18,&local_24,0,0,(int)unaff_ESI[0x24] << 0x18 | 0xffffff)
        ;
      }
      (**(code **)(*in_ECX + 0xe4))(in_ECX,0x13,5);
      (**(code **)(*in_ECX + 0xe4))(in_ECX,0x14,6);
      (**(code **)(*in_ECX + 0xe4))(in_ECX,0xab,1);
    }
    if ((unaff_ESI[0x16] != 0.0) && (unaff_ESI[0x1d] != 0.0)) {
      local_1c = (int *)unaff_ESI[3];
      local_24 = unaff_ESI[0x1b] * (float)(int)unaff_ESI[2] * 0.001953125;
      local_20 = unaff_ESI[0x1b] * (float)(int)local_1c * 0.001953125;
      (**(code **)(*(int *)unaff_ESI[0x16] + 0x24))
                ((int)unaff_ESI[2] / 2,(int)local_1c / 2,0,&local_24,1,0,
                 (int)unaff_ESI[0x1c] << 0x18 | 0xffffff);
    }
    if ((unaff_ESI[0x27] != 0.0) && (unaff_ESI[0x2e] != 0.0)) {
      fVar1 = unaff_ESI[2];
      local_24 = unaff_ESI[0x2c] * (float)(int)fVar1 * 0.001953125;
      local_20 = unaff_ESI[0x2c] * (float)(int)unaff_ESI[3] * 0.001953125;
      iVar6 = *(int *)unaff_ESI[0x27];
      local_1c = (int *)((int)unaff_ESI[3] / 2);
      uVar3 = FUN_008fed10(0,&local_24,1,0,(int)unaff_ESI[0x2d] << 0x18 | 0xffffff);
      local_1c = (int *)((int)fVar1 / 2);
      uVar3 = FUN_008fed10(uVar3);
      (**(code **)(iVar6 + 0x24))(uVar3);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


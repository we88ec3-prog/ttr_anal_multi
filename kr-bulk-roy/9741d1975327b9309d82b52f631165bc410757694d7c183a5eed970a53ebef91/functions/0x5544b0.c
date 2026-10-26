
void FUN_005544b0(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  float *unaff_ESI;
  float10 fVar6;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (unaff_ESI[2] == 0.0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (unaff_ESI[3] == 0.0) {
LAB_0055483b:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_0040f060();
  piVar3 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
  if (piVar3 == (int *)0x0) {
    unaff_ESI[3] = 0.0;
    goto LAB_0055483b;
  }
  local_10 = (float)piVar3[0x28];
  local_c = (float)piVar3[0x29];
  fVar1 = *unaff_ESI - local_10;
  fVar2 = unaff_ESI[1] - local_c;
  local_18 = fVar1 * fVar1 + fVar2 * fVar2;
  if (local_18 < 2500.0) {
    if (unaff_ESI[3] == 1.4013e-45) {
      unaff_ESI[4] = local_10;
      unaff_ESI[5] = local_c;
      unaff_ESI[3] = 2.8026e-45;
    }
    else {
      unaff_ESI[4] = unaff_ESI[4] + (*unaff_ESI - unaff_ESI[4]) * 0.04;
      unaff_ESI[5] = unaff_ESI[5] + (unaff_ESI[1] - unaff_ESI[5]) * 0.04;
    }
    local_10 = unaff_ESI[1];
    local_14 = *unaff_ESI;
    local_18 = 0.0;
    (**(code **)*DAT_00fba838)(unaff_ESI[4],unaff_ESI[5],&local_18,0);
    FUN_004c8eb0();
    FUN_007cda60(unaff_ESI[2]);
    goto LAB_005547b3;
  }
  if (unaff_ESI[3] == 2.8026e-45) {
    local_18 = 0.0;
    local_14 = unaff_ESI[4];
    local_10 = unaff_ESI[5];
    local_c = 0.0;
    (**(code **)*DAT_00fba838)(local_14,local_10,&local_c,0);
    unaff_ESI[3] = 4.2039e-45;
  }
  else {
    if (unaff_ESI[3] == 4.2039e-45) {
      local_10 = local_10 - unaff_ESI[4];
      local_c = local_c - unaff_ESI[5];
      local_18 = local_10 * local_10 + local_c * local_c;
      if (10.0 <= local_18) {
        local_18 = 0.0;
        fVar1 = local_c * 0.2;
        unaff_ESI[4] = unaff_ESI[4] + local_10 * 0.2;
        local_c = 0.0;
        unaff_ESI[5] = unaff_ESI[5] + fVar1;
        local_14 = unaff_ESI[4];
        local_10 = unaff_ESI[5];
        (**(code **)*DAT_00fba838)(local_14,local_10,&local_c,0);
        goto LAB_00554775;
      }
    }
    pfVar4 = (float *)(**(code **)(*piVar3 + 0x4c))();
    local_14 = *pfVar4;
    local_10 = pfVar4[1];
    local_c = pfVar4[2];
    unaff_ESI[3] = 1.4013e-45;
  }
LAB_00554775:
  fVar6 = (float10)FUN_004c8eb0();
  local_c = (float)(fVar6 + (float10)5.0 + (float10)local_c);
  FUN_007cd970(unaff_ESI[2]);
LAB_005547b3:
  FUN_007cd8a0();
  local_18 = (float)piVar3[0x2d];
  iVar5 = FUN_00444ad0();
  fVar1 = unaff_ESI[2];
  local_18 = *(float *)(iVar5 + 0x6c) * local_18;
  *(float *)((int)fVar1 + 0x54) = local_18;
  *(float *)((int)fVar1 + 0x58) = local_18;
  *(float *)((int)fVar1 + 0x5c) = local_18;
  iVar5 = *(int *)((int)fVar1 + 0x20);
  *(float *)(iVar5 + 0x84) = local_18;
  *(float *)(iVar5 + 0x88) = local_18;
  *(float *)(iVar5 + 0x8c) = local_18;
  *(undefined4 *)(iVar5 + 0xc0) = 0;
  FUN_007cd830(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


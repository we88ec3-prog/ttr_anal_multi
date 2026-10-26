
void FUN_008720b0(undefined4 param_1)

{
  float extraout_EDX;
  float extraout_EDX_00;
  float fVar1;
  float *unaff_ESI;
  int *unaff_EDI;
  float *pfVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 local_48 [12];
  int local_3c;
  undefined4 local_34;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_ESI = 0.0;
  unaff_ESI[1] = 0.0;
  puVar4 = local_48;
  unaff_ESI[2] = 0.0;
  unaff_ESI[3] = 0.0;
  uVar3 = param_1;
  (**(code **)(*unaff_EDI + 0x10))();
  if (local_3c == 1) {
    local_1c = 0.0;
    (**(code **)(*unaff_EDI + 0x5c))();
    if (local_1c == 0.0) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = 1.0;
    }
    *unaff_ESI = fVar1;
    unaff_ESI[1] = fVar1;
    unaff_ESI[2] = fVar1;
    unaff_ESI[3] = fVar1;
    local_1c = fVar1;
    local_18 = fVar1;
    local_14 = fVar1;
    local_10 = fVar1;
    local_c = fVar1;
  }
  else {
    if (local_3c == 2) {
      pfVar2 = &local_1c;
      local_1c = 0.0;
      (**(code **)(*unaff_EDI + 0x6c))();
      local_1c = (float)(int)local_1c;
      *unaff_ESI = local_1c;
      unaff_ESI[1] = local_1c;
      unaff_ESI[2] = local_1c;
      unaff_ESI[3] = local_1c;
      local_18 = local_1c;
      local_14 = local_1c;
      local_10 = local_1c;
      local_c = local_1c;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,local_1c,param_1,pfVar2);
      return;
    }
    fVar1 = extraout_EDX;
    if (local_3c == 3) {
      (**(code **)(*unaff_EDI + 0x84))();
      fVar1 = extraout_EDX_00;
      switch(local_34) {
      case 1:
        unaff_ESI[3] = local_18;
        unaff_ESI[2] = local_18;
        unaff_ESI[1] = local_18;
        *unaff_ESI = local_18;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_00,uVar3,puVar4);
        return;
      case 2:
        *unaff_ESI = local_18;
        unaff_ESI[1] = local_14;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_00,uVar3,puVar4);
        return;
      case 3:
        *unaff_ESI = local_18;
        unaff_ESI[1] = local_14;
        unaff_ESI[2] = local_10;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_00,uVar3,puVar4);
        return;
      case 4:
        *unaff_ESI = local_18;
        unaff_ESI[1] = local_14;
        unaff_ESI[2] = local_10;
        unaff_ESI[3] = local_c;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_00,uVar3,puVar4);
        return;
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,fVar1,uVar3,puVar4);
  return;
}


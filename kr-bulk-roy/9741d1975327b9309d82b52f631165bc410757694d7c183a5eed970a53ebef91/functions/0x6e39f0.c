
void FUN_006e39f0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 uVar4;
  undefined4 extraout_ECX_00;
  undefined4 *unaff_ESI;
  undefined8 uVar5;
  undefined1 local_18 [12];
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)FUN_006dfb80();
  _memset(unaff_ESI,0,0x48);
  if (*param_2 == 0) {
    *unaff_ESI = 0;
  }
  else {
    *unaff_ESI = *param_1;
  }
  if (param_2[1] == 0) {
    unaff_ESI[1] = 1;
  }
  else {
    unaff_ESI[1] = param_1[1];
  }
  if (param_2[2] == 0) {
    unaff_ESI[0xc] = 1;
  }
  else {
    unaff_ESI[0xc] = param_1[0xc];
  }
  if (param_2[3] == 0) {
    (**(code **)(*piVar1 + 0x20))(piVar1,*unaff_ESI,local_18);
    if ((unaff_ESI[0xc] == 0) && (uVar2 = FUN_006ec900(), local_c = extraout_ECX, uVar2 < 8)) {
      unaff_ESI[2] = 0x16;
    }
    else {
      unaff_ESI[2] = local_c;
    }
  }
  else {
    unaff_ESI[2] = param_1[2];
  }
  if (param_2[4] == 0) {
    unaff_ESI[3] = unaff_ESI[3] & 0xffffffcf | 0x40;
  }
  else {
    unaff_ESI[3] = param_1[3];
  }
  if (param_2[5] == 0) {
    if (unaff_ESI[0xc] != 0) {
      unaff_ESI[4] = 0x400;
      unaff_ESI[5] = 0x300;
      goto LAB_006e3b47;
    }
LAB_006e3ae2:
    if (DAT_00fba7cc == 0) {
      iVar3 = FUN_00891268(0x1380);
      if (iVar3 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    uVar4 = FUN_006e1260(DAT_00fba7cc);
    unaff_ESI[4] = uVar4;
    if (DAT_00fba7cc == 0) {
      iVar3 = FUN_00891268(0x1380);
      if (iVar3 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    uVar4 = FUN_006e12a0(DAT_00fba7cc);
  }
  else {
    if (unaff_ESI[0xc] == 0) goto LAB_006e3ae2;
    unaff_ESI[4] = param_1[4];
    uVar4 = param_1[5];
  }
  unaff_ESI[5] = uVar4;
LAB_006e3b47:
  if (param_2[6] == 0) {
    unaff_ESI[6] = unaff_ESI[2];
  }
  else {
    unaff_ESI[6] = param_1[6];
  }
  uVar4 = 2;
  if (param_2[7] == 0) {
    unaff_ESI[7] = 2;
  }
  else {
    unaff_ESI[7] = param_1[7];
  }
  if (param_2[8] == 0) {
    unaff_ESI[8] = 0;
    unaff_ESI[9] = 0;
  }
  else {
    unaff_ESI[8] = param_1[8];
    unaff_ESI[9] = param_1[9];
  }
  if (param_2[9] == 0) {
    unaff_ESI[10] = 1;
  }
  else {
    unaff_ESI[10] = param_1[10];
  }
  if ((param_2[10] == 0) && (param_2[0xb] == 0)) {
    uVar5 = FUN_006ec900();
    param_1 = (undefined4 *)((ulonglong)uVar5 >> 0x20);
    iVar3 = (-(uint)((uint)uVar5 < 8) & 9) + 0x47;
    uVar4 = extraout_ECX_00;
  }
  else {
    iVar3 = param_1[0xe];
  }
  unaff_ESI[0xe] = iVar3;
  if (param_2[0xc] != 0) {
    uVar4 = param_1[0xf];
  }
  unaff_ESI[0xf] = uVar4;
  if (param_2[0xd] == 0) {
    unaff_ESI[0x10] = 0;
  }
  else {
    unaff_ESI[0x10] = param_1[0x10];
  }
  if (param_2[0xe] != 0) {
    unaff_ESI[0x11] = param_1[0x11];
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  unaff_ESI[0x11] = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


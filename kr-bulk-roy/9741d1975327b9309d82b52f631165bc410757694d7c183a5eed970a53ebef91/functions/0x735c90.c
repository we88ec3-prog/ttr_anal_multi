
void FUN_00735c90(int *param_1,short *param_2,undefined4 param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint in_ECX;
  short *psVar4;
  uint uVar5;
  int *in_EDX;
  undefined4 *unaff_EDI;
  float local_80;
  float local_7c;
  int local_78;
  uint local_74;
  short *local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c [4];
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_74 = in_ECX;
  if (param_2 == (short *)0x0) goto LAB_00735eb0;
  local_70 = param_2 + 1;
  psVar4 = param_2;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  if ((int)psVar4 - (int)local_70 >> 1 == 0) goto LAB_00735eb0;
  local_78 = *in_EDX;
  local_70 = (short *)in_EDX[1];
  iVar2 = FUN_00735620(unaff_EDI,unaff_EDI[8],param_2,in_ECX);
  if (iVar2 == 0) goto LAB_00735eb0;
  local_2c = *(int *)(iVar2 + 0x24);
  local_28 = *(int *)(iVar2 + 0x28);
  local_24 = *(int *)(iVar2 + 0x2c);
  local_20 = *(int *)(iVar2 + 0x30);
  if (param_1 != (int *)0x0) {
    if (*in_EDX < *param_1) {
      local_2c = local_2c + (*param_1 - *in_EDX);
    }
    if (in_EDX[1] < param_1[1]) {
      local_28 = local_28 + (param_1[1] - in_EDX[1]);
    }
    if (param_1[2] < in_EDX[2]) {
      local_24 = local_24 + (param_1[2] - in_EDX[2]);
    }
    if (param_1[3] < in_EDX[3]) {
      local_20 = local_20 + (param_1[3] - in_EDX[3]);
    }
  }
  if ((local_74 & 1) == 0) {
    if ((local_74 & 2) != 0) {
      iVar3 = ((in_EDX[2] - *(int *)(iVar2 + 0x2c)) - *in_EDX) + *(int *)(iVar2 + 0x24);
      goto LAB_00735d7a;
    }
  }
  else {
    iVar3 = (((in_EDX[2] - *(int *)(iVar2 + 0x2c)) - *in_EDX) + *(int *)(iVar2 + 0x24)) / 2;
LAB_00735d7a:
    local_78 = local_78 + iVar3;
  }
  if ((local_74 & 4) == 0) {
    if ((local_74 & 8) != 0) {
      local_70 = (short *)((int)local_70 +
                          (((in_EDX[3] - *(int *)(iVar2 + 0x30)) + *(int *)(iVar2 + 0x28)) -
                          in_EDX[1]));
    }
  }
  else {
    local_70 = (short *)((int)local_70 +
                        (((in_EDX[3] - *(int *)(iVar2 + 0x30)) + *(int *)(iVar2 + 0x28)) - in_EDX[1]
                        ) / 2);
  }
  local_c = param_3;
  local_1c[0] = param_4;
  local_1c[1] = param_4;
  local_1c[2] = param_4;
  local_1c[3] = param_4;
  uVar5 = 4;
  if (((local_74 & 0x100) != 0) && (param_4 != 0)) {
    uVar5 = 0;
  }
  if (uVar5 < 5) {
    iVar2 = uVar5 * 4;
    do {
      local_74 = *(int *)((int)&DAT_00f88a08 + iVar2) + (int)local_70;
      local_80 = (float)(*(int *)((int)&DAT_00f889f4 + iVar2) + local_78);
      local_7c = (float)(int)local_74;
      D3DXMatrixTransformation2D(&local_6c,0,0,0,0,0,&local_80);
      (**(code **)(*(int *)*unaff_EDI + 0x14))((int *)*unaff_EDI,&local_6c);
      iVar3 = (**(code **)(*(int *)*unaff_EDI + 0x24))
                        ((int *)*unaff_EDI,unaff_EDI[1],&local_2c,0,0,
                         *(undefined4 *)((int)local_1c + iVar2));
      if (iVar3 < 0) {
        unaff_EDI[0x15] = 0;
      }
      local_34 = 0;
      local_38 = 0;
      local_3c = 0;
      local_40 = 0;
      local_48 = 0;
      local_4c = 0;
      local_50 = 0;
      local_54 = 0;
      local_5c = 0;
      local_60 = 0;
      local_64 = 0;
      local_68 = 0;
      local_30 = 0x3f800000;
      local_44 = 0x3f800000;
      local_58 = 0x3f800000;
      local_6c = 0x3f800000;
      (**(code **)(*(int *)*unaff_EDI + 0x14))((int *)*unaff_EDI,&local_6c);
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x14);
  }
LAB_00735eb0:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


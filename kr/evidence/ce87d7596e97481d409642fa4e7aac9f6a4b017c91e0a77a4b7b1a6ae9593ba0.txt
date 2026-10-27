
void FUN_00838430(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  undefined1 local_e4 [16];
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 local_b0 [64];
  undefined4 local_70;
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
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_70 = 0xbf800000;
  local_6c = 0xbf800000;
  local_68 = 0;
  local_64 = 0x3f800000;
  local_58 = 0x3f800000;
  local_50 = 0x3f800000;
  local_44 = 0x3f800000;
  local_3c = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  local_28 = 0x3f800000;
  local_24 = 0x3f800000;
  local_20 = 0x3f800000;
  local_18 = 0x3f800000;
  local_14 = 0x3f800000;
  local_60 = 0xbf800000;
  local_54 = 0xbf800000;
  local_4c = 0xbf800000;
  local_48 = 0xbf800000;
  local_40 = 0xbf800000;
  local_1c = 0xbf800000;
  local_5c = 0;
  local_38 = 0;
  local_2c = 0;
  D3DXMatrixInverse(local_b0,0,param_1);
  puVar1 = &local_70;
  iVar2 = 8;
  do {
    D3DXVec3TransformCoord(puVar1,puVar1,local_b0);
    puVar1 = puVar1 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_d4 = local_28;
  local_d0 = local_24;
  local_cc = local_20;
  local_c8 = local_34;
  local_c4 = local_30;
  local_c0 = local_2c;
  local_bc = local_40;
  local_b8 = local_3c;
  local_b4 = local_38;
  puVar1 = (undefined4 *)FUN_00862c00(local_e4);
  local_bc = local_58;
  unaff_ESI[0xc] = *puVar1;
  local_b8 = local_54;
  unaff_ESI[0xd] = puVar1[1];
  local_b4 = local_50;
  unaff_ESI[0xe] = puVar1[2];
  local_c8 = local_4c;
  local_c4 = local_48;
  local_c0 = local_44;
  unaff_ESI[0xf] = puVar1[3];
  local_d4 = local_70;
  local_d0 = local_6c;
  local_cc = local_68;
  puVar1 = (undefined4 *)FUN_00862c00(local_e4);
  local_bc = local_34;
  unaff_ESI[0x10] = *puVar1;
  local_b8 = local_30;
  unaff_ESI[0x11] = puVar1[1];
  local_b4 = local_2c;
  unaff_ESI[0x12] = puVar1[2];
  local_c8 = local_64;
  unaff_ESI[0x13] = puVar1[3];
  local_c4 = local_60;
  local_c0 = local_5c;
  local_d4 = local_70;
  local_d0 = local_6c;
  local_cc = local_68;
  puVar1 = (undefined4 *)FUN_00862c00(local_e4);
  local_bc = local_1c;
  unaff_ESI[0x14] = *puVar1;
  local_b8 = local_18;
  unaff_ESI[0x15] = puVar1[1];
  local_b4 = local_14;
  unaff_ESI[0x16] = puVar1[2];
  local_c8 = local_4c;
  local_c4 = local_48;
  local_c0 = local_44;
  local_d4 = local_58;
  unaff_ESI[0x17] = puVar1[3];
  local_d0 = local_54;
  local_cc = local_50;
  puVar1 = (undefined4 *)FUN_00862c00(local_e4);
  local_bc = local_1c;
  unaff_ESI[8] = *puVar1;
  local_b8 = local_18;
  unaff_ESI[9] = puVar1[1];
  local_b4 = local_14;
  unaff_ESI[10] = puVar1[2];
  local_c8 = local_40;
  local_c4 = local_3c;
  local_c0 = local_38;
  unaff_ESI[0xb] = puVar1[3];
  local_d4 = local_70;
  local_d0 = local_6c;
  local_cc = local_68;
  puVar1 = (undefined4 *)FUN_00862c00(local_e4);
  unaff_ESI[4] = *puVar1;
  local_bc = local_28;
  unaff_ESI[5] = puVar1[1];
  unaff_ESI[6] = puVar1[2];
  unaff_ESI[7] = puVar1[3];
  local_b8 = local_24;
  local_b4 = local_20;
  local_c8 = local_58;
  local_c4 = local_54;
  local_c0 = local_50;
  local_d4 = local_64;
  local_d0 = local_60;
  local_cc = local_5c;
  puVar1 = (undefined4 *)FUN_00862c00(local_e4);
  *unaff_ESI = *puVar1;
  unaff_ESI[1] = puVar1[1];
  unaff_ESI[2] = puVar1[2];
  unaff_ESI[3] = puVar1[3];
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}


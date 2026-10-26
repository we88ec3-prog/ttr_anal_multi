
void FUN_007d8a50(undefined4 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 **ppuVar3;
  undefined4 *puVar4;
  undefined1 **ppuStack_2e8;
  undefined1 *puStack_2e4;
  undefined1 *puStack_2e0;
  undefined1 *puStack_2dc;
  undefined4 uStack_2d8;
  undefined4 uStack_2d4;
  undefined1 **ppuStack_2d0;
  undefined4 uStack_2cc;
  undefined1 **ppuStack_2c8;
  undefined4 *puStack_2c4;
  undefined1 **ppuStack_2c0;
  undefined1 *puStack_2bc;
  undefined1 *puStack_2b8;
  undefined1 *puStack_2b4;
  undefined1 *puStack_2b0;
  undefined1 *puStack_2ac;
  undefined1 *puStack_2a8;
  undefined4 uStack_2a4;
  undefined1 *apuStack_2a0 [7];
  undefined4 uStack_284;
  undefined1 *puStack_280;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  undefined1 auStack_264 [16];
  undefined1 auStack_254 [12];
  undefined1 auStack_248 [12];
  undefined1 auStack_23c [28];
  undefined4 auStack_220 [19];
  undefined1 auStack_1d4 [20];
  undefined1 auStack_1c0 [4];
  undefined1 auStack_1bc [108];
  undefined1 local_150 [8];
  undefined1 auStack_148 [24];
  undefined1 auStack_130 [80];
  undefined1 auStack_e0 [24];
  undefined1 auStack_c8 [16];
  undefined1 auStack_b8 [16];
  undefined1 auStack_a8 [24];
  uint uStack_90;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_264;
  local_274 = param_1[6];
  puStack_280 = local_150;
  local_278 = param_1[6];
  local_27c = param_1[6];
  uStack_284 = 0x7d8a95;
  D3DXMatrixScaling();
  uStack_284 = param_1[2];
  apuStack_2a0[4] = auStack_e0;
  apuStack_2a0[6] = (undefined1 *)param_1[1];
  apuStack_2a0[5] = (undefined1 *)*param_1;
  apuStack_2a0[3] = (undefined1 *)0x7d8ab9;
  D3DXMatrixTranslation();
  apuStack_2a0[3] = (undefined1 *)param_1[3];
  apuStack_2a0[2] = auStack_130;
  apuStack_2a0[1] = (undefined1 *)0x7d8ace;
  D3DXMatrixRotationX();
  apuStack_2a0[1] = (undefined1 *)param_1[4];
  apuStack_2a0[0] = auStack_b8;
  uStack_2a4 = 0x7d8ae3;
  D3DXMatrixRotationY();
  uStack_2a4 = param_1[5];
  puStack_2a8 = auStack_1c0;
  puStack_2ac = (undefined1 *)0x7d8af8;
  D3DXMatrixRotationZ();
  puStack_2ac = auStack_c8;
  puStack_2b0 = auStack_148;
  puStack_2b4 = auStack_248;
  puStack_2b8 = (undefined1 *)0x7d8b15;
  D3DXMatrixMultiply();
  puStack_2b8 = auStack_1d4;
  puStack_2bc = auStack_254;
  ppuStack_2c0 = apuStack_2a0 + 3;
  puStack_2c4 = (undefined4 *)0x7d8b29;
  D3DXMatrixMultiply();
  puStack_2c4 = auStack_220;
  ppuStack_2c8 = &puStack_2b4;
  ppuVar3 = apuStack_2a0;
  puVar4 = auStack_220;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *ppuVar3;
    ppuVar3 = ppuVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  uStack_2cc = 0x7d8b4e;
  D3DXQuaternionRotationMatrix();
  puVar1 = puStack_2b4;
  uStack_2cc = 0;
  ppuStack_2d0 = &puStack_2bc;
  puStack_2ac = puStack_2b4;
  uStack_2d4 = 0;
  puStack_2b4 = puStack_2b8;
  puStack_2b8 = puVar1;
  puStack_2b0 = (undefined1 *)-(float)puStack_2b0;
  puStack_2dc = auStack_a8;
  uStack_2d8 = 0x3f800000;
  puStack_2e0 = (undefined1 *)0x7d8b8d;
  D3DXMatrixAffineTransformation();
  puStack_2e0 = auStack_23c;
  puStack_2e4 = auStack_1bc;
  ppuStack_2e8 = &puStack_2bc;
  D3DXMatrixMultiply();
  D3DXMatrixMultiply(apuStack_2a0 + 6,&ppuStack_2c8,auStack_148);
  ppuVar3 = apuStack_2a0 + 3;
  puVar4 = param_1 + 7;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *ppuVar3;
    ppuVar3 = ppuVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  __security_check_cookie(uStack_90 ^ (uint)&ppuStack_2e8);
  return;
}


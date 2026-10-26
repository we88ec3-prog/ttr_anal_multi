
void FUN_007f2800(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 **ppuStack_198;
  undefined1 *puStack_194;
  undefined1 *puStack_190;
  undefined1 *puStack_18c;
  undefined1 *puStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 *puStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined1 *puStack_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined1 auStack_150 [16];
  undefined1 auStack_140 [16];
  undefined1 auStack_130 [36];
  undefined1 auStack_10c [12];
  undefined1 auStack_100 [64];
  undefined1 auStack_c0 [40];
  undefined4 auStack_98 [2];
  undefined1 local_90 [4];
  undefined1 auStack_8c [56];
  uint uStack_54;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_150;
  local_15c = *(undefined4 *)(in_ECX + 0x38);
  puStack_168 = local_90;
  local_160 = *(undefined4 *)(in_ECX + 0x38);
  local_164 = *(undefined4 *)(in_ECX + 0x38);
  uStack_16c = 0x7f2843;
  D3DXMatrixScaling();
  uStack_16c = *(undefined4 *)(in_ECX + 0x28);
  puStack_178 = &local_160;
  uStack_170 = *(undefined4 *)(in_ECX + 0x24);
  uStack_174 = *(undefined4 *)(in_ECX + 0x20);
  uStack_17c = 0x7f2865;
  D3DXMatrixTranslation();
  uStack_17c = *(undefined4 *)(in_ECX + 0x34);
  puStack_188 = auStack_130;
  uStack_180 = *(undefined4 *)(in_ECX + 0x2c);
  uStack_184 = *(undefined4 *)(in_ECX + 0x30);
  puStack_18c = (undefined1 *)0x7f2887;
  D3DXMatrixRotationYawPitchRoll();
  puStack_18c = auStack_140;
  puStack_190 = auStack_c0;
  puStack_194 = auStack_100;
  ppuStack_198 = (undefined1 **)0x7f28a4;
  D3DXMatrixMultiply();
  ppuStack_198 = &puStack_18c;
  D3DXMatrixMultiply(auStack_8c,auStack_10c);
  puVar2 = auStack_98;
  puVar3 = (undefined4 *)(in_ECX + 0x3c);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  __security_check_cookie(uStack_54 ^ (uint)&ppuStack_198);
  return;
}


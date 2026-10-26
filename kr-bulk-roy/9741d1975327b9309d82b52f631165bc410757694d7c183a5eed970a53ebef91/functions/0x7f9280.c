
void FUN_007f9280(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_150 [16];
  undefined1 local_110 [64];
  undefined1 local_d0 [64];
  undefined1 local_90 [64];
  undefined1 local_50 [68];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  D3DXMatrixScaling(local_110,*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x3c),
                    *(undefined4 *)(param_1 + 0x3c));
  D3DXMatrixTranslation
            (local_50,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
             *(undefined4 *)(param_1 + 0x2c));
  D3DXMatrixRotationYawPitchRoll
            (local_90,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x30),
             *(undefined4 *)(param_1 + 0x38));
  D3DXMatrixMultiply(local_d0,local_110,local_90);
  D3DXMatrixMultiply(local_150,local_d0,local_50);
  puVar2 = local_150;
  puVar3 = (undefined4 *)(param_1 + 0x40);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  D3DXMatrixInverse(param_1 + 0x80,0,(undefined4 *)(param_1 + 0x40));
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}



void FUN_00733ea0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *in_ECX;
  uint uVar6;
  int local_8c;
  byte local_88 [128];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_88[0] = 0xc;
  local_88[1] = 0x30;
  local_88[2] = 0x37;
  local_88[3] = 0x13;
  local_88[4] = 0x2a;
  local_88[5] = 0xf;
  local_88[6] = 0x41;
  local_88[7] = 0x25;
  local_88[8] = 0x37;
  local_88[9] = 0x20;
  local_88[10] = 0x36;
  local_88[0xb] = 0x39;
  local_88[0xc] = 0x40;
  local_88[0xd] = 0x30;
  local_88[0xe] = 0x4e;
  local_88[0xf] = 0x40;
  local_88[0x10] = 0x52;
  local_88[0x11] = 0x41;
  local_88[0x12] = 0x25;
  local_88[0x13] = 0x40;
  local_88[0x14] = 0xb;
  local_88[0x15] = 0x16;
  local_88[0x16] = 0x5b;
  local_88[0x17] = 0x30;
  local_88[0x18] = 0x35;
  local_88[0x19] = 0x4e;
  local_88[0x1a] = 0x5e;
  local_88[0x1b] = 0xf;
  local_88[0x1c] = 0x4b;
  local_88[0x1d] = 0x3a;
  local_88[0x1e] = 0x42;
  local_88[0x1f] = 0xc;
  uVar6 = 0x20;
  do {
    uVar5 = uVar6 & 0x8000001f;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xffffffe0) + 1;
    }
    local_88[uVar6] = local_88[uVar5] * (char)uVar6;
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 0x80);
  iVar1 = -(int)in_ECX;
  iVar2 = 1 - (int)in_ECX;
  iVar3 = 2 - (int)in_ECX;
  iVar4 = 3 - (int)in_ECX;
  local_8c = 0x20;
  do {
    *in_ECX = *in_ECX ^ in_ECX[(int)(local_88 + iVar1)];
    in_ECX[1] = in_ECX[1] ^ in_ECX[(int)(local_88 + iVar2)];
    in_ECX[2] = in_ECX[2] ^ in_ECX[(int)(local_88 + iVar3)];
    in_ECX[3] = in_ECX[3] ^ in_ECX[(int)(local_88 + iVar4)];
    in_ECX = in_ECX + 4;
    local_8c = local_8c + -1;
  } while (local_8c != 0);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


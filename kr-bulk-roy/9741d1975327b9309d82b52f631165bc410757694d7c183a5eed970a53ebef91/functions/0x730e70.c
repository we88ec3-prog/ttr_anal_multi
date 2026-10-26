
void FUN_00730e70(int param_1)

{
  byte *pbVar1;
  uint in_ECX;
  int *unaff_ESI;
  byte local_24 [28];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[2] = 0;
  local_24[3] = 0;
  local_24[4] = 0;
  local_24[5] = 0;
  local_24[6] = 0;
  local_24[7] = 0;
  local_24[8] = 0xc0;
  local_24[9] = 0;
  local_24[10] = 0;
  local_24[0xb] = 0;
  local_24[0xc] = 0xe0;
  local_24[0xd] = 0;
  local_24[0xe] = 0;
  local_24[0xf] = 0;
  local_24[0x10] = 0xf0;
  local_24[0x11] = 0;
  local_24[0x12] = 0;
  local_24[0x13] = 0;
  local_24[0x14] = 0xf8;
  local_24[0x15] = 0;
  local_24[0x16] = 0;
  local_24[0x17] = 0;
  local_24[0x18] = 0xfc;
  local_24[0x19] = 0;
  local_24[0x1a] = 0;
  local_24[0x1b] = 0;
  if (in_ECX < 0x80) {
    *unaff_ESI = 1;
  }
  else if (in_ECX < 0x800) {
    *unaff_ESI = 2;
  }
  else if (in_ECX < 0x10000) {
    *unaff_ESI = 3;
  }
  else {
    if (0x1fffff < in_ECX) {
      *unaff_ESI = 0;
      goto switchD_00730ef6_default;
    }
    *unaff_ESI = 4;
  }
  pbVar1 = (byte *)(param_1 + *unaff_ESI);
  switch(*unaff_ESI) {
  case 4:
    pbVar1 = pbVar1 + -1;
    *pbVar1 = (byte)in_ECX & 0x3f | 0x80;
    in_ECX = in_ECX >> 6;
  case 3:
    pbVar1 = pbVar1 + -1;
    *pbVar1 = (byte)in_ECX & 0x3f | 0x80;
    in_ECX = in_ECX >> 6;
  case 2:
    pbVar1 = pbVar1 + -1;
    *pbVar1 = (byte)in_ECX & 0x3f | 0x80;
    in_ECX = in_ECX >> 6;
  case 1:
    pbVar1[-1] = local_24[*unaff_ESI * 4] | (byte)in_ECX;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
switchD_00730ef6_default:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


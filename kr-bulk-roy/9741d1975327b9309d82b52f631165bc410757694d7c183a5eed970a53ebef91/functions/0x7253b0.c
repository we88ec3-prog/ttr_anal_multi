
void FUN_007253b0(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  byte *in_EAX;
  byte bVar3;
  int in_ECX;
  uint uVar4;
  
  puVar1 = param_1 + in_ECX;
  for (; param_1 < puVar1; param_1 = param_1 + 1) {
    uVar2 = *param_1;
    uVar4 = (uVar2 & 0xff0000 | uVar2 >> 0x10) >> 8 | (uVar2 & 0xff00 | uVar2 << 0x10) << 8;
    bVar3 = (byte)(uVar2 >> 0x18);
    if (uVar4 < 0x10000) {
      if (uVar4 < 0x80) {
        *in_EAX = bVar3;
        in_EAX = in_EAX + 1;
      }
      else if (uVar4 < 0x800) {
        *in_EAX = (byte)(uVar4 >> 6) | 0xc0;
        in_EAX[1] = bVar3 & 0x3f | 0x80;
        in_EAX = in_EAX + 2;
      }
      else {
        *in_EAX = (byte)(uVar4 >> 0xc) | 0xe0;
        in_EAX[1] = (byte)(uVar4 >> 6) & 0x3f | 0x80;
        in_EAX[2] = bVar3 & 0x3f | 0x80;
        in_EAX = in_EAX + 3;
      }
    }
    else {
      *in_EAX = (byte)((uVar2 & 0xff00 | uVar2 << 0x10 & 0xffffff) >> 10) | 0xf0;
      in_EAX[1] = (byte)(uVar4 >> 0xc) & 0x3f | 0x80;
      in_EAX[2] = (byte)(uVar4 >> 6) & 0x3f | 0x80;
      in_EAX[3] = bVar3 & 0x3f | 0x80;
      in_EAX = in_EAX + 4;
    }
  }
  return;
}


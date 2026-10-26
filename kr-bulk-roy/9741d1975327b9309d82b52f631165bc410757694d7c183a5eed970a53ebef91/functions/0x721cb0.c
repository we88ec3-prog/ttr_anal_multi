
void FUN_00721cb0(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  byte *in_EAX;
  byte bVar3;
  int in_ECX;
  
  puVar1 = param_1 + in_ECX;
  for (; param_1 < puVar1; param_1 = param_1 + 1) {
    uVar2 = *param_1;
    bVar3 = (byte)uVar2;
    if (uVar2 < 0x10000) {
      if (uVar2 < 0x80) {
        *in_EAX = bVar3;
        in_EAX = in_EAX + 1;
      }
      else if (uVar2 < 0x800) {
        *in_EAX = (byte)(uVar2 >> 6) | 0xc0;
        in_EAX[1] = bVar3 & 0x3f | 0x80;
        in_EAX = in_EAX + 2;
      }
      else {
        *in_EAX = (byte)(uVar2 >> 0xc) | 0xe0;
        in_EAX[1] = (byte)(uVar2 >> 6) & 0x3f | 0x80;
        in_EAX[2] = bVar3 & 0x3f | 0x80;
        in_EAX = in_EAX + 3;
      }
    }
    else {
      *in_EAX = (byte)(uVar2 >> 0x12) | 0xf0;
      in_EAX[1] = (byte)(uVar2 >> 0xc) & 0x3f | 0x80;
      in_EAX[2] = (byte)(uVar2 >> 6) & 0x3f | 0x80;
      in_EAX[3] = bVar3 & 0x3f | 0x80;
      in_EAX = in_EAX + 4;
    }
  }
  return;
}


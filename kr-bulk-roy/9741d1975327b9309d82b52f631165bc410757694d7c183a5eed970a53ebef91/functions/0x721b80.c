
void FUN_00721b80(ushort *param_1)

{
  ushort *puVar1;
  ushort uVar2;
  byte *in_EAX;
  byte bVar3;
  int in_ECX;
  uint uVar4;
  ushort *puVar5;
  
  puVar1 = param_1 + in_ECX;
  if (param_1 < puVar1) {
    puVar5 = param_1 + 1;
    do {
      uVar2 = *param_1;
      uVar4 = (uint)uVar2;
      bVar3 = (byte)uVar2;
      if (uVar2 < 0xd800) {
        if (uVar4 < 0x80) {
          *in_EAX = bVar3;
          in_EAX = in_EAX + 1;
        }
        else {
LAB_00721bbd:
          if (uVar4 < 0x800) {
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
LAB_00721c99:
        param_1 = param_1 + 1;
        puVar5 = puVar5 + 1;
      }
      else {
        if (uVar4 - 0xe000 < 0x2000) {
          if (0x7f < uVar4) goto LAB_00721bbd;
          *in_EAX = bVar3;
          in_EAX = in_EAX + 1;
          goto LAB_00721c99;
        }
        if (((0x3ff < uVar4 - 0xd800) || (puVar1 <= puVar5)) || (0x3ff < *puVar5 - 0xdc00))
        goto LAB_00721c99;
        uVar4 = ((uVar4 & 0x3ff) + 0x40) * 0x400 + (*puVar5 & 0x3ff);
        *in_EAX = (byte)(uVar4 >> 0x12) | 0xf0;
        in_EAX[1] = (byte)(uVar4 >> 0xc) & 0x3f | 0x80;
        in_EAX[2] = (byte)(uVar4 >> 6) & 0x3f | 0x80;
        in_EAX[3] = (byte)uVar4 & 0x3f | 0x80;
        in_EAX = in_EAX + 4;
        param_1 = param_1 + 2;
        puVar5 = puVar5 + 2;
      }
    } while (param_1 < puVar1);
  }
  return;
}


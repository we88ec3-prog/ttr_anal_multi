
void FUN_00725270(ushort *param_1)

{
  ushort *puVar1;
  ushort uVar2;
  byte *in_EAX;
  byte bVar3;
  ushort uVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  
  puVar1 = param_1 + in_ECX;
  if (param_1 < puVar1) {
    puVar7 = param_1 + 1;
    do {
      uVar2 = *param_1;
      uVar4 = uVar2 << 8 | uVar2 >> 8;
      uVar5 = (uint)uVar4;
      bVar3 = (byte)(uVar2 >> 8);
      if (uVar4 < 0xd800) {
        if (uVar5 < 0x80) {
          *in_EAX = bVar3;
          in_EAX = in_EAX + 1;
        }
        else {
LAB_007252b4:
          if (uVar5 < 0x800) {
            *in_EAX = (byte)(uVar4 >> 6) | 0xc0;
            in_EAX[1] = bVar3 & 0x3f | 0x80;
            in_EAX = in_EAX + 2;
          }
          else {
            *in_EAX = (byte)uVar2 >> 4 | 0xe0;
            in_EAX[1] = (byte)(uVar4 >> 6) & 0x3f | 0x80;
            in_EAX[2] = bVar3 & 0x3f | 0x80;
            in_EAX = in_EAX + 3;
          }
        }
LAB_00725397:
        param_1 = param_1 + 1;
        puVar7 = puVar7 + 1;
      }
      else {
        if (uVar5 - 0xe000 < 0x2000) {
          if (0x7f < uVar5) goto LAB_007252b4;
          *in_EAX = bVar3;
          in_EAX = in_EAX + 1;
          goto LAB_00725397;
        }
        if (((0x3ff < uVar5 - 0xd800) || (puVar1 <= puVar7)) ||
           (uVar6 = (uint)(ushort)(*puVar7 << 8 | *puVar7 >> 8), 0x3ff < uVar6 - 0xdc00))
        goto LAB_00725397;
        uVar5 = ((uVar5 & 0x3ff) + 0x40) * 0x400 + (uVar6 & 0x3ff);
        *in_EAX = (byte)(uVar5 >> 0x12) | 0xf0;
        in_EAX[1] = (byte)(uVar5 >> 0xc) & 0x3f | 0x80;
        in_EAX[2] = (byte)(uVar5 >> 6) & 0x3f | 0x80;
        in_EAX[3] = (byte)uVar5 & 0x3f | 0x80;
        in_EAX = in_EAX + 4;
        param_1 = param_1 + 2;
        puVar7 = puVar7 + 2;
      }
    } while (param_1 < puVar1);
  }
  return;
}


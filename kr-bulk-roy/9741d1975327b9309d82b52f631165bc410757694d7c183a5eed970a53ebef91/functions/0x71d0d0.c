
void FUN_0071d0d0(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 *unaff_ESI;
  
  pbVar3 = (byte *)*unaff_ESI;
  bVar1 = (&DAT_00c0b650)[*pbVar3];
  while ((bVar1 & 8) != 0) {
    pbVar4 = pbVar3 + 1;
    pbVar3 = pbVar3 + 1;
    bVar1 = (&DAT_00c0b650)[*pbVar4];
  }
  unaff_ESI[1] = pbVar3;
  bVar1 = *pbVar3;
  switch(bVar1) {
  case 0:
    unaff_ESI[4] = 0x1a;
    *unaff_ESI = pbVar3;
    return;
  default:
    if (((&DAT_00c0b750)[bVar1] & 8) != 0) {
      unaff_ESI[2] = pbVar3;
      bVar1 = (&DAT_00c0b750)[*pbVar3];
      while ((bVar1 & 8) != 0) {
        pbVar4 = pbVar3 + 1;
        pbVar3 = pbVar3 + 1;
        bVar1 = (&DAT_00c0b750)[*pbVar4];
      }
      if (*pbVar3 == 0x2e) {
        bVar1 = (&DAT_00c0b750)[pbVar3[1]];
        pbVar4 = pbVar3;
        while (pbVar3 = pbVar4 + 1, (bVar1 & 8) != 0) {
          bVar1 = (&DAT_00c0b750)[pbVar4[2]];
          pbVar4 = pbVar3;
        }
      }
      unaff_ESI[3] = pbVar3;
      unaff_ESI[4] = 0xf;
      *unaff_ESI = pbVar3;
      return;
    }
    if (((&DAT_00c0b750)[bVar1] & 4) != 0) {
      unaff_ESI[2] = pbVar3;
      bVar1 = (&DAT_00c0b750)[*pbVar3];
      while ((bVar1 & 0x10) != 0) {
        pbVar4 = pbVar3 + 1;
        pbVar3 = pbVar3 + 1;
        bVar1 = (&DAT_00c0b750)[*pbVar4];
      }
      if (*pbVar3 == 0x3a) {
        if (pbVar3[1] == 0x2a) {
          unaff_ESI[4] = 0x14;
          unaff_ESI[3] = pbVar3 + 2;
          *unaff_ESI = pbVar3 + 2;
          return;
        }
        if (((&DAT_00c0b750)[pbVar3[1]] & 0x10) != 0) {
          bVar1 = (&DAT_00c0b750)[pbVar3[1]];
          pbVar4 = pbVar3;
          while (pbVar3 = pbVar4 + 1, (bVar1 & 0x10) != 0) {
            bVar1 = (&DAT_00c0b750)[pbVar4[2]];
            pbVar4 = pbVar3;
          }
        }
      }
      unaff_ESI[4] = 0x14;
      unaff_ESI[3] = pbVar3;
      *unaff_ESI = pbVar3;
      return;
    }
    break;
  case 0x21:
    if (pbVar3[1] == 0x3d) {
      unaff_ESI[4] = 2;
      *unaff_ESI = pbVar3 + 2;
      return;
    }
    break;
  case 0x22:
  case 0x27:
    pbVar3 = pbVar3 + 1;
    unaff_ESI[2] = pbVar3;
    bVar2 = *pbVar3;
    while ((bVar2 != 0 && (bVar2 != bVar1))) {
      pbVar4 = pbVar3 + 1;
      pbVar3 = pbVar3 + 1;
      bVar2 = *pbVar4;
    }
    unaff_ESI[3] = pbVar3;
    if (*pbVar3 != 0) {
      unaff_ESI[4] = 0xe;
      *unaff_ESI = pbVar3 + 1;
      return;
    }
    break;
  case 0x24:
    pbVar4 = pbVar3 + 1;
    pbVar3 = pbVar3 + 1;
    if (((&DAT_00c0b750)[*pbVar4] & 4) != 0) {
      unaff_ESI[2] = pbVar3;
      bVar1 = (&DAT_00c0b750)[*pbVar3];
      while ((bVar1 & 0x10) != 0) {
        pbVar4 = pbVar3 + 1;
        pbVar3 = pbVar3 + 1;
        bVar1 = (&DAT_00c0b750)[*pbVar4];
      }
      if ((*pbVar3 == 0x3a) && (((&DAT_00c0b750)[pbVar3[1]] & 0x10) != 0)) {
        bVar1 = (&DAT_00c0b750)[pbVar3[1]];
        while (pbVar3 = pbVar3 + 1, (bVar1 & 0x10) != 0) {
          bVar1 = (&DAT_00c0b750)[pbVar3[1]];
        }
      }
      unaff_ESI[4] = 0xb;
      unaff_ESI[3] = pbVar3;
      *unaff_ESI = pbVar3;
      return;
    }
    break;
  case 0x28:
    unaff_ESI[4] = 0xc;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x29:
    unaff_ESI[4] = 0xd;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x2a:
    unaff_ESI[4] = 9;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x2b:
    unaff_ESI[4] = 7;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x2c:
    unaff_ESI[4] = 0x15;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x2d:
    unaff_ESI[4] = 8;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x2e:
    if (pbVar3[1] == 0x2e) {
      unaff_ESI[4] = 0x18;
      *unaff_ESI = pbVar3 + 2;
      return;
    }
    if (((&DAT_00c0b750)[pbVar3[1]] & 8) == 0) {
      unaff_ESI[4] = 0x17;
      *unaff_ESI = pbVar3 + 1;
      return;
    }
    unaff_ESI[2] = pbVar3;
    bVar1 = (&DAT_00c0b750)[pbVar3[1]];
    while (pbVar3 = pbVar3 + 1, (bVar1 & 8) != 0) {
      bVar1 = (&DAT_00c0b750)[pbVar3[1]];
    }
    unaff_ESI[3] = pbVar3;
    unaff_ESI[4] = 0xf;
    *unaff_ESI = pbVar3;
    return;
  case 0x2f:
    if (pbVar3[1] != 0x2f) {
      unaff_ESI[4] = 0x10;
      *unaff_ESI = pbVar3 + 1;
      return;
    }
    unaff_ESI[4] = 0x11;
    *unaff_ESI = pbVar3 + 2;
    return;
  case 0x3a:
    if (pbVar3[1] == 0x3a) {
      unaff_ESI[4] = 0x19;
      *unaff_ESI = pbVar3 + 2;
      return;
    }
    break;
  case 0x3c:
    if (pbVar3[1] != 0x3d) {
      unaff_ESI[4] = 3;
      *unaff_ESI = pbVar3 + 1;
      return;
    }
    unaff_ESI[4] = 5;
    *unaff_ESI = pbVar3 + 2;
    return;
  case 0x3d:
    unaff_ESI[4] = 1;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x3e:
    if (pbVar3[1] != 0x3d) {
      unaff_ESI[4] = 4;
      *unaff_ESI = pbVar3 + 1;
      return;
    }
    unaff_ESI[4] = 6;
    *unaff_ESI = pbVar3 + 2;
    return;
  case 0x40:
    unaff_ESI[4] = 0x16;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x5b:
    unaff_ESI[4] = 0x12;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x5d:
    unaff_ESI[4] = 0x13;
    *unaff_ESI = pbVar3 + 1;
    return;
  case 0x7c:
    unaff_ESI[4] = 10;
    *unaff_ESI = pbVar3 + 1;
    return;
  }
  unaff_ESI[4] = 0;
  *unaff_ESI = pbVar3;
  return;
}


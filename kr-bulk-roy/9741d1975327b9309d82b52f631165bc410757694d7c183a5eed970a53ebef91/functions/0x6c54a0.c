
void FUN_006c54a0(void)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  undefined4 in_ECX;
  
  uVar1 = *(uint *)(in_EAX + 0x10);
  if (uVar1 < 0xf43ea) {
    if (uVar1 == 0xf43e9) {
      FUN_006c5890();
      return;
    }
    if (uVar1 == 0x70b) {
      iVar2 = FUN_004068c0();
      switch(*(undefined4 *)(iVar2 + 0x14)) {
      case 1:
        FUN_006c30e0(in_ECX);
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 2:
        FUN_006c3140(in_ECX);
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 3:
        FUN_006c3bd0();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 4:
        FUN_006c3d50(in_ECX);
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 5:
        FUN_006c40b0();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 6:
        FUN_006c4240();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 7:
        FUN_006c43d0();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 8:
        FUN_006c4560();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 9:
        FUN_006c46f0();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 10:
        FUN_006c4880();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0xb:
        FUN_006c4a10();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0xc:
        FUN_006c4ba0();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0xd:
        FUN_006c4d30(in_ECX);
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0xe:
        FUN_006c4de0();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0xf:
        FUN_006c4f70();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0x10:
        FUN_006c5100();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0x11:
        FUN_006c31a0(in_ECX);
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0x12:
        FUN_006c3200();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0x13:
        FUN_006c3390();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0x14:
        FUN_006c3520(in_ECX);
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0x15:
        FUN_006c3730();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0x16:
        FUN_006c38c0();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0x17:
        FUN_006c3a50();
        FUN_00404aa0();
        FUN_0074f940();
        return;
      case 0x19:
        FUN_006c5290();
      }
      FUN_00404aa0();
      FUN_0074f940();
      return;
    }
  }
  else {
    switch(uVar1) {
    case 0xf43ea:
      FUN_006c5970();
      return;
    case 0xf43eb:
      FUN_006c5a80();
      return;
    case 0xf43ec:
      FUN_006c5b60();
      return;
    case 0xf43ed:
      FUN_006c5c30();
      return;
    case 0xf43ee:
      FUN_006c5cf0();
      return;
    case 0xf43ef:
      FUN_006c5db0();
      return;
    case 0xf43f0:
      FUN_006c5e70();
      return;
    case 0xf43f1:
      FUN_006c5fb0();
      return;
    case 0xf43f2:
      FUN_0063ddd0();
      return;
    case 0xf43f3:
      FUN_006c6050();
      return;
    case 0xf43f4:
      FUN_006c60f0();
      return;
    case 0xf43f5:
      FUN_006c61b0();
      return;
    case 0xf43f6:
      FUN_006c6310();
      return;
    case 0xf43f7:
      FUN_006c6250();
      return;
    case 0xf43f8:
      FUN_006c63d0(in_ECX);
      return;
    case 0xf43f9:
      FUN_006c6500(in_ECX);
      return;
    case 0xf43fa:
      FUN_006c6630(in_ECX);
      return;
    case 0xf43fb:
      FUN_006c6760();
    }
  }
  return;
}


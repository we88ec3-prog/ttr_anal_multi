
undefined4 FUN_0071ff30(undefined1 *param_1)

{
  char cVar1;
  undefined4 *unaff_ESI;
  
  *param_1 = 1;
  switch(*(undefined1 *)*unaff_ESI) {
  case 0x61:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 0;
    }
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 1;
    }
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 2;
    }
    break;
  case 99:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 3;
    }
    break;
  case 100:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 4;
    }
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 5;
    }
    break;
  case 0x66:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 6;
    }
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 7;
    }
    break;
  case 0x6e:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 8;
    }
    break;
  case 0x70:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 9;
    }
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 10;
    }
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 0xb;
    }
    break;
  case 0x73:
    cVar1 = FUN_0071d0a0();
    if (cVar1 != '\0') {
      return 0xc;
    }
  }
  *param_1 = 0;
  return 3;
}


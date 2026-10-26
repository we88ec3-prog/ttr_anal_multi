
byte FUN_00645060(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iStack00000004;
  
  bVar3 = 0;
  iStack00000004 = 0;
  do {
    switch(iStack00000004) {
    case 0:
      cVar1 = FUN_00640ab0();
      bVar3 = bVar3 | cVar1 != '\0';
      break;
    case 1:
      cVar1 = FUN_00640ab0();
      bVar3 = bVar3 | -(cVar1 != '\0') & 4U;
      break;
    case 2:
      cVar1 = FUN_00640ab0();
      bVar2 = -(cVar1 != '\0') & 8;
      goto LAB_00645131;
    case 3:
      cVar1 = FUN_00640ab0();
      bVar3 = bVar3 | -(cVar1 != '\0') & 2U;
      break;
    case 4:
      cVar1 = FUN_00640ab0();
      bVar3 = bVar3 | -(cVar1 != '\0') & 0x10U;
      break;
    case 5:
      cVar1 = FUN_00640ab0();
      bVar2 = -(cVar1 != '\0') & 0x20;
LAB_00645131:
      bVar3 = bVar3 | bVar2;
    }
    iStack00000004 = iStack00000004 + 1;
    if (5 < iStack00000004) {
      return bVar3;
    }
  } while( true );
}


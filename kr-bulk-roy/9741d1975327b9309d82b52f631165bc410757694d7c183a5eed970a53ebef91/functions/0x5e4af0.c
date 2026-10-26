
void FUN_005e4af0(void)

{
  int unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 uVar1;
  
  if (unaff_ESI == 0) {
    return;
  }
  switch(*(undefined4 *)(unaff_ESI + 8)) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 0xd:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x1b:
  case 0x1f:
  case 0x20:
  case 0x24:
  case 0x25:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    uVar1 = *(undefined4 *)(unaff_ESI + 4);
    break;
  default:
    goto switchD_005e4b04_caseD_5;
  case 0x15:
    uVar1 = *(undefined4 *)(unaff_ESI + 4);
  }
  FUN_005e4b70(unaff_EDI,uVar1);
switchD_005e4b04_caseD_5:
  FUN_005e3bc0(unaff_EDI,unaff_ESI);
  FUN_005e4340(unaff_EDI,unaff_ESI);
  return;
}


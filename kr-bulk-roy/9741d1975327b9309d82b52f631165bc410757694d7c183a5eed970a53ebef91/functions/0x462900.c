
void FUN_00462900(void)

{
  undefined2 in_AX;
  undefined2 *unaff_EDI;
  undefined4 uVar1;
  
  switch(in_AX) {
  case 1:
    uVar1 = 0x127;
    FUN_00585620(0x127);
    uVar1 = FUN_00585330(uVar1);
    FUN_00402250(uVar1);
    return;
  case 2:
    uVar1 = 0x128;
    FUN_00585620(0x128);
    uVar1 = FUN_00585330(uVar1);
    FUN_00402250(uVar1);
    return;
  case 3:
    uVar1 = 0x129;
    FUN_00585620(0x129);
    uVar1 = FUN_00585330(uVar1);
    FUN_00402250(uVar1);
    return;
  case 4:
    uVar1 = 0x12a;
    FUN_00585620(0x12a);
    uVar1 = FUN_00585330(uVar1);
    FUN_00402250(uVar1);
    return;
  default:
    *(undefined4 *)(unaff_EDI + 8) = 0;
    *(undefined4 *)(unaff_EDI + 10) = 7;
    *unaff_EDI = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    return;
  }
}


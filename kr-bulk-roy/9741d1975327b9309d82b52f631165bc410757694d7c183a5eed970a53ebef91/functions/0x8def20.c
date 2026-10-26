
void FUN_008def20(void)

{
  undefined4 uVar1;
  undefined4 *unaff_EBX;
  uint uVar2;
  
  uVar1 = unaff_EBX[1];
  FUN_008ddb10();
  FUN_008ddb10();
  FUN_008ddb10();
  FUN_008ddb10();
  if (unaff_EBX[0x1da] != 0) {
    uVar2 = 0;
    if (unaff_EBX[0x1da] != 0) {
      do {
        FUN_008deae0(uVar1);
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)unaff_EBX[0x1da]);
    }
    FUN_008b9f80(uVar1,unaff_EBX[0x1db]);
    unaff_EBX[0x1db] = 0;
  }
  FUN_008de580();
  FUN_008de280();
  FUN_008deae0(uVar1);
  FUN_008de070(*unaff_EBX);
  FUN_008b9f80(uVar1,unaff_EBX[0x2e4]);
  unaff_EBX[0x2e4] = 0;
  FUN_008b9f80(uVar1,unaff_EBX[0x146]);
  unaff_EBX[0x146] = 0;
  FUN_008b9f80(uVar1,unaff_EBX[0x147]);
  unaff_EBX[0x147] = 0;
  FUN_008b9f80(uVar1,unaff_EBX[0x149]);
  unaff_EBX[0x149] = 0;
  FUN_008b9f80(uVar1,unaff_EBX[0x14a]);
  unaff_EBX[0x14a] = 0;
  if ((code *)unaff_EBX[0x2e8] != (code *)0x0) {
    (*(code *)unaff_EBX[0x2e8])(unaff_EBX[0x2e7]);
    FUN_008b9f80(uVar1,unaff_EBX[0x2e7]);
    unaff_EBX[0x2e7] = 0;
  }
  return;
}


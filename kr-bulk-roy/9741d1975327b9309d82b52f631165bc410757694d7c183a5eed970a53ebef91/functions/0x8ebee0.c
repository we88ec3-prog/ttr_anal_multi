
undefined4 FUN_008ebee0(void)

{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  
  uVar1 = unaff_ESI[2];
  unaff_ESI[0x6e] = 0;
  FUN_008b9f80(uVar1,unaff_ESI[6]);
  unaff_ESI[6] = 0;
  unaff_ESI[5] = 0;
  FUN_008b9f80(uVar1,unaff_ESI[0x6d]);
  unaff_ESI[0x6d] = 0;
  unaff_ESI[0x6c] = 0;
  unaff_ESI[0x6b] = 0;
  FUN_008b9f80(uVar1,unaff_ESI[0x62]);
  unaff_ESI[0x62] = 0;
  unaff_ESI[0x61] = 0;
  unaff_ESI[1] = 0;
  *unaff_ESI = 0;
  FUN_008b9f80(uVar1);
  return 0;
}



void FUN_0079c5b0(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_EDI;
  
  puVar1 = (undefined4 *)FUN_00891268(0x30);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = IS3D::CFieldPanel::vftable;
    puVar1[4] = 0x3f800000;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[5] = 0;
    puVar1[0xb] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
  }
  unaff_EDI[1] = 0x3f800000;
  unaff_EDI[2] = 0;
  *unaff_EDI = puVar1;
  FUN_007bedc0(puVar1,0,0x41400000,0x41400000,0,0,0);
  return;
}


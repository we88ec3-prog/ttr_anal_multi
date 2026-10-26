
void FUN_00640ba0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_004285e0();
  *unaff_ESI = FUI::CChatForm::vftable;
  unaff_ESI[0x48] = 0;
  unaff_ESI[0x49] = 7;
  *(undefined2 *)(unaff_ESI + 0x44) = 0;
  unaff_ESI[0x4c] = 0;
  unaff_ESI[0x4d] = 0;
  unaff_ESI[0x4e] = 0;
  unaff_ESI[0x4f] = 0;
  unaff_ESI[0x50] = 0;
  *(undefined1 *)(unaff_ESI + 0x51) = 0;
  unaff_ESI[0x52] = 0;
  unaff_ESI[0x53] = 0;
  unaff_ESI[0x54] = 0;
  return;
}


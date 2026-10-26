
void FUN_005df620(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  in_ECX[0xa6] = 0;
  in_ECX[0xa8] = 0;
  in_ECX[0xa9] = 0;
  in_ECX[0xaa] = 0;
  in_ECX[0xab] = 0;
  *in_ECX = FUI::CItemSlotMailAttachmentSlotWrite::vftable;
  return;
}


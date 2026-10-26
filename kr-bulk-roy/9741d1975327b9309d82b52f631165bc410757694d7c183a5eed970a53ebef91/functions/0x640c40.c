
void FUN_00640c40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CChatForm::vftable;
  if (in_ECX[0x52] != 0) {
    FUN_0049bf30();
    FUN_0089120c(in_ECX[0x52]);
  }
  in_ECX[0x52] = 0;
  in_ECX[0x53] = 0;
  in_ECX[0x54] = 0;
  if (7 < (uint)in_ECX[0x49]) {
    FUN_0089120c(in_ECX[0x44]);
  }
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 7;
  *(undefined2 *)(in_ECX + 0x44) = 0;
  *in_ECX = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  return;
}


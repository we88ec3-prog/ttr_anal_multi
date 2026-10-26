
void FUN_0064dd20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CMiniMapFieldPanel::vftable;
  if (7 < (uint)in_ECX[0x4a]) {
    FUN_0089120c(in_ECX[0x45]);
  }
  in_ECX[0x4a] = 7;
  in_ECX[0x49] = 0;
  *(undefined2 *)(in_ECX + 0x45) = 0;
  *in_ECX = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  return;
}


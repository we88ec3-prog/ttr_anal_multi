
void FUN_00699980(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CCashShopChar::vftable;
  if (in_ECX[0x59] != 0) {
    FUN_0089120c(in_ECX[0x59]);
  }
  in_ECX[0x59] = 0;
  in_ECX[0x5a] = 0;
  in_ECX[0x5b] = 0;
  if (in_ECX[0x44] != 0) {
    FUN_0089120c(in_ECX[0x44]);
  }
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0;
  *in_ECX = FoxUI::FXUIDummy::vftable;
  FUN_00745380();
  return;
}


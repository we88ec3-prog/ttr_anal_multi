
void FUN_00776400(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIImageSetItem::vftable;
  if (7 < (uint)in_ECX[8]) {
    FUN_0089120c(in_ECX[3]);
  }
  in_ECX[8] = 7;
  in_ECX[7] = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  *in_ECX = FoxUI::FXUIArchive::vftable;
  return;
}


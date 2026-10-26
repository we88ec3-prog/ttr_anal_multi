
void FUN_00693d00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CPartyListInside::vftable;
  if (7 < (uint)in_ECX[0x33]) {
    FUN_0089120c(in_ECX[0x2e]);
  }
  in_ECX[0x33] = 7;
  in_ECX[0x32] = 0;
  *(undefined2 *)(in_ECX + 0x2e) = 0;
  *in_ECX = FoxUI::FXUIDummy::vftable;
  FUN_00745380();
  return;
}


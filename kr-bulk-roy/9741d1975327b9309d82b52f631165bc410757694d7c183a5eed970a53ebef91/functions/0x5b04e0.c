
void FUN_005b04e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CPartyLobbyPage::vftable;
  FUN_005b5230();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}


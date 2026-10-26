
void FUN_00520940(byte param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX[3] != 0) {
    FUN_0089120c(in_ECX[3]);
  }
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *in_ECX = ITEM::UsableAction::ItemUsableAction::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


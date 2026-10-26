
void FUN_004c5000(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = Scene::CRaidDecision::vftable;
  FUN_004ba640(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


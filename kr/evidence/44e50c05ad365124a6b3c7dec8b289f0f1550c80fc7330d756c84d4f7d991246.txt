
void FUN_004c4380(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = Scene::CScenarioDecision::vftable;
  FUN_004ba640(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


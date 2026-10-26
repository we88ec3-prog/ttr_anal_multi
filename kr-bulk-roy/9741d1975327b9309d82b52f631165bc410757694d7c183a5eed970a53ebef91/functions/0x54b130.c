
void FUN_0054b130(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = SubAI::CPhaseCondition::vftable;
  if (in_ECX[1] != 0) {
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *in_ECX = ObsessionsAI::CCondition::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


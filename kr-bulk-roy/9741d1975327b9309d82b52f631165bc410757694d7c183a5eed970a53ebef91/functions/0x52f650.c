
void FUN_0052f650(uint param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = SkillTable::CSkillLevelBase::vftable;
  if (in_ECX[1] != 0) {
    FUN_00508b90(param_1);
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


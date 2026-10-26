
void FUN_0052f530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = SkillTable::CSkillLevelactive::vftable;
  if (in_ECX[5] != 0) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = SkillTable::CSkillLevelBase::vftable;
  if (in_ECX[1] != 0) {
    FUN_00508b90(in_ECX);
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


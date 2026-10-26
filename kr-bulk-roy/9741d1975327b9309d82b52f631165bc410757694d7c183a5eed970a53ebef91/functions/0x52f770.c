
void FUN_0052f770(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = SkillTable::CSkillActive::vftable;
  in_ECX[0x13] = SkillTable::CSkillActive::vftable;
  if (in_ECX[0x1e] != 0) {
    FUN_0089120c(in_ECX[0x1e]);
  }
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  FUN_0052f530();
  FUN_0052f5f0();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


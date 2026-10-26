
void FUN_0082cb70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSkillInterrupt_CooltimeReset::vftable;
  if (in_ECX[3] != 0) {
    FUN_0089120c(in_ECX[3]);
  }
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *in_ECX = CInterruptAction::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


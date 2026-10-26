
void FUN_0052f5f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = SkillTable::CSkillBase::vftable;
  if (7 < (uint)in_ECX[0xf]) {
    FUN_0089120c(in_ECX[10]);
  }
  in_ECX[0xf] = 7;
  in_ECX[0xe] = 0;
  *(undefined2 *)(in_ECX + 10) = 0;
  if (7 < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[7] = 7;
  in_ECX[6] = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  return;
}


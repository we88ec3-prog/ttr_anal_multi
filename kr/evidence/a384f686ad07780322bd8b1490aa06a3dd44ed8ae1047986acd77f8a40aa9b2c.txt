
void FUN_004d18d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMonster::vftable;
  in_ECX[0x3c] = CMonster::vftable;
  FUN_004c7b90();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


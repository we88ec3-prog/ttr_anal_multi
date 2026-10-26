
void FUN_0054b420(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSubAIManager::vftable;
  if (in_ECX[0xb] != 0) {
    FUN_0089120c(in_ECX[0xb]);
  }
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  FUN_00808450();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


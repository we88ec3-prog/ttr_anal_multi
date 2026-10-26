
void FUN_004d0ca0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CEventActor::vftable;
  in_ECX[0x3c] = CEventActor::vftable;
  FUN_004c7b90();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


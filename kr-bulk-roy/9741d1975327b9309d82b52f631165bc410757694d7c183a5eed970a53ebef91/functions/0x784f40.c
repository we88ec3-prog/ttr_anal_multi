
void FUN_00784f40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = gbBase::vftable;
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = gbRefCount::vftable;
  return;
}


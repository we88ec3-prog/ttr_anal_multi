
void FUN_0080ff40(void)

{
  int *in_ECX;
  
  alSourcePlay(in_ECX[4]);
  if (in_ECX[0x8009] != 0) {
    (**(code **)(*in_ECX + 0x20))(in_ECX[0x800a]);
  }
  FUN_00810080();
  return;
}



bool FUN_008122f0(void)

{
  int in_ECX;
  int local_8;
  
  local_8 = in_ECX;
  alGetSourcei(*(undefined4 *)(in_ECX + 8),0x1010,&local_8);
  alGetError();
  return local_8 == 0x1012;
}



bool FUN_0080ff70(void)

{
  int in_ECX;
  int local_8;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    return false;
  }
  local_8 = in_ECX;
  alGetSourcei(*(int *)(in_ECX + 0x10),0x1010,&local_8);
  alGetError();
  return local_8 == 0x1012;
}


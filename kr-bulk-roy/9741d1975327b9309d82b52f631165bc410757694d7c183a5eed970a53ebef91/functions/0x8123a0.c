
bool FUN_008123a0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    alSourceStop(*(int *)(in_ECX + 8));
    iVar1 = alGetError();
    return iVar1 == 0;
  }
  return true;
}


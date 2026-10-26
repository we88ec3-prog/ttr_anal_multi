
bool FUN_008123f0(void)

{
  int iVar1;
  int in_ECX;
  
  alSourcePause(*(undefined4 *)(in_ECX + 8));
  iVar1 = alGetError();
  return iVar1 == 0;
}


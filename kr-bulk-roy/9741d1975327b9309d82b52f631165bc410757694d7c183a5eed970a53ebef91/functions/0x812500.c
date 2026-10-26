
bool FUN_00812500(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    return true;
  }
  alSourcef(*(undefined4 *)(in_ECX + 8),0x100a,param_1);
  iVar1 = alGetError();
  return iVar1 == 0;
}


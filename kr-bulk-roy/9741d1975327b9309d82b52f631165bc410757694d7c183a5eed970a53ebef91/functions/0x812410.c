
float10 FUN_00812410(void)

{
  int iVar1;
  int *in_ECX;
  float local_8;
  
  local_8 = 0.0;
  iVar1 = (**(code **)(*in_ECX + 0x10))();
  if (iVar1 != 0) {
    alGetSourcef(in_ECX[2],0x1024,&local_8);
    alGetError();
  }
  return (float10)local_8;
}


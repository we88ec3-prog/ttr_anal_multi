
void FUN_0075b110(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 900) {
    if ((char)in_ECX[0x3a] != '\0') {
      (**(code **)(*in_ECX + 0x18c))();
    }
  }
  else if (iVar1 == 0x385) {
    if ((char)in_ECX[0x3a] != '\0') {
      (**(code **)(*in_ECX + 400))();
      return;
    }
  }
  else if ((iVar1 == 0x386) && ((char)in_ECX[0x3a] != '\0')) {
    (**(code **)(*in_ECX + 0x194))();
    return;
  }
  return;
}



void FUN_00755f80(int param_1)

{
  int *in_ECX;
  
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 900:
    if ((char)in_ECX[0x3a] != '\0') {
      (**(code **)(*in_ECX + 0x18c))();
      return;
    }
    break;
  case 0x385:
    if ((char)in_ECX[0x3a] != '\0') {
      (**(code **)(*in_ECX + 400))();
      return;
    }
    break;
  case 0x386:
    if ((char)in_ECX[0x3a] != '\0') {
      (**(code **)(*in_ECX + 0x194))();
      return;
    }
    break;
  case 0x387:
    if ((char)in_ECX[0x3c] != '\0') {
      (**(code **)(*in_ECX + 0x184))();
    }
  }
  return;
}


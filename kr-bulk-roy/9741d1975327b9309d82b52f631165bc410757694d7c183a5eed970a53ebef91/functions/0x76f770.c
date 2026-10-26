
void FUN_0076f770(int param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0x4b1) {
    if (uVar1 == 0x4b0) {
      if (*(char *)((int)in_ECX + 0xf5) != '\0') {
        (**(code **)(*in_ECX + 0x1a8))();
        return;
      }
    }
    else {
      switch(uVar1) {
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
        if (*(char *)((int)in_ECX + 0xf6) != '\0') {
          (**(code **)(*in_ECX + 0x184))();
          return;
        }
      }
    }
  }
  else if (uVar1 == 0x4b1) {
    if (*(char *)((int)in_ECX + 0xf5) != '\0') {
      (**(code **)(*in_ECX + 0x1a4))();
    }
  }
  else if ((uVar1 == 0x4b2) && ((char)in_ECX[0x3d] != '\0')) {
    (**(code **)(*in_ECX + 0x1a0))();
    return;
  }
  return;
}


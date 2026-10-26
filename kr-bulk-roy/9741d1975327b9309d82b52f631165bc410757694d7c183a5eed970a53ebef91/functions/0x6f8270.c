
undefined4 FUN_006f8270(int param_1)

{
  bool bVar1;
  uint in_ECX;
  int in_EDX;
  
  if (param_1 == 0) {
    if (in_ECX != 0) {
      return 0;
    }
  }
  else if (param_1 == 2) {
    if ((int)(uint)*(byte *)(in_EDX + 0x4b) <= (int)in_ECX) {
      return 0;
    }
  }
  else if (param_1 == 3) {
    if ((in_ECX & 0x100) == 0) {
      bVar1 = (int)in_ECX < (int)(uint)*(byte *)(in_EDX + 0x4b);
    }
    else {
      bVar1 = (int)(in_ECX & 0xfffffeff) < *(int *)(in_EDX + 0x28);
    }
    if (!bVar1) {
      return 0;
    }
  }
  return 1;
}



void FUN_00719ce0(int param_1,int param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x14) = 0;
  if (param_2 == 0) {
    *(int *)(in_ECX + 0x10) = param_1;
  }
  else {
    if (param_2 == 1) {
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + param_1;
      return;
    }
    if (param_2 == 2) {
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0xc) - param_1;
      return;
    }
  }
  return;
}


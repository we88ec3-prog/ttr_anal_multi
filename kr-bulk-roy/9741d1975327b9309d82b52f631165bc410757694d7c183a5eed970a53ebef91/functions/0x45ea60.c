
void FUN_0045ea60(int param_1)

{
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
      *(undefined4 *)in_ECX[0x40] = 0;
      FUN_00797a00();
      FUN_0045eb40();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  return;
}


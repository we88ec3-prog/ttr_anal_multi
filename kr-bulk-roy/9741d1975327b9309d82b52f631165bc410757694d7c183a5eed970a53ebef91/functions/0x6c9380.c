
void FUN_006c9380(int param_1)

{
  int *in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20))) {
    if ((*(uint *)(in_ECX[0x40] + 0x28) >> 9 & 1) != 0) {
      FUN_006c93e0();
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    FUN_006c9460(in_ECX);
    (**(code **)(*in_ECX + 0xd4))();
  }
  return;
}


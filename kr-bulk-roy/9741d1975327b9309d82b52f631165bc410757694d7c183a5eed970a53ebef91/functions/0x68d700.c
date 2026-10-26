
void FUN_0068d700(int param_1)

{
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
      FUN_0068d4c0(in_ECX);
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
  }
  else if ((*(int *)(param_1 + 0x10) == 0x3ea) &&
          (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3d] + 0x20))) {
    FUN_0068d4c0(in_ECX);
    (**(code **)(*in_ECX + 0xd4))();
  }
  return;
}


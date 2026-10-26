
void FUN_006aad80(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x3ea) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3d] + 0x20)) {
      FUN_006aaff0(in_ECX);
    }
  }
  else if (iVar1 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
      FUN_006ab220(in_ECX);
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
  }
  else if ((iVar1 == 0x70a) && (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x40] + 0x20))) {
    FUN_006aaeb0(in_ECX);
    return;
  }
  return;
}


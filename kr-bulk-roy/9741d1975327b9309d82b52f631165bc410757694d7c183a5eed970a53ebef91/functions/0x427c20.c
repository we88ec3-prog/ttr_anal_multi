
void FUN_00427c20(int param_1)

{
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x44] + 0x20)) {
      (**(code **)(*in_ECX + 0x16c))(~(byte)(*(uint *)(in_ECX[0x44] + 0x28) >> 9) & 1);
    }
    if (*(int *)(in_ECX[0x46] + 0x20) == *(int *)(param_1 + 8)) {
      FUN_00427ed0(in_ECX,1);
    }
    if (*(int *)(in_ECX[0x47] + 0x20) == *(int *)(param_1 + 8)) {
      FUN_00427ed0(in_ECX,2);
    }
    if (*(int *)(in_ECX[0x48] + 0x20) == *(int *)(param_1 + 8)) {
      FUN_00427ed0(in_ECX,3);
    }
  }
  return;
}


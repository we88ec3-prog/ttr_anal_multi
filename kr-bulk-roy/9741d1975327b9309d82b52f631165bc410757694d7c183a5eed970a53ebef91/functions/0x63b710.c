
void FUN_0063b710(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x3ea) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3d] + 0x20)) {
LAB_0063b7bd:
      FUN_0063b620();
      return;
    }
  }
  else if (iVar1 == 0x3ec) {
    iVar1 = in_ECX[0x3d];
    if (*(int *)(param_1 + 8) == *(int *)(iVar1 + 0x20)) {
      if (*(char *)(iVar1 + 0x141) != '\0') {
        FUN_006edb10("Not supported operation");
      }
      if (*(int *)(iVar1 + 0x118) == 0) {
        (**(code **)(*(int *)in_ECX[0x3e] + 0x90))(0);
        return;
      }
      (**(code **)(*(int *)in_ECX[0x3e] + 0x90))(1);
    }
  }
  else if (iVar1 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) goto LAB_0063b7bd;
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
  }
  return;
}


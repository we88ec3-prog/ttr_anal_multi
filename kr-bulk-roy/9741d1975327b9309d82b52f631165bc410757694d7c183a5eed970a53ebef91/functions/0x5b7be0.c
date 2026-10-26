
void FUN_005b7be0(int param_1)

{
  int in_ECX;
  
  FUN_0059b8c0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf4356) {
    if (((uint)(*(int **)(in_ECX + 0x284))[10] >> 8 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x284) + 0xd4))();
    }
  }
  else if (((*(int *)(param_1 + 0x10) == 0xf4359) && (*(int *)(in_ECX + 0x2c4) != 0)) &&
          ((*(uint *)(*(int *)(in_ECX + 0x2c4) + 0x28) >> 8 & 1) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x2c4) + 0xd4))();
    return;
  }
  return;
}


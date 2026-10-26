
void FUN_00424090(int param_1)

{
  int in_ECX;
  
  FUN_005a44e0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf426b) {
    (**(code **)(**(int **)(in_ECX + 0x164) + 0xd0))();
  }
  return;
}


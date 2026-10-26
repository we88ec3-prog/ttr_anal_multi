
undefined4 FUN_00638e30(int param_1)

{
  int in_ECX;
  
  if (param_1 == 0xe) {
    if ((*(uint *)(*(int *)(in_ECX + 0x10) + 0x28) >> 8 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 4) + 0xd4))();
    }
    return 1;
  }
  return 0;
}


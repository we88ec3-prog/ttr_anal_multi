
void FUN_006959e0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x80) + 0xd0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xd8))(param_1);
  }
  return;
}


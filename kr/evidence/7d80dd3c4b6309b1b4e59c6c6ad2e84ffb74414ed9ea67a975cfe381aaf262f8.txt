
void FUN_007be5b0(void)

{
  int *piVar1;
  int in_EAX;
  int *piVar2;
  
  piVar2 = *(int **)(in_EAX + 4);
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  piVar1 = *(int **)(in_EAX + 8);
  *(undefined4 *)(in_EAX + 0x6c) = 0;
  for (; piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*(int *)(*piVar2 + 8) != 0) {
      (**(code **)(**(int **)(*piVar2 + 8) + 0x24))();
    }
  }
  return;
}


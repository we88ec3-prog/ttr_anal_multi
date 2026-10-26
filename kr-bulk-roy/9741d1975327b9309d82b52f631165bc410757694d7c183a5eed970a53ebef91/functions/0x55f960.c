
void FUN_0055f960(void)

{
  int iVar1;
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x2c) == 0) {
    iVar1 = *(int *)(in_EAX + 4);
    if (*(int *)(iVar1 + 0x34) == *(int *)(iVar1 + 0x10)) {
      if (*(int **)(in_EAX + 8) != (int *)0x0) {
        (**(code **)(**(int **)(in_EAX + 8) + 8))();
        *(undefined4 *)(in_EAX + 8) = 0;
      }
      FUN_0055f470(in_EAX);
      if (*(int *)(in_EAX + 0x28) != 0) {
        FUN_0055f8a0();
        return;
      }
      FUN_0055f370();
      if (*(int *)(in_EAX + 0x24) != 0) {
        FUN_0056c620();
        return;
      }
    }
    else {
      *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x10);
    }
  }
  return;
}



void FUN_006fd830(undefined4 param_1)

{
  int *piVar1;
  int in_EAX;
  
  piVar1 = (int *)(in_EAX + 0x10);
  if (*(int **)(in_EAX + 8) != piVar1) {
    *(int *)(*(int *)(in_EAX + 0x14) + 0x10) = *piVar1;
    *(undefined4 *)(*piVar1 + 0x14) = *(undefined4 *)(in_EAX + 0x14);
  }
  FUN_00700880(param_1);
  return;
}


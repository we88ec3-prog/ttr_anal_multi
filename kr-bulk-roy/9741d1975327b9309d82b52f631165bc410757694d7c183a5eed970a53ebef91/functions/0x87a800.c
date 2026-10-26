
undefined4 FUN_0087a800(int param_1)

{
  int iVar1;
  int in_stack_00000014;
  int *local_8;
  
  if ((*(int *)(in_stack_00000014 + 0x40) == 0) ||
     (iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0xd4))
                        (*(int **)(param_1 + 4),*(int *)(in_stack_00000014 + 0x40),&local_8),
     iVar1 < 0)) {
    local_8 = (int *)0x0;
  }
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0085a800(*(undefined4 *)(in_stack_00000014 + 4),local_8);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return 1;
}


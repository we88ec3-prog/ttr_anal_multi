
undefined4 FUN_0087a870(int param_1)

{
  undefined4 uVar1;
  int in_stack_00000014;
  
  in_stack_00000014 = *(undefined4 *)(in_stack_00000014 + 0x40);
  FUN_0085de90(&stack0x00000014);
  if (param_1 == *(int *)(param_1 + 0x44)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0085a950(uVar1);
  }
  return 1;
}


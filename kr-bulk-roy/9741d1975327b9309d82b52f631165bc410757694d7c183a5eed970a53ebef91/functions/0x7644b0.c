
undefined4 FUN_007644b0(void)

{
  int in_ECX;
  
  FUN_0082ef00(&stack0x00000004);
  if (in_ECX != *(int *)(in_ECX + 8)) {
    FUN_00746b80();
    FUN_00746c10();
    if (*(int **)(in_ECX + 0x10) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0x10) + 0x1c))(1);
      *(undefined4 *)(in_ECX + 0x10) = 0;
    }
    FUN_007b6890(in_ECX + 4,&stack0x00000004,in_ECX);
    return 1;
  }
  return 0;
}


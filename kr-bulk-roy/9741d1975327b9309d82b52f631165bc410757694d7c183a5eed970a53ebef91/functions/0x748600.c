
undefined4 FUN_00748600(void)

{
  undefined4 uVar1;
  int *in_ECX;
  int local_8;
  
  FUN_0082ef00(&stack0x00000004);
  if (local_8 != in_ECX[0x14]) {
    uVar1 = *(undefined4 *)(local_8 + 0x10);
    (**(code **)(*in_ECX + 0x74))(uVar1);
    if (*(int **)(local_8 + 0x10) != (int *)0x0) {
      (**(code **)(**(int **)(local_8 + 0x10) + 0x1c))(1);
      *(undefined4 *)(local_8 + 0x10) = 0;
    }
    FUN_007b6890(in_ECX + 0x13,&stack0x00000004,local_8);
    return uVar1;
  }
  return 0;
}


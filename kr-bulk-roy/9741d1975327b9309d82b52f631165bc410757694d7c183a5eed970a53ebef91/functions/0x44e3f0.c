
undefined4 FUN_0044e3f0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int local_8;
  
  FUN_0082ef00(&param_1);
  if (local_8 != *(int *)(in_ECX + 8)) {
    piVar1 = *(int **)(local_8 + 0x10);
    if (((uint)piVar1[10] >> 0x15 & 1) != 0) {
      FUN_00745680();
    }
    param_1 = piVar1[1];
    piVar2 = (int *)FUN_0082ef00(&param_1);
    if (*piVar2 == *(int *)(in_ECX + 0x18)) {
      FUN_00746b80();
      FUN_00746c10();
      (**(code **)(*piVar1 + 0x1c))(1);
    }
    FUN_007b6890(in_ECX + 4,&param_1,local_8);
    return 1;
  }
  return 0;
}


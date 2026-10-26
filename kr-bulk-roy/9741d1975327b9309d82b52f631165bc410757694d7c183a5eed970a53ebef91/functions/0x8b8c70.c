
undefined4 FUN_008b8c70(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    return 0x23;
  }
  if (param_2 == 0) {
    return 6;
  }
  if (param_2 == 0x756e6963) {
    uVar2 = FUN_008b8520();
    return uVar2;
  }
  piVar3 = *(int **)(param_1 + 0x28);
  if (piVar3 != (int *)0x0) {
    piVar1 = piVar3 + *(int *)(param_1 + 0x24);
    while( true ) {
      if (piVar1 <= piVar3) {
        return 6;
      }
      if (*(int *)(*piVar3 + 4) == param_2) break;
      piVar3 = piVar3 + 1;
    }
    *(int *)(param_1 + 0x5c) = *piVar3;
    return 0;
  }
  return 0x26;
}


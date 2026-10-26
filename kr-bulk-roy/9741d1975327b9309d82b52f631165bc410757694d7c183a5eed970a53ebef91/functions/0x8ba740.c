
undefined4 FUN_008ba740(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    return 0x23;
  }
  piVar3 = *(int **)(param_1 + 0x28);
  if (piVar3 == (int *)0x0) {
    return 0x26;
  }
  iVar2 = FUN_008b8e10(param_2);
  if (iVar2 != 0xe) {
    piVar1 = piVar3 + *(int *)(param_1 + 0x24);
    for (; piVar3 < piVar1; piVar3 = piVar3 + 1) {
      if (*piVar3 == param_2) {
        *(int *)(param_1 + 0x5c) = *piVar3;
        return 0;
      }
    }
  }
  return 6;
}


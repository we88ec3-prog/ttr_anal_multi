
undefined4 FUN_008bc0d0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 == 0) {
    return 0x21;
  }
  if (param_2 != 0) {
    piVar3 = (int *)(param_1 + 0x14);
    piVar2 = piVar3 + *(int *)(param_1 + 0x10);
    for (; piVar3 < piVar2; piVar3 = piVar3 + 1) {
      if (*piVar3 == param_2) {
        piVar2 = piVar2 + -1;
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
        if (piVar3 < piVar2) {
          piVar4 = piVar3;
          for (iVar1 = ((uint)((int)piVar2 + (-1 - (int)piVar3)) >> 2) + 1; piVar3 = piVar3 + 1,
              iVar1 != 0; iVar1 = iVar1 + -1) {
            *piVar4 = *piVar3;
            piVar4 = piVar4 + 1;
          }
        }
        *piVar2 = 0;
        FUN_008bc070();
        return 0;
      }
    }
  }
  return 0x22;
}


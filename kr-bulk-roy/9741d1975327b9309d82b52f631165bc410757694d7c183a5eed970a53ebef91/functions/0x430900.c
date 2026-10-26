
void FUN_00430900(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  short *psVar3;
  short sVar4;
  undefined1 *in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    if ((*(int *)piVar1[9] == 0) || (piVar2 = (int *)piVar1[0xd], *piVar2 < 1)) {
      sVar4 = (**(code **)(*piVar1 + 0xc))(param_1);
    }
    else {
      *piVar2 = *piVar2 + -1;
      psVar3 = *(short **)piVar1[9];
      *(short **)piVar1[9] = psVar3 + 1;
      sVar4 = (short)param_1;
      *psVar3 = sVar4;
    }
    if (sVar4 != -1) {
      return;
    }
  }
  *in_ECX = 1;
  return;
}


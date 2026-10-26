
void FUN_00474b80(int param_1)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  int *in_EDX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = *in_EDX;
  uVar3 = in_EDX[1] - iVar4 >> 2;
  uVar5 = 0;
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  if (3 < (int)uVar3) {
    piVar2 = (int *)(iVar4 + 8);
    iVar6 = (uVar3 - 4 >> 2) + 1;
    uVar5 = iVar6 * 4;
    do {
      piVar1 = (int *)piVar2[-2];
      if (*piVar1 == param_1) {
        *in_EAX = piVar1[1];
        in_EAX[1] = piVar1[2];
        in_EAX[2] = piVar1[3];
      }
      piVar1 = (int *)piVar2[-1];
      if (*piVar1 == param_1) {
        *in_EAX = piVar1[1];
        in_EAX[1] = piVar1[2];
        in_EAX[2] = piVar1[3];
      }
      piVar1 = (int *)*piVar2;
      if (*piVar1 == param_1) {
        *in_EAX = piVar1[1];
        in_EAX[1] = piVar1[2];
        in_EAX[2] = piVar1[3];
      }
      piVar1 = (int *)piVar2[1];
      if (*piVar1 == param_1) {
        *in_EAX = piVar1[1];
        in_EAX[1] = piVar1[2];
        in_EAX[2] = piVar1[3];
      }
      piVar2 = piVar2 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (uVar5 < uVar3) {
    piVar2 = (int *)(iVar4 + uVar5 * 4);
    iVar4 = uVar3 - uVar5;
    do {
      piVar1 = (int *)*piVar2;
      if (*piVar1 == param_1) {
        *in_EAX = piVar1[1];
        in_EAX[1] = piVar1[2];
        in_EAX[2] = piVar1[3];
      }
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


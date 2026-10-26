
void FUN_005c7ba0(int *param_1)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  
  if (in_EAX != param_1) {
    piVar2 = in_EAX + 7;
    do {
      if (*piVar2 != 0) {
        FUN_006ab960(param_1);
        FUN_0089120c(*piVar2);
      }
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      if (7 < (uint)piVar2[-2]) {
        FUN_0089120c(piVar2[-7]);
      }
      piVar2[-2] = 7;
      piVar2[-3] = 0;
      *(undefined2 *)(piVar2 + -7) = 0;
      piVar1 = piVar2 + 4;
      piVar2 = piVar2 + 0xb;
    } while (piVar1 != param_1);
  }
  return;
}


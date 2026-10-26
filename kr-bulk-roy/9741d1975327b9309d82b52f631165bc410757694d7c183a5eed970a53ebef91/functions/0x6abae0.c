
uint FUN_006abae0(int param_1)

{
  uint uVar1;
  int *in_EAX;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  piVar3 = (int *)*in_EAX;
  uVar1 = (in_EAX[1] - (int)piVar3) / 0x33;
  uVar4 = 0;
  while( true ) {
    uVar2 = uVar1;
    if (2 < uVar1) {
      uVar2 = 3;
    }
    if (uVar2 <= uVar4) break;
    if (*piVar3 == param_1) {
      return uVar4;
    }
    uVar4 = uVar4 + 1;
    piVar3 = (int *)((int)piVar3 + 0x33);
  }
  return 3;
}


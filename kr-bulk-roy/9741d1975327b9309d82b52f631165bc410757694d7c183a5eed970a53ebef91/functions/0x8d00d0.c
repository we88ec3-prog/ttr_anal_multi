
void FUN_008d00d0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  piVar3 = (int *)in_ECX[6];
  iVar2 = *in_ECX;
  piVar1 = piVar3 + in_ECX[4];
  for (; piVar3 < piVar1; piVar3 = piVar3 + 1) {
    if (*piVar3 != 0) {
      *piVar3 = *piVar3 + (iVar2 - param_1);
    }
  }
  return;
}


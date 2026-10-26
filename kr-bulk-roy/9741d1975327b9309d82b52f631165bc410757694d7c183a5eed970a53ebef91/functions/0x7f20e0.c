
int FUN_007f20e0(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = in_ECX + 2;
  *piVar1 = *piVar1 + -1;
  iVar2 = in_ECX[2];
  if (*piVar1 == 0) {
    if (in_ECX[1] != 0) {
      FUN_007f1c80();
      (**(code **)(*in_ECX + 8))();
    }
    iVar2 = in_ECX[2];
  }
  return iVar2;
}


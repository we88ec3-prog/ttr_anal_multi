
void FUN_0067c920(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int in_EDX;
  
  iVar1 = 0;
  piVar2 = (int *)(in_EDX + 300);
  while ((piVar2[-1] != -1 && (*piVar2 != -1))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0xe;
    if (1 < iVar1) {
      return;
    }
  }
  if (iVar1 != -1) {
    FUN_0067c960(in_EDX,iVar1,param_1,param_2);
  }
  return;
}


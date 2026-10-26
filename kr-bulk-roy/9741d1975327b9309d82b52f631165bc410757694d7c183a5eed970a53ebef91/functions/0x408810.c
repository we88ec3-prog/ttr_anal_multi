
int FUN_00408810(void)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  int in_EDX;
  
  iVar1 = *(int *)(in_EAX + 0xcc);
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = *(int **)(iVar1 + 0xa8);
  while( true ) {
    if (piVar2 == *(int **)(iVar1 + 0xac)) {
      return 0;
    }
    if (*(int *)(*piVar2 + 0x20) == in_EDX) break;
    piVar2 = piVar2 + 1;
  }
  return *piVar2;
}


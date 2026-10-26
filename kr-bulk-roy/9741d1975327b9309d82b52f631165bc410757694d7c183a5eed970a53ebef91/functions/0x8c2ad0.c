
int * FUN_008c2ad0(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  int in_EDX;
  
  piVar1 = *(int **)(in_ECX + 0x9c);
  piVar2 = piVar1 + (uint)*(ushort *)(in_ECX + 0x98) * 4;
  while( true ) {
    if (piVar2 <= piVar1) {
      return (int *)0x0;
    }
    if ((*piVar1 == in_EDX) && (piVar1[3] != 0)) break;
    piVar1 = piVar1 + 4;
  }
  return piVar1;
}


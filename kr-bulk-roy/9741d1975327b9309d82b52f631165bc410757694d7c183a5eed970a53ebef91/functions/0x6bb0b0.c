
void FUN_006bb0b0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x248);
  *(undefined4 *)(in_ECX + 0x24c) = 0;
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar4 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar4 == 0xbf6b) {
      iVar2 = *(int *)(iVar2 + 0x94);
      iVar4 = *(int *)(iVar2 + 0x10);
      if (iVar4 != 0) {
        piVar3 = *(int **)(iVar4 + 8);
        if (piVar3 != (int *)0x0) {
          piVar1 = piVar3 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar3 + 0x28))();
          }
        }
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
    }
  }
  return;
}


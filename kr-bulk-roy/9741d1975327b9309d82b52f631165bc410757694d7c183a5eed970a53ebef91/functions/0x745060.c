
void FUN_00745060(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int in_EAX;
  int iVar4;
  int in_ECX;
  
  if (in_EAX == 0) {
    if ((*(char *)(in_ECX + 0xa4) != '\0') && (*(int *)(in_ECX + 0x94) != 0)) {
      iVar4 = (**(code **)(**(int **)(in_ECX + 0x94) + 4))();
      if (iVar4 == 0xbf6b) {
        iVar4 = *(int *)(in_ECX + 0x94);
        iVar2 = *(int *)(iVar4 + 0x10);
        if (iVar2 != 0) {
          piVar3 = *(int **)(iVar2 + 8);
          if (piVar3 != (int *)0x0) {
            piVar1 = piVar3 + 0x27;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (**(code **)(*piVar3 + 0x28))();
            }
          }
          *(undefined4 *)(iVar4 + 0x10) = 0;
        }
      }
    }
  }
  else if ((*(char *)(in_ECX + 0xa4) != '\0') && (*(int *)(in_ECX + 0x94) != 0)) {
    iVar4 = (**(code **)(**(int **)(in_ECX + 0x94) + 4))();
    if (iVar4 == 0xbf6b) {
      FUN_0077b200();
      return;
    }
  }
  return;
}


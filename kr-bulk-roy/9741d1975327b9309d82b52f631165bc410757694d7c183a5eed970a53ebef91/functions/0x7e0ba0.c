
void FUN_007e0ba0(void)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(in_EAX + 0xc);
  iVar3 = 8;
  do {
    iVar1 = *piVar2;
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
      (**(code **)(**(int **)(iVar1 + 0x10) + 0x1c))();
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


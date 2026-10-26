
void FUN_007e0be0(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(in_EAX + 0xc);
  iVar2 = 8;
  do {
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      if (*(int *)(iVar1 + 0x10) != 0) {
        (**(code **)(**(int **)(iVar1 + 0x10) + 0x14))();
      }
      if (*(int *)(iVar1 + 4) != 0) {
        FUN_007f4bf0();
      }
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



void FUN_0062b8c0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x104);
  piVar2 = (int *)*piVar1;
  while (piVar2 != piVar1) {
    piVar4 = (int *)FUN_00831f50();
    iVar3 = *piVar4;
    *(undefined1 *)(*(int *)(iVar3 + 0x24c) + 600) = 1;
    *(undefined1 *)(*(int *)(iVar3 + 0x250) + 600) = 1;
    FUN_00628740();
  }
  return;
}


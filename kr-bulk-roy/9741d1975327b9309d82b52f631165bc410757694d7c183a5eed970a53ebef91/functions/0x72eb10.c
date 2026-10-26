
void FUN_0072eb10(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  char *pcVar5;
  int unaff_EDI;
  
  if (*(uint *)(param_1 + 0x34) < 0x10) {
    pcVar5 = (char *)(param_1 + 0x20);
  }
  else {
    pcVar5 = *(char **)(param_1 + 0x20);
  }
  pcVar3 = pcVar5;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar5,(int)pcVar3 - (int)(pcVar5 + 1));
  *(undefined4 *)(unaff_EDI + 0xc) = *(undefined4 *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 0x94);
  if (iVar2 != param_1 + 0x44) {
    do {
      if (iVar2 == 0) break;
      piVar4 = (int *)(iVar2 + 0x14);
      if (0xf < *(uint *)(iVar2 + 0x28)) {
        piVar4 = (int *)*piVar4;
      }
      FUN_0072e770(unaff_EDI,piVar4);
      iVar2 = *(int *)(iVar2 + 0x50);
    } while ((*(int *)(iVar2 + 0x40) != 0) || (*(int *)(iVar2 + 0x24) != 0));
  }
  for (piVar4 = *(int **)(param_1 + 0x18); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x10]) {
    (**(code **)(*piVar4 + 0x3c))();
    FUN_0072e0d0();
  }
  return;
}


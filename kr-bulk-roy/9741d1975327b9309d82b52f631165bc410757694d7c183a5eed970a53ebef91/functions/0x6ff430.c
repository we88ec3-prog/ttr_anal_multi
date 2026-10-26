
void FUN_006ff430(int param_1)

{
  char cVar1;
  int iVar2;
  char cVar3;
  lconv *plVar4;
  int iVar5;
  
  plVar4 = _localeconv();
  cVar1 = *(char *)(param_1 + 0x44);
  if (plVar4 == (lconv *)0x0) {
    cVar3 = '.';
  }
  else {
    cVar3 = *plVar4->decimal_point;
  }
  *(char *)(param_1 + 0x44) = cVar3;
  iVar5 = (*(int **)(param_1 + 0x3c))[1];
  iVar2 = **(int **)(param_1 + 0x3c);
  while (iVar5 != 0) {
    iVar5 = iVar5 + -1;
    if (*(char *)(iVar2 + iVar5) == cVar1) {
      *(char *)(iVar2 + iVar5) = cVar3;
    }
  }
  iVar5 = FUN_006f7760();
  if (iVar5 == 0) {
    iVar5 = (*(int **)(param_1 + 0x3c))[1];
    cVar1 = *(char *)(param_1 + 0x44);
    iVar2 = **(int **)(param_1 + 0x3c);
    while (iVar5 != 0) {
      iVar5 = iVar5 + -1;
      if (*(char *)(iVar2 + iVar5) == cVar1) {
        *(undefined1 *)(iVar2 + iVar5) = 0x2e;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(param_1,"malformed number",0x11c);
  }
  return;
}


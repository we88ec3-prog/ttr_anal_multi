
void FUN_0067e870(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  
  iVar1 = FUN_0067e570(unaff_ESI);
  if (iVar1 == 1) {
    FUN_0067ed20(param_1);
    return;
  }
  if (iVar1 == 2) {
    iVar1 = 0;
    piVar2 = (int *)(unaff_ESI + 0x17c);
    do {
      if ((piVar2[-1] == -1) || (*piVar2 == -1)) break;
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x16;
    } while (iVar1 < 3);
    FUN_0067f060(unaff_ESI,param_1);
  }
  return;
}


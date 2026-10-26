
void FUN_0059c510(void)

{
  char cVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar2 = (**(code **)(*unaff_ESI + 4))();
    if (iVar2 == 0x105b9) goto LAB_0059c53e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059c53e:
  cVar1 = FUN_006a9c30(*(undefined4 *)(unaff_EDI + 0x1bc),unaff_ESI[5]);
  if (cVar1 == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0059c560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x1bc) + 0xd0))();
  return;
}


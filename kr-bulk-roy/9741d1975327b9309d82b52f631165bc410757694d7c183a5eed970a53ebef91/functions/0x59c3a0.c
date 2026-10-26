
void FUN_0059c3a0(void)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar2 = (**(code **)(*unaff_ESI + 4))();
    if (iVar2 == 0x105ba) goto LAB_0059c3ce;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059c3ce:
  iVar2 = unaff_ESI[6];
  iVar1 = *(int *)(unaff_EDI + 0x17c);
  *(int *)(iVar1 + 0xf4) = unaff_ESI[5];
  *(int *)(iVar1 + 0xf8) = iVar2;
                    /* WARNING: Could not recover jumptable at 0x0059c3f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x17c) + 0xd0))();
  return;
}


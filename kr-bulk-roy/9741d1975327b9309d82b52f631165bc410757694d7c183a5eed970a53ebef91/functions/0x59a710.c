
void FUN_0059a710(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105ba) goto LAB_0059a73e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059a73e:
  if (*(int *)(unaff_EDI + 500) == 0) {
    return;
  }
  FUN_0061e4a0(*(int *)(unaff_EDI + 500),(char)unaff_ESI[5],(char)unaff_ESI[6]);
                    /* WARNING: Could not recover jumptable at 0x0059a766. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 500) + 0xd0))();
  return;
}


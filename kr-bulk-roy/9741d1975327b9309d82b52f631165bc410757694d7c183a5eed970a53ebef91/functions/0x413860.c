
void FUN_00413860(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  if ((unaff_ESI != (int *)0x0) && (iVar1 = (**(code **)(*unaff_ESI + 4))(), iVar1 != 0x105b9)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  FUN_007597b0(0);
                    /* WARNING: Could not recover jumptable at 0x004138b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x8c) + 200))();
  return;
}


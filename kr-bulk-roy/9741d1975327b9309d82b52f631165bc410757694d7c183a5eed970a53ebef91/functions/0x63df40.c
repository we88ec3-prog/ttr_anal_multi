
void FUN_0063df40(void)

{
  int *in_EAX;
  int iVar1;
  int unaff_EDI;
  
  if ((in_EAX != (int *)0x0) && (iVar1 = (**(code **)(*in_EAX + 4))(), iVar1 != 0x105b9)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  if (*(int *)(*(int *)(unaff_EDI + 0xec) + 0xcc) != 0) {
    FUN_0063d020();
  }
  FUN_00749920(*(undefined4 *)(unaff_EDI + 0xec));
                    /* WARNING: Could not recover jumptable at 0x0063dfa4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0xec) + 200))();
  return;
}


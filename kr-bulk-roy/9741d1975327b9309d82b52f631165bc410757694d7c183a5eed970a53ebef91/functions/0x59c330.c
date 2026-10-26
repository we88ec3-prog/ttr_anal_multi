
void FUN_0059c330(void)

{
  int *in_EAX;
  int iVar1;
  int unaff_EDI;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105c7) goto LAB_0059c361;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0059c361:
  FUN_00689880(in_EAX[5],in_EAX[7],in_EAX[9],in_EAX[10]);
                    /* WARNING: Could not recover jumptable at 0x0059c391. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x178) + 0xd0))();
  return;
}


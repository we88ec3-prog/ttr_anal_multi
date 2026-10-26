
void FUN_0059d240(void)

{
  int *in_EAX;
  int iVar1;
  int unaff_EDI;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105ba) goto LAB_0059d271;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0059d271:
  iVar1 = in_EAX[5];
  if ((0 < iVar1) && (iVar1 < 6)) {
    if ((-1 < (int)(iVar1 - 1U)) &&
       (iVar1 - 1U <
        (uint)(*(int *)(*(int *)(unaff_EDI + 0x168) + 0x108) -
               *(int *)(*(int *)(unaff_EDI + 0x168) + 0x104) >> 2))) {
      FUN_005f6130(in_EAX[6] == 0);
    }
                    /* WARNING: Could not recover jumptable at 0x0059d2c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_EDI + 0x168) + 0x1b0))();
    return;
  }
  return;
}


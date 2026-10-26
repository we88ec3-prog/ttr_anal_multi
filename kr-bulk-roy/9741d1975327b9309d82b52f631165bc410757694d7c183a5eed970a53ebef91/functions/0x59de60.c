
void FUN_0059de60(void)

{
  int *in_EAX;
  int iVar1;
  int unaff_EDI;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105b9) goto LAB_0059de91;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0059de91:
  if ((*(uint *)(*(int *)(unaff_EDI + 0x210) + 0x28) >> 8 & 1) == 0) {
    FUN_0040b5b0(in_EAX[5]);
                    /* WARNING: Could not recover jumptable at 0x0059decb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_EDI + 0x210) + 0xd0))();
    return;
  }
  FUN_0040b5b0(in_EAX[5]);
  return;
}


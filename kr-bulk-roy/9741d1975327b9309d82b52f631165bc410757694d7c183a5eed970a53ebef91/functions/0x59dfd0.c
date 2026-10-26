
void FUN_0059dfd0(void)

{
  int *in_EAX;
  int iVar1;
  int *unaff_EDI;
  
  if ((in_EAX != (int *)0x0) && (iVar1 = (**(code **)(*in_EAX + 4))(), iVar1 != 0x105ba)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  (**(code **)(*unaff_EDI + 0x19c))(0x11);
  FUN_00477740(unaff_EDI[0x7e]);
  FUN_00596e00(unaff_EDI,unaff_EDI[0x7e]);
  return;
}


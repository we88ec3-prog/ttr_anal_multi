
void FUN_0059a490(void)

{
  int *in_EAX;
  int iVar1;
  int *unaff_EDI;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105b9) goto LAB_0059a4bd;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0059a4bd:
  (**(code **)(*unaff_EDI + 0x19c))(0xb);
  FUN_0066b120(unaff_EDI[0x73],in_EAX[5]);
  return;
}


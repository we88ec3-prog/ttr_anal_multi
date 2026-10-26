
void FUN_0069ca20(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105bd) goto LAB_0069ca4e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0069ca4e:
  *(int *)(unaff_EDI + 0x14c) = *(int *)(unaff_EDI + 0x144) * 0xf + unaff_ESI[5];
  return;
}


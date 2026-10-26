
int * FUN_0040afc0(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105b9) {
      return unaff_ESI;
    }
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  return (int *)0x0;
}


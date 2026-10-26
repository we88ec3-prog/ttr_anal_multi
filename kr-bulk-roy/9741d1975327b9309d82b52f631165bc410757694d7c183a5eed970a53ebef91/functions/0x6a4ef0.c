
void FUN_006a4ef0(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105b9) goto LAB_006a4f1e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_006a4f1e:
  switch(unaff_ESI[5]) {
  case 0:
    FUN_006a4820();
    return;
  case 1:
    FUN_006a4a60();
    return;
  case 2:
    FUN_006a48e0();
    return;
  case 3:
    FUN_006a49a0();
    return;
  default:
    return;
  }
}


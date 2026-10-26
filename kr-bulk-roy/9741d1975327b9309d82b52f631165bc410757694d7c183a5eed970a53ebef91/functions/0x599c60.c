
void FUN_00599c60(void)

{
  int iVar1;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_EDI + 4))();
    if (iVar1 == 0x105b9) goto LAB_00599c8e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_EDI = (int *)0x0;
LAB_00599c8e:
  *(int *)(*(int *)(unaff_ESI + 0x180) + 0xf8) = unaff_EDI[5];
  *(undefined4 *)(*(int *)(unaff_ESI + 0x180) + 0xf4) = 2;
  FUN_00597040(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x180),1,1);
  return;
}


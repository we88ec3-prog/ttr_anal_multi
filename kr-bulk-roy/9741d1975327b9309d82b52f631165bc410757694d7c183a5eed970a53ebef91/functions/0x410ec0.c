
void FUN_00410ec0(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  
  if (in_EAX == (int *)0x0) {
LAB_00410ef1:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_00410ef1;
    }
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105ba) goto LAB_00410f24;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_00410f24:
  if (in_EAX[5] != 0x6a7) {
    if (in_EAX[5] == 0x6a8) {
      FUN_0075cd30(*(undefined4 *)(unaff_ESI + 0xf8));
      (**(code **)(**(int **)(unaff_ESI + 0xf8) + 200))();
    }
    return;
  }
  *(char *)(unaff_ESI + 0x145) = (char)piVar2[5];
  *(int *)(unaff_ESI + 0x15c) = piVar2[6];
  FUN_0075cd30(*(undefined4 *)(unaff_ESI + 0xf8));
  (**(code **)(**(int **)(unaff_ESI + 0xf8) + 200))();
  FUN_00410af0();
  return;
}


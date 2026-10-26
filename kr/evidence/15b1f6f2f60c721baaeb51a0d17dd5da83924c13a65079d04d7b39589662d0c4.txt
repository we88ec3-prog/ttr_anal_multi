
void FUN_005b6b70(void)

{
  int in_EAX;
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105be) goto LAB_005b6ba1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005b6ba1:
  FUN_00636520(unaff_ESI[5],0,0);
  FUN_0074a010(*(undefined4 *)(in_EAX + 0x224));
  FUN_00596e00(in_EAX,*(undefined4 *)(in_EAX + 0x224));
  return;
}


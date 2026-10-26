
void FUN_005b7670(int *param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if ((unaff_ESI != (int *)0x0) && (iVar1 = (**(code **)(*unaff_ESI + 4))(), iVar1 != 0x105b9)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  FUN_0045def0();
  (**(code **)(*param_1 + 0x19c))(0xc);
  FUN_00596e00(param_1,param_1[0xa5]);
  return;
}


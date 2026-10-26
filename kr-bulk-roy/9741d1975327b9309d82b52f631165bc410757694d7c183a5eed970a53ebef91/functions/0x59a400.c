
void FUN_0059a400(void)

{
  int *in_EAX;
  int iVar1;
  int *unaff_EDI;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105ca) goto LAB_0059a434;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0059a434:
  if (in_EAX[6] != 0 || in_EAX[7] != 0) {
    (**(code **)(*unaff_EDI + 0x19c))();
    FUN_0066af30(in_EAX[6],in_EAX[7]);
    return;
  }
  (**(code **)(*unaff_EDI + 0x19c))(0xb);
  (**(code **)(*(int *)unaff_EDI[0x73] + 0xd0))();
  return;
}



void FUN_0059ce80(int param_1)

{
  char cVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  
  if (in_EAX != (int *)0x0) {
    iVar2 = (**(code **)(*in_EAX + 4))();
    if (iVar2 == 0x105ba) goto LAB_0059ceb6;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0059ceb6:
  iVar2 = in_EAX[5];
  if (((0 < iVar2) && (iVar3 = (**(code **)(**(int **)(param_1 + 0x168) + 0x1ac))(), iVar2 <= iVar3)
      ) && (cVar1 = FUN_005f5f90(), cVar1 != '\0')) {
    FUN_005fd3c0();
  }
  return;
}


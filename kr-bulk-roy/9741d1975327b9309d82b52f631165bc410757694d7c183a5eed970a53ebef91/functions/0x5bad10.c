
void FUN_005bad10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  
  if (in_EAX != (int *)0x0) {
    iVar3 = (**(code **)(*in_EAX + 4))();
    if (iVar3 == 0x105ba) goto LAB_005bad46;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005bad46:
  iVar3 = in_EAX[6];
  iVar1 = in_EAX[5];
  uVar2 = *(undefined4 *)(param_1 + 0x29c);
  iVar4 = FUN_0045c050(uVar2,iVar3);
  if (iVar4 != 1) {
    if (iVar4 == 2) {
      FUN_0045be00(uVar2,iVar1,iVar3);
    }
    return;
  }
  FUN_0045b4c0(uVar2);
  return;
}


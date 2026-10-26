
void FUN_005baae0(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *in_EAX;
  int iVar4;
  
  if (in_EAX != (int *)0x0) {
    iVar4 = (**(code **)(*in_EAX + 4))();
    if (iVar4 == 0x105ba) goto LAB_005bab16;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005bab16:
  iVar4 = in_EAX[6];
  iVar1 = in_EAX[5];
  iVar2 = *(int *)(param_1 + 600);
  cVar3 = FUN_00481e60(iVar2,*(int *)(iVar2 + 0x130) != -1);
  if (cVar3 != '\0') {
    if (*(int *)(iVar2 + 0x130) == -1) {
      FUN_00481250(iVar1,iVar4);
      FUN_00481320();
      return;
    }
    FUN_00481180(iVar1,iVar4);
  }
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005978d0(int param_1)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  HWND hWnd;
  undefined4 extraout_ECX;
  UINT Msg;
  WPARAM wParam;
  undefined4 uVar3;
  LPARAM lParam;
  undefined2 local_6;
  
  if (in_EAX == (int *)0x0) {
LAB_00597909:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_00597909;
    }
  }
  if (in_EAX[5] != 0x6a7) goto LAB_0059797a;
  piVar2 = (int *)in_EAX[6];
  if (piVar2 == (int *)0x0) {
LAB_0059793d:
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 != 0x105b9) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0059793d;
    }
  }
  if (piVar2[5] == 1) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_6 = 0x44;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_6,2);
      *(undefined4 *)(param_1 + 0x130) = 0;
      return;
    }
  }
  else {
    if (piVar2[5] != 2) {
      iVar1 = FUN_00422f40();
      if (*(int *)(iVar1 + 0x28) == 1) {
        uVar3 = 1;
        FUN_00422f40(extraout_ECX,1);
        FUN_005624b0(uVar3);
      }
      lParam = 1;
      wParam = 0;
      Msg = 0x10;
      hWnd = (HWND)FUN_006dfd60();
      PostMessageW(hWnd,Msg,wParam,lParam);
LAB_0059797a:
      *(undefined4 *)(param_1 + 0x130) = 0;
      return;
    }
    iVar1 = FUN_0041a4d0();
    if (*(int *)(iVar1 + 0x5ed8) != 0) {
      iVar1 = FUN_0041a4d0();
      if (*(int *)(iVar1 + 0x5ed8) != 0) {
        FUN_0053ba20();
      }
      *(undefined4 *)(param_1 + 0x130) = 0;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x130) = 0;
  return;
}



void FUN_005a69e0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1[4] == 0xf42ef) {
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 != 0x105b9) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    FUN_00665150(param_1[5]);
    (**(code **)(**(int **)(in_ECX + 0x13c) + 0xd0))();
  }
  return;
}


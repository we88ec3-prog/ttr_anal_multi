
void FUN_005ab5b0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 == 0x105b9) goto LAB_005ab5e8;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  param_1 = (int *)0x0;
LAB_005ab5e8:
  *(int *)(*(int *)(in_ECX + 0x168) + 0x108) = param_1[5];
  (**(code **)(**(int **)(in_ECX + 0x168) + 0xd0))();
  return;
}


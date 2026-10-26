
void FUN_0040d370(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_005cee00(param_1);
  if (param_1[4] == 0xf42d1) {
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 != 0x105cf) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
    FUN_0040df20(*(undefined4 *)(in_ECX + 0x380));
  }
  return;
}


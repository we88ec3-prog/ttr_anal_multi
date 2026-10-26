
void FUN_0059dd70(int param_1)

{
  int iVar1;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009451fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0x105bd) goto LAB_0059ddc0;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_0059ddc0:
  if ((int *)in_ECX[6] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)in_ECX[6] + 4))();
    if (iVar1 != 0x105b9) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
  }
  if (in_ECX[5] == 0x6a7) {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_8 = 0;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_8 = 0xffffffff;
    }
    if (DAT_00fb7258 != 0) {
      FUN_0053ba20();
    }
    (**(code **)(**(int **)(param_1 + 0x204) + 0xd4))();
  }
  ExceptionList = local_10;
  return;
}


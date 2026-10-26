
void FUN_0059d2d0(int *param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933726;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 != 0x105bf) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      ExceptionList = local_10;
      return;
    }
    if (param_1[6] != 0) {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_8 = 0;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_8 = 0xffffffff;
      }
      FUN_008438c0();
      if (((in_ECX != DAT_00f8d91c) && (*(int *)(in_ECX + 0x10) != 0)) &&
         (iVar1 = *(int *)(*(int *)(in_ECX + 0x10) + 0x54), iVar1 != 0)) {
        if (*(int *)(iVar1 + 8) == 0x1d) {
          iVar1 = FUN_00891268();
          if (iVar1 != 0) {
            FUN_00753d00();
          }
          FUN_00404aa0();
          FUN_00750020();
        }
        else if ((param_1[7] == 0) && (*(int *)(iVar1 + 0x11c) != 0)) {
          FUN_004054c0();
          FUN_00402250();
          local_8 = 1;
          FUN_00402110(iVar1 + 0x10c);
          local_8 = 0xffffffff;
          FUN_0058b270(0xca);
          ExceptionList = local_10;
          return;
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}


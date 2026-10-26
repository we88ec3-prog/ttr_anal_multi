
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00604490(void)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  undefined2 local_1e;
  int local_1c;
  undefined1 local_18;
  undefined2 local_17;
  int local_15;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094344c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX == (int *)0x0) {
LAB_006044e2:
    in_ECX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006044e2;
    }
  }
  piVar2 = (int *)in_ECX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105b9) goto LAB_0060450d;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_0060450d:
  if (in_ECX[5] == 0x6a7) {
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_8 = 0;
      FUN_004fdac0();
      _atexit(FUN_00bce150);
      local_8 = 0xffffffff;
    }
    iVar1 = piVar2[5];
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_17 = 0x4a;
    local_11 = 0;
    if (DAT_00fba798 == 0) {
      local_15 = iVar1;
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_17,7);
    }
    _DAT_00fc7b6c = 2;
    ExceptionList = local_10;
    return;
  }
  if (in_ECX[5] == 0x6a8) {
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_8 = 1;
      FUN_004fdac0();
      _atexit(FUN_00bce150);
      local_8 = 0xffffffff;
    }
    iVar1 = piVar2[5];
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_1e = 0x4a;
    local_18 = 1;
    if (DAT_00fba798 == 0) {
      local_1c = iVar1;
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1e,7);
    }
    _DAT_00fc7b6c = 0;
  }
  ExceptionList = local_10;
  return;
}


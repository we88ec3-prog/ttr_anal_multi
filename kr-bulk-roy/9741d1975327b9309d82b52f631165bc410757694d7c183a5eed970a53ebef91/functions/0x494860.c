
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00494860(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093114a;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xbfd4) = 1;
  if ((DAT_00fc18fc & 1) == 0) {
    DAT_00fc18fc = DAT_00fc18fc | 1;
    local_8 = 0;
    FUN_005548f0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcdcd0);
  }
  local_8 = 0xffffffff;
  FUN_005550e0(&DAT_00fc1900,(int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 4));
  timeGetTime();
  piVar1 = (int *)(in_ECX + 8);
  (**(code **)(*(int *)(in_ECX + 8) + 0x38))(piVar1);
  (**(code **)(**(int **)(in_ECX + 0x18) + 0x44))(*(int **)(in_ECX + 0x18),0,0,0,0);
  (**(code **)(*piVar1 + 0x38))(piVar1);
  (**(code **)(**(int **)(in_ECX + 0x18) + 0x44))(*(int **)(in_ECX + 0x18),0,0,0,0);
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  if (DAT_00fd2cd0 != (int *)0x0) {
    if ((_DAT_00fd2cf0 & 1) == 0) {
      _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
      FUN_00738090();
      _atexit((_func_4879 *)&DAT_00bce680);
    }
    (**(code **)(*DAT_00fd2cd0 + 8))();
  }
  FUN_006dfc40();
  iVar3 = FUN_006dfc40();
  iVar3 = FUN_007347f0(*(undefined4 *)(iVar3 + 0x18));
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  if (iVar3 != 0) {
    _DAT_00fd2cd4 = 1;
  }
  _DAT_00fd2cd8 = DAT_00fd2ce0;
  _DAT_00fd2cdc = DAT_00fd2ce4;
  DAT_00fd2cd0 = (int *)iVar3;
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  _DAT_00fd2cec = 1;
  timeGetTime();
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_8 = 1;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    local_8 = 0xffffffff;
  }
  FUN_006d9680();
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_8 = 2;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    local_8 = 0xffffffff;
  }
  FUN_006d9780();
  ExceptionList = local_10;
  return 0x100;
}


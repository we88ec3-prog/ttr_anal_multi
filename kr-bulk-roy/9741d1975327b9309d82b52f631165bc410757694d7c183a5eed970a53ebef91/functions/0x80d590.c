
int FUN_0080d590(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int in_ECX;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  undefined *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091858a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8 = 0;
    FUN_0080a3a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccdd0);
  }
  local_18 = &DAT_00fab09c;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fab09c);
  local_8 = 1;
  if (DAT_00fab028 == (int *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fab09c);
  }
  else {
    piVar1 = (int *)(**(code **)(*DAT_00fab028 + 0x1c))();
    local_8 = 0xffffffff;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fab09c);
    if (piVar1 != (int *)0x0) {
      if ((DAT_00fe3414 & 1) == 0) {
        DAT_00fe3414 = DAT_00fe3414 | 1;
        local_8 = 2;
        FUN_0080f520();
        _atexit(FUN_00bd0c40);
        local_8 = 0xffffffff;
      }
      if (DAT_00fe342c != 0) {
        FUN_0080f5b0(&DAT_00fe341c,local_1c,in_ECX + 0x18);
      }
      (**(code **)(*piVar1 + 0x14))(*(undefined4 *)(in_ECX + 0x3c));
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        local_8 = 3;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        local_8 = 0xffffffff;
      }
      iVar2 = FUN_0080be60(in_ECX,piVar1);
      if (iVar2 != 0) {
        InterlockedIncrement((LONG *)(iVar2 + 0x24));
        (**(code **)(*piVar1 + 8))();
        *(undefined4 *)(local_14 + 0x34) = 600;
        local_2c = *param_1;
        local_28 = param_1[1];
        local_24 = param_1[2];
        local_34 = 0;
        local_20 = param_2;
        local_30 = iVar2;
        lpCriticalSection = (LPCRITICAL_SECTION)FUN_0080a2e0();
        EnterCriticalSection(lpCriticalSection);
        local_8 = 4;
        FUN_0080cdb0(&local_34);
        LeaveCriticalSection(lpCriticalSection);
      }
      ExceptionList = local_10;
      return iVar2;
    }
  }
  ExceptionList = local_10;
  return 0;
}


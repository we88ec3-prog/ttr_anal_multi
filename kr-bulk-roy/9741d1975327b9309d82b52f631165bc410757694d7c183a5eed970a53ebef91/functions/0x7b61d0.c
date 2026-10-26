
void FUN_007b61d0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 *local_c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
  param_2[1] = *(undefined4 *)(param_1 + 0x94);
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
  local_10 = *param_2;
  local_c = param_2;
  uVar1 = FUN_0057ef20();
  FUN_007b71b0(&local_10,uVar1);
  local_10 = param_2[1];
  local_c = (undefined4 *)param_3;
  uVar1 = FUN_0057ef20();
  FUN_007b71b0(&local_10,uVar1);
  local_c = (undefined4 *)param_2[1];
  local_10 = param_3;
  uVar1 = FUN_0057ef20();
  FUN_007b71b0(&local_10,uVar1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
  return;
}


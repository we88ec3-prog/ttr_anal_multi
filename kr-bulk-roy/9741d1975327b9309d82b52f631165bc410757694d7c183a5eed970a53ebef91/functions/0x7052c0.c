
undefined4 FUN_007052c0(int param_1)

{
  int iVar1;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  FUN_006f6590("string",&PTR_DAT_00c0bca0);
  iVar1 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"gmatch",6);
  local_10 = 4;
  FUN_006fb850(param_1,iVar1 + -0x10,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar1 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"gfind",5);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar1 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  FUN_007051d0();
  return 1;
}


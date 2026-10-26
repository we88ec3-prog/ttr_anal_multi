
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007028d0(int param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  FUN_006f6590(&DAT_00c4286c,&PTR_DAT_00c0bd20);
  puVar1 = *(undefined8 **)(param_1 + 8);
  *puVar1 = 0x400921fb54442d18;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar2 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,&DAT_00c4315c,2);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar2 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  uVar3 = _DAT_00d61ef0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 8);
  *puVar1 = uVar3;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar2 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,&DAT_00c43160,4);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar2 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  iVar2 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,&DAT_00c430e0,4);
  local_10 = 4;
  FUN_006fb850(param_1,iVar2 + -0x10,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar2 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,&DAT_00c43168,3);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar2 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return 1;
}


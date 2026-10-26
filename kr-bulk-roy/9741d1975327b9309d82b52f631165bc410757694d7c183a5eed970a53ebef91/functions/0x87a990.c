
undefined4 FUN_0087a990(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090dfd8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_4[7] = *(undefined4 *)(param_5 + 0x40);
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0xffffffff;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  piVar1 = *(int **)(param_1 + 4);
  iVar2 = *piVar1;
  uVar4 = (**(code **)(iVar2 + 0xec))(piVar1,*(undefined4 *)(param_5 + 0x40),uVar3);
  (**(code **)(iVar2 + 0x38))(piVar1,uVar4);
  local_2c = FUN_0087af70(param_1 + 0x70);
  local_28 = param_4[3];
  local_18 = param_4[7];
  local_34 = *param_4;
  local_30 = 0;
  FUN_00863260(param_3 + 0x28,&local_34);
  FUN_008630f0(param_3,param_1,param_2);
  ExceptionList = local_10;
  return 1;
}



undefined4 FUN_006fe990(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_1c [4];
  undefined4 local_18;
  int local_10;
  
  local_18 = 0;
  local_10 = 0;
  uVar3 = FUN_006fe770(FUN_006fe860,local_1c,*(int *)(param_1 + 8) - *(int *)(param_1 + 0x20));
  iVar2 = local_10;
  iVar1 = *(int *)(param_1 + 0x10);
  (**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 0x10),local_18,local_10,0);
  *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) - iVar2;
  return uVar3;
}



undefined4 FUN_00706400(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int local_24 [2];
  undefined4 local_1c;
  undefined4 local_18;
  code *local_14;
  int *local_10;
  int local_c;
  
  local_24[0] = FUN_006f6210(param_1);
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar1 < *(undefined4 **)(param_1 + 8)) && (puVar1 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    FUN_006f6210(param_1);
  }
  local_10 = local_24;
  local_c = param_1;
  local_14 = FUN_006f70e0;
  local_1c = 0;
  local_18 = 0;
  iVar2 = FUN_006fe990(param_1);
  if (iVar2 == 0) {
    return 1;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_006f52b0();
  return 2;
}


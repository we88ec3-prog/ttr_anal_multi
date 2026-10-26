
void FUN_0066b910(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_4c;
  int *local_48;
  uint local_40;
  uint local_34;
  undefined4 local_30 [7];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093cfa8;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  FUN_0066c720(local_30,DAT_00fe1b54 + 8);
  local_c = 0;
  FUN_004d8460(uVar1);
  if (*(int *)(param_1 + 0xfc) != *(int *)(param_1 + 0x100)) {
    uVar2 = FUN_0066d440(*(int *)(param_1 + 0x100),local_4c);
    FUN_005aa000(*(undefined4 *)(param_1 + 0x100));
    *(undefined4 *)(param_1 + 0x100) = uVar2;
  }
  FUN_00542210();
  for (; local_40 != local_34; local_40 = local_40 + 1) {
    if (local_48 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *local_48;
    }
    uVar1 = local_40;
    if (*(uint *)(iVar3 + 8) <= local_40) {
      uVar1 = local_40 - *(uint *)(iVar3 + 8);
    }
    FUN_0066c830(param_1 + 0xfc,*(undefined4 *)(*(int *)(iVar3 + 4) + uVar1 * 4));
  }
  FUN_0066ba20(param_1);
  FUN_0066bbd0(param_1);
  FUN_004c4240();
  FUN_0089120c(local_30[0]);
  ExceptionList = local_14;
  return;
}


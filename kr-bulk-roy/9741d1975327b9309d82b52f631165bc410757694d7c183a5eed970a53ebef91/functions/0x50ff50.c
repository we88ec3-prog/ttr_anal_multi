
void FUN_0050ff50(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,undefined4 param_8,undefined4 param_9,int param_10)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uStack_60;
  undefined1 local_4c [24];
  undefined1 local_34 [24];
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d410;
  local_10 = ExceptionList;
  uStack_60 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  iVar1 = FUN_00542210();
  uVar3 = param_4 - *(int *)(iVar1 + 8);
  local_18 = *(uint *)(param_1 + 0x10);
  if (param_7 != param_10) {
    local_1c = uVar3;
    if (local_18 >> 1 < uVar3) {
      local_8 = 2;
      for (; param_7 != param_10; param_7 = param_7 + 1) {
        FUN_00804260();
      }
      FUN_004d8460();
      FUN_00542210();
      FUN_0050b4b0();
      FUN_00542210(uVar3);
      FUN_0050b4b0(uVar3);
      puVar2 = local_34;
    }
    else {
      local_8 = 0;
      for (; param_7 != param_10; param_7 = param_7 + 1) {
        FUN_004f07f0();
      }
      FUN_00542210();
      FUN_0050b4b0();
      FUN_00542210();
      FUN_005101d0();
      FUN_00542210();
      FUN_0050b4b0();
      FUN_0050b4b0();
      FUN_00542210();
      FUN_0050b4b0();
      FUN_00542210();
      puVar2 = local_4c;
    }
    FUN_00510230(puVar2);
  }
  ExceptionList = local_10;
  return;
}


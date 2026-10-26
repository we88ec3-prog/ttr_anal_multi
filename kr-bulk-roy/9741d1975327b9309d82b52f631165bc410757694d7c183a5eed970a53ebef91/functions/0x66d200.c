
void FUN_0066d200(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,undefined4 param_8,undefined4 param_9,int param_10)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uStack_80;
  undefined1 local_70 [36];
  undefined1 local_4c [48];
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090cc00;
  local_10 = ExceptionList;
  uStack_80 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_80;
  ExceptionList = &local_10;
  iVar1 = FUN_00542210();
  uVar2 = param_4 - *(int *)(iVar1 + 8);
  local_1c = *(uint *)(param_1 + 0x10);
  if (param_7 != param_10) {
    local_18 = uVar2;
    if (local_1c >> 1 < uVar2) {
      local_8 = 2;
      for (; param_7 != param_10; param_7 = param_7 + 1) {
        FUN_00507ba0();
      }
      local_8 = 0xffffffff;
      FUN_004d8460();
      FUN_00542210();
      FUN_0050b4b0();
      FUN_00542210(uVar2);
      FUN_0050b4b0(uVar2);
      puVar3 = local_70;
    }
    else {
      local_8 = 0;
      for (; param_7 != param_10; param_7 = param_7 + 1) {
        FUN_0066d7c0();
      }
      local_8 = 0xffffffff;
      FUN_00542210();
      FUN_0050b4b0();
      FUN_00542210();
      FUN_0066d8f0();
      FUN_00542210();
      FUN_0050b4b0();
      FUN_0050b4b0();
      FUN_00542210();
      FUN_0050b4b0();
      FUN_00542210();
      puVar3 = local_4c;
    }
    FUN_0066d950(puVar3);
  }
  ExceptionList = local_10;
  return;
}


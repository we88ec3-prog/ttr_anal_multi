
void FUN_005e7cc0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091659d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 0;
    FUN_00523540(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
  }
  local_8 = 0xffffffff;
  local_30 = *(undefined4 *)(in_ECX + 0x1a0);
  FUN_008438c0(&local_30);
  if ((local_2c != DAT_00f8d9b0) && (iVar1 = *(int *)(local_2c + 0x10), iVar1 != 0)) {
    local_14 = *(undefined4 *)(iVar1 + 0x1c);
    local_18 = *(undefined4 *)(iVar1 + 0x34);
    uVar4 = *(undefined4 *)(iVar1 + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x1a8);
    local_24 = *(int *)(in_ECX + 0x1ac);
    local_30 = uVar4;
    iVar2 = FUN_00409560();
    FUN_004dd400(iVar2,&local_2c,&local_28);
    if ((local_2c != *(int *)(iVar2 + 4)) && (*(int *)(local_2c + 0x18) != 0)) {
      iVar2 = *(int *)(*(int *)(local_2c + 0x18) + 0x30);
      local_20 = 0;
      local_24 = 0;
      local_2c = 0;
      local_1c = iVar2;
      if ((DAT_00fc1b00 & 1) == 0) {
        DAT_00fc1b00 = DAT_00fc1b00 | 1;
        local_8 = 2;
        FUN_00829b30();
        _atexit(FUN_00bce3e0);
        local_8 = 0xffffffff;
      }
      iVar3 = FUN_008295e0(*(undefined4 *)(iVar1 + 0x20),iVar2,&local_20);
      if (iVar3 != 0) {
        local_20 = *(int *)(iVar1 + 0x24) * iVar2;
        local_14 = FUN_008fed10();
      }
      if ((DAT_00fc1b00 & 1) == 0) {
        DAT_00fc1b00 = DAT_00fc1b00 | 1;
        local_8 = 3;
        FUN_00829b30();
        _atexit(FUN_00bce3e0);
        local_8 = 0xffffffff;
      }
      iVar3 = FUN_008295e0(*(undefined4 *)(iVar1 + 0x38),iVar2,&local_24);
      if (iVar3 != 0) {
        local_24 = *(int *)(iVar1 + 0x3c) * iVar2;
        local_18 = FUN_008fed10();
      }
      if ((DAT_00fc1b00 & 1) == 0) {
        DAT_00fc1b00 = DAT_00fc1b00 | 1;
        local_8 = 4;
        FUN_00829b30();
        _atexit(FUN_00bce3e0);
      }
      iVar3 = FUN_008295e0(*(undefined4 *)(iVar1 + 0x50),iVar2,&local_2c);
      if (iVar3 != 0) {
        local_2c = *(int *)(iVar1 + 0x54) * iVar2;
        uVar4 = FUN_008fed10();
      }
    }
    *param_1 = local_14;
    *param_2 = local_18;
    *param_3 = uVar4;
    ExceptionList = local_10;
    return;
  }
  *param_1 = 0;
  *param_2 = 0;
  *param_3 = 0;
  ExceptionList = local_10;
  return;
}


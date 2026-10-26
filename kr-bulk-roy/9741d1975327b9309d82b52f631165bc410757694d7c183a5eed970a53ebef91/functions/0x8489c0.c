
void FUN_008489c0(undefined1 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uStack_98;
  uint local_7c [4];
  undefined4 local_6c;
  uint local_68;
  undefined4 local_60 [4];
  undefined4 local_50;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28 [4];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00911497;
  local_10 = ExceptionList;
  uStack_98 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_98;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_98;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_68 = 0xf;
    local_6c = 0;
    local_7c[0] = local_7c[0] & 0xffffff00;
    local_30 = 7;
    _memset(local_60,0,0x34);
    local_40 = 0x3f800000;
    local_50 = 0x3f800000;
    local_60[0] = 0x3f800000;
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_8._0_1_ = 2;
    if (param_1 != (undefined1 *)0x0) {
      *(undefined4 *)(param_1 + 0x14) = 0xf;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *param_1 = 0;
      FUN_00403040(local_7c,0,0xffffffff);
      local_8._0_1_ = 3;
      puVar2 = local_60;
      puVar3 = (undefined4 *)(param_1 + 0x1c);
      for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      *(undefined4 *)(param_1 + 0x50) = local_2c;
      FUN_00848e90(param_1 + 0x54,local_28);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_28[0] != 0) {
      FUN_0089120c(local_28[0]);
    }
    if (0xf < local_68) {
      FUN_0089120c(local_7c[0]);
    }
    param_1 = param_1 + 100;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a3980(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined1 auStack_5c [4];
  float local_58;
  undefined4 *local_54;
  int *local_50;
  undefined **local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093f78e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  ExceptionList = &local_14;
  FUN_00596010(DAT_00d61f20 ^ (uint)&stack0xffffff98);
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_4c = FUI::CFXUIBinder::vftable;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  FUN_005a5af0();
  FUN_005a9f40(in_ECX + 0x148);
  local_54 = (undefined4 *)(in_ECX + 0x140);
  FUN_005a5bd0();
  FUN_005a9f40((undefined4 *)(in_ECX + 0x140));
  FUN_005a5cb0();
  FUN_005a9f40(in_ECX + 0x144);
  local_50 = (int *)(in_ECX + 0x14c);
  FUN_005a5d90();
  FUN_005a9f40((int *)(in_ECX + 0x14c));
  FUN_005a5e70();
  FUN_005a9f40(in_ECX + 0x150);
  FUN_0040b670(in_ECX);
  local_58 = 0.0;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*local_54);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 3;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*(undefined4 *)(in_ECX + 0x144));
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 4;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058ee60(&DAT_00faaf80);
  FUN_00644900();
  FUN_00641b40();
  piVar1 = *(int **)(*local_50 + 0xf4);
  piVar1[0x31] = (int)local_58;
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(*piVar1 + 200))();
  FUN_006477c0();
  FUN_00647be0();
  local_58 = (float)(int)local_58;
  uVar3 = DAT_00f94390 & 1;
  *(float *)(in_ECX + 0x160) = local_58 / 100.0;
  if (uVar3 == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 5;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c._0_1_ = 1;
  }
  _DAT_00f942a0 = local_58;
  local_58 = 1.96182e-44;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 6;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058ee60(&DAT_00faaf80);
  fVar4 = local_58;
  iVar2 = *local_50;
  *(float *)(iVar2 + 0x104) = local_58;
  puVar5 = (undefined4 *)FUN_00412df0();
  local_c._0_1_ = 7;
  iVar2 = *(int *)(iVar2 + 0xfc);
  if (*(int *)(iVar2 + 0x24c) != 0) {
    if (7 < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    FUN_0075cc70(iVar2,puVar5);
  }
  local_c = CONCAT31(local_c._1_3_,1);
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  FUN_00645420(fVar4);
  local_4c = FoxUI::FXUIBinderBase::vftable;
  if (local_48 != 0) {
    FUN_0089120c(local_48);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_5c);
  return;
}


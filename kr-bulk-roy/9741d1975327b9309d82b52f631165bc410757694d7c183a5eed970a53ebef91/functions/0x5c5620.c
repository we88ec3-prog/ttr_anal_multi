
void FUN_005c5620(int param_1)

{
  void *pvVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  undefined4 ***pppuVar5;
  int iVar6;
  void *local_74;
  int *local_70;
  void *local_6c;
  void *local_68;
  int *local_64;
  int local_60;
  int local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  int local_38;
  undefined4 **local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091aad0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_005c72f0(&local_58);
  if (local_58 == *(uint *)(in_ECX + 8)) {
    local_6c = _malloc(0x18);
    iVar6 = 0;
    local_8 = 0;
    if (local_6c != (void *)0x0) {
      iVar6 = FUN_00763ba0(uVar2);
    }
    local_8 = 0xffffffff;
    local_54 = (uint)local_54._2_2_ << 0x10;
    local_40 = 7;
    local_44 = 0;
    local_5c = iVar6;
    FUN_004026e0(param_1,0,0xffffffff);
    local_8 = 1;
    local_38 = iVar6;
    uVar3 = FUN_0044fc70(&local_54);
    FUN_005c78c0(in_ECX + 4,&local_74,uVar3);
    local_8 = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
  }
  else {
    local_5c = *(int *)(local_58 + 0x28);
  }
  local_58 = 0;
  if (*(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 5 != 0) {
    local_60 = 0;
    do {
      piVar4 = (int *)(local_60 + *(int *)(param_1 + 0x1c));
      pvVar1 = (void *)*piVar4;
      local_34[0] = (undefined4 **)((uint)local_34[0] & 0xffff0000);
      local_20 = 7;
      local_24 = 0;
      FUN_004026e0(piVar4 + 1,0,0xffffffff);
      local_8 = 2;
      local_68 = _malloc(0xa0);
      local_8._0_1_ = 3;
      if (local_68 == (void *)0x0) {
        local_64 = (int *)0x0;
      }
      else {
        pppuVar5 = (undefined4 ***)local_34[0];
        if (local_20 < 8) {
          pppuVar5 = local_34;
        }
        local_64 = (int *)FUN_00763060(local_68,pppuVar5);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      local_68 = pvVar1;
      FUN_0082ef00(&local_68);
      if (local_6c == *(void **)(local_5c + 0xc)) {
        local_64[3] = (int)pvVar1;
        local_70 = local_64;
        local_74 = pvVar1;
        uVar3 = FUN_0057ef20();
        FUN_0082f200(local_5c + 8,uVar3);
      }
      else if (local_64 != (int *)0x0) {
        (**(code **)(*local_64 + 0x1c))(1);
      }
      local_8 = 0xffffffff;
      if (7 < local_20) {
        FUN_0089120c(local_34[0]);
      }
      local_60 = local_60 + 0x20;
      local_58 = local_58 + 1;
    } while (local_58 < (uint)(*(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 5));
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


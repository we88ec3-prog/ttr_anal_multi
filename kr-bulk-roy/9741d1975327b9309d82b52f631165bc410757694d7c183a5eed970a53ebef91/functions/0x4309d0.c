
void FUN_004309d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 ushort param_5,char param_6)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined4 *puVar3;
  uint local_74;
  uint local_70;
  undefined4 local_6c;
  undefined4 local_64;
  uint local_60;
  _Lockit local_5c [8];
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_38 [5];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00917be0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_74;
  ExceptionList = &local_14;
  local_74 = (uint)param_5;
  local_64 = param_1;
  if ((*(uint *)(param_4 + 0x14) & 0x4000) == 0) {
    (**(code **)(*in_ECX + 0x1c))
              (param_1,param_2,param_3,param_4,local_74,param_6,
               DAT_00d61f20 ^ (uint)&stack0xffffff80);
  }
  else {
    uVar2 = FUN_004318d0(&local_60);
    local_c = 0;
    local_6c = FUN_00430690(uVar2);
    local_c = 0xffffffff;
    if (local_60 != 0) {
      local_70 = local_60;
      std::_Lockit::_Lockit(local_5c,0);
      iVar1 = *(int *)(local_60 + 4);
      if ((iVar1 != 0) && (iVar1 != -1)) {
        *(int *)(local_60 + 4) = iVar1 + -1;
      }
      iVar1 = *(int *)(local_60 + 4);
      FUN_0087dd6f();
      puVar3 = (undefined4 *)(~-(uint)(iVar1 != 0) & local_70);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
    }
    local_40 = 7;
    local_44 = 0;
    local_54 = (uint)local_54._2_2_ << 0x10;
    local_c = 1;
    if (param_6 == '\0') {
      uVar2 = FUN_006ef8b0(local_38);
      local_c._0_1_ = 3;
      FUN_00402800(uVar2);
    }
    else {
      uVar2 = FUN_006ef8d0(local_38);
      local_c._0_1_ = 2;
      FUN_00402800(uVar2);
    }
    local_c = CONCAT31(local_c._1_3_,1);
    if (7 < uStack_24) {
      FUN_0089120c(local_38[0]);
    }
    if ((*(uint *)(param_4 + 0x14) & 0x1c0) != 0x40) {
      FUN_00430960();
    }
    FUN_00430890();
    *(undefined4 *)(param_4 + 0x20) = 0;
    *(undefined4 *)(param_4 + 0x24) = 0;
    FUN_00430960();
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_74);
  return;
}


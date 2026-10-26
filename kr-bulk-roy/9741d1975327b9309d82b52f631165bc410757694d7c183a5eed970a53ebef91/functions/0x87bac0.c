
void FUN_0087bac0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 auStack_104 [4];
  int local_100;
  int *local_fc;
  undefined4 local_f8;
  int *local_f4;
  int local_f0;
  int local_ec;
  int local_e8 [4];
  undefined4 local_d8 [30];
  undefined4 local_60 [17];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00904c6b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_104;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffef0;
  ExceptionList = &local_14;
  local_f8 = param_3;
  local_fc = param_2;
  local_100 = param_5;
  if ((((param_4 != 0) && (param_2 != (int *)0x0)) && (param_5 != 0)) &&
     (local_f4 = *(int **)(param_5 + 0x38), local_f4 != (int *)0x0)) {
    local_e8[0] = 0;
    local_e8[1] = 0;
    local_e8[2] = 0;
    local_c = 0;
    local_f0 = (local_f4[1] - *local_f4) / 0x34;
    if (local_f0 != 0) {
      local_ec = param_5 + 4;
      iVar3 = 0;
      local_100 = local_f0;
      do {
        FUN_007e7dd0(*local_f4 + iVar3);
        FUN_0079c530();
        puVar4 = local_d8;
        puVar5 = local_60;
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        FUN_0087d930(local_e8);
        iVar3 = iVar3 + 0x34;
        local_100 = local_100 + -1;
      } while (local_100 != 0);
      local_100 = 0;
    }
    iVar3 = local_e8[0];
    if (local_f0 == 0) {
      if (local_e8[0] != 0) {
        FUN_0089120c(local_e8[0],uVar1);
      }
    }
    else {
      (**(code **)(*local_fc + 0xa0))(local_fc,local_f8,local_e8[0],local_f0);
      if (iVar3 != 0) {
        FUN_0089120c(iVar3,uVar1);
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_104);
  return;
}


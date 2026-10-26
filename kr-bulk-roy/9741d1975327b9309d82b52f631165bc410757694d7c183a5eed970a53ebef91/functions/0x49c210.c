
void FUN_0049c210(undefined4 *param_1,undefined4 param_2)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  short *psVar6;
  uint uVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b1b8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = param_2;
  uVar7 = 0;
  local_38 = 10;
  local_14 = uVar3;
  iVar4 = FUN_00466df0(param_1,&local_38,1);
  if (iVar4 != -1) {
    local_38 = 10;
    do {
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      local_8 = 0;
      puVar5 = param_1;
      if (7 < (uint)param_1[5]) {
        puVar5 = (undefined4 *)*param_1;
      }
      FUN_00402160((int)puVar5 + uVar7 * 2,iVar4 - uVar7);
      FUN_0049c120(uVar3);
      local_8 = 0xffffffff;
      uVar7 = iVar4 + 1;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      iVar4 = FUN_00466df0(param_1,&local_38,1);
    } while (iVar4 != -1);
  }
  if (uVar7 < (uint)param_1[4]) {
    local_1c = 7;
    local_20 = 0;
    local_30 = (uint)local_30._2_2_ << 0x10;
    local_8 = 1;
    if (7 < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    psVar1 = (short *)((int)param_1 + uVar7 * 2);
    psVar6 = psVar1;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar1,(int)psVar6 - (int)(psVar1 + 1) >> 1);
    FUN_0049c120(uVar3);
  }
  else {
    if (param_1[4] != uVar7) goto LAB_0049c379;
    local_1c = 7;
    local_20 = 0;
    local_30 = (uint)local_30._2_2_ << 0x10;
    local_8 = 2;
    FUN_0049c120(uVar3);
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
LAB_0049c379:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


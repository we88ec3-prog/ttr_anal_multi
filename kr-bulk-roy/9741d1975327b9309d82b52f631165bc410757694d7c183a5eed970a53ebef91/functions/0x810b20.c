
void FUN_00810b20(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined1 local_34 [4];
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928338;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar8 = 0;
  local_34[0] = 0x3d;
  local_14 = uVar3;
  uVar9 = FUN_00440930(param_1,local_34,1);
  uVar6 = (undefined4)((ulonglong)uVar9 >> 0x20);
  iVar7 = (int)uVar9;
  if (iVar7 != -1) {
    local_34[0] = 0x3d;
    do {
      local_1c = 0xf;
      local_20 = 0;
      local_30 = local_30 & 0xffffff00;
      local_8 = 0;
      puVar4 = param_1;
      if (0xf < (uint)param_1[5]) {
        puVar4 = (undefined4 *)*param_1;
      }
      FUN_00402a70((int)puVar4 + uVar8,iVar7 - uVar8);
      FUN_00440c60(uVar3);
      local_8 = 0xffffffff;
      uVar8 = iVar7 + 1;
      if (0xf < local_1c) {
        FUN_0089120c(local_30);
      }
      uVar9 = FUN_00440930(param_1,local_34,1);
      uVar6 = (undefined4)((ulonglong)uVar9 >> 0x20);
      iVar7 = (int)uVar9;
    } while (iVar7 != -1);
  }
  if (uVar8 < (uint)param_1[4]) {
    local_1c = 0xf;
    local_20 = 0;
    local_30 = (uint)local_30._1_3_ << 8;
    local_8 = 1;
    if (0xf < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    pcVar1 = (char *)((int)param_1 + uVar8);
    pcVar5 = pcVar1;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70(pcVar1,(int)pcVar5 - (int)(pcVar1 + 1));
    FUN_00440c60(uVar3);
    uVar6 = extraout_EDX;
  }
  else {
    if (param_1[4] != uVar8) goto LAB_00810c72;
    local_1c = 0xf;
    local_20 = 0;
    local_30 = (uint)local_30._1_3_ << 8;
    local_8 = 2;
    FUN_00440c60(uVar3);
    uVar6 = extraout_EDX_00;
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30);
    uVar6 = extraout_EDX_01;
  }
LAB_00810c72:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar6,param_2);
  return;
}


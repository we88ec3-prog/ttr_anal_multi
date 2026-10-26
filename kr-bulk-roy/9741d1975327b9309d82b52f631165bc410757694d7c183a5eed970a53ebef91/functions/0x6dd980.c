
void FUN_006dd980(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
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
  puStack_c = &LAB_009289d0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar7 = 0;
  local_34[0] = 0x3b;
  local_14 = uVar2;
  uVar9 = FUN_00440930(param_1,local_34,1);
  uVar6 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar3 = (uint)uVar9;
  if (uVar3 != 0xffffffff) {
    local_34[0] = 0x3b;
    do {
      if (uVar7 != uVar3) {
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        local_8 = 0;
        puVar4 = param_1;
        if (0xf < (uint)param_1[5]) {
          puVar4 = (undefined4 *)*param_1;
        }
        FUN_00402a70((int)puVar4 + uVar7,uVar3 - uVar7);
        FUN_00440c60(uVar2);
        local_8 = 0xffffffff;
        if (0xf < local_1c) {
          FUN_0089120c(local_30);
        }
      }
      uVar7 = uVar3 + 1;
      uVar9 = FUN_00440930(param_1,local_34,1);
      uVar6 = (undefined4)((ulonglong)uVar9 >> 0x20);
      uVar3 = (uint)uVar9;
    } while (uVar3 != 0xffffffff);
  }
  if (uVar7 < (uint)param_1[4]) {
    local_1c = 0xf;
    local_20 = 0;
    local_30 = local_30 & 0xffffff00;
    local_8 = 1;
    if (0xf < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    pcVar8 = (char *)(uVar7 + (int)param_1);
    pcVar5 = pcVar8;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar8,(int)pcVar5 - (int)(pcVar8 + 1));
    FUN_00440c60(uVar2);
    uVar6 = extraout_EDX;
    if (0xf < local_1c) {
      FUN_0089120c(local_30);
      uVar6 = extraout_EDX_00;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar6,param_2);
  return;
}


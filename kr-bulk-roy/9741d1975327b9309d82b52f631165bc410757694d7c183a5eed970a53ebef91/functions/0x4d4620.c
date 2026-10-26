
void FUN_004d4620(undefined4 param_1,short *param_2,undefined4 param_3)

{
  short sVar1;
  void **ppvVar2;
  uint uVar3;
  short *psVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int local_38;
  uint local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b176;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  psVar4 = param_2;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  uVar5 = (int)psVar4 - (int)(param_2 + 1) >> 1;
  local_14 = uVar3;
  ppvVar2 = &local_10;
  local_34 = uVar5;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar2, 0 < (int)uVar5) {
    uVar6 = FUN_0087dc3d(-(uint)((int)((ulonglong)local_34 * 4 >> 0x20) != 0) |
                         (uint)((ulonglong)local_34 * 4),uVar3);
    iVar10 = 0;
    local_38 = 0;
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 0;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_8 = 0xffffffff;
    }
    iVar7 = (**(code **)(*DAT_00fb7b78 + 0x38))(param_1,param_2,param_3,uVar6,&local_38);
    if ((iVar7 == 0) || (local_38 = local_38 + -1, local_38 < 0)) break;
    iVar7 = -1;
    iVar8 = 0;
    if (0 < local_38) {
      do {
        if (param_2[iVar8] == 0x20) {
          iVar10 = iVar8;
        }
        if ((iVar7 == -1) && (param_2[iVar8] == 10)) {
          iVar7 = iVar8;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < local_38);
    }
    FUN_00891d3d(uVar6);
    uVar9 = local_38 + 1;
    if ((uVar9 != local_34) && (iVar10 != 0)) {
      uVar9 = iVar10 + 1;
    }
    if ((iVar7 != -1) && ((int)(iVar7 + 1U) <= (int)uVar9)) {
      uVar9 = iVar7 + 1U;
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    local_8 = 1;
    FUN_00402160(param_2,uVar9);
    FUN_0049c120();
    uVar5 = local_34 - uVar9;
    for (param_2 = param_2 + uVar9; (*param_2 != 0 && (*param_2 == 0x20)); param_2 = param_2 + 1) {
      uVar5 = uVar5 - 1;
    }
    local_8 = 0xffffffff;
    ppvVar2 = ExceptionList;
    local_34 = uVar5;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
      ppvVar2 = ExceptionList;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


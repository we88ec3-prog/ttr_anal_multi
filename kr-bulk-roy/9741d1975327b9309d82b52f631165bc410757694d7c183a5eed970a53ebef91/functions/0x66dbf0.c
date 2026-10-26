
void FUN_0066dbf0(int param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 uint param_6)

{
  undefined4 *puVar1;
  int iVar2;
  void **ppvVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  int local_a4;
  int local_a0;
  int local_9c;
  uint local_98;
  uint local_90;
  int local_8c;
  int local_88;
  uint local_80;
  int local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60 [15];
  int local_24 [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090cbd8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_6c = param_4 - param_2;
  iVar5 = local_6c;
  local_68 = param_6 - param_2;
  while (iVar2 = iVar5, iVar2 != 0) {
    iVar5 = local_68 % iVar2;
    local_68 = iVar2;
  }
  ppvVar3 = &local_10;
  uVar6 = local_70;
  iVar5 = local_74;
  if (local_68 < (int)(param_6 - param_2)) {
    for (; local_74 = iVar5, local_70 = uVar6, ExceptionList = ppvVar3, 0 < local_68;
        local_68 = local_68 + -1) {
      local_90 = local_68 + param_2;
      uVar6 = local_6c + local_90;
      local_7c = param_1;
      uVar8 = local_90;
      if (uVar6 == param_6) {
        local_74 = param_1;
        local_70 = param_2;
        iVar5 = local_74;
        uVar6 = local_70;
      }
      else {
        local_9c = param_1;
        local_74 = param_1;
        local_98 = uVar6;
        iVar5 = local_74;
      }
      do {
        local_70 = uVar6;
        local_74 = iVar5;
        uVar6 = local_70;
        if (*(uint *)(local_74 + 8) <= local_70) {
          uVar6 = local_70 - *(uint *)(local_74 + 8);
        }
        if (*(uint *)(local_7c + 8) <= uVar8) {
          uVar8 = uVar8 - *(uint *)(local_7c + 8);
        }
        local_80 = *(undefined4 *)(*(int *)(local_74 + 4) + uVar6 * 4);
        puVar1 = *(undefined4 **)(*(int *)(local_7c + 4) + uVar8 * 4);
        local_64 = *puVar1;
        puVar9 = local_60;
        puVar7 = puVar1;
        for (iVar5 = 0xf; puVar7 = puVar7 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar9 = *puVar7;
          puVar9 = puVar9 + 1;
        }
        FUN_00507f70(local_24,puVar1 + 0x10);
        uVar6 = local_80;
        local_8 = 0;
        FUN_0066d490(puVar1);
        FUN_0066d490(uVar6);
        local_8 = 0xffffffff;
        if (local_24[0] != 0) {
          FUN_0089120c(local_24[0]);
        }
        local_78 = local_70;
        local_7c = local_74;
        if (local_6c < (int)(param_6 - local_70)) {
          local_80 = local_70;
          local_a0 = local_70 + local_6c;
          local_a4 = local_74;
          piVar4 = &local_a4;
        }
        else {
          local_88 = (param_2 - (param_6 - local_70)) + local_6c;
          local_80 = param_2;
          local_8c = param_1;
          piVar4 = &local_8c;
        }
        uVar6 = piVar4[1];
        uVar8 = local_70;
        iVar5 = *piVar4;
      } while (uVar6 != local_90);
      ppvVar3 = ExceptionList;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


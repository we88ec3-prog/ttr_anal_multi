
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00799d20(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 local_11c [18];
  undefined4 local_d4 [19];
  undefined4 local_88 [4];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_54 [6];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009325ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  local_8 = 0xffffffff;
  puVar5 = (undefined4 *)(DAT_00fb76a8 + 0x54);
  puVar7 = local_11c;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  puVar5 = (undefined4 *)(DAT_00fb76a8 + 0x98);
  puVar7 = local_88;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  local_54[0] = local_88[0];
  local_54[1] = local_88[1];
  local_54[2] = local_88[2];
  local_54[3] = 0;
  local_54[4] = local_88[3];
  local_54[5] = local_78;
  iVar3 = *(int *)(param_1 + 0x14);
  local_3c = local_74;
  local_38 = 0;
  local_34 = local_70;
  local_30 = local_6c;
  local_2c = local_68;
  local_28 = 0;
  local_24 = local_64;
  local_20 = local_60;
  local_1c = local_5c;
  local_18 = 0x3f800000;
  puVar5 = local_54;
  puVar7 = local_d4;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  if (iVar3 != 0) {
    iVar3 = **(int **)(param_1 + 0x14);
    uVar2 = FUN_008fed10();
    (**(code **)(iVar3 + 0x1c))(uVar2);
    FUN_00780150(*(int *)(param_1 + 0x14),*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x30));
  }
  uVar2 = FUN_00838210(local_d4);
  FUN_00838430(uVar2);
  _DAT_00fba93c = param_2;
  _memset(local_54 + 4,0,0x34);
  local_24 = 0x3f800000;
  local_34 = 0x3f800000;
  local_54[4] = 0x3f800000;
  FUN_00790b40();
  FUN_00780890();
  piVar1 = *(int **)(param_1 + 0x9c);
  uVar8 = 0;
  uVar6 = piVar1[1] - *piVar1 >> 2;
  if (uVar6 != 0) {
    do {
      (**(code **)(**(int **)(*piVar1 + uVar8 * 4) + 0x18))(param_2);
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar6);
  }
  ExceptionList = local_10;
  return;
}


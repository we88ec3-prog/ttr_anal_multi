
undefined4 * FUN_0084aa40(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *local_2c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar3 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918248;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007846f0(param_1);
  *param_1 = gbParticleSystem::vftable;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x25] = 0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  if (param_1[0x1d] != param_1[0x1e]) {
    uVar5 = FUN_0084b880(param_1[0x1e],param_1,uVar4);
    FUN_0084b900(uVar5,param_1[0x1e],param_1);
    param_1[0x1e] = uVar5;
  }
  iVar6 = *(int *)(param_2 + 0x74);
  iVar8 = *(int *)(param_2 + 0x78) - iVar6;
  local_14 = 0;
  iVar2 = iVar8 >> 0x1f;
  if (iVar8 / 0x14 + iVar2 != iVar2) {
    param_2 = 0;
    do {
      local_2c = (int *)0x0;
      local_8._0_1_ = 4;
      piVar7 = *(int **)(iVar6 + param_2);
      if (piVar7 != (int *)0x0) {
        iVar6 = (**(code **)(*piVar7 + 8))();
        if (iVar6 == 0) {
          piVar7 = (int *)(**(code **)(*piVar7 + 0xc))();
        }
        piVar7[1] = piVar7[1] + 1;
        local_2c = piVar7;
      }
      FUN_0084b470();
      local_8._0_1_ = 6;
      if (local_2c != (int *)0x0) {
        piVar7 = local_2c + 1;
        *piVar7 = *piVar7 + -1;
        if (*piVar7 == 0) {
          (**(code **)*local_2c)(1);
        }
      }
      _free((void *)0x0);
      param_2 = param_2 + 0x14;
      local_8._0_1_ = 3;
      iVar6 = *(int *)(iVar3 + 0x74);
      local_14 = local_14 + 1;
    } while (local_14 < (uint)((*(int *)(iVar3 + 0x78) - iVar6) / 0x14));
  }
  puVar1 = (undefined4 *)param_1[0x25];
  if (puVar1 != *(undefined4 **)(iVar3 + 0x94)) {
    if (puVar1 != (undefined4 *)0x0) {
      piVar7 = puVar1 + 1;
      *piVar7 = *piVar7 + -1;
      if (*piVar7 == 0) {
        (**(code **)*puVar1)(1);
      }
    }
    piVar7 = *(int **)(iVar3 + 0x94);
    param_1[0x25] = piVar7;
    if (piVar7 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar7 + 8))();
      if (iVar6 == 0) {
        uVar5 = (**(code **)(*(int *)param_1[0x25] + 0xc))();
        param_1[0x25] = uVar5;
      }
      *(int *)(param_1[0x25] + 4) = *(int *)(param_1[0x25] + 4) + 1;
    }
  }
  param_1[0x26] = *(undefined4 *)(iVar3 + 0x98);
  param_1[0x27] = *(undefined4 *)(iVar3 + 0x9c);
  param_1[0x29] = *(undefined4 *)(iVar3 + 0xa4);
  uVar5 = *(undefined4 *)(iVar3 + 0xa8);
  param_1[0x28] = 0;
  param_1[0x2a] = uVar5;
  param_1[0x2b] = *(undefined4 *)(iVar3 + 0xac);
  param_1[0x2c] = *(undefined4 *)(iVar3 + 0xb0);
  param_1[0x2d] = *(undefined4 *)(iVar3 + 0xb4);
  param_1[9] = 0;
  ExceptionList = local_10;
  return param_1;
}


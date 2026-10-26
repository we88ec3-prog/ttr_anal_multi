
undefined4 * FUN_0077ecb0(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined1 local_1c [4];
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915403;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0077fed0(param_1);
  *param_1 = gbNode::vftable;
  param_1[0x15] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = *(undefined4 *)(param_2 + 0x60);
  param_1[0x19] = *(undefined4 *)(param_2 + 100);
  *param_1 = gbTransformNode::vftable;
  puVar2 = (undefined4 *)(param_2 + 0x68);
  puVar3 = param_1 + 0x1a;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)(param_2 + 0x94);
  puVar3 = param_1 + 0x25;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  puVar2 = param_1 + 0x36;
  *puVar2 = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  local_8 = 2;
  local_14 = *(undefined4 *)(param_2 + 0xdc);
  local_18 = *(undefined4 *)(param_2 + 0xd8);
  FUN_00860810(puVar2,local_1c,*puVar2,param_1[0x37]);
  FUN_0077fae0(*puVar2,local_18,local_14,param_2);
  uVar4 = *(int *)(param_2 + 0xcc) - *(int *)(param_2 + 200) >> 2;
  FUN_0077f820(uVar4);
  local_14 = 0;
  if (uVar4 != 0) {
    do {
      iVar1 = (**(code **)(**(int **)(*(int *)(param_2 + 200) + local_14 * 4) + 0xc))();
      *(undefined4 **)(iVar1 + 0x54) = param_1;
      *(int *)(param_1[0x32] + local_14 * 4) = iVar1;
      local_14 = local_14 + 1;
    } while (local_14 < uVar4);
  }
  ExceptionList = local_10;
  return param_1;
}



undefined4 * FUN_007dcac0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *local_8;
  
  uVar2 = *(uint *)(param_1 + 0x20);
  uVar6 = FUN_005525e0();
  uVar6 = uVar6 & uVar2;
  if (*(uint *)(param_1 + 0x24) <= uVar6) {
    uVar6 = uVar6 + (-1 - (uVar2 >> 1));
  }
  puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x10) + uVar6 * 8);
  iVar1 = *(int *)(param_1 + 0x10) + uVar6 * 8;
  puVar4 = *(undefined4 **)(param_1 + 4);
  puVar10 = puVar3;
  do {
    puVar8 = puVar4;
    if (puVar3 != puVar4) {
      puVar8 = (undefined4 *)**(undefined4 **)(iVar1 + 4);
    }
    if (puVar10 == puVar8) goto LAB_007dcc0d;
    uVar2 = *(uint *)(param_3 + 0x10);
    uVar6 = puVar10[6];
    uVar7 = uVar6;
    if (uVar2 <= uVar6) {
      uVar7 = uVar2;
    }
    uVar7 = FUN_00407e70(uVar7);
    if (uVar7 == 0) {
      if (uVar2 <= uVar6) {
        uVar7 = (uint)(uVar6 != uVar2);
        goto LAB_007dcb5d;
      }
    }
    else {
LAB_007dcb5d:
      local_8 = puVar10;
      if (-1 < (int)uVar7) break;
    }
    puVar10 = (undefined4 *)*puVar10;
  } while( true );
LAB_007dcb88:
  puVar8 = puVar4;
  if (puVar3 != puVar4) {
    puVar8 = (undefined4 *)**(undefined4 **)(iVar1 + 4);
  }
  if (local_8 == puVar8) {
LAB_007dcbf2:
    if (puVar10 != local_8) {
      *param_2 = puVar10;
      param_2[1] = local_8;
      return param_2;
    }
LAB_007dcc0d:
    uVar5 = *(undefined4 *)(param_1 + 4);
    *param_2 = uVar5;
    param_2[1] = uVar5;
    return param_2;
  }
  uVar6 = local_8[6];
  uVar7 = *(uint *)(param_3 + 0x10);
  if (uVar2 < *(uint *)(param_3 + 0x10)) {
    uVar7 = uVar2;
  }
  uVar9 = uVar7;
  if (uVar6 <= uVar7) {
    uVar9 = uVar6;
  }
  uVar9 = FUN_00407e70(uVar9);
  if (uVar9 == 0) {
    if (uVar7 < uVar6) goto LAB_007dcbf2;
    uVar9 = (uint)(uVar7 != uVar6);
  }
  if ((int)uVar9 < 0) goto LAB_007dcbf2;
  local_8 = (undefined4 *)*local_8;
  goto LAB_007dcb88;
}


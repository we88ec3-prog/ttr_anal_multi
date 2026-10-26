
/* WARNING: Removing unreachable block (ram,0x00552471) */
/* WARNING: Removing unreachable block (ram,0x005524d3) */

void FUN_00552400(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_EAX;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *local_8;
  
  uVar2 = *(uint *)(in_EAX + 0x20);
  uVar5 = FUN_005525e0();
  uVar5 = uVar5 & uVar2;
  if (*(uint *)(in_EAX + 0x24) <= uVar5) {
    uVar5 = uVar5 + (-1 - (uVar2 >> 1));
  }
  puVar3 = *(undefined4 **)(in_EAX + 4);
  piVar1 = (int *)(*(int *)(in_EAX + 0x10) + uVar5 * 8);
  puVar4 = (undefined4 *)*piVar1;
  local_8 = puVar4;
  do {
    puVar6 = puVar3;
    if (puVar4 != puVar3) {
      puVar6 = *(undefined4 **)piVar1[1];
    }
    if (local_8 == puVar6) {
      *param_1 = (int)puVar3;
      return;
    }
    uVar2 = *(uint *)(param_2 + 0x10);
    uVar5 = local_8[6];
    uVar7 = uVar5;
    if (uVar2 <= uVar5) {
      uVar7 = uVar2;
    }
    uVar7 = FUN_00407e70(uVar7);
    if (uVar7 == 0) {
      if (uVar2 <= uVar5) {
        uVar7 = (uint)(uVar5 != uVar2);
        goto LAB_0055249d;
      }
    }
    else {
LAB_0055249d:
      if (-1 < (int)uVar7) break;
    }
    local_8 = (undefined4 *)*local_8;
  } while( true );
  uVar2 = local_8[6];
  uVar5 = *(uint *)(param_2 + 0x10);
  uVar7 = uVar5;
  if (uVar2 <= uVar5) {
    uVar7 = uVar2;
  }
  uVar7 = FUN_00407e70(uVar7);
  if (uVar7 == 0) {
    if (uVar5 < uVar2) goto LAB_00552504;
    uVar7 = (uint)(uVar5 != uVar2);
  }
  if (-1 < (int)uVar7) {
    *param_1 = (int)local_8;
    return;
  }
LAB_00552504:
  *param_1 = (int)puVar3;
  return;
}



int FUN_008bcd10(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  uint uVar10;
  bool bVar11;
  uint local_8;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0x21;
  }
  if (param_2 == (byte *)0x0) {
    return 6;
  }
  if (0x20005 < *(int *)(param_2 + 0x10)) {
    return 4;
  }
  local_8 = 0;
  if (param_1[4] != 0) {
    puVar8 = param_1 + 5;
    do {
      piVar2 = (int *)*puVar8;
      pbVar6 = *(byte **)(*piVar2 + 8);
      pbVar9 = *(byte **)(param_2 + 8);
      do {
        bVar1 = *pbVar6;
        bVar11 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_008bcd90:
          iVar7 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_008bcd95;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar11 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_008bcd90;
        pbVar6 = pbVar6 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar7 = 0;
LAB_008bcd95:
      if (iVar7 == 0) {
        if (*(int *)(param_2 + 0xc) <= *(int *)(*piVar2 + 0xc)) {
          return 5;
        }
        FUN_008bc0d0(param_1,piVar2);
        break;
      }
      local_8 = local_8 + 1;
      puVar8 = puVar8 + 1;
    } while (local_8 < (uint)param_1[4]);
  }
  uVar3 = *param_1;
  local_8 = 0;
  if (0x1f < (uint)param_1[4]) {
    return 0x30;
  }
  puVar8 = (undefined4 *)FUN_008baee0(uVar3,*(undefined4 *)(param_2 + 4),&local_8);
  uVar10 = local_8;
  if (local_8 == 0) {
    puVar8[1] = param_1;
    puVar8[2] = uVar3;
    *puVar8 = param_2;
    if ((*param_2 & 2) != 0) {
      iVar7 = FUN_008bbfc0();
      if (iVar7 != 0) goto LAB_008bce77;
      uVar10 = 0;
    }
    if ((*(byte *)*puVar8 & 4) != 0) {
      param_1[0x28] = puVar8;
    }
    puVar4 = (uint *)*puVar8;
    if (((*puVar4 & 1) != 0) && (puVar8[3] = puVar4, (*puVar4 & 0x200) == 0)) {
      iVar7 = FUN_008bb050(uVar3,puVar8 + 6);
      if (iVar7 != 0) goto LAB_008bce77;
      uVar10 = 0;
    }
    if (*(code **)(param_2 + 0x18) != (code *)0x0) {
      iVar7 = (**(code **)(param_2 + 0x18))(puVar8);
      if (iVar7 != 0) {
LAB_008bce77:
        if (((*(uint *)*puVar8 & 1) != 0) && ((*(uint *)*puVar8 & 0x200) == 0)) {
          FUN_008ba2a0(puVar8[6]);
        }
        if (((((*(byte *)*puVar8 & 2) != 0) && (iVar5 = puVar8[3], iVar5 != 0)) &&
            (*(int *)(iVar5 + 0x24) == 0x6f75746c)) && (puVar8[0xd] != 0)) {
          (**(code **)(*(int *)(iVar5 + 0x38) + 0x14))(puVar8[0xd]);
        }
        FUN_008b9f80(uVar3,puVar8);
        return iVar7;
      }
      uVar10 = 0;
    }
    param_1[param_1[4] + 5] = puVar8;
    param_1[4] = param_1[4] + 1;
  }
  return uVar10;
}


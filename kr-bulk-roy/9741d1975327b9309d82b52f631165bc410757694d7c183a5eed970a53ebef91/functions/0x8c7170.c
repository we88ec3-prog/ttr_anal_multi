
int FUN_008c7170(int param_1,short param_2,undefined4 *param_3)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  undefined2 *puVar8;
  int iVar9;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_c;
  bool local_5;
  
  uVar4 = *(undefined4 *)(param_1 + 100);
  puVar1 = *(undefined2 **)(param_1 + 0x164);
  local_14 = (uint)*(ushort *)(param_1 + 0x154);
  local_c = 0;
  local_1c = -1;
  local_18 = -1;
  iVar9 = -1;
  local_20 = -1;
  local_5 = false;
  iVar6 = -1;
  puVar8 = puVar1;
  if (*(ushort *)(param_1 + 0x154) != 0) {
    iVar5 = 0;
    do {
      iVar6 = local_18;
      if ((puVar8[3] == param_2) && (puVar8[4] != 0)) {
        switch(*puVar8) {
        case 0:
        case 2:
          local_20 = iVar5;
          break;
        case 1:
          iVar6 = iVar5;
          if ((puVar8[2] != 0) && (iVar6 = local_18, puVar8[1] == 0)) {
            local_1c = iVar5;
          }
          break;
        case 3:
          if (((iVar9 == -1) || ((puVar8[2] & 0x3ff) == 9)) &&
             (((ushort)puVar8[1] < 2 || (puVar8[1] == 10)))) {
            local_5 = (puVar8[2] & 0x3ff) == 9;
            iVar9 = iVar5;
          }
        }
      }
      local_18 = iVar6;
      iVar5 = iVar5 + 1;
      puVar8 = puVar8 + 10;
      local_14 = local_14 - 1;
      iVar6 = local_18;
    } while (local_14 != 0);
  }
  if (-1 < iVar6) {
    local_1c = iVar6;
  }
  pcVar7 = (code *)0x0;
  if ((iVar9 < 0) || ((-1 < local_1c && (local_5 == false)))) {
    if (-1 < local_1c) {
      puVar8 = puVar1 + local_1c * 10;
      pcVar7 = FUN_008c7100;
      goto LAB_008c72a2;
    }
    if (local_20 < 0) goto LAB_008c72a2;
    puVar8 = puVar1 + local_20 * 10;
  }
  else {
    puVar8 = puVar1 + iVar9 * 10;
    if ((1 < (ushort)puVar1[iVar9 * 10 + 1]) && (puVar1[iVar9 * 10 + 1] != 10)) goto LAB_008c72a2;
  }
  pcVar7 = FUN_008c7080;
LAB_008c72a2:
  if (puVar8 == (undefined2 *)0x0) {
    *param_3 = 0;
    return 0;
  }
  if (pcVar7 == (code *)0x0) {
    *param_3 = 0;
    return 0;
  }
  if (*(int *)(puVar8 + 8) == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x168);
    uVar3 = FUN_008bc7d0(uVar4,1,0,puVar8[4],0,&local_c);
    *(undefined4 *)(puVar8 + 8) = uVar3;
    if (((local_c != 0) || (local_c = FUN_008b97e0(uVar2,*(undefined4 *)(puVar8 + 6)), local_c != 0)
        ) || (local_c = FUN_008bab70(uVar2,*(undefined4 *)(puVar8 + 8),puVar8[4]), local_c != 0)) {
      FUN_008b9f80(uVar4,*(undefined4 *)(puVar8 + 8));
      *(undefined4 *)(puVar8 + 8) = 0;
      puVar8[4] = 0;
      *param_3 = 0;
      return local_c;
    }
  }
  uVar4 = (*pcVar7)(puVar8,uVar4);
  *param_3 = uVar4;
  return local_c;
}


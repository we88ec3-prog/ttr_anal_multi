
int * FUN_007c6430(int *param_1,byte *param_2,undefined4 *param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  uint local_8;
  
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  pbVar3 = (byte *)(param_1 + 2);
  pbVar8 = param_2;
  if (0xf < (uint)param_1[7]) {
    pbVar3 = *(byte **)pbVar3;
  }
  do {
    bVar1 = *pbVar3;
    bVar13 = bVar1 < *pbVar8;
    if (bVar1 != *pbVar8) {
LAB_007c6473:
      iVar4 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      goto LAB_007c6478;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar13 = bVar1 < pbVar8[1];
    if (bVar1 != pbVar8[1]) goto LAB_007c6473;
    pbVar3 = pbVar3 + 2;
    pbVar8 = pbVar8 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_007c6478:
  if (iVar4 == 0) {
    return param_1;
  }
  uVar9 = param_1[0x37] - param_1[0x36] >> 2;
  local_8 = 0;
  if (uVar9 != 0) {
    do {
      piVar5 = (int *)FUN_0077f090();
      iVar4 = (**(code **)(*piVar5 + 4))();
      if (*(int *)(iVar4 + 4) == -0x5edf0000) {
        uVar12 = 0;
        uVar10 = piVar5[0x23] - piVar5[0x22] >> 2;
        if (uVar10 != 0) {
          do {
            piVar2 = *(int **)(piVar5[0x22] + uVar12 * 4);
            piVar6 = piVar2 + 2;
            if (0xf < (uint)piVar2[7]) {
              piVar6 = (int *)*piVar6;
            }
            iVar4 = __stricmp((char *)piVar6,(char *)param_2);
            if (iVar4 == 0) {
              return piVar2;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar10);
        }
        uVar12 = 0;
        uVar10 = piVar5[0x27] - piVar5[0x26] >> 2;
        if (uVar10 != 0) {
          do {
            piVar2 = *(int **)(piVar5[0x26] + uVar12 * 4);
            piVar6 = piVar2 + 2;
            if (0xf < (uint)piVar2[7]) {
              piVar6 = (int *)*piVar6;
            }
            iVar4 = __stricmp((char *)piVar6,(char *)param_2);
            if (iVar4 == 0) {
              return piVar2;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar10);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < uVar9);
  }
  iVar4 = (**(code **)(*param_1 + 0x34))();
  iVar11 = 0;
  if (0 < iVar4) {
    do {
      if ((char)param_4 != '\0') {
        *param_3 = param_1;
      }
      uVar7 = (**(code **)(*param_1 + 0x30))(iVar11,param_2,param_3,param_4);
      piVar5 = (int *)FUN_007c6430(uVar7);
      if (piVar5 != (int *)0x0) {
        return piVar5;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar4);
  }
  return (int *)0x0;
}


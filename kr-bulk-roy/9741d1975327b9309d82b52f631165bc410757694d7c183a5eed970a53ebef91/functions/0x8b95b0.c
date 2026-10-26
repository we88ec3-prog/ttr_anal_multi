
undefined4 FUN_008b95b0(short *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar9;
  uint local_34;
  int local_30;
  uint local_2c;
  int local_28;
  int local_20;
  int local_18;
  int local_14;
  uint local_10;
  int local_8;
  short *psVar8;
  
  local_8 = 0;
  if ((param_1 == (short *)0x0) || (param_1[1] < 1)) {
    return 0;
  }
  FUN_008b9440(param_1,&local_34);
  iVar1 = FUN_008b7cb0((local_34 ^ (int)local_34 >> 0x1f) - ((int)local_34 >> 0x1f) |
                       (local_2c ^ (int)local_2c >> 0x1f) - ((int)local_2c >> 0x1f));
  local_10 = ((int)(iVar1 - 0xeU) < 1) - 1 & iVar1 - 0xeU;
  iVar2 = FUN_008b7cb0(local_28 - local_30);
  iVar1 = 0;
  bVar4 = (iVar2 + -0xe < 1) - 1U & (byte)(iVar2 + -0xe);
  iVar2 = *(int *)(param_1 + 2);
  local_20 = (int)*param_1;
  if (0 < local_20) {
    psVar8 = *(short **)(param_1 + 6);
    do {
      iVar7 = (int)*psVar8;
      iVar6 = *(int *)(iVar2 + 4 + iVar7 * 8);
      local_18 = 0;
      local_14 = 0;
      iVar9 = *(int *)(iVar2 + iVar7 * 8);
      if (iVar1 <= iVar7) {
        bVar5 = (byte)local_10;
        param_1 = (short *)iVar1;
        if (1 < (iVar7 - iVar1) + 1) {
          iVar7 = ((iVar7 - iVar1) - 1U >> 1) + 1;
          param_1 = (short *)(iVar1 + iVar7 * 2);
          piVar3 = (int *)(iVar2 + iVar1 * 8);
          do {
            local_18 = local_18 +
                       (piVar3[1] - iVar6 >> (bVar4 & 0x1f)) * (iVar9 + *piVar3 >> (bVar5 & 0x1f));
            iVar9 = piVar3[2];
            iVar6 = piVar3[3];
            local_14 = local_14 +
                       (piVar3[3] - piVar3[1] >> (bVar4 & 0x1f)) *
                       (*piVar3 + iVar9 >> (bVar5 & 0x1f));
            iVar7 = iVar7 + -1;
            piVar3 = piVar3 + 4;
          } while (iVar7 != 0);
        }
        iVar7 = (int)*psVar8;
        if ((int)param_1 <= iVar7) {
          local_8 = local_8 + (*(int *)(iVar2 + 4 + (int)param_1 * 8) - iVar6 >> (bVar4 & 0x1f)) *
                              (iVar9 + *(int *)(iVar2 + (int)param_1 * 8) >> (bVar5 & 0x1f));
        }
        local_8 = local_8 + local_14 + local_18;
      }
      iVar1 = iVar7 + 1;
      psVar8 = psVar8 + 1;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
    if (0 < local_8) {
      return 1;
    }
    if (local_8 < 0) {
      return 0;
    }
  }
  return 2;
}


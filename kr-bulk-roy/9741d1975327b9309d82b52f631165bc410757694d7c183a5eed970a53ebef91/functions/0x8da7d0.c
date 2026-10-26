
int FUN_008da7d0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int local_1c;
  int local_18;
  
  iVar4 = FUN_008b97e0(param_2,param_3 + param_4);
  if ((iVar4 == 0) && (iVar4 = FUN_008babe0(param_2,param_5), iVar4 == 0)) {
    pbVar1 = *(byte **)(param_2 + 0x20);
    if ((param_5 == 0) || ((*pbVar1 & 0x80) == 0)) {
      iVar4 = FUN_008da050(pbVar1,pbVar1 + param_5);
      FUN_008baca0(param_2);
      return iVar4;
    }
    iVar2 = *(int *)(param_1 + 0x1c);
    iVar7 = *(int *)(param_1 + 0x10);
    iVar4 = FUN_008da4f0(param_1,pbVar1,pbVar1 + param_5);
    FUN_008baca0(param_2);
    if ((iVar4 == 0) && (iVar6 = *(int *)(param_1 + 0x10) - iVar7, 0 < iVar6)) {
      iVar7 = iVar7 * 0x18;
      local_1c = 0;
      do {
        iVar9 = (int)*(short *)(iVar2 + 0x16);
        iVar4 = FUN_008da7d0(param_1,param_2,param_3,
                             *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar7 + 0x10),
                             *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x14 + iVar7));
        if (iVar4 != 0) {
          return iVar4;
        }
        piVar8 = (int *)(*(int *)(param_1 + 0x18) + iVar7);
        local_18 = *(short *)(iVar2 + 0x16) - iVar9;
        if ((*piVar8 == 0x10000) && (piVar8[1] == 0x10000)) {
          piVar5 = (int *)(*(int *)(iVar2 + 0x18) + iVar9 * 8);
          if (0 < local_18) {
            do {
              *piVar5 = *piVar5 + piVar8[2];
              piVar5[1] = piVar5[1] + piVar8[3];
              piVar5 = piVar5 + 2;
              local_18 = local_18 + -1;
            } while (local_18 != 0);
          }
        }
        else {
          piVar5 = (int *)(*(int *)(iVar2 + 0x18) + iVar9 * 8);
          if (0 < local_18) {
            do {
              lVar3 = (longlong)*piVar5 * (longlong)*piVar8 +
                      (ulonglong)((int)((longlong)*piVar5 * (longlong)*piVar8 >> 0x3f) + 0x8000);
              *piVar5 = piVar8[2] +
                        ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
              lVar3 = (longlong)piVar5[1] * (longlong)piVar8[1] +
                      (ulonglong)((int)((longlong)piVar5[1] * (longlong)piVar8[1] >> 0x3f) + 0x8000)
              ;
              local_18 = local_18 + -1;
              piVar5[1] = piVar8[3] +
                          ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
              piVar5 = piVar5 + 2;
            } while (local_18 != 0);
          }
        }
        iVar7 = iVar7 + 0x18;
        local_1c = local_1c + 1;
        iVar4 = 0;
      } while (local_1c < iVar6);
    }
  }
  return iVar4;
}


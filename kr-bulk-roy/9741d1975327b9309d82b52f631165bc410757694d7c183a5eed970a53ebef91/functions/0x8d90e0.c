
int FUN_008d90e0(int param_1,byte *param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  int *piVar11;
  
  *param_4 = 0;
  param_4[1] = 0;
  if (param_2 != (byte *)0x0) {
    param_2 = (byte *)((int)param_2 - 1);
  }
  if (param_3 != 0) {
    param_3 = param_3 - 1;
  }
  if (*(uint *)(param_1 + 0x198) < param_2) {
    return 0;
  }
  if (*(uint *)(param_1 + 0x198) < param_3) {
    return 0;
  }
  piVar11 = *(int **)(param_1 + 0x1a8);
  iVar1 = *(int *)(param_1 + 0x68);
  uVar5 = *(int *)(*(int *)(param_1 + 0x1a0) + (int)param_2 * 0x10) << 0x10 |
          (uint)*(ushort *)(*(int *)(param_1 + 0x1a0) + param_3 * 0x10);
  if (piVar11 == (int *)0x0) {
    return 0;
  }
  while ((uVar5 < (uint)piVar11[4] || ((uint)piVar11[5] < uVar5))) {
    piVar11 = (int *)*piVar11;
    if (piVar11 == (int *)0x0) {
      return 0;
    }
  }
  iVar2 = FUN_008b97e0(iVar1,piVar11[3]);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = FUN_008babe0(iVar1,(uint)*(byte *)(piVar11 + 1) * piVar11[2]);
  if (iVar2 != 0) {
    return iVar2;
  }
  bVar9 = *(byte *)(piVar11 + 1);
  uVar7 = piVar11[2];
  iVar2 = FUN_008ba190((uint)bVar9);
  iVar10 = (uint)bVar9 - iVar2;
  uVar8 = iVar2 * uVar7;
  param_2 = *(byte **)(iVar1 + 0x20);
  bVar9 = *(byte *)((int)piVar11 + 5) & 1;
  param_1._3_1_ = *(byte *)((int)piVar11 + 5) & 2;
  if (iVar10 == 0) {
LAB_008d922e:
    if (uVar7 <= uVar8 && uVar8 - uVar7 != 0) {
      do {
        uVar8 = uVar8 >> 1;
        pbVar3 = param_2 + uVar8;
        if (bVar9 == 0) {
          pbVar4 = pbVar3 + 2;
          uVar6 = (uint)*pbVar3 << 0x10;
        }
        else {
          pbVar4 = pbVar3 + 4;
          uVar6 = (uint)CONCAT21(CONCAT11(*pbVar3,pbVar3[1]),pbVar3[2]) << 8;
        }
        if ((uVar6 | pbVar4[-1]) == uVar5) goto LAB_008d92b9;
        if ((uVar6 | pbVar4[-1]) < uVar5) {
          param_2 = pbVar3;
        }
      } while (uVar7 < uVar8);
    }
    if (bVar9 == 0) {
      pbVar4 = param_2 + 2;
      uVar7 = (uint)*param_2 << 0x10;
    }
    else {
      pbVar4 = param_2 + 4;
      uVar7 = (uint)CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]) << 8;
    }
    if ((uVar7 | pbVar4[-1]) != uVar5) goto LAB_008d92da;
  }
  else {
    pbVar3 = param_2 + iVar10 * uVar7;
    if (bVar9 == 0) {
      pbVar4 = pbVar3 + 2;
      uVar6 = (uint)*pbVar3 << 0x10;
    }
    else {
      pbVar4 = pbVar3 + 4;
      uVar6 = (uint)CONCAT21(CONCAT11(*pbVar3,pbVar3[1]),pbVar3[2]) << 8;
    }
    if ((uVar6 | pbVar4[-1]) != uVar5) {
      if ((uVar6 | pbVar4[-1]) < uVar5) {
        if (param_1._3_1_ == 0) {
          param_2 = pbVar4 + 1;
        }
        else {
          param_2 = pbVar4 + 2;
        }
      }
      goto LAB_008d922e;
    }
  }
LAB_008d92b9:
  uVar5 = (uint)*pbVar4;
  if (param_1._3_1_ != 0) {
    uVar5 = (int)(short)((ushort)*pbVar4 << 8) | (uint)pbVar4[1];
  }
  *param_4 = (int)*(short *)((int)piVar11 + 6) + uVar5;
LAB_008d92da:
  FUN_008baca0(iVar1);
  return 0;
}


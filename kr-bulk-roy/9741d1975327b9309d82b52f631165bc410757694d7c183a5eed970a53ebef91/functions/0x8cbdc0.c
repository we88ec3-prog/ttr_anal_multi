
void FUN_008cbdc0(undefined4 *param_1,short param_2,int param_3,uint param_4,int param_5,int param_6
                 )

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  
  iVar6 = param_1[1];
  uVar7 = iVar6 + -1 + param_3 & -iVar6;
  uVar3 = -iVar6 & param_4;
  uVar5 = uVar7;
  if ((int)uVar7 <= (int)uVar3) goto LAB_008cbf02;
  uVar1 = *(uint *)(param_5 + 0xc);
  if (uVar7 != iVar6 + uVar3) {
    return;
  }
  uVar4 = uVar3;
  switch(uVar1 & 7) {
  case 0:
    break;
  case 1:
  case 5:
    if ((*(int *)(param_5 + 0x1c) == param_6) && (*(int *)(param_5 + 0x10) < 1)) {
      if ((uVar1 & 0x10) == 0) {
        return;
      }
      if ((int)(param_4 - param_3) < (int)param_1[2]) {
        return;
      }
    }
    if ((*(int *)(param_6 + 0x1c) == param_5) && (*(int *)(param_5 + 0x14) == (int)param_2)) {
      if ((uVar1 & 0x20) == 0) {
        return;
      }
      if ((int)(param_4 - param_3) < (int)param_1[2]) {
        return;
      }
    }
    if ((uVar1 & 7) != 1) goto LAB_008cbe93;
    break;
  default:
    return;
  case 4:
LAB_008cbe93:
    uVar4 = (int)(param_3 + -1 + param_4) / 2 + param_1[2] & -iVar6;
  }
  if ((int)uVar4 < 0) {
LAB_008cbebb:
    uVar7 = uVar3;
  }
  else {
    uVar5 = uVar4;
    if ((int)param_1[0x1a] <= (int)uVar4 >> ((byte)*param_1 & 0x1f)) {
      uVar5 = uVar3;
    }
    if (uVar5 == uVar7) goto LAB_008cbebb;
  }
  iVar6 = (int)uVar7 >> ((byte)*param_1 & 0x1f);
  pbVar8 = (byte *)((((int)param_2 >> 3) - param_1[0x1c] * iVar6) + param_1[0xf]);
  if (0 < (int)param_1[0x1c]) {
    pbVar8 = pbVar8 + (param_1[0x1a] + -1) * param_1[0x1c];
  }
  if (((-1 < iVar6) && (iVar6 < (int)param_1[0x1a])) &&
     ((*pbVar8 & (byte)(0x80 >> ((byte)param_2 & 7))) != 0)) {
    return;
  }
LAB_008cbf02:
  iVar6 = (int)uVar5 >> ((byte)*param_1 & 0x1f);
  if ((-1 < iVar6) && (iVar6 < (int)param_1[0x1a])) {
    iVar2 = param_1[0x1c];
    pbVar8 = (byte *)((((int)param_2 >> 3) - iVar2 * iVar6) + param_1[0xf]);
    if (0 < iVar2) {
      pbVar8 = pbVar8 + (param_1[0x1a] + -1) * iVar2;
    }
    *pbVar8 = *pbVar8 | (byte)(0x80 >> ((byte)param_2 & 7));
  }
  return;
}


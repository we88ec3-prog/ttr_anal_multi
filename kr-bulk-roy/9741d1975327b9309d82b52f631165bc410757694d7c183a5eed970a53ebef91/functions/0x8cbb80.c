
void FUN_008cbb80(undefined4 *param_1,short param_2,int param_3,uint param_4,int param_5,int param_6
                 )

{
  short sVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar3 = param_1[1];
  uVar5 = -iVar3;
  uVar6 = uVar5 & param_4;
  uVar7 = iVar3 + -1 + param_3 & uVar5;
  if ((int)uVar7 <= (int)uVar6) goto LAB_008cbca9;
  uVar2 = *(uint *)(param_5 + 0xc);
  if (uVar7 != iVar3 + uVar6) {
    return;
  }
  switch(uVar2 & 7) {
  case 1:
  case 5:
    if ((*(int *)(param_5 + 0x1c) == param_6) && (*(int *)(param_5 + 0x10) < 1)) {
      if ((uVar2 & 0x10) == 0) {
        return;
      }
      if ((int)(param_4 - param_3) < (int)param_1[2]) {
        return;
      }
    }
    if ((*(int *)(param_6 + 0x1c) == param_5) && (*(int *)(param_5 + 0x14) == (int)param_2)) {
      if ((uVar2 & 0x20) == 0) {
        return;
      }
      if ((int)(param_4 - param_3) < (int)param_1[2]) {
        return;
      }
    }
    if ((uVar2 & 7) != 1) goto LAB_008cbc49;
  case 0:
    uVar5 = uVar6;
    break;
  default:
    return;
  case 4:
LAB_008cbc49:
    uVar5 = (int)(param_3 + -1 + param_4) / 2 + param_1[2] & uVar5;
  }
  uVar2 = uVar7;
  if ((int)uVar5 < 0) {
LAB_008cbc6f:
    uVar5 = uVar2;
    uVar8 = uVar6;
  }
  else {
    if ((int)(uint)*(ushort *)(param_1 + 0xe) <= (int)uVar5 >> ((byte)*param_1 & 0x1f)) {
      uVar5 = uVar6;
    }
    uVar2 = uVar5;
    uVar8 = uVar7;
    if (uVar5 == uVar7) goto LAB_008cbc6f;
  }
  uVar7 = uVar5;
  iVar3 = (int)uVar8 >> ((byte)*param_1 & 0x1f);
  if (((-1 < iVar3) && (iVar3 < (int)(uint)*(ushort *)(param_1 + 0xe))) &&
     ((*(byte *)((int)(short)(iVar3 >> 3) + param_1[0x25] + param_1[0xf]) &
      (byte)(0x80 >> ((byte)iVar3 & 7))) != 0)) {
    return;
  }
LAB_008cbca9:
  iVar3 = (int)uVar7 >> ((byte)*param_1 & 0x1f);
  if ((-1 < iVar3) && (iVar3 < (int)(uint)*(ushort *)(param_1 + 0xe))) {
    sVar1 = (short)(iVar3 >> 3);
    if (sVar1 < *(short *)((int)param_1 + 0x9e)) {
      *(short *)((int)param_1 + 0x9e) = sVar1;
    }
    if (*(short *)(param_1 + 0x28) < sVar1) {
      *(short *)(param_1 + 0x28) = sVar1;
    }
    pbVar4 = (byte *)(param_1[0x25] + param_1[0xf] + (int)sVar1);
    *pbVar4 = *pbVar4 | (byte)(0x80 >> ((byte)iVar3 & 7));
  }
  return;
}


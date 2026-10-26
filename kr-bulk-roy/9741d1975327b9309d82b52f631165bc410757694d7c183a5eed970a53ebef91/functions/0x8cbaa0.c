
void FUN_008cbaa0(undefined4 *param_1,undefined4 param_2,int param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  short sVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_1[1];
  iVar2 = (iVar8 + -1 + param_3 & -iVar8) >> ((byte)*param_1 & 0x1f);
  iVar7 = iVar2;
  if ((int)param_1[5] < (int)((param_4 - iVar8) - param_3)) {
    iVar7 = (int)(-iVar8 & param_4) >> ((byte)*param_1 & 0x1f);
  }
  if ((-1 < iVar7) && (uVar5 = (uint)*(ushort *)(param_1 + 0xe), iVar2 < (int)uVar5)) {
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    if ((int)uVar5 <= iVar7) {
      iVar7 = uVar5 - 1;
    }
    sVar4 = (short)(iVar2 >> 3);
    iVar8 = (int)sVar4;
    sVar6 = (short)(iVar7 >> 3);
    bVar1 = ~(byte)(0x7f >> ((byte)iVar7 & 7));
    if (iVar8 < *(short *)((int)param_1 + 0x9e)) {
      *(short *)((int)param_1 + 0x9e) = sVar4;
    }
    if ((int)*(short *)(param_1 + 0x28) < (int)sVar6) {
      *(short *)(param_1 + 0x28) = sVar6;
    }
    iVar7 = sVar6 - iVar8;
    pbVar3 = (byte *)(param_1[0x25] + param_1[0xf] + iVar8);
    param_3._3_1_ = (byte)(0xff >> ((byte)iVar2 & 7));
    if (0 < iVar7) {
      *pbVar3 = *pbVar3 | param_3._3_1_;
      while (iVar7 = iVar7 + -1, 0 < iVar7) {
        pbVar3 = pbVar3 + 1;
        *pbVar3 = 0xff;
      }
      pbVar3[1] = pbVar3[1] | bVar1;
      return;
    }
    *pbVar3 = *pbVar3 | bVar1 & param_3._3_1_;
  }
  return;
}


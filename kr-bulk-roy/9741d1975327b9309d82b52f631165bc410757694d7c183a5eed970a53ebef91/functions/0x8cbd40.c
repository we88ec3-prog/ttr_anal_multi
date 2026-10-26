
void FUN_008cbd40(undefined4 *param_1,short param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  if (((int)(param_4 - param_3) < (int)param_1[1]) &&
     (uVar2 = -param_1[1], uVar4 = param_1[1] + -1 + param_3 & uVar2, uVar4 == (uVar2 & param_4))) {
    iVar5 = (int)uVar4 >> ((byte)*param_1 & 0x1f);
    if ((-1 < iVar5) && (iVar5 < (int)param_1[0x1a])) {
      iVar1 = param_1[0x1c];
      pbVar3 = (byte *)((((int)param_2 >> 3) - iVar1 * iVar5) + param_1[0xf]);
      if (0 < iVar1) {
        pbVar3 = pbVar3 + (param_1[0x1a] + -1) * iVar1;
      }
      *pbVar3 = *pbVar3 | (byte)(0x80 >> ((byte)param_2 & 7));
    }
  }
  return;
}


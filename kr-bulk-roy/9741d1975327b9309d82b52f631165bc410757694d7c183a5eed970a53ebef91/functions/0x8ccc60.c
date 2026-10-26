
int FUN_008ccc60(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int *in_ECX;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  
  iVar1 = FUN_008ccc20();
  if ((iVar1 == 0) && (iVar1 = FUN_008cca60(), iVar1 == 0)) {
    pbVar4 = (byte *)((param_2 >> 3) + param_1);
    iVar2 = 0x80 >> ((byte)param_2 & 7);
    *in_ECX = param_3;
    pbVar6 = (byte *)in_ECX[2];
    iVar5 = 0x80;
    for (; param_3 != 0; param_3 = param_3 + -1) {
      bVar3 = *pbVar6 & ~(byte)iVar5;
      if ((*pbVar4 & (byte)iVar2) != 0) {
        bVar3 = bVar3 | (byte)iVar5;
      }
      iVar2 = iVar2 >> 1;
      *pbVar6 = bVar3;
      if (iVar2 == 0) {
        pbVar4 = pbVar4 + 1;
        iVar2 = 0x80;
      }
      iVar5 = iVar5 >> 1;
      if (iVar5 == 0) {
        pbVar6 = pbVar6 + 1;
        iVar5 = 0x80;
      }
    }
  }
  return iVar1;
}


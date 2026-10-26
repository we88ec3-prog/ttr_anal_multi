
int FUN_008e86b0(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  bool bVar7;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x1a0)) {
    puVar6 = *(undefined4 **)(param_1 + 0x1a4);
    do {
      pbVar5 = (byte *)*puVar6;
      pbVar3 = param_2;
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_008e86f5:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_008e86fa;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_008e86f5;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_008e86fa:
      if (iVar4 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x1a0));
  }
  return 0;
}


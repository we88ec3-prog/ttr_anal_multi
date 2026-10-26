
undefined4 FUN_007c4af0(byte *param_1)

{
  byte bVar1;
  int in_EAX;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  uVar6 = *(int *)(in_EAX + 0xa8) - *(int *)(in_EAX + 0xa4) >> 2;
  uVar7 = 0;
  if (uVar6 != 0) {
    puVar5 = *(undefined4 **)(in_EAX + 0xa4);
    do {
      pbVar2 = (byte *)*puVar5;
      pbVar4 = param_1;
      do {
        bVar1 = *pbVar2;
        bVar8 = bVar1 < *pbVar4;
        if (bVar1 != *pbVar4) {
LAB_007c4b40:
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_007c4b45;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar8 = bVar1 < pbVar4[1];
        if (bVar1 != pbVar4[1]) goto LAB_007c4b40;
        pbVar2 = pbVar2 + 2;
        pbVar4 = pbVar4 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_007c4b45:
      if (iVar3 == 0) {
        return (*(undefined4 **)(in_EAX + 0xa4))[uVar7];
      }
      uVar7 = uVar7 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar7 < uVar6);
  }
  return 0;
}


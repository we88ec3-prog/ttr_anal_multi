
uint FUN_008d0e30(int param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  if (0xff < param_2) {
    return 0;
  }
  pbVar2 = (byte *)(**(code **)(param_1 + 0x14))
                             (*(undefined2 *)(*(int *)(param_1 + 0x10) + param_2 * 2));
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x18) != 0) {
    puVar7 = *(undefined4 **)(param_1 + 0x1c);
    do {
      pbVar4 = (byte *)*puVar7;
      if ((pbVar4 != (byte *)0x0) && (pbVar6 = pbVar2, *pbVar4 == *pbVar2)) {
        do {
          bVar1 = *pbVar4;
          bVar8 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_008d0e92:
            iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_008d0e97;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar8 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_008d0e92;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_008d0e97:
        if (iVar5 == 0) {
          return uVar3;
        }
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x18));
  }
  return 0;
}


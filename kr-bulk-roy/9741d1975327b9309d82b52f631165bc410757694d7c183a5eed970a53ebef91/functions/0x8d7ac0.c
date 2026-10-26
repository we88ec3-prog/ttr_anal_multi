
long FUN_008d7ac0(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  long lVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x1a0)) {
    puVar7 = *(undefined4 **)(param_1 + 0x1a4);
    do {
      pbVar5 = (byte *)*puVar7;
      pbVar2 = param_2;
      if (*param_2 == *pbVar5) {
        do {
          bVar1 = *pbVar2;
          bVar8 = bVar1 < *pbVar5;
          if (bVar1 != *pbVar5) {
LAB_008d7b10:
            iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_008d7b15;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar8 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_008d7b10;
          pbVar5 = pbVar5 + 2;
          pbVar2 = pbVar2 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_008d7b15:
        if (iVar3 == 0) {
          lVar4 = _atol(*(char **)(*(int *)(param_1 + 0x1a8) + iVar6 * 4));
          return lVar4;
        }
      }
      iVar6 = iVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x1a0));
  }
  return 0;
}


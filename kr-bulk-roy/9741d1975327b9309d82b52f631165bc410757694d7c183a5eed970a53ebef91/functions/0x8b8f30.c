
undefined4 FUN_008b8f30(int param_1,byte *param_2)

{
  undefined4 *puVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  bool bVar7;
  
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    return 0;
  }
  puVar6 = (undefined4 *)(param_1 + 0x14);
  puVar1 = puVar6 + *(int *)(param_1 + 0x10);
  if (puVar1 <= puVar6) {
    return 0;
  }
  do {
    pbVar3 = *(byte **)(*(int *)*puVar6 + 8);
    pbVar5 = param_2;
    do {
      bVar2 = *pbVar3;
      bVar7 = bVar2 < *pbVar5;
      if (bVar2 != *pbVar5) {
LAB_008b8f90:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_008b8f95;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar7 = bVar2 < pbVar5[1];
      if (bVar2 != pbVar5[1]) goto LAB_008b8f90;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_008b8f95:
    if (iVar4 == 0) {
      return *puVar6;
    }
    puVar6 = puVar6 + 1;
    if (puVar1 <= puVar6) {
      return 0;
    }
  } while( true );
}


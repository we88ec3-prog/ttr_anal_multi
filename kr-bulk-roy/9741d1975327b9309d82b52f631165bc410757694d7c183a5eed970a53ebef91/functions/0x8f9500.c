
int FUN_008f9500(int param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  bool bVar6;
  
  puVar2 = param_3;
  pcVar5 = "glyph-to-script-map";
  pbVar3 = param_2;
  do {
    bVar1 = *pbVar3;
    bVar6 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_008f9540:
      iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_008f9545;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar6 = bVar1 < (byte)pcVar5[1];
    if (bVar1 != pcVar5[1]) goto LAB_008f9540;
    pbVar3 = pbVar3 + 2;
    pcVar5 = pcVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_008f9545:
  if (iVar4 == 0) {
    iVar4 = FUN_008f9380(&param_1,param_1);
    if (iVar4 == 0) {
      puVar2[1] = *(undefined4 *)(param_1 + 8);
      return 0;
    }
  }
  else {
    pcVar5 = "fallback-script";
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_008f95a0:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_008f95a5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar6 = bVar1 < (byte)pcVar5[1];
      if (bVar1 != pcVar5[1]) goto LAB_008f95a0;
      pbVar3 = pbVar3 + 2;
      pcVar5 = pcVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_008f95a5:
    if (iVar4 == 0) {
      *param_3 = *(undefined4 *)((&PTR_DAT_00bebbe0)[*(int *)(param_1 + 0xc)] + 8);
      return 0;
    }
    pcVar5 = "default-script";
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_008f95e6:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_008f95eb;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar6 = bVar1 < (byte)pcVar5[1];
      if (bVar1 != pcVar5[1]) goto LAB_008f95e6;
      pbVar3 = pbVar3 + 2;
      pcVar5 = pcVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_008f95eb:
    if (iVar4 == 0) {
      *param_3 = *(undefined4 *)(param_1 + 0x10);
      return 0;
    }
    pcVar5 = "increase-x-height";
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_008f9620:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_008f9625;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar6 = bVar1 < (byte)pcVar5[1];
      if (bVar1 != pcVar5[1]) goto LAB_008f9620;
      pbVar3 = pbVar3 + 2;
      pcVar5 = pcVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_008f9625:
    if (iVar4 == 0) {
      iVar4 = FUN_008f9380(&param_1,param_1);
      if (iVar4 == 0) {
        puVar2[1] = *(undefined4 *)(param_1 + 0xc);
        return 0;
      }
    }
    else {
      iVar4 = 0xc;
    }
  }
  return iVar4;
}


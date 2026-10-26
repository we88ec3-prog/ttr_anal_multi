
int FUN_008f93d0(int param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  undefined *puVar5;
  char *pcVar6;
  bool bVar7;
  
  piVar2 = param_3;
  pcVar6 = "fallback-script";
  pbVar3 = param_2;
  do {
    bVar1 = *pbVar3;
    bVar7 = bVar1 < (byte)*pcVar6;
    if (bVar1 != *pcVar6) {
LAB_008f9400:
      iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_008f9405;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar7 = bVar1 < (byte)pcVar6[1];
    if (bVar1 != pcVar6[1]) goto LAB_008f9400;
    pbVar3 = pbVar3 + 2;
    pcVar6 = pcVar6 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_008f9405:
  if (iVar4 != 0) {
    pcVar6 = "default-script";
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar7 = bVar1 < (byte)*pcVar6;
      if (bVar1 != *pcVar6) {
LAB_008f9480:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_008f9485;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar7 = bVar1 < (byte)pcVar6[1];
      if (bVar1 != pcVar6[1]) goto LAB_008f9480;
      pbVar3 = pbVar3 + 2;
      pcVar6 = pcVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_008f9485:
    if (iVar4 == 0) {
      *(int *)(param_1 + 0x10) = *param_3;
      return 0;
    }
    pcVar6 = "increase-x-height";
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar7 = bVar1 < (byte)*pcVar6;
      if (bVar1 != *pcVar6) {
LAB_008f94c0:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_008f94c5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar7 = bVar1 < (byte)pcVar6[1];
      if (bVar1 != pcVar6[1]) goto LAB_008f94c0;
      pbVar3 = pbVar3 + 2;
      pcVar6 = pcVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_008f94c5:
    if (iVar4 == 0) {
      iVar4 = FUN_008f9380(&param_1,param_1);
      if (iVar4 == 0) {
        *(int *)(param_1 + 0xc) = piVar2[1];
        return 0;
      }
    }
    else {
      iVar4 = 0xc;
    }
    return iVar4;
  }
  puVar5 = &DAT_00beb754;
  iVar4 = 0;
  while ((*(int *)(puVar5 + 8) != *param_3 || (*(int *)(puVar5 + 0x10) != 10))) {
    puVar5 = (&PTR_DAT_00bebbe4)[iVar4];
    iVar4 = iVar4 + 1;
    if (puVar5 == (undefined *)0x0) {
LAB_008f943e:
      return (-(uint)((&PTR_DAT_00bebbe0)[iVar4] != (undefined *)0x0) & 0xfffffffa) + 6;
    }
  }
  *(int *)(param_1 + 0xc) = iVar4;
  goto LAB_008f943e;
}


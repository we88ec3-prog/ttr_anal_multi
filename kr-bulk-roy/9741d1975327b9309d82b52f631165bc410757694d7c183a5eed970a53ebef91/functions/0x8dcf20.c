
undefined4 FUN_008dcf20(int param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  
  pcVar4 = "darkening-parameters";
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < (byte)*pcVar4;
    if (bVar1 != *pcVar4) {
LAB_008dcf50:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_008dcf55;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < (byte)pcVar4[1];
    if (bVar1 != pcVar4[1]) goto LAB_008dcf50;
    pbVar2 = pbVar2 + 2;
    pcVar4 = pcVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_008dcf55:
  if (iVar3 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x24);
    param_3[1] = *(undefined4 *)(param_1 + 0x28);
    param_3[2] = *(undefined4 *)(param_1 + 0x2c);
    param_3[3] = *(undefined4 *)(param_1 + 0x30);
    param_3[4] = *(undefined4 *)(param_1 + 0x34);
    param_3[5] = *(undefined4 *)(param_1 + 0x38);
    param_3[6] = *(undefined4 *)(param_1 + 0x3c);
    param_3[7] = *(undefined4 *)(param_1 + 0x40);
    return 0;
  }
  pcVar4 = "hinting-engine";
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < (byte)*pcVar4;
    if (bVar1 != *pcVar4) {
LAB_008dcfc0:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_008dcfc5;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < (byte)pcVar4[1];
    if (bVar1 != pcVar4[1]) goto LAB_008dcfc0;
    pbVar2 = pbVar2 + 2;
    pcVar4 = pcVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_008dcfc5:
  if (iVar3 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x1c);
    return 0;
  }
  pcVar4 = "no-stem-darkening";
  do {
    bVar1 = *param_2;
    bVar5 = bVar1 < (byte)*pcVar4;
    if (bVar1 != *pcVar4) {
LAB_008dd000:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_008dd005;
    }
    if (bVar1 == 0) break;
    bVar1 = param_2[1];
    bVar5 = bVar1 < (byte)pcVar4[1];
    if (bVar1 != pcVar4[1]) goto LAB_008dd000;
    param_2 = param_2 + 2;
    pcVar4 = pcVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_008dd005:
  if (iVar3 == 0) {
    *(undefined1 *)param_3 = *(undefined1 *)(param_1 + 0x20);
    return 0;
  }
  return 0xc;
}


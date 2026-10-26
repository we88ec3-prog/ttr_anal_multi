
undefined4 FUN_008d5140(undefined4 param_1,int param_2,int param_3)

{
  byte bVar1;
  char *pcVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined4 uVar9;
  byte *pbVar10;
  bool bVar11;
  int local_10 [3];
  
  iVar4 = FUN_008d4bb0();
  if (iVar4 != 0) {
    FUN_008d4ff0(param_2);
    iVar4 = param_2 + 0x84;
    iVar5 = FUN_008fbc00(iVar4,param_1);
    if ((char)iVar5 == '\a') {
LAB_008d519e:
      FUN_008d4ff0(param_2);
      return 2;
    }
    if (iVar5 != 0) {
      iVar5 = FUN_008fcc90(iVar4,param_1);
      if (((char)iVar5 == '\a') || (iVar5 != 0)) goto LAB_008d519e;
    }
    *(undefined4 *)(param_2 + 0xac) = param_1;
    *(int *)(param_2 + 0x68) = iVar4;
    iVar4 = FUN_008d4bb0();
    if (iVar4 != 0) goto LAB_008d519e;
  }
  if (0 < param_3) {
    FUN_008d4ff0(param_2);
    return 6;
  }
  pcVar2 = *(char **)(param_2 + 0xb4);
  bVar3 = false;
  if (((((pcVar2 == (char *)0x0) || (pbVar8 = *(byte **)(param_2 + 0xb0), pbVar8 == (byte *)0x0)) ||
       ((*pcVar2 != 'i' && (*pcVar2 != 'I')))) || ((pcVar2[1] != 's' && (pcVar2[1] != 'S')))) ||
     ((pcVar2[2] != 'o' && (pcVar2[2] != 'O')))) goto LAB_008d52bd;
  pbVar7 = (byte *)(pcVar2 + 3);
  pbVar10 = &DAT_00bd7c88;
  pbVar6 = pbVar7;
  do {
    bVar1 = *pbVar6;
    bVar11 = bVar1 < *pbVar10;
    if (bVar1 != *pbVar10) {
LAB_008d5250:
      iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_008d5255;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar6[1];
    bVar11 = bVar1 < pbVar10[1];
    if (bVar1 != pbVar10[1]) goto LAB_008d5250;
    pbVar6 = pbVar6 + 2;
    pbVar10 = pbVar10 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_008d5255:
  if (iVar4 != 0) {
    pbVar6 = &DAT_00bd7c80;
    do {
      bVar1 = *pbVar7;
      bVar11 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_008d5280:
        iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_008d5285;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar7[1];
      bVar11 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_008d5280;
      pbVar7 = pbVar7 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_008d5285:
    if (iVar4 != 0) goto LAB_008d52bd;
    pbVar7 = &DAT_00c1ffdc;
    do {
      bVar1 = *pbVar8;
      bVar11 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_008d52b0:
        iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_008d52b5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar8[1];
      bVar11 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_008d52b0;
      pbVar8 = pbVar8 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_008d52b5:
    if (iVar4 != 0) goto LAB_008d52bd;
  }
  bVar3 = true;
LAB_008d52bd:
  local_10[0] = param_2;
  local_10[1] = 0;
  local_10[2] = 0;
  if (bVar3) {
    local_10[1] = 0x756e6963;
    local_10[2] = 0x10003;
  }
  uVar9 = FUN_008bcc30(&DAT_00be7ffc,0,local_10,0);
  return uVar9;
}


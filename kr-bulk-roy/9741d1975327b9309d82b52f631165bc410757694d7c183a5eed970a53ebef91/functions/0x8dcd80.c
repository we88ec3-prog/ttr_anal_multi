
undefined4 FUN_008dcd80(int param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  char *pcVar11;
  bool bVar12;
  
  pcVar11 = "darkening-parameters";
  pbVar9 = param_2;
  do {
    bVar1 = *pbVar9;
    bVar12 = bVar1 < (byte)*pcVar11;
    if (bVar1 != *pcVar11) {
LAB_008dcdb4:
      iVar10 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_008dcdb9;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar9[1];
    bVar12 = bVar1 < (byte)pcVar11[1];
    if (bVar1 != pcVar11[1]) goto LAB_008dcdb4;
    pbVar9 = pbVar9 + 2;
    pcVar11 = pcVar11 + 2;
  } while (bVar1 != 0);
  iVar10 = 0;
LAB_008dcdb9:
  if (iVar10 == 0) {
    iVar10 = param_3[3];
    iVar2 = *param_3;
    iVar3 = param_3[1];
    iVar4 = param_3[2];
    iVar5 = param_3[5];
    iVar6 = param_3[6];
    iVar7 = param_3[4];
    iVar8 = param_3[7];
    if (((((-1 < iVar2) && (-1 < iVar4)) && (-1 < iVar7)) &&
        (((-1 < iVar6 && (-1 < iVar3)) && ((-1 < iVar10 && ((-1 < iVar5 && (-1 < iVar8)))))))) &&
       ((iVar2 <= iVar4 &&
        (((((iVar4 <= iVar7 && (iVar7 <= iVar6)) && (iVar3 < 0x1f5)) &&
          ((iVar10 < 0x1f5 && (iVar5 < 0x1f5)))) && (iVar8 < 0x1f5)))))) {
      *(int *)(param_1 + 0x24) = iVar2;
      *(int *)(param_1 + 0x30) = iVar10;
      *(int *)(param_1 + 0x34) = iVar7;
      *(int *)(param_1 + 0x2c) = iVar4;
      *(int *)(param_1 + 0x38) = iVar5;
      *(int *)(param_1 + 0x28) = iVar3;
      *(int *)(param_1 + 0x40) = iVar8;
      *(int *)(param_1 + 0x3c) = iVar6;
      return 0;
    }
    return 6;
  }
  pcVar11 = "hinting-engine";
  pbVar9 = param_2;
  do {
    bVar1 = *pbVar9;
    bVar12 = bVar1 < (byte)*pcVar11;
    if (bVar1 != *pcVar11) {
LAB_008dce96:
      iVar10 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_008dce9b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar9[1];
    bVar12 = bVar1 < (byte)pcVar11[1];
    if (bVar1 != pcVar11[1]) goto LAB_008dce96;
    pbVar9 = pbVar9 + 2;
    pcVar11 = pcVar11 + 2;
  } while (bVar1 != 0);
  iVar10 = 0;
LAB_008dce9b:
  if (iVar10 == 0) {
    if (*param_3 != 1) {
      return 7;
    }
    *(undefined4 *)(param_1 + 0x1c) = 1;
    return 0;
  }
  pcVar11 = "no-stem-darkening";
  do {
    bVar1 = *param_2;
    bVar12 = bVar1 < (byte)*pcVar11;
    if (bVar1 != *pcVar11) {
LAB_008dcef0:
      iVar10 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_008dcef5;
    }
    if (bVar1 == 0) break;
    bVar1 = param_2[1];
    bVar12 = bVar1 < (byte)pcVar11[1];
    if (bVar1 != pcVar11[1]) goto LAB_008dcef0;
    param_2 = param_2 + 2;
    pcVar11 = pcVar11 + 2;
  } while (bVar1 != 0);
  iVar10 = 0;
LAB_008dcef5:
  if (iVar10 == 0) {
    *(char *)(param_1 + 0x20) = (char)*param_3;
    return 0;
  }
  return 0xc;
}



void FUN_008c0d30(undefined4 param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  short *psVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  byte *pbVar13;
  int *piVar14;
  byte *pbVar15;
  short sVar16;
  bool bVar17;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 *local_24;
  char local_1d;
  uint local_1c [6];
  
  local_1c[5] = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar3 = param_2[0x19];
  local_24 = param_2;
  local_1c[0] = 0;
  local_28 = 0;
  local_1c[0] = FUN_008b97e0(param_1,0);
  if (local_1c[0] != 0) {
LAB_008c1252:
    __security_check_cookie(local_1c[5] ^ (uint)&stack0xfffffffc);
    return;
  }
  local_1c[1] = 1;
  local_1c[2] = 1;
  local_1c[3] = 0;
  local_1c[4] = 8;
  local_1c[0] = FUN_008c0ae0(param_1,uVar3,&local_28);
  uVar5 = local_28;
  if ((char)local_1c[0] == -0x50) {
    FUN_008bfe00(param_2);
    __security_check_cookie(local_1c[5] ^ (uint)&stack0xfffffffc);
    return;
  }
  if (local_1c[0] != 0) goto LAB_008c1252;
  param_2[0x23] = local_28;
  if (0 < param_3) {
    FUN_008bfe00(param_2);
    __security_check_cookie(local_1c[5] ^ (uint)&stack0xfffffffc);
    return;
  }
  param_2[2] = param_2[2] | 0x92;
  uVar10 = param_2[2];
  *param_2 = 1;
  param_2[1] = 0;
  iVar7 = FUN_008bfab0();
  if ((((iVar7 != 0) && (*(int *)(iVar7 + 4) == 1)) && (*(char **)(iVar7 + 0xc) != (char *)0x0)) &&
     (((cVar1 = **(char **)(iVar7 + 0xc), cVar1 == 'M' || (cVar1 == 'm')) ||
      ((cVar1 == 'C' || (cVar1 == 'c')))))) {
    param_2[2] = uVar10 | 4;
  }
  iVar7 = FUN_008bfab0();
  if ((iVar7 == 0) || (*(int *)(iVar7 + 0xc) == 0)) {
    param_2[5] = 0;
  }
  else {
    uVar8 = FUN_008ba000(uVar3,*(int *)(iVar7 + 0xc),local_1c);
    param_2[5] = uVar8;
    if (local_1c[0] != 0) goto LAB_008c1252;
  }
  local_1c[0] = FUN_008bfc10();
  if (local_1c[0] != 0) goto LAB_008c1252;
  param_2[4] = *(int *)(uVar5 + 0x30) + 1;
  param_2[7] = 1;
  psVar9 = (short *)FUN_008bc7d0(uVar3,0x10,0,1,0,local_1c);
  param_2[8] = psVar9;
  if (local_1c[0] != 0) goto LAB_008c1252;
  psVar9[0] = 0;
  psVar9[1] = 0;
  psVar9[2] = 0;
  psVar9[3] = 0;
  psVar9[4] = 0;
  psVar9[5] = 0;
  psVar9[6] = 0;
  psVar9[7] = 0;
  sVar16 = *(short *)(uVar5 + 0x2c) + *(short *)(uVar5 + 0x28);
  local_28 = local_1c[0];
  *psVar9 = sVar16;
  iVar7 = FUN_008bfab0();
  if (iVar7 == 0) {
    lVar4 = (longlong)(sVar16 * 2) * 0x55555556;
    psVar9[1] = (short)((ulonglong)lVar4 >> 0x20) - (short)(lVar4 >> 0x3f);
  }
  else {
    iVar7 = *(int *)(iVar7 + 0xc) + 5;
    psVar9[1] = ((short)(iVar7 / 10) + (short)(iVar7 >> 0x1f)) -
                (short)((longlong)iVar7 * 0x66666667 >> 0x3f);
  }
  iVar7 = FUN_008bfab0();
  if (iVar7 == 0) {
    *(int *)(psVar9 + 2) = (int)psVar9[1] << 6;
  }
  else {
    *(int *)(psVar9 + 2) = (*(int *)(iVar7 + 0xc) * 0x70800 + 0x8d27) / 0x11a4e;
  }
  iVar7 = FUN_008bfab0();
  if (iVar7 != 0) {
    *(int *)(psVar9 + 6) = (int)*(short *)(iVar7 + 0xc) << 6;
  }
  iVar7 = FUN_008bfab0();
  if (iVar7 != 0) {
    local_28 = (uint)*(ushort *)(iVar7 + 0xc);
  }
  iVar7 = FUN_008bfab0();
  if (iVar7 == 0) {
    sVar16 = 0;
  }
  else {
    sVar16 = *(short *)(iVar7 + 0xc);
  }
  if (*(int *)(psVar9 + 6) == 0) {
    *(int *)(psVar9 + 6) = *(int *)(psVar9 + 2);
    if (sVar16 != 0) {
      *(int *)(psVar9 + 6) = ((int)sVar16 * *(int *)(psVar9 + 2)) / 0x48;
    }
  }
  if (((short)local_28 == 0) || (sVar16 == 0)) {
    *(undefined4 *)(psVar9 + 4) = *(undefined4 *)(psVar9 + 6);
  }
  else {
    *(int *)(psVar9 + 4) = ((int)(short)local_28 * *(int *)(psVar9 + 6)) / (int)sVar16;
  }
  iVar7 = *(int *)(uVar5 + 0x38);
  uVar8 = FUN_008bc7d0(uVar3,8,0,*(undefined4 *)(uVar5 + 0x30),0,local_1c);
  local_24[0x24] = uVar8;
  if (local_1c[0] != 0) goto LAB_008c1252;
  local_24[0x29] = 0;
  if (*(int *)(uVar5 + 0x30) != 0) {
    piVar14 = (int *)(iVar7 + 4);
    uVar10 = 0;
    do {
      *(int *)(local_24[0x24] + uVar10 * 8) = *piVar14;
      *(short *)(local_24[0x24] + 4 + uVar10 * 8) = (short)uVar10;
      if ((*piVar14 == *(int *)(uVar5 + 0x24)) && (uVar10 != 0xffffffff)) {
        local_24[0x29] = uVar10;
      }
      uVar10 = uVar10 + 1;
      piVar14 = piVar14 + 9;
    } while (uVar10 < *(uint *)(uVar5 + 0x30));
  }
  local_1d = '\0';
  iVar7 = FUN_008bfab0();
  iVar11 = FUN_008bfab0();
  puVar6 = local_24;
  if (((((iVar7 == 0) || (iVar11 == 0)) || (*(int *)(iVar7 + 4) != 1)) ||
      ((*(int *)(iVar11 + 4) != 1 || (*(int *)(iVar7 + 0xc) == 0)))) ||
     (*(int *)(iVar11 + 0xc) == 0)) {
    local_34 = local_24;
    local_30 = 0x41444f42;
    local_2c = 7;
    local_1c[0] = FUN_008bcc30(&DAT_00bd7b10,0,&local_34,0);
    if (puVar6[9] != 0) {
      puVar6[0x17] = *(undefined4 *)puVar6[10];
    }
    goto LAB_008c1252;
  }
  uVar8 = FUN_008ba000(uVar3,*(int *)(iVar11 + 0xc),local_1c);
  puVar6 = local_24;
  local_24[0x21] = uVar8;
  if (local_1c[0] != 0) goto LAB_008c1252;
  pcVar12 = (char *)FUN_008ba000(uVar3,*(undefined4 *)(iVar7 + 0xc),local_1c);
  puVar6[0x22] = pcVar12;
  if (local_1c[0] != 0) goto LAB_008c1252;
  if ((((*pcVar12 != 'i') && (*pcVar12 != 'I')) || ((pcVar12[1] != 's' && (pcVar12[1] != 'S')))) ||
     ((pcVar12[2] != 'o' && (pcVar12[2] != 'O')))) goto LAB_008c11cd;
  pbVar15 = &DAT_00bd7c88;
  pbVar13 = (byte *)(pcVar12 + 3);
  do {
    bVar2 = *pbVar13;
    bVar17 = bVar2 < *pbVar15;
    if (bVar2 != *pbVar15) {
LAB_008c1156:
      iVar7 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
      goto LAB_008c115b;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar13[1];
    bVar17 = bVar2 < pbVar15[1];
    if (bVar2 != pbVar15[1]) goto LAB_008c1156;
    pbVar13 = pbVar13 + 2;
    pbVar15 = pbVar15 + 2;
  } while (bVar2 != 0);
  iVar7 = 0;
LAB_008c115b:
  if (iVar7 != 0) {
    pbVar15 = &DAT_00bd7c80;
    pbVar13 = (byte *)(pcVar12 + 3);
    do {
      bVar2 = *pbVar13;
      bVar17 = bVar2 < *pbVar15;
      if (bVar2 != *pbVar15) {
LAB_008c1187:
        iVar7 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
        goto LAB_008c118c;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar13[1];
      bVar17 = bVar2 < pbVar15[1];
      if (bVar2 != pbVar15[1]) goto LAB_008c1187;
      pbVar13 = pbVar13 + 2;
      pbVar15 = pbVar15 + 2;
    } while (bVar2 != 0);
    iVar7 = 0;
LAB_008c118c:
    if (iVar7 != 0) goto LAB_008c11cd;
    pbVar13 = (byte *)local_24[0x21];
    pbVar15 = &DAT_00c1ffdc;
    do {
      bVar2 = *pbVar13;
      bVar17 = bVar2 < *pbVar15;
      if (bVar2 != *pbVar15) {
LAB_008c11c0:
        iVar7 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
        goto LAB_008c11c5;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar13[1];
      bVar17 = bVar2 < pbVar15[1];
      if (bVar2 != pbVar15[1]) goto LAB_008c11c0;
      pbVar13 = pbVar13 + 2;
      pbVar15 = pbVar15 + 2;
    } while (bVar2 != 0);
    iVar7 = 0;
LAB_008c11c5:
    if (iVar7 != 0) goto LAB_008c11cd;
  }
  local_1d = '\x01';
LAB_008c11cd:
  local_34 = local_24;
  local_30 = 0;
  local_2c = 0;
  if (local_1d != '\0') {
    local_30 = 0x756e6963;
    local_2c = 0x10003;
  }
  FUN_008bcc30(&DAT_00bd7b10,0,&local_34,0);
  __security_check_cookie(local_1c[5] ^ (uint)&stack0xfffffffc);
  return;
}


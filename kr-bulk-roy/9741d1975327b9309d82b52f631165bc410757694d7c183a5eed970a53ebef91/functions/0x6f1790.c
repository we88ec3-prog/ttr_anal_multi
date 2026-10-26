
void FUN_006f1790(int param_1)

{
  byte bVar1;
  HWND pHVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_194;
  byte local_190 [256];
  undefined4 local_90;
  byte local_10 [8];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_190[0] = 0;
  _memset(local_190 + 1,0,0xff);
  local_10[0] = 0;
  local_10[1] = 0;
  local_10[2] = 0;
  local_10[3] = 0;
  local_10[4] = 0;
  local_10[5] = 0;
  local_10[6] = 0;
  local_10[7] = 0;
  local_90._0_1_ = 0;
  _memset((void *)((int)&local_90 + 1),0,0x7f);
  pHVar2 = GetForegroundWindow();
  if (pHVar2 == *(HWND *)(param_1 + 4)) {
    local_194 = 4;
    piVar8 = (int *)(param_1 + 0x18);
    do {
      if ((*piVar8 != 0) && (iVar3 = (**(code **)(*(int *)*piVar8 + 0x30))(), iVar3 != 0)) {
        iVar3 = (**(code **)(*(int *)*piVar8 + 0x1c))();
        if (iVar3 != 0) {
          iVar7 = 0;
          do {
            pbVar5 = local_190 + iVar7;
            *pbVar5 = *pbVar5 | -(pbVar5[iVar3 - (int)local_190] != 0) & 0x80U;
            local_190[iVar7 + 1] =
                 local_190[iVar7 + 1] | -(*(char *)(iVar3 + 1 + iVar7) != '\0') & 0x80U;
            local_190[iVar7 + 2] =
                 local_190[iVar7 + 2] | -(*(char *)(iVar3 + 2 + iVar7) != '\0') & 0x80U;
            local_190[iVar7 + 3] =
                 local_190[iVar7 + 3] | -(*(char *)(iVar3 + 3 + iVar7) != '\0') & 0x80U;
            iVar7 = iVar7 + 4;
          } while (iVar7 < 0x100);
        }
        iVar3 = (**(code **)(*(int *)*piVar8 + 0x24))();
        if (iVar3 != 0) {
          local_10[0] = local_10[0] | -(*(char *)(iVar3 + 0xc) != '\0') & 0x80U;
          local_10[1] = local_10[1] | -(*(char *)(iVar3 + 0xd) != '\0') & 0x80U;
          local_10[2] = local_10[2] | -(*(char *)(iVar3 + 0xe) != '\0') & 0x80U;
          local_10[3] = local_10[3] | -(*(char *)(iVar3 + 0xf) != '\0') & 0x80U;
          local_10[4] = local_10[4] | -(*(char *)(iVar3 + 0x10) != '\0') & 0x80U;
          local_10[5] = local_10[5] | -(*(char *)(iVar3 + 0x11) != '\0') & 0x80U;
          local_10[6] = local_10[6] | -(*(char *)(iVar3 + 0x12) != '\0') & 0x80U;
          local_10[7] = local_10[7] | -(*(char *)(iVar3 + 0x13) != '\0') & 0x80U;
        }
        iVar3 = (**(code **)(*(int *)*piVar8 + 0x20))();
        if (iVar3 != 0) {
          pbVar5 = (byte *)((int)&local_90 + 1);
          pcVar4 = (char *)(iVar3 + 0x31);
          iVar3 = 0x20;
          do {
            pbVar5[-1] = pbVar5[-1] | -(pcVar4[-1] != '\0') & 0x80U;
            *pbVar5 = *pbVar5 | -(*pcVar4 != '\0') & 0x80U;
            pbVar5[1] = pbVar5[1] | -(pcVar4[1] != '\0') & 0x80U;
            pbVar5[2] = pbVar5[2] | -(pcVar4[2] != '\0') & 0x80U;
            pcVar4 = pcVar4 + 4;
            pbVar5 = pbVar5 + 4;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      local_194 = local_194 + -1;
      piVar8 = piVar8 + -1;
    } while (-1 < local_194);
  }
  pbVar5 = local_190 + 1;
  pbVar6 = (byte *)(param_1 + 0x160);
  iVar3 = 0x40;
  do {
    bVar1 = pbVar6[-0x100];
    if (bVar1 == pbVar5[-1]) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    *pbVar6 = bVar1;
    bVar1 = pbVar6[-0xff];
    if (bVar1 == *pbVar5) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    pbVar6[1] = bVar1;
    bVar1 = pbVar6[-0xfe];
    if (bVar1 == pbVar5[1]) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    pbVar6[2] = bVar1;
    bVar1 = pbVar6[-0xfd];
    if (bVar1 == pbVar5[2]) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    pbVar6[3] = bVar1;
    pbVar6 = pbVar6 + 4;
    pbVar5 = pbVar5 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pbVar5 = local_10 + 1;
  pbVar6 = (byte *)(param_1 + 0x368);
  iVar3 = 2;
  do {
    bVar1 = pbVar6[-8];
    if (bVar1 == pbVar5[-1]) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    *pbVar6 = bVar1;
    bVar1 = pbVar6[-7];
    if (bVar1 == *pbVar5) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    pbVar6[1] = bVar1;
    bVar1 = pbVar6[-6];
    if (bVar1 == pbVar5[1]) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    pbVar6[2] = bVar1;
    bVar1 = pbVar6[-5];
    if (bVar1 == pbVar5[2]) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    pbVar6[3] = bVar1;
    pbVar6 = pbVar6 + 4;
    pbVar5 = pbVar5 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pbVar5 = (byte *)((int)&local_90 + 1);
  pbVar6 = (byte *)(param_1 + 0x3f8);
  iVar3 = 0x20;
  do {
    bVar1 = pbVar6[-0x80];
    if (bVar1 == pbVar5[-1]) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    *pbVar6 = bVar1;
    bVar1 = pbVar6[-0x7f];
    if (bVar1 == *pbVar5) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    pbVar6[1] = bVar1;
    bVar1 = pbVar6[-0x7e];
    if (bVar1 == pbVar5[1]) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    pbVar6[2] = bVar1;
    bVar1 = pbVar6[-0x7d];
    if (bVar1 == pbVar5[2]) {
      bVar1 = bVar1 >> 6 & 2;
    }
    else {
      bVar1 = (byte)((bVar1 | 0x40) >> 6);
    }
    pbVar6[3] = bVar1;
    pbVar6 = pbVar6 + 4;
    pbVar5 = pbVar5 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pbVar5 = local_190;
  puVar9 = (undefined4 *)(param_1 + 0x60);
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar9 = *(undefined4 *)pbVar5;
    pbVar5 = pbVar5 + 4;
    puVar9 = puVar9 + 1;
  }
  *(uint *)(param_1 + 0x360) =
       CONCAT13(local_10[3],CONCAT12(local_10[2],CONCAT11(local_10[1],local_10[0])));
  puVar9 = &local_90;
  puVar10 = (undefined4 *)(param_1 + 0x378);
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  *(uint *)(param_1 + 0x364) =
       CONCAT13(local_10[7],CONCAT12(local_10[6],CONCAT11(local_10[5],local_10[4])));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



int FUN_008fbff0(byte *param_1,uint *param_2,uint *param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  size_t _Size;
  undefined1 uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  void *_Src;
  byte *pbVar14;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  iVar10 = 0;
  local_8 = 0;
  if (param_1 == (byte *)0x0) {
    return 0x21;
  }
  uVar2 = *(undefined4 *)param_1;
  if ((byte)(*(char *)((int)param_2 + 0x12) - 1U) < 7) {
    iVar13 = *param_3 * param_3[2];
    if (iVar13 < 0) {
      iVar13 = -iVar13;
    }
    *(undefined1 *)((int)param_3 + 0x12) = 2;
    *param_3 = *param_2;
    param_3[1] = param_2[1];
    if (0 < param_4) {
      iVar10 = 0;
      if ((int)param_2[1] % param_4 != 0) {
        iVar10 = param_4 - (int)param_2[1] % param_4;
      }
    }
    uVar6 = param_2[1] + iVar10;
    param_3[2] = uVar6;
    if ((0 < (int)uVar6) && ((uint)(0xffffffff / (ulonglong)uVar6) < *param_3)) {
      return 6;
    }
    iVar10 = *param_3 * uVar6;
    if (iVar10 - iVar13 != 0 && iVar13 <= iVar10) {
      uVar6 = FUN_008baf40(uVar2,1,iVar13,iVar10,param_3[3],&local_8);
      param_3[3] = uVar6;
      if (local_8 != 0) {
        return local_8;
      }
    }
  }
  else {
    local_8 = 6;
  }
  switch(*(undefined1 *)((int)param_2 + 0x12)) {
  case 1:
    pbVar4 = (byte *)param_2[3];
    pbVar11 = (byte *)param_3[3];
    *(undefined2 *)(param_3 + 4) = 2;
    local_14 = *param_2;
    if (0 < (int)local_14) {
      do {
        pbVar14 = pbVar4;
        pbVar7 = pbVar11;
        for (iVar10 = (int)param_2[1] >> 3; 0 < iVar10; iVar10 = iVar10 + -1) {
          bVar1 = *pbVar14;
          uVar6 = (uint)bVar1;
          *pbVar7 = (byte)((int)uVar6 >> 7);
          pbVar7[1] = (byte)((int)uVar6 >> 6) & 1;
          pbVar7[2] = (byte)((int)uVar6 >> 5) & 1;
          pbVar7[3] = (byte)((int)uVar6 >> 4) & 1;
          pbVar7[4] = (byte)((int)uVar6 >> 3) & 1;
          pbVar7[5] = (byte)((int)uVar6 >> 2) & 1;
          pbVar7[7] = bVar1 & 1;
          pbVar7[6] = (byte)((int)uVar6 >> 1) & 1;
          pbVar14 = pbVar14 + 1;
          pbVar7 = pbVar7 + 8;
        }
        uVar6 = param_2[1] & 7;
        if (uVar6 != 0) {
          uVar5 = (uint)*pbVar14;
          do {
            *pbVar7 = (byte)((int)uVar5 >> 7) & 1;
            uVar6 = uVar6 - 1;
            uVar5 = uVar5 * 2;
            pbVar7 = pbVar7 + 1;
          } while (0 < (int)uVar6);
        }
        pbVar4 = pbVar4 + param_2[2];
        pbVar11 = pbVar11 + param_3[2];
        local_14 = local_14 - 1;
      } while (0 < (int)local_14);
      return local_8;
    }
    break;
  case 2:
  case 5:
  case 6:
    param_1 = (byte *)param_3[3];
    _Size = param_2[1];
    uVar6 = param_2[2];
    _Src = (void *)param_2[3];
    *(undefined2 *)(param_3 + 4) = 0x100;
    uVar5 = *param_2;
    uVar12 = param_3[2];
    if (0 < (int)uVar5) {
      do {
        FID_conflict__memcpy(param_1,_Src,_Size);
        _Src = (void *)((int)_Src + uVar6);
        param_1 = (byte *)((int)param_1 + uVar12);
        uVar5 = uVar5 - 1;
      } while (0 < (int)uVar5);
      return local_8;
    }
    break;
  case 3:
    pbVar4 = (byte *)param_2[3];
    pbVar11 = (byte *)param_3[3];
    *(undefined2 *)(param_3 + 4) = 4;
    local_c = *param_2;
    if (0 < (int)local_c) {
      do {
        pbVar14 = pbVar4;
        pbVar7 = pbVar11;
        for (iVar10 = (int)param_2[1] >> 2; 0 < iVar10; iVar10 = iVar10 + -1) {
          bVar1 = *pbVar14;
          uVar6 = (uint)bVar1;
          *pbVar7 = (byte)((int)uVar6 >> 6);
          pbVar7[1] = (byte)((int)uVar6 >> 4) & 3;
          pbVar7[3] = bVar1 & 3;
          pbVar7[2] = (byte)((int)uVar6 >> 2) & 3;
          pbVar14 = pbVar14 + 1;
          pbVar7 = pbVar7 + 4;
        }
        uVar6 = param_2[1] & 3;
        if (uVar6 != 0) {
          uVar5 = (uint)*pbVar14;
          do {
            *pbVar7 = (byte)((int)uVar5 >> 6) & 3;
            uVar6 = uVar6 - 1;
            uVar5 = uVar5 * 4;
            pbVar7 = pbVar7 + 1;
          } while (0 < (int)uVar6);
        }
        pbVar4 = pbVar4 + param_2[2];
        pbVar11 = pbVar11 + param_3[2];
        local_c = local_c - 1;
      } while (0 < (int)local_c);
      return local_8;
    }
    break;
  case 4:
    param_1 = (byte *)param_3[3];
    pbVar4 = (byte *)param_2[3];
    *(undefined2 *)(param_3 + 4) = 0x10;
    local_10 = *param_2;
    if (0 < (int)local_10) {
      do {
        pbVar11 = pbVar4;
        pbVar14 = param_1;
        for (iVar10 = (int)param_2[1] >> 1; 0 < iVar10; iVar10 = iVar10 + -1) {
          bVar1 = *pbVar11;
          *pbVar14 = (byte)((int)(uint)bVar1 >> 4);
          pbVar14[1] = bVar1 & 0xf;
          pbVar11 = pbVar11 + 1;
          pbVar14 = pbVar14 + 2;
        }
        if ((param_2[1] & 1) != 0) {
          *pbVar14 = *pbVar11 >> 4;
        }
        pbVar4 = pbVar4 + param_2[2];
        param_1 = param_1 + param_3[2];
        local_10 = local_10 - 1;
      } while (0 < (int)local_10);
      return local_8;
    }
    break;
  case 7:
    puVar9 = (undefined1 *)param_3[3];
    uVar6 = param_3[2];
    *(undefined2 *)(param_3 + 4) = 0x100;
    for (uVar5 = *param_2; 0 < (int)uVar5; uVar5 = uVar5 - 1) {
      puVar8 = puVar9;
      for (uVar12 = param_2[1]; 0 < (int)uVar12; uVar12 = uVar12 - 1) {
        uVar3 = FUN_008fbe60();
        *puVar8 = uVar3;
        puVar8 = puVar8 + 1;
      }
      puVar9 = puVar9 + uVar6;
    }
  }
  return local_8;
}


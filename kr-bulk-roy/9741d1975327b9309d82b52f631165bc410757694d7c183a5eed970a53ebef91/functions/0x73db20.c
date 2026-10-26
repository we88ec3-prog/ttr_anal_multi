
undefined4 FUN_0073db20(int param_1,int param_2,short *param_3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  bool bVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  short *psVar10;
  int iVar11;
  uint uVar12;
  float fVar13;
  void *_Dst;
  float10 fVar14;
  uint uVar15;
  int local_70;
  uint *local_6c;
  uint *local_68;
  int local_64;
  int local_60;
  int local_5c;
  float local_58;
  float local_54;
  int local_50;
  int local_4c;
  int local_48 [17];
  
  local_54 = 0.0;
  FUN_0073da10(param_1,param_2,param_3,0xffffffff,0,&local_50);
  local_68 = (uint *)(local_4c << 6);
  local_64 = local_50 << 6;
  local_50 = *(int *)(*(int *)(param_2 + 8) + 0x58);
  local_60 = (int)*(short *)(local_50 + 0x46);
  lVar4 = (longlong)local_60 * (longlong)*(int *)(*(int *)(local_50 + 0x58) + 0x14);
  lVar4 = lVar4 + (ulonglong)((int)(lVar4 >> 0x3f) + 0x8000);
  local_5c = ((uint)lVar4 >> 0x10) + (int)((ulonglong)lVar4 >> 0x20) * 0x10000;
  local_70 = 0;
  bVar5 = false;
  if ((*(int *)(param_2 + 0x18) != 0) && (*(int *)(*(int *)(param_2 + 8) + 0x50) == 0)) {
    bVar5 = true;
  }
  _Dst = *(void **)(param_1 + 0x44);
  local_58 = (float)local_64 * 0.015625;
  fVar14 = (float10)FUN_00892d30((double)local_58);
  local_58 = (float)fVar14;
  iVar7 = FUN_008fed10();
  iVar7 = iVar7 + 0x20;
  local_58 = (float)(int)local_68 * 0.015625;
  fVar14 = (float10)FUN_00892d30((double)local_58);
  local_58 = (float)fVar14;
  iVar8 = FUN_008fed10();
  iVar8 = iVar8 + 0x10;
  if (0x800 < iVar7) {
    iVar7 = 0x800;
  }
  if (0x300 < iVar8) {
    iVar8 = 0x300;
  }
  if (0 < iVar8) {
    do {
      _memset(_Dst,0,iVar7 * 4);
      _Dst = (void *)((int)_Dst + 0x2000);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  local_58 = 0.0;
  psVar10 = param_3;
  do {
    sVar1 = *psVar10;
    psVar10 = psVar10 + 1;
  } while (sVar1 != 0);
  if ((int)psVar10 - (int)(param_3 + 1) >> 1 != 0) {
    do {
      fVar13 = local_58;
      iVar8 = 0;
      local_6c = (uint *)0x0;
      iVar7 = FUN_0073ffa0(param_2,&local_6c);
      if ((iVar7 == 0) &&
         ((local_6c != (uint *)0x0 ||
          (((iVar8 = FUN_0073d5e0(), iVar8 != 0 &&
            (iVar7 = FUN_0073ffa0(iVar8,&local_6c), iVar7 == 0)) && (local_6c != (uint *)0x0)))))) {
        puVar6 = local_6c;
        if (local_6c[0xb] == 0) {
          FUN_00740500();
        }
        if ((local_54 != 0.0) && (puVar6[1] != 0)) {
          if (iVar8 == 0) {
            uVar15 = puVar6[1];
            iVar7 = local_50;
          }
          else {
            uVar15 = puVar6[1];
            iVar7 = *(int *)(*(int *)(iVar8 + 8) + 0x58);
          }
          FUN_008b8b80(iVar7,local_54,uVar15,ZEXT48(local_48) << 0x20);
          local_70 = local_70 + local_48[0];
        }
        local_54 = (float)local_70 * 0.015625 + 0.5;
        fVar14 = (float10)FUN_008ff2e0((double)local_54);
        local_54 = (float)fVar14;
        iVar7 = FUN_008fed10();
        iVar7 = iVar7 + puVar6[7];
        local_54 = (float)local_5c * 0.015625 + 0.5;
        fVar14 = (float10)FUN_008ff2e0();
        local_54 = (float)fVar14;
        iVar8 = FUN_008fed10();
        iVar8 = iVar8 - puVar6[8];
        iVar11 = 0;
        local_64 = 0;
        if (iVar7 < 0) {
          local_64 = -iVar7;
          iVar7 = 0;
        }
        if (iVar8 < 0) {
          iVar11 = -iVar8;
          iVar8 = 0;
        }
        local_6c = (uint *)(*(int *)(param_1 + 0x44) + (iVar8 * 0x800 + iVar7) * 4);
        if (((int)(puVar6[3] + iVar7) < 0x800) &&
           (uVar15 = puVar6[2], (int)(iVar8 + uVar15) < 0x300)) {
          local_60 = iVar11;
          if (bVar5) {
            if (iVar11 < (int)uVar15) {
              local_68 = local_6c + 1;
              do {
                uVar15 = puVar6[0xc];
                uVar2 = puVar6[0xb];
                local_54 = (float)(puVar6[3] - local_64);
                if (local_54 != 0.0) {
                  puVar9 = local_6c;
                  do {
                    uVar3 = *(uint *)(((uVar2 + (((int)uVar15 >> 2) * iVar11 + local_64) * 4) -
                                      (int)local_6c) + (int)puVar9);
                    uVar12 = *puVar9;
                    if (*puVar9 <= uVar3) {
                      uVar12 = uVar3;
                    }
                    *puVar9 = uVar12;
                    puVar9 = puVar9 + 1;
                    local_54 = (float)((int)local_54 + -1);
                  } while (local_54 != 0.0);
                }
                uVar15 = puVar6[0xc];
                uVar2 = puVar6[0xb];
                iVar7 = puVar6[3] - local_64;
                if (iVar7 != 0) {
                  puVar9 = local_68;
                  do {
                    uVar3 = *(uint *)((int)puVar9 +
                                     ((uVar2 + (((int)uVar15 >> 2) * iVar11 + local_64) * 4) -
                                     (int)local_68));
                    uVar12 = *puVar9;
                    if (*puVar9 <= uVar3) {
                      uVar12 = uVar3;
                    }
                    *puVar9 = uVar12;
                    puVar9 = puVar9 + 1;
                    iVar7 = iVar7 + -1;
                  } while (iVar7 != 0);
                }
                local_6c = local_6c + 0x800;
                local_68 = local_68 + 0x800;
                iVar11 = iVar11 + 1;
                local_60 = iVar11;
              } while (iVar11 < (int)puVar6[2]);
            }
          }
          else if (iVar11 < (int)uVar15) {
            do {
              uVar15 = puVar6[0xc];
              iVar7 = puVar6[3] - local_64;
              uVar2 = puVar6[0xb];
              if (iVar7 != 0) {
                puVar9 = local_6c;
                do {
                  uVar3 = *(uint *)(((uVar2 + (((int)uVar15 >> 2) * iVar11 + local_64) * 4) -
                                    (int)local_6c) + (int)puVar9);
                  uVar12 = *puVar9;
                  if (*puVar9 <= uVar3) {
                    uVar12 = uVar3;
                  }
                  *puVar9 = uVar12;
                  puVar9 = puVar9 + 1;
                  iVar7 = iVar7 + -1;
                } while (iVar7 != 0);
              }
              iVar11 = iVar11 + 1;
              local_6c = local_6c + 0x800;
              local_60 = iVar11;
            } while (iVar11 < (int)puVar6[2]);
          }
        }
        local_54 = (float)puVar6[1];
        local_70 = local_70 + puVar6[9];
        local_5c = local_5c + puVar6[10];
        fVar13 = local_58;
        if (bVar5) {
          local_70 = local_70 + 0x40;
        }
      }
      local_58 = (float)((int)fVar13 + 1);
      psVar10 = param_3;
      do {
        sVar1 = *psVar10;
        psVar10 = psVar10 + 1;
      } while (sVar1 != 0);
    } while ((uint)local_58 < (uint)((int)psVar10 - (int)(param_3 + 1) >> 1));
  }
  return 1;
}



void FUN_008ce8e0(uint *param_1,short *param_2,int param_3,uint *param_4)

{
  uint *puVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  char cVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  uint *puVar15;
  uint *puVar16;
  int iVar17;
  int iVar18;
  uint local_10;
  uint local_c;
  uint *local_8;
  
  _memset(param_1,0,0x80);
  uVar3 = *param_4;
  param_1[4] = uVar3;
  uVar12 = FUN_008bc7d0(uVar3,0x28,0,(int)param_2[1],0,&local_10);
  param_1[2] = uVar12;
  if (local_10 == 0) {
    puVar13 = (undefined4 *)FUN_008bc7d0(uVar3,8,0,(int)*param_2,0,&local_10);
    param_1[3] = (uint)puVar13;
    if (local_10 == 0) {
      *param_1 = (int)param_2[1];
      sVar2 = *param_2;
      local_8 = (uint *)param_1[2];
      param_1[1] = (int)sVar2;
      local_c = local_10;
      if ((int)sVar2 != 0) {
        iVar14 = 0;
        do {
          iVar18 = (int)*(short *)(*(int *)(param_2 + 6) + local_c * 2);
          iVar17 = (iVar18 + 1) - iVar14;
          puVar1 = local_8 + iVar14 * 10;
          *puVar13 = puVar1;
          puVar13[1] = iVar17;
          if (0 < iVar17) {
            *puVar1 = (uint)(local_8 + (iVar18 * 5 + 5) * 2 + -10);
            puVar1[2] = (uint)puVar13;
            puVar16 = puVar1;
            if (1 < iVar17) {
              iVar17 = iVar17 + -1;
              puVar15 = puVar1;
              do {
                iVar17 = iVar17 + -1;
                puVar16 = puVar15 + 10;
                puVar15[1] = (uint)puVar16;
                *puVar16 = (uint)puVar15;
                puVar15[0xc] = (uint)puVar13;
                puVar15 = puVar16;
              } while (iVar17 != 0);
            }
            puVar16[1] = (uint)puVar1;
          }
          local_c = local_c + 1;
          puVar13 = puVar13 + 2;
          iVar14 = iVar18 + 1;
        } while (local_c < param_1[1]);
      }
      uVar3 = param_1[2];
      iVar14 = *(int *)(param_2 + 2);
      local_c = 0;
      if (*param_1 != 0) {
        local_8 = (uint *)(uVar3 + 0xc);
        do {
          iVar17 = (int)(local_8[-3] - uVar3) / 0x28;
          iVar18 = (int)(local_8[-2] - uVar3) / 0x28;
          if ((*(byte *)(local_c + *(int *)(param_2 + 4)) & 1) == 0) {
            *local_8 = 1;
          }
          iVar4 = *(int *)(iVar14 + local_c * 8);
          iVar5 = *(int *)(iVar14 + 4 + local_c * 8);
          iVar6 = *(int *)(iVar14 + iVar17 * 8);
          iVar17 = *(int *)(iVar14 + 4 + iVar17 * 8);
          cVar10 = FUN_008ce7e0();
          *(char *)(local_8 + 2) = cVar10;
          iVar7 = *(int *)(iVar14 + iVar18 * 8);
          iVar18 = *(int *)(iVar14 + 4 + iVar18 * 8);
          iVar8 = *(int *)(iVar14 + local_c * 8);
          iVar9 = *(int *)(iVar14 + 4 + local_c * 8);
          cVar11 = FUN_008ce7e0();
          *(char *)((int)local_8 + 9) = cVar11;
          if ((*local_8 & 1) == 0) {
            if ((cVar10 == cVar11) &&
               ((cVar11 != '\x04' ||
                (iVar17 = FUN_008b8270(iVar4 - iVar6,iVar5 - iVar17,iVar7 - iVar8,iVar18 - iVar9),
                iVar17 != 0)))) {
              *local_8 = *local_8 | 2;
            }
          }
          else {
            *local_8 = *local_8 | 2;
          }
          local_c = local_c + 1;
          local_8 = local_8 + 10;
        } while (local_c < *param_1);
      }
      param_1[6] = (uint)param_4;
      param_1[5] = (uint)param_2;
      FUN_008ce830();
      FUN_008ce640(param_1);
      local_10 = FUN_008ce0c0(param_3 + 0x10,param_3 + 0x1c);
      if (local_10 == 0) {
        FUN_008ce0c0(param_3 + 0x34,param_3 + 0x40);
      }
    }
  }
  return;
}


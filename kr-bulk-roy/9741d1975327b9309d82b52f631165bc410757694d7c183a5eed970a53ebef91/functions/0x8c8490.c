
void FUN_008c8490(int param_1)

{
  byte bVar1;
  short *psVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short *psVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  byte *local_10;
  int local_c;
  byte *local_8;
  
  iVar6 = 0;
  local_8 = (byte *)0x0;
  if (*(int *)(param_1 + 0x298) == 0) {
    iVar9 = -1;
    iVar8 = -1;
    if (*(short *)(param_1 + 0x154) != 0) {
      psVar2 = *(short **)(param_1 + 0x164);
      psVar5 = psVar2;
      do {
        if ((psVar5[3] == 6) && (psVar5[4] != 0)) {
          if ((*psVar5 == 3) && ((psVar5[1] == 1 && (psVar5[2] == 0x409)))) {
            iVar9 = iVar6;
          }
          if (((*psVar5 == 1) && (psVar5[1] == 0)) && (psVar5[2] == 0)) {
            iVar8 = iVar6;
          }
        }
        iVar6 = iVar6 + 1;
        psVar5 = psVar5 + 10;
      } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x154));
      if (iVar9 == -1) {
        if (iVar8 != -1) {
          uVar3 = *(undefined4 *)(param_1 + 100);
          uVar10 = (uint)(ushort)psVar2[iVar8 * 10 + 4];
          local_c = 0;
          local_8 = (byte *)FUN_008baee0(uVar3,uVar10 + 1,&local_c);
          if (local_c == 0) {
            uVar4 = *(undefined4 *)(param_1 + 0x168);
            local_c = FUN_008b97e0(uVar4,*(undefined4 *)(psVar2 + iVar8 * 10 + 6));
            if ((local_c == 0) && (local_c = FUN_008bab70(uVar4,local_8,uVar10), local_c == 0)) {
              local_8[uVar10] = 0;
              *(byte **)(param_1 + 0x298) = local_8;
              return;
            }
            uVar4 = *(undefined4 *)(psVar2 + iVar8 * 10 + 8);
            (psVar2 + iVar8 * 10 + 6)[0] = 0;
            (psVar2 + iVar8 * 10 + 6)[1] = 0;
            psVar2[iVar8 * 10 + 4] = 0;
            FUN_008b9f80(uVar3,uVar4);
            (psVar2 + iVar8 * 10 + 8)[0] = 0;
            (psVar2 + iVar8 * 10 + 8)[1] = 0;
            FUN_008b9f80(uVar3,local_8);
            local_8 = (byte *)0x0;
          }
        }
      }
      else {
        uVar3 = *(undefined4 *)(param_1 + 100);
        local_c = 0;
        uVar10 = (uint)((ushort)psVar2[iVar9 * 10 + 4] >> 1);
        local_10 = (byte *)FUN_008baee0(uVar3,(ushort)psVar2[iVar9 * 10 + 4] + 1,&local_c);
        local_8 = local_10;
        if (local_c == 0) {
          iVar6 = *(int *)(param_1 + 0x168);
          local_c = FUN_008b97e0(iVar6,*(undefined4 *)(psVar2 + iVar9 * 10 + 6));
          if ((local_c == 0) && (local_c = FUN_008babe0(iVar6,psVar2[iVar9 * 10 + 4]), local_c == 0)
             ) {
            pcVar7 = *(char **)(iVar6 + 0x20);
            for (; uVar10 != 0; uVar10 = uVar10 - 1) {
              if (((*pcVar7 == '\0') && (bVar1 = pcVar7[1], 0x1f < bVar1)) && (bVar1 < 0x80)) {
                *local_10 = bVar1;
                local_10 = local_10 + 1;
              }
              pcVar7 = pcVar7 + 2;
            }
            *local_10 = 0;
            FUN_008baca0(iVar6);
            *(byte **)(param_1 + 0x298) = local_8;
            return;
          }
          FUN_008b9f80(uVar3,local_8);
          uVar4 = *(undefined4 *)(psVar2 + iVar9 * 10 + 8);
          local_8 = (byte *)0x0;
          psVar2[iVar9 * 10 + 4] = 0;
          (psVar2 + iVar9 * 10 + 6)[0] = 0;
          (psVar2 + iVar9 * 10 + 6)[1] = 0;
          FUN_008b9f80(uVar3,uVar4);
          (psVar2 + iVar9 * 10 + 8)[0] = 0;
          (psVar2 + iVar9 * 10 + 8)[1] = 0;
        }
      }
    }
    *(byte **)(param_1 + 0x298) = local_8;
  }
  return;
}


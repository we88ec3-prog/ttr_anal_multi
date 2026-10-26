
void FUN_008e62a0(int param_1,int *param_2)

{
  int iVar1;
  byte bVar2;
  int *piVar3;
  uint *puVar4;
  int *piVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 uVar9;
  char *pcVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  int local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  int local_44 [15];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar9 = *(undefined4 *)(param_1 + 100);
  piVar3 = *(int **)(param_1 + 0x210);
  local_58 = FUN_008e60e0(param_1,&local_50);
  uVar11 = local_50;
  if ((local_58 == 0) &&
     (puVar4 = (uint *)FUN_008baee0(uVar9,local_50 * 0x18 + 0x14,&local_58), local_58 == 0)) {
    *puVar4 = uVar11;
    puVar4[1] = local_4c;
    puVar4[2] = 0xffffffff;
    puVar4[3] = (uint)(puVar4 + 5);
    puVar4[4] = 0;
    if (uVar11 != 0) {
      piVar5 = local_44;
      iVar12 = 0;
      local_54 = uVar11;
      do {
        *(int *)(iVar12 + puVar4[3]) = piVar5[-1];
        *(int *)(puVar4[3] + 4 + iVar12) = *piVar5 << 0x10;
        *(int *)(puVar4[3] + 0xc + iVar12) = piVar5[1] << 0x10;
        uVar11 = puVar4[3];
        *(int *)(uVar11 + 8 + iVar12) =
             (*(int *)(uVar11 + 0xc + iVar12) + *(int *)(uVar11 + 4 + iVar12)) / 2;
        *(undefined4 *)(puVar4[3] + 0x14 + iVar12) = 0xffffffff;
        *(undefined4 *)(puVar4[3] + 0x10 + iVar12) = 0xffffffff;
        pbVar8 = *(byte **)(puVar4[3] + iVar12);
        iVar1 = puVar4[3] + iVar12;
        pcVar10 = "Weight";
        pbVar6 = pbVar8;
        do {
          bVar2 = *pbVar6;
          bVar14 = bVar2 < (byte)*pcVar10;
          if (bVar2 != *pcVar10) {
LAB_008e63c0:
            iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
            goto LAB_008e63c5;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar6[1];
          bVar14 = bVar2 < (byte)pcVar10[1];
          if (bVar2 != pcVar10[1]) goto LAB_008e63c0;
          pbVar6 = pbVar6 + 2;
          pcVar10 = pcVar10 + 2;
        } while (bVar2 != 0);
        iVar7 = 0;
LAB_008e63c5:
        if (iVar7 == 0) {
          *(undefined4 *)(iVar1 + 0x10) = 0x77676874;
        }
        else {
          pcVar10 = "Width";
          pbVar6 = pbVar8;
          do {
            bVar2 = *pbVar6;
            bVar14 = bVar2 < (byte)*pcVar10;
            if (bVar2 != *pcVar10) {
LAB_008e6400:
              iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
              goto LAB_008e6405;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar6[1];
            bVar14 = bVar2 < (byte)pcVar10[1];
            if (bVar2 != pcVar10[1]) goto LAB_008e6400;
            pbVar6 = pbVar6 + 2;
            pcVar10 = pcVar10 + 2;
          } while (bVar2 != 0);
          iVar7 = 0;
LAB_008e6405:
          if (iVar7 == 0) {
            *(undefined4 *)(iVar1 + 0x10) = 0x77647468;
          }
          else {
            pcVar10 = "OpticalSize";
            do {
              bVar2 = *pbVar8;
              bVar14 = bVar2 < (byte)*pcVar10;
              if (bVar2 != *pcVar10) {
LAB_008e6440:
                iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                goto LAB_008e6445;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar8[1];
              bVar14 = bVar2 < (byte)pcVar10[1];
              if (bVar2 != pcVar10[1]) goto LAB_008e6440;
              pbVar8 = pbVar8 + 2;
              pcVar10 = pcVar10 + 2;
            } while (bVar2 != 0);
            iVar7 = 0;
LAB_008e6445:
            if (iVar7 == 0) {
              *(undefined4 *)(iVar1 + 0x10) = 0x6f70737a;
            }
          }
        }
        piVar5 = piVar5 + 3;
        iVar12 = iVar12 + 0x18;
        local_54 = local_54 - 1;
      } while (local_54 != 0);
      local_54 = 0;
      uVar11 = local_50;
    }
    if (*piVar3 == 1 << ((byte)piVar3[1] & 0x1f)) {
      FUN_008e61e0();
      uVar13 = 0;
      if (uVar11 != 0) {
        local_54 = 0;
        do {
          uVar9 = FUN_008e6160();
          *(undefined4 *)(puVar4[3] + 8 + local_54) = uVar9;
          uVar13 = uVar13 + 1;
          local_54 = local_54 + 0x18;
        } while (uVar13 < local_50);
      }
    }
    *param_2 = (int)puVar4;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


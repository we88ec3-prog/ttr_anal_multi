
int FUN_008d9dc0(int param_1,char param_2)

{
  byte bVar1;
  byte bVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint in_ECX;
  int iVar7;
  int iVar8;
  uint *unaff_ESI;
  byte *pbVar9;
  byte *local_c;
  int local_8;
  
  local_8 = FUN_008b97e0(param_1);
  if (local_8 == 0) {
    uVar4 = FUN_008b9ab0(param_1,&local_8);
    if (local_8 == 0) {
      if ((uVar4 & 0xffff) <= in_ECX) {
        return 6;
      }
      local_8 = FUN_008b9820(param_1,in_ECX * 5);
      if (local_8 == 0) {
        uVar4 = FUN_008b9ab0(param_1,&local_8);
        uVar4 = uVar4 & 0xffff;
        if ((local_8 == 0) && (uVar5 = FUN_008b9b90(param_1,&local_8), local_8 == 0)) {
          *unaff_ESI = uVar4;
          unaff_ESI[1] = uVar5;
          local_8 = FUN_008b97e0(param_1,uVar5);
          if ((local_8 == 0) && (local_8 = FUN_008babe0(param_1,uVar4), local_8 == 0)) {
            puVar3 = *(undefined1 **)(param_1 + 0x20);
            pbVar9 = puVar3 + uVar4;
            if (puVar3 + 0xd <= pbVar9) {
              unaff_ESI[2] = (uint)CONCAT21(CONCAT11(*puVar3,puVar3[1]),puVar3[2]);
              unaff_ESI[3] = (uint)CONCAT21(CONCAT11(puVar3[3],puVar3[4]),puVar3[5]);
              unaff_ESI[4] = (uint)CONCAT21(CONCAT11(puVar3[6],puVar3[7]),puVar3[8]);
              unaff_ESI[5] = (uint)CONCAT21(CONCAT11(puVar3[9],puVar3[10]),puVar3[0xb]);
              bVar1 = puVar3[0xc];
              local_c = puVar3 + 0xd;
              iVar7 = 0;
              if ((bVar1 & 4) != 0) {
                iVar7 = 1;
                if ((bVar1 & 8) != 0) {
                  iVar7 = 2;
                }
                if ((bVar1 & 3) == 0) {
                  iVar7 = iVar7 + 3;
                }
              }
              iVar8 = iVar7;
              if (((bVar1 & 0x10) != 0) && (iVar8 = iVar7 + 1, (bVar1 & 0x20) != 0)) {
                iVar8 = iVar7 + 2;
              }
              if (local_c + iVar8 <= pbVar9) {
                if ((bVar1 & 4) != 0) {
                  if ((bVar1 & 8) == 0) {
                    uVar4 = (uint)*local_c;
                    pbVar6 = puVar3 + 0xe;
                  }
                  else {
                    pbVar6 = puVar3 + 0xf;
                    uVar4 = (int)(short)((ushort)*local_c << 8) | (uint)(byte)puVar3[0xe];
                  }
                  unaff_ESI[7] = uVar4;
                  local_c = pbVar6;
                  if ((bVar1 & 3) == 0) {
                    local_c = pbVar6 + 3;
                    unaff_ESI[9] = (uint)CONCAT21(CONCAT11(*pbVar6,pbVar6[1]),pbVar6[2]);
                  }
                }
                if ((bVar1 & 0x10) != 0) {
                  if ((bVar1 & 0x20) == 0) {
                    uVar4 = (uint)*local_c;
                    local_c = local_c + 1;
                  }
                  else {
                    bVar2 = *local_c;
                    pbVar6 = local_c + 1;
                    local_c = local_c + 2;
                    uVar4 = (int)(short)((ushort)bVar2 << 8) | (uint)*pbVar6;
                  }
                  unaff_ESI[8] = uVar4;
                }
                iVar7 = 0;
                if (((bVar1 & 0x40) == 0) ||
                   (local_8 = FUN_008d9da0(), iVar7 = local_8, local_8 == 0)) {
                  local_8 = iVar7;
                  if (pbVar9 < local_c + 5) goto LAB_008da017;
                  unaff_ESI[10] = (uint)CONCAT11(*local_c,local_c[1]);
                  unaff_ESI[0xb] = (uint)CONCAT21(CONCAT11(local_c[2],local_c[3]),local_c[4]);
                  if (param_2 != '\0') {
                    if (pbVar9 < local_c + 6) goto LAB_008da017;
                    unaff_ESI[10] = unaff_ESI[10] + (uint)local_c[5] * 0x10000;
                  }
                }
                FUN_008baca0(param_1);
                return local_8;
              }
            }
LAB_008da017:
            local_8 = 8;
            FUN_008baca0(param_1);
            return local_8;
          }
        }
      }
    }
  }
  return local_8;
}


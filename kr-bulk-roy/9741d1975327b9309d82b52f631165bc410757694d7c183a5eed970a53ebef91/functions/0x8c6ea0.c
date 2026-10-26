
uint FUN_008c6ea0(int param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int local_20;
  uint local_18;
  uint local_14;
  uint local_c;
  uint local_8;
  
  local_20 = *(int *)(param_1 + 0x2ec);
  uVar8 = *(int *)(param_1 + 0x2e8) + *(int *)(param_1 + 0x2e4);
  local_8 = 0;
  local_c = 1;
  uVar4 = *(int *)(param_1 + 0x2e4) + 4;
  if (local_20 == 0) {
    return 0;
  }
  do {
    if (uVar8 < uVar4 + 6) {
      return local_8;
    }
    uVar7 = CONCAT11(*(undefined1 *)(uVar4 + 2),*(undefined1 *)(uVar4 + 3)) + uVar4;
    if (uVar8 < uVar7) {
      uVar7 = uVar8;
    }
    uVar3 = local_8;
    if (((*(uint *)(param_1 + 0x2f0) & local_c) != 0) && (uVar4 + 0xe <= uVar7)) {
      local_14 = (uint)CONCAT11(*(undefined1 *)(uVar4 + 6),*(undefined1 *)(uVar4 + 7));
      puVar5 = (undefined1 *)(uVar4 + 0xe);
      if ((int)(uVar7 - (int)puVar5) < (int)(local_14 * 6)) {
        local_14 = (int)(uVar7 - (int)puVar5) / 6;
      }
      if (*(char *)(uVar4 + 4) == '\0') {
        uVar9 = param_2 << 0x10 | param_3;
        if ((*(uint *)(param_1 + 0x2f4) & local_c) == 0) {
          for (; local_14 != 0; local_14 = local_14 - 1) {
            if (CONCAT31(CONCAT21(CONCAT11(*puVar5,puVar5[1]),puVar5[2]),puVar5[3]) == uVar9) {
              uVar3 = (int)(short)((ushort)(byte)puVar5[4] << 8) | (uint)(byte)puVar5[5];
              goto LAB_008c7049;
            }
            puVar5 = puVar5 + 6;
          }
        }
        else {
          local_18 = 0;
          if (local_14 != 0) {
LAB_008c6fa6:
            uVar6 = local_14 + local_18 >> 1;
            pbVar1 = (byte *)(uVar4 + 0x12 + uVar6 * 6);
            uVar2 = CONCAT31(CONCAT21(CONCAT11(pbVar1[-4],*(undefined1 *)(uVar4 + 0xf + uVar6 * 6)),
                                      pbVar1[-2]),pbVar1[-1]);
            if (uVar2 != uVar9) break;
            uVar3 = (int)(short)((ushort)*pbVar1 << 8) | (uint)pbVar1[1];
LAB_008c7049:
            if ((*(byte *)(uVar4 + 5) & 8) == 0) {
              uVar3 = local_8 + uVar3;
            }
          }
        }
      }
    }
LAB_008c7057:
    local_8 = uVar3;
    local_c = local_c << 1;
    local_20 = local_20 + -1;
    uVar4 = uVar7;
    if (local_20 == 0) {
      return local_8;
    }
  } while( true );
  if (uVar2 < uVar9) {
    local_18 = uVar6 + 1;
    uVar6 = local_14;
  }
  local_14 = uVar6;
  if (local_14 <= local_18) goto LAB_008c7057;
  goto LAB_008c6fa6;
}


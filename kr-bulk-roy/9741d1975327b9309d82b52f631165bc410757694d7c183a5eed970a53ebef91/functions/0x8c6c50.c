
int FUN_008c6c50(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_c;
  uint local_8;
  
  local_1c = 0;
  local_20 = 0;
  iVar2 = (**(code **)(param_1 + 0x1fc))(param_1,0x6b65726e,param_2,&local_24);
  if (iVar2 == 0) {
    if (local_24 < 4) {
      return 0x8e;
    }
    iVar2 = FUN_008bc7a0(param_2,local_24,(int *)(param_1 + 0x2e4));
    if (iVar2 == 0) {
      iVar7 = *(int *)(param_1 + 0x2e4);
      uVar1 = iVar7 + local_24;
      *(uint *)(param_1 + 0x2e8) = local_24;
      local_c = (uint)CONCAT11(*(undefined1 *)(iVar7 + 2),*(undefined1 *)(iVar7 + 3));
      if (0x20 < local_c) {
        local_c = 0x20;
      }
      local_18 = 0;
      local_8 = 1;
      uVar5 = iVar7 + 4;
      if (local_c != 0) {
        do {
          if (uVar1 < uVar5 + 6) break;
          uVar3 = (uint)CONCAT11(*(undefined1 *)(uVar5 + 2),*(undefined1 *)(uVar5 + 3));
          if (uVar3 < 7) break;
          uVar3 = uVar5 + uVar3;
          if (uVar1 < uVar3) {
            uVar3 = uVar1;
          }
          if (((CONCAT11(*(undefined1 *)(uVar5 + 4),*(undefined1 *)(uVar5 + 5)) & 0xfff7) == 1) &&
             (uVar5 + 0xe <= uVar1)) {
            uVar4 = (uint)CONCAT11(*(undefined1 *)(uVar5 + 6),*(undefined1 *)(uVar5 + 7));
            iVar7 = uVar3 - (int)(uVar5 + 0xe);
            if (iVar7 < (int)(uVar4 * 6)) {
              uVar4 = iVar7 / 6;
            }
            local_1c = local_1c | local_8;
            if (uVar4 != 0) {
              local_14 = uVar4 - 1;
              if (local_14 != 0) {
                iVar7 = uVar5 + 0x13;
                iVar9 = uVar5 + 0x12;
                iVar8 = uVar5 + 0x11;
                iVar6 = uVar5 + 0x10;
                uVar5 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar5 + 0xe),
                                                   *(undefined1 *)(uVar5 + 0xf)),
                                          *(undefined1 *)(uVar5 + 0x10)),
                                 *(undefined1 *)(uVar5 + 0x11));
                do {
                  uVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar6 + 4),
                                                     *(undefined1 *)(iVar8 + 4)),
                                            *(undefined1 *)(iVar9 + 4)),*(undefined1 *)(iVar7 + 4));
                  if (uVar4 <= uVar5) break;
                  iVar6 = iVar6 + 6;
                  iVar8 = iVar8 + 6;
                  iVar9 = iVar9 + 6;
                  iVar7 = iVar7 + 6;
                  local_14 = local_14 + -1;
                  uVar5 = uVar4;
                } while (local_14 != 0);
              }
              if (local_14 == 0) {
                local_20 = local_20 | local_8;
              }
            }
          }
          local_18 = local_18 + 1;
          local_8 = local_8 << 1 | (uint)((int)local_8 < 0);
          uVar5 = uVar3;
        } while (local_18 < local_c);
      }
      *(uint *)(param_1 + 0x2ec) = local_18;
      *(uint *)(param_1 + 0x2f0) = local_1c;
      *(uint *)(param_1 + 0x2f4) = local_20;
    }
  }
  return iVar2;
}


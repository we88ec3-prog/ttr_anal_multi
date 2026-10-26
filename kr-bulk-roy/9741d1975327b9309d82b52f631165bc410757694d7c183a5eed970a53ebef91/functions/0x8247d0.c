
/* WARNING: Removing unreachable block (ram,0x00824cdf) */
/* WARNING: Removing unreachable block (ram,0x008249de) */
/* WARNING: Removing unreachable block (ram,0x0082497d) */
/* WARNING: Removing unreachable block (ram,0x00824c7e) */
/* WARNING: Removing unreachable block (ram,0x00824d8a) */
/* WARNING: Removing unreachable block (ram,0x00824a86) */
/* WARNING: Removing unreachable block (ram,0x00824b2a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008247d0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int local_68;
  undefined4 *local_50;
  undefined1 local_44 [8];
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34 [4];
  int *local_30;
  int *local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c040;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00825b50(*(undefined4 *)(DAT_00fc0cd8 + 4));
  *(int *)(DAT_00fc0cd8 + 4) = DAT_00fc0cd8;
  *(int *)DAT_00fc0cd8 = DAT_00fc0cd8;
  *(int *)(DAT_00fc0cd8 + 8) = DAT_00fc0cd8;
  _DAT_00fc0cdc = 0;
  local_14 = (int *)*DAT_00fc0cc8;
  local_2c = DAT_00fc0cc8;
  if (local_14 != DAT_00fc0cc8) {
    do {
      local_18 = 1;
      local_20 = local_14[6] - local_14[5] >> 3;
      if (local_20 < 2) {
        if (local_20 == 1) {
          local_18 = *(int *)(local_14[5] + 4);
        }
      }
      else {
        iVar9 = *(int *)(local_14[5] + 0xc);
        iVar8 = *(int *)(local_14[5] + 4);
        local_18 = iVar8;
        if (iVar8 < iVar9) {
          local_18 = iVar9;
          iVar9 = iVar8;
        }
        while (0 < iVar9) {
          iVar8 = local_18 % iVar9;
          local_18 = iVar9;
          iVar9 = iVar8;
        }
        if (2 < local_20) {
          piVar10 = (int *)(local_14[5] + 0x14);
          iVar9 = local_20 - 2;
          do {
            iVar8 = *piVar10;
            iVar3 = local_18;
            if (local_18 < iVar8) {
              iVar3 = iVar8;
              iVar8 = local_18;
            }
            for (; local_18 = iVar3, 0 < iVar8; iVar8 = local_18 % iVar8) {
              iVar3 = iVar8;
            }
            piVar10 = piVar10 + 2;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
      puVar7 = (undefined4 *)0x0;
      local_50 = (undefined4 *)0x0;
      local_8 = 0;
      local_1c = 0;
      if (local_20 != 0) {
        do {
          local_28 = *(int *)(local_14[5] + 4 + local_1c * 8) / local_18;
          local_24 = 0;
          if (0 < (int)local_28) {
            local_38 = 1;
            do {
              uVar6 = *(undefined4 *)(local_14[5] + local_1c * 8);
              local_3c = uVar6;
              if (&local_3c < puVar7) {
                iVar9 = (int)&local_3c >> 3;
                if (puVar7 == (undefined4 *)0x0) {
                  FUN_004e7330(1);
                  puVar7 = local_50;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  *puVar7 = *(undefined4 *)(iVar9 * 8);
                  puVar7[1] = *(undefined4 *)(iVar9 * 8 + 4);
                }
              }
              else {
                if (puVar7 == (undefined4 *)0x0) {
                  FUN_004e7330(1);
                  puVar7 = local_50;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  *puVar7 = uVar6;
                  puVar7[1] = 1;
                }
              }
              local_24 = local_24 + 1;
              puVar7 = puVar7 + 2;
              local_50 = puVar7;
            } while (local_24 < (int)local_28);
          }
          local_1c = local_1c + 1;
        } while (local_1c < local_20);
        if (puVar7 != (undefined4 *)0x0) {
          FUN_00824f10(0,puVar7,uVar5);
        }
      }
      piVar10 = local_14;
      uVar6 = FUN_00824ee0();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_00824fa0(uVar6);
      FUN_0047eb20(&DAT_00fc0cd4,local_34);
      if (local_68 != 0) {
        FUN_0089120c(local_68);
      }
      local_8 = 0xffffffff;
      if (*(char *)((int)piVar10 + 0x25) == '\0') {
        piVar2 = (int *)piVar10[2];
        if (*(char *)((int)piVar2 + 0x25) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x25);
          piVar10 = piVar2;
          piVar2 = (int *)*piVar2;
          while (local_14 = piVar10, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x25);
            piVar10 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar10[1] + 0x25);
          piVar4 = (int *)piVar10[1];
          piVar2 = piVar10;
          while ((piVar10 = piVar4, local_14 = piVar10, cVar1 == '\0' &&
                 (piVar2 == (int *)piVar10[2]))) {
            cVar1 = *(char *)(piVar10[1] + 0x25);
            piVar4 = (int *)piVar10[1];
            piVar2 = piVar10;
          }
        }
      }
    } while (piVar10 != local_2c);
  }
  FUN_00825b50(*(undefined4 *)(DAT_00fc0ce8 + 4));
  *(int *)(DAT_00fc0ce8 + 4) = DAT_00fc0ce8;
  *(int *)DAT_00fc0ce8 = DAT_00fc0ce8;
  *(int *)(DAT_00fc0ce8 + 8) = DAT_00fc0ce8;
  _DAT_00fc0cec = 0;
  local_14 = (int *)*DAT_00fc0cb8;
  local_30 = DAT_00fc0cb8;
  if (local_14 != DAT_00fc0cb8) {
    do {
      local_20 = (local_14[6] - local_14[5]) / 0xc;
      local_18 = 1;
      if (local_20 < 2) {
        if (local_20 == 1) {
          local_18 = *(int *)(local_14[5] + 8);
        }
      }
      else {
        iVar9 = *(int *)(local_14[5] + 0x14);
        iVar8 = *(int *)(local_14[5] + 8);
        local_18 = iVar8;
        if (iVar8 < iVar9) {
          local_18 = iVar9;
          iVar9 = iVar8;
        }
        while (0 < iVar9) {
          iVar8 = local_18 % iVar9;
          local_18 = iVar9;
          iVar9 = iVar8;
        }
        if (2 < local_20) {
          piVar10 = (int *)(local_14[5] + 0x20);
          iVar9 = local_20 - 2;
          do {
            iVar8 = *piVar10;
            iVar3 = local_18;
            if (local_18 < iVar8) {
              iVar3 = iVar8;
              iVar8 = local_18;
            }
            for (; local_18 = iVar3, 0 < iVar8; iVar8 = local_18 % iVar8) {
              iVar3 = iVar8;
            }
            piVar10 = piVar10 + 3;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
      puVar7 = (undefined4 *)0x0;
      local_50 = (undefined4 *)0x0;
      local_8 = 2;
      local_28 = 0;
      if (local_20 != 0) {
        local_1c = 0;
        do {
          local_2c = (int *)(*(int *)(local_14[5] + 8 + local_1c) / local_18);
          local_24 = 0;
          if (0 < (int)local_2c) {
            do {
              uVar6 = *(undefined4 *)(local_14[5] + local_1c);
              local_38 = *(undefined4 *)(local_14[5] + 4 + local_1c);
              local_3c = uVar6;
              if (&local_3c < puVar7) {
                iVar9 = (int)&local_3c >> 3;
                if (puVar7 == (undefined4 *)0x0) {
                  FUN_004e7330(1);
                  puVar7 = local_50;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  *puVar7 = *(undefined4 *)(iVar9 * 8);
                  puVar7[1] = *(undefined4 *)(iVar9 * 8 + 4);
                }
              }
              else {
                if (puVar7 == (undefined4 *)0x0) {
                  FUN_004e7330(1);
                  puVar7 = local_50;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  *puVar7 = uVar6;
                  puVar7[1] = local_38;
                }
              }
              local_24 = local_24 + 1;
              puVar7 = puVar7 + 2;
              local_50 = puVar7;
            } while (local_24 < (int)local_2c);
          }
          local_1c = local_1c + 0xc;
          local_28 = local_28 + 1;
        } while (local_28 < local_20);
        if (puVar7 != (undefined4 *)0x0) {
          FUN_00824f10(0,puVar7);
        }
      }
      piVar10 = local_14;
      uVar6 = FUN_00824ee0();
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00824fa0(uVar6);
      FUN_0047eb20(&DAT_00fc0ce4,local_44);
      if (local_68 != 0) {
        FUN_0089120c(local_68);
      }
      if (*(char *)((int)piVar10 + 0x25) == '\0') {
        piVar2 = (int *)piVar10[2];
        if (*(char *)((int)piVar2 + 0x25) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x25);
          piVar10 = piVar2;
          piVar2 = (int *)*piVar2;
          while (local_14 = piVar10, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x25);
            piVar10 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar10[1] + 0x25);
          piVar4 = (int *)piVar10[1];
          piVar2 = piVar10;
          while ((piVar10 = piVar4, local_14 = piVar10, cVar1 == '\0' &&
                 (piVar2 == (int *)piVar10[2]))) {
            cVar1 = *(char *)(piVar10[1] + 0x25);
            piVar4 = (int *)piVar10[1];
            piVar2 = piVar10;
          }
        }
      }
    } while (piVar10 != local_30);
  }
  DAT_00fc0cf4 = 1;
  ExceptionList = local_10;
  return;
}


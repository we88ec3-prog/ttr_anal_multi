
void FUN_00416580(int param_1)

{
  undefined4 **ppuVar1;
  undefined4 **ppuVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  int local_28;
  uint local_24;
  undefined4 *local_20;
  char *local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917d13;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar7 = 0;
  local_14 = 0;
  iVar8 = param_1 + 0xe0;
  do {
    FUN_00418440(iVar8,uVar3);
    *(undefined1 *)(param_1 + 0x498 + iVar7) = 0;
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 0x10;
  } while (iVar7 < 6);
  local_1c = (char *)(param_1 + 0x498);
  local_28 = 0;
  puVar9 = (uint *)(param_1 + 0xe4);
  do {
    local_24 = 0;
    if ((int)(puVar9[0x18] - puVar9[0x17]) >> 2 != 0) {
      do {
        iVar7 = local_24 * 4;
        iVar8 = **(int **)(iVar7 + puVar9[0x17]) + 0x3a;
        iVar4 = **(int **)(iVar7 + puVar9[0x17]) + 0x1c;
        iVar8 = (*(int *)(param_1 + 4 + iVar8 * 0x10) - *(int *)(param_1 + iVar8 * 0x10) >> 2) +
                (*(int *)(param_1 + 4 + iVar4 * 0x10) - *(int *)(param_1 + iVar4 * 0x10) >> 2);
        local_14 = local_14 + iVar8;
        if (iVar8 != 0) {
          puVar5 = (undefined4 *)FUN_00891268(0x20);
          local_8 = 0;
          if (puVar5 == (undefined4 *)0x0) {
            puVar5 = (undefined4 *)0x0;
          }
          else {
            local_3c = 0;
            local_38 = 7;
            local_4c[0] = local_4c[0] & 0xffff0000;
            local_20 = puVar5;
            FUN_004026e0(*(int *)(puVar9[0x17] + iVar7) + 4,0,0xffffffff);
            local_8 = CONCAT31(local_8._1_3_,1);
            *puVar5 = **(undefined4 **)(puVar9[0x17] + iVar7);
            puVar5[6] = 7;
            puVar5[5] = 0;
            *(undefined2 *)(puVar5 + 1) = 0;
            FUN_004026e0(local_4c,0,0xffffffff);
            if (7 < local_38) {
              FUN_0089120c(local_4c[0]);
            }
            local_38 = 7;
            local_3c = 0;
            local_4c[0] = local_4c[0] & 0xffff0000;
          }
          local_8 = 0xffffffff;
          ppuVar1 = (undefined4 **)*puVar9;
          local_20 = puVar5;
          local_18 = puVar5;
          if ((&local_18 < ppuVar1) && (ppuVar2 = (undefined4 **)puVar9[-1], ppuVar2 <= &local_18))
          {
            if (ppuVar1 == (undefined4 **)puVar9[1]) {
              uVar3 = (int)ppuVar1 - (int)ppuVar2 >> 2;
              if (0x3ffffffe < uVar3) {
LAB_00416801:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar3 = uVar3 + 1;
              uVar6 = (int)puVar9[1] - (int)ppuVar2 >> 2;
              if (uVar6 < uVar3) {
                if (0x3fffffff - (uVar6 >> 1) < uVar6) {
                  uVar6 = 0;
                }
                else {
                  uVar6 = uVar6 + (uVar6 >> 1);
                }
                if (uVar6 < uVar3) {
                  uVar6 = uVar3;
                }
                FUN_00797980(uVar6);
              }
            }
            if ((undefined4 *)*puVar9 != (undefined4 *)0x0) {
              *(undefined4 *)*puVar9 =
                   *(undefined4 *)(puVar9[-1] + ((int)&local_18 - (int)ppuVar2 >> 2) * 4);
            }
          }
          else {
            if (ppuVar1 == (undefined4 **)puVar9[1]) {
              uVar3 = (int)((int)ppuVar1 - puVar9[-1]) >> 2;
              if (0x3ffffffe < uVar3) goto LAB_00416801;
              uVar3 = uVar3 + 1;
              uVar6 = (int)((int)puVar9[1] - puVar9[-1]) >> 2;
              if (uVar6 < uVar3) {
                if (0x3fffffff - (uVar6 >> 1) < uVar6) {
                  uVar6 = 0;
                }
                else {
                  uVar6 = uVar6 + (uVar6 >> 1);
                }
                if (uVar6 < uVar3) {
                  uVar6 = uVar3;
                }
                FUN_00797980(uVar6);
              }
            }
            if ((undefined4 *)*puVar9 != (undefined4 *)0x0) {
              *(undefined4 *)*puVar9 = local_20;
            }
          }
          *puVar9 = *puVar9 + 4;
        }
        if ((local_14 != 0) && (*local_1c == '\0')) {
          *local_1c = '\x01';
        }
        local_24 = local_24 + 1;
      } while (local_24 < (uint)((int)(puVar9[0x18] - puVar9[0x17]) >> 2));
    }
    local_1c = local_1c + 1;
    local_28 = local_28 + 1;
    puVar9 = puVar9 + 4;
    local_14 = 0;
    if (5 < local_28) {
      FUN_00414e40();
      ExceptionList = local_10;
      return;
    }
  } while( true );
}


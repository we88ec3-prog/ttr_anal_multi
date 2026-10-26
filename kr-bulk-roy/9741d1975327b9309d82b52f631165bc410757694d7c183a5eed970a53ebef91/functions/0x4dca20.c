
undefined4 FUN_004dca20(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  undefined4 **ppuVar8;
  uint uVar9;
  DWORD DVar10;
  int iVar11;
  undefined2 *puVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  int local_5c;
  undefined4 *local_58;
  undefined4 *local_50;
  int local_4c;
  int local_48;
  byte *local_44;
  uint local_40 [2];
  uint local_38 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00924afc;
  local_14 = ExceptionList;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  local_5c = 8;
  local_48 = 0;
  if (*(short *)(param_2 + 2) != 0) {
    do {
      puVar1 = (undefined4 *)(local_5c + param_2);
      local_5c = local_5c + 0x1b;
      local_58 = (undefined4 *)FUN_00891268(0x58,uVar9);
      if (local_58 == (undefined4 *)0x0) {
        local_58 = (undefined4 *)0x0;
      }
      else {
        local_58[10] = 0;
        local_58[0xb] = 0;
        local_58[0xc] = 0;
        local_58[0xd] = 0;
        local_58[0xe] = 0;
        local_58[0xf] = 0;
        local_58[0x11] = 0;
        local_58[0x12] = 0;
        local_58[0x13] = 0;
        local_58[0x15] = 0;
      }
      *local_58 = *puVar1;
      local_58[1] = puVar1[1];
      local_58[2] = (uint)*(byte *)((int)puVar1 + 10);
      local_58[3] = (uint)*(ushort *)(puVar1 + 2);
      local_58[4] = (uint)*(byte *)(puVar1 + 3);
      *(undefined1 *)(local_58 + 5) = *(undefined1 *)((int)puVar1 + 0xe);
      *(undefined1 *)((int)local_58 + 0x15) = *(undefined1 *)((int)puVar1 + 0xd);
      local_58[6] = *(undefined4 *)((int)puVar1 + 0xf);
      local_58[7] = *(undefined4 *)((int)puVar1 + 0x13);
      local_50 = local_58;
      DVar10 = timeGetTime();
      local_58[8] = DVar10;
      if (*(char *)((int)local_58 + 0x15) == '\0') {
        uVar17 = 0;
      }
      else {
        iVar11 = FUN_00404ba0();
        uVar17 = (uint)((int)local_58[7] < *(int *)(iVar11 + 0x5f70));
      }
      local_58[9] = uVar17;
      local_4c = 0;
      if (*(char *)((int)puVar1 + 0xb) != '\0') {
        puVar16 = local_58 + 0xd;
        do {
          uVar17 = (uint)*(byte *)(local_5c + param_2);
          local_40[1] = (uint)*(short *)(local_5c + param_2 + 1);
          puVar4 = (uint *)local_58[0xe];
          local_5c = local_5c + 3;
          local_40[0] = uVar17;
          if ((local_40 < puVar4) && (puVar5 = (uint *)*puVar16, puVar5 <= local_40)) {
            if (puVar4 == (uint *)local_58[0xf]) {
              uVar17 = (int)puVar4 - (int)puVar5 >> 3;
              if (0x1ffffffe < uVar17) goto LAB_004dcf71;
              uVar17 = uVar17 + 1;
              uVar14 = (int)local_58[0xf] - (int)puVar5 >> 3;
              if (uVar14 < uVar17) {
                if (0x1fffffff - (uVar14 >> 1) < uVar14) {
                  uVar14 = 0;
                }
                else {
                  uVar14 = uVar14 + (uVar14 >> 1);
                }
                if (uVar14 < uVar17) {
                  uVar14 = uVar17;
                }
                FUN_004e7330(uVar14);
              }
            }
            puVar6 = (undefined4 *)local_58[0xe];
            puVar2 = (undefined4 *)(*puVar16 + ((int)local_40 - (int)puVar5 >> 3) * 8);
            if (puVar6 != (undefined4 *)0x0) {
              *puVar6 = *puVar2;
              puVar6[1] = puVar2[1];
            }
          }
          else {
            if (puVar4 == (uint *)local_58[0xf]) {
              uVar14 = (int)((int)puVar4 - *puVar16) >> 3;
              if (0x1ffffffe < uVar14) goto LAB_004dcf71;
              uVar14 = uVar14 + 1;
              uVar15 = (int)((int)local_58[0xf] - *puVar16) >> 3;
              if (uVar15 < uVar14) {
                if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                  uVar15 = 0;
                }
                else {
                  uVar15 = uVar15 + (uVar15 >> 1);
                }
                if (uVar15 < uVar14) {
                  uVar15 = uVar14;
                }
                FUN_004e7330(uVar15);
              }
            }
            puVar4 = (uint *)local_58[0xe];
            if (puVar4 != (uint *)0x0) {
              *puVar4 = uVar17;
              puVar4[1] = local_40[1];
            }
          }
          local_58[0xe] = local_58[0xe] + 8;
          local_4c = local_4c + 1;
        } while (local_4c < (int)(uint)*(byte *)((int)puVar1 + 0xb));
      }
      local_58[10] = (uint)*(byte *)((int)puVar1 + 10);
      if ((*(byte *)((int)puVar1 + 0x17) & 1) != 0) {
        local_58[0xc] = (uint)*(byte *)(local_5c + param_2);
        local_5c = local_5c + 1;
      }
      local_44 = (byte *)(local_5c + param_2);
      local_5c = local_5c + 1;
      local_4c = 0;
      if (*local_44 != 0) {
        puVar16 = local_58 + 0x11;
        do {
          uVar17 = (uint)*(byte *)(param_2 + local_5c);
          local_38[1] = (uint)*(ushort *)(param_2 + 1 + local_5c);
          puVar4 = (uint *)local_58[0x12];
          local_5c = local_5c + 3;
          local_38[0] = uVar17;
          if (local_38 < puVar4) {
            puVar5 = (uint *)*puVar16;
            if (local_38 < puVar5) goto LAB_004dcd09;
            if (puVar4 == (uint *)local_58[0x13]) {
              uVar17 = (int)puVar4 - (int)puVar5 >> 3;
              if (0x1ffffffe < uVar17) goto LAB_004dcf71;
              uVar17 = uVar17 + 1;
              uVar14 = (int)local_58[0x13] - (int)puVar5 >> 3;
              if (uVar14 < uVar17) {
                if (0x1fffffff - (uVar14 >> 1) < uVar14) {
                  uVar14 = 0;
                }
                else {
                  uVar14 = uVar14 + (uVar14 >> 1);
                }
                if (uVar14 < uVar17) {
                  uVar14 = uVar17;
                }
                FUN_004e7330(uVar14);
              }
            }
            puVar6 = (undefined4 *)local_58[0x12];
            puVar2 = (undefined4 *)(*puVar16 + ((int)local_38 - (int)puVar5 >> 3) * 8);
            if (puVar6 != (undefined4 *)0x0) {
              *puVar6 = *puVar2;
              puVar6[1] = puVar2[1];
            }
          }
          else {
LAB_004dcd09:
            if (puVar4 == (uint *)local_58[0x13]) {
              uVar14 = (int)((int)puVar4 - *puVar16) >> 3;
              if (0x1ffffffe < uVar14) goto LAB_004dcf71;
              uVar14 = uVar14 + 1;
              uVar15 = (int)((int)local_58[0x13] - *puVar16) >> 3;
              if (uVar15 < uVar14) {
                if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                  uVar15 = 0;
                }
                else {
                  uVar15 = uVar15 + (uVar15 >> 1);
                }
                if (uVar15 < uVar14) {
                  uVar15 = uVar14;
                }
                FUN_004e7330(uVar15);
              }
            }
            puVar4 = (uint *)local_58[0x12];
            if (puVar4 != (uint *)0x0) {
              *puVar4 = uVar17;
              puVar4[1] = local_38[1];
            }
          }
          local_58[0x12] = local_58[0x12] + 8;
          local_4c = local_4c + 1;
        } while (local_4c < (int)(uint)*local_44);
      }
      if ((*(byte *)((int)puVar1 + 0x17) & 4) != 0) {
        puVar3 = (undefined2 *)(local_5c + param_2);
        local_5c = local_5c + 5;
        puVar12 = (undefined2 *)FUN_00891268(4);
        *puVar12 = *puVar3;
        *(undefined1 *)(puVar12 + 1) = *(undefined1 *)(puVar3 + 2);
        local_58[0x15] = puVar12;
      }
      FUN_004dc730(*local_58,local_58[1]);
      if ((*(char *)((int)local_58 + 0x15) != '\0') && (local_58[9] == 0)) {
        ppuVar7 = *(undefined4 ***)(param_1 + 0x14);
        puVar16 = (uint *)(param_1 + 0x10);
        if ((&local_50 < ppuVar7) && (ppuVar8 = (undefined4 **)*puVar16, ppuVar8 <= &local_50)) {
          if (ppuVar7 == *(undefined4 ***)(param_1 + 0x18)) {
            uVar17 = (int)ppuVar7 - (int)ppuVar8 >> 2;
            if (0x3ffffffe < uVar17) {
LAB_004dcf71:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar17 = uVar17 + 1;
            uVar14 = (int)*(undefined4 ***)(param_1 + 0x18) - (int)ppuVar8 >> 2;
            if (uVar14 < uVar17) {
              if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                uVar14 = 0;
              }
              else {
                uVar14 = uVar14 + (uVar14 >> 1);
              }
              if (uVar14 < uVar17) {
                uVar14 = uVar17;
              }
              FUN_00797980(uVar14);
            }
          }
          if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x14) =
                 *(undefined4 *)(*puVar16 + ((int)&local_50 - (int)ppuVar8 >> 2) * 4);
          }
        }
        else {
          if (ppuVar7 == *(undefined4 ***)(param_1 + 0x18)) {
            uVar17 = (int)((int)ppuVar7 - *puVar16) >> 2;
            if (0x3ffffffe < uVar17) goto LAB_004dcf71;
            uVar17 = uVar17 + 1;
            uVar14 = (int)((int)*(undefined4 ***)(param_1 + 0x18) - *puVar16) >> 2;
            if (uVar14 < uVar17) {
              if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                uVar14 = 0;
              }
              else {
                uVar14 = uVar14 + (uVar14 >> 1);
              }
              if (uVar14 < uVar17) {
                uVar14 = uVar17;
              }
              FUN_00797980(uVar14);
            }
          }
          if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x14) = local_58;
          }
        }
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 4;
      }
      local_28 = *local_58;
      local_24 = local_58[1];
      local_20 = local_58;
      uVar13 = FUN_006d74f0();
      FUN_007c0b70(param_1,uVar13);
      local_48 = local_48 + 1;
    } while (local_48 < (int)(uint)*(ushort *)(param_2 + 2));
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf4365);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(&DAT_000f4284);
  ExceptionList = local_14;
  return 0;
}


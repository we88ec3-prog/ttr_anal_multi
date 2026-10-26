
void FUN_00441060(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  ushort uVar3;
  ushort *puVar4;
  int *piVar5;
  uint *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 **ppuVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint *puVar16;
  int *piVar17;
  uint local_48;
  uint local_44;
  uint *local_40;
  int local_3c;
  int local_38;
  uint local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  uint local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009419d6;
  local_14 = ExceptionList;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  iVar9 = *(int *)(*(int *)(param_1 + 0xf8) + 0x24c);
  if (iVar9 != 0) {
    iVar9 = *(int *)(iVar9 + 0xcc);
    if (iVar9 == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(iVar9 + 0xdc);
    }
    if (iVar9 != 0) {
      local_3c = *(int *)(iVar9 + 0x20);
      goto LAB_004410cc;
    }
  }
  local_3c = -1;
LAB_004410cc:
  uVar10 = *(undefined4 *)(DAT_00fb1318 + 0xbfe8);
  FUN_006dbd10(uVar10);
  FUN_006dbf20(uVar10,local_3c);
  if ((DAT_00fb7bcc & 1) == 0) {
    DAT_00fb7bcc = DAT_00fb7bcc | 1;
    local_c = 0;
    FUN_00820290(uVar8);
    _atexit((_func_4879 *)&LAB_00bcd520);
    local_c = 0xffffffff;
  }
  iVar9 = FUN_008204e0();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if ((local_3c < 1) || (0xf < local_3c)) {
    local_40 = (uint *)0x0;
  }
  else {
    local_40 = (uint *)(local_3c * 0x108 + DAT_00f94300);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if ((local_3c < 0) || (9 < local_3c)) {
    local_44 = 0;
  }
  else {
    local_44 = -(uint)(*(int *)(local_3c * 0x210 + 0x5c + DAT_00f94304) != 0) &
               local_3c * 0x210 + DAT_00f94304;
  }
  local_38 = 1;
  local_48 = 2;
  puVar6 = local_40;
  do {
    puVar16 = puVar6 + 4;
    if ((local_38 < 3) || (5 < local_38)) {
      if (local_38 - 1U < 0xf) {
        if ((puVar16 != (uint *)0x0) && (puVar6[6] != 0)) {
          if ((DAT_00f8d9a4 & 1) == 0) {
            DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
            local_c = 3;
            FUN_0051c120();
            _atexit((_func_4879 *)&LAB_00bccc90);
            local_c = 0xffffffff;
          }
          local_30 = puVar6[5];
          FUN_008438c0(&local_30);
          if (((local_2c != DAT_00f8d91c) && (local_2c[4] != 0)) &&
             (iVar13 = *(int *)(local_2c[4] + 0x68), iVar13 != 0)) {
            uVar3 = *(ushort *)(iVar13 + 8);
            iVar13 = FUN_00404ba0();
            iVar13 = *(int *)(iVar13 + 0x6928);
            local_30 = (uint)uVar3;
            FUN_004a4cc0(&local_30);
            if (((local_28 == *(undefined4 **)(iVar13 + 0x14)) || (local_28[4] == 0)) ||
               (*(int *)(local_28[4] + 0xc) == 0)) goto LAB_00441377;
          }
          local_20 = puVar6[6];
          local_1c = puVar6[7];
          iVar13 = FUN_00409560();
          FUN_004dd400(iVar13,&local_24,&local_20);
          if ((local_24 == *(undefined4 **)(iVar13 + 4)) || (iVar13 = local_24[6], iVar13 == 0)) {
            if ((*(uint *)(local_44 + 0xf8) & local_48) == 0) {
              uVar10 = 0;
              uVar8 = 0;
LAB_0044136b:
              uVar15 = *puVar16;
              goto LAB_0044136e;
            }
          }
          else {
            puVar4 = *(ushort **)(iVar13 + 0x54);
            if (((*(uint *)(local_44 + 0xf8) & local_48) == 0) && (*(int *)(iVar13 + 0x24) == 0)) {
              if ((puVar4 == (ushort *)0x0) || (*puVar4 == 0)) {
                uVar10 = FUN_004dc850();
                uVar8 = *(uint *)(iVar13 + 0x30);
                goto LAB_0044136b;
              }
              uVar10 = FUN_004dc850();
              uVar8 = (uint)(byte)puVar4[1];
              uVar15 = (uint)*puVar4;
LAB_0044136e:
              FUN_006dc180(uVar15,uVar8,uVar10);
            }
          }
        }
      }
      else {
        FUN_006edb60(&DAT_00c0dddc,local_38);
      }
    }
LAB_00441377:
    local_38 = local_38 + 1;
    local_48 = local_48 << 1 | (uint)((int)local_48 < 0);
    puVar6 = puVar16;
    if (0xf < local_38) {
      piVar17 = (int *)**(int **)(iVar9 + 8);
      if (piVar17 != *(int **)(iVar9 + 8)) {
        do {
          iVar13 = piVar17[4];
          if (iVar13 != 0) {
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c = 4;
              FUN_0051c120();
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = 0xffffffff;
            }
            cVar1 = *(char *)((int)DAT_00f8d91c[1] + 0x15);
            puVar11 = (undefined4 *)DAT_00f8d91c[1];
            local_24 = DAT_00f8d91c;
            while (puVar14 = puVar11, cVar1 == '\0') {
              if ((int)puVar14[3] < iVar13) {
                puVar11 = (undefined4 *)puVar14[2];
                puVar14 = local_24;
              }
              else {
                puVar11 = (undefined4 *)*puVar14;
              }
              cVar1 = *(char *)((int)puVar11 + 0x15);
              local_24 = puVar14;
            }
            if ((local_24 == DAT_00f8d91c) || (iVar13 < (int)local_24[3])) {
              local_28 = DAT_00f8d91c;
              ppuVar12 = &local_28;
            }
            else {
              ppuVar12 = &local_24;
            }
            if (*ppuVar12 == DAT_00f8d91c) {
              iVar13 = 0;
            }
            else {
              iVar13 = (*ppuVar12)[4];
            }
            FUN_006dc180(*(undefined4 *)(iVar13 + 0x20),0,0);
          }
          if (*(char *)((int)piVar17 + 0x15) == '\0') {
            piVar5 = (int *)piVar17[2];
            if (*(char *)((int)piVar5 + 0x15) == '\0') {
              cVar1 = *(char *)(*piVar5 + 0x15);
              piVar17 = piVar5;
              piVar5 = (int *)*piVar5;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar5 + 0x15);
                piVar17 = piVar5;
                piVar5 = (int *)*piVar5;
              }
            }
            else {
              cVar1 = *(char *)(piVar17[1] + 0x15);
              piVar7 = (int *)piVar17[1];
              piVar5 = piVar17;
              while ((piVar17 = piVar7, cVar1 == '\0' && (piVar5 == (int *)piVar17[2]))) {
                cVar1 = *(char *)(piVar17[1] + 0x15);
                piVar7 = (int *)piVar17[1];
                piVar5 = piVar17;
              }
            }
          }
        } while (piVar17 != *(int **)(iVar9 + 8));
      }
      uVar8 = (uint)(ushort)local_40[0x40];
      if ((ushort)local_40[0x40] == 0) {
        uVar2 = *(undefined1 *)((int)local_40 + 0x102);
        uVar8 = local_3c + 31000;
      }
      else {
        uVar2 = *(undefined1 *)((int)local_40 + 0x102);
      }
      FUN_006dc180(uVar8,uVar2,0);
      (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
      ExceptionList = local_14;
      return;
    }
  } while( true );
}


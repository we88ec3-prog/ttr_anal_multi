
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00500240(int param_1,int param_2)

{
  char cVar1;
  void *_Dst;
  uint **ppuVar2;
  uint **ppuVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  ushort *puVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  uint *local_5c;
  uint *local_54;
  uint local_50;
  ushort *local_4c;
  char *local_48;
  uint local_44;
  undefined **local_40 [3];
  undefined **local_34 [3];
  uint *local_28;
  uint *local_24;
  uint *local_20;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00940219;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  _Dst = *(void **)(param_1 + 0x5ec0);
  if (_Dst != *(void **)(param_1 + 0x5ec4)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x5ec4),0);
    *(void **)(param_1 + 0x5ec4) = _Dst;
  }
  puVar13 = (uint *)0x0;
  local_28 = (uint *)0x0;
  local_24 = (uint *)0x0;
  local_20 = (uint *)0x0;
  local_c = 0;
  uVar15 = 1;
  iVar16 = 0x210;
  puVar14 = (uint *)0x0;
  do {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 1;
      FUN_004e1590(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = (uint)local_c._1_3_ << 8;
      puVar13 = local_24;
    }
    local_54 = puVar14;
    if ((((uVar15 < 10) && (iVar5 = DAT_00f94304 + iVar16, *(int *)(iVar5 + 0x5c) != 0)) &&
        (iVar5 != 0)) &&
       (local_54 = *(uint **)(iVar5 + 8), (int)*(uint **)(iVar5 + 8) <= (int)puVar14)) {
      local_54 = puVar14;
    }
    iVar16 = iVar16 + 0x210;
    uVar15 = uVar15 + 1;
    puVar14 = local_54;
  } while (iVar16 < 0x14a0);
  iVar16 = *(int *)(param_1 + 0x5eac);
  local_5c = (uint *)**(int **)(iVar16 + 4);
  puVar14 = local_24;
  if (local_5c != (uint *)*(int **)(iVar16 + 4)) {
    do {
      puVar13 = local_5c + 4;
      if ((DAT_00fb9390 & 1) == 0) {
        DAT_00fb9390 = DAT_00fb9390 | 1;
        local_c._0_1_ = 2;
        DAT_00fb939c = 0;
        puVar6 = (undefined4 *)FUN_00891268(0x18);
        if (puVar6 == (undefined4 *)0x0) {
          local_48 = (char *)0x0;
          std::exception::exception((exception *)local_34,&local_48);
          local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_34,&DAT_00c857a8);
        }
        DAT_00fb9398 = puVar6;
        *puVar6 = puVar6;
        DAT_00fb9398[1] = DAT_00fb9398;
        DAT_00fb9398[2] = DAT_00fb9398;
        *(undefined1 *)(DAT_00fb9398 + 5) = 1;
        *(undefined1 *)((int)DAT_00fb9398 + 0x15) = 1;
        local_c._0_1_ = 3;
        _DAT_00fb93ac = 0;
        iVar5 = FUN_00891268(0x18);
        if (iVar5 == 0) {
          local_4c = (ushort *)0x0;
          std::exception::exception((exception *)local_40,(char **)&local_4c);
          local_40[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_40,&DAT_00c857a8);
        }
        DAT_00fb93a8 = iVar5;
        *(int *)iVar5 = iVar5;
        *(int *)(DAT_00fb93a8 + 4) = DAT_00fb93a8;
        *(int *)(DAT_00fb93a8 + 8) = DAT_00fb93a8;
        *(undefined1 *)(DAT_00fb93a8 + 0x14) = 1;
        *(undefined1 *)(DAT_00fb93a8 + 0x15) = 1;
        _DAT_00fb93b4 = 1;
        _atexit((_func_4879 *)&LAB_00bcd610);
        local_c = (uint)local_c._1_3_ << 8;
      }
      puVar6 = (undefined4 *)DAT_00fb9398[1];
      uVar4 = *puVar13;
      cVar1 = *(char *)((int)puVar6 + 0x15);
      puVar10 = puVar6;
      while (cVar1 == '\0') {
        if ((int)puVar10[3] < 10) {
          puVar10 = (undefined4 *)puVar10[2];
        }
        else {
          puVar10 = (undefined4 *)*puVar10;
        }
        cVar1 = *(char *)((int)puVar10 + 0x15);
      }
      puVar10 = DAT_00fb9398;
      if (*(char *)((int)puVar6 + 0x15) == '\0') {
        do {
          if ((int)puVar6[3] < 9) {
            puVar7 = (undefined4 *)puVar6[2];
          }
          else {
            puVar7 = (undefined4 *)*puVar6;
            puVar10 = puVar6;
          }
          puVar6 = puVar7;
        } while (*(char *)((int)puVar7 + 0x15) == '\0');
        if ((puVar10 == DAT_00fb9398) ||
           (iVar5 = *(int *)(puVar10[4] + 8), local_50 = uVar4,
           piVar8 = (int *)FUN_0044b540(&local_50), puVar14 = local_24, *piVar8 == iVar5))
        goto LAB_00500485;
      }
      else {
LAB_00500485:
        if ((local_5c[0xc] == param_2) && ((int)local_5c[7] <= (int)local_54)) {
          iVar5 = 0;
          puVar11 = (ushort *)(param_1 + 0x5ed0);
          do {
            if (*puVar11 == uVar4) goto LAB_0050054a;
            iVar5 = iVar5 + 1;
            puVar11 = puVar11 + 1;
          } while (iVar5 < 0x14);
          puVar11 = *(ushort **)(param_1 + 0x5eb4);
          puVar9 = *(ushort **)(param_1 + 0x5eb0);
          if (puVar9 != puVar11) {
            do {
              if (*puVar9 == uVar4) break;
              puVar9 = puVar9 + 1;
            } while (puVar9 != puVar11);
            if (puVar9 != puVar11) goto LAB_0050054a;
          }
          if ((puVar13 < puVar14) && (local_28 <= puVar13)) {
            iVar5 = (int)puVar13 - (int)local_28;
            if (puVar14 == local_20) {
              FUN_006d6240();
              puVar14 = local_24;
            }
            if (puVar14 != (uint *)0x0) {
              *puVar14 = local_28[iVar5 >> 2];
            }
          }
          else {
            if (puVar14 == local_20) {
              FUN_006d6240();
              puVar14 = local_24;
            }
            if (puVar14 != (uint *)0x0) {
              *puVar14 = *puVar13;
            }
          }
          puVar14 = puVar14 + 1;
          local_24 = puVar14;
        }
      }
LAB_0050054a:
      if (*(char *)((int)local_5c + 0xb5) == '\0') {
        piVar8 = (int *)local_5c[2];
        if (*(char *)((int)piVar8 + 0xb5) == '\0') {
          cVar1 = *(char *)(*piVar8 + 0xb5);
          local_5c = (uint *)piVar8;
          piVar8 = (int *)*piVar8;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar8 + 0xb5);
            local_5c = (uint *)piVar8;
            piVar8 = (int *)*piVar8;
          }
        }
        else {
          cVar1 = *(char *)((int)local_5c[1] + 0xb5);
          piVar8 = (int *)local_5c[1];
          puVar13 = local_5c;
          while ((local_5c = (uint *)piVar8, cVar1 == '\0' && (puVar13 == (uint *)local_5c[2]))) {
            cVar1 = *(char *)((int)local_5c[1] + 0xb5);
            piVar8 = (int *)local_5c[1];
            puVar13 = local_5c;
          }
        }
      }
      puVar13 = local_24;
    } while (local_5c != (uint *)*(int **)(iVar16 + 4));
  }
  local_44 = (int)puVar13 - (int)local_28 >> 2;
  local_50 = 0;
  if (local_44 != 0) {
    local_5c = local_28;
    do {
      FUN_00503d20(local_5c);
      if (local_48 != *(char **)(iVar16 + 4)) {
        uVar15 = 0;
        uVar4 = *(int *)(local_48 + 0x24) - *(int *)(local_48 + 0x20) >> 2;
        if (uVar4 != 0) {
          puVar11 = *(ushort **)(param_1 + 0x5eb4);
          local_4c = *(ushort **)(param_1 + 0x5eb0);
          local_54 = *(uint **)(local_48 + 0x20);
          do {
            if (local_4c == puVar11) goto LAB_0050077e;
            puVar9 = local_4c;
            do {
              if ((uint)*puVar9 == *local_54) break;
              puVar9 = puVar9 + 1;
            } while (puVar9 != puVar11);
            if (puVar9 == puVar11) goto LAB_0050077e;
            local_54 = local_54 + 1;
            uVar15 = uVar15 + 1;
          } while (uVar15 < uVar4);
        }
        uVar4 = *local_5c;
        local_54 = (uint *)(uint)(ushort)uVar4;
        ppuVar2 = *(uint ***)(param_1 + 0x5ec4);
        puVar13 = (uint *)(param_1 + 0x5ec0);
        if (&local_54 < ppuVar2) {
          ppuVar3 = (uint **)*puVar13;
          if (&local_54 < ppuVar3) goto LAB_00500733;
          if (ppuVar2 == *(uint ***)(param_1 + 0x5ec8)) {
            uVar4 = (int)ppuVar2 - (int)ppuVar3 >> 1;
            if (0x7ffffffe < uVar4) goto LAB_005007c0;
            uVar4 = uVar4 + 1;
            uVar15 = (int)*(uint ***)(param_1 + 0x5ec8) - (int)ppuVar3 >> 1;
            if (uVar15 < uVar4) {
              if (0x7fffffff - (uVar15 >> 1) < uVar15) {
                uVar15 = 0;
              }
              else {
                uVar15 = uVar15 + (uVar15 >> 1);
              }
              if (uVar15 < uVar4) {
                uVar15 = uVar4;
              }
              FUN_0044b6a0(uVar15);
            }
          }
          if (*(undefined2 **)(param_1 + 0x5ec4) != (undefined2 *)0x0) {
            **(undefined2 **)(param_1 + 0x5ec4) =
                 *(undefined2 *)(*puVar13 + ((int)&local_54 - (int)ppuVar3 >> 1) * 2);
          }
        }
        else {
LAB_00500733:
          if (ppuVar2 == *(uint ***)(param_1 + 0x5ec8)) {
            uVar15 = (int)((int)ppuVar2 - *puVar13) >> 1;
            if (0x7ffffffe < uVar15) {
LAB_005007c0:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar15 = uVar15 + 1;
            uVar12 = (int)((int)*(uint ***)(param_1 + 0x5ec8) - *puVar13) >> 1;
            if (uVar12 < uVar15) {
              if (0x7fffffff - (uVar12 >> 1) < uVar12) {
                uVar12 = 0;
              }
              else {
                uVar12 = uVar12 + (uVar12 >> 1);
              }
              if (uVar12 < uVar15) {
                uVar12 = uVar15;
              }
              FUN_0044b6a0(uVar12);
            }
          }
          if (*(ushort **)(param_1 + 0x5ec4) != (ushort *)0x0) {
            **(ushort **)(param_1 + 0x5ec4) = (ushort)uVar4;
          }
        }
        *(int *)(param_1 + 0x5ec4) = *(int *)(param_1 + 0x5ec4) + 2;
      }
LAB_0050077e:
      local_5c = local_5c + 1;
      local_50 = local_50 + 1;
    } while (local_50 < local_44);
  }
  if (local_28 != (uint *)0x0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}


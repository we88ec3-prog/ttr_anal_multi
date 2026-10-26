
void FUN_004704c0(int param_1)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  byte bVar6;
  undefined1 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 **ppuVar11;
  uint uVar12;
  undefined4 uVar13;
  uint uVar14;
  int *piVar15;
  undefined1 auStack_8c [4];
  int local_88;
  int local_84;
  int iStack_80;
  ushort *puStack_7c;
  ushort *puStack_78;
  int iStack_74;
  undefined4 *puStack_70;
  undefined4 uStack_6c;
  int local_68;
  undefined4 uStack_64;
  undefined4 *puStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  short sStack_40;
  undefined4 uStack_3e;
  undefined4 uStack_3a;
  undefined4 uStack_36;
  undefined4 uStack_32;
  undefined4 uStack_2e;
  undefined4 uStack_2a;
  undefined4 uStack_26;
  undefined4 uStack_22;
  undefined2 uStack_1e;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094144e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_8c;
  ExceptionList = &local_14;
  local_68 = param_1;
  if ((DAT_00fc0dc4 & 1) == 0) {
    DAT_00fc0dc4 = DAT_00fc0dc4 | 1;
    local_c = 0;
    FUN_0052a3b0(DAT_00d61f20 ^ (uint)&stack0xffffff68);
    _atexit(FUN_00bcd980);
  }
  local_c = 0xffffffff;
  local_88 = **(int **)(param_1 + 0x108);
  FUN_0052a340(&local_88);
  iVar8 = local_84;
  if ((local_84 != DAT_00fc0dcc) && (piVar15 = (int *)(local_84 + 0x10), piVar15 != (int *)0x0)) {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 1;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    iVar5 = DAT_00f943ec;
    if ((((DAT_00f943ec == 0) ||
         (local_88 = *piVar15, FUN_0082ef00(&local_88), local_84 == *(int *)(iVar5 + 0xc))) ||
        (*(int *)(local_84 + 0x10) == 0)) && ((DAT_00f94394 & 1) == 0)) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 2;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    FUN_00745060();
    FUN_00757800(iVar8 + 0x14);
    (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
    uStack_48 = 7;
    local_c = 3;
    uStack_5c = (uint)uStack_5c._2_2_ << 0x10;
    uStack_4c = 0;
    FUN_004041f0(iVar8 + 0x30,0,0xffffffff);
    iVar8 = FUN_00529cf0();
    if (iVar8 != 0) {
      FUN_004041f0(iVar8 + 4,0,0xffffffff);
    }
    FUN_00757800(&uStack_5c);
    (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
    if ((DAT_00fab278 & 1) == 0) {
      DAT_00fab278 = DAT_00fab278 | 1;
      local_c._0_1_ = 4;
      FUN_00817da0();
      _atexit((_func_4879 *)&LAB_00bcced0);
      local_c = CONCAT31(local_c._1_3_,3);
    }
    local_88 = FUN_00819220(*(undefined1 *)(param_1 + 0x105),*(undefined1 *)(param_1 + 0x104));
    sStack_40 = 0;
    uStack_3e = 0;
    uStack_3a = 0;
    uStack_36 = 0;
    uStack_32 = 0;
    uStack_2e = 0;
    uStack_2a = 0;
    uStack_26 = 0;
    uStack_22 = 0;
    uStack_1e = 0;
    if (local_88 != 0) {
      bVar6 = 0;
      uVar14 = 0;
      do {
        uVar12 = 0;
        do {
          if (((bVar6 < 4) && ((byte)(uVar12 + 1) < 0xb)) &&
             (sVar2 = *(short *)(local_88 + 4 + ((uint)bVar6 * 0xb + (uVar12 + 1 & 0xff)) * 2),
             sVar2 != 0)) {
            (&sStack_40)[uVar14 + uVar12] = sVar2;
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 < 6);
        uVar14 = uVar14 + 6;
        bVar6 = bVar6 + 1;
      } while (uVar14 < 0x12);
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 5;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = CONCAT31(local_c._1_3_,3);
    }
    if (((*(byte *)(param_1 + 0x105) < 10) &&
        (iVar8 = (uint)*(byte *)(param_1 + 0x105) * 0x210 + DAT_00f94304,
        *(int *)(iVar8 + 0x5c) != 0)) &&
       ((iVar8 != 0 && (iStack_74 = iVar8 + 0x1d4, iStack_74 != 0)))) {
      iVar8 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
      if (iVar8 != 0) {
        FUN_00408920(iVar8,0x12);
      }
      puStack_7c = (ushort *)((int)&uStack_2a + 2);
      iStack_80 = 0;
      local_88 = 2;
      local_84 = 6;
      puStack_78 = puStack_7c;
      while( true ) {
        do {
          iVar8 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
          if (((iVar8 == 0) || (iStack_80 < 0)) ||
             (*(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2 <= iStack_80)) {
            piVar15 = (int *)0x0;
          }
          else {
            piVar15 = *(int **)(*(int *)(iVar8 + 0xa8) + iStack_80 * 4);
          }
          uVar3 = *puStack_78;
          puVar10 = (undefined4 *)(*(undefined4 **)(iStack_74 + 4))[1];
          cVar1 = *(char *)((int)puVar10 + 0x15);
          puStack_70 = *(undefined4 **)(iStack_74 + 4);
          while (cVar1 == '\0') {
            if (*(ushort *)(puVar10 + 3) < uVar3) {
              puVar9 = (undefined4 *)puVar10[2];
              puVar10 = puStack_70;
            }
            else {
              puVar9 = (undefined4 *)*puVar10;
            }
            puStack_70 = puVar10;
            puVar10 = puVar9;
            cVar1 = *(char *)((int)puVar9 + 0x15);
          }
          puVar10 = *(undefined4 **)(iStack_74 + 4);
          if ((puStack_70 == puVar10) || (uVar3 < *(ushort *)(puStack_70 + 3))) {
            puStack_60 = puVar10;
            ppuVar11 = &puStack_60;
          }
          else {
            ppuVar11 = &puStack_70;
          }
          if ((*ppuVar11 == puVar10) || (iVar8 = (*ppuVar11)[4], iVar8 == 0)) {
            uVar7 = *(undefined1 *)(param_1 + 0x104);
            *(ushort *)(piVar15 + 0x93) = uVar3;
            *(undefined1 *)((int)piVar15 + 0x24e) = 1;
            *(undefined1 *)((int)piVar15 + 0x24f) = uVar7;
            FUN_00470200();
            uVar7 = FUN_00470ac0(**(undefined4 **)(param_1 + 0x108),uVar3);
            uStack_6c = CONCAT31(uStack_6c._1_3_,uVar7);
            uVar13 = uStack_6c;
          }
          else {
            uVar4 = *(undefined2 *)(iVar8 + 4);
            uVar7 = *(undefined1 *)(param_1 + 0x104);
            *(ushort *)(piVar15 + 0x93) = uVar3;
            *(char *)((int)piVar15 + 0x24e) = (char)uVar4;
            *(undefined1 *)((int)piVar15 + 0x24f) = uVar7;
            FUN_00470200();
            uVar7 = FUN_00470ac0(**(undefined4 **)(param_1 + 0x108),uVar3);
            uStack_64 = CONCAT31(uStack_64._1_3_,uVar7);
            uVar13 = uStack_64;
          }
          (**(code **)(*(int *)piVar15[0x92] + 0x90))(uVar13);
          (**(code **)(*piVar15 + 200))();
          puStack_78 = puStack_78 + 1;
          iStack_80 = iStack_80 + 1;
          local_84 = local_84 + -1;
        } while (local_84 != 0);
        puStack_7c = puStack_7c + -6;
        local_88 = local_88 + -1;
        if (local_88 < 0) break;
        local_84 = 6;
        puStack_78 = puStack_7c;
      }
      piVar15 = *(int **)(param_1 + 0xfc);
      puVar10 = (undefined4 *)piVar15[0x19];
      local_84 = 0;
      for (puVar9 = (undefined4 *)*puVar10; puVar9 != puVar10; puVar9 = (undefined4 *)*puVar9) {
        iVar8 = puVar9[2];
        if ((*(int *)(iVar8 + 0x60) != 0) && ((*(int **)(iVar8 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar8 + 0x1c) + 0x30))(iVar8);
        }
      }
      (**(code **)(*piVar15 + 0x128))();
      (**(code **)(**(int **)(local_68 + 0xfc) + 200))();
    }
    if (7 < uStack_48) {
      FUN_0089120c(uStack_5c);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_8c);
  return;
}


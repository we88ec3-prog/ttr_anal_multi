
/* WARNING: Removing unreachable block (ram,0x006d1a23) */
/* WARNING: Removing unreachable block (ram,0x006d1a27) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d1480(void)

{
  HWND pHVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  HWND pHVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 **ppuVar8;
  byte *pbVar9;
  byte bVar10;
  int in_ECX;
  undefined4 *puVar11;
  char cVar12;
  byte *pbVar13;
  uint *puVar14;
  int *piVar15;
  undefined4 *puVar16;
  undefined **local_78;
  undefined4 *local_74;
  undefined4 local_70;
  undefined4 *local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 *local_54;
  undefined4 *local_50;
  int local_4c;
  int *local_48;
  char local_41;
  undefined4 *local_40;
  byte local_3c [40];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928a5b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x7fc) == 0) {
    *(int *)(in_ECX + 0x7fc) = in_ECX + 4;
  }
  local_3c[0] = 0;
  local_4c = in_ECX;
  local_14 = uVar2;
  _memset(local_3c + 1,0,0x27);
  if (DAT_00fba80c == 0) {
    iVar3 = FUN_00891268(0x57c,uVar2);
    if (iVar3 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  if (*(int *)(DAT_00fba80c + 0x20) == 0) {
    local_40 = (undefined4 *)(DAT_00fba80c + 0x260);
  }
  else {
    local_40 = (undefined4 *)(DAT_00fba80c + 0x60);
  }
  local_41 = '\0';
  if ((*(char *)((int)local_40 + 0x1d) != '\0') || (*(char *)((int)local_40 + 0x9d) != '\0')) {
    local_41 = '\x01';
  }
  local_48 = *(int **)(in_ECX + 0x7fc);
  iVar3 = 0;
  do {
    puVar14 = (uint *)*local_48;
    for (iVar4 = local_48[1] - (int)puVar14 >> 2; iVar4 != 0; iVar4 = iVar4 + -1) {
      uVar2 = *puVar14;
      cVar12 = '\x01';
      if ((char)(uVar2 >> 0x10) == '\0') {
        if (local_41 != '\0') {
          cVar12 = '\0';
        }
      }
      else {
        cVar12 = *(char *)((uVar2 >> 0x10 & 0xff) + (int)local_40);
      }
      if (((char)uVar2 != '\0') && (cVar12 != '\0')) {
        local_3c[iVar3] = local_3c[iVar3] | *(byte *)((uVar2 & 0xff) + (int)local_40);
      }
      puVar14 = puVar14 + 1;
    }
    if (local_3c[iVar3] != 0) {
      local_3c[iVar3] = 0x80;
    }
    local_48 = local_48 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x28);
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 0;
  }
  local_8._0_1_ = 0;
  iVar3 = 0;
  if ((DAT_00fb9111 != '\0') &&
     (pHVar1 = *(HWND *)(DAT_00fb1318 + 0x10), pHVar5 = GetForegroundWindow(), pHVar5 == pHVar1)) {
    if ((_DAT_00fc1a6c & 1) == 0) {
      _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
      _atexit((_func_4879 *)&DAT_00bce3b0);
    }
    FUN_006f33f0(&local_64);
    iVar3 = local_60;
  }
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8._0_1_ = 2;
    DAT_00fc1730 = 0;
    iVar4 = FUN_00891268(0x30);
    if (iVar4 == 0) {
      local_48 = (int *)0x0;
      std::exception::exception((exception *)&local_78,(char **)&local_48);
      local_78 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&local_78,&DAT_00c857a8);
    }
    DAT_00fc172c = iVar4;
    *(int *)iVar4 = iVar4;
    *(int *)(DAT_00fc172c + 4) = DAT_00fc172c;
    *(int *)(DAT_00fc172c + 8) = DAT_00fc172c;
    *(undefined1 *)(DAT_00fc172c + 0x2c) = 1;
    *(undefined1 *)(DAT_00fc172c + 0x2d) = 1;
    local_8._0_1_ = 3;
    FUN_006ccc00(&DAT_00fc173c);
    local_8._0_1_ = 4;
    FUN_006ccc00(&DAT_00fc17bc);
    local_8._0_1_ = 5;
    DAT_00fc1778 = 1;
    FUN_006cd0e0();
    _atexit((_func_4879 *)&LAB_00bce3c0);
    local_8._0_1_ = 0;
  }
  if ((DAT_00fc1a70 & 1) == 0) {
    DAT_00fc1a70 = DAT_00fc1a70 | 1;
    local_8._0_1_ = 6;
    FUN_006cfc50();
    local_8._0_1_ = 0;
  }
  if (DAT_00fc1a78 == 1) {
    piVar15 = (int *)0x0;
    local_48 = (int *)(iVar3 - local_64 >> 2);
    puVar16 = DAT_00fc1820;
    if (local_48 != (int *)0x0) {
      do {
        iVar3 = local_64;
        puVar7 = *(undefined4 **)(local_64 + (int)piVar15 * 4);
        cVar12 = *(char *)((int)puVar16[1] + 0x19);
        puVar6 = (undefined4 *)puVar16[1];
        local_40 = puVar16;
        while (puVar11 = puVar6, cVar12 == '\0') {
          if ((int)puVar11[3] < (int)puVar7) {
            puVar6 = (undefined4 *)puVar11[2];
            puVar11 = local_40;
          }
          else {
            puVar6 = (undefined4 *)*puVar11;
          }
          cVar12 = *(char *)((int)puVar6 + 0x19);
          local_40 = puVar11;
        }
        if ((local_40 == puVar16) || ((int)puVar7 < (int)local_40[3])) {
          local_6c = puVar16;
          ppuVar8 = &local_6c;
        }
        else {
          ppuVar8 = &local_40;
        }
        if (*ppuVar8 == puVar16) {
          local_40 = puVar7;
          FUN_0062db10(&local_40);
          if (local_68 != DAT_00fc1810) {
            *(undefined4 *)(iVar3 + (int)piVar15 * 4) = *(undefined4 *)(local_68 + 0x14);
            puVar16 = DAT_00fc1820;
          }
          local_40 = *(undefined4 **)(local_64 + (int)piVar15 * 4);
          FUN_0062db10(&local_40);
          puVar7 = local_50;
          if ((local_50 != DAT_00fc1830) && (*(char *)(local_4c + 0x808) == '\0')) {
            if ((DAT_00fdf3ec & 1) == 0) {
              DAT_00fdf3ec = DAT_00fdf3ec | 1;
              local_8._0_1_ = 7;
              FUN_006d1da0();
              _atexit((_func_4879 *)&LAB_00bce330);
              local_8._0_1_ = 0;
            }
            puVar16 = (undefined4 *)puVar7[5];
            local_40 = puVar16;
            FUN_0082ef00(&local_40);
            if (local_54 != DAT_00fdf634) {
              local_70 = 1;
              local_74 = puVar16;
              FUN_0041e560();
            }
            *(undefined4 *)(local_64 + (int)piVar15 * 4) = 0;
            *(undefined1 *)(local_4c + 0x808) = 1;
            puVar16 = DAT_00fc1820;
          }
        }
        else {
          *(undefined4 *)(local_64 + (int)piVar15 * 4) = 0;
          puVar16 = DAT_00fc1820;
        }
        piVar15 = (int *)((int)piVar15 + 1);
        iVar3 = local_60;
      } while (piVar15 < local_48);
    }
    if (local_48 == (int *)0x0) {
      *(undefined1 *)(local_4c + 0x808) = 0;
    }
  }
  piVar15 = (int *)0x0;
  local_48 = (int *)(iVar3 - local_64 >> 2);
  if (local_48 != (int *)0x0) {
    puVar16 = (undefined4 *)DAT_00fc1800[1];
    do {
      iVar3 = *(int *)(local_64 + (int)piVar15 * 4);
      cVar12 = *(char *)((int)puVar16 + 0x19);
      puVar7 = puVar16;
      local_54 = DAT_00fc1800;
      while (puVar6 = puVar7, cVar12 == '\0') {
        if ((int)puVar6[3] < iVar3) {
          puVar7 = (undefined4 *)puVar6[2];
          puVar6 = local_54;
        }
        else {
          puVar7 = (undefined4 *)*puVar6;
        }
        cVar12 = *(char *)((int)puVar7 + 0x19);
        local_54 = puVar6;
      }
      if ((local_54 == DAT_00fc1800) || (iVar3 < (int)local_54[3])) {
        local_50 = DAT_00fc1800;
        ppuVar8 = &local_50;
      }
      else {
        ppuVar8 = &local_54;
      }
      if ((*ppuVar8 != DAT_00fc1800) && (iVar3 = (*ppuVar8)[5], iVar3 < 0x28)) {
        local_3c[iVar3] = 0x80;
      }
      piVar15 = (int *)((int)piVar15 + 1);
    } while (piVar15 < local_48);
  }
  if (local_3c[5] != '\0') {
    if (local_3c[1] != '\0') {
      local_3c[6] = 0x80;
      local_3c[1] = '\0';
    }
    if (local_3c[3] != '\0') {
      local_3c[8] = 0x80;
      local_3c[3] = '\0';
    }
    if (local_3c[4] != '\0') {
      local_3c[9] = 0x80;
      local_3c[4] = '\0';
    }
    if (local_3c[2] != '\0') {
      local_3c[7] = 0x80;
      local_3c[2] = '\0';
    }
  }
  pbVar13 = local_3c + 1;
  pbVar9 = (byte *)(local_4c + 0x7d4);
  iVar3 = 8;
  do {
    bVar10 = pbVar9[-0x28];
    if (bVar10 == pbVar13[-1]) {
      bVar10 = bVar10 >> 6 & 2;
    }
    else {
      bVar10 = (byte)((bVar10 | 0x40) >> 6);
    }
    *pbVar9 = bVar10;
    bVar10 = pbVar9[-0x27];
    if (bVar10 == *pbVar13) {
      bVar10 = bVar10 >> 6 & 2;
    }
    else {
      bVar10 = (byte)((bVar10 | 0x40) >> 6);
    }
    pbVar9[1] = bVar10;
    bVar10 = pbVar9[-0x26];
    if (bVar10 == pbVar13[1]) {
      bVar10 = bVar10 >> 6 & 2;
    }
    else {
      bVar10 = (byte)((bVar10 | 0x40) >> 6);
    }
    pbVar9[2] = bVar10;
    bVar10 = pbVar9[-0x25];
    if (bVar10 == pbVar13[2]) {
      bVar10 = bVar10 >> 6 & 2;
    }
    else {
      bVar10 = (byte)((bVar10 | 0x40) >> 6);
    }
    pbVar9[3] = bVar10;
    bVar10 = pbVar9[-0x24];
    if (bVar10 == pbVar13[3]) {
      bVar10 = bVar10 >> 6 & 2;
    }
    else {
      bVar10 = (byte)((bVar10 | 0x40) >> 6);
    }
    pbVar9[4] = bVar10;
    pbVar9 = pbVar9 + 5;
    pbVar13 = pbVar13 + 5;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pbVar13 = local_3c;
  puVar16 = (undefined4 *)(local_4c + 0x7ac);
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar16 = *(undefined4 *)pbVar13;
    pbVar13 = pbVar13 + 4;
    puVar16 = puVar16 + 1;
  }
  uVar2 = 0;
  if (*(int *)(local_4c + 0x810) - *(int *)(local_4c + 0x80c) >> 3 != 0) {
    do {
      piVar15 = (int *)(*(int *)(local_4c + 0x80c) + uVar2 * 8);
      *(char *)(local_4c + 0x7d4 + *piVar15) = (char)piVar15[1];
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(local_4c + 0x810) - *(int *)(local_4c + 0x80c) >> 3));
  }
  if (*(int *)(local_4c + 0x80c) != *(int *)(local_4c + 0x810)) {
    *(int *)(local_4c + 0x810) = *(int *)(local_4c + 0x80c);
  }
  if (local_64 != 0) {
    FUN_0089120c(local_64);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


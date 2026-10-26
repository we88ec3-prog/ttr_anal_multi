
void FUN_00580390(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  wchar_t ****ppppwVar10;
  wchar_t *pwVar11;
  undefined4 *puVar12;
  char *pcVar13;
  int *in_ECX;
  int *piVar14;
  int iVar15;
  int local_114;
  undefined4 *local_110;
  int iStack_10c;
  int *local_108;
  wchar_t ***apppwStack_104 [4];
  undefined4 uStack_f4;
  uint uStack_f0;
  uint local_e8 [2];
  uint local_e0;
  undefined4 uStack_d8;
  uint uStack_d4;
  undefined4 local_d0;
  uint local_cc;
  undefined4 *local_c4;
  undefined4 *local_c0;
  undefined4 local_bc;
  uint uStack_b4;
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092ae3d;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_114;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffee0;
  ExceptionList = &local_14;
  local_108 = in_ECX;
  if (*in_ECX != in_ECX[1]) {
    iVar5 = FUN_00580d10(in_ECX[1]);
    FUN_005800f0(in_ECX[1],local_110);
    in_ECX[1] = iVar5;
  }
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  else {
    FUN_0072e2e0("Synopsis");
    local_114 = FUN_0072e360(uVar4);
    piVar14 = local_108;
    while (local_114 != 0) {
      local_cc = 0xf;
      local_d0 = 0;
      local_e0 = local_e0 & 0xffffff00;
      local_c4 = (undefined4 *)0x0;
      local_c0 = (undefined4 *)0x0;
      local_bc = 0;
      local_c._1_3_ = (uint3)(local_c >> 8);
      local_c._0_1_ = 1;
      local_108 = piVar14;
      FUN_005809d0(piVar14);
      puVar2 = local_c0;
      puVar12 = local_c4;
      local_c = (uint)local_c._1_3_ << 8;
      puVar1 = local_c4;
      if (local_c4 != (undefined4 *)0x0) {
        for (; puVar1 != puVar2; puVar1 = puVar1 + 7) {
          if (7 < (uint)puVar1[5]) {
            FUN_0089120c(*puVar1);
          }
          puVar1[5] = 7;
          puVar1[4] = 0;
          *(undefined2 *)puVar1 = 0;
        }
        FUN_0089120c(puVar12);
        piVar14 = local_108;
      }
      if (0xf < local_cc) {
        FUN_0089120c(local_e0);
      }
      puVar1 = (undefined4 *)(((piVar14[1] - *piVar14) / 0x34) * 0x34 + -0x34 + *piVar14);
      uStack_d4 = 0xf;
      uStack_d8 = 0;
      local_e8[0] = local_e8[0] & 0xffffff00;
      FUN_00402a70("PicturePath",0xb);
      local_c._0_1_ = 2;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_c = CONCAT31(local_c._1_3_,3);
      FUN_00402bb0(uVar6);
      if (0xf < uStack_f0) {
        FUN_0089120c(apppwStack_104[0]);
      }
      local_c = local_c & 0xffffff00;
      uStack_f0 = 0xf;
      uStack_f4 = 0;
      apppwStack_104[0] = (wchar_t ***)((uint)apppwStack_104[0] & 0xffffff00);
      if (0xf < uStack_d4) {
        FUN_0089120c(local_e8[0]);
      }
      iVar8 = local_114;
      iVar15 = local_114 + 0x44;
      for (iVar5 = *(int *)(local_114 + 0x94); iVar5 != iVar15; iVar5 = *(int *)(iVar5 + 0x50)) {
        pcVar13 = (char *)(iVar5 + 0x14);
        if (0xf < *(uint *)(iVar5 + 0x28)) {
          pcVar13 = *(char **)pcVar13;
        }
        iVar7 = __stricmp(pcVar13,"BaseXPos");
        if (iVar7 == 0) {
          if (iVar5 != 0) {
            puVar12 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar12 = (undefined4 *)*puVar12;
            }
            if (puVar12 != (undefined4 *)0x0) {
              uVar6 = FUN_008917b4(puVar12);
              goto LAB_0058064f;
            }
          }
          break;
        }
      }
      uVar6 = 0x40;
LAB_0058064f:
      *puVar1 = uVar6;
      for (iVar5 = *(int *)(iVar8 + 0x94); iVar5 != iVar15; iVar5 = *(int *)(iVar5 + 0x50)) {
        pcVar13 = (char *)(iVar5 + 0x14);
        if (0xf < *(uint *)(iVar5 + 0x28)) {
          pcVar13 = *(char **)pcVar13;
        }
        iVar8 = __stricmp(pcVar13,"BaseYPos");
        if (iVar8 == 0) {
          if (iVar5 != 0) {
            puVar12 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar12 = (undefined4 *)*puVar12;
            }
            if (puVar12 != (undefined4 *)0x0) {
              uVar6 = FUN_008917b4(puVar12);
              goto LAB_00580690;
            }
          }
          break;
        }
      }
      uVar6 = 0x80;
LAB_00580690:
      puVar1[1] = uVar6;
      for (iVar5 = *(int *)(local_114 + 0x18); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x40)) {
        pcVar13 = (char *)(iVar5 + 0x20);
        if (0xf < *(uint *)(iVar5 + 0x34)) {
          pcVar13 = *(char **)pcVar13;
        }
        iVar8 = __stricmp(pcVar13,"Line");
        if (iVar8 == 0) goto LAB_005806c5;
      }
      iVar5 = 0;
LAB_005806c5:
      iStack_10c = iVar5;
      if (iVar5 != 0) {
        local_110 = puVar1 + 9;
        do {
          if ((*(int **)(iStack_10c + 0x18) == (int *)0x0) ||
             (iVar5 = (**(code **)(**(int **)(iStack_10c + 0x18) + 0x2c))(), iVar5 == 0)) {
            uStack_b4 = uStack_b4 & 0xffff0000;
            uStack_a0 = 7;
            uStack_a4 = 0;
            FUN_00402160(&DAT_00bed1fc,0);
            local_c._0_1_ = 7;
            FUN_0049c120();
            local_c = (uint)local_c._1_3_ << 8;
            if (7 < uStack_a0) {
              FUN_0089120c(uStack_b4);
            }
            uStack_a0 = 7;
            uStack_a4 = 0;
            uStack_b4 = uStack_b4 & 0xffff0000;
          }
          else {
            pcVar13 = (char *)(iVar5 + 0x20);
            if (0xf < *(uint *)(iVar5 + 0x34)) {
              pcVar13 = *(char **)pcVar13;
            }
            uStack_d4 = 0xf;
            uStack_d8 = 0;
            local_e8[0] = local_e8[0] & 0xffffff00;
            pcVar9 = pcVar13;
            do {
              cVar3 = *pcVar9;
              pcVar9 = pcVar9 + 1;
            } while (cVar3 != '\0');
            FUN_00402a70(pcVar13,(int)pcVar9 - (int)(pcVar13 + 1));
            local_c._0_1_ = 4;
            FUN_004028b0(local_e8);
            local_c = CONCAT31(local_c._1_3_,6);
            if (0xf < uStack_d4) {
              FUN_0089120c(local_e8[0]);
            }
            uStack_d4 = 0xf;
            uStack_d8 = 0;
            local_e8[0] = local_e8[0] & 0xffffff00;
            while( true ) {
              ppppwVar10 = (wchar_t ****)apppwStack_104[0];
              if (uStack_f0 < 8) {
                ppppwVar10 = apppwStack_104;
              }
              pwVar11 = _wcsstr((wchar_t *)ppppwVar10,L"nbsp;");
              if (pwVar11 == (wchar_t *)0x0) break;
              ppppwVar10 = (wchar_t ****)apppwStack_104[0];
              if (uStack_f0 < 8) {
                ppppwVar10 = apppwStack_104;
              }
              FUN_00498090((int)pwVar11 - (int)ppppwVar10 >> 1,5,&DAT_00bf3a70,1);
            }
            FUN_0049c120();
            local_c = local_c & 0xffffff00;
            if (7 < uStack_f0) {
              FUN_0089120c(apppwStack_104[0]);
            }
          }
          for (iVar5 = *(int *)(iStack_10c + 0x40); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x40)) {
            pcVar13 = (char *)(iVar5 + 0x20);
            if (0xf < *(uint *)(iVar5 + 0x34)) {
              pcVar13 = *(char **)pcVar13;
            }
            iVar8 = __stricmp(pcVar13,"Line");
            if (iVar8 == 0) goto LAB_005808f5;
          }
          iVar5 = 0;
LAB_005808f5:
          iStack_10c = iVar5;
        } while (iVar5 != 0);
      }
      local_114 = FUN_0072e3c0();
      piVar14 = local_108;
    }
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  local_3c = 0;
  local_4c = local_4c & 0xffffff00;
  local_38 = 0xf;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_114);
  return;
}


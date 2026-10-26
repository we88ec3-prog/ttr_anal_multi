
void FUN_00542230(int *param_1,int param_2)

{
  uint *puVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *****pppppcVar5;
  uint **ppuVar6;
  uint *puVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  char *pcVar11;
  char *****pppppcVar12;
  uint uVar13;
  int local_f8;
  int local_f4;
  int local_f0;
  uint *local_e8;
  int *local_e4;
  uint local_e0;
  uint *local_dc;
  uint local_d8 [4];
  undefined4 local_c8;
  uint local_c4;
  char ****local_bc [4];
  undefined4 local_ac;
  uint local_a8;
  uint local_a0;
  undefined4 local_90;
  uint local_8c;
  uint local_84 [4];
  undefined4 local_74;
  uint local_70;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  char ****local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916e5d;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_e0 = 0;
  local_e4 = param_1;
  puVar7 = local_dc;
  if ((*param_1 != 0) && (param_2 != 0)) {
    puVar3 = (undefined4 *)FUN_0071ba40("Sound");
    puVar1 = (uint *)*puVar3;
    puVar7 = local_dc;
    while (local_dc = puVar1, local_dc != (uint *)0x0) {
      if ((local_dc == (uint *)0x0) || ((*local_dc & 7) != 1)) {
        local_dc = (uint *)0x0;
      }
      FUN_0071baa0(&DAT_00c0f680);
      if (local_f8 == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = *(char **)(local_f8 + 8);
        if (pcVar11 == (char *)0x0) {
          pcVar11 = "";
        }
      }
      local_20 = 0;
      local_1c = 0xf;
      local_30[0] = (char ****)((uint)local_30[0] & 0xffffff00);
      pcVar4 = pcVar11;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      FUN_00402a70(pcVar11,(int)pcVar4 - (int)(pcVar11 + 1));
      local_8 = 0;
      FUN_0071baa0(&DAT_00c0d66c);
      if (local_f4 == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = *(char **)(local_f4 + 8);
        if (pcVar11 == (char *)0x0) {
          pcVar11 = "";
        }
      }
      local_74 = 0;
      local_70 = 0xf;
      local_84[0] = local_84[0] & 0xffffff00;
      pcVar4 = pcVar11;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      FUN_00402a70(pcVar11,(int)pcVar4 - (int)(pcVar11 + 1));
      local_8._0_1_ = 1;
      FUN_00719f10(&local_dc,&DAT_00bf2375);
      local_8._0_1_ = 2;
      uVar13 = *(uint *)(*param_1 + 0x20);
      FUN_0071baa0("Setting");
      if (local_f0 != 0) {
        pppppcVar12 = (char *****)local_bc[0];
        if (local_a8 < 0x10) {
          pppppcVar12 = local_bc;
        }
        local_38 = 0xf;
        local_3c = 0;
        local_4c[0] = local_4c[0] & 0xffffff00;
        pppppcVar5 = pppppcVar12;
        do {
          cVar2 = *(char *)pppppcVar5;
          pppppcVar5 = (char *****)((int)pppppcVar5 + 1);
        } while (cVar2 != '\0');
        FUN_0040b310(pppppcVar12);
        local_8 = CONCAT31(local_8._1_3_,3);
        iVar10 = *param_1;
        local_dc = (uint *)FUN_0080c1c0(local_4c);
        if ((local_dc == *(uint **)(iVar10 + 0x2c)) || (cVar2 = FUN_005436a0(), cVar2 != '\0')) {
          local_e8 = *(uint **)(iVar10 + 0x2c);
          ppuVar6 = &local_e8;
        }
        else {
          ppuVar6 = &local_dc;
        }
        if (*ppuVar6 == *(uint **)(iVar10 + 0x2c)) {
          uVar13 = *(uint *)(iVar10 + 0x24);
        }
        else {
          uVar13 = (*ppuVar6)[10];
        }
        local_8._0_1_ = 2;
        if (0xf < local_38) {
          FUN_0089120c(local_4c[0]);
        }
        local_38 = 0xf;
        local_3c = 0;
        local_4c[0] = local_4c[0] & 0xffffff00;
      }
      puVar7 = (uint *)FUN_00891268(0x5c);
      local_dc = puVar7;
      local_8._0_1_ = 4;
      if (puVar7 == (uint *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        pppppcVar12 = (char *****)local_30[0];
        if (local_1c < 0x10) {
          pppppcVar12 = local_30;
        }
        local_54 = 0xf;
        local_58 = 0;
        local_68 = local_68 & 0xffffff00;
        pppppcVar5 = pppppcVar12;
        do {
          cVar2 = *(char *)pppppcVar5;
          pppppcVar5 = (char *****)((int)pppppcVar5 + 1);
        } while (cVar2 != '\0');
        FUN_0040b310(pppppcVar12);
        local_8 = CONCAT31(local_8._1_3_,5);
        local_e0 = local_e0 | 1;
        uVar8 = FUN_00543500(local_d8,local_e4 + 1,local_84);
        local_8._0_1_ = 6;
        local_8._1_3_ = 0;
        local_e0 = local_e0 | 2;
        piVar9 = (int *)FUN_0080d8e0(puVar7,uVar8,uVar13);
      }
      uVar13 = local_e0;
      if ((local_e0 & 2) != 0) {
        uVar13 = local_e0 & 0xfffffffd;
        local_e0 = uVar13;
        if (0xf < local_c4) {
          FUN_0089120c(local_d8[0]);
        }
        local_c4 = 0xf;
        local_c8 = 0;
        local_d8[0] = local_d8[0] & 0xffffff00;
      }
      local_8 = 2;
      if ((uVar13 & 1) != 0) {
        local_e0 = uVar13 & 0xfffffffe;
        if (0xf < local_54) {
          FUN_0089120c(local_68);
        }
        local_54 = 0xf;
        local_58 = 0;
        local_68 = local_68 & 0xffffff00;
      }
      pppppcVar12 = (char *****)local_30[0];
      if (local_1c < 0x10) {
        pppppcVar12 = local_30;
      }
      local_8c = 0xf;
      local_90 = 0;
      local_a0 = local_a0 & 0xffffff00;
      pppppcVar5 = pppppcVar12;
      do {
        cVar2 = *(char *)pppppcVar5;
        pppppcVar5 = (char *****)((int)pppppcVar5 + 1);
      } while (cVar2 != '\0');
      FUN_0040b310(pppppcVar12);
      local_8._0_1_ = 10;
      iVar10 = FUN_0080b750(*local_e4,piVar9);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (0xf < local_8c) {
        FUN_0089120c(local_a0);
      }
      local_8c = 0xf;
      local_90 = 0;
      local_a0 = local_a0 & 0xffffff00;
      if ((iVar10 == 0) && (piVar9 != (int *)0x0)) {
        (**(code **)(*piVar9 + 0xc))(1);
      }
      if (0xf < local_a8) {
        FUN_0089120c(local_bc[0]);
      }
      local_a8 = 0xf;
      local_ac = 0;
      local_bc[0] = (char ****)((uint)local_bc[0] & 0xffffff00);
      if (0xf < local_70) {
        FUN_0089120c(local_84[0]);
      }
      local_8 = 0xffffffff;
      local_70 = 0xf;
      local_74 = 0;
      local_84[0] = local_84[0] & 0xffffff00;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      puVar3 = (undefined4 *)FUN_0071bb00("Sound");
      puVar7 = local_dc;
      param_1 = local_e4;
      puVar1 = (uint *)*puVar3;
    }
  }
  local_dc = puVar7;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


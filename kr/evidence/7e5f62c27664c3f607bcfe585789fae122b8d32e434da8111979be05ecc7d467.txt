
void FUN_004f5640(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int *_Str1;
  char *pcVar6;
  undefined **local_1ec [19];
  uint local_1a0;
  undefined4 local_190;
  uint local_18c;
  undefined **local_174 [19];
  uint local_128;
  undefined4 local_118;
  uint local_114;
  undefined **local_fc [19];
  uint local_b0;
  undefined4 local_a0;
  uint local_9c;
  uint local_84 [4];
  undefined4 local_74;
  uint local_70;
  uint local_68 [4];
  undefined4 local_58;
  uint local_54;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924781;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0072ee30(local_174);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    FUN_0072e2e0("MAPLIST");
    for (piVar2 = (int *)FUN_0072e2e0(&DAT_00c0d4d0); piVar2 != (int *)0x0;
        piVar2 = (int *)piVar2[0x10]) {
      iVar3 = (**(code **)(*piVar2 + 0x14))();
      if (iVar3 != 0) {
        iVar3 = FUN_007300a0(&DAT_00bed1d0);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_008917b4(puVar4);
          }
        }
        iVar3 = FUN_007300a0("trigger");
        if (iVar3 == 0) {
          pcVar6 = (char *)0x0;
        }
        else {
          pcVar6 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        pcVar5 = pcVar6;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar6,(int)pcVar5 - (int)(pcVar6 + 1));
        local_8._0_1_ = 1;
        iVar3 = FUN_007300a0(&DAT_00c0d4dc);
        if (iVar3 == 0) {
          pcVar6 = (char *)0x0;
        }
        else if (*(uint *)(iVar3 + 0x44) < 0x10) {
          pcVar6 = (char *)(iVar3 + 0x30);
        }
        else {
          pcVar6 = *(char **)(iVar3 + 0x30);
        }
        local_38 = 0xf;
        local_3c = 0;
        local_4c[0] = local_4c[0] & 0xffffff00;
        pcVar5 = pcVar6;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar6,(int)pcVar5 - (int)(pcVar6 + 1));
        local_8._0_1_ = 2;
        iVar3 = FUN_007300a0("bound");
        if (iVar3 == 0) {
          pcVar6 = (char *)0x0;
        }
        else if (*(uint *)(iVar3 + 0x44) < 0x10) {
          pcVar6 = (char *)(iVar3 + 0x30);
        }
        else {
          pcVar6 = *(char **)(iVar3 + 0x30);
        }
        local_54 = 0xf;
        local_58 = 0;
        local_68[0] = local_68[0] & 0xffffff00;
        pcVar5 = pcVar6;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar6,(int)pcVar5 - (int)(pcVar6 + 1));
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004f7df0();
        FUN_00403040(local_30,0,0xffffffff);
        FUN_004f7df0();
        FUN_00403040(local_4c,0,0xffffffff);
        FUN_004f7df0();
        FUN_00403040(local_68,0,0xffffffff);
        if (0xf < local_54) {
          FUN_0089120c(local_68[0]);
        }
        local_54 = 0xf;
        local_58 = 0;
        local_68[0] = local_68[0] & 0xffffff00;
        if (0xf < local_38) {
          FUN_0089120c(local_4c[0]);
        }
        local_8 = local_8 & 0xffffff00;
        local_38 = 0xf;
        local_3c = 0;
        local_4c[0] = local_4c[0] & 0xffffff00;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
    }
  }
  FUN_0072ee30(local_1ec);
  local_8 = CONCAT31(local_8._1_3_,4);
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    FUN_0072e2e0("SYSMAPLIST");
    piVar2 = (int *)FUN_0072e2e0(&DAT_00c0d4d0);
joined_r0x004f5941:
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x14))();
      if (iVar3 != 0) {
        iVar3 = FUN_007300a0(&DAT_00bed1d0);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_008917b4(puVar4);
          }
        }
        iVar3 = FUN_007300a0(&DAT_00c0d4dc);
        if (iVar3 == 0) {
          pcVar6 = (char *)0x0;
        }
        else {
          pcVar6 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        pcVar5 = pcVar6;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar6,(int)pcVar5 - (int)(pcVar6 + 1));
        local_8._0_1_ = 5;
        FUN_004f7df0();
        FUN_00403040(local_30,0,0xffffffff);
        local_8 = CONCAT31(local_8._1_3_,4);
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
      for (piVar2 = (int *)piVar2[0x10]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x10]) {
        _Str1 = piVar2 + 8;
        if (0xf < (uint)piVar2[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar3 = __stricmp((char *)_Str1,"MAP");
        if (iVar3 == 0) goto joined_r0x004f5941;
      }
      piVar2 = (int *)0x0;
      goto joined_r0x004f5941;
    }
  }
  FUN_0072ee30(local_fc);
  local_8 = CONCAT31(local_8._1_3_,6);
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    FUN_0072e2e0("MUSICLIST");
    for (piVar2 = (int *)FUN_0072e2e0(&DAT_00c0d4d0); piVar2 != (int *)0x0;
        piVar2 = (int *)piVar2[0x10]) {
      iVar3 = (**(code **)(*piVar2 + 0x14))();
      if (iVar3 != 0) {
        iVar3 = FUN_007300a0(&DAT_00bed1d0);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_008917b4(puVar4);
          }
        }
        local_38 = 0xf;
        local_3c = 0;
        local_4c[0] = local_4c[0] & 0xffffff00;
        FUN_00402a70("MUSIC",5);
        local_8._0_1_ = 7;
        FUN_0072ecf0(&DAT_00c0d530);
        local_8._0_1_ = 9;
        if (0xf < local_38) {
          FUN_0089120c(local_4c[0]);
        }
        local_38 = 0xf;
        local_3c = 0;
        local_4c[0] = local_4c[0] & 0xffffff00;
        local_54 = 0xf;
        local_58 = 0;
        local_68[0] = local_68[0] & 0xffffff00;
        FUN_00402a70("ENVSOUND",8);
        local_8._0_1_ = 10;
        FUN_0072ecf0(&DAT_00c0d530);
        local_8 = CONCAT31(local_8._1_3_,0xc);
        if (0xf < local_54) {
          FUN_0089120c(local_68[0]);
        }
        local_54 = 0xf;
        local_58 = 0;
        local_68[0] = local_68[0] & 0xffffff00;
        FUN_004f7df0();
        FUN_00403040(local_84,0,0xffffffff);
        FUN_004f7df0();
        FUN_00403040(local_30,0,0xffffffff);
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        local_8 = CONCAT31(local_8._1_3_,6);
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        if (0xf < local_70) {
          FUN_0089120c(local_84[0]);
        }
        local_70 = 0xf;
        local_74 = 0;
        local_84[0] = local_84[0] & 0xffffff00;
      }
    }
  }
  local_8._0_1_ = 4;
  local_fc[0] = TiXmlDocument::vftable;
  if (0xf < local_9c) {
    FUN_0089120c(local_b0);
  }
  local_9c = 0xf;
  local_a0 = 0;
  local_b0 = local_b0 & 0xffffff00;
  FUN_0072e040();
  local_8 = (uint)local_8._1_3_ << 8;
  local_1ec[0] = TiXmlDocument::vftable;
  if (0xf < local_18c) {
    FUN_0089120c(local_1a0);
  }
  local_18c = 0xf;
  local_190 = 0;
  local_1a0 = local_1a0 & 0xffffff00;
  FUN_0072e040();
  local_8 = 0xffffffff;
  local_174[0] = TiXmlDocument::vftable;
  if (0xf < local_114) {
    FUN_0089120c(local_128);
  }
  local_114 = 0xf;
  local_118 = 0;
  local_128 = local_128 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


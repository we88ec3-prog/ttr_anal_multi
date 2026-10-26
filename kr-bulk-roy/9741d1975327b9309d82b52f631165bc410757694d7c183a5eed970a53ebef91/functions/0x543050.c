
void FUN_00543050(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char ****ppppcVar8;
  undefined4 *_Dst;
  char ****ppppcVar9;
  int *piVar10;
  char *pcVar11;
  int iVar12;
  undefined4 *puVar13;
  int local_1b0;
  undefined4 local_19c;
  char local_198 [96];
  undefined4 local_138;
  undefined4 local_134;
  undefined1 local_70;
  uint local_6c;
  undefined4 local_5c;
  uint local_58;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  char ***local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923191;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_138 = 0;
  local_134 = 0;
  FUN_0071bc20(local_18);
  local_70 = 0;
  local_58 = 0xf;
  local_5c = 0;
  local_6c = local_6c & 0xffffff00;
  local_8 = 0;
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
  FUN_00402a70("Table/_Sound.xml",0x10);
  local_8 = CONCAT31(local_8._1_3_,1);
  ppppcVar8 = (char ****)local_34[0];
  if (local_20 < 0x10) {
    ppppcVar8 = local_34;
  }
  piVar4 = (int *)FUN_00714770(ppppcVar8,&DAT_00bed1e0);
  if (piVar4 == (int *)0x0) {
    cVar3 = '\0';
  }
  else {
    (**(code **)(*piVar4 + 0x38))();
    uVar5 = (**(code **)(*piVar4 + 0x2c))();
    cVar3 = FUN_00499340(uVar5);
    (**(code **)(*piVar4 + 4))();
  }
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  if ((cVar3 != '\0') && (piVar4 = (int *)FUN_0071ba40("SoundDefinition"), *piVar4 != 0)) {
    puVar6 = (undefined4 *)FUN_0071ba40("DefaultSettings");
    uVar5 = *puVar6;
    piVar4 = (int *)FUN_0071ba40("Settings");
    iVar12 = *piVar4;
    piVar4 = (int *)FUN_0071ba40("SoundBaseDir");
    iVar1 = *piVar4;
    puVar6 = (undefined4 *)FUN_0071ba40("SoundList");
    uVar2 = *puVar6;
    puVar6 = (undefined4 *)FUN_0071ba40("SoundSetList");
    local_19c = *puVar6;
    FUN_00542cd0(param_1,uVar5,0);
    while (iVar12 != 0) {
      _memset(local_198,0,0x5c);
      FUN_00542cd0(param_1,iVar12,local_198);
      FUN_0071baa0(&DAT_00c0f680);
      if (local_1b0 == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = *(char **)(local_1b0 + 8);
        if (pcVar11 == (char *)0x0) {
          pcVar11 = "";
        }
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
      pcVar7 = pcVar11;
      do {
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
      FUN_00402a70(pcVar11,(int)pcVar7 - (int)(pcVar11 + 1));
      local_8._0_1_ = 2;
      ppppcVar8 = (char ****)local_34[0];
      if (local_20 < 0x10) {
        ppppcVar8 = local_34;
      }
      _strcpy_s(local_198,0x20,(char *)ppppcVar8);
      _Dst = (undefined4 *)FUN_00891268(0x78);
      local_8._0_1_ = 3;
      puVar6 = (undefined4 *)0x0;
      if (_Dst != (undefined4 *)0x0) {
        _memset(_Dst,0,0x5c);
        _Dst[0x1c] = 0xf;
        _Dst[0x1b] = 0;
        *(undefined1 *)(_Dst + 0x17) = 0;
        FUN_00403040(local_34,0,0xffffffff);
        pcVar11 = local_198;
        puVar13 = _Dst;
        for (iVar12 = 0x17; puVar6 = _Dst, iVar12 != 0; iVar12 = iVar12 + -1) {
          *puVar13 = *(undefined4 *)pcVar11;
          pcVar11 = pcVar11 + 4;
          puVar13 = puVar13 + 1;
        }
      }
      local_8._0_1_ = 2;
      ppppcVar8 = (char ****)local_34[0];
      if (local_20 < 0x10) {
        ppppcVar8 = local_34;
      }
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      ppppcVar9 = ppppcVar8;
      do {
        cVar3 = *(char *)ppppcVar9;
        ppppcVar9 = (char ****)((int)ppppcVar9 + 1);
      } while (cVar3 != '\0');
      FUN_0040b310(ppppcVar8);
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_0080bf50(*param_1,puVar6);
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      piVar4 = (int *)FUN_0071bb00("Settings");
      iVar12 = *piVar4;
      local_8 = local_8 & 0xffffff00;
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
    }
    if (iVar1 != 0) {
      FUN_0071baa0(&DAT_00c0f7c0);
      if (local_1b0 == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = *(char **)(local_1b0 + 8);
        if (pcVar11 == (char *)0x0) {
          pcVar11 = "";
        }
      }
      pcVar7 = pcVar11;
      do {
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
      piVar4 = param_1 + 1;
      FUN_00402a70(pcVar11,(int)pcVar7 - (int)(pcVar11 + 1));
      if (0xf < (uint)param_1[6]) {
        piVar4 = (int *)*piVar4;
      }
      piVar10 = piVar4;
      do {
        iVar12 = *piVar10;
        piVar10 = (int *)((int)piVar10 + 1);
      } while ((char)iVar12 != '\0');
      FUN_00402a70(piVar4,(int)piVar10 - (int)((int)piVar4 + 1));
    }
    FUN_00542230(param_1,uVar2);
    if (*param_1 != 0) {
      FUN_00542710(param_1,&local_19c);
    }
  }
  local_8 = 0xffffffff;
  if (0xf < local_58) {
    FUN_0089120c(local_6c);
  }
  local_58 = 0xf;
  local_5c = 0;
  local_6c = local_6c & 0xffffff00;
  FUN_0071bc90(&local_138);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


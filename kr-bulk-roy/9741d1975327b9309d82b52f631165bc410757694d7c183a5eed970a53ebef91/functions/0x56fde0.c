
void FUN_0056fde0(int param_1)

{
  int iVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int *_Str1;
  char *pcVar11;
  undefined4 uVar12;
  int *piVar13;
  bool bVar14;
  undefined **local_13c [4];
  undefined4 local_12c;
  undefined4 local_128;
  int local_124;
  char *local_120;
  undefined1 *local_11c;
  int *local_118;
  uint *local_114;
  undefined **local_110 [19];
  uint local_c4;
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_98;
  uint local_94 [4];
  undefined4 local_84;
  uint local_80;
  undefined4 local_78;
  undefined1 local_74 [4];
  undefined4 *local_70;
  uint local_64;
  uint local_54;
  uint local_50;
  uint local_48 [4];
  undefined4 local_38;
  uint local_34;
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined4 *local_24;
  undefined4 local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922e64;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_124 = param_1 + 0x24;
  local_18 = uVar4;
  FUN_00570560(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
  *(int *)(*(int *)(param_1 + 0x28) + 4) = *(int *)(param_1 + 0x28);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(int *)(*(int *)(param_1 + 0x28) + 8) = *(int *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_0072ee30(local_110);
  local_8 = 0;
  cVar3 = FUN_0072f110(0);
  if ((cVar3 != '\0') && (iVar5 = FUN_0072e2e0("Minimap"), iVar5 != 0)) {
    local_118 = (int *)FUN_0072e2e0("MarkerCategory");
    piVar13 = local_118;
    while (piVar13 != (int *)0x0) {
      (**(code **)(*local_118 + 0x14))();
      local_34 = 0xf;
      local_38 = 0;
      local_48[0] = local_48[0] & 0xffffff00;
      local_8._0_1_ = 1;
      local_20 = 0;
      puVar6 = (undefined4 *)FUN_00891268(0x18);
      if (puVar6 == (undefined4 *)0x0) {
        local_120 = (char *)0x0;
        std::exception::exception((exception *)local_13c,&local_120);
        local_13c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_13c,&DAT_00c857a8);
      }
      *puVar6 = puVar6;
      puVar6[1] = puVar6;
      puVar6[2] = puVar6;
      *(undefined1 *)(puVar6 + 5) = 1;
      *(undefined1 *)((int)puVar6 + 0x15) = 1;
      local_8 = CONCAT31(local_8._1_3_,2);
      local_24 = puVar6;
      iVar5 = FUN_007300a0(&DAT_00bed1d0);
      if (iVar5 == 0) {
LAB_0056ff5e:
        local_114 = (uint *)0x0;
      }
      else {
        puVar6 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 == (undefined4 *)0x0) goto LAB_0056ff5e;
        local_114 = (uint *)FUN_008917b4(puVar6);
      }
      iVar5 = FUN_007300a0(&DAT_00bed1d4);
      if (iVar5 == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = (char *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          pcVar11 = *(char **)pcVar11;
        }
      }
      pcVar7 = pcVar11;
      do {
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
      FUN_00402a70(pcVar11,(int)pcVar7 - (int)(pcVar11 + 1));
      iVar5 = FUN_007300a0(&DAT_00c108b4);
      if (iVar5 == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = (char *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          pcVar11 = *(char **)pcVar11;
        }
      }
      local_50 = 0xf;
      local_54 = 0;
      local_64 = local_64 & 0xffffff00;
      pcVar7 = pcVar11;
      do {
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
      FUN_00402a70(pcVar11,(int)pcVar7 - (int)(pcVar11 + 1));
      uVar9 = local_54;
      local_8 = CONCAT31(local_8._1_3_,3);
      uVar8 = local_54;
      if (6 < local_54) {
        uVar8 = 7;
      }
      iVar5 = FUN_00407e70(uVar8);
      bVar14 = false;
      if (iVar5 == 0) {
        if (uVar9 < 7) {
          uVar8 = 0xffffffff;
        }
        else {
          uVar8 = (uint)(uVar9 != 7);
        }
        bVar14 = uVar8 == 0;
      }
      if (bVar14) {
        local_2c = 0;
      }
      else {
        uVar8 = uVar9;
        if (7 < uVar9) {
          uVar8 = 8;
        }
        iVar5 = FUN_00407e70(uVar8);
        bVar14 = false;
        if (iVar5 == 0) {
          if (uVar9 < 8) {
            uVar8 = 0xffffffff;
          }
          else {
            uVar8 = (uint)(uVar9 != 8);
          }
          bVar14 = uVar8 == 0;
        }
        if (bVar14) {
          local_2c = 1;
        }
        else {
          uVar8 = uVar9;
          if (7 < uVar9) {
            uVar8 = 8;
          }
          iVar5 = FUN_00407e70(uVar8);
          bVar14 = false;
          if (iVar5 == 0) {
            if (uVar9 < 8) {
              uVar9 = 0xffffffff;
            }
            else {
              uVar9 = (uint)(uVar9 != 8);
            }
            bVar14 = uVar9 == 0;
          }
          if (bVar14) {
            local_2c = 2;
          }
        }
      }
      iVar5 = FUN_0072e360();
      puVar2 = local_114;
      uVar12 = local_98;
      while (local_98 = puVar2, local_11c = (undefined1 *)iVar5, iVar5 != 0) {
        local_114 = (uint *)local_98;
        local_98 = uVar12;
        for (iVar1 = *(int *)(iVar5 + 0x94); iVar1 != iVar5 + 0x44; iVar1 = *(int *)(iVar1 + 0x50))
        {
          pcVar11 = (char *)(iVar1 + 0x14);
          if (0xf < *(uint *)(iVar1 + 0x28)) {
            pcVar11 = *(char **)pcVar11;
          }
          iVar10 = __stricmp(pcVar11,"id");
          if (iVar10 == 0) {
            if (iVar1 != 0) {
              puVar6 = (undefined4 *)(iVar1 + 0x30);
              if (0xf < *(uint *)(iVar1 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                uVar12 = FUN_008917b4(puVar6);
                goto LAB_00570141;
              }
            }
            break;
          }
        }
        uVar12 = 0;
LAB_00570141:
        for (iVar1 = *(int *)(iVar5 + 0x94); iVar1 != iVar5 + 0x44; iVar1 = *(int *)(iVar1 + 0x50))
        {
          pcVar11 = (char *)(iVar1 + 0x14);
          if (0xf < *(uint *)(iVar1 + 0x28)) {
            pcVar11 = *(char **)pcVar11;
          }
          iVar10 = __stricmp(pcVar11,"ImageIdx");
          if (iVar10 == 0) {
            if (iVar1 != 0) {
              puVar6 = (undefined4 *)(iVar1 + 0x30);
              if (0xf < *(uint *)(iVar1 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                local_128 = FUN_008917b4(puVar6);
                goto LAB_0057017a;
              }
            }
            break;
          }
        }
        local_128 = 0;
LAB_0057017a:
        local_12c = uVar12;
        uVar12 = FUN_0057ef20();
        FUN_0057e850(local_28,uVar12);
        iVar5 = FUN_0072e3c0();
        puVar2 = local_114;
        uVar12 = local_98;
      }
      local_114 = local_94;
      local_80 = 0xf;
      local_84 = 0;
      local_94[0] = local_94[0] & 0xffffff00;
      FUN_00403040(local_48,0,0xffffffff);
      local_8._0_1_ = 4;
      local_78 = local_2c;
      FUN_0051ab00(local_74,local_28);
      iVar5 = local_124;
      local_8._0_1_ = 5;
      uVar12 = FUN_00570ca0(&local_98);
      FUN_00570a70(iVar5,uVar12);
      local_114 = local_94;
      local_11c = local_74;
      local_8 = CONCAT31(local_8._1_3_,7);
      FUN_005540c0(*local_70,local_70);
      FUN_0089120c(local_70);
      if (0xf < local_80) {
        FUN_0089120c(local_94[0]);
      }
      for (piVar13 = (int *)local_118[0x10]; piVar13 != (int *)0x0; piVar13 = (int *)piVar13[0x10])
      {
        _Str1 = piVar13 + 8;
        if (0xf < (uint)piVar13[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar5 = __stricmp((char *)_Str1,"MarkerCategory");
        if (iVar5 == 0) goto LAB_005702c9;
      }
      piVar13 = (int *)0x0;
LAB_005702c9:
      local_118 = piVar13;
      if (0xf < local_50) {
        FUN_0089120c(local_64);
      }
      local_50 = 0xf;
      local_54 = 0;
      local_64 = local_64 & 0xffffff00;
      local_114 = (uint *)local_28;
      local_8._0_1_ = 9;
      FUN_005540c0(*local_24,local_24);
      FUN_0089120c(local_24);
      local_8 = (uint)local_8._1_3_ << 8;
      if (0xf < local_34) {
        FUN_0089120c(local_48[0]);
      }
      local_34 = 0xf;
      local_38 = 0;
      local_48[0] = local_48[0] & 0xffffff00;
    }
  }
  local_110[0] = TiXmlDocument::vftable;
  local_8 = 0xffffffff;
  if (0xf < local_b0) {
    local_8 = 0xffffffff;
    local_110[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_c4,uVar4);
  }
  local_b0 = 0xf;
  local_b4 = 0;
  local_c4 = local_c4 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



/* WARNING: Type propagation algorithm not settling */

void FUN_00551030(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char *******pppppppcVar9;
  char *pcVar10;
  int *piVar11;
  int iVar12;
  undefined1 local_1f8 [16];
  undefined **local_1e8 [3];
  undefined **local_1dc [3];
  undefined4 local_1d0;
  undefined4 local_1cc;
  char *local_1c8;
  int local_1c4;
  int local_1c0;
  int *local_1bc;
  int local_1b8;
  int *local_1b4;
  char *local_1b0;
  int local_1ac;
  int *local_1a8;
  int local_1a4;
  undefined1 local_1a0 [120];
  undefined **local_128 [19];
  uint local_dc;
  undefined4 local_cc;
  uint local_c8;
  uint local_ac;
  undefined4 local_a8 [3];
  undefined4 local_9c;
  uint local_98;
  uint local_94;
  int local_90;
  uint local_8c;
  undefined4 local_7c;
  uint local_78;
  uint local_70 [4];
  undefined4 local_60;
  uint local_5c;
  char *******local_54 [4];
  undefined4 local_44;
  uint local_40;
  uint local_38;
  uint local_34 [3];
  undefined4 local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009230b6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1b8 = param_1;
  local_18 = uVar2;
  FUN_0072ee30(local_128);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 == '\0') || (iVar3 = FUN_0072e2e0("EffectList"), iVar3 == 0)) {
    local_128[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_c8) {
      local_8 = 0xffffffff;
      local_128[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_dc,uVar2);
    }
    local_c8 = 0xf;
    local_cc = 0;
    local_dc = local_dc & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_1a8 = (int *)FUN_0072e2e0("Effect");
    piVar11 = local_1a8;
    while (piVar11 != (int *)0x0) {
      local_1ac = (**(code **)(*local_1a8 + 0x14))();
      piVar4 = (int *)FUN_00891268(0x54);
      piVar11 = (int *)0x0;
      if (piVar4 != (int *)0x0) {
        piVar4[4] = 0;
        piVar4[5] = 0xf;
        *(undefined1 *)piVar4 = 0;
        piVar4[0xb] = 0;
        piVar4[0xc] = 0xf;
        *(undefined1 *)(piVar4 + 7) = 0;
        piVar4[0x12] = 0;
        piVar4[0x13] = 0xf;
        *(undefined1 *)(piVar4 + 0xe) = 0;
        piVar11 = piVar4;
      }
      iVar3 = FUN_007300a0(&DAT_00c071fc);
      if (iVar3 == 0) {
LAB_005511be:
        local_1a4 = 0;
      }
      else {
        puVar5 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 == (undefined4 *)0x0) goto LAB_005511be;
        local_1a4 = FUN_008917b4(puVar5);
      }
      local_78 = 0xf;
      local_7c = 0;
      local_8c = local_8c & 0xffffff00;
      FUN_00402a70("Folder",6);
      local_8._0_1_ = 1;
      FUN_0072ecf0(&DAT_00bf2375);
      local_8._0_1_ = 3;
      if (0xf < local_78) {
        FUN_0089120c(local_8c);
      }
      local_7c = 0;
      local_8c = local_8c & 0xffffff00;
      local_44 = 0;
      local_54[0] = (char *******)((uint)local_54[0] & 0xffffff00);
      local_78 = 0xf;
      local_40 = 0xf;
      FUN_00402a70(&DAT_00c0d66c,4);
      local_8._0_1_ = 4;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_00402bb0(uVar6);
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      local_8._0_1_ = 3;
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = local_34[0] & 0xffffff00;
      if (0xf < local_40) {
        FUN_0089120c(local_54[0]);
      }
      local_40 = 0xf;
      local_44 = 0;
      local_54[0] = (char *******)((uint)local_54[0] & 0xffffff00);
      FUN_00402a70("Sound",5);
      local_8._0_1_ = 6;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,7);
      FUN_00402bb0(uVar6);
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      local_8._0_1_ = 3;
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = local_34[0] & 0xffffff00;
      if (0xf < local_40) {
        FUN_0089120c(local_54[0]);
      }
      local_5c = 0xf;
      local_60 = 0;
      local_70[0] = local_70[0] & 0xffffff00;
      FUN_00402a70("Effect/",7);
      local_8._0_1_ = 8;
      FUN_00401ed0(local_a8,0,0xffffffff);
      FUN_00403040(local_70,0,0xffffffff);
      local_1c0 = local_1a4;
      local_1bc = piVar11;
      uVar6 = FUN_0057ef20();
      iVar3 = local_1b8;
      FUN_0057e850(local_1b8 + 0x10,uVar6);
      local_24 = 0xf;
      local_28 = 0;
      local_38 = local_38 & 0xffffff00;
      FUN_00403040(piVar11,0,0xffffffff);
      local_1c = local_1a4;
      local_8 = CONCAT31(local_8._1_3_,9);
      uVar6 = FUN_00552de0(&local_38);
      FUN_00552980(iVar3 + 0x20,&local_1d0,uVar6);
      if (0xf < local_24) {
        FUN_0089120c(local_38);
      }
      for (piVar11 = (int *)local_1a8[0x10]; piVar11 != (int *)0x0; piVar11 = (int *)piVar11[0x10])
      {
        piVar4 = piVar11 + 8;
        if (0xf < (uint)piVar11[0xd]) {
          piVar4 = (int *)*piVar4;
        }
        iVar3 = __stricmp((char *)piVar4,"Effect");
        if (iVar3 == 0) goto LAB_00551445;
      }
      piVar11 = (int *)0x0;
LAB_00551445:
      local_1a8 = piVar11;
      if (0xf < local_5c) {
        FUN_0089120c(local_70[0]);
      }
      local_8 = local_8 & 0xffffff00;
      local_5c = 0xf;
      local_60 = 0;
      local_70[0] = local_70[0] & 0xffffff00;
      if (0xf < local_94) {
        FUN_0089120c(local_a8[0]);
      }
    }
    local_8 = 0xffffffff;
    local_128[0] = TiXmlDocument::vftable;
    if (0xf < local_c8) {
      FUN_0089120c(local_dc);
    }
    local_c8 = 0xf;
    local_cc = 0;
    local_dc = local_dc & 0xffffff00;
    FUN_0072e040();
    FUN_0072ee30(local_1a0);
    local_8 = 10;
    cVar1 = FUN_0072f110(0);
    if ((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("CategoryList"), iVar3 != 0)) {
      piVar11 = (int *)FUN_0072e2e0("Category");
      local_1bc = piVar11;
      while (piVar11 != (int *)0x0) {
        (**(code **)(*piVar11 + 0x14))();
        local_78 = 0xf;
        local_7c = 0;
        local_8c = local_8c & 0xffffff00;
        FUN_00402a70(&DAT_00c0f680,4);
        local_8._0_1_ = 0xb;
        FUN_0072ecf0(&DAT_00bf2375);
        local_8._0_1_ = 0xd;
        if (0xf < local_78) {
          FUN_0089120c(local_8c);
        }
        local_78 = 0xf;
        local_7c = 0;
        local_8c = local_8c & 0xffffff00;
        iVar3 = FUN_00891268(0x10);
        local_8._0_1_ = 0xe;
        if (iVar3 == 0) {
          local_1ac = 0;
        }
        else {
          *(undefined4 *)(iVar3 + 8) = 0;
          local_1ac = iVar3;
          iVar7 = FUN_00891268(0x18);
          if (iVar7 == 0) {
            local_1b0 = (char *)0x0;
            std::exception::exception((exception *)local_1dc,&local_1b0);
            local_1dc[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_1dc,&DAT_00c857a8);
          }
          *(int *)(iVar3 + 4) = iVar7;
          *(int *)iVar7 = iVar7;
          *(int *)(*(int *)(iVar3 + 4) + 4) = *(int *)(iVar3 + 4);
          *(int *)(*(int *)(iVar3 + 4) + 8) = *(int *)(iVar3 + 4);
          *(undefined1 *)(*(int *)(iVar3 + 4) + 0x14) = 1;
          *(undefined1 *)(*(int *)(iVar3 + 4) + 0x15) = 1;
          local_1ac = iVar3;
        }
        local_8._0_1_ = 0xd;
        piVar11 = (int *)FUN_0072e2e0("SubCategory");
        local_1b4 = piVar11;
        while (piVar11 != (int *)0x0) {
          iVar7 = (**(code **)(*local_1b4 + 0x14))();
          for (iVar3 = *(int *)(iVar7 + 0x94); iVar3 != iVar7 + 0x44; iVar3 = *(int *)(iVar3 + 0x50)
              ) {
            pcVar10 = (char *)(iVar3 + 0x14);
            if (0xf < *(uint *)(iVar3 + 0x28)) {
              pcVar10 = *(char **)pcVar10;
            }
            iVar8 = __stricmp(pcVar10,"idx");
            if (iVar8 == 0) {
              if (iVar3 != 0) {
                puVar5 = (undefined4 *)(iVar3 + 0x30);
                if (0xf < *(uint *)(iVar3 + 0x44)) {
                  puVar5 = (undefined4 *)*puVar5;
                }
                if (puVar5 != (undefined4 *)0x0) {
                  local_1b0 = (char *)FUN_008917b4(puVar5);
                  goto LAB_00551692;
                }
              }
              break;
            }
          }
          local_1b0 = (char *)0x0;
LAB_00551692:
          local_5c = 0xf;
          local_60 = 0;
          local_70[0] = local_70[0] & 0xffffff00;
          FUN_00402a70("IterationMethod",0xf);
          local_8._0_1_ = 0xf;
          FUN_0072ecf0(&DAT_00bf2375);
          local_8._0_1_ = 0x11;
          if (0xf < local_5c) {
            FUN_0089120c(local_70[0]);
          }
          local_5c = 0xf;
          local_60 = 0;
          local_70[0] = local_70[0] & 0xffffff00;
          iVar3 = FUN_00891268(0x14);
          local_8._0_1_ = 0x12;
          if (iVar3 == 0) {
            iVar3 = 0;
          }
          else {
            *(undefined4 *)(iVar3 + 8) = 0;
            local_1a4 = iVar3;
            iVar8 = FUN_00891268(0x18);
            if (iVar8 == 0) {
              local_1a8 = (int *)0x0;
              std::exception::exception((exception *)local_1e8,(char **)&local_1a8);
              local_1e8[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(local_1e8,&DAT_00c857a8);
            }
            *(int *)(iVar3 + 4) = iVar8;
            *(int *)iVar8 = iVar8;
            *(int *)(*(int *)(iVar3 + 4) + 4) = *(int *)(iVar3 + 4);
            *(int *)(*(int *)(iVar3 + 4) + 8) = *(int *)(iVar3 + 4);
            *(undefined1 *)(*(int *)(iVar3 + 4) + 0x14) = 1;
            *(undefined1 *)(*(int *)(iVar3 + 4) + 0x15) = 1;
          }
          local_8 = CONCAT31(local_8._1_3_,0x11);
          pppppppcVar9 = local_54[0];
          if (local_40 < 0x10) {
            pppppppcVar9 = (char *******)local_54;
          }
          local_1a4 = iVar3;
          iVar8 = __stricmp((char *)pppppppcVar9,"NotIteratable");
          if (iVar8 == 0) {
            *(undefined4 *)(iVar3 + 0x10) = 0;
          }
          else {
            pppppppcVar9 = local_54[0];
            if (local_40 < 0x10) {
              pppppppcVar9 = (char *******)local_54;
            }
            iVar8 = __stricmp((char *)pppppppcVar9,"Random");
            *(uint *)(iVar3 + 0x10) = (iVar8 != 0) + 1;
          }
          for (piVar11 = *(int **)(iVar7 + 0x18); piVar11 != (int *)0x0;
              piVar11 = (int *)piVar11[0x10]) {
            piVar4 = piVar11 + 8;
            if (0xf < (uint)piVar11[0xd]) {
              piVar4 = (int *)*piVar4;
            }
            iVar7 = __stricmp((char *)piVar4,"Effect");
            iVar3 = local_1ac;
            if (iVar7 == 0) goto joined_r0x005517f6;
          }
          piVar11 = (int *)0x0;
          iVar3 = local_1ac;
joined_r0x005517f6:
          local_1a8 = piVar11;
          local_1ac = iVar3;
          if (local_1a8 != (int *)0x0) {
            iVar7 = (**(code **)(*local_1a8 + 0x14))();
            for (iVar3 = *(int *)(iVar7 + 0x94); iVar3 != iVar7 + 0x44;
                iVar3 = *(int *)(iVar3 + 0x50)) {
              pcVar10 = (char *)(iVar3 + 0x14);
              if (0xf < *(uint *)(iVar3 + 0x28)) {
                pcVar10 = *(char **)pcVar10;
              }
              iVar8 = __stricmp(pcVar10,"idx");
              if (iVar8 == 0) {
                if (iVar3 != 0) {
                  puVar5 = (undefined4 *)(iVar3 + 0x30);
                  if (0xf < *(uint *)(iVar3 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    uVar6 = FUN_008917b4(puVar5);
                    goto LAB_00551849;
                  }
                }
                break;
              }
            }
            uVar6 = 0;
LAB_00551849:
            for (iVar3 = *(int *)(iVar7 + 0x94); iVar3 != iVar7 + 0x44;
                iVar3 = *(int *)(iVar3 + 0x50)) {
              pcVar10 = (char *)(iVar3 + 0x14);
              if (0xf < *(uint *)(iVar3 + 0x28)) {
                pcVar10 = *(char **)pcVar10;
              }
              iVar8 = __stricmp(pcVar10,"effectId");
              if (iVar8 == 0) {
                if (iVar3 != 0) {
                  puVar5 = (undefined4 *)(iVar3 + 0x30);
                  if (0xf < *(uint *)(iVar3 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    local_1cc = FUN_008917b4(puVar5);
                    goto LAB_0055187a;
                  }
                }
                break;
              }
            }
            local_1cc = 0;
LAB_0055187a:
            iVar3 = local_1a4;
            local_1d0 = uVar6;
            uVar6 = FUN_0057ef20();
            FUN_0057e850(iVar3,uVar6);
            for (piVar11 = (int *)local_1a8[0x10]; piVar11 != (int *)0x0;
                piVar11 = (int *)piVar11[0x10]) {
              piVar4 = piVar11 + 8;
              if (0xf < (uint)piVar11[0xd]) {
                piVar4 = (int *)*piVar4;
              }
              iVar7 = __stricmp((char *)piVar4,"Effect");
              iVar3 = local_1ac;
              if (iVar7 == 0) goto joined_r0x005517f6;
            }
            piVar11 = (int *)0x0;
            iVar3 = local_1ac;
            goto joined_r0x005517f6;
          }
          local_1c8 = local_1b0;
          local_1c4 = local_1a4;
          uVar6 = FUN_0057ef20();
          FUN_0057e850(iVar3,uVar6);
          for (piVar11 = (int *)local_1b4[0x10]; piVar11 != (int *)0x0;
              piVar11 = (int *)piVar11[0x10]) {
            piVar4 = piVar11 + 8;
            if (0xf < (uint)piVar11[0xd]) {
              piVar4 = (int *)*piVar4;
            }
            iVar3 = __stricmp((char *)piVar4,"SubCategory");
            if (iVar3 == 0) goto LAB_00551958;
          }
          piVar11 = (int *)0x0;
LAB_00551958:
          local_8._0_1_ = 0xd;
          local_1b4 = piVar11;
          if (0xf < local_40) {
            FUN_0089120c(local_54[0]);
          }
        }
        local_98 = 0xf;
        local_9c = 0;
        local_ac = local_ac & 0xffffff00;
        FUN_00403040(local_34,0,0xffffffff);
        iVar7 = local_1b8;
        local_90 = local_1ac;
        local_8 = CONCAT31(local_8._1_3_,0x13);
        iVar3 = **(int **)(local_1b8 + 0x34);
        iVar12 = local_1b8 + 0x30;
        iVar8 = FUN_00552ef0(iVar3,*(undefined4 *)(iVar3 + 4),&local_ac);
        if (*(int *)(iVar7 + 0x38) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("list<T> too long");
        }
        *(int *)(iVar7 + 0x38) = *(int *)(iVar7 + 0x38) + 1;
        *(int *)(iVar3 + 4) = iVar8;
        **(int **)(iVar8 + 4) = iVar8;
        FUN_00552b00(iVar12,local_1f8,**(int **)(iVar7 + 0x34) + 8,**(int **)(iVar7 + 0x34));
        if (0xf < local_98) {
          FUN_0089120c(local_ac);
        }
        local_98 = 0xf;
        local_9c = 0;
        local_ac = local_ac & 0xffffff00;
        piVar11 = (int *)FUN_0072e320("Category");
        local_8 = CONCAT31(local_8._1_3_,10);
        local_1bc = piVar11;
        if (0xf < local_20) {
          FUN_0089120c(local_34[0]);
        }
        local_20 = 0xf;
        local_24 = 0;
        local_34[0] = local_34[0] & 0xffffff00;
      }
    }
    local_8 = 0xffffffff;
    FUN_00407fb0();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


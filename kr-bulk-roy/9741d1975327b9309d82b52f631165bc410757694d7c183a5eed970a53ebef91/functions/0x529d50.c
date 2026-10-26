
void FUN_00529d50(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  undefined1 local_174 [76];
  undefined4 local_128 [15];
  undefined1 local_ec [20];
  undefined **local_d8 [17];
  char local_94;
  uint local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined1 local_5c;
  uint local_58;
  undefined4 local_48;
  uint local_44;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923833;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_d8);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_94 == '\0') && (iVar3 = FUN_0072e2e0("PRACTICEEXPLAIN"), iVar3 != 0)) {
    iVar3 = FUN_0072e360(uVar2);
    while (iVar3 != 0) {
      FUN_00529c30(local_128);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar3 = FUN_007300a0(&DAT_00bfb82c);
      if (iVar3 == 0) {
LAB_00529ea1:
        local_128[0] = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00529ea1;
        local_128[0] = FUN_008917b4(puVar4);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = local_34[0] & 0xffffff00;
      FUN_00402a70(&DAT_00c0ce30,4);
      local_8._0_1_ = 2;
      uVar5 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00440130(uVar5);
      if (0xf < local_44) {
        FUN_0089120c(local_58);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      local_44 = 0xf;
      local_48 = 0;
      local_58 = local_58 & 0xffffff00;
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      iVar3 = FUN_0072e360();
      if (((iVar3 != 0) && (*(int **)(iVar3 + 0x18) != (int *)0x0)) &&
         (iVar6 = (**(code **)(**(int **)(iVar3 + 0x18) + 0x30))(), iVar6 != 0)) {
        puVar4 = (undefined4 *)(iVar6 + 0x20);
        if (0xf < *(uint *)(iVar6 + 0x34)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 != (undefined4 *)0x0) {
          if ((*(int **)(iVar3 + 0x18) == (int *)0x0) ||
             (iVar3 = (**(code **)(**(int **)(iVar3 + 0x18) + 0x30))(), iVar3 == 0)) {
            pcVar9 = (char *)0x0;
          }
          else {
            pcVar9 = (char *)(iVar3 + 0x20);
            if (0xf < *(uint *)(iVar3 + 0x34)) {
              pcVar9 = *(char **)pcVar9;
            }
          }
          local_20 = 0xf;
          local_24 = 0;
          local_34[0] = local_34[0] & 0xffffff00;
          pcVar7 = pcVar9;
          do {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar9,(int)pcVar7 - (int)(pcVar9 + 1));
          local_8._0_1_ = 4;
          FUN_00440130(local_34);
          local_8 = CONCAT31(local_8._1_3_,1);
          if (0xf < local_20) {
            FUN_0089120c(local_34[0]);
          }
        }
      }
      iVar3 = FUN_0072e360();
      while (iVar3 != 0) {
        local_5c = 0;
        local_44 = 7;
        local_48 = 0;
        local_58 = local_58 & 0xffff0000;
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        local_8._0_1_ = 5;
        for (iVar6 = *(int *)(iVar3 + 0x94); iVar6 != iVar3 + 0x44; iVar6 = *(int *)(iVar6 + 0x50))
        {
          pcVar9 = (char *)(iVar6 + 0x14);
          if (0xf < *(uint *)(iVar6 + 0x28)) {
            pcVar9 = *(char **)pcVar9;
          }
          iVar8 = __stricmp(pcVar9,"ID");
          if (iVar8 == 0) {
            if (iVar6 != 0) {
              puVar4 = (undefined4 *)(iVar6 + 0x30);
              if (0xf < *(uint *)(iVar6 + 0x44)) {
                puVar4 = (undefined4 *)*puVar4;
              }
              if (puVar4 != (undefined4 *)0x0) {
                local_5c = FUN_008917b4(puVar4);
                goto LAB_0052a04c;
              }
            }
            break;
          }
        }
        local_5c = 0;
LAB_0052a04c:
        if ((*(int **)(iVar3 + 0x18) != (int *)0x0) &&
           (iVar6 = (**(code **)(**(int **)(iVar3 + 0x18) + 0x30))(), iVar6 != 0)) {
          puVar4 = (undefined4 *)(iVar6 + 0x20);
          if (0xf < *(uint *)(iVar6 + 0x34)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            if ((*(int **)(iVar3 + 0x18) == (int *)0x0) ||
               (iVar3 = (**(code **)(**(int **)(iVar3 + 0x18) + 0x30))(), iVar3 == 0)) {
              pcVar9 = (char *)0x0;
            }
            else {
              pcVar9 = (char *)(iVar3 + 0x20);
              if (0xf < *(uint *)(iVar3 + 0x34)) {
                pcVar9 = *(char **)pcVar9;
              }
            }
            local_20 = 0xf;
            local_24 = 0;
            local_34[0] = local_34[0] & 0xffffff00;
            pcVar7 = pcVar9;
            do {
              cVar1 = *pcVar7;
              pcVar7 = pcVar7 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(pcVar9,(int)pcVar7 - (int)(pcVar9 + 1));
            local_8._0_1_ = 6;
            FUN_00440130(local_34);
            local_8._0_1_ = 5;
            if (0xf < local_20) {
              FUN_0089120c(local_34[0]);
            }
          }
        }
        FUN_0052ace0();
        local_8 = CONCAT31(local_8._1_3_,7);
        uVar5 = FUN_0052b5d0(local_ec);
        FUN_0052ad50(local_ec,uVar5);
        if (7 < local_20) {
          FUN_0089120c(local_34[0]);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        if (7 < local_44) {
          FUN_0089120c(local_58);
        }
        iVar3 = FUN_0072e3c0();
      }
      uVar5 = FUN_0052ad20(local_128);
      local_8._0_1_ = 8;
      uVar5 = FUN_0052b240(uVar5);
      FUN_0052ae20(param_1,uVar5);
      local_8._0_1_ = 1;
      FUN_0052a270(local_174);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0052a270(local_128);
      iVar3 = FUN_0072e3c0();
    }
    local_8 = 0xffffffff;
    local_d8[0] = TiXmlDocument::vftable;
    if (0xf < local_78) {
      FUN_0089120c(local_8c);
    }
    local_78 = 0xf;
    local_7c = 0;
    local_8c = local_8c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_d8[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_78) {
      local_8 = 0xffffffff;
      local_d8[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_8c);
    }
    local_78 = 0xf;
    local_7c = 0;
    local_8c = local_8c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


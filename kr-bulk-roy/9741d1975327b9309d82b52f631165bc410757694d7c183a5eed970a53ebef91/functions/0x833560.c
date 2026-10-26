
void FUN_00833560(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined **local_80 [4];
  char *local_70;
  undefined4 local_6c;
  undefined1 local_68 [4];
  undefined4 *local_64;
  undefined4 local_60;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int *local_48;
  int local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 *local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 *local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090beb2;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6c = param_1;
  local_14 = uVar1;
  if (param_2 != 0) {
    local_3c = FUN_0072e360(uVar1);
    iVar3 = local_3c;
    while (iVar3 != 0) {
      local_60 = 0;
      puVar2 = (undefined4 *)FUN_00891268(0x28);
      if (puVar2 == (undefined4 *)0x0) {
        local_70 = (char *)0x0;
        std::exception::exception((exception *)local_80,&local_70);
        local_80[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_80,&DAT_00c857a8);
      }
      *puVar2 = puVar2;
      puVar2[1] = puVar2;
      puVar2[2] = puVar2;
      *(undefined1 *)(puVar2 + 9) = 1;
      *(undefined1 *)((int)puVar2 + 0x25) = 1;
      local_8 = 0;
      local_64 = puVar2;
      local_30 = FUN_0072e360(uVar1);
      iVar3 = FUN_007300a0(&DAT_00bed1d0);
      if (iVar3 == 0) {
LAB_0083362a:
        local_48 = (int *)0x0;
      }
      else {
        puVar2 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) goto LAB_0083362a;
        local_48 = (int *)FUN_008917b4(puVar2);
      }
      local_50 = 0;
      local_54 = 0;
      local_4c = 0;
      local_40 = local_48;
      iVar4 = local_54;
      iVar3 = local_58;
      iVar5 = local_30;
      while (local_58 = iVar4, local_54 = local_58, local_30 = iVar5, iVar5 != 0) {
        iVar4 = *(int *)(iVar5 + 0x94);
        iVar9 = iVar5 + 0x44;
        local_28 = 0;
        local_24 = (undefined4 *)0x0;
        local_20 = 0;
        local_1c = 0;
        local_18 = 0;
        for (; local_58 = iVar3, iVar4 != iVar9; iVar4 = *(int *)(iVar4 + 0x50)) {
          pcVar6 = (char *)(iVar4 + 0x14);
          if (0xf < *(uint *)(iVar4 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar3 = __stricmp(pcVar6,"Level");
          if (iVar3 == 0) {
            if (iVar4 != 0) {
              puVar2 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar2 = (undefined4 *)*puVar2;
              }
              if (puVar2 != (undefined4 *)0x0) {
                local_44 = FUN_008917b4(puVar2);
                goto LAB_00833694;
              }
            }
            break;
          }
          iVar3 = local_58;
        }
        local_44 = 0;
LAB_00833694:
        iVar3 = local_44;
        if (local_4c + 1 != local_44) {
          FID_conflict__wprintf
                    ("EnchantRatioTable: Enchant Ratio List doesn\'t sorted or missed. SetID %d\n",
                     local_40);
        }
        local_4c = iVar3;
        for (iVar4 = *(int *)(iVar5 + 0x94); iVar4 != iVar9; iVar4 = *(int *)(iVar4 + 0x50)) {
          pcVar6 = (char *)(iVar4 + 0x14);
          if (0xf < *(uint *)(iVar4 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar3 = __stricmp(pcVar6,"SuccessRatio");
          if (iVar3 == 0) {
            if (iVar4 != 0) {
              puVar2 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar2 = (undefined4 *)*puVar2;
              }
              if (puVar2 != (undefined4 *)0x0) {
                local_34 = FUN_008917b4(puVar2);
                goto LAB_008336e5;
              }
            }
            break;
          }
        }
        local_34 = 0;
LAB_008336e5:
        for (iVar3 = *(int *)(iVar5 + 0x94); iVar3 != iVar9; iVar3 = *(int *)(iVar3 + 0x50)) {
          pcVar6 = (char *)(iVar3 + 0x14);
          if (0xf < *(uint *)(iVar3 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar4 = __stricmp(pcVar6,"FailRatio");
          if (iVar4 == 0) {
            if (iVar3 != 0) {
              puVar2 = (undefined4 *)(iVar3 + 0x30);
              if (0xf < *(uint *)(iVar3 + 0x44)) {
                puVar2 = (undefined4 *)*puVar2;
              }
              if (puVar2 != (undefined4 *)0x0) {
                local_38 = (undefined4 *)FUN_008917b4(puVar2);
                goto LAB_0083371e;
              }
            }
            break;
          }
        }
        local_38 = (undefined4 *)0x0;
LAB_0083371e:
        for (iVar3 = *(int *)(iVar5 + 0x94); iVar3 != iVar9; iVar3 = *(int *)(iVar3 + 0x50)) {
          pcVar6 = (char *)(iVar3 + 0x14);
          if (0xf < *(uint *)(iVar3 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar5 = __stricmp(pcVar6,"LeveldownRatio");
          if (iVar5 == 0) {
            if (iVar3 != 0) {
              puVar2 = (undefined4 *)(iVar3 + 0x30);
              if (0xf < *(uint *)(iVar3 + 0x44)) {
                puVar2 = (undefined4 *)*puVar2;
              }
              if (puVar2 != (undefined4 *)0x0) {
                iVar3 = FUN_008917b4(puVar2);
                goto LAB_0083374e;
              }
            }
            break;
          }
        }
        iVar3 = 0;
LAB_0083374e:
        iVar4 = local_30 + 0x44;
        for (iVar5 = *(int *)(local_30 + 0x94); iVar5 != iVar4; iVar5 = *(int *)(iVar5 + 0x50)) {
          pcVar6 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar9 = __stricmp(pcVar6,"ResetRatio");
          if (iVar9 == 0) {
            if (iVar5 != 0) {
              puVar2 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar2 = (undefined4 *)*puVar2;
              }
              if (puVar2 != (undefined4 *)0x0) {
                iVar5 = FUN_008917b4(puVar2);
                goto LAB_0083378a;
              }
            }
            break;
          }
        }
        iVar5 = 0;
LAB_0083378a:
        iVar4 = *(int *)(local_30 + 0x94);
        if (iVar4 != local_30 + 0x44) {
          do {
            pcVar6 = (char *)(iVar4 + 0x14);
            if (0xf < *(uint *)(iVar4 + 0x28)) {
              pcVar6 = *(char **)pcVar6;
            }
            iVar9 = __stricmp(pcVar6,"BreakRatio");
            if (iVar9 == 0) {
              if (iVar4 != 0) {
                puVar2 = (undefined4 *)(iVar4 + 0x30);
                if (0xf < *(uint *)(iVar4 + 0x44)) {
                  puVar2 = (undefined4 *)*puVar2;
                }
                if (puVar2 != (undefined4 *)0x0) {
                  iVar4 = FUN_008917b4(puVar2);
                  goto LAB_008337d0;
                }
              }
              break;
            }
            iVar4 = *(int *)(iVar4 + 0x50);
          } while (iVar4 != local_30 + 0x44);
        }
        iVar4 = 0;
LAB_008337d0:
        if (local_50 == 0) {
          if (iVar4 == 0) {
            local_54 = local_44;
          }
          else {
            local_50 = 1;
          }
        }
        if ((int)local_38 + local_34 + iVar4 + iVar5 + iVar3 != 100000) {
          FID_conflict__wprintf
                    ("EnchantRatioTable: [SetID %d] Sum of probability is Not 100000\n",local_40);
        }
        local_24 = local_38;
        local_2c = local_44;
        local_28 = local_34;
        local_20 = iVar3;
        local_1c = iVar5;
        local_18 = iVar4;
        uVar7 = FUN_0052e860();
        FUN_00834230(local_68,uVar7);
        iVar5 = FUN_0072e3c0();
        iVar4 = local_54;
        iVar3 = local_58;
      }
      uVar8 = FUN_00834200(local_68);
      uVar7 = local_6c;
      local_8._0_1_ = 1;
      uVar8 = FUN_008345e0(uVar8);
      FUN_00834300(uVar7,uVar8);
      local_48 = &local_28;
      local_8._0_1_ = 2;
      FUN_00833ad0(*local_24,local_24);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0089120c(local_24);
      iVar3 = FUN_0072e3c0();
      local_8 = 3;
      local_3c = iVar3;
      FUN_00833ad0(*local_64,local_64);
      local_8 = 0xffffffff;
      FUN_0089120c(local_64);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


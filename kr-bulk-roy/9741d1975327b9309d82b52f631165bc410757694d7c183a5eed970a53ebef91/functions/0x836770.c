
void FUN_00836770(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 local_e8 [8];
  undefined1 local_e0 [8];
  undefined **local_d8 [5];
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  undefined4 local_9c;
  char *local_98;
  int local_94;
  undefined1 local_90 [4];
  undefined4 *local_8c;
  undefined4 local_88;
  undefined4 local_80;
  int local_7c;
  undefined4 *local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_50;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 *local_20;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090bdc8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_9c = param_1;
  local_14 = uVar2;
  if (param_2 != 0) {
    local_74 = FUN_0072e360(uVar2);
    iVar3 = local_74;
    while (iVar3 != 0) {
      iVar3 = FUN_007300a0(&DAT_00bed1d0);
      if (iVar3 == 0) {
LAB_00836800:
        local_80 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00836800;
        local_80 = FUN_008917b4(puVar4);
      }
      local_78 = (undefined4 *)local_80;
      iVar3 = FUN_0072e360(uVar2);
      local_88 = 0;
      local_70 = iVar3;
      puVar4 = (undefined4 *)FUN_00891268(0x3c);
      if (puVar4 == (undefined4 *)0x0) {
        local_98 = (char *)0x0;
        std::exception::exception((exception *)local_d8,&local_98);
        local_d8[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_d8,&DAT_00c857a8);
      }
      *puVar4 = puVar4;
      puVar4[1] = puVar4;
      puVar4[2] = puVar4;
      *(undefined1 *)(puVar4 + 0xe) = 1;
      *(undefined1 *)((int)puVar4 + 0x39) = 1;
      local_8 = 0;
      local_8c = puVar4;
      iVar1 = local_70;
      while (local_70 = iVar1, iVar3 != 0) {
        local_3c = 0;
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        local_2c = 0;
        local_28 = 0;
        local_24 = 0;
        local_20 = (undefined4 *)0x0;
        iVar8 = iVar1 + 0x44;
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        local_8 = CONCAT31(local_8._1_3_,1);
        iVar3 = *(int *)(iVar1 + 0x94);
        local_18 = 0;
        for (; iVar3 != iVar8; iVar3 = *(int *)(iVar3 + 0x50)) {
          pcVar6 = (char *)(iVar3 + 0x14);
          if (0xf < *(uint *)(iVar3 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar5 = __stricmp(pcVar6,"Level");
          if (iVar5 == 0) {
            if (iVar3 != 0) {
              puVar4 = (undefined4 *)(iVar3 + 0x30);
              if (0xf < *(uint *)(iVar3 + 0x44)) {
                puVar4 = (undefined4 *)*puVar4;
              }
              if (puVar4 != (undefined4 *)0x0) {
                local_a0 = FUN_008917b4(puVar4);
                goto LAB_008368ca;
              }
            }
            break;
          }
        }
        local_a0 = 0;
LAB_008368ca:
        if (0 < local_a0) {
          local_18 = local_a0;
        }
        for (iVar3 = *(int *)(iVar1 + 0x94); iVar3 != iVar8; iVar3 = *(int *)(iVar3 + 0x50)) {
          pcVar6 = (char *)(iVar3 + 0x14);
          if (0xf < *(uint *)(iVar3 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar5 = __stricmp(pcVar6,"SuccessRatio");
          if (iVar5 == 0) {
            if (iVar3 != 0) {
              puVar4 = (undefined4 *)(iVar3 + 0x30);
              if (0xf < *(uint *)(iVar3 + 0x44)) {
                puVar4 = (undefined4 *)*puVar4;
              }
              if (puVar4 != (undefined4 *)0x0) {
                local_6c = FUN_008917b4(puVar4);
                goto LAB_00836909;
              }
            }
            break;
          }
        }
        local_6c = 0;
LAB_00836909:
        local_3c = local_6c;
        for (iVar3 = *(int *)(iVar1 + 0x94); iVar3 != iVar8; iVar3 = *(int *)(iVar3 + 0x50)) {
          pcVar6 = (char *)(iVar3 + 0x14);
          if (0xf < *(uint *)(iVar3 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar5 = __stricmp(pcVar6,"FailRatio");
          if (iVar5 == 0) {
            if (iVar3 != 0) {
              puVar4 = (undefined4 *)(iVar3 + 0x30);
              if (0xf < *(uint *)(iVar3 + 0x44)) {
                puVar4 = (undefined4 *)*puVar4;
              }
              if (puVar4 != (undefined4 *)0x0) {
                local_94 = FUN_008917b4(puVar4);
                goto LAB_0083693f;
              }
            }
            break;
          }
        }
        local_94 = 0;
LAB_0083693f:
        local_38 = local_94;
        for (iVar3 = *(int *)(iVar1 + 0x94); iVar3 != iVar8; iVar3 = *(int *)(iVar3 + 0x50)) {
          pcVar6 = (char *)(iVar3 + 0x14);
          if (0xf < *(uint *)(iVar3 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar5 = __stricmp(pcVar6,"LeveldownRatio");
          if (iVar5 == 0) {
            if (iVar3 != 0) {
              puVar4 = (undefined4 *)(iVar3 + 0x30);
              if (0xf < *(uint *)(iVar3 + 0x44)) {
                puVar4 = (undefined4 *)*puVar4;
              }
              if (puVar4 != (undefined4 *)0x0) {
                local_7c = FUN_008917b4(puVar4);
                goto LAB_00836979;
              }
            }
            break;
          }
        }
        local_7c = 0;
LAB_00836979:
        local_34 = local_7c;
        for (iVar3 = *(int *)(iVar1 + 0x94); iVar3 != iVar8; iVar3 = *(int *)(iVar3 + 0x50)) {
          pcVar6 = (char *)(iVar3 + 0x14);
          if (0xf < *(uint *)(iVar3 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar5 = __stricmp(pcVar6,"ResetRatio");
          if (iVar5 == 0) {
            if (iVar3 != 0) {
              puVar4 = (undefined4 *)(iVar3 + 0x30);
              if (0xf < *(uint *)(iVar3 + 0x44)) {
                puVar4 = (undefined4 *)*puVar4;
              }
              if (puVar4 != (undefined4 *)0x0) {
                iVar3 = FUN_008917b4(puVar4);
                goto LAB_008369af;
              }
            }
            break;
          }
        }
        iVar3 = 0;
LAB_008369af:
        local_30 = iVar3;
        for (iVar1 = *(int *)(iVar1 + 0x94); iVar1 != iVar8; iVar1 = *(int *)(iVar1 + 0x50)) {
          pcVar6 = (char *)(iVar1 + 0x14);
          if (0xf < *(uint *)(iVar1 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar5 = __stricmp(pcVar6,"BreakRatio");
          if (iVar5 == 0) {
            if (iVar1 != 0) {
              puVar4 = (undefined4 *)(iVar1 + 0x30);
              if (0xf < *(uint *)(iVar1 + 0x44)) {
                puVar4 = (undefined4 *)*puVar4;
              }
              if (puVar4 != (undefined4 *)0x0) {
                local_2c = FUN_008917b4(puVar4);
                goto LAB_008369ea;
              }
            }
            break;
          }
        }
        local_2c = 0;
LAB_008369ea:
        if (local_2c + iVar3 + local_7c + local_94 + local_6c != 0) {
          FID_conflict__wprintf
                    ("EnchantAssistanceTable: [SetID %d] Sum of probability is Not Zero\n",local_80)
          ;
        }
        iVar3 = FUN_0072e360();
        while (iVar3 != 0) {
          for (iVar1 = *(int *)(iVar3 + 0x94); iVar1 != iVar3 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar6 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar6 = *(char **)pcVar6;
            }
            iVar8 = __stricmp(pcVar6,"id");
            if (iVar8 == 0) {
              if (iVar1 != 0) {
                puVar4 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                if (puVar4 != (undefined4 *)0x0) {
                  local_a8 = FUN_008917b4(puVar4);
                  goto LAB_00836a5c;
                }
              }
              break;
            }
          }
          local_a8 = 0;
LAB_00836a5c:
          for (iVar1 = *(int *)(iVar3 + 0x94); iVar1 != iVar3 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar6 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar6 = *(char **)pcVar6;
            }
            iVar8 = __stricmp(pcVar6,"qty");
            if (iVar8 == 0) {
              if (iVar1 != 0) {
                puVar4 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                if (puVar4 != (undefined4 *)0x0) {
                  local_a4 = FUN_008917b4(puVar4);
                  goto LAB_00836a9a;
                }
              }
              break;
            }
          }
          local_a4 = 0;
LAB_00836a9a:
          local_ac = 1;
          FUN_0052ef90();
          iVar3 = FUN_0072e3c0();
        }
        iVar3 = FUN_0072e360();
        local_6c = iVar3;
        if (iVar3 != 0) {
          do {
            for (iVar1 = *(int *)(iVar3 + 0x94); iVar1 != iVar3 + 0x44;
                iVar1 = *(int *)(iVar1 + 0x50)) {
              pcVar6 = (char *)(iVar1 + 0x14);
              if (0xf < *(uint *)(iVar1 + 0x28)) {
                pcVar6 = *(char **)pcVar6;
              }
              iVar8 = __stricmp(pcVar6,"id");
              if (iVar8 == 0) {
                if (iVar1 != 0) {
                  puVar4 = (undefined4 *)(iVar1 + 0x30);
                  if (0xf < *(uint *)(iVar1 + 0x44)) {
                    puVar4 = (undefined4 *)*puVar4;
                  }
                  if (puVar4 != (undefined4 *)0x0) {
                    local_b4 = FUN_008917b4(puVar4);
                    goto LAB_00836b2a;
                  }
                }
                break;
              }
            }
            local_b4 = 0;
LAB_00836b2a:
            for (iVar1 = *(int *)(iVar3 + 0x94); iVar1 != iVar3 + 0x44;
                iVar1 = *(int *)(iVar1 + 0x50)) {
              pcVar6 = (char *)(iVar1 + 0x14);
              if (0xf < *(uint *)(iVar1 + 0x28)) {
                pcVar6 = *(char **)pcVar6;
              }
              iVar8 = __stricmp(pcVar6,"qty");
              if (iVar8 == 0) {
                if (iVar1 != 0) {
                  puVar4 = (undefined4 *)(iVar1 + 0x30);
                  if (0xf < *(uint *)(iVar1 + 0x44)) {
                    puVar4 = (undefined4 *)*puVar4;
                  }
                  if (puVar4 != (undefined4 *)0x0) {
                    local_b0 = FUN_008917b4(puVar4);
                    goto LAB_00836b61;
                  }
                }
                break;
              }
            }
            local_b0 = 0;
LAB_00836b61:
            local_b8 = 2;
            FUN_0052ef90();
            iVar3 = FUN_0072e3c0();
          } while (iVar3 != 0);
          local_6c = 0;
        }
        iVar3 = FUN_0072e360();
        if (iVar3 != 0) {
          local_6c = local_6c + 0x44;
          do {
            iVar1 = local_6c;
            iVar3 = *(int *)(local_6c + 0x50);
            local_c0 = 0;
            for (; iVar3 != iVar1; iVar3 = *(int *)(iVar3 + 0x50)) {
              pcVar6 = (char *)(iVar3 + 0x14);
              if (0xf < *(uint *)(iVar3 + 0x28)) {
                pcVar6 = *(char **)pcVar6;
              }
              iVar8 = __stricmp(pcVar6,"amount");
              if (iVar8 == 0) {
                if (iVar3 != 0) {
                  puVar4 = (undefined4 *)(iVar3 + 0x30);
                  if (0xf < *(uint *)(iVar3 + 0x44)) {
                    puVar4 = (undefined4 *)*puVar4;
                  }
                  if (puVar4 != (undefined4 *)0x0) {
                    local_bc = FUN_008917b4(puVar4);
                    goto LAB_00836bfe;
                  }
                }
                break;
              }
            }
            local_bc = 0;
LAB_00836bfe:
            local_c4 = 0;
            FUN_0052ef90();
            iVar3 = FUN_0072e3c0();
          } while (iVar3 != 0);
        }
        uVar7 = FUN_00837200();
        local_8._0_1_ = 2;
        FUN_00837820(uVar7);
        FUN_00837370(local_90,local_e0);
        local_8._0_1_ = 1;
        if (local_50 != 0) {
          FUN_0089120c(local_50);
        }
        iVar3 = FUN_0072e3c0();
        local_8 = (uint)local_8._1_3_ << 8;
        iVar1 = iVar3;
        if (local_28 != 0) {
          local_70 = iVar3;
          FUN_0089120c(local_28);
          iVar1 = local_70;
        }
      }
      uVar7 = FUN_00837250();
      local_8._0_1_ = 3;
      uVar7 = FUN_008378f0(uVar7);
      FUN_00837270(local_e8,uVar7);
      local_78 = &local_24;
      local_8._0_1_ = 4;
      FUN_00832660(*local_20,local_20);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0089120c(local_20);
      iVar3 = FUN_0072e3c0();
      local_8 = 5;
      local_74 = iVar3;
      FUN_00832660(*local_8c,local_8c);
      local_8 = 0xffffffff;
      FUN_0089120c(local_8c);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


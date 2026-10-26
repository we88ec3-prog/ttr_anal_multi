
undefined4 FUN_008357c0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *local_64;
  undefined1 local_58 [4];
  undefined4 *local_54;
  undefined4 local_50;
  undefined **local_48 [9];
  char *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090be42;
  local_10 = ExceptionList;
  if (param_2 == 0) {
    return 0;
  }
  ExceptionList = &local_10;
  local_14 = FUN_0072e360(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar3 = local_14;
  do {
    if (iVar3 == 0) {
      ExceptionList = local_10;
      return 1;
    }
    iVar7 = local_14 + 0x44;
    for (iVar3 = *(int *)(local_14 + 0x94); iVar3 != iVar7; iVar3 = *(int *)(iVar3 + 0x50)) {
      pcVar5 = (char *)(iVar3 + 0x14);
      if (0xf < *(uint *)(iVar3 + 0x28)) {
        pcVar5 = *(char **)pcVar5;
      }
      iVar1 = __stricmp(pcVar5,"id");
      if (iVar1 == 0) {
        if (iVar3 != 0) {
          puVar2 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar2 = (undefined4 *)*puVar2;
          }
          if (puVar2 != (undefined4 *)0x0) {
            local_20 = FUN_008917b4(puVar2);
            goto LAB_00835860;
          }
        }
        break;
      }
    }
    local_20 = 0;
LAB_00835860:
    local_50 = 0;
    puVar2 = (undefined4 *)FUN_00891268(0x24);
    if (puVar2 == (undefined4 *)0x0) {
      local_24 = (char *)0x0;
      std::exception::exception((exception *)local_48,&local_24);
      local_48[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_48,&DAT_00c857a8);
    }
    *puVar2 = puVar2;
    puVar2[1] = puVar2;
    puVar2[2] = puVar2;
    *(undefined1 *)(puVar2 + 8) = 1;
    *(undefined1 *)((int)puVar2 + 0x21) = 1;
    local_8 = 0;
    local_54 = puVar2;
    iVar3 = FUN_0072e360();
    while (iVar3 != 0) {
      iVar1 = iVar3 + 0x44;
      for (iVar7 = *(int *)(iVar3 + 0x94); iVar7 != iVar1; iVar7 = *(int *)(iVar7 + 0x50)) {
        pcVar5 = (char *)(iVar7 + 0x14);
        if (0xf < *(uint *)(iVar7 + 0x28)) {
          pcVar5 = *(char **)pcVar5;
        }
        iVar4 = __stricmp(pcVar5,"rank");
        if (iVar4 == 0) {
          if (iVar7 != 0) {
            puVar2 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar2 = (undefined4 *)*puVar2;
            }
            if (puVar2 != (undefined4 *)0x0) {
              local_18 = FUN_008917b4(puVar2);
              goto LAB_008358f5;
            }
          }
          break;
        }
      }
      local_18 = 0;
LAB_008358f5:
      for (iVar7 = *(int *)(iVar3 + 0x94); iVar7 != iVar1; iVar7 = *(int *)(iVar7 + 0x50)) {
        pcVar5 = (char *)(iVar7 + 0x14);
        if (0xf < *(uint *)(iVar7 + 0x28)) {
          pcVar5 = *(char **)pcVar5;
        }
        iVar4 = __stricmp(pcVar5,"RatioID");
        if (iVar4 == 0) {
          if (iVar7 != 0) {
            puVar2 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar2 = (undefined4 *)*puVar2;
            }
            if (puVar2 != (undefined4 *)0x0) {
              local_1c = FUN_008917b4(puVar2);
              goto LAB_0083592e;
            }
          }
          break;
        }
      }
      local_1c = 0;
LAB_0083592e:
      for (iVar7 = *(int *)(iVar3 + 0x94); iVar7 != iVar1; iVar7 = *(int *)(iVar7 + 0x50)) {
        pcVar5 = (char *)(iVar7 + 0x14);
        if (0xf < *(uint *)(iVar7 + 0x28)) {
          pcVar5 = *(char **)pcVar5;
        }
        iVar4 = __stricmp(pcVar5,"SafetyID");
        if (iVar4 == 0) {
          if (iVar7 != 0) {
            puVar2 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar2 = (undefined4 *)*puVar2;
            }
            if (puVar2 != (undefined4 *)0x0) {
              local_64 = (undefined4 *)FUN_008917b4(puVar2);
              goto LAB_0083595e;
            }
          }
          break;
        }
      }
      local_64 = (undefined4 *)0x0;
LAB_0083595e:
      for (iVar7 = *(int *)(iVar3 + 0x94); iVar7 != iVar3 + 0x44; iVar7 = *(int *)(iVar7 + 0x50)) {
        pcVar5 = (char *)(iVar7 + 0x14);
        if (0xf < *(uint *)(iVar7 + 0x28)) {
          pcVar5 = *(char **)pcVar5;
        }
        iVar1 = __stricmp(pcVar5,"RequirementID");
        if (iVar1 == 0) {
          if (iVar7 != 0) {
            puVar2 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar2 = (undefined4 *)*puVar2;
            }
            if (puVar2 != (undefined4 *)0x0) {
              FUN_008917b4(puVar2);
            }
          }
          break;
        }
      }
      iVar7 = *(int *)(iVar3 + 0x94);
      if (iVar7 != iVar3 + 0x44) {
        do {
          pcVar5 = (char *)(iVar7 + 0x14);
          if (0xf < *(uint *)(iVar7 + 0x28)) {
            pcVar5 = *(char **)pcVar5;
          }
          iVar1 = __stricmp(pcVar5,"AssistanceID");
          if (iVar1 == 0) {
            if (iVar7 != 0) {
              puVar2 = (undefined4 *)(iVar7 + 0x30);
              if (0xf < *(uint *)(iVar7 + 0x44)) {
                puVar2 = (undefined4 *)*puVar2;
              }
              if (puVar2 != (undefined4 *)0x0) {
                FUN_008917b4(puVar2);
              }
            }
            break;
          }
          iVar7 = *(int *)(iVar7 + 0x50);
        } while (iVar7 != iVar3 + 0x44);
      }
      uVar6 = FUN_0054f7d0();
      FUN_00836230(local_58,uVar6);
      iVar3 = FUN_0072e3c0();
    }
    uVar6 = FUN_00836110();
    local_8._0_1_ = 1;
    uVar6 = FUN_008364e0(uVar6);
    FUN_00836130(param_1,uVar6);
    local_8._0_1_ = 2;
    FUN_006d7120(*local_64,local_64);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0089120c(local_64);
    iVar3 = FUN_0072e3c0();
    local_8 = 3;
    local_14 = iVar3;
    FUN_006d7120(*local_54,local_54);
    local_8 = 0xffffffff;
    FUN_0089120c(local_54);
  } while( true );
}


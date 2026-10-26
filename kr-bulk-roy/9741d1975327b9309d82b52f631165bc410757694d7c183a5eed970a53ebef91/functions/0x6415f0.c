
/* WARNING: Type propagation algorithm not settling */

void FUN_006415f0(void)

{
  short sVar1;
  undefined4 *puVar2;
  short *psVar3;
  short *psVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  short *******pppppppsVar7;
  int iVar8;
  short *******pppppppsVar9;
  int iVar10;
  undefined1 auStack_9c [24];
  int local_84;
  uint local_80;
  undefined4 uStack_70;
  uint local_6c;
  undefined4 local_64;
  undefined4 local_54;
  uint local_50;
  undefined4 *local_48;
  undefined4 *local_44;
  undefined4 local_40;
  short *******apppppppsStack_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093da39;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_9c;
  ExceptionList = &local_14;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c = 0;
    FUN_0058d410(DAT_00d61f20 ^ (uint)&stack0xffffff58);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_c = 0xffffffff;
  FUN_00590230();
  local_c = 1;
  FUN_0058ec10(&DAT_00faaf80,L"ChatMode");
  if (7 < local_6c) {
    FUN_0089120c(local_80);
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = (uint)local_64._2_2_ << 0x10;
  local_48 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_40 = 0;
  local_c._1_3_ = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 3;
    local_c._1_3_ = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c._0_1_ = 2;
  psVar3 = &DAT_00f938f2;
  do {
    psVar4 = psVar3;
    psVar3 = psVar4 + 1;
  } while (*psVar4 != 0);
  FUN_00402160(&DAT_00f938f2,(int)(psVar4 + -0x7c9c79) >> 1);
  iVar10 = 0;
  do {
    uStack_24 = 7;
    uStack_28 = 0;
    apppppppsStack_38[0] = (short *******)((uint)apppppppsStack_38[0] & 0xffff0000);
    FUN_00402160(&DAT_00bed1fc,0);
    local_c._0_1_ = 4;
    iVar8 = *(int *)(*(int *)(local_84 + 0x134) + 0x24c);
    if ((iVar8 == 0) || (iVar8 = *(int *)(iVar8 + 0xcc), iVar8 == 0)) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2;
    }
    if (iVar10 < iVar8) {
      FUN_0075cc10();
      local_c._0_1_ = 5;
      iVar8 = FUN_0044df20(0,&DAT_00bed1fc,0);
      local_c._0_1_ = 4;
      if (7 < local_6c) {
        FUN_0089120c(local_80);
      }
      if (iVar8 != 0) {
        uVar5 = FUN_0075cc10();
        local_c._0_1_ = 6;
        FUN_00402800(uVar5);
        local_c._0_1_ = 4;
        if (7 < local_6c) {
          FUN_0089120c(local_80);
        }
      }
    }
    iVar10 = iVar10 + 1;
    puVar6 = (undefined4 *)FUN_004068f0();
    if (7 < (uint)puVar6[5]) {
      puVar6 = (undefined4 *)*puVar6;
    }
    if ((DAT_00faaf7c & 1) == 0) {
      DAT_00faaf7c = DAT_00faaf7c | 1;
      local_c._0_1_ = 8;
      FUN_0058d410();
      _atexit((_func_4879 *)&LAB_00bccdc0);
    }
    local_c._0_1_ = 7;
    FUN_0058ec10(&DAT_00faaf80,puVar6);
    local_c._0_1_ = 4;
    if (7 < local_6c) {
      FUN_0089120c(local_80);
    }
    pppppppsVar9 = apppppppsStack_38[0];
    if (uStack_24 < 8) {
      pppppppsVar9 = (short *******)apppppppsStack_38;
    }
    local_80 = local_80 & 0xffff0000;
    local_6c = 7;
    uStack_70 = 0;
    pppppppsVar7 = pppppppsVar9;
    do {
      sVar1 = *(short *)pppppppsVar7;
      pppppppsVar7 = (short *******)((int)pppppppsVar7 + 2);
    } while (sVar1 != 0);
    FUN_00402160(pppppppsVar9,(int)pppppppsVar7 - (int)((int)pppppppsVar9 + 2) >> 1);
    local_c = CONCAT31(local_c._1_3_,9);
    FUN_0049c120();
    if (7 < local_6c) {
      FUN_0089120c(local_80);
    }
    local_c._0_1_ = 2;
    if (7 < uStack_24) {
      FUN_0089120c(apppppppsStack_38[0]);
    }
  } while (iVar10 < 10);
  FUN_00582d00();
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 10;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 2;
  }
  FUN_0040ef80();
  local_c._0_1_ = 0xb;
  FUN_0058ec10(&DAT_00faaf80,L"ResizedWidth");
  local_c._0_1_ = 2;
  if (7 < local_6c) {
    FUN_0089120c(local_80);
  }
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 0xc;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 2;
  }
  FUN_0040ef80();
  local_c = CONCAT31(local_c._1_3_,0xd);
  FUN_0058ec10(&DAT_00faaf80,L"ResizedHeight");
  if (7 < local_6c) {
    FUN_0089120c(local_80);
  }
  puVar6 = local_44;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  puVar2 = local_48;
  if (local_48 != (undefined4 *)0x0) {
    for (; puVar2 != puVar6; puVar2 = puVar2 + 7) {
      if (7 < (uint)puVar2[5]) {
        FUN_0089120c(*puVar2);
      }
      puVar2[5] = 7;
      puVar2[4] = 0;
      *(undefined2 *)puVar2 = 0;
    }
    FUN_0089120c(local_48);
  }
  local_48 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_40 = 0;
  if (7 < local_50) {
    FUN_0089120c(local_64);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_9c);
  return;
}


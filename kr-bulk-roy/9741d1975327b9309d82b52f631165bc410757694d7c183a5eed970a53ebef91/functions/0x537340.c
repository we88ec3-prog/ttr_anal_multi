
void FUN_00537340(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 local_cc [8];
  undefined4 local_c4;
  int local_c0;
  uint local_bc [4];
  undefined4 local_ac;
  uint local_a8;
  uint local_a0 [4];
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
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e016;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_c4 = param_1;
  if (param_2 != 0) {
    local_c0 = FUN_0072e360(local_14);
    while (local_c0 != 0) {
      iVar3 = FUN_007300a0(&DAT_00c0f038);
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
      pcVar4 = pcVar6;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar6,(int)pcVar4 - (int)(pcVar6 + 1));
      local_8 = 0;
      FUN_004028b0(local_30);
      local_8._0_1_ = 2;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      iVar3 = FUN_007300a0(&DAT_00c0f278);
      if (iVar3 == 0) {
        pcVar6 = (char *)0x0;
      }
      else {
        pcVar6 = (char *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          pcVar6 = *(char **)pcVar6;
        }
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c[0] = local_4c[0] & 0xffffff00;
      pcVar4 = pcVar6;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar6,(int)pcVar4 - (int)(pcVar6 + 1));
      local_8._0_1_ = 3;
      FUN_004028b0(local_4c);
      local_8._0_1_ = 5;
      if (0xf < local_38) {
        FUN_0089120c(local_4c[0]);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c[0] = local_4c[0] & 0xffffff00;
      local_70 = 7;
      local_74 = 0;
      local_84[0] = local_84[0] & 0xffff0000;
      FUN_004026e0(local_a0,0,0xffffffff);
      local_8._0_1_ = 6;
      local_68 = local_68 & 0xffff0000;
      local_54 = 7;
      local_58 = 0;
      FUN_004026e0(local_bc,0,0xffffffff);
      uVar2 = local_c4;
      local_8 = CONCAT31(local_8._1_3_,7);
      uVar5 = FUN_005394c0(local_84);
      FUN_00539230(uVar2,local_cc,uVar5);
      if (7 < local_54) {
        FUN_0089120c(local_68);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = local_68 & 0xffff0000;
      if (7 < local_70) {
        FUN_0089120c(local_84[0]);
      }
      local_70 = 7;
      local_74 = 0;
      local_84[0] = local_84[0] & 0xffff0000;
      if (7 < local_a8) {
        FUN_0089120c(local_bc[0]);
      }
      local_8 = 0xffffffff;
      local_a8 = 7;
      local_ac = 0;
      local_bc[0] = local_bc[0] & 0xffff0000;
      if (7 < local_8c) {
        FUN_0089120c(local_a0[0]);
      }
      local_a0[0] = local_a0[0] & 0xffff0000;
      local_8c = 7;
      local_90 = 0;
      local_c0 = FUN_0072e3c0();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


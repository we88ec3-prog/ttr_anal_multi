
void FUN_00522e80(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  short *****pppppsVar6;
  int in_ECX;
  short *****pppppsVar7;
  undefined4 local_10c;
  int local_108;
  int local_104;
  int local_100;
  undefined **local_fc [17];
  char local_b8;
  uint local_b0;
  undefined4 local_a0;
  uint local_9c;
  uint local_84;
  undefined4 local_74;
  uint local_70;
  short ****local_68 [4];
  undefined4 local_58;
  uint local_54;
  short ****local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009239cb;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_0072ed80(local_fc);
  local_8 = 0;
  FUN_0072f110(0);
  if (local_b8 == '\0') {
    iVar3 = FUN_0072e2e0("ITEM_USING_MSG_LIST");
    if (iVar3 != 0) {
      local_108 = *(int *)(in_ECX + 4);
      local_100 = FUN_0072e360(uVar2);
      while (local_100 != 0) {
        iVar3 = FUN_007300a0(&DAT_00bf2330);
        if (iVar3 == 0) {
LAB_00522fa1:
          local_10c = 0;
        }
        else {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 == (undefined4 *)0x0) goto LAB_00522fa1;
          local_10c = FUN_008917b4(puVar4);
        }
        local_54 = 7;
        local_58 = 0;
        local_68[0] = (short ****)((uint)local_68[0] & 0xffff0000);
        local_8._0_1_ = 1;
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        FUN_00402a70("PRE_MSG",7);
        local_8._0_1_ = 2;
        uVar5 = FUN_0072ecf0(&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00440130(uVar5);
        if (0xf < local_70) {
          FUN_0089120c(local_84);
        }
        local_70 = 0xf;
        local_74 = 0;
        local_84 = local_84 & 0xffffff00;
        if (0xf < local_1c) {
          FUN_0089120c(local_30);
        }
        local_38 = 7;
        local_3c = 0;
        local_4c[0] = (short ****)((uint)local_4c[0] & 0xffff0000);
        local_8._0_1_ = 4;
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        FUN_00402a70("POST_MSG",8);
        local_8._0_1_ = 5;
        uVar5 = FUN_0072ecf0(&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,6);
        FUN_00440130(uVar5);
        if (0xf < local_70) {
          FUN_0089120c(local_84);
        }
        local_8 = CONCAT31(local_8._1_3_,4);
        local_70 = 0xf;
        local_74 = 0;
        local_84 = local_84 & 0xffffff00;
        if (0xf < local_1c) {
          FUN_0089120c(local_30);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        FUN_008438c0(&local_10c);
        if (local_104 != local_108) {
          pppppsVar7 = (short *****)local_68[0];
          if (local_54 < 8) {
            pppppsVar7 = local_68;
          }
          pppppsVar6 = pppppsVar7;
          do {
            sVar1 = *(short *)pppppsVar6;
            pppppsVar6 = (short *****)((int)pppppsVar6 + 2);
          } while (sVar1 != 0);
          FUN_00402160(pppppsVar7,(int)pppppsVar6 - (int)((int)pppppsVar7 + 2) >> 1);
          pppppsVar7 = (short *****)local_4c[0];
          if (local_38 < 8) {
            pppppsVar7 = local_4c;
          }
          pppppsVar6 = pppppsVar7;
          do {
            sVar1 = *(short *)pppppsVar6;
            pppppsVar6 = (short *****)((int)pppppsVar6 + 2);
          } while (sVar1 != 0);
          FUN_00402160(pppppsVar7,(int)pppppsVar6 - (int)((int)pppppsVar7 + 2) >> 1);
        }
        if (7 < local_38) {
          FUN_0089120c(local_4c[0]);
        }
        local_8 = local_8 & 0xffffff00;
        local_38 = 7;
        local_3c = 0;
        local_4c[0] = (short ****)((uint)local_4c[0] & 0xffff0000);
        if (7 < local_54) {
          FUN_0089120c(local_68[0]);
        }
        local_54 = 7;
        local_58 = 0;
        local_68[0] = (short ****)((uint)local_68[0] & 0xffff0000);
        local_100 = FUN_0072e3c0();
      }
    }
    local_8 = 0xffffffff;
    local_fc[0] = TiXmlDocument::vftable;
    if (0xf < local_9c) {
      FUN_0089120c(local_b0);
    }
    local_9c = 0xf;
    local_a0 = 0;
    local_b0 = local_b0 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_8 = 0xffffffff;
    local_fc[0] = TiXmlDocument::vftable;
    if (0xf < local_9c) {
      FUN_0089120c(local_b0);
    }
    local_9c = 0xf;
    local_a0 = 0;
    local_b0 = local_b0 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


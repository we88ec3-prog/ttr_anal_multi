
void FUN_0053c4e0(uint param_1,uint param_2)

{
  short sVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  short ****ppppsVar4;
  short ****ppppsVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint local_5c;
  undefined4 *local_58;
  uint auStack_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  short ***local_38 [5];
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092f1a8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_5c;
  ExceptionList = &local_14;
  local_5c = param_1;
  if (5 < param_2) {
    uVar6 = (param_2 - 6) / 10;
    uVar2 = FUN_004ed610(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    local_c = 0;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_c = (uint)local_c._1_3_ << 8;
    }
    FUN_004d6b30(uVar2);
    local_c = 0xffffffff;
    if (7 < local_24) {
      FUN_0089120c(local_38[0]);
    }
    if (uVar6 != 0) {
      puVar7 = (undefined4 *)(local_5c + 10);
      local_5c = uVar6;
      do {
        local_58 = puVar7;
        if (puVar7 != (undefined4 *)0x4) {
          if ((DAT_00fb75b0 & 1) == 0) {
            DAT_00fb75b0 = DAT_00fb75b0 | 1;
            local_c = 2;
            FUN_004f3d80();
            _atexit((_func_4879 *)&LAB_00bcd1e0);
            local_c = 0xffffffff;
          }
          puVar3 = (undefined2 *)FUN_004f6a30(*puVar7);
          if (puVar3 == (undefined2 *)0x0) {
            puVar3 = &DAT_00bed1fc;
          }
          FUN_0053cfe0(puVar3,*puVar7);
          local_c = 3;
          ppppsVar5 = (short ****)local_38[0];
          if (local_24 < 8) {
            ppppsVar5 = local_38;
          }
          auStack_54[0] = auStack_54[0] & 0xffff0000;
          uStack_40 = 7;
          uStack_44 = 0;
          ppppsVar4 = ppppsVar5;
          do {
            sVar1 = *(short *)ppppsVar4;
            ppppsVar4 = (short ****)((int)ppppsVar4 + 2);
          } while (sVar1 != 0);
          FUN_00402160(ppppsVar5,(int)ppppsVar4 - (int)((int)ppppsVar5 + 2) >> 1);
          if ((DAT_00fb11e0 & 1) == 0) {
            DAT_00fb11e0 = DAT_00fb11e0 | 1;
            local_c._0_1_ = 5;
            FUN_004d4d10();
            _atexit((_func_4879 *)&LAB_00bccef0);
          }
          local_c = CONCAT31(local_c._1_3_,4);
          FUN_004d6b30(auStack_54);
          if (7 < uStack_40) {
            FUN_0089120c(auStack_54[0]);
          }
          local_c = 0xffffffff;
          if (7 < local_24) {
            FUN_0089120c(local_38[0]);
          }
        }
        puVar7 = (undefined4 *)((int)local_58 + 10);
        local_5c = local_5c - 1;
        local_58 = puVar7;
      } while (local_5c != 0);
    }
    auStack_54[0] = auStack_54[0] & 0xffff0000;
    uStack_40 = 7;
    uStack_44 = 0;
    FUN_00402160(L"--UnionList End--",0x11);
    local_c = 6;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_c._0_1_ = 7;
      local_c._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_c = CONCAT31(local_c._1_3_,6);
    }
    puVar7 = (undefined4 *)FUN_00891268(0x24);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7[7] = 7;
      puVar7[6] = 0;
      *(undefined2 *)(puVar7 + 2) = 0;
    }
    *puVar7 = 0;
    *(undefined1 *)(puVar7 + 1) = 1;
    FUN_004026e0(auStack_54,0,0xffffffff);
    FUN_004d7b00(&DAT_00fb11e8);
    if (DAT_00fb1308 == 0) {
      FUN_004d4fa0();
      puVar7 = (undefined4 *)FUN_00891268(0x14);
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = FoxUI::FXUIEvent::vftable;
        puVar7[1] = 0xffffffff;
        puVar7[2] = 0xffffffff;
        puVar7[3] = 0;
        puVar7[4] = 0xf4366;
      }
      FUN_004072a0();
    }
    if (7 < uStack_40) {
      FUN_0089120c(auStack_54[0]);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_5c);
  return;
}


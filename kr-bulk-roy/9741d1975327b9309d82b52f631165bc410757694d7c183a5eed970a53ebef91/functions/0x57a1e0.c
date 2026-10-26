
void FUN_0057a1e0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 local_540 [8];
  undefined4 local_530;
  uint *local_52c;
  undefined1 **ppuStack_528;
  uint uStack_524;
  undefined1 auStack_514 [4];
  undefined1 *local_510;
  undefined4 uStack_50c;
  uint local_508 [4];
  undefined4 local_4f8;
  uint local_4f4;
  uint local_4ec [4];
  undefined4 local_4dc;
  uint local_4d8;
  uint uStack_4d0;
  undefined4 uStack_4c0;
  uint uStack_4bc;
  undefined1 auStack_4b4 [28];
  undefined1 auStack_498 [28];
  undefined1 auStack_47c [28];
  undefined1 auStack_460 [28];
  undefined1 auStack_444 [28];
  undefined1 auStack_428 [28];
  undefined1 auStack_40c [28];
  undefined1 auStack_3f0 [28];
  undefined1 auStack_3d4 [28];
  undefined1 auStack_3b8 [28];
  undefined1 auStack_39c [28];
  undefined1 auStack_380 [28];
  undefined1 auStack_364 [28];
  undefined1 auStack_348 [84];
  undefined1 auStack_2f4 [28];
  undefined1 auStack_2d8 [28];
  undefined1 auStack_2bc [28];
  undefined1 auStack_2a0 [28];
  undefined1 auStack_284 [28];
  undefined1 auStack_268 [56];
  undefined1 auStack_230 [28];
  undefined1 auStack_214 [28];
  undefined1 auStack_1f8 [112];
  undefined1 auStack_188 [140];
  undefined1 auStack_fc [28];
  undefined1 auStack_e0 [28];
  undefined1 auStack_c4 [56];
  undefined1 auStack_8c [84];
  undefined1 auStack_38 [28];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092eb1d;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_514;
  uStack_524 = DAT_00d61f20 ^ (uint)&stack0xfffffae0;
  ExceptionList = &local_14;
  ppuStack_528 = (undefined1 **)0x300;
  local_52c = (uint *)0x400;
  *(undefined4 *)(param_1 + 0xd0) = 0x400;
  *(undefined4 *)(param_1 + 0xd4) = 0x300;
  local_530 = 0x57a249;
  FUN_00575780();
  if (*(int *)(param_1 + 0x78) == 0) {
    ppuStack_528 = (undefined1 **)0xc;
    local_52c = (uint *)0xc10d04;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a27a;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"ButtonStart0",0xc);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,1);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a2c4;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a2d5;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a303;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc;
    local_52c = (uint *)0xc10d30;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a327;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 2;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"ButtonStart1",0xc);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,3);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a375;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a386;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a3b4;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc;
    local_52c = (uint *)0xc10d5c;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a3d8;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 4;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"ButtonStart2",0xc);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,5);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a426;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a437;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a465;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc;
    local_52c = (uint *)0xc10d88;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a489;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 6;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"ButtonStart3",0xc);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,7);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a4d7;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a4e8;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a516;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10db0;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a53a;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 8;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"ButtonStop0",0xb);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,9);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a588;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a599;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a5c7;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10dd4;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a5eb;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 10;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"ButtonStop1",0xb);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0xb);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a639;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a64a;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a678;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10df8;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a69c;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0xc;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"ButtonStop2",0xb);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0xd);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a6ea;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a6fb;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a729;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10e1c;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a74d;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0xe;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"ButtonStop3",0xb);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0xf);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a79b;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a7ac;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a7da;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x5;
    local_52c = (uint *)0xc10aa4;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a7fe;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x10;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"Icon0",5);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x11);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a84c;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a85d;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a88b;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x5;
    local_52c = (uint *)0xc10aac;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a8af;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x12;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"Icon1",5);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x13);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a8fd;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a90e;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a93c;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x5;
    local_52c = (uint *)0xc10a9c;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57a960;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x14;
    local_52c = (uint *)0x7;
    local_530 = 0;
    local_540[0] = 0;
    FUN_00402160(L"Icon2",5);
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x15);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57a9ae;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57a9bf;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57a9ed;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x7;
    local_52c = (uint *)0xc10e5c;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57aa10;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x16;
    FUN_00402250(L"Icon0-1");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x17);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57aa51;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57aa62;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57aa90;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x7;
    local_52c = (uint *)0xc10e74;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57aab3;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x18;
    FUN_00402250(L"Icon1-1");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x19);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57aaf4;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57ab05;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57ab33;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x7;
    local_52c = (uint *)0xc10e8c;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57ab56;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x1a;
    FUN_00402250(L"Icon2-1");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x1b);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57ab97;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57aba8;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57abd6;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10eac;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57abfa;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x1c;
    FUN_00402250(L"HelperIcon0");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x1d);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57ac3b;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57ac4c;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57ac7a;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10ed0;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57ac9e;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x1e;
    FUN_00402250(L"HelperIcon1");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x1f);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57acdf;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57acf0;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57ad1e;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10ef4;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_530 = 0x57ad42;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x20;
    FUN_00402250(L"HelperIcon2");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x21);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57ad83;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57ad94;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57adc2;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10f18;
    local_52c = (uint *)0x57add3;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x22;
    FUN_00402250(L"HelperIcon3");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x23);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57ae14;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57ae25;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57ae53;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10f3c;
    local_52c = (uint *)0x57ae64;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x24;
    FUN_00402250(L"HelperDesc");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x25);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57aea5;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57aeb6;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57aee4;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10f5c;
    local_52c = (uint *)0x57aef5;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x26;
    FUN_00402250(L"MainFrame");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x27);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57af36;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57af47;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57af75;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10f7c;
    local_52c = (uint *)0x57af86;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x28;
    FUN_00402250(L"IconMask");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x29);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57afc7;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57afd8;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b006;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10fa0;
    local_52c = (uint *)0x57b017;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x2a;
    FUN_00402250(L"SlotOutline");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x2b);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57b058;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b069;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b097;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10fc0;
    local_52c = (uint *)0x57b0a8;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x2c;
    FUN_00402250(L"ItemSlot");
    ppuStack_528 = (undefined1 **)FUN_0044f640(local_508);
    local_c = CONCAT31(local_c._1_3_,0x2d);
    local_52c = *(uint **)(param_1 + 4);
    local_530 = 0x57b0e9;
    FUN_005752e0();
    if (7 < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b0fa;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4f4 = 7;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffff0000;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b128;
      FUN_0089120c();
    }
    *(undefined4 *)(param_1 + 0x78) = 1;
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if (*(int *)(param_1 + 0x7c) == 0) {
    ppuStack_528 = (undefined1 **)0x57b149;
    FUN_00573b50();
    ppuStack_528 = (undefined1 **)0xc10a80;
    local_52c = (uint *)0x57b157;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x3;
    local_52c = local_508;
    local_c = 0x2e;
    local_530 = 0x57b171;
    FUN_00573510();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b18d;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10d04;
    local_52c = (uint *)0x57b19e;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10a80;
    local_c = 0x2f;
    local_52c = (uint *)0x57b1b7;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x30);
    local_530 = 0x57b1d2;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b1e7;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b216;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10d30;
    local_52c = (uint *)0x57b227;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10a80;
    local_c = 0x31;
    local_52c = (uint *)0x57b240;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x2;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x32);
    local_530 = 0x57b25b;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b26b;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b29a;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10d5c;
    local_52c = (uint *)0x57b2ab;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10a80;
    local_c = 0x33;
    local_52c = (uint *)0x57b2c4;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x3;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x34);
    local_530 = 0x57b2df;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b2ef;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b31e;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10d88;
    local_52c = (uint *)0x57b32f;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10a80;
    local_c = 0x35;
    local_52c = (uint *)0x57b348;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x4;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x36);
    local_530 = 0x57b363;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b373;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b3a2;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10a80;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    local_52c = (uint *)0x57b3c9;
    FUN_0040b310();
    local_c = 0x37;
    local_52c = *(uint **)(param_1 + 8);
    ppuStack_528 = (undefined1 **)0x2;
    local_530 = 0x57b3e3;
    FUN_00573170();
    local_c = 0xffffffff;
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b3ff;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10a80;
    local_52c = (uint *)0x57b410;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x38;
    FUN_00402250(L"StartButton");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = local_508;
    local_530 = 0x57b448;
    FUN_00573320();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b464;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10af0;
    local_52c = (uint *)0x57b475;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x3;
    local_52c = local_508;
    local_c = 0x39;
    local_530 = 0x57b48f;
    FUN_00573510();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b4ab;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10db0;
    local_52c = (uint *)0x57b4bc;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10af0;
    local_c = 0x3a;
    local_52c = (uint *)0x57b4d5;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x3b);
    local_530 = 0x57b4f0;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b505;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b534;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10dd4;
    local_52c = (uint *)0x57b545;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10af0;
    local_c = 0x3c;
    local_52c = (uint *)0x57b55e;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x2;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x3d);
    local_530 = 0x57b579;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b589;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b5b8;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10df8;
    local_52c = (uint *)0x57b5c9;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10af0;
    local_c = 0x3e;
    local_52c = (uint *)0x57b5e2;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x3;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x3f);
    local_530 = 0x57b5fd;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b60d;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b63c;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10e1c;
    local_52c = (uint *)0x57b64d;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10af0;
    local_c = 0x40;
    local_52c = (uint *)0x57b666;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x4;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x41);
    local_530 = 0x57b681;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b691;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b6c0;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x57b6d1;
    FUN_0040b3c0();
    local_c = 0x42;
    local_52c = *(uint **)(param_1 + 8);
    ppuStack_528 = (undefined1 **)0x2;
    local_530 = 0x57b6e9;
    FUN_00573170();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b705;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10af0;
    local_52c = (uint *)0x57b716;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x43;
    FUN_00402250(L"StopButton");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = local_508;
    local_530 = 0x57b74e;
    FUN_00573320();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b76a;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x57b77b;
    FUN_0040b3c0();
    local_c = 0x44;
    local_52c = *(uint **)(param_1 + 8);
    ppuStack_528 = (undefined1 **)0x0;
    local_530 = 0x57b793;
    FUN_00573110();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b7af;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10a8c;
    local_52c = (uint *)0x57b7c0;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x3;
    local_52c = local_508;
    local_c = 0x45;
    local_530 = 0x57b7da;
    FUN_00573510();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b7f9;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10eac;
    local_52c = (uint *)0x57b80a;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10a8c;
    local_c = 0x46;
    local_52c = (uint *)0x57b823;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x47);
    local_530 = 0x57b83e;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b84e;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b87d;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10ed0;
    local_52c = (uint *)0x57b88e;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10a8c;
    local_c = 0x48;
    local_52c = (uint *)0x57b8a7;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x2;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x49);
    local_530 = 0x57b8c2;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b8d2;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b901;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10ef4;
    local_52c = (uint *)0x57b912;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10a8c;
    local_c = 0x4a;
    local_52c = (uint *)0x57b92b;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x3;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x4b);
    local_530 = 0x57b946;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b956;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57b985;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10f18;
    local_52c = (uint *)0x57b996;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10a8c;
    local_c = 0x4c;
    local_52c = (uint *)0x57b9af;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x4;
    local_52c = local_4ec;
    local_c = CONCAT31(local_c._1_3_,0x4d);
    local_530 = 0x57b9ca;
    FUN_005736d0();
    if (0xf < local_4d8) {
      ppuStack_528 = (undefined1 **)local_4ec[0];
      local_52c = (uint *)0x57b9da;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_4d8 = 0xf;
    local_4dc = 0;
    local_4ec[0] = local_4ec[0] & 0xffffff00;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57ba09;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x57ba1a;
    FUN_0040b3c0();
    local_c = 0x4e;
    local_52c = *(uint **)(param_1 + 8);
    ppuStack_528 = (undefined1 **)0x2;
    local_530 = 0x57ba32;
    FUN_00573170();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57ba4e;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10a8c;
    local_52c = (uint *)0x57ba5f;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x4f;
    FUN_00402250(L"HelperButton");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = local_508;
    local_530 = 0x57ba97;
    FUN_00573320();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57bab3;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10fe8;
    local_52c = (uint *)0x57bac4;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x4;
    local_52c = local_508;
    local_c = 0x50;
    local_530 = 0x57bade;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57baf1;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10aa4;
    local_52c = (uint *)0x57baff;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10fe8;
    local_c = 0x51;
    local_52c = (uint *)0x57bb18;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x5;
    local_52c = local_508;
    local_c = CONCAT31(local_c._1_3_,0x52);
    local_530 = 0x57bb33;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57bb3c;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bb4c;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10aac;
    local_52c = (uint *)0x57bb5d;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10fe8;
    local_c = 0x53;
    local_52c = (uint *)0x57bb76;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x5;
    local_52c = local_508;
    local_c = CONCAT31(local_c._1_3_,0x54);
    local_530 = 0x57bb94;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57bb9d;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bbb0;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10a9c;
    local_52c = (uint *)0x57bbc1;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10fe8;
    local_c = 0x55;
    local_52c = (uint *)0x57bbdd;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x5;
    local_52c = (uint *)auStack_47c;
    local_c = CONCAT31(local_c._1_3_,0x56);
    local_530 = 0x57bbfe;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57bc0a;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bc1d;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10fe8;
    local_52c = (uint *)0x57bc2e;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x57;
    FUN_00402250(L"IconList");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_1f8;
    local_530 = 0x57bc69;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bc7c;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c2c;
    local_52c = (uint *)0x57bc8d;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_3f0;
    local_c = 0x58;
    local_530 = 0x57bcaa;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bcbd;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10aa4;
    local_52c = (uint *)0x57bcce;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10c2c;
    local_c = 0x59;
    local_52c = (uint *)0x57bcea;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_3f0;
    local_c = CONCAT31(local_c._1_3_,0x5a);
    local_530 = 0x57bd0b;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57bd17;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bd2a;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c38;
    local_52c = (uint *)0x57bd3b;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_460;
    local_c = 0x5b;
    local_530 = 0x57bd58;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bd6b;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10aac;
    local_52c = (uint *)0x57bd7c;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10c38;
    local_c = 0x5c;
    local_52c = (uint *)0x57bd98;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_460;
    local_c = CONCAT31(local_c._1_3_,0x5d);
    local_530 = 0x57bdb9;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57bdc5;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bdd8;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c44;
    local_52c = (uint *)0x57bde9;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_380;
    local_c = 0x5e;
    local_530 = 0x57be06;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57be19;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10a9c;
    local_52c = (uint *)0x57be2a;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10c44;
    local_c = 0x5f;
    local_52c = (uint *)0x57be46;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_380;
    local_c = CONCAT31(local_c._1_3_,0x60);
    local_530 = 0x57be67;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57be73;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57be86;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c50;
    local_52c = (uint *)0x57be94;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_4b4;
    local_c = 0x61;
    local_530 = 0x57beae;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bebe;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10e5c;
    local_52c = (uint *)0x57becf;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10c50;
    local_c = 0x62;
    local_52c = (uint *)0x57bee8;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_4b4;
    local_c = CONCAT31(local_c._1_3_,99);
    local_530 = 0x57bf06;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57bf0f;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bf22;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c5c;
    local_52c = (uint *)0x57bf33;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_3b8;
    local_c = 100;
    local_530 = 0x57bf50;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bf63;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10e74;
    local_52c = (uint *)0x57bf74;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10c5c;
    local_c = 0x65;
    local_52c = (uint *)0x57bf90;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_3b8;
    local_c = CONCAT31(local_c._1_3_,0x66);
    local_530 = 0x57bfb1;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57bfbd;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57bfd0;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c68;
    local_52c = (uint *)0x57bfe1;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_498;
    local_c = 0x67;
    local_530 = 0x57bffe;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c011;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10e8c;
    local_52c = (uint *)0x57c022;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10c68;
    local_c = 0x68;
    local_52c = (uint *)0x57c03e;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_498;
    local_c = CONCAT31(local_c._1_3_,0x69);
    local_530 = 0x57c05f;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57c06b;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c07e;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c2c;
    local_52c = (uint *)0x57c08f;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x6a;
    FUN_00402250(L"IconList");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_2f4;
    local_530 = 0x57c0ca;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c0dd;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c38;
    local_52c = (uint *)0x57c0ee;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x6b;
    FUN_00402250(L"IconList");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_8c;
    local_530 = 0x57c129;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c13c;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c44;
    local_52c = (uint *)0x57c14d;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x6c;
    FUN_00402250(L"IconList");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_2bc;
    local_530 = 0x57c188;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c19b;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c50;
    local_52c = (uint *)0x57c1ac;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x6d;
    FUN_00402250(L"IconList");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_348;
    local_530 = 0x57c1e7;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c1fa;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c5c;
    local_52c = (uint *)0x57c20b;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x6e;
    FUN_00402250(L"IconList");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_284;
    local_530 = 0x57c246;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c259;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c68;
    local_52c = (uint *)0x57c26a;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x6f;
    FUN_00402250(L"IconList");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_c4;
    local_530 = 0x57c2a5;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c2b8;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10afc;
    local_52c = (uint *)0x57c2c9;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_444;
    local_c = 0x70;
    local_530 = 0x57c2e6;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c2f9;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10f5c;
    local_52c = (uint *)0x57c30a;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10afc;
    local_c = 0x71;
    local_52c = (uint *)0x57c326;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_444;
    local_c = CONCAT31(local_c._1_3_,0x72);
    local_530 = 0x57c347;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57c353;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c366;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10afc;
    local_52c = (uint *)0x57c377;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x73;
    FUN_00402250(L"MainBackground");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_214;
    local_530 = 0x57c3b2;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c3c5;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c20;
    local_52c = (uint *)0x57c3d6;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_40c;
    local_c = 0x74;
    local_530 = 0x57c3f3;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c406;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10f3c;
    local_52c = (uint *)0x57c417;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10c20;
    local_c = 0x75;
    local_52c = (uint *)0x57c433;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_40c;
    local_c = CONCAT31(local_c._1_3_,0x76);
    local_530 = 0x57c454;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57c460;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c473;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c20;
    local_52c = (uint *)0x57c484;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x77;
    FUN_00402250(L"HelperImage");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_fc;
    local_530 = 0x57c4bf;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c4d2;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10ba0;
    local_52c = (uint *)0x57c4e3;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_3d4;
    local_c = 0x78;
    local_530 = 0x57c500;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c513;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10f7c;
    local_52c = (uint *)0x57c524;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10ba0;
    local_c = 0x79;
    local_52c = (uint *)0x57c540;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_3d4;
    local_c = CONCAT31(local_c._1_3_,0x7a);
    local_530 = 0x57c561;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57c56d;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c580;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10ba0;
    local_52c = (uint *)0x57c591;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x7b;
    FUN_00402250(L"MaskImage");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_2d8;
    local_530 = 0x57c5cc;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c5df;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10b20;
    local_52c = (uint *)0x57c5f0;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x6;
    local_52c = (uint *)auStack_2a0;
    local_c = 0x7c;
    local_530 = 0x57c60d;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c620;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10b44;
    local_52c = (uint *)0x57c631;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x6;
    local_52c = (uint *)auStack_268;
    local_c = 0x7d;
    local_530 = 0x57c64e;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c661;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10b64;
    local_52c = (uint *)0x57c672;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x6;
    local_52c = (uint *)auStack_230;
    local_c = 0x7e;
    local_530 = 0x57c68f;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c6a2;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10bf0;
    local_52c = (uint *)0x57c6b3;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_39c;
    local_c = 0x7f;
    local_530 = 0x57c6d0;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c6e3;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10fc0;
    local_52c = (uint *)0x57c6f4;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10bf0;
    local_c = 0x80;
    local_52c = (uint *)0x57c710;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_39c;
    local_c = CONCAT31(local_c._1_3_,0x81);
    local_530 = 0x57c731;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57c73d;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c750;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10bf0;
    local_52c = (uint *)0x57c761;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x82;
    FUN_00402250(L"AcquisitionItem");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_188;
    local_530 = 0x57c79c;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c7af;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10bc4;
    local_52c = (uint *)0x57c7c0;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x7;
    local_52c = (uint *)auStack_364;
    local_c = 0x83;
    local_530 = 0x57c7dd;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c7f0;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10fa0;
    local_52c = (uint *)0x57c801;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10bc4;
    local_c = 0x84;
    local_52c = (uint *)0x57c81d;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_364;
    local_c = CONCAT31(local_c._1_3_,0x85);
    local_530 = 0x57c83e;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57c84a;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c85d;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10bc4;
    local_52c = (uint *)0x57c86e;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x86;
    FUN_00402250(L"ItemOutline");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_e0;
    local_530 = 0x57c8a9;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c8bc;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c14;
    local_52c = (uint *)0x57c8cd;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x1;
    local_52c = (uint *)auStack_428;
    local_c = 0x87;
    local_530 = 0x57c8ea;
    FUN_00573510();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c8fd;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)&DAT_00c0dc30;
    local_52c = (uint *)0x57c90e;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0xc10c14;
    local_c = 0x88;
    local_52c = (uint *)0x57c92a;
    FUN_00402b70();
    ppuStack_528 = (undefined1 **)0x0;
    local_52c = (uint *)auStack_428;
    local_c = CONCAT31(local_c._1_3_,0x89);
    local_530 = 0x57c94b;
    FUN_005736d0();
    ppuStack_528 = (undefined1 **)0x57c957;
    FUN_00402c50();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c96a;
    FUN_00402c50();
    ppuStack_528 = (undefined1 **)0xc10c14;
    local_52c = (uint *)0x57c97b;
    FUN_00402b70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x8a;
    FUN_00402250(L"ItemImage");
    ppuStack_528 = (undefined1 **)FUN_0044f8f0();
    local_52c = (uint *)auStack_38;
    local_530 = 0x57c9b6;
    FUN_00573320();
    local_c = 0xffffffff;
    ppuStack_528 = (undefined1 **)0x57c9c9;
    FUN_00402c50();
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0x40;
    *(undefined4 *)(param_1 + 0x2c) = 0x5e;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0x40;
    *(undefined4 *)(param_1 + 0x48) = 0x5e;
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0x40;
    *(undefined4 *)(param_1 + 100) = 0x5e;
    ppuStack_528 = (undefined1 **)0x57ca04;
    FUN_006df330();
    ppuStack_528 = (undefined1 **)0x57ca0c;
    FUN_007b6d70();
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10a80;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57ca31;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x8b;
    FUN_00402250(L"StartButton");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    local_52c = (uint *)*puVar1;
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_530 = 0x57ca87;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57caa3;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xa;
    local_52c = (uint *)0xc10af0;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57cacb;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x8c;
    FUN_00402250(L"StopButton");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_52c = (uint *)*puVar1;
    local_530 = 0x57cb21;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57cb3c;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10c20;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57cb64;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x8d;
    FUN_00402250(L"HelperImage");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    local_52c = (uint *)*puVar1;
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_530 = 0x57cbba;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57cbd2;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc;
    local_52c = (uint *)0xc10a8c;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57cbfa;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x8e;
    FUN_00402250(L"HelperButton");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_52c = (uint *)*puVar1;
    local_530 = 0x57cc50;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57cc68;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x8;
    local_52c = (uint *)0xc10fe8;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57cc90;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x8f;
    FUN_00402250(L"IconList");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    local_52c = (uint *)*puVar1;
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_530 = 0x57cce6;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57ccfe;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xe;
    local_52c = (uint *)0xc10afc;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57cd26;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x90;
    FUN_00402250(L"MainBackground");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_52c = (uint *)*puVar1;
    local_530 = 0x57cd7c;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57cd94;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x9;
    local_52c = (uint *)0xc10ba0;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57cdbc;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x91;
    FUN_00402250(L"MaskImage");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    local_52c = (uint *)*puVar1;
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_530 = 0x57ce12;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57ce2a;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xf;
    local_52c = (uint *)0xc10bf0;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57ce52;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x92;
    FUN_00402250(L"AcquisitionItem");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_52c = (uint *)*puVar1;
    local_530 = 0x57cea8;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57cec0;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10bc4;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57cee8;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x93;
    FUN_00402250(L"ItemOutline");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    local_52c = (uint *)*puVar1;
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_530 = 0x57cf3e;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57cf56;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x9;
    local_52c = (uint *)0xc10c14;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57cf7e;
    FUN_00402a70();
    local_510 = (undefined1 *)local_540;
    local_c = 0x94;
    FUN_00402250(L"ItemImage");
    puVar1 = (undefined4 *)FUN_0044f7e0(local_4ec);
    ppuStack_528 = (undefined1 **)puVar1[1];
    local_52c = (uint *)*puVar1;
    local_530 = 0x57cfd4;
    local_510 = (undefined1 *)local_52c;
    uStack_50c = ppuStack_528;
    FUN_00573230();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57cfec;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x9;
    local_52c = (uint *)0xc10c2c;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57d014;
    FUN_00402a70();
    local_c = 0x95;
    ppuStack_528 = &local_510;
    local_52c = local_508;
    local_510 = (undefined1 *)0x3ee00000;
    uStack_50c = 0x3ee00000;
    local_530 = 0x57d045;
    FUN_00573420();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d05d;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x9;
    local_52c = (uint *)0xc10c38;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57d085;
    FUN_00402a70();
    local_c = 0x96;
    ppuStack_528 = &local_510;
    local_52c = local_508;
    local_510 = (undefined1 *)0x3ee00000;
    uStack_50c = 0x3ee00000;
    local_530 = 0x57d0b6;
    FUN_00573420();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d0ce;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x9;
    local_52c = (uint *)0xc10c44;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57d0f6;
    FUN_00402a70();
    local_c = 0x97;
    ppuStack_528 = &local_510;
    local_52c = local_508;
    local_510 = (undefined1 *)0x3ee00000;
    uStack_50c = 0x3ee00000;
    local_530 = 0x57d127;
    FUN_00573420();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d13f;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10c50;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57d167;
    FUN_00402a70();
    local_c = 0x98;
    ppuStack_528 = &local_510;
    local_52c = local_508;
    local_510 = (undefined1 *)0x3ed00000;
    uStack_50c = 0x3ed00000;
    local_530 = 0x57d198;
    FUN_00573420();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d1b0;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10c5c;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57d1d8;
    FUN_00402a70();
    local_c = 0x99;
    ppuStack_528 = &local_510;
    local_52c = local_508;
    local_510 = (undefined1 *)0x3ed00000;
    uStack_50c = 0x3ed00000;
    local_530 = 0x57d209;
    FUN_00573420();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d221;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xb;
    local_52c = (uint *)0xc10c68;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57d249;
    FUN_00402a70();
    local_c = 0x9a;
    ppuStack_528 = &local_510;
    local_52c = local_508;
    local_510 = (undefined1 *)0x3ed00000;
    uStack_50c = 0x3ed00000;
    local_530 = 0x57d27a;
    FUN_00573420();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d292;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0x9;
    local_52c = (uint *)0xc10c14;
    local_4f4 = 0xf;
    local_4f8 = 0;
    local_508[0] = local_508[0] & 0xffffff00;
    local_530 = 0x57d2ba;
    FUN_00402a70();
    local_c = 0x9b;
    ppuStack_528 = &local_510;
    local_52c = local_508;
    local_510 = (undefined1 *)0x3fb00000;
    uStack_50c = 0x3fb00000;
    local_530 = 0x57d2eb;
    FUN_00573420();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d303;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10afc;
    local_52c = (uint *)0x57d314;
    FUN_00402b70();
    local_c = 0x9c;
    ppuStack_528 = *(undefined1 ***)(param_1 + 8);
    local_52c = (uint *)0x57d32c;
    FUN_005737d0();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d348;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10a80;
    local_52c = (uint *)0x57d359;
    FUN_00402b70();
    local_c = 0x9d;
    ppuStack_528 = *(undefined1 ***)(param_1 + 8);
    local_52c = (uint *)0x57d371;
    FUN_005737d0();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d388;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10af0;
    local_52c = (uint *)0x57d399;
    FUN_00402b70();
    local_c = 0x9e;
    ppuStack_528 = *(undefined1 ***)(param_1 + 8);
    local_52c = (uint *)0x57d3b1;
    FUN_005737d0();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d3c8;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10a8c;
    local_52c = (uint *)0x57d3d9;
    FUN_00402b70();
    local_c = 0x9f;
    ppuStack_528 = *(undefined1 ***)(param_1 + 8);
    local_52c = (uint *)0x57d3f1;
    FUN_005737d0();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d408;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10bf0;
    local_52c = (uint *)0x57d419;
    FUN_00402b70();
    local_c = 0xa0;
    ppuStack_528 = *(undefined1 ***)(param_1 + 8);
    local_52c = (uint *)0x57d431;
    FUN_005737d0();
    local_c = 0xffffffff;
    if (0xf < local_4f4) {
      ppuStack_528 = (undefined1 **)local_508[0];
      local_52c = (uint *)0x57d448;
      FUN_0089120c();
    }
    ppuStack_528 = (undefined1 **)0xc10bc4;
    local_52c = (uint *)0x57d459;
    FUN_00402b70();
    local_c = 0xa1;
    ppuStack_528 = *(undefined1 ***)(param_1 + 8);
    local_52c = (uint *)0x57d471;
    FUN_005737d0();
    local_c = 0xffffffff;
    if (0xf < uStack_4bc) {
      ppuStack_528 = (undefined1 **)uStack_4d0;
      local_52c = (uint *)0x57d488;
      FUN_0089120c();
    }
    uStack_4bc = 0xf;
    uStack_4c0 = 0;
    uStack_4d0 = uStack_4d0 & 0xffffff00;
  }
  ppuStack_528 = (undefined1 **)0x57d4a7;
  iVar2 = FUN_006dfc40();
  iVar2 = *(int *)(iVar2 + 0x18);
  ppuStack_528 = (undefined1 **)0x57d4af;
  iVar3 = FUN_006dfc40();
  iVar3 = *(int *)(iVar3 + 0x1c);
  *(float *)(param_1 + 0xfc) = (float)((iVar2 - *(int *)(param_1 + 0xd0)) / 2);
  *(float *)(param_1 + 0x100) = (float)((iVar3 - *(int *)(param_1 + 0xd4)) / 2);
  ppuStack_528 = (undefined1 **)0x57d4f2;
  FUN_00575a80();
  ppuStack_528 = (undefined1 **)0x57d4f9;
  FUN_00577080();
  *(undefined4 *)(param_1 + 0x90) = 1;
  ppuStack_528 = (undefined1 **)0x57d50a;
  FUN_0057dda0();
  *(undefined4 *)(param_1 + 0x88) = 0;
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_514);
  return;
}


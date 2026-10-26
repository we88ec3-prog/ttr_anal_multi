
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055bce0(void)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  short *psVar5;
  undefined4 ****ppppuVar6;
  int iVar7;
  int in_ECX;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_490;
  int local_48c;
  int local_488;
  float local_484;
  float local_480;
  int local_47c;
  int local_478;
  int local_474;
  int local_470;
  int local_46c;
  int local_468;
  uint local_464;
  undefined4 *local_460;
  int local_45c;
  int local_458;
  undefined4 *local_454;
  undefined4 *local_450;
  undefined1 local_44c [64];
  undefined1 local_40c [64];
  undefined4 local_3cc;
  undefined4 local_3c8;
  undefined4 local_3c4;
  undefined4 local_3c0;
  undefined4 local_3bc;
  undefined4 local_3b8;
  undefined4 local_3b4;
  undefined4 local_3b0;
  undefined4 local_3ac;
  undefined4 local_3a8;
  undefined4 local_3a4;
  undefined4 local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  int local_388;
  undefined4 *local_384;
  int local_380;
  int local_37c;
  undefined4 ***local_378 [4];
  undefined4 local_368;
  uint local_364;
  undefined1 local_35c [840];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933959;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x4d4c) != 0) {
    local_45c = in_ECX;
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 0;
      FUN_00734ef0(local_14);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    local_460 = DAT_00fb7b90;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    piVar4 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
    (**(code **)(*piVar4 + 0xb4))(piVar4,2,local_44c);
    (**(code **)(*piVar4 + 0xb4))(piVar4,3,local_40c);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb773c + 0x10))(DAT_00fb773c);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 3;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb7738 + 0x14))(DAT_00fb7738);
    local_394 = 0;
    local_398 = 0;
    local_39c = 0;
    local_3a0 = 0;
    local_3a8 = 0;
    local_3ac = 0;
    local_3b0 = 0;
    local_3b4 = 0;
    local_3bc = 0;
    local_3c0 = 0;
    local_3c4 = 0;
    local_3c8 = 0;
    local_390 = 0x3f800000;
    local_3a4 = 0x3f800000;
    local_3b8 = 0x3f800000;
    local_3cc = 0x3f800000;
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x8b,0xffffffff);
    (**(code **)(*piVar4 + 0xb0))(piVar4,2,local_44c);
    (**(code **)(*piVar4 + 0xb0))(piVar4,3,local_40c);
    (**(code **)(*piVar4 + 0xb0))(piVar4,0x100,&local_3cc);
    (**(code **)(*piVar4 + 0x164))(piVar4,0x144);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x16,3);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x1b,1);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0xf,1);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x19,5);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x18,0);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0xab,1);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x13,5);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x14,6);
    (**(code **)(*piVar4 + 0x10c))(piVar4,0,4,2);
    (**(code **)(*piVar4 + 0x10c))(piVar4,0,5,2);
    (**(code **)(*piVar4 + 0xe4))(piVar4,7,1);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x17,4);
    (**(code **)(*piVar4 + 0x114))(piVar4,0,1,3);
    (**(code **)(*piVar4 + 0x114))(piVar4,0,2,3);
    (**(code **)(*piVar4 + 0x114))(piVar4,0,6,2);
    (**(code **)(*piVar4 + 0x114))(piVar4,0,5,1);
    local_464 = 0;
    if (*(int *)(in_ECX + 0x4d30) != 0) {
      puVar9 = (undefined4 *)(in_ECX + 8);
      do {
        in_ECX = local_45c;
        local_454 = puVar9;
        if (0x103 < local_464) break;
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          local_8 = 4;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          local_8 = 0xffffffff;
        }
        puVar8 = *(undefined4 **)(local_45c + 0x4d34 + *(short *)(puVar9 + -2) * 4);
        local_450 = puVar8;
        FUN_00736180(&local_450);
        if ((local_488 == DAT_00fb7b80) || (DAT_00fb7b90 = puVar8, local_488 == -0x10)) {
          DAT_00fb7b90 = DAT_00fb7b8c;
        }
        if ((uint)puVar9[9] < 8) {
          psVar5 = (short *)(puVar9 + 4);
        }
        else {
          psVar5 = (short *)puVar9[4];
        }
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          local_8 = 5;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          local_8 = 0xffffffff;
        }
        if (psVar5 != (short *)0x0) {
          psVar1 = psVar5 + 1;
          do {
            sVar2 = *psVar5;
            psVar5 = psVar5 + 1;
          } while (sVar2 != 0);
          if ((int)psVar5 - (int)psVar1 >> 1 != 0) {
            local_450 = (undefined4 *)*local_454;
            iVar3 = local_454[-1];
            FUN_0073ce20();
            local_8 = 6;
            ppppuVar6 = (undefined4 ****)local_378[0];
            if (local_364 < 8) {
              ppppuVar6 = local_378;
            }
            iVar7 = FUN_00735620(&DAT_00fb7b70,DAT_00fb7b90,ppppuVar6,0x101);
            puVar9 = local_454;
            if (iVar7 == 0) {
              local_8 = 0xffffffff;
              if (7 < local_364) {
                FUN_0089120c(local_378[0]);
              }
            }
            else {
              local_478 = *(int *)(iVar7 + 0x28);
              local_47c = *(int *)(iVar7 + 0x24);
              local_470 = *(int *)(iVar7 + 0x30);
              local_474 = *(int *)(iVar7 + 0x2c);
              local_388 = iVar3 + (((local_454[1] - local_454[-1]) - local_474) +
                                  *(int *)(iVar7 + 0x24)) / 2;
              local_384 = local_450;
              local_380 = (local_388 - *(int *)(iVar7 + 0x24)) + *(int *)(iVar7 + 0x2c);
              local_37c = (*(int *)(iVar7 + 0x30) - *(int *)(iVar7 + 0x28)) + (int)local_450;
              local_8 = 0xffffffff;
              local_458 = DAT_00fb7b74;
              if (7 < local_364) {
                FUN_0089120c(local_378[0]);
              }
              local_364 = 7;
              local_368 = 0;
              local_378[0] = (undefined4 ***)((uint)local_378[0] & 0xffff0000);
              if ((DAT_00fb7bc8 & 1) == 0) {
                DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
                local_8 = 7;
                FUN_00734ef0();
                _atexit((_func_4879 *)&LAB_00bcd4f0);
                local_8 = 0xffffffff;
              }
              local_490 = local_474 - local_47c;
              puVar8 = (undefined4 *)puVar9[0xd];
              local_48c = local_470 - local_478;
              local_46c = 0x800;
              local_450 = (undefined4 *)puVar9[0xe];
              local_468 = 0x400;
              if (puVar8 != local_450) {
                do {
                  (**(code **)(*(int *)*puVar8 + 4))
                            (&local_490,&local_46c,&local_388,puVar9[3],piVar4);
                  puVar8 = puVar8 + 1;
                } while (puVar8 != local_450);
              }
              local_484 = (float)local_46c;
              local_480 = (float)local_468;
              if ((_DAT_00fe1bc4 & 1) == 0) {
                _DAT_00fe1bc4 = _DAT_00fe1bc4 | 1;
                _atexit((_func_4879 *)&DAT_00bcec00);
              }
              FUN_007398a0(local_35c,puVar9[3],puVar9[0xb],puVar9[0xc],local_484,local_480);
              (**(code **)(*piVar4 + 0x104))(piVar4,0,local_458);
              (**(code **)(*piVar4 + 0x14c))(piVar4,4,10,local_35c,0x1c);
            }
          }
        }
        puVar9 = local_454 + 0x13;
        local_464 = local_464 + 1;
        in_ECX = local_45c;
        local_454 = puVar9;
      } while (local_464 < *(uint *)(local_45c + 0x4d30));
    }
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 8;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_8 = 0xffffffff;
    }
    puVar9 = local_460;
    FUN_00736180(&local_460);
    if ((local_458 == DAT_00fb7b80) || (local_458 == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    else {
      DAT_00fb7b90 = puVar9;
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 9;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb773c + 0x14))(DAT_00fb773c);
  }
  FUN_0055bb50(in_ECX);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


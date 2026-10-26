
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055a810(void)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int unaff_EDI;
  undefined1 local_3cc [16];
  undefined1 local_3bc [16];
  double local_3ac;
  int local_3a0;
  int local_39c;
  undefined4 local_398;
  undefined4 local_394;
  int local_390;
  int local_38c;
  undefined4 local_388;
  undefined4 local_384;
  undefined4 local_380;
  undefined4 local_37c;
  undefined4 local_378;
  float local_374;
  float local_370;
  undefined4 local_36c;
  undefined4 *local_368;
  undefined4 local_364;
  undefined4 *local_360;
  undefined1 local_35c [840];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009339e4;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(unaff_EDI + 0xc) != 0) {
    local_374 = *(float *)(unaff_EDI + 0x48);
    local_370 = *(float *)(unaff_EDI + 0x4c);
    local_36c = *(undefined4 *)(unaff_EDI + 0x50);
    iVar4 = (int)local_374;
    local_38c = (int)local_370;
    local_390 = iVar4;
    local_388 = FUN_008fed10(local_14);
    local_384 = FUN_008fed10();
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 0;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_8 = 0xffffffff;
    }
    local_378 = DAT_00fb7b90;
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 1;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_8 = 0xffffffff;
    }
    uVar1 = DAT_00e4b338;
    local_364 = DAT_00e4b338;
    FUN_00736180(&local_364);
    if ((local_360 == DAT_00fb7b80) || (local_360 == (undefined4 *)0xfffffff0)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    else {
      DAT_00fb7b90 = uVar1;
    }
    local_368 = *(undefined4 **)(unaff_EDI + 0x2c);
    puVar3 = *(undefined4 **)(unaff_EDI + 0x28);
    local_360 = puVar3;
    if (puVar3 != local_368) {
      do {
        local_3a0 = iVar4;
        local_360 = puVar3;
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8 = 2;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8 = 0xffffffff;
        }
        piVar2 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
        local_39c = (int)local_370;
        local_398 = FUN_008fed10();
        local_3ac = (double)(local_370 + 15.0);
        local_394 = FUN_008fed10();
        local_364 = 0;
        if (7 < (uint)puVar3[5]) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          local_8 = 3;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          local_8 = 0xffffffff;
        }
        iVar4 = FUN_007359e0(&DAT_00fb7b70,local_3bc,&local_3a0,&local_390,puVar3,0);
        if (iVar4 != 0) {
          if ((DAT_00fb7bc8 & 1) == 0) {
            DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
            local_8 = 4;
            FUN_00734ef0();
            _atexit((_func_4879 *)&LAB_00bcd4f0);
            local_8 = 0xffffffff;
          }
          local_380 = 0x45000000;
          local_37c = 0x44800000;
          if ((_DAT_00fe1bc4 & 1) == 0) {
            _DAT_00fe1bc4 = _DAT_00fe1bc4 | 1;
            _atexit((_func_4879 *)&DAT_00bcec00);
          }
          FUN_007396c0(local_35c,local_3cc,local_36c,local_380,local_37c);
          (**(code **)(*piVar2 + 0x104))(piVar2,0,local_364);
          (**(code **)(*piVar2 + 0x14c))(piVar2,4,2,local_35c,0x1c);
          local_370 = (float)local_3ac;
        }
        puVar3 = local_360 + 7;
        iVar4 = local_3a0;
        local_360 = puVar3;
      } while (puVar3 != local_368);
    }
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 5;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    uVar1 = local_378;
    FUN_00736180(&local_378);
    if ((local_368 == DAT_00fb7b80) || (local_368 == (undefined4 *)0xfffffff0)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    else {
      DAT_00fb7b90 = uVar1;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


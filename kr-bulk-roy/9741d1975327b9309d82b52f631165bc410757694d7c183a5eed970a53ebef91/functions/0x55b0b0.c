
void FUN_0055b0b0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  float10 fVar5;
  int *piVar6;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  int *piStack_2ac;
  undefined4 uStack_2a8;
  undefined4 uStack_2a4;
  int *piStack_2a0;
  undefined4 uStack_29c;
  undefined4 uStack_298;
  int *piStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  int *piStack_288;
  undefined4 uStack_284;
  undefined1 auStack_15c [8];
  int *local_154;
  undefined4 uStack_11c;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936560;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_15c;
  ExceptionList = &local_14;
  local_154 = param_1;
  if (param_1[4] != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_c = 0xffffffff;
    piVar3 = (int *)FUN_0079a5f0();
    (**(code **)(*piVar3 + 0xb4))();
    (**(code **)(*piVar3 + 0xb4))();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_24 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_24 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb773c + 0x10))();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_28 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_28 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb7738 + 0x14))();
    uStack_c8 = 0;
    uStack_cc = 0;
    uStack_d0 = 0;
    uStack_d4 = 0;
    uStack_dc = 0;
    uStack_e0 = 0;
    uStack_e4 = 0;
    uStack_e8 = 0;
    uStack_f0 = 0;
    uStack_f4 = 0;
    uStack_f8 = 0;
    uStack_fc = 0;
    uStack_c4 = 0x3f800000;
    uStack_d8 = 0x3f800000;
    uStack_ec = 0x3f800000;
    uStack_100 = 0x3f800000;
    (**(code **)(*piVar3 + 0xb0))();
    (**(code **)(*piVar3 + 0xb0))();
    (**(code **)(*piVar3 + 0xb0))();
    (**(code **)(*piVar3 + 0x164))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0x10c))();
    (**(code **)(*piVar3 + 0x10c))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0xe4))();
    (**(code **)(*piVar3 + 0x114))();
    (**(code **)(*piVar3 + 0x114))();
    (**(code **)(*piVar3 + 0xe4))();
    puVar1 = (undefined4 *)*param_1;
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      iVar4 = puVar2[2];
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        uStack_11c = 3;
        FUN_00798de0();
        uStack_284 = 0x55b41f;
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        uStack_11c = 0xffffffff;
      }
      if (DAT_00fb76e4 == 0) {
LAB_0055b460:
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          uStack_11c = 4;
          FUN_00798de0();
          uStack_284 = 0x55b48a;
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          uStack_11c = 0xffffffff;
        }
        uStack_284 = 0x55b4ac;
        (**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))();
        fVar5 = (float10)FUN_008ff870();
        if ((float)fVar5 <= 250.0) {
          FUN_0055a810();
        }
      }
      else {
        uStack_284 = *(undefined4 *)(iVar4 + 0x40);
        piStack_288 = *(int **)(iVar4 + 0x3c);
        uStack_28c = 0x55b458;
        iVar4 = FUN_00838800();
        if (iVar4 != 0) goto LAB_0055b460;
      }
    }
    uStack_284 = 0x1b;
    uStack_28c = 0x55b54d;
    piStack_288 = piVar3;
    (**(code **)(*piVar3 + 0xe4))();
    uStack_28c = 0;
    uStack_290 = 0xf;
    uStack_298 = 0x55b55c;
    piStack_294 = piVar3;
    (**(code **)(*piVar3 + 0xe4))();
    uStack_298 = 2;
    uStack_29c = 0x17;
    uStack_2a4 = 0x55b56b;
    piStack_2a0 = piVar3;
    (**(code **)(*piVar3 + 0xe4))();
    uStack_2a4 = 8;
    uStack_2a8 = 0x19;
    uStack_2b0 = 0x55b57a;
    piStack_2ac = piVar3;
    (**(code **)(*piVar3 + 0xe4))();
    uStack_2b0 = 1;
    uStack_2b4 = 0xce;
    (**(code **)(*piVar3 + 0xe4))(piVar3);
    (**(code **)(*piVar3 + 0xe4))(piVar3,0xd0,2);
    piVar6 = piVar3;
    (**(code **)(*piVar3 + 0xe4))(piVar3,0xcf,2);
    (**(code **)(*piVar3 + 0xe4))(piVar3,0x13,5);
    (**(code **)(*piVar3 + 0xe4))(piVar3,0x14,6);
    for (puVar2 = *(undefined4 **)*piVar6; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      iVar4 = puVar2[2];
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
      if ((DAT_00fb76e4 == 0) ||
         (iVar4 = FUN_00838800(*(undefined4 *)(iVar4 + 0x3c),*(undefined4 *)(iVar4 + 0x40),
                               *(undefined4 *)(iVar4 + 0x44)), iVar4 != 0)) {
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
        }
        (**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))(&uStack_2b4);
        fVar5 = (float10)FUN_008ff870();
        if ((float)fVar5 <= 250.0) {
          FUN_0055a6c0(puVar2[2]);
        }
      }
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    (**(code **)(*DAT_00fb773c + 0x14))(DAT_00fb773c);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_15c);
  return;
}


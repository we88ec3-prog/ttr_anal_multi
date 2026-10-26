
void FUN_006084b0(int param_1,char **param_2)

{
  code *pcVar1;
  char **ppcVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  char acStack_108 [4];
  undefined4 uStack_104;
  undefined *puStack_100;
  undefined1 *puStack_fc;
  char **ppcStack_f8;
  undefined ***pppuStack_f4;
  undefined1 auStack_dc [4];
  char *local_d8;
  int local_d4;
  uint local_d0;
  uint local_cc;
  int local_c8;
  int local_c4;
  undefined4 *local_c0;
  char **local_bc;
  int local_b8;
  undefined **local_b4 [3];
  uint local_a8;
  undefined4 local_98;
  uint local_94;
  undefined1 local_8c [44];
  int local_60;
  undefined1 local_54 [20];
  uint local_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093cdf7;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_dc;
  ExceptionList = &local_14;
  pppuStack_f4 = (undefined ***)&DAT_00bed1fc;
  local_b8 = param_1;
  local_bc = param_2;
  *(undefined1 *)(param_1 + 0x148) = 0;
  ppcStack_f8 = (char **)0x608518;
  FUN_00402160();
  pppuStack_f4 = *(undefined ****)(param_1 + 0x14c);
  puStack_fc = (undefined1 *)(param_1 + 0x14c);
  ppcStack_f8 = &local_d8;
  local_c4 = 0;
  puStack_100 = (undefined *)0x60853b;
  FUN_004d7fe0();
  if ((DAT_00fe1de0 & 1) == 0) {
    DAT_00fe1de0 = DAT_00fe1de0 | 1;
    local_c = 0;
    FUN_00519060();
    pppuStack_f4 = (undefined ***)0x608561;
    _atexit(FUN_00bcef60);
    local_c = 0xffffffff;
  }
  local_d0 = *(undefined4 *)(param_1 + 0x120);
  pppuStack_f4 = (undefined ***)0x60858c;
  FUN_00519680();
  if (local_cc == DAT_00fe1de8) {
    local_c8 = 0;
  }
  else {
    local_c8 = local_cc + 0x10;
  }
  local_d0 = 0;
  uVar6 = *(int *)(local_c8 + 0x1c) - *(int *)(local_c8 + 0x18) >> 3;
  local_cc = uVar6;
  if (uVar6 != 0) {
    do {
      local_c0 = (undefined4 *)(*(int *)(local_c8 + 0x18) + local_d0 * 8);
      if ((DAT_00f8d9a8 & 1) == 0) {
        DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
        local_c = 1;
        DAT_00f8d9b4 = 0;
        pppuStack_f4 = (undefined ***)0x608682;
        iVar4 = FUN_00891268();
        if (iVar4 == 0) {
          local_d8 = (char *)0x0;
          pppuStack_f4 = (undefined ***)0x608844;
          std::exception::exception((exception *)local_b4,&local_d8);
          pppuStack_f4 = local_b4;
          local_b4[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          ppcStack_f8 = (char **)0x60885b;
          __CxxThrowException_8();
        }
        DAT_00f8d9b0 = iVar4;
        *(int *)iVar4 = iVar4;
        *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
        *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
        *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
        *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
        local_c = CONCAT31(local_c._1_3_,2);
        pppuStack_f4 = (undefined ***)0x6086ca;
        FUN_00521080();
        pppuStack_f4 = (undefined ***)0x6086d4;
        _atexit((_func_4879 *)&LAB_00bccc50);
        local_c = 0xffffffff;
      }
      local_c0 = (undefined4 *)*local_c0;
      pppuStack_f4 = (undefined ***)0x6086ff;
      FUN_008438c0();
      if ((local_d4 != DAT_00f8d9b0) &&
         (puVar5 = *(undefined4 **)(local_d4 + 0x10), uVar6 = local_cc, puVar5 != (undefined4 *)0x0)
         ) {
        pppuStack_f4 = (undefined ***)&DAT_00bed1fc;
        local_94 = 7;
        local_98 = 0;
        local_a8 = local_a8 & 0xffff0000;
        ppcStack_f8 = (char **)0x608740;
        FUN_00402160();
        local_c._1_3_ = 0;
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c._0_1_ = 4;
          local_c._1_3_ = 0;
          FUN_004e1590();
          pppuStack_f4 = (undefined ***)0x608772;
          _atexit((_func_4879 *)&LAB_00bccc80);
        }
        local_c._0_1_ = 3;
        pppuStack_f4 = (undefined ***)*puVar5;
        ppcStack_f8 = local_bc;
        puStack_fc = (undefined1 *)DAT_00f94300;
        puStack_100 = (undefined *)0x608796;
        cVar3 = FUN_00509670();
        if (cVar3 != '\0') {
          *(undefined1 *)(param_1 + 0x148) = 1;
          FUN_0049c120();
          ppcStack_f8 = (char **)FUN_004068f0();
          pppuStack_f4 = (undefined ***)0x0;
          local_c = CONCAT31(local_c._1_3_,5);
          puStack_fc = (undefined1 *)0x6087d7;
          FUN_004041f0();
          local_c4 = local_c4 + 1;
          if (7 < local_40) {
            pppuStack_f4 = (undefined ***)0x6087f2;
            FUN_0089120c();
          }
        }
        local_c = 0xffffffff;
        uVar6 = local_cc;
        if (7 < local_94) {
          pppuStack_f4 = (undefined ***)0x608811;
          FUN_0089120c();
          uVar6 = local_cc;
        }
      }
      local_d0 = local_d0 + 1;
    } while (local_d0 < uVar6);
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 6;
    pppuStack_f4 = (undefined ***)0x6085e9;
    FUN_00584c40();
    pppuStack_f4 = (undefined ***)0x6085f3;
    _atexit(FUN_00bcf370);
    local_c = 0xffffffff;
  }
  local_d8 = &DAT_000001a6;
  pppuStack_f4 = (undefined ***)0x60861c;
  FUN_005740f0();
  if (local_d4 == DAT_00fe5b10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pppuStack_f4 = (undefined ***)0x60886b;
  FUN_007572f0();
  local_c = 7;
  local_d8 = (char *)0x0;
  pppuStack_f4 = (undefined ***)0x608891;
  FUN_00848020();
  if (local_d4 != local_60) {
    *(undefined4 *)(local_d4 + 0x18) = 0xffffbb00;
    *(undefined1 *)(local_d4 + 0x1c) = 1;
    ppcStack_f8 = *(char ***)(local_d4 + 0x10);
    pppuStack_f4 = (undefined ***)(*(int *)(local_d4 + 0x14) - (int)ppcStack_f8);
    puStack_fc = (undefined1 *)0x6088bf;
    FUN_007591a0();
  }
  ppcVar2 = local_bc;
  local_d8 = acStack_108;
  FUN_00412df0();
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 9;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  local_c._0_1_ = 8;
  local_d8 = &DAT_000001a7;
  FUN_005740f0(&local_d8);
  if (local_d4 == DAT_00fe5b10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar5 = (undefined4 *)(local_d4 + 0x10);
  if (7 < *(uint *)(local_d4 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_c._0_1_ = 7;
  FUN_00424c80(puVar5);
  local_c._0_1_ = 10;
  pppuStack_f4 = (undefined ***)0x608989;
  FUN_00759ac0();
  local_c._0_1_ = 7;
  if (7 < local_94) {
    pppuStack_f4 = (undefined ***)0x6089a1;
    FUN_0089120c();
  }
  pppuStack_f4 = (undefined ***)0x6089ab;
  puVar5 = (undefined4 *)FUN_00891268();
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5[5] = ppcVar2;
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0xffffffff;
    puVar5[3] = 0;
    puVar5[4] = 0xf440c;
    *puVar5 = FoxUI::FXUIEventI1::vftable;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 0xb;
    pppuStack_f4 = (undefined ***)0x6089f6;
    FUN_00584c40();
    pppuStack_f4 = (undefined ***)0x608a00;
    _atexit(FUN_00bcf370);
    local_c._0_1_ = 7;
  }
  local_d8 = (char *)0x196;
  pppuStack_f4 = (undefined ***)0x608a26;
  FUN_005740f0();
  if (local_d4 != DAT_00fe5b10) {
    pppuStack_f4 = (undefined ***)0x608a51;
    FUN_007572f0();
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c._0_1_ = 0xd;
      FUN_0074d990();
      pppuStack_f4 = (undefined ***)0x608a81;
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    local_c._0_1_ = 0xc;
    ppcStack_f8 = (char **)local_54;
    puStack_fc = local_8c;
    puStack_100 = &DAT_00f94810;
    uStack_104 = 0x608aad;
    pppuStack_f4 = (undefined ***)puVar5;
    FUN_007531a0();
    local_c = CONCAT31(local_c._1_3_,7);
    pppuStack_f4 = (undefined ***)0x608ac2;
    FUN_00757640();
    local_c = 0xffffffff;
    pppuStack_f4 = (undefined ***)0x608ad7;
    FUN_00757640();
    ExceptionList = local_14;
    __security_check_cookie(local_1c ^ (uint)auStack_dc);
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


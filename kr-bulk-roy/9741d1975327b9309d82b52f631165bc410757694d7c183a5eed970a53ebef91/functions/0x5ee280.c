
void FUN_005ee280(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 **in_ECX;
  undefined2 auStack_f8 [8];
  undefined4 uStack_e8;
  undefined4 *puStack_e4;
  undefined4 **ppuStack_e0;
  undefined4 **ppuStack_dc;
  undefined4 **ppuStack_d8;
  uint uStack_d4;
  undefined4 local_c4;
  undefined1 *local_c0;
  undefined4 local_bc;
  undefined4 local_ac;
  uint local_a8;
  undefined4 *local_a0 [5];
  uint local_8c;
  undefined4 local_84;
  undefined4 local_74;
  uint local_70;
  undefined4 local_68;
  undefined4 local_58;
  uint local_54;
  undefined4 *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_8 = 0xff;
  uStack_7 = 0xffffff;
  puStack_c = &LAB_00948fb4;
  local_10 = ExceptionList;
  uStack_d4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uStack_d4;
  if (*in_ECX[0x61] == 0) goto LAB_005ee80d;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (undefined4 *)((uint)local_4c[0] & 0xffff0000);
  ppuStack_d8 = local_4c;
  local_8 = 0;
  uStack_7 = 0;
  ppuStack_dc = (undefined4 **)0x5ee2de;
  FUN_005e2440();
  ppuStack_d8 = local_4c;
  ppuStack_e0 = (undefined4 **)0x5ee2e8;
  ppuStack_dc = in_ECX;
  FUN_005e2510();
  puVar1 = in_ECX[0x61];
  if (puVar1 != (undefined4 *)0x0) {
    switch(puVar1[2]) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 0xd:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x1b:
    case 0x1f:
    case 0x20:
    case 0x24:
    case 0x25:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      ppuStack_d8 = (undefined4 **)puVar1[1];
      break;
    default:
      goto switchD_005ee302_caseD_5;
    case 0x15:
      ppuStack_d8 = (undefined4 **)puVar1[1];
    }
    ppuStack_dc = local_4c;
    ppuStack_e0 = (undefined4 **)0x5ee326;
    FUN_005e4b70();
switchD_005ee302_caseD_5:
    ppuStack_dc = local_4c;
    ppuStack_e0 = (undefined4 **)0x5ee330;
    ppuStack_d8 = (undefined4 **)puVar1;
    FUN_005e3bc0();
    ppuStack_dc = local_4c;
    ppuStack_e0 = (undefined4 **)0x5ee33a;
    ppuStack_d8 = (undefined4 **)puVar1;
    FUN_005e4340();
  }
  if (in_ECX[0x61][0x31] != 0) {
    ppuStack_d8 = (undefined4 **)0x5ee36d;
    ppuStack_e0 = (undefined4 **)FUN_004ed610();
    ppuStack_d8 = (undefined4 **)0xffffffff;
    ppuStack_dc = (undefined4 **)0x0;
    local_8 = 1;
    puStack_e4 = (undefined4 *)0x5ee37e;
    FUN_004041f0();
    local_8 = 0;
    if (7 < local_8c) {
      ppuStack_d8 = (undefined4 **)local_a0[0];
      ppuStack_dc = (undefined4 **)0x5ee396;
      FUN_0089120c();
    }
  }
  if (in_ECX[0x61][0x38] != 0) {
    ppuStack_d8 = (undefined4 **)0x5ee3c6;
    ppuStack_e0 = (undefined4 **)FUN_004ed610();
    ppuStack_d8 = (undefined4 **)0xffffffff;
    ppuStack_dc = (undefined4 **)0x0;
    local_8 = 2;
    puStack_e4 = (undefined4 *)0x5ee3d7;
    FUN_004041f0();
    local_8 = 0;
    if (7 < local_8c) {
      ppuStack_d8 = (undefined4 **)local_a0[0];
      ppuStack_dc = (undefined4 **)0x5ee3ef;
      FUN_0089120c();
    }
  }
  ppuStack_d8 = (undefined4 **)in_ECX[0x60];
  if (ppuStack_d8 != (undefined4 **)0x0) {
    ppuStack_dc = (undefined4 **)0x5ee405;
    FUN_005e86e0();
  }
  ppuStack_d8 = (undefined4 **)in_ECX[0x61];
  ppuStack_dc = local_4c;
  ppuStack_e0 = (undefined4 **)0x5ee41a;
  FUN_005e8c10();
  ppuStack_d8 = (undefined4 **)0xffffffff;
  ppuStack_dc = (undefined4 **)0x0;
  ppuStack_e0 = local_4c;
  local_1c = 7;
  local_20 = 0;
  local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
  puStack_e4 = (undefined4 *)0x5ee43d;
  FUN_004026e0();
  puVar1 = in_ECX[0x66];
  local_8 = 3;
  ppuStack_d8 = (undefined4 **)0x5ee452;
  FUN_007578f0();
  ppuStack_d8 = (undefined4 **)0x7d;
  ppuStack_dc = (undefined4 **)0x7b;
  ppuStack_e0 = (undefined4 **)&local_30;
  uStack_e8 = 0x5ee460;
  puStack_e4 = puVar1 + 0x3a;
  FUN_00759ed0();
  local_8 = 0;
  if (7 < local_1c) {
    ppuStack_d8 = (undefined4 **)local_30;
    ppuStack_dc = (undefined4 **)0x5ee472;
    FUN_0089120c();
  }
  if (in_ECX[0x61][0x18] == 0) {
    ppuStack_d8 = (undefined4 **)0x0;
    ppuStack_dc = (undefined4 **)0x5ee83b;
    (**(code **)(*in_ECX[0x6d] + 0x94))();
    ppuStack_dc = (undefined4 **)0x0;
    ppuStack_e0 = (undefined4 **)0x5ee84d;
    (**(code **)(*in_ECX[0x6e] + 0x94))();
    ppuStack_e0 = (undefined4 **)0x0;
    puStack_e4 = (undefined4 *)0x5ee85f;
    (**(code **)(*in_ECX[0x6f] + 0x94))();
    puStack_e4 = (undefined4 *)0x0;
    uStack_e8 = 0x5ee873;
    (**(code **)(*in_ECX[0x70] + 0x94))();
  }
  else {
    local_c4 = in_ECX[0x61][0x18];
    ppuStack_d8 = (undefined4 **)0x5ee493;
    iVar2 = FUN_004034e0();
    ppuStack_d8 = (undefined4 **)&local_c4;
    ppuStack_dc = (undefined4 **)0x5ee4a9;
    FUN_008438c0();
    if ((local_c0 != *(undefined1 **)(iVar2 + 4)) &&
       (puVar1 = *(undefined4 **)(local_c0 + 0x10), puVar1 != (undefined4 *)0x0)) {
      ppuStack_d8 = (undefined4 **)(puVar1 + 0x26);
      if (7 < (uint)puVar1[0x2b]) {
        ppuStack_d8 = (undefined4 **)*ppuStack_d8;
      }
      ppuStack_dc = (undefined4 **)0x5ee4e1;
      FUN_00402250();
      local_8 = 4;
      ppuStack_dc = (undefined4 **)puVar1[2];
      ppuStack_d8 = (undefined4 **)0x0;
      ppuStack_e0 = (undefined4 **)0x5ee4f6;
      FUN_005e1e00();
      ppuStack_d8 = (undefined4 **)0x7d;
      ppuStack_dc = (undefined4 **)0x7b;
      local_c0 = (undefined1 *)auStack_f8;
      puStack_e4 = (undefined4 *)0x7;
      uStack_e8 = 0;
      auStack_f8[0] = 0;
      FUN_004026e0(local_a0,0,0xffffffff);
      FUN_00759e60();
      local_a8 = 7;
      local_ac = 0;
      local_bc = (undefined4 *)((uint)local_bc._2_2_ << 0x10);
      ppuStack_d8 = (undefined4 **)&local_bc;
      local_8 = 5;
      ppuStack_dc = (undefined4 **)0x5ee561;
      FUN_005e2160();
      ppuStack_d8 = (undefined4 **)0x7d;
      ppuStack_dc = (undefined4 **)0x7b;
      local_c0 = (undefined1 *)auStack_f8;
      puStack_e4 = (undefined4 *)0x7;
      uStack_e8 = 0;
      auStack_f8[0] = 0;
      FUN_004026e0(&local_bc,0,0xffffffff);
      FUN_00759e60();
      local_54 = 7;
      local_58 = 0;
      local_68 = (undefined4 *)((uint)local_68._2_2_ << 0x10);
      local_1c = 7;
      local_20 = 0;
      local_30 = (undefined4 *)((uint)local_30 & 0xffff0000);
      local_70 = 7;
      local_74 = 0;
      local_84 = (undefined4 *)((uint)local_84._2_2_ << 0x10);
      local_8 = 8;
      ppuStack_d8 = (undefined4 **)puVar1[0x10];
      ppuStack_dc = (undefined4 **)puVar1[10];
      puStack_e4 = &local_30;
      uStack_e8 = 0x5ee5e1;
      ppuStack_e0 = (undefined4 **)puVar1;
      FUN_005e7580();
      ppuStack_d8 = (undefined4 **)puVar1[0x13];
      ppuStack_dc = (undefined4 **)puVar1[0xd];
      puStack_e4 = &local_30;
      uStack_e8 = 0x5ee5f6;
      ppuStack_e0 = (undefined4 **)puVar1;
      FUN_005e7920();
      ppuStack_dc = (undefined4 **)&local_84;
      ppuStack_e0 = (undefined4 **)0x5ee600;
      ppuStack_d8 = (undefined4 **)puVar1;
      FUN_005e1c60();
      ppuStack_d8 = (undefined4 **)0x5ee608;
      FUN_005e4af0();
      ppuStack_dc = (undefined4 **)0x5ee612;
      ppuStack_d8 = (undefined4 **)&local_84;
      FUN_005e5ee0();
      ppuStack_dc = (undefined4 **)0x5ee61c;
      ppuStack_d8 = (undefined4 **)&local_84;
      FUN_005e2770();
      ppuStack_d8 = (undefined4 **)0xffffffff;
      ppuStack_dc = (undefined4 **)0x0;
      ppuStack_e0 = (undefined4 **)&local_30;
      puStack_e4 = (undefined4 *)0x5ee62c;
      FUN_004041f0();
      if (puVar1[0x31] != 0) {
        ppuStack_d8 = (undefined4 **)&local_68;
        ppuStack_dc = (undefined4 **)0x5ee643;
        FUN_00404420();
        ppuStack_d8 = (undefined4 **)&local_68;
        ppuStack_dc = (undefined4 **)0x5ee660;
        FUN_00404420();
        ppuStack_d8 = (undefined4 **)&local_68;
        ppuStack_dc = (undefined4 **)0x5ee66e;
        FUN_00404420();
      }
      if (puVar1[0x38] != 0) {
        ppuStack_d8 = (undefined4 **)&local_68;
        ppuStack_dc = (undefined4 **)0x5ee68c;
        FUN_00404420();
        ppuStack_d8 = (undefined4 **)&local_68;
        ppuStack_dc = (undefined4 **)0x5ee6a7;
        FUN_00404420();
        ppuStack_d8 = (undefined4 **)&local_68;
        ppuStack_dc = (undefined4 **)0x5ee6b5;
        FUN_00404420();
      }
      ppuStack_d8 = (undefined4 **)0xffffffff;
      ppuStack_dc = (undefined4 **)0x0;
      ppuStack_e0 = (undefined4 **)&local_84;
      puStack_e4 = (undefined4 *)0x5ee6c5;
      FUN_004041f0();
      ppuStack_d8 = (undefined4 **)*puVar1;
      ppuStack_dc = (undefined4 **)0x5ee6cd;
      iVar2 = FUN_005e1bc0();
      if (iVar2 == 0) {
        ppuStack_d8 = (undefined4 **)0x5ee6d6;
        FUN_00403470();
      }
      ppuStack_d8 = (undefined4 **)0x5ee6e6;
      FUN_00745060();
      ppuStack_d8 = (undefined4 **)0x7d;
      ppuStack_dc = (undefined4 **)0x7b;
      local_c0 = (undefined1 *)auStack_f8;
      puStack_e4 = (undefined4 *)0x7;
      uStack_e8 = 0;
      auStack_f8[0] = 0;
      FUN_004026e0(&local_68,0,0xffffffff);
      FUN_00759e60();
      ppuStack_d8 = (undefined4 **)0x1;
      ppuStack_dc = (undefined4 **)0x5ee738;
      (**(code **)(*in_ECX[0x6d] + 0x94))();
      ppuStack_dc = (undefined4 **)0x1;
      ppuStack_e0 = (undefined4 **)0x5ee74a;
      (**(code **)(*in_ECX[0x6e] + 0x94))();
      ppuStack_e0 = (undefined4 **)0x1;
      puStack_e4 = (undefined4 *)0x5ee75c;
      (**(code **)(*in_ECX[0x6f] + 0x94))();
      puStack_e4 = (undefined4 *)0x1;
      uStack_e8 = 0x5ee770;
      (**(code **)(*in_ECX[0x70] + 0x94))();
      if (7 < local_70) {
        ppuStack_d8 = (undefined4 **)local_84;
        ppuStack_dc = (undefined4 **)0x5ee77e;
        FUN_0089120c();
      }
      local_70 = 7;
      local_74 = 0;
      local_84 = (undefined4 *)((uint)local_84 & 0xffff0000);
      if (7 < local_1c) {
        ppuStack_d8 = (undefined4 **)local_30;
        ppuStack_dc = (undefined4 **)0x5ee79d;
        FUN_0089120c();
      }
      local_1c = 7;
      local_20 = 0;
      local_30 = (undefined4 *)((uint)local_30 & 0xffff0000);
      if (7 < local_54) {
        ppuStack_d8 = (undefined4 **)local_68;
        ppuStack_dc = (undefined4 **)0x5ee7ba;
        FUN_0089120c();
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (undefined4 *)((uint)local_68 & 0xffff0000);
      if (7 < local_a8) {
        ppuStack_d8 = (undefined4 **)local_bc;
        ppuStack_dc = (undefined4 **)0x5ee7dd;
        FUN_0089120c();
      }
      if (7 < local_8c) {
        ppuStack_d8 = (undefined4 **)local_a0[0];
        ppuStack_dc = (undefined4 **)0x5ee7f4;
        FUN_0089120c();
      }
    }
  }
  if (7 < local_38) {
    ppuStack_d8 = (undefined4 **)local_4c[0];
    ppuStack_dc = (undefined4 **)0x5ee80a;
    FUN_0089120c();
  }
LAB_005ee80d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


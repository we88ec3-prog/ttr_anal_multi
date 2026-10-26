
void FUN_007e46c0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EDI;
  int iStack_f8;
  int local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  int local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84 [4];
  undefined4 local_74;
  undefined4 local_64;
  undefined4 local_50 [4];
  undefined4 local_40;
  undefined4 local_30;
  undefined1 auStack_20 [4];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&iStack_f8;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0x3f800000;
  local_b0 = *(undefined4 *)(unaff_EDI + 0x28);
  local_ac = *(undefined4 *)(unaff_EDI + 0x2c);
  iVar2 = (*(int *)(unaff_EDI + 0x5c) - *(int *)(unaff_EDI + 0x58)) / 0x2c;
  local_a8 = *(undefined4 *)(unaff_EDI + 0x30);
  local_88 = 1;
  _memset(local_84,0,0x34);
  local_64 = 0x3f800000;
  local_74 = 0x3f800000;
  local_84[0] = 0x3f800000;
  FUN_00790dc0(*(undefined4 *)(unaff_EDI + 0x34));
  FUN_00790e90(*(undefined4 *)(unaff_EDI + 0x38));
  FUN_00790f60(*(undefined4 *)(unaff_EDI + 0x3c));
  FUN_00780890();
  local_8c = *(undefined4 *)(unaff_EDI + 0x48);
  local_98 = local_10;
  local_94 = *(undefined4 *)(unaff_EDI + 0x40);
  local_90 = *(undefined4 *)(unaff_EDI + 0x44);
  local_a4 = local_1c;
  local_a0 = local_18;
  local_9c = local_14;
  if (iVar2 != 0) {
    local_f4 = 0;
    local_c4 = iVar2;
    do {
      puVar1 = (undefined4 *)(local_f4 + *(int *)(unaff_EDI + 0x58));
      local_c8 = 1;
      local_e4 = 0;
      local_e0 = 0;
      local_dc = 0;
      local_d8 = 0x3f800000;
      local_d4 = 0x3f800000;
      local_d0 = 0x3f800000;
      local_cc = 0x3f800000;
      local_f0 = *puVar1;
      local_c0 = 0;
      local_bc = 0;
      local_ec = puVar1[1];
      local_b8 = 0;
      local_e8 = puVar1[2];
      local_b4 = 0x3f800000;
      _memset(local_50,0,0x34);
      local_30 = 0x3f800000;
      local_40 = 0x3f800000;
      local_50[0] = 0x3f800000;
      FUN_00790dc0(puVar1[3]);
      FUN_00790e90(puVar1[4]);
      FUN_00790f60(puVar1[5]);
      FUN_00780890();
      local_d8 = local_b4;
      iVar2 = local_f4 + *(int *)(unaff_EDI + 0x58);
      local_e4 = local_c0;
      local_e0 = local_bc;
      local_dc = local_b8;
      local_d4 = *(undefined4 *)(iVar2 + 0x18);
      local_d0 = *(undefined4 *)(iVar2 + 0x1c);
      local_cc = *(undefined4 *)(iVar2 + 0x20);
      puVar1 = (undefined4 *)FUN_0077e910(local_84,&local_f0,&local_b0);
      if (&local_f0 != puVar1) {
        local_f0 = *puVar1;
        local_ec = puVar1[1];
        local_e8 = puVar1[2];
        if (&local_e4 != puVar1 + 3) {
          local_d8 = puVar1[6];
          local_e4 = puVar1[3];
          local_e0 = puVar1[4];
          local_dc = puVar1[5];
        }
        local_d4 = puVar1[7];
        local_d0 = puVar1[8];
        local_cc = puVar1[9];
        local_c8 = puVar1[10];
      }
      FUN_007cc3a0(&local_14,&local_1c,&local_18);
      (**(code **)(**(int **)(iVar2 + 0x28) + 0x10))(&local_f0);
      iVar2 = iStack_f8;
      (**(code **)(**(int **)(iStack_f8 + 0x28 + *(int *)(unaff_EDI + 0x58)) + 0x14))(auStack_20);
      (**(code **)(**(int **)(iVar2 + 0x28 + *(int *)(unaff_EDI + 0x58)) + 0x18))(&local_dc);
      local_f4 = iVar2 + 0x2c;
      local_c4 = local_c4 + -1;
    } while (local_c4 != 0);
    *(undefined4 *)(unaff_EDI + 0x4c) = 0;
    __security_check_cookie(local_c ^ (uint)&iStack_f8);
    return;
  }
  *(undefined4 *)(unaff_EDI + 0x4c) = 0;
  __security_check_cookie(local_c ^ (uint)&iStack_f8);
  return;
}


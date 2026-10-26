
void FUN_0048bb80(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint local_8c;
  int local_88;
  undefined4 *local_84;
  int local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_8c;
  local_80 = param_1;
  local_7c = param_2;
  local_84 = param_3;
  local_8c = param_2;
  local_74 = 0;
  local_78 = 0;
  local_70 = 0x67452301;
  local_6c = 0xefcdab89;
  local_68 = 0x98badcfe;
  local_64 = 0x10325476;
  if (0x4000 < param_2) {
    iVar2 = (param_2 - 0x4001 >> 0xe) + 1;
    do {
      local_88 = iVar2;
      if ((local_78 & 0x1f8) == 0) {
        if (local_78 + 0x20000 < local_78) {
          local_74 = local_74 + 1;
        }
        iVar2 = 0x100;
        local_78 = local_78 + 0x20000;
        do {
          FUN_00809ba0(&local_70);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      else {
        FUN_008098e0(param_1);
        local_88 = iVar2;
      }
      local_8c = local_8c - 0x4000;
      param_1 = param_1 + 0x4000;
      iVar2 = local_88 + -1;
    } while (iVar2 != 0);
    local_88 = 0;
  }
  puVar1 = local_84;
  FUN_00809a10(local_8c);
  FUN_00809a70();
  *puVar1 = local_20;
  puVar1[1] = local_1c;
  puVar1[2] = local_18;
  puVar1[3] = local_14;
  __security_check_cookie(local_c ^ (uint)&local_8c);
  return;
}



void FUN_008bd520(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *in_EDX;
  int iVar2;
  int local_ac [9];
  undefined4 local_88;
  int local_7c;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  char local_52;
  char local_51;
  undefined4 local_50 [9];
  int local_2c [9];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_68 = *in_EDX;
  iVar2 = 0;
  local_64 = param_3;
  local_58 = 2;
  local_51 = '\0';
  local_5c = 0;
  FUN_008ba9e0();
  do {
    local_52 = FUN_008b9780();
    if (((local_52 == '\0') || (local_51 == '\0')) && (local_2c[iVar2] == 0)) {
      local_7c = local_ac[iVar2];
      local_88 = 4;
      if (local_7c == 0) {
        local_7c = *(int *)(param_3 + 0xc);
      }
      local_58 = FUN_008bb080();
      uVar1 = local_5c;
      if ((local_52 != '\0') && ((char)local_58 == 'Q')) {
        local_51 = '\x01';
      }
      if (local_58 == 0) {
        local_58 = FUN_008bd330(local_50[iVar2],param_2,local_60);
        FUN_008ba2d0(uVar1,0);
        if (local_58 == 0) break;
        if (local_52 != '\0') {
          local_51 = '\x01';
        }
      }
    }
    iVar2 = iVar2 + 1;
    param_3 = local_64;
  } while (iVar2 < 9);
  uVar1 = local_68;
  iVar2 = 0;
  do {
    if (local_ac[iVar2] != 0) {
      FUN_008b9f80(uVar1,local_ac[iVar2]);
      local_ac[iVar2] = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 9);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


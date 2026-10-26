
void FUN_00733c30(undefined4 *param_1,size_t param_2)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  size_t _Size;
  undefined4 *local_48c;
  int local_488;
  undefined4 *local_484;
  undefined4 *local_480;
  size_t local_47c;
  uint local_478;
  int local_474;
  undefined4 local_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined4 local_464;
  undefined4 local_420;
  undefined4 local_41c;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410 [257];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_48c;
  local_484 = param_1;
  local_474 = 0;
  local_478 = 0;
  local_470 = 0x67452301;
  local_46c = 0xefcdab89;
  local_468 = 0x98badcfe;
  local_464 = 0x10325476;
  local_480 = in_ECX;
  _memset(local_410,0,0x400);
  _Size = param_2;
  if (0x400 < (int)param_2) {
    local_488 = (param_2 - 0x401 >> 10) + 1;
    local_47c = param_2 + local_488 * -0x400;
    local_48c = local_484;
    do {
      puVar2 = local_48c;
      puVar3 = local_410;
      for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      if ((local_478 & 0x1f8) == 0) {
        if (local_478 + 0x2000 < local_478) {
          local_474 = local_474 + 1;
        }
        iVar1 = 0x10;
        local_478 = local_478 + 0x2000;
        do {
          FUN_00809ba0(&local_470);
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      else {
        FUN_008098e0(local_410);
      }
      local_48c = local_48c + 0x100;
      local_488 = local_488 + -1;
    } while (local_488 != 0);
    local_488 = 0;
    in_ECX = local_480;
    _Size = local_47c;
  }
  FID_conflict__memcpy(local_410,(void *)((param_2 - _Size) + (int)local_484),_Size);
  FUN_00809a10(_Size);
  FUN_00809a70();
  *in_ECX = local_420;
  in_ECX[1] = local_41c;
  in_ECX[2] = local_418;
  in_ECX[3] = local_414;
  __security_check_cookie(local_c ^ (uint)&local_48c);
  return;
}


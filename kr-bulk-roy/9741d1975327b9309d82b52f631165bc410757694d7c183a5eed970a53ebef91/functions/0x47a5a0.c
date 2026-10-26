
void FUN_0047a5a0(FILE *param_1)

{
  size_t _Size;
  int iVar1;
  byte *pbVar2;
  undefined4 *in_ECX;
  undefined4 local_d4;
  byte local_d0 [100];
  byte local_6c [100];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((uint)in_ECX[4] < 0x33) {
    _Size = in_ECX[4] * 2;
    local_6c[0] = 0;
    _memset(local_6c + 1,0,99);
    if (7 < (uint)in_ECX[5]) {
      in_ECX = (undefined4 *)*in_ECX;
    }
    FID_conflict__memcpy(local_6c,in_ECX,_Size);
    iVar1 = 0;
    local_d4 = 0;
    if (0 < (int)_Size) {
      local_d4._0_2_ = 0;
      do {
        pbVar2 = local_6c + iVar1;
        iVar1 = iVar1 + 1;
        local_d4._0_2_ = (ushort)local_d4 + *pbVar2;
      } while (iVar1 < (int)_Size);
      local_d4 = (uint)(ushort)local_d4;
    }
    local_d0[0] = 0x1b;
    _memset(local_d0 + 1,0,99);
    iVar1 = 1;
    do {
      local_d0[iVar1] = local_d0[iVar1 + -1] * -0x3b;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 100);
    iVar1 = 0;
    if (0 < (int)_Size) {
      do {
        local_6c[iVar1] = local_6c[iVar1] ^ local_d0[iVar1];
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)_Size);
    }
    iVar1 = 100;
    pbVar2 = local_d0;
    do {
      *pbVar2 = 0;
      pbVar2 = pbVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    _fwrite(&local_d4,2,1,param_1);
    _fwrite(local_6c,_Size,1,param_1);
  }
  _fclose(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


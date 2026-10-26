
int FUN_008b9ec0(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint local_c;
  uint local_8;
  
  local_c = *param_1;
  local_8 = param_1[1];
  uVar1 = local_8;
  if ((local_c != 0) && (uVar1 = local_c, local_8 != 0)) {
    iVar2 = FUN_008b9d40();
    FUN_008b9d90(&local_c);
    iVar3 = FUN_008b9ce0();
    bVar4 = (byte)iVar2;
    if (iVar2 < 1) {
      return iVar3 << (-bVar4 & 0x1f);
    }
    return (1 << (bVar4 - 1 & 0x1f)) + iVar3 >> (bVar4 & 0x1f);
  }
  return (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
}


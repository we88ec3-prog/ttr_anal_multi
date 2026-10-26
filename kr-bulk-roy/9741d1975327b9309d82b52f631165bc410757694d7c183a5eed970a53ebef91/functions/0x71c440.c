
uint FUN_0071c440(void)

{
  uint *puVar1;
  byte *pbVar2;
  undefined4 *in_ECX;
  undefined4 local_8;
  
  puVar1 = (uint *)in_ECX[1];
  if (puVar1 != (uint *)0x0) {
    local_8 = 0;
    in_ECX = &local_8;
  }
  pbVar2 = (byte *)*in_ECX;
  if (pbVar2 == (byte *)0x0) {
    if (puVar1 != (uint *)0x0) {
      if ((*puVar1 & 0x10) == 0) {
        return puVar1[1];
      }
      if ((*puVar1 & 8) == 0) {
        return puVar1[2];
      }
    }
  }
  else {
    if ((*(uint *)(pbVar2 + 8) != 0) && ((*pbVar2 & 0x10) == 0)) {
      return *(uint *)(pbVar2 + 8);
    }
    if ((*(uint *)(pbVar2 + 0xc) != 0) && ((*pbVar2 & 8) == 0)) {
      return *(uint *)(pbVar2 + 0xc);
    }
  }
  return 0;
}


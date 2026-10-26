
undefined4 FUN_00731c90(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *unaff_ESI;
  int iVar5;
  int local_8;
  
  iVar5 = 0;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  local_8 = 0;
  do {
    if (0x17 < local_8) {
      return 0;
    }
    bVar2 = *(byte *)(iVar5 + param_1);
    if ((char)bVar2 < '\0') {
      if ((bVar2 & 0xe0) == 0xc0) {
        puVar4 = unaff_ESI;
        if (7 < (uint)unaff_ESI[5]) {
          puVar4 = (undefined4 *)*unaff_ESI;
        }
        iVar1 = (int)puVar4 + unaff_ESI[4] * 2;
        puVar4 = unaff_ESI;
        if (7 < (uint)unaff_ESI[5]) {
          puVar4 = (undefined4 *)*unaff_ESI;
        }
        iVar3 = 0;
        if (iVar1 != 0) {
          iVar3 = iVar1 - (int)puVar4 >> 1;
        }
        FUN_004f0b60(iVar3,1,(short)(char)(*(byte *)(iVar5 + 1 + param_1) & 0x3f) |
                             (short)(char)(bVar2 & 0x3f) << 6);
        local_8 = local_8 + 1;
        iVar5 = iVar5 + 2;
      }
      else if ((bVar2 & 0xf0) == 0xe0) {
        FUN_004f07a0(((short)(char)(*(byte *)(iVar5 + 1 + param_1) & 0x3f) | (short)(char)bVar2 << 6
                     ) << 6 | (short)(char)(*(byte *)(iVar5 + 2 + param_1) & 0x3f));
        local_8 = local_8 + 1;
        iVar5 = iVar5 + 3;
      }
    }
    else {
      puVar4 = unaff_ESI;
      if (7 < (uint)unaff_ESI[5]) {
        puVar4 = (undefined4 *)*unaff_ESI;
      }
      iVar1 = (int)puVar4 + unaff_ESI[4] * 2;
      puVar4 = unaff_ESI;
      if (7 < (uint)unaff_ESI[5]) {
        puVar4 = (undefined4 *)*unaff_ESI;
      }
      iVar3 = 0;
      if (iVar1 != 0) {
        iVar3 = iVar1 - (int)puVar4 >> 1;
      }
      FUN_004f0b60(iVar3,1,(short)(char)bVar2);
      iVar5 = iVar5 + 1;
      local_8 = local_8 + 1;
    }
  } while (iVar5 < 0x48);
  return 0;
}


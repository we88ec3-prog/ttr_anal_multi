
uint FUN_00728be0(void)

{
  byte bVar1;
  int *piVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[0xf] != 0) {
    return 0xffffffff;
  }
  if (unaff_ESI[1] == 0) {
    piVar2 = __errno();
    *piVar2 = 0;
    sVar3 = _fread((void *)unaff_ESI[0x11],1,0x4000,(FILE *)unaff_ESI[0x10]);
    unaff_ESI[1] = sVar3;
    if (sVar3 == 0) {
      unaff_ESI[0xf] = 1;
      iVar4 = _ferror((FILE *)unaff_ESI[0x10]);
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      unaff_ESI[0xe] = 0xffffffff;
      return 0xffffffff;
    }
    *unaff_ESI = unaff_ESI[0x11];
  }
  unaff_ESI[1] = unaff_ESI[1] + -1;
  bVar1 = *(byte *)*unaff_ESI;
  *unaff_ESI = (byte *)*unaff_ESI + 1;
  return (uint)bVar1;
}


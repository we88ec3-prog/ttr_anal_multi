
int FUN_004eefb0(int param_1,int param_2)

{
  uint uVar1;
  uint in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar2 = in_ECX - 1;
  iVar3 = 1;
  iVar2 = (iVar2 / 400 - iVar2 / 100) + ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) + -0x16d +
          in_ECX * 0x16d;
  if (1 < param_1) {
    do {
      iVar4 = *(int *)(s___AVCInventoryExpandInfo___00f7ea90 + iVar3 * 4 + 0x18);
      if (0 < (int)in_ECX) {
        uVar1 = in_ECX & 0x80000003;
        bVar5 = uVar1 == 0;
        if ((int)uVar1 < 0) {
          bVar5 = (uVar1 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if ((bVar5) &&
           (((in_ECX != ((int)in_ECX / 100) * 100 || (in_ECX == ((int)in_ECX / 400) * 400)) &&
            (iVar3 == 2)))) {
          iVar4 = iVar4 + 1;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + iVar4;
    } while (iVar3 < param_1);
    return param_2 + iVar2;
  }
  return iVar2 + param_2;
}


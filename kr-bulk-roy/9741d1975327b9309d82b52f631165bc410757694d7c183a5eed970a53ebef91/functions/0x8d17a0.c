
int FUN_008d17a0(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint in_ECX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = *param_1;
  uVar6 = 0;
  iVar2 = 0;
  uVar4 = 1;
  if (in_ECX <= uVar1) {
    return iVar2;
  }
  uVar5 = in_ECX - uVar1;
  if ((uint)(param_3 * 2) <= in_ECX - uVar1) {
    uVar5 = param_3 * 2;
  }
  if (uVar5 != 0) {
    do {
      uVar3 = (uint)*(byte *)(uVar1 + uVar6);
      if (((((uVar3 != 0x20) && (uVar3 != 0xd)) && (uVar3 != 10)) &&
          ((uVar3 != 9 && (uVar3 != 0xc)))) && (uVar3 != 0)) {
        if ((0x7f < uVar3) || (0xf < (uint)(int)(char)(&DAT_00be7e60)[uVar3 & 0x7f])) break;
        uVar4 = uVar4 << 4 | (int)(char)(&DAT_00be7e60)[uVar3 & 0x7f];
        if ((uVar4 & 0x100) != 0) {
          *(char *)(iVar2 + param_2) = (char)uVar4;
          iVar2 = iVar2 + 1;
          uVar4 = 1;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar5);
    if (uVar4 != 1) {
      *(char *)(iVar2 + param_2) = (char)uVar4 << 4;
      iVar2 = iVar2 + 1;
    }
  }
  *param_1 = uVar1 + uVar6;
  return iVar2;
}


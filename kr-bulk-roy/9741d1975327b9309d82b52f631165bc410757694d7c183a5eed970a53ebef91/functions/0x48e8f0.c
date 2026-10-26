
undefined4 FUN_0048e8f0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *in_EAX;
  int in_ECX;
  
  if ((((*(uint *)(in_ECX + 8) == in_EAX[2]) && (uVar1 = *in_EAX, 0x3ff < uVar1)) &&
      (uVar2 = in_EAX[1], 0x2cf < uVar2)) &&
     ((((uVar1 == (int)(uVar2 << 4) / 9 || (uVar1 == (int)(uVar2 << 4) / 10)) ||
       ((uVar1 == (int)(uVar2 * 4) / 3 ||
        ((iVar3 = uVar2 * 5, uVar1 == iVar3 / 3 ||
         (uVar1 == (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2)))))) || (uVar1 == (int)(uVar2 * 3) / 2)
      ))) {
    return 1;
  }
  return 0;
}


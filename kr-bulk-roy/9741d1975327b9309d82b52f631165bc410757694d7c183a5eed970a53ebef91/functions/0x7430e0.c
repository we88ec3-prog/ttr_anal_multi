
undefined4 FUN_007430e0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) < 1) {
    FUN_006edb60("FTFace: refCount > 0");
  }
  else {
    iVar1 = *(int *)(in_ECX + 4) + -1;
    *(int *)(in_ECX + 4) = iVar1;
    if (iVar1 == 0) {
      FUN_008bbe50(*(undefined4 *)(in_ECX + 0x58));
      return 0;
    }
  }
  return *(undefined4 *)(in_ECX + 4);
}


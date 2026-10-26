
undefined4 FUN_0054abb0(void)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  float in_XMM0_Da;
  
  iVar2 = FUN_0054a7e0(*(undefined4 *)(in_ECX + 8));
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x158) != 0)) &&
     (*(int *)(*(int *)(iVar2 + 0x158) + 0x34) == 0)) {
    FUN_00549290();
    fVar1 = *(float *)(in_ECX + 0xc);
    if ((((fVar1 != 0.0) && (fVar1 <= in_XMM0_Da)) || (fVar1 == 0.0)) &&
       (((fVar1 = *(float *)(in_ECX + 0x10), fVar1 != 0.0 && (in_XMM0_Da <= fVar1)) ||
        (fVar1 == 0.0)))) {
      return 1;
    }
  }
  return 0;
}


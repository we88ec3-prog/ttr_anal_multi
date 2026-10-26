
undefined4 FUN_007c5210(void)

{
  short *psVar1;
  int in_EAX;
  undefined4 uVar2;
  uint in_ECX;
  int unaff_ESI;
  int local_c;
  uint local_8;
  
  local_8 = in_EAX << 0x10 | in_ECX & 0xffff;
  FUN_0082ef00(&local_8);
  if (local_c == *(int *)(unaff_ESI + 0xb8)) {
    return 0;
  }
  psVar1 = *(short **)(local_c + 0x10);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    uVar2 = FUN_007c4d30(psVar1);
    return uVar2;
  }
  return 1;
}


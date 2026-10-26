
undefined4 FUN_008606c0(void)

{
  undefined4 uVar1;
  int in_ECX;
  int unaff_ESI;
  
  if ((*(int *)(in_ECX + 0x98) != *(int *)(in_ECX + 0x9c)) && (*(int *)(unaff_ESI + 0x74) != 0)) {
    uVar1 = FUN_00860700(unaff_ESI,in_ECX + 0x98,
                         (*(int *)(in_ECX + 0x9c) - *(int *)(in_ECX + 0x98) >> 2) + -1);
    return uVar1;
  }
  return 0;
}


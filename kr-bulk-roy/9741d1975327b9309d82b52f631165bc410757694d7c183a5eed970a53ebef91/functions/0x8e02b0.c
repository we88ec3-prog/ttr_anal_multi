
undefined4 FUN_008e02b0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int in_EDX;
  
  if (in_ECX != 0) {
    iVar1 = *(int *)(in_EDX + 0xc);
    if (*(uint *)(iVar1 + 4) <
        (uint)((int)*(short *)(iVar1 + 0x16) + *(short *)(iVar1 + 0x3a) + in_ECX)) {
      uVar2 = FUN_008bc9a0(iVar1);
      return uVar2;
    }
  }
  return 0;
}


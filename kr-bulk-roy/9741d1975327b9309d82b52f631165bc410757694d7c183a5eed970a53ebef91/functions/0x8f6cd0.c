
undefined4 FUN_008f6cd0(void)

{
  int iVar1;
  uint uVar2;
  int extraout_ECX;
  int extraout_EDX;
  
  FUN_008f4350();
  *(undefined4 *)(extraout_ECX + 4) = *(undefined4 *)(extraout_EDX + 0x2c);
  *(undefined4 *)(extraout_ECX + 8) = *(undefined4 *)(extraout_EDX + 0x30);
  *(undefined4 *)(extraout_ECX + 0xc) = *(undefined4 *)(extraout_EDX + 0x458);
  *(undefined4 *)(extraout_ECX + 0x10) = *(undefined4 *)(extraout_EDX + 0x45c);
  iVar1 = *(int *)(extraout_EDX + 0x18);
  uVar2 = 0;
  if ((iVar1 == 2) || (iVar1 == 3)) {
    uVar2 = 1;
  }
  if ((iVar1 == 2) || (iVar1 == 4)) {
    uVar2 = uVar2 | 2;
  }
  if (iVar1 != 1) {
    uVar2 = uVar2 | 4;
  }
  if (iVar1 == 2) {
    uVar2 = uVar2 | 8;
  }
  *(uint *)(extraout_ECX + 100) = *(uint *)(extraout_ECX + 100) | 4;
  *(uint *)(extraout_ECX + 0x68) = uVar2;
  return 0;
}


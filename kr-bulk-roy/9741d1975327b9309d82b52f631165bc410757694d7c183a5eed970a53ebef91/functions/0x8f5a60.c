
undefined4 FUN_008f5a60(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int extraout_ECX;
  int extraout_EDX;
  uint uVar4;
  
  iVar1 = *(int *)(param_2 + 4);
  FUN_008f4350();
  uVar4 = *(uint *)(extraout_ECX + 100);
  *(undefined4 *)(extraout_ECX + 4) = *(undefined4 *)(extraout_EDX + 0x2c);
  *(undefined4 *)(extraout_ECX + 8) = *(undefined4 *)(extraout_EDX + 0x30);
  *(undefined4 *)(extraout_ECX + 0xc) = *(undefined4 *)(extraout_EDX + 0x458);
  *(undefined4 *)(extraout_ECX + 0x10) = *(undefined4 *)(extraout_EDX + 0x45c);
  iVar2 = *(int *)(extraout_EDX + 0x18);
  uVar3 = 0;
  if ((iVar2 == 2) || (iVar2 == 3)) {
    uVar3 = 1;
  }
  if ((iVar2 == 2) || (iVar2 == 4)) {
    uVar3 = uVar3 | 2;
  }
  if (iVar2 != 1) {
    uVar3 = uVar3 | 4;
  }
  if (iVar2 == 2) {
    uVar3 = uVar3 | 8;
LAB_008f5ace:
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) goto LAB_008f5ad7;
  }
  else if (iVar2 != 1) goto LAB_008f5ace;
  uVar4 = uVar4 | 1;
LAB_008f5ad7:
  *(uint *)(extraout_ECX + 100) = uVar4;
  *(uint *)(extraout_ECX + 0x68) = uVar3;
  return 0;
}


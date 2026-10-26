
void FUN_00749a00(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 8) != param_1) || (*(int *)(unaff_ESI + 0xc) != param_2)) {
    iVar1 = *(int *)(unaff_ESI + 0x10);
    iVar2 = *(int *)(unaff_ESI + 0x14);
    iVar3 = *(int *)(unaff_ESI + 8);
    iVar4 = *(int *)(unaff_ESI + 0xc);
    if ((*(int *)(unaff_ESI + 0x24) != 0) &&
       (((*(int *)(unaff_ESI + 0x34) != *(int *)(unaff_ESI + 0x2c) &&
          -1 < *(int *)(unaff_ESI + 0x34) - *(int *)(unaff_ESI + 0x2c) &&
         (*(int *)(unaff_ESI + 0x38) != *(int *)(unaff_ESI + 0x30) &&
          -1 < *(int *)(unaff_ESI + 0x38) - *(int *)(unaff_ESI + 0x30))) &&
        ((*(uint *)(unaff_ESI + 0x28) & 0x100000) == 0)))) {
      FUN_00753020(*(undefined4 *)(unaff_ESI + 0x2c),*(undefined4 *)(unaff_ESI + 0x30),
                   *(undefined4 *)(unaff_ESI + 0x34),*(undefined4 *)(unaff_ESI + 0x38));
    }
    *(int *)(unaff_ESI + 8) = param_1;
    *(int *)(unaff_ESI + 0xc) = param_2;
    *(int *)(unaff_ESI + 0x10) = (iVar1 - iVar3) + param_1;
    *(int *)(unaff_ESI + 0x14) = (iVar2 - iVar4) + param_2;
    FUN_00746f70();
    if (((*(int *)(unaff_ESI + 0x24) != 0) &&
        (*(int *)(unaff_ESI + 0x34) != *(int *)(unaff_ESI + 0x2c) &&
         -1 < *(int *)(unaff_ESI + 0x34) - *(int *)(unaff_ESI + 0x2c))) &&
       ((*(int *)(unaff_ESI + 0x38) != *(int *)(unaff_ESI + 0x30) &&
         -1 < *(int *)(unaff_ESI + 0x38) - *(int *)(unaff_ESI + 0x30) &&
        ((*(uint *)(unaff_ESI + 0x28) & 0x100000) == 0)))) {
      FUN_00753020(*(undefined4 *)(unaff_ESI + 0x2c),*(undefined4 *)(unaff_ESI + 0x30),
                   *(undefined4 *)(unaff_ESI + 0x34),*(undefined4 *)(unaff_ESI + 0x38));
    }
  }
  return;
}


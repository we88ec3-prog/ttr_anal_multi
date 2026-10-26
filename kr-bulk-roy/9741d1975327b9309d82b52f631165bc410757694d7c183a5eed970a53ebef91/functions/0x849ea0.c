
undefined4 FUN_00849ea0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  int *unaff_EDI;
  
  iVar1 = (**(code **)(*unaff_ESI + 4))();
  if (*(int *)(iVar1 + 4) == -0x5ece0000) {
    uVar2 = (**(code **)(*unaff_EDI + 0xf0))();
    return uVar2;
  }
  iVar1 = (**(code **)(*unaff_ESI + 4))();
  if (*(int *)(iVar1 + 4) == -0x5ecc0000) {
    uVar2 = (**(code **)(*unaff_EDI + 0xec))();
    return uVar2;
  }
  return 0;
}


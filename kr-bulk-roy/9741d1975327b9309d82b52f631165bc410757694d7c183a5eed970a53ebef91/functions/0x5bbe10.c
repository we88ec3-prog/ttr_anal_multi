
void FUN_005bbe10(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x2cc);
  if (((uint)piVar1[10] >> 8 & 1) != 0) {
    if (((uint)piVar1[10] >> 8 & 1) != 0) {
      (**(code **)(*piVar1 + 0xd4))();
    }
    FUN_005a55e0(1);
    return;
  }
  FUN_00596e00(unaff_ESI,piVar1);
  FUN_005a55e0(2);
  if (*(int *)(unaff_ESI + 0x158) == 1) {
    iVar3 = *(int *)(unaff_ESI + 0x140);
  }
  else {
    if (*(int *)(unaff_ESI + 0x158) != 2) goto LAB_005bbe8e;
    iVar3 = *(int *)(unaff_ESI + 0x148);
  }
  iVar2 = 0x19 - *(int *)(iVar3 + 8);
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + iVar2;
  *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + iVar2;
  iVar2 = 0x37 - *(int *)(iVar3 + 0xc);
  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + iVar2;
  *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + iVar2;
  FUN_00746f70();
LAB_005bbe8e:
  if (*(int *)(unaff_ESI + 0x158) == 1) {
    (**(code **)(**(int **)(unaff_ESI + 0x140) + 0xb4))(0xc9);
  }
  else if (*(int *)(unaff_ESI + 0x158) == 2) {
    (**(code **)(**(int **)(unaff_ESI + 0x148) + 0xb4))(0xc9);
    return;
  }
  return;
}


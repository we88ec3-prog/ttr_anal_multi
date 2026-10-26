
void FUN_006b8eb0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  
  iVar1 = *(int *)(unaff_ESI + 0xfc);
  if (iVar1 == 0) {
    (**(code **)(**(int **)(unaff_ESI + 0xa8) + 0xd4))();
  }
  else {
    if (iVar1 == 1) {
      (**(code **)(**(int **)(unaff_ESI + 0xac) + 0xd4))();
      uVar2 = *(uint *)(*(int *)(unaff_ESI + 0xac) + 0x28);
    }
    else {
      if (iVar1 != 2) goto LAB_006b8f65;
      (**(code **)(**(int **)(unaff_ESI + 0xb0) + 0xd4))();
      uVar2 = *(uint *)(*(int *)(unaff_ESI + 0xb0) + 0x28);
    }
    if ((uVar2 >> 8 & 1) != 0) {
      iVar1 = *(int *)(unaff_ESI + 0xb4);
      iVar4 = *(int *)(unaff_ESI + 0x108) + -7;
      *(int *)(unaff_ESI + 0x104) = iVar4;
      iVar3 = (*(int *)(unaff_ESI + 0x10) - *(int *)(unaff_ESI + 8)) / 2 + -0x57;
      *(int *)(unaff_ESI + 0x100) = iVar3;
      iVar3 = iVar3 - *(int *)(iVar1 + 8);
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar3;
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar3;
      iVar4 = iVar4 - *(int *)(iVar1 + 0xc);
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar4;
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar4;
      FUN_00746f70();
    }
  }
LAB_006b8f65:
  *(int *)(unaff_ESI + 0xfc) = param_1;
  if (param_1 == 0) {
    (**(code **)(**(int **)(unaff_ESI + 0xa8) + 0xd0))();
  }
  else {
    if (param_1 == 1) {
      (**(code **)(**(int **)(unaff_ESI + 0xac) + 0xd0))();
      uVar2 = *(uint *)(*(int *)(unaff_ESI + 0xac) + 0x28);
    }
    else {
      if (param_1 != 2) goto LAB_006b9014;
      (**(code **)(**(int **)(unaff_ESI + 0xb0) + 0xd0))();
      uVar2 = *(uint *)(*(int *)(unaff_ESI + 0xb0) + 0x28);
    }
    if ((uVar2 >> 8 & 1) != 0) {
      iVar1 = *(int *)(unaff_ESI + 0xb4);
      iVar4 = *(int *)(unaff_ESI + 0x108) + -7;
      *(int *)(unaff_ESI + 0x104) = iVar4;
      iVar3 = (*(int *)(unaff_ESI + 0x10) - *(int *)(unaff_ESI + 8)) / 2 + -0x57;
      *(int *)(unaff_ESI + 0x100) = iVar3;
      iVar3 = iVar3 - *(int *)(iVar1 + 8);
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar3;
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar3;
      iVar4 = iVar4 - *(int *)(iVar1 + 0xc);
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar4;
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar4;
      FUN_00746f70();
    }
  }
LAB_006b9014:
  if (param_2 != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0xa4) + 0xd0))();
    return;
  }
  (**(code **)(**(int **)(unaff_ESI + 0xa4) + 0xd4))();
  return;
}


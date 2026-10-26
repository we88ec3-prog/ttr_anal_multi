
void FUN_006b8a80(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0xb8);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
    FUN_0077b200();
  }
  iVar1 = *(int *)(param_1 + 0xbc);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0xb8) + 200))();
  (**(code **)(**(int **)(param_1 + 0xbc) + 200))();
  iVar1 = *(int *)(param_1 + 0xc0);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
    FUN_0077b200();
  }
  iVar1 = *(int *)(param_1 + 0xc4);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0xc0) + 200))();
  (**(code **)(**(int **)(param_1 + 0xc4) + 200))();
  iVar1 = *(int *)(param_1 + 200);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
    FUN_0077b200();
  }
  iVar1 = *(int *)(param_1 + 0xcc);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 200) + 200))();
  (**(code **)(**(int **)(param_1 + 0xcc) + 200))();
  if ((*(uint *)(*(int *)(param_1 + 0xa4) + 0x28) >> 8 & 1) != 0) {
    FUN_006b81a0(*(int *)(param_1 + 0xa4));
  }
  if ((*(uint *)(*(int *)(param_1 + 0xa8) + 0x28) >> 8 & 1) != 0) {
    FUN_006b66d0();
  }
  if ((*(uint *)(*(int *)(param_1 + 0xac) + 0x28) >> 8 & 1) != 0) {
    iVar1 = *(int *)(param_1 + 0xb4);
    iVar3 = *(int *)(param_1 + 0x104);
    iVar2 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8)) / 2 + -0x57;
    *(int *)(param_1 + 0x100) = iVar2;
    iVar2 = iVar2 - *(int *)(iVar1 + 8);
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar2;
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar2;
    iVar3 = iVar3 - *(int *)(iVar1 + 0xc);
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar3;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar3;
    FUN_00746f70();
  }
  if ((*(uint *)(*(int *)(param_1 + 0xb0) + 0x28) >> 8 & 1) != 0) {
    iVar1 = *(int *)(param_1 + 0xb4);
    iVar3 = *(int *)(param_1 + 0x104);
    iVar2 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8)) / 2 + -0x57;
    *(int *)(param_1 + 0x100) = iVar2;
    iVar2 = iVar2 - *(int *)(iVar1 + 8);
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar2;
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar2;
    iVar3 = iVar3 - *(int *)(iVar1 + 0xc);
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar3;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar3;
    FUN_00746f70();
  }
  return;
}


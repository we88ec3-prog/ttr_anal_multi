
void FUN_0075ddd0(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_EBX;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  piVar5 = (int *)(in_ECX + 0x94);
  iVar4 = 4;
  do {
    if (*piVar5 != 0) {
      (**(code **)(*(int *)*piVar5 + 0x48))();
    }
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = *(int *)(in_ECX + 0xbc);
  if (*(char *)(in_ECX + 0xd4) != '\0') {
    iVar6 = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc);
    iVar2 = (*(int *)(in_ECX + 0x10) + iVar4 * -2) - *(int *)(in_ECX + 8);
    iVar1 = *(int *)(in_ECX + 0xc0);
    if (*(int *)(in_ECX + 0xc0) < iVar2) {
      iVar1 = iVar2;
    }
    *(int *)(in_ECX + 0xd0) = iVar1;
    (**(code **)(**(int **)(in_ECX + 0xa4) + 0xbc))(0,0,iVar4,iVar6);
    (**(code **)(**(int **)(in_ECX + 0xa8) + 0xbc))(unaff_EBX,0,uStack_20,iVar6);
    if (*(int *)(in_ECX + 0xb8) < 1) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_008fed10();
    }
    (**(code **)(**(int **)(in_ECX + 0xac) + 0xbc))
              (*(int *)(in_ECX + 0xbc) + iVar4,0,
               *(int *)(in_ECX + 0xbc) + iVar4 + *(int *)(in_ECX + 0xc0),iVar6);
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0xbc))
              (*(undefined4 *)(*(int *)(in_ECX + 0xa4) + 0x10),0,
               *(undefined4 *)(*(int *)(in_ECX + 0xac) + 8),iVar6);
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0xbc))
              (*(undefined4 *)(*(int *)(in_ECX + 0xac) + 0x10),0,
               *(undefined4 *)(*(int *)(in_ECX + 0xa8) + 8),iVar6);
    return;
  }
  iVar2 = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8);
  iVar1 = iVar4 * -2 - *(int *)(in_ECX + 0xc);
  uVar3 = *(int *)(in_ECX + 0x14) + (iVar1 - *(int *)(in_ECX + 0xc0));
  iVar1 = iVar1 + *(int *)(in_ECX + 0x14);
  if (iVar1 <= *(int *)(in_ECX + 0xc0)) {
    iVar1 = *(int *)(in_ECX + 0xc0);
  }
  *(int *)(in_ECX + 0xd0) = iVar1;
  (**(code **)(**(int **)(in_ECX + 0xa4) + 0xbc))(0,0,iVar2,iVar4);
  (**(code **)(**(int **)(in_ECX + 0xa8) + 0xbc))(0,uStack_24,iVar2,((int)uVar3 < 1) - 1 & uVar3);
  if (*(int *)(in_ECX + 0xb8) < 1) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_008fed10();
  }
  (**(code **)(**(int **)(in_ECX + 0xac) + 0xbc))
            (0,*(int *)(in_ECX + 0xbc) + iVar4,iVar2,
             *(int *)(in_ECX + 0xbc) + iVar4 + *(int *)(in_ECX + 0xc0));
  (**(code **)(**(int **)(in_ECX + 0xb0) + 0xbc))
            (0,*(undefined4 *)(*(int *)(in_ECX + 0xa4) + 0x14),iVar2,
             *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0xc));
  (**(code **)(**(int **)(in_ECX + 0xb4) + 0xbc))
            (0,*(undefined4 *)(*(int *)(in_ECX + 0xac) + 0x14),iVar2,
             *(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0xc));
  return;
}


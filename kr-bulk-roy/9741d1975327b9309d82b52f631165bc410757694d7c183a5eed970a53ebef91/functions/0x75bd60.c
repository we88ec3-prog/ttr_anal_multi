
void FUN_0075bd60(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_00754430();
  (**(code **)(**(int **)(in_ECX + 0xcc) + 0xbc))
            (0,0,*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8),
             *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc));
  if (*(int *)(in_ECX + 0xd8) == 0) {
    iVar2 = *(int *)(in_ECX + 0xa4);
    iVar1 = FUN_008fed10();
    iVar1 = iVar1 + iVar2;
    uVar3 = *(undefined4 *)(in_ECX + 0xa8);
    uVar4 = *(undefined4 *)(in_ECX + 0xb0);
  }
  else {
    if (*(int *)(in_ECX + 0xd8) != 1) goto LAB_0075be5a;
    uVar3 = *(undefined4 *)(in_ECX + 0xa8);
    iVar2 = FUN_008fed10();
    iVar2 = *(int *)(in_ECX + 0xac) - iVar2;
    iVar1 = *(int *)(in_ECX + 0xac);
    uVar4 = *(undefined4 *)(in_ECX + 0xb0);
  }
  (**(code **)(**(int **)(in_ECX + 200) + 0xbc))(iVar2,uVar3,iVar1,uVar4);
LAB_0075be5a:
  if (*(char *)(in_ECX + 0xd4) != '\0') {
    FUN_00759be0(*(float *)(in_ECX + 0xd0) * 100.0);
  }
  return;
}


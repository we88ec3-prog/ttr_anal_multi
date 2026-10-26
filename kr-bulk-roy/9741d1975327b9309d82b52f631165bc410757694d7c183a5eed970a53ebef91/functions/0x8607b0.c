
void FUN_008607b0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int *piVar3;
  
  iVar1 = *(int *)(in_ECX + 0x74);
  if ((iVar1 != 0) && (*(int *)(in_ECX + 0xa8) != 0)) {
    FUN_00780150(iVar1,*(undefined4 *)(iVar1 + 0x30));
  }
  piVar3 = *(int **)(in_ECX + 0x78);
  piVar2 = *(int **)(in_ECX + 0x7c);
  if (piVar3 != piVar2) {
    do {
      FUN_00780150(*piVar3,*(undefined4 *)(*piVar3 + 0x30));
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      *(int *)(iVar1 + 0xac) = in_ECX + 0x98;
    } while (piVar3 != piVar2);
  }
  return;
}


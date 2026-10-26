
void FUN_0077eae0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  FUN_0077f710();
  piVar2 = *(int **)(in_ECX + 0xd8);
  if (piVar2 != *(int **)(in_ECX + 0xdc)) {
    do {
      iVar1 = *piVar2;
      if (*(int *)(iVar1 + 0x70) == 0) {
        FUN_00780150(iVar1,*(undefined4 *)(iVar1 + 0x30));
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != *(int **)(in_ECX + 0xdc));
  }
  piVar2 = *(int **)(in_ECX + 200);
  if (piVar2 != *(int **)(in_ECX + 0xcc)) {
    do {
      FUN_00780150(*piVar2,*(undefined4 *)(*piVar2 + 0x30));
      piVar2 = piVar2 + 1;
    } while (piVar2 != *(int **)(in_ECX + 0xcc));
  }
  return;
}


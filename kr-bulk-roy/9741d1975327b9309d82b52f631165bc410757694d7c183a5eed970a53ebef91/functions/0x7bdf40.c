
void FUN_007bdf40(int param_1)

{
  char *pcVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  if (uVar4 != 0) {
    do {
      pcVar1 = *(char **)(*(int *)(param_1 + 4) + uVar3 * 4);
      piVar2 = *(int **)(pcVar1 + 8);
      if (((piVar2 != (int *)0x0) && (*pcVar1 == '\0')) && (piVar2[0x20] == 0)) {
        (**(code **)(*piVar2 + 0x18))();
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  return;
}


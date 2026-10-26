
int FUN_00539aa0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int in_EDX;
  int *piVar3;
  
  uVar1 = *(int *)(in_EDX + 0x2c) - *(int *)(in_EDX + 0x28) >> 2;
  if (uVar1 != 0) {
    uVar2 = 0;
    piVar3 = *(int **)(in_EDX + 0x28);
    do {
      if ((*(char *)(*piVar3 + 10) != '\0') && (*(int *)*piVar3 == param_1)) {
        return (*(int **)(in_EDX + 0x28))[uVar2];
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar2 < uVar1);
  }
  return 0;
}


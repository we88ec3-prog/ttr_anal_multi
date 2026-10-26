
void FUN_00544940(short param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  int in_EDX;
  int *piVar3;
  
  uVar1 = *(int *)(in_EDX + 8) - *(int *)(in_EDX + 4) >> 2;
  uVar2 = 0;
  if (uVar1 != 0) {
    piVar3 = *(int **)(in_EDX + 4);
    while ((*(short *)(*piVar3 + 0xf6) != param_1 || (*(short *)(*piVar3 + 0xf4) != (short)param_2))
          ) {
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
      if (uVar1 <= uVar2) {
        return;
      }
    }
    FUN_00543b30((*(int **)(in_EDX + 4))[uVar2]);
  }
  return;
}


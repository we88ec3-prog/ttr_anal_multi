
void FUN_00753020(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  
  piVar4 = (int *)**(int **)(in_ECX + 0x1474);
  if (piVar4 != *(int **)(in_ECX + 0x1474)) {
    do {
      cVar2 = FUN_00755c50();
      if (cVar2 != '\0') {
        if (piVar4[2] < param_1) {
          param_1 = piVar4[2];
        }
        if (param_3 < piVar4[4]) {
          param_3 = piVar4[4];
        }
        if (piVar4[3] < param_2) {
          param_2 = piVar4[3];
        }
        if (param_4 < piVar4[5]) {
          param_4 = piVar4[5];
        }
        if (piVar4 != *(int **)(in_ECX + 0x1474)) {
          *(int *)piVar4[1] = *piVar4;
          *(int *)(*piVar4 + 4) = piVar4[1];
          FUN_0089120c(piVar4);
          *(int *)(in_ECX + 0x1478) = *(int *)(in_ECX + 0x1478) + -1;
        }
        FUN_00753020(param_1,param_2,param_3,param_4);
        return;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)*(int *)(in_ECX + 0x1474));
  }
  iVar1 = *(int *)(in_ECX + 0x1474);
  iVar3 = FUN_0074d550(iVar1,*(undefined4 *)(iVar1 + 4));
  if (*(int *)(in_ECX + 0x1478) == 0xffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(in_ECX + 0x1478) = *(int *)(in_ECX + 0x1478) + 1;
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


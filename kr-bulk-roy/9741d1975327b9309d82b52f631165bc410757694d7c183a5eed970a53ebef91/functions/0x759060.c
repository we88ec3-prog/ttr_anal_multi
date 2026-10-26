
void FUN_00759060(undefined4 param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  int in_EDX;
  int *piVar5;
  
  piVar2 = *(int **)(in_ECX + 0x1c);
  piVar1 = (int *)(in_ECX + 0x1c);
  piVar5 = (int *)*piVar2;
  if (*(int *)(in_ECX + 0x20) == 0) {
    iVar3 = FUN_00404fd0(piVar2,piVar2[1]);
    piVar5 = piVar2;
  }
  else {
    if (piVar5[2] <= in_EDX) {
      if (*(int *)(piVar2[1] + 8) < in_EDX) {
        FUN_0075a6f0(piVar1);
        return;
      }
      for (piVar2 = piVar5;
          (piVar4 = piVar5, piVar2 != (undefined4 *)*piVar1 && (piVar4 = piVar2, piVar2[2] < in_EDX)
          ); piVar2 = (int *)*piVar2) {
      }
      if (piVar4[2] == in_EDX) {
        if (param_2 == '\0') {
          piVar4[3] = param_1;
          return;
        }
      }
      else {
        FUN_0075a7e0(piVar1,&param_2,piVar4);
      }
      return;
    }
    iVar3 = FUN_00404fd0(piVar5,piVar5[1]);
  }
  if (*(int *)(in_ECX + 0x20) == 0x1ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
  piVar5[1] = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


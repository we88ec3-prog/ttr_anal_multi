
int * FUN_007531a0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  
  iVar2 = (int)param_1;
  FUN_0082ef00(&param_1);
  if (((in_ECX != *(int *)((int)param_1 + 0x1414)) && (*(int **)(in_ECX + 0x10) != (int *)0x0)) &&
     (*(int *)((int)param_1 + 0x13c4) != 0)) {
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x28))();
    if (piVar3 != (int *)0x0) {
      param_1 = piVar3;
      FUN_0074a200();
      (**(code **)(**(int **)(iVar2 + 0x13c4) + 0x70))(piVar3);
      if (piVar3[0x20] != 0) {
        *(undefined4 *)(piVar3[0x20] + 0xd4) = param_4;
      }
      FUN_00405300(piVar3 + 0x28);
      if ((piVar3[0x20] != 0) && (iVar1 = *(int *)(piVar3[0x20] + 0xcc), iVar1 != 0)) {
        FUN_00405300(iVar1 + 0xe8);
      }
      if (piVar3[0x20] != 0) {
        *(undefined4 *)(piVar3[0x20] + 0xd0) = param_5;
      }
      (**(code **)(*piVar3 + 200))();
      (**(code **)(*piVar3 + 0xd0))();
      *(int **)(iVar2 + 0x13dc) = piVar3;
      *(undefined1 *)(iVar2 + 0x13d9) = 1;
      return piVar3;
    }
  }
  return (int *)0x0;
}


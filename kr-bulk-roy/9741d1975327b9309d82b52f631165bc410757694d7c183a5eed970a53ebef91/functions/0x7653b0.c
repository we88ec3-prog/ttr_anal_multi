
void FUN_007653b0(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  
  FUN_00746280(param_1);
  if (((char)param_1 != '\0') && (in_ECX[0x11] != 0)) {
    piVar1 = *(int **)(in_ECX[0x11] + 0x50);
    piVar2 = (int *)*piVar1;
    while (piVar2 != piVar1) {
      iVar4 = (**(code **)(*(int *)piVar2[4] + 4))();
      if (((iVar4 == 800) && (piVar3 = (int *)piVar2[4], piVar3[0x92] == in_ECX[0x92])) &&
         (piVar3 != in_ECX)) {
        (**(code **)(*piVar3 + 0xa0))(0);
      }
      FUN_0049e6a0();
    }
  }
  return;
}


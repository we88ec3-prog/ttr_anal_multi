
void FUN_0062b1d0(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x104);
  piVar2 = (int *)*piVar1;
  while (piVar2 != piVar1) {
    puVar3 = (undefined4 *)FUN_00831f50();
    FUN_00629bd0(*puVar3,piVar2 + 0x10);
    puVar3 = (undefined4 *)FUN_00831f50();
    (**(code **)(*(int *)*puVar3 + 200))();
    FUN_00628740();
  }
  return;
}


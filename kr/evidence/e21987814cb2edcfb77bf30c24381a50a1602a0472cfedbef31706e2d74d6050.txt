
void FUN_007be0f0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  for (piVar3 = *(int **)(param_1 + 4); piVar3 != piVar1; piVar3 = piVar3 + 1) {
    iVar2 = *piVar3;
    if (*(int **)(iVar2 + 8) != (int *)0x0) {
      (**(code **)(**(int **)(iVar2 + 8) + 8))();
      if (*(undefined4 **)(iVar2 + 8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar2 + 8))(1);
        *(undefined4 *)(iVar2 + 8) = 0;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x74) = 0;
  return;
}


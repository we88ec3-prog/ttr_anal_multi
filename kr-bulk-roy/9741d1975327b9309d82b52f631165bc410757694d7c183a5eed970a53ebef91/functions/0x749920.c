
void FUN_00749920(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)param_1[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[2];
    if ((*(int *)(iVar3 + 0x60) != 0) && ((*(int **)(iVar3 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar3 + 0x1c) + 0x30))(iVar3);
    }
  }
  (**(code **)(*param_1 + 0x128))();
  return;
}


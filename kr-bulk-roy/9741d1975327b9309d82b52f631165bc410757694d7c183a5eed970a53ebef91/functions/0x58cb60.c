
void FUN_0058cb60(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    (**(code **)(**(int **)(param_1 + 4) + 0xbc))
              (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
               *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
    if (*(int *)(param_1 + 8) != 0) {
      (**(code **)(**(int **)(param_1 + 8) + 0x28))();
    }
    FUN_00746020();
    iVar1 = *(int *)(param_1 + 4);
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
    (**(code **)(**(int **)(param_1 + 4) + 0xb4))(0x191);
    iVar1 = (*(int **)(param_1 + 4))[7];
    if (iVar1 != 0) {
      (**(code **)(**(int **)(param_1 + 4) + 0xb4))(*(undefined4 *)(iVar1 + 8));
    }
  }
  return;
}


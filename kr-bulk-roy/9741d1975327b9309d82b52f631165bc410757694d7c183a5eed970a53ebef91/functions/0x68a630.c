
void FUN_0068a630(undefined4 param_1)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xa8);
  if (iVar1 == 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x84) + 0xd8))(param_1);
    (**(code **)(**(int **)(unaff_ESI + 0x84) + 200))();
  }
  else {
    if (iVar1 == 1) {
      (**(code **)(**(int **)(unaff_ESI + 0x88) + 0xd8))(param_1);
      (**(code **)(**(int **)(unaff_ESI + 0x88) + 200))();
      return;
    }
    if (iVar1 == 2) {
      (**(code **)(**(int **)(unaff_ESI + 0x8c) + 0xd8))(param_1);
      (**(code **)(**(int **)(unaff_ESI + 0x8c) + 200))();
      return;
    }
  }
  return;
}


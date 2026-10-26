
void FUN_0074f840(int param_1,char param_2)

{
  int unaff_EDI;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (*(int **)(param_1 + 0x13f0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x13f0) + 0xd4))();
  }
  if (*(int **)(param_1 + 0x13f0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x13f0) + 0x130))();
  }
  *(int *)(param_1 + 0x13f0) = unaff_EDI;
  if (unaff_EDI != 0) {
    if (param_2 != '\0') {
      FUN_00750720(param_1,*(int *)(param_1 + 0xa8) -
                           (*(int *)(unaff_EDI + 0x10) - *(int *)(unaff_EDI + 8)) / 2,
                   *(int *)(param_1 + 0xac) -
                   (*(int *)(unaff_EDI + 0x14) - *(int *)(unaff_EDI + 0xc)) / 2);
      FUN_00749970(uStack_18,uStack_14);
    }
    (**(code **)(**(int **)(param_1 + 0x13f0) + 0xd0))();
    (**(code **)(**(int **)(param_1 + 0x13f0) + 300))();
    (**(code **)(**(int **)(param_1 + 0x13f0) + 200))();
  }
  *(undefined1 *)(param_1 + 0x13f4) = 1;
  return;
}


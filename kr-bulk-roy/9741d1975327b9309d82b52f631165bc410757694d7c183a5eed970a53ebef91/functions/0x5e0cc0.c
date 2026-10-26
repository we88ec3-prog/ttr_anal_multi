
void FUN_005e0cc0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x254) != -1) {
    iVar1 = FUN_005e06b0(*(undefined4 *)(unaff_ESI + 0x298),*(int *)(unaff_ESI + 0x254),param_1,
                         param_2);
    (**(code **)(**(int **)(unaff_ESI + 0x2a0) + 0x94))(iVar1 != 0);
    return;
  }
  (**(code **)(**(int **)(unaff_ESI + 0x2a0) + 0x94))(0);
  return;
}


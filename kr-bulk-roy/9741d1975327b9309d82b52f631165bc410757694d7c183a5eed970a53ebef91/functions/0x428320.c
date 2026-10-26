
void FUN_00428320(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_ESI;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(unaff_ESI + 0xec) + 0xcc);
  iVar1 = *(int *)(unaff_ESI + 0xf4);
  if (((iVar2 == 0) || (iVar1 < 0)) ||
     (*(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2 <= iVar1)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar2 + 0xa8) + iVar1 * 4);
  }
  if (iVar2 != 0) {
    FUN_00695100(iVar2);
    (**(code **)(**(int **)(iVar2 + 0x24c) + 0x94))(param_2);
    (**(code **)(**(int **)(iVar2 + 0x24c) + 200))();
    *(int *)(unaff_ESI + 0xf4) = *(int *)(unaff_ESI + 0xf4) + 1;
    FUN_00749920(*(undefined4 *)(unaff_ESI + 0xec));
    (**(code **)(**(int **)(unaff_ESI + 0xec) + 200))();
  }
  return;
}


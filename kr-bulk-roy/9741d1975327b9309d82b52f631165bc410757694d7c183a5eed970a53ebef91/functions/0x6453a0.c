
void FUN_006453a0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  
  if ((*(int *)(*(int *)(unaff_EDI + 0x110) + 0xcc) != 0) &&
     (*(int *)(*(int *)(unaff_EDI + 0x110) + 0xd8) != 0)) {
    iVar2 = FUN_005f55a0();
    if ((iVar2 != -1) &&
       (piVar1 = *(int **)(*(int *)(unaff_EDI + 0x128 + iVar2 * 4) + 0x118), piVar1 != (int *)0x0))
    {
      (**(code **)(*piVar1 + 0xd8))(0x3f800000);
      piVar1 = *(int **)(*(int *)(*(int *)(unaff_EDI + 0x128 + iVar2 * 4) + 0x118) + 0x10c);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0xd8))(param_1);
      }
    }
  }
  return;
}


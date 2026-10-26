
void FUN_0074f7c0(undefined4 param_1,undefined4 param_2)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (*(int **)(unaff_EDI + 0x13f0) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EDI + 0x13f0) + 0xd4))();
  }
  if (*(int **)(unaff_EDI + 0x13f0) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EDI + 0x13f0) + 0x130))();
  }
  *(int **)(unaff_EDI + 0x13f0) = unaff_ESI;
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 0xd0))();
    FUN_00749970(param_1,param_2);
    (**(code **)(*unaff_ESI + 300))();
    (**(code **)(*unaff_ESI + 200))();
  }
  *(undefined1 *)(unaff_EDI + 0x13f4) = 1;
  return;
}


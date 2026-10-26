
void FUN_00864e00(void)

{
  int *piVar1;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x14) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x18) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 4) = 0;
  }
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    FUN_00891d3d(*(int *)(unaff_ESI + 0xc));
    *(undefined4 *)(unaff_ESI + 0xc) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  return;
}


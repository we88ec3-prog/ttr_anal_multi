
void FUN_0074e8a0(void)

{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x165a0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x165a0) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x14) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0xc) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x14b4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x14b4) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x14b8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x14b8) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x18) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x10) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 8) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x1598);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x1598) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x1594);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x1594) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 0x1474);
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*(int *)(unaff_ESI + 0x1474) + 4) = *(int *)(unaff_ESI + 0x1474);
  *(undefined4 *)(unaff_ESI + 0x1478) = 0;
  if (piVar2 != *(int **)(unaff_ESI + 0x1474)) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_ESI + 0x1474));
  }
  if (*(int *)(unaff_ESI + 0x13c4) != 0) {
    FUN_00746c10();
  }
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  return;
}


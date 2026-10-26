
void FUN_007747b0(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x20c);
  uVar3 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x20c) = 0;
  }
  if (*(int *)(unaff_ESI + 0x26c) - *(int *)(unaff_ESI + 0x268) >> 2 != 0) {
    do {
      iVar2 = *(int *)(*(int *)(unaff_ESI + 0x268) + uVar3 * 4);
      piVar1 = *(int **)(iVar2 + 0x208);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)(iVar2 + 0x208) = 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(unaff_ESI + 0x26c) - *(int *)(unaff_ESI + 0x268) >> 2));
  }
  piVar1 = *(int **)(unaff_ESI + 0x220);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 0x220) = 0;
  }
  return;
}


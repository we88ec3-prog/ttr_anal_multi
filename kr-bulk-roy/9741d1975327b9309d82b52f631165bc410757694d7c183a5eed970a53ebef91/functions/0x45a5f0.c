
void FUN_0045a5f0(void)

{
  int *piVar1;
  uint uVar2;
  int unaff_EDI;
  
  uVar2 = 0;
  if (*(int *)(unaff_EDI + 0xf4) - *(int *)(unaff_EDI + 0xf0) >> 2 != 0) {
    do {
      piVar1 = *(int **)(*(int *)(unaff_EDI + 0xf0) + uVar2 * 4);
      *(undefined1 *)(piVar1 + 0xa9) = 1;
      (**(code **)(*(int *)piVar1[0xa8] + 0x94))(1);
      (**(code **)(*(int *)piVar1[0xa8] + 200))();
      (**(code **)(*piVar1 + 0x1ac))(0xffffffff,0xffffffff,0,0,0xffffffff);
      FUN_0045a210(*(undefined4 *)(*(int *)(unaff_EDI + 0xf0) + uVar2 * 4));
      (**(code **)(**(int **)(*(int *)(unaff_EDI + 0xf0) + uVar2 * 4) + 200))();
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_EDI + 0xf4) - *(int *)(unaff_EDI + 0xf0) >> 2));
  }
  return;
}


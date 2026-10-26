
void FUN_0058cc10(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 4) != 0) {
    if (*(int *)(*(int *)(unaff_ESI + 4) + 0x1c) != 0) {
      if (*(int **)(unaff_ESI + 8) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_ESI + 8) + 0x1c))(1);
        *(undefined4 *)(unaff_ESI + 8) = 0;
      }
      uVar2 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 4) + 0x1c) + 0x28))();
      *(undefined4 *)(unaff_ESI + 8) = uVar2;
    }
    iVar1 = *(int *)(unaff_ESI + 4);
    *(undefined4 *)(unaff_ESI + 0xc) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(iVar1 + 0x14);
  }
  return;
}



void FUN_007a4ad4(void)

{
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  int *unaff_ESI;
  uint uVar3;
  
  uVar3 = *(uint *)(unaff_EBP + -0x18);
  iVar1 = *(int *)(*unaff_ESI + 4);
  *(undefined4 *)(iVar1 + 0x20 + (int)unaff_ESI) = 0;
  *(undefined4 *)(iVar1 + 0x24 + (int)unaff_ESI) = 0;
  if (*(char *)(unaff_EBP + -0x11) == '\0') {
    uVar3 = uVar3 | 2;
  }
  if (uVar3 != 0) {
    FUN_00431a90(0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar2 = *(int **)(*(int *)(**(int **)(unaff_EBP + -0x2c) + 4) + 0x38 +
                    (int)*(int **)(unaff_EBP + -0x2c));
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



void FUN_0063ce10(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x100) + 0x24c);
  if (iVar1 == 0) {
LAB_0063ce3d:
    iVar1 = -1;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xcc);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
    }
    if (iVar1 == 0) goto LAB_0063ce3d;
    iVar1 = *(int *)(iVar1 + 0x20);
  }
  if (iVar1 == 0) {
    uVar3 = *(undefined4 *)(unaff_ESI + 0x104);
    *(undefined4 *)(unaff_ESI + 0x108) = 0;
    uVar2 = 0;
  }
  else if (iVar1 == 1) {
    uVar3 = *(undefined4 *)(unaff_ESI + 0x104);
    *(undefined4 *)(unaff_ESI + 0x108) = 1;
    uVar2 = 1;
  }
  else {
    if (iVar1 != 2) goto LAB_0063ce8d;
    uVar3 = *(undefined4 *)(unaff_ESI + 0x104);
    *(undefined4 *)(unaff_ESI + 0x108) = 2;
    uVar2 = 2;
  }
  FUN_0063ceb0(uVar2,uVar3);
LAB_0063ce8d:
  FUN_00749920(*(undefined4 *)(unaff_ESI + 0x100));
                    /* WARNING: Could not recover jumptable at 0x0063cea7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_ESI + 0x100) + 200))();
  return;
}


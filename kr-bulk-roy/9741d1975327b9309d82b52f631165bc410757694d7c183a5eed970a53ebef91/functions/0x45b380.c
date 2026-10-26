
void FUN_0045b380(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(unaff_ESI + 0x100);
  if ((*(int *)(iVar1 + 0x2b0) == -1) || (*(int *)(iVar1 + 0x2b4) == -1)) {
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = 0xffffffff;
    uVar2 = 0xffffffff;
  }
  else {
    uVar5 = *(undefined4 *)(iVar1 + 0x2ac);
    uVar4 = *(undefined4 *)(iVar1 + 0x2a8);
    uVar3 = *(undefined4 *)(iVar1 + 0x2b4);
    uVar2 = *(undefined4 *)(iVar1 + 0x2b0);
  }
  FUN_005d7240(uVar2,uVar3,uVar4,uVar5);
  (**(code **)(**(int **)(unaff_ESI + 0x100) + 200))();
  if ((*(int *)(*(int *)(unaff_ESI + 0x100) + 0x2b0) != -1) &&
     (*(int *)(*(int *)(unaff_ESI + 0x100) + 0x2b4) != -1)) {
    (**(code **)(**(int **)(unaff_ESI + 0xfc) + 0x90))(1);
                    /* WARNING: Could not recover jumptable at 0x0045b40a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0xfc) + 200))();
    return;
  }
  return;
}


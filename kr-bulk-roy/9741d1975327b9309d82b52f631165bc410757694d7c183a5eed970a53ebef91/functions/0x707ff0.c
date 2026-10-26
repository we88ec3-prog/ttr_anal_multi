
int FUN_00707ff0(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 0x58) =
       *(undefined4 *)(**(int **)(*(int *)(unaff_EDI + 0x14) + 4) + 0xc);
  *(undefined4 *)(unaff_EDI + 0x60) = 5;
  puVar3 = (undefined4 *)FUN_006f9b70(param_1);
  puVar1 = *(undefined4 **)(unaff_EDI + 8);
  *puVar1 = *puVar3;
  puVar1[1] = puVar3[1];
  puVar1[2] = puVar3[2];
  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 0x10;
  iVar2 = *(int *)(unaff_EDI + 8);
  if (*(int *)(iVar2 + -8) == 2) {
    piVar4 = *(int **)(iVar2 + -0x10);
  }
  else if (*(int *)(iVar2 + -8) == 7) {
    piVar4 = (int *)(*(int *)(iVar2 + -0x10) + 0x18);
  }
  else {
    piVar4 = (int *)0x0;
  }
  iVar2 = *piVar4;
  if (iVar2 == 0) {
    FUN_006f5f30();
  }
  return iVar2;
}


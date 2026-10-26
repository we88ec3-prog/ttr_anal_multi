
void FUN_006fe0e0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int unaff_EDI;
  
  piVar2 = param_1;
  iVar5 = param_1[2];
  if (iVar5 == 5) {
    iVar5 = *(int *)(*param_1 + 8);
  }
  else if (iVar5 == 7) {
    iVar5 = *(int *)(*param_1 + 8);
  }
  else {
    iVar5 = *(int *)(*(int *)(unaff_EDI + 0x10) + 0x98 + iVar5 * 4);
  }
  if (iVar5 == 0) {
    param_1 = &DAT_00c0bfc8;
  }
  else {
    param_1 = (int *)FUN_006f9c10();
  }
  iVar5 = *(int *)(unaff_EDI + 0x20);
  if (param_1[2] != 6) {
    FUN_006f8970(&DAT_00c42afc);
  }
  piVar3 = *(int **)(unaff_EDI + 8);
  piVar1 = piVar3;
  for (; piVar2 < piVar3; piVar3 = piVar3 + -4) {
    *piVar3 = piVar1[-4];
    piVar3[1] = piVar1[-3];
    piVar1[2] = piVar1[-2];
    piVar1 = piVar1 + -4;
  }
  if (*(int *)(unaff_EDI + 0x1c) - *(int *)(unaff_EDI + 8) < 0x11) {
    FUN_006fdcb0();
  }
  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 0x10;
  puVar4 = (undefined4 *)((int)piVar2 + (*(int *)(unaff_EDI + 0x20) - iVar5));
  *puVar4 = *param_1;
  puVar4[1] = param_1[1];
  puVar4[2] = param_1[2];
  return;
}


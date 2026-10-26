
void FUN_006f5870(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  piVar3 = (int *)FUN_006f50f0();
  iVar1 = *(int *)(unaff_EDI + 8);
  puVar4 = (undefined4 *)FUN_006f9b70(param_1);
  if (puVar4 == &DAT_00c0bfc8) {
    puVar4 = (undefined4 *)FUN_006f9a60();
  }
  *puVar4 = *(undefined4 *)(iVar1 + -0x10);
  puVar4[1] = *(undefined4 *)(iVar1 + -0xc);
  puVar4[2] = *(undefined4 *)(iVar1 + -8);
  if (((3 < *(int *)(*(int *)(unaff_EDI + 8) + -8)) &&
      ((*(byte *)(*(int *)(*(int *)(unaff_EDI + 8) + -0x10) + 5) & 3) != 0)) &&
     (iVar1 = *piVar3, (*(byte *)(iVar1 + 5) & 4) != 0)) {
    iVar2 = *(int *)(unaff_EDI + 0x10);
    *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xfb;
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar2 + 0x28);
    *(int *)(iVar2 + 0x28) = iVar1;
  }
  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + -0x10;
  return;
}


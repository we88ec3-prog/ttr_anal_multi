
void FUN_006f5730(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_ESI;
  
  piVar4 = (int *)FUN_006f50f0();
  iVar1 = piVar4[2];
  if ((iVar1 != 6) && (iVar1 != 7)) {
    if (iVar1 != 8) {
      *(undefined4 *)(*(int *)(unaff_ESI + 8) + 8) = 0;
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
      return;
    }
    iVar1 = *piVar4;
    puVar2 = *(undefined4 **)(unaff_ESI + 8);
    *puVar2 = *(undefined4 *)(iVar1 + 0x48);
    puVar2[1] = *(undefined4 *)(iVar1 + 0x4c);
    puVar2[2] = *(undefined4 *)(iVar1 + 0x50);
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    return;
  }
  puVar2 = *(undefined4 **)(unaff_ESI + 8);
  uVar3 = *(undefined4 *)(*piVar4 + 0xc);
  puVar2[2] = 5;
  *puVar2 = uVar3;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return;
}


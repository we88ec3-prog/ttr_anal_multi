
undefined4 FUN_006f59b0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int unaff_ESI;
  
  piVar4 = (int *)FUN_006f50f0();
  iVar1 = piVar4[2];
  if (iVar1 == 6) {
    *(undefined4 *)(*piVar4 + 0xc) = *(undefined4 *)(*(int *)(unaff_ESI + 8) + -0x10);
  }
  else if (iVar1 == 7) {
    *(undefined4 *)(*piVar4 + 0xc) = *(undefined4 *)(*(int *)(unaff_ESI + 8) + -0x10);
  }
  else {
    if (iVar1 != 8) {
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
      return 0;
    }
    iVar1 = *piVar4;
    *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(*(int *)(unaff_ESI + 8) + -0x10);
    *(undefined4 *)(iVar1 + 0x50) = 5;
  }
  iVar1 = *(int *)(*(int *)(unaff_ESI + 8) + -0x10);
  if (((*(byte *)(iVar1 + 5) & 3) != 0) && (iVar2 = *piVar4, (*(byte *)(iVar2 + 5) & 4) != 0)) {
    iVar3 = *(int *)(unaff_ESI + 0x10);
    if (*(char *)(iVar3 + 0x15) == '\x01') {
      FUN_006f9f70(iVar3,iVar1);
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
      return 1;
    }
    *(byte *)(iVar2 + 5) = *(byte *)(iVar3 + 0x14) & 3 | *(byte *)(iVar2 + 5) & 0xf8;
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
  return 1;
}


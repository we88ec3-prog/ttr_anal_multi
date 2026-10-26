
undefined1 * FUN_006f5cf0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int unaff_EDI;
  
  piVar3 = (int *)FUN_006f50f0();
  if (piVar3[2] != 6) {
    return (undefined1 *)0x0;
  }
  iVar1 = *piVar3;
  if (*(char *)(iVar1 + 6) == '\0') {
    if (in_EAX < 1) {
      return (undefined1 *)0x0;
    }
    if (*(int *)(*(int *)(iVar1 + 0x10) + 0x24) < in_EAX) {
      return (undefined1 *)0x0;
    }
    puVar4 = *(undefined4 **)(*(int *)(iVar1 + 0x10 + in_EAX * 4) + 8);
    puVar5 = (undefined1 *)
             (*(int *)(*(int *)(*(int *)(iVar1 + 0x10) + 0x1c) + -4 + in_EAX * 4) + 0x10);
    if (puVar5 == (undefined1 *)0x0) {
      return (undefined1 *)0x0;
    }
  }
  else {
    if (in_EAX < 1) {
      return (undefined1 *)0x0;
    }
    if ((int)(uint)*(byte *)(iVar1 + 7) < in_EAX) {
      return (undefined1 *)0x0;
    }
    puVar4 = (undefined4 *)(iVar1 + 8 + in_EAX * 0x10);
    puVar5 = &DAT_00bf2375;
  }
  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + -0x10;
  puVar2 = *(undefined4 **)(unaff_EDI + 8);
  *puVar4 = *puVar2;
  puVar4[1] = puVar2[1];
  puVar4[2] = puVar2[2];
  if (((3 < (*(int **)(unaff_EDI + 8))[2]) &&
      (iVar1 = **(int **)(unaff_EDI + 8), (*(byte *)(iVar1 + 5) & 3) != 0)) &&
     ((*(byte *)(*piVar3 + 5) & 4) != 0)) {
    FUN_006fb5a0(iVar1);
  }
  return puVar5;
}


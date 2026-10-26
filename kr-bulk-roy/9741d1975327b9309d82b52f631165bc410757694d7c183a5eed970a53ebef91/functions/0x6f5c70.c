
undefined1 * FUN_006f5c70(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
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
    puVar5 = *(undefined4 **)(*(int *)(iVar1 + 0x10 + in_EAX * 4) + 8);
    puVar4 = (undefined1 *)
             (*(int *)(*(int *)(*(int *)(iVar1 + 0x10) + 0x1c) + -4 + in_EAX * 4) + 0x10);
    if (puVar4 == (undefined1 *)0x0) {
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
    puVar5 = (undefined4 *)(iVar1 + 8 + in_EAX * 0x10);
    puVar4 = &DAT_00bf2375;
  }
  puVar2 = *(undefined4 **)(unaff_EDI + 8);
  *puVar2 = *puVar5;
  puVar2[1] = puVar5[1];
  puVar2[2] = puVar5[2];
  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 0x10;
  return puVar4;
}



void FUN_0053e120(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int unaff_EDI;
  
  timeGetTime();
  if (*(int *)(unaff_EDI + 0x40) == 0) {
    puVar1 = (undefined4 *)FUN_00891268(0x240);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      iVar3 = 0x22;
      puVar2 = (undefined1 *)((int)puVar1 + 0x1a);
      do {
        *(undefined2 *)(puVar2 + -2) = 0;
        *puVar2 = 0xff;
        puVar2[1] = 0xff;
        puVar2[2] = 0;
        puVar2 = puVar2 + 0x10;
        iVar3 = iVar3 + -1;
      } while (-1 < iVar3);
    }
    FUN_0053e800(puVar1);
    *(undefined4 **)(unaff_EDI + 0x40) = puVar1;
  }
  if (*(int *)(unaff_EDI + 0x44) == 0) {
    puVar1 = (undefined4 *)FUN_00891268(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
    }
    FUN_0053e230(puVar1);
    *(undefined4 **)(unaff_EDI + 0x44) = puVar1;
  }
  timeGetTime();
  return;
}



void FUN_007f3b20(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = 1;
  unaff_ESI[1] = 0;
  iVar1 = FUN_00891268(0x34);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  unaff_ESI[2] = iVar1;
  puVar2 = (undefined4 *)FUN_00891268(0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[2] = 0xff000000;
    *puVar2 = 0x43fa0000;
    puVar2[3] = 1;
    puVar2[1] = 0x447a0000;
  }
  unaff_ESI[3] = puVar2;
  unaff_ESI[4] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0xf;
  *(undefined1 *)(unaff_ESI + 5) = 0;
  return;
}


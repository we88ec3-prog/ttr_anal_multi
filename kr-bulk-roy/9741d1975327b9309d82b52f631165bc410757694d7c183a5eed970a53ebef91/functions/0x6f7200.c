
void FUN_006f7200(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_00700880();
  *(int *)(unaff_ESI + 0x28) = iVar1;
  *(int *)(unaff_ESI + 0x14) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x30) = 8;
  *(int *)(unaff_ESI + 0x24) = iVar1 + 0xa8;
  iVar1 = FUN_00700880();
  *(int *)(unaff_ESI + 8) = iVar1;
  *(int *)(unaff_ESI + 0x20) = iVar1;
  *(int *)(unaff_ESI + 0x1c) = iVar1 + 0x270;
  *(undefined4 *)(unaff_ESI + 0x2c) = 0x2d;
  *(int *)(*(int *)(unaff_ESI + 0x14) + 4) = iVar1;
  *(undefined4 *)(*(int *)(unaff_ESI + 8) + 8) = 0;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  **(undefined4 **)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_ESI + 8);
  *(undefined4 *)(unaff_ESI + 0xc) = **(undefined4 **)(unaff_ESI + 0x14);
  (*(undefined4 **)(unaff_ESI + 0x14))[2] = *(int *)(unaff_ESI + 8) + 0x140;
  return;
}


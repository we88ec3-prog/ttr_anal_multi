
void FUN_00572aa0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  FUN_00402a70(&DAT_00bf2375,0);
  iVar1 = unaff_ESI[1];
  FUN_005740f0(unaff_ESI + 7);
  if (in_ECX != *(int *)(iVar1 + 4)) {
    FUN_00403040(in_ECX + 0x10,0,0xffffffff);
  }
  *(undefined4 *)(unaff_EDI + 0x34) = *unaff_ESI;
  *(undefined4 *)(unaff_EDI + 0x44) = unaff_ESI[0x12];
  *(undefined4 *)(unaff_EDI + 0x3c) = unaff_ESI[0x10];
  *(undefined4 *)(unaff_EDI + 0x40) = unaff_ESI[0x11];
  *(undefined4 *)(unaff_EDI + 0x2c) = unaff_ESI[0xc];
  *(undefined4 *)(unaff_EDI + 0x30) = unaff_ESI[0xd];
  *(undefined4 *)(unaff_EDI + 0x1c) = unaff_ESI[8];
  *(undefined4 *)(unaff_EDI + 0x20) = unaff_ESI[9];
  *(undefined4 *)(unaff_EDI + 0x24) = unaff_ESI[10];
  *(undefined4 *)(unaff_EDI + 0x28) = unaff_ESI[0xb];
  return;
}


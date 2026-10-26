
void FUN_0057d540(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = FUN_006dfc40();
  iVar1 = *(int *)(iVar1 + 0x18);
  iVar2 = FUN_006dfc40();
  iVar2 = *(int *)(iVar2 + 0x1c);
  *(float *)(unaff_ESI + 0xfc) = (float)((iVar1 - *(int *)(unaff_ESI + 0xd0)) / 2);
  *(float *)(unaff_ESI + 0x100) = (float)((iVar2 - *(int *)(unaff_ESI + 0xd4)) / 2);
  FUN_00575c80();
  *(undefined4 *)(unaff_ESI + 0x80) = 0;
  *(undefined4 *)(unaff_ESI + 0x114) = 0;
  FUN_00575b30();
  *(undefined4 *)(unaff_ESI + 0x78) = 0;
  *(undefined4 *)(unaff_ESI + 0x114) = 0;
  FUN_005759a0();
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  return;
}


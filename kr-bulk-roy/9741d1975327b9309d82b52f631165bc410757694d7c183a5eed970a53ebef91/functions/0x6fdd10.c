
void FUN_006fdd10(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_ESI + 0x28);
  if (unaff_EDI + 1U < 0xaaaaaab) {
    iVar2 = FUN_00700880();
  }
  else {
    iVar2 = FUN_00700860();
  }
  *(int *)(unaff_ESI + 0x28) = iVar2;
  *(int *)(unaff_ESI + 0x30) = unaff_EDI;
  *(int *)(unaff_ESI + 0x14) = iVar2 + ((*(int *)(unaff_ESI + 0x14) - iVar1) / 0x18) * 0x18;
  *(int *)(unaff_ESI + 0x24) = iVar2 + -0x18 + unaff_EDI * 0x18;
  return;
}



void FUN_00758d30(void)

{
  int unaff_ESI;
  undefined4 unaff_EDI;
  int local_c;
  undefined1 local_8 [4];
  
  FUN_00848020(local_8);
  if (local_c != *(int *)(unaff_ESI + 0x2c)) {
    *(undefined4 *)(local_c + 0x18) = unaff_EDI;
    *(undefined1 *)(local_c + 0x1c) = 1;
    FUN_007591a0(*(int *)(local_c + 0x10),*(int *)(local_c + 0x14) - *(int *)(local_c + 0x10),
                 unaff_EDI);
  }
  return;
}



undefined4 FUN_008f4df0(void)

{
  int extraout_ECX;
  int extraout_EDX;
  
  FUN_008f4350();
  *(undefined4 *)(extraout_ECX + 4) = *(undefined4 *)(extraout_EDX + 8);
  *(undefined4 *)(extraout_ECX + 0xc) = *(undefined4 *)(extraout_EDX + 0xc);
  *(undefined4 *)(extraout_ECX + 8) = *(undefined4 *)(extraout_EDX + 0x10);
  *(undefined4 *)(extraout_ECX + 0x10) = *(undefined4 *)(extraout_EDX + 0x14);
  return 0;
}

